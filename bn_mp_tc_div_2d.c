#include "tommath_private.h"
#ifdef BN_MP_TC_DIV_2D_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* two complement right shift */
mp_err mp_tc_div_2d(const mp_int *a, int b, mp_int *c)
{
   mp_err err;
   if (a->sign == MP_ZPOS) {
      return mp_div_2d(a, b, c, NULL);
   }

   err = mp_add_d(a, 1uL, c);
   if (err != MP_OKAY) {
      return err;
   }

   err = mp_div_2d(c, b, c, NULL);
   return (err == MP_OKAY) ? mp_sub_d(c, 1uL, c) : err;
}
#endif
