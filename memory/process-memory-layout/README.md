# Exploring Linux Process Memory with C

## Objective
Understand how Linux organizes a process's virtual memory and where global, local, and dynamically allocated variables reside.

## Experiment
A simple C program prints the memory addresses of three variables:

- **Global variable:** Stored in the executable's writable data region (`.data`).
- **Local variable:** Stored on the stack.
- **Dynamically allocated variable:** Allocated using `malloc()`, typically within the heap.

The program also prints its PID and pauses execution, allowing its memory mappings to be inspected.

## Running the experiment

Compile and execute:

```bash
gcc inspectmem.c -o inspectmem
./inspectmem
```

While the program is paused, open another terminal:

```bash
cat /proc/<PID>/maps
```

Replace `<PID>` with the process ID printed by the program.

## Findings
- `/proc/PID/maps` displays virtual memory regions and their permissions.
- `rw-p` indicates readable, writable, private memory.
- `r-xp` typically identifies executable code mappings.
- Global variables, stack variables, and heap allocations occupy different memory regions.
- Memory addresses can change between executions due to ASLR (Address Space Layout Randomization).

## Security relevance
Understanding process memory layouts is foundational for debugging, reverse engineering, malware analysis, and investigating memory corruption vulnerabilities.

## Example

Identifying heap, stack and writeable memory regions based on the range from proc maps

<img width="278" height="67" alt="pic1" src="https://github.com/user-attachments/assets/b2a56e88-a119-4560-8f7a-76d1af2f40c0" />
<img width="496" height="233" alt="pic2" src="https://github.com/user-attachments/assets/78eb11a2-0583-4606-a253-03325bf95c14" />
