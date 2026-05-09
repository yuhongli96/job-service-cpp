#include "jobmanager.ih"

JobManager::JobManager()
:   
   d_threadpool(d_jobq, defaultWorkerCount())
{
    d_threadpool.start();
}