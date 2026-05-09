#include "jobmanager.ih"

JobManager::JobManager(size_t workerCount)
:   
   d_threadpool(d_jobq, workerCount)
{
    d_threadpool.start();
}