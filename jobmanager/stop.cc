#include "jobmanager.ih"

void JobManager::stop()
{
    d_threadpool.stop();
    cout << "Exiting...\n";
}