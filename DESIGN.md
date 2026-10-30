# Decisions log

Each entry records the choice, the alternatives, why they lost, and what would
reopen it. The first four were scaffolding defaults; challenge them.

## Develop on macOS, target Linux only

**Choice:** Linux is the only supported platform. The Mac is for editing and for
fast builds of portable code, and a Docker container covers Linux-specific code.

**Alternatives:** supporting both. Rejected because macOS has no
`sched_setaffinity`, `isolcpus`, `nohz_full` or `PTHREAD_MUTEX_ROBUST`, and those
are central to Phases 0 and 3.

**Open:** tail-latency numbers can't come from the Mac or Docker. Docker Desktop
runs a VM whose vCPUs the host scheduler can preempt, and the harness can't
control that. Benchmarks need bare-metal Linux, and the machine isn't chosen yet.

## CI on x86-64, local Linux on arm64

**Choice:** CI runs on `ubuntu-24.04` (x86-64); the dev container runs on arm64.

**Why it's useful:** x86 is strongly ordered and hides many missing
acquire/release bugs that arm64 exposes, so running on both tests the memory
ordering on both. Keep the stress tests running on arm64 from Phase 1 onwards.

**Reconsider if:** arm64 runners are available for this repo, which would make
that coverage automatic.

## Catch2 v3 over GoogleTest

**Choice:** Catch2, pinned with FetchContent.

**Alternatives:** GoogleTest, which is equally capable. Catch2 won on less
boilerplate; it's a low-stakes choice.

**Reconsider if:** `TEST_CASE` overhead or compile times become a problem.

## HdrHistogram_c in core-only mode

**Choice:** HdrHistogram_c 0.12.1, pinned with FetchContent, built with
`HDR_HISTOGRAM_CORE_ONLY`. That gives only the record and percentile engine, with
no zlib or threads.

**Alternatives:** the full library, which adds log encoding and an interval
recorder that the harness doesn't need yet. Writing a histogram by hand, which
would mean debugging the instrument as well as the thing it measures.

**Reconsider if:** runs need HdrHistogram's log format, or recording interval
snapshots from a running process.
