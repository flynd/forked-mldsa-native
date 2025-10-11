/*
 * Copyright (c) The mldsa-native project authors
 * SPDX-License-Identifier: Apache-2.0 OR ISC OR MIT
 */

#include "../../../common.h"

#if defined(MLD_ARITH_BACKEND_AARCH64) && \
    !defined(MLD_CONFIG_MULTILEVEL_NO_SHARED)

#include <stdint.h>
#include "arith_native_aarch64.h"

/* Table of indices used for tbl instructions in polyz_unpack_{17,19}. */

MLD_ALIGN const uint8_t mld_polyz_unpack_17_indices[] = {
    0,  1,  2,  -1, 2,  3,  4,  -1, 4,  5,  6,  -1, 6,  7,  8,  -1,
    9,  10, 11, -1, 11, 12, 13, -1, 13, 14, 15, -1, 15, 16, 17, -1,
    2,  3,  4,  -1, 4,  5,  6,  -1, 6,  7,  8,  -1, 8,  9,  10, -1,
    11, 12, 13, -1, 13, 14, 15, -1, 15, 16, 17, -1, 17, 18, 19, -1,
};

MLD_ALIGN const uint8_t mld_polyz_unpack_19_indices[] = {
    0,  1,  2,  -1, 2,  3,  4,  -1, 5,  6,  7,  -1, 7,  8,  9,  -1,
    10, 11, 12, -1, 12, 13, 14, -1, 15, 16, 17, -1, 17, 18, 19, -1,
    4,  5,  6,  -1, 6,  7,  8,  -1, 9,  10, 11, -1, 11, 12, 13, -1,
    14, 15, 16, -1, 16, 17, 18, -1, 19, 20, 21, -1, 21, 22, 23, -1,
};

#else /* MLD_ARITH_BACKEND_AARCH64 && !MLD_CONFIG_MULTILEVEL_NO_SHARED */

MLD_EMPTY_CU(aarch64_polyz_unpack_table)

#endif /* !(MLD_ARITH_BACKEND_AARCH64 && !MLD_CONFIG_MULTILEVEL_NO_SHARED) */
