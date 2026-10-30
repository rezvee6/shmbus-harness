# shmbus

Zero-copy shared-memory pub/sub transport for Linux, in C++17.

**Status:** Phase 0, measurement harness. Nothing is implemented yet.

## Build and test

Each preset (`debug`, `release`, `tsan`, `asan`, `ubsan`) configures, builds and
tests in one command:

```bash
cmake --workflow --preset debug
```

## Linux shell on macOS

shmbus targets Linux. On a Mac, use the dev container to build and run anything
Linux-specific:

```bash
docker build -t shmbus-dev -f docker/Dockerfile .
```

```bash
docker run --rm -it -v "$PWD":/src shmbus-dev
```

Build directories are separated by host OS, so Mac and container builds can
share the checkout.

Benchmark numbers from a container or VM don't count. See
[DESIGN.md](DESIGN.md).
