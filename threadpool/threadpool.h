#ifndef INCLUDED_THREADPOOL_
#define INCLUDED_THREADPOOL_

#include "../jobqueue/jobqueue.h"
#include <vector>
#include <thread>

class ThreadPool
{
    JobQueue &d_jobq;
    std::vector<std::thread> d_workers;
    size_t d_workerCount;
    bool d_stopped = false;

    public:
        ThreadPool(JobQueue &jobq, size_t workerCount);
        ~ThreadPool();
        void start();
        void stop();
    
    private:
        void workerLoop();
        void count(Job &job);
};

#endif