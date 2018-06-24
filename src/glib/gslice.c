/* GLIB sliced memory - fast concurrent memory chunk allocator
 * Copyright (C) 2005 Tim Janik
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
/* MT safe */

#include <config.h>
#include <glibconfig.h>
#include <glib/gslice.h>

/**
 * g_slice_alloc:
 * @block_size: the number of bytes to allocate
 *
 * Allocates a block of memory from the slice allocator.
 * The block address handed out can be expected to be aligned
 * to at least 1 * sizeof (void*),
 * though in general slices are 2 * sizeof (void*) bytes aligned,
 * if a malloc() fallback implementation is used instead,
 * the alignment may be reduced in a libc dependent fashion.
 * Note that the underlying slice allocation mechanism can
 * be changed with the [`G_SLICE=always-malloc`][G_SLICE]
 * environment variable.
 *
 * Returns: a pointer to the allocated memory block, which will be %NULL if and
 *    only if @mem_size is 0
 *
 * Since: 2.10
 */
gpointer
g_slice_alloc (gsize mem_size)
{
    gpointer mem;

    mem = g_malloc (mem_size);
    return mem;
}


/**
 * g_slice_alloc0:
 * @block_size: the number of bytes to allocate
 *
 * Allocates a block of memory via g_slice_alloc() and initializes
 * the returned memory to 0. Note that the underlying slice allocation
 * mechanism can be changed with the [`G_SLICE=always-malloc`][G_SLICE]
 * environment variable.
 *
 * Returns: a pointer to the allocated block, which will be %NULL if and only
 *    if @mem_size is 0
 *
 * Since: 2.10
 */
gpointer
g_slice_alloc0 (gsize mem_size)
{
  gpointer mem = g_slice_alloc (mem_size);
  if (mem)
    memset (mem, 0, mem_size);
  return mem;
}

/**
 * g_slice_free_chain_with_offset:
 * @block_size: the size of the blocks
 * @mem_chain:  a pointer to the first block of the chain
 * @next_offset: the offset of the @next field in the blocks
 *
 * Frees a linked list of memory blocks of structure type @type.
 *
 * The memory blocks must be equal-sized, allocated via
 * g_slice_alloc() or g_slice_alloc0() and linked together by a
 * @next pointer (similar to #GSList). The offset of the @next
 * field in each block is passed as third argument.
 * Note that the exact release behaviour can be changed with the
 * [`G_DEBUG=gc-friendly`][G_DEBUG] environment variable, also see
 * [`G_SLICE`][G_SLICE] for related debugging options.
 *
 * If @mem_chain is %NULL, this function does nothing.
 *
 * Since: 2.10
 */
void
g_slice_free_chain_with_offset (gsize    mem_size,
                                gpointer mem_chain,
                                gsize    next_offset)
{
  gpointer slice = mem_chain;
  /* while the thread magazines and the magazine cache are implemented so that
   * they can easily be extended to allow for free lists containing more free
   * lists for the first level nodes, which would allow O(1) freeing in this
   * function, the benefit of such an extension is questionable, because:
   * - the magazine size counts will become mere lower bounds which confuses
   *   the code adapting to lock contention;
   * - freeing a single node to the thread magazines is very fast, so this
   *   O(list_length) operation is multiplied by a fairly small factor;
   * - memory usage histograms on larger applications seem to indicate that
   *   the amount of released multi node lists is negligible in comparison
   *   to single node releases.
   * - the major performance bottle neck, namely g_private_get() or
   *   g_mutex_lock()/g_mutex_unlock() has already been moved out of the
   *   inner loop for freeing chained slices.
   */
  // gsize chunk_size = P2ALIGN (mem_size);
  // guint acat = allocator_categorize (chunk_size);
  // if (G_LIKELY (acat == 1))             /* allocate through magazine layer */
  //   {
  //     ThreadMemory *tmem = thread_memory_from_self();
  //     guint ix = SLAB_INDEX (allocator, chunk_size);
  //     while (slice)
  //       {
  //         guint8 *current = slice;
  //         slice = *(gpointer*) (current + next_offset);
  //         if (G_UNLIKELY (allocator->config.debug_blocks) &&
  //             !smc_notify_free (current, mem_size))
  //           abort();
  //         if (G_UNLIKELY (thread_memory_magazine2_is_full (tmem, ix)))
  //           {
  //             thread_memory_swap_magazines (tmem, ix);
  //             if (G_UNLIKELY (thread_memory_magazine2_is_full (tmem, ix)))
  //               thread_memory_magazine2_unload (tmem, ix);
  //           }
  //         if (G_UNLIKELY (g_mem_gc_friendly))
  //           memset (current, 0, chunk_size);
  //         thread_memory_magazine2_free (tmem, ix, current);
  //       }
  //   }
  // else if (acat == 2)                   /* allocate through slab allocator */
  //   {
  //     g_mutex_lock (&allocator->slab_mutex);
  //     while (slice)
  //       {
  //         guint8 *current = slice;
  //         slice = *(gpointer*) (current + next_offset);
  //         if (G_UNLIKELY (allocator->config.debug_blocks) &&
  //             !smc_notify_free (current, mem_size))
  //           abort();
  //         if (G_UNLIKELY (g_mem_gc_friendly))
  //           memset (current, 0, chunk_size);
  //         slab_allocator_free_chunk (chunk_size, current);
  //       }
  //     g_mutex_unlock (&allocator->slab_mutex);
  //   }
  // else                                  /* delegate to system malloc */
    while (slice)
      {
        guint8 *current = slice;
        slice = *(gpointer*) (current + next_offset);
        // if (G_UNLIKELY (allocator->config.debug_blocks) &&
        //     !smc_notify_free (current, mem_size))
        //   abort();
        // if (G_UNLIKELY (g_mem_gc_friendly))
        //   memset (current, 0, mem_size);
        g_free (current);
      }
}


/**
 * g_slice_copy:
 * @block_size: the number of bytes to allocate
 * @mem_block: the memory to copy
 *
 * Allocates a block of memory from the slice allocator
 * and copies @block_size bytes into it from @mem_block.
 *
 * @mem_block must be non-%NULL if @block_size is non-zero.
 *
 * Returns: a pointer to the allocated memory block, which will be %NULL if and
 *    only if @mem_size is 0
 *
 * Since: 2.14
 */
gpointer
g_slice_copy (gsize         mem_size,
              gconstpointer mem_block)
{
  gpointer mem = g_slice_alloc (mem_size);
  if (mem)
    memcpy (mem, mem_block, mem_size);
  return mem;
}


/**
 * g_slice_free1:
 * @block_size: the size of the block
 * @mem_block: a pointer to the block to free
 *
 * Frees a block of memory.
 *
 * The memory must have been allocated via g_slice_alloc() or
 * g_slice_alloc0() and the @block_size has to match the size
 * specified upon allocation. Note that the exact release behaviour
 * can be changed with the [`G_DEBUG=gc-friendly`][G_DEBUG] environment
 * variable, also see [`G_SLICE`][G_SLICE] for related debugging options.
 *
 * If @mem_block is %NULL, this function does nothing.
 *
 * Since: 2.10
 */
void
g_slice_free1 (gsize    mem_size,
               gpointer mem_block)
{
    // if (G_UNLIKELY (g_mem_gc_friendly))
    //     memset (mem_block, 0, mem_size);
    g_free (mem_block);
}
