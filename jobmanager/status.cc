#include "jobmanager.ih"

JobStatus JobManager::status(size_t jobID) const
{
    auto iter = d_map.find(jobID);

    if (iter == d_map.end())
        return JobStatus::NOT_FOUND;

    lock_guard<mutex> lock(iter->second->d_mutex);
    return iter->second->d_status;
}