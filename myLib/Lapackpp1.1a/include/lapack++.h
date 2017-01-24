//      LAPACK++ (V. 1.1)
//      (C) 1992-1996 All Rights Reserved.

// NOTE: This header file includes all of the header files for LAPACK++.
//       IT'S LARGE!

#ifndef _LAPACKPP_H
#define _LAPACKPP_H

#include "lapack.h"

#include "lafnames.h"
#include "gmd.h" LA_GEN_MAT_DOUBLE_H
#include "lavd.h" LA_VECTOR_DOUBLE_H
#include "gfd.h" LA_GEN_FACT_DOUBLE_H
#include "bmd.h" LA_BAND_MAT_DOUBLE_H
#include "bfd.h" LA_BAND_FACT_DOUBLE_H
#include "trmd.h" LA_TRIDIAG_MAT_DOUBLE_H
#include "trfd.h" LA_TRIDIAG_FACT_DOUBLE_H
#include "spdmd.h" LA_SPD_MAT_DOUBLE_H
#include "symd.h" LA_SYMM_MAT_DOUBLE_H
#include "syfd.h" LA_SYMM_FACT_DOUBLE_H
#include "sytrmd.h" LA_SYMM_TRIDIAG_MAT_DOUBLE_H
#include "sybmd.h" LA_SYMM_BAND_MAT_DOUBLE_H
#include "uutgmd.h" LA_UNIT_UPPER_TRIANG_MAT_DOUBLE_H
#include "ultgmd.h" LA_UNIT_LOWER_TRIANG_MAT_DOUBLE_H
#include "laslv.h" LA_SOLVE_DOUBLE_H

#include "arch.h"
#include "laexcp.h"
#include "lautil.h"
#include "blas++.h"
#endif 


