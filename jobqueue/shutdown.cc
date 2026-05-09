#include "jobqueue.ih"

void JobQueue::shutdown()
{
    d_shutdown.store(true);

    d_condition.notify_all();
}