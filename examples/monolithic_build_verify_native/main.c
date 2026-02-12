/*
 * Copyright (c) The mlkem-native project authors
 * Copyright (c) The mldsa-native project authors
 * SPDX-License-Identifier: Apache-2.0 OR ISC OR MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Import public mldsa-native API
 *
 * This requires specifying the parameter set and namespace prefix
 * used for the build.
 *
 * The parameter set is configured on the command line
 */

#include <mldsa_native.h>
#include "expected_signatures.h"

#define CHECK(x)                                              \
  do                                                          \
  {                                                           \
    int rc;                                                   \
    rc = (x);                                                 \
    if (!rc)                                                  \
    {                                                         \
      fprintf(stderr, "ERROR (%s,%d)\n", __FILE__, __LINE__); \
      return 1;                                               \
    }                                                         \
  } while (0)

int main(void)
{
  printf("ML-DSA-%d monolithic_build_verify_native Example\n",
         MLD_CONFIG_API_PARAMETER_SET);
  printf("======================\n\n");

  printf("Verifying signature... ");

  const uint8_t prefix[2] = {
      0x00,  // MLD_PREHASH_NONE
      0x00}; // Context length

  CHECK(mldsa_verify_internal(expected_signature, sizeof(expected_signature),
      message, sizeof(message), prefix, sizeof(prefix), public_key, 0) == 0);

  printf("DONE\n");

  printf("\nAll tests passed! ML-DSA signature verification successful.\n");
  return 0;
}
