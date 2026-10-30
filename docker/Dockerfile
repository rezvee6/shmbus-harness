# Linux development shell. Matches the CI runner's distro so behaviour that
# macOS lacks (robust mutexes, sched_setaffinity) can be built and tested on a
# Mac. Not a benchmarking environment: see DESIGN.md.
FROM ubuntu:24.04

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    cmake \
    gdb \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
