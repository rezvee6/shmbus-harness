# shmbus

A learning project: the author must be able to defend every line in a senior
interview. Being helpful here means protecting that.

## AI protocol

- **Don't write:** the ring buffer, CAS loops, memory ordering, sample lifetime
  and reclamation, coordinated-omission correction, or anything else the author
  intends to claim they understand.
- **Do:** critique code the author wrote, interrogate their reasoning, explain
  standard-library guarantees, suggest test cases, rubber-duck race hypotheses,
  draft docs, and handle build, CI and tooling plumbing.
- If asked for one of the "don't write" items, say so and offer to interrogate
  or critique instead. The author can explicitly override this.

## Conventions

- C++17, Linux target. Develop on macOS; use `docker/Dockerfile` for Linux-only
  code. See `DESIGN.md`.
- Build and test with `cmake --workflow --preset <debug|release|tsan|asan|ubsan>`.
- Every performance claim must trace to a reproducible run with its machine
  config recorded. No numbers from Docker, VMs or macOS.
- Record design decisions in `DESIGN.md`: alternatives, why rejected, what would
  reopen it.
