/**
 * @file duplicate.c
 * @brief Implementation of a utility to check repeated numbers in a sorted array.
 *
 */
#include <stdlib.h>

#include "duplicate.h"
#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

/*<START_CODE>*/

/* recursive implementation */
Boolean is_duplicate_recursive(int e, int *t, int left, int right, int size) {
  /* no matching numbers found */
  if (left > right) return FALSE;

  /* recalculate midpoint */
  int mid = left + (right - left) / 2;

  /* check if midpoint is the character you are looking for (implement a binary search based on this info for efficiency) */
  if (t[mid] == e) {
      
      /* character found */
      if ((mid > 0 && t[mid - 1] == e) || (mid < size - 1 && t[mid + 1] == e)) {
          return TRUE;
      }
      /* character not found */
      return FALSE;
      
  /* binary search bit for calling recursive function on either half of the sorted array */    
  } else if (t[mid] < e) {
      return is_duplicate_recursive(e, t, mid + 1, right, size);
  } else {
      return is_duplicate_recursive(e, t, left, mid - 1, size);
  }
}

Boolean is_duplicate(int e, int *t, int size) {
  if (!t || size <= 1) return FALSE;

  return is_duplicate_recursive(e, t, 0, size - 1, size);
}

/*<END_CODE>*/