# Priority Inversion Simulation in C

## Overview

This project demonstrates the concept of **priority inversion** in operating systems and its resolution using **priority inheritance**.

It is implemented in C and uses a terminal-based interface to simulate process scheduling and resource contention.

---

## Concepts Covered

* CPU Scheduling
* Priority-based Scheduling
* Priority Inversion
* Priority Inheritance
* Resource Sharing (Mutex concept)

---

## Problem Description

Priority inversion occurs when:

* A **high-priority process (P1)** is blocked by a **low-priority process (P3)** holding a resource
* A **medium-priority process (P2)** continues execution instead of allowing P3 to finish

This leads to inefficient CPU utilization and delays in critical tasks.

---

## Solution: Priority Inheritance

To resolve this:

* The system temporarily **increases the priority of the low-priority process (P3)**
* This allows it to complete execution quickly
* The resource is released
* The high-priority process resumes execution

---

## Simulation Flow

1. Normal scheduling begins (P1 executes first)
2. P3 acquires the shared resource
3. P1 requests the resource and gets blocked
4. P2 continues execution (causing priority inversion)
5. Priority inheritance is applied to P3
6. P3 releases the resource
7. P1 resumes execution
8. All processes complete

---

## How to Run

### Compile

```bash
gcc priority.c -o priority
```

### Execute

```bash
./priority
```

---

## Output

The program displays:

* Process states (Running, Waiting, Blocked, Completed)
* Resource status (Locked / Available)
* System messages describing each stage

---

## Limitations

* This is a conceptual simulation (not a real scheduler)
* No actual threads or mutex locks are used
* Designed for educational purposes

---

## Future Improvements

* Implement using pthreads for real concurrency
* Add graphical visualization
* Simulate real-time scheduling algorithms

---

## Author
Khushi Chirag Shitole
