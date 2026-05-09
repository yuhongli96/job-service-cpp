#include "threadpool.ih"

//void ThreadPool::workerLoop(size_t worker_id)
void ThreadPool::workerLoop()
{
    while (true)
    {
        auto job = d_jobq.pop();

        if (!job)                       // nullptr
            break;

        count(*job);
    }
}