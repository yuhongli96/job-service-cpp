#ifndef INCLUDED_JOBQUEUE_
#define INCLUDED_JOBQUEUE_

#include "../job/job.h"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>   // shared_ptr
#include <atomic>

class JobQueue
{
    std::queue<std::shared_ptr<Job>> d_queue;
    std::mutex d_mutex;
    std::condition_variable d_condition;
    std::atomic<bool> d_shutdown = false;
    
    public:
        void push(std::shared_ptr<Job> job);
        std::shared_ptr<Job> pop();
        void shutdown();
};

#endif