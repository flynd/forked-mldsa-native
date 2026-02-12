[//]: # (SPDX-License-Identifier: CC-BY-4.0)

# Monolithic Build Verify Only (Native Backend)

This directory contains a minimal example for building mldsa-native for a minimal footprint with
native assembly backends to only verify signatures, using the auto-generated `mldsa_native.c`
and `mldsa_native_asm.S` files.

## Use Case

Use this approach when:
- You need only one ML-DSA parameter set (44, 65, or 87)
- You want simple build integration with optimal performance
- You want to minimze code size and memory usage
- You only need to verify signatures, not generate keys or create signatures
- You don't need the wrapper functions and can call mldsa_verify_internal() directly

## Components

1. Source tree [mldsa_native/*](mldsa_native), including top-level compilation unit
   [mldsa_native.c](mldsa_native/mldsa_native.c) (gathering all C sources),
   [mldsa_native_asm.S](mldsa_native/mldsa_native_asm.S) (gathering all assembly sources),
   and the mldsa-native API [mldsa_native.h](mldsa_native/mldsa_native.h).
2. Your application source code

## Configuration

The configuration file [mldsa_native_config.h](mldsa_native/mldsa_native_config.h) sets:
- `MLD_CONFIG_PARAMETER_SET`: Security level (default 87)
- `MLD_CONFIG_NAMESPACE_PREFIX`: Symbol prefix (set to `mldsa`)
- `MLD_CONFIG_NO_KEYPAIR_API`: Disables `crypto_sign_signature`, etc.
- `MLD_CONFIG_NO_SIGN_API`: Disables `crypto_sign_keypair`, etc.
- `MLD_CONFIG_INTERNAL_API_ONLY`: Disables all public functions except `crypto_sign_XXXX_internal`
- `MLD_CONFIG_USE_NATIVE_BACKEND_ARITH`: Enables native arithmetic backend
- `MLD_CONFIG_USE_NATIVE_BACKEND_FIPS202`: Enables native FIPS-202 backend
- `MLD_CONFIG_INTERNAL_API_QUALIFIER`: `static` to build as a single unit
- `MLD_CONFIG_REDUCE_RAM`: Reduces the amount of working memory needed

## Notes

- Both `mldsa_native.c` and `mldsa_native_asm.S` must be compiled and linked
- Native backends are auto-selected based on target architecture
- On unsupported platforms, the C backend is used automatically

## Usage

```bash
make build   # Build the example
make run     # Run the example
```
