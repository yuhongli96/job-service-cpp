#include "threadpool.ih"

void ThreadPool::start()
{                                       // initialize all workers
    for (size_t worker = 0; worker != d_workerCount; ++worker)
        d_workers.emplace_back(&ThreadPool::workerLoop, this);    
}