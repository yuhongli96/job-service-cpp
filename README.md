# Job Service (C++ Thread Pool CLI)

A multithreaded job processing system written in modern C++.

## Overview

This project implements a simple backend-style service that processes file-based jobs (word, line, and character counting) using a thread pool and a synchronized job queue.

The system is structured into the following core components:

- JobManager: acts as the interface layer, handling job submission, status queries, result retrieval, and listing of jobs
- JobQueue: a thread-safe queue implemented using a mutex and condition variable, responsible for coordinating access between producers and workers
- ThreadPool: a group of worker threads that continuously fetch and process jobs from the queue
- Job: represents an individual task, containing input data, processing results, and execution status

Together, these components form a producer–consumer architecture where jobs are submitted asynchronously and processed concurrently by worker threads.

---

## Features

- Thread-safe job queue (`JobQueue`)
- Thread pool with worker threads (`ThreadPool`)
- Job lifecycle management (`JobManager`)
- CLI interface for interacting with jobs
- Asynchronous processing
- Safe shutdown of threads
- Cross-platform build with CMake (macOS / Linux)

---

## Build Instructions

### Requirements
- C++20 compiler (GCC / Clang)
- CMake version 3.16 or higher

### Build

```bash
$ cmake -S . -B build
$ cmake --build build
```

## Usage

```bash
$ ./build/job_service
```

Follow the command instruction when prompted.


## Example
```shell
$ ./build/job_service

==== Job Service ====
1. Submit word-count job
2. Check job status
3. Get job result
4. List all jobs
5. Exit

Choose an option: 1

Enter file path: tests/large.txt
Job submitted successfully
Job ID: 1

Choose an option: 2
Enter job ID: 1
Job 1 status: Done


Choose an option: 3
Enter job ID: 1
Job 1 result:
Lines: 1270000
Words: 10160000
Characters: 52070000

Choose an option: 4
Jobs:
[1] Done

Choose an option: 5
Exiting...
```

---

## Job States

- Pending: job is waiting in the queue
- Running: job is currently being processed
- Done: job completed successfully
- Failed: job failed (e.g. file cannot be opened)
- Not found: the requested job ID does not exist

---

## Performance Testing
The program includes a benchmark mode that measures total processing time and throughput for different worker counts.  
Results exclude program initialization time and measure only job processing.

### Test Environment

- CPU: Apple M2 (8 cores)
- RAM: 16 GB
- Storage: SSD
- OS: macOS
- Compiler: GCC 15.1.0

### Results

| Workers | Jobs | File Size (MB) | Total Time (s) | Throughput (jobs/s) |
|---:|---:|---:|---:|---:|
| 1 | 10 | 50 | 5.8 | 1.72 |
| 2 | 10 | 50 | 3.1 | 3.21 |
| 4 | 10 | 50 | 2.0 | 5.03 |
| 6 | 10 | 50 | 1.5 | 6.49 |

---

## Future Improvements

- Add HTTP API (REST interface)
- Persistent storage for jobs
- Job cancellation support
- Progress reporting
- Unit testing with Catch2 or GoogleTest
- Logging system

---


## Author

Yuhong Li