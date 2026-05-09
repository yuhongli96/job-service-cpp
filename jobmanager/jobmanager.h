#ifndef INCLUDED_JOBMANAGER_
#define INCLUDED_JOBMANAGER_

#include "../job/job.h"
#include "../jobqueue/jobqueue.h"
#include "../threadpool/threadpool.h"
#include <map>
#include <memory>

class JobManager
{
    std::map<size_t, std::shared_ptr<Job>> d_map;
    JobQueue d_jobq;
    ThreadPool d_threadpool;
    size_t d_thisJobID = 0;

    public:
        JobManager();                   // 1
        JobManager(size_t workerCount); // 2

        size_t submit(std::string const &filename);    
        JobStatus status(size_t jobID) const;
        void result(size_t jobID) const;
        void list() const;
        void stop();
};

#endif