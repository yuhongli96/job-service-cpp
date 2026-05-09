#include "threadpool.ih"

ThreadPool::ThreadPool(JobQueue &jobq, size_t workerCount)
:
    d_jobq(jobq),
    d_workerCount(workerCount)
{}