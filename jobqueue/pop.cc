#include "jobqueue.ih"

shared_ptr<Job> JobQueue::pop()
{
    unique_lock<mutex> lock(d_mutex);

                                        // keep locked until d_queue has something or shutdown is requested
    d_condition.wait(lock, [this]() -> bool    
                            {
                                return !d_queue.empty() || d_shutdown;
                            });

    if (d_shutdown && d_queue.empty())  // shutdown after all jobs are popped
        return nullptr;
    
    auto job = d_queue.front();
    d_queue.pop();
    return job;
}