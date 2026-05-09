#include "jobqueue.ih"

void JobQueue::push(shared_ptr<Job> job)
{
    {
        lock_guard<mutex> lock(d_mutex);
        d_queue.push(job);
    }                                   // unlock
    d_condition.notify_one();           // wake up one waiting worker
}