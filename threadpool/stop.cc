#include "threadpool.ih"

void ThreadPool::stop()
{
    if (!d_stopped)
    {
        d_stopped = true;
        
        d_jobq.shutdown();
    
        for (auto &worker : d_workers)
        {
            if (worker.joinable())
                worker.join();
        }
    }
}