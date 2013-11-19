/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2010  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <grub/types.h>
#include <grub/misc.h>
#include <grub/decompressor.h>

void *
memset (void *s, int c, grub_size_t len)
{
  grub_uint8_t *ptr;
  for (ptr = s; len; ptr++, len--)
    *ptr = c;
  return s;
}

void *
grub_memmove (void *dest, const void *src, grub_size_t n)
{
  char *d = (char *) dest;
  const char *s = (const char *) src;

  if (d < s)
    while (n--)
      *d++ = *s++;
  else
    {
      d += n;
      s += n;

      while (n--)
	*--d = *--s;
    }

  return dest;
}

int
grub_memcmp (const void *s1, const void *s2, grub_size_t n)
{
  const unsigned char *t1 = s1;
  const unsigned char *t2 = s2;

  while (n--)
    {
      if (*t1 != *t2)
	return (int) *t1 - (int) *t2;

      t1++;
      t2++;
    }

  return 0;
}

int memcmp (const void *s1, const void *s2, grub_size_t n)
  __attribute__ ((alias ("grub_memcmp")));

void *memmove (void *dest, const void *src, grub_size_t n)
  __attribute__ ((alias ("grub_memmove")));

void *memcpy (void *dest, const void *src, grub_size_t n)
  __attribute__ ((alias ("grub_memmove")));

void *grub_decompressor_scratch;

