#include "jobmanager.ih"

size_t JobManager::submit(std::string const &filename)
{
    size_t jobID = ++d_thisJobID;

    auto ptrJob = make_shared<Job>();
    ptrJob->d_id = jobID;
    ptrJob->d_inputPath = filename;

    d_map[jobID] = ptrJob;
    
    d_jobq.push(ptrJob);

    return jobID;
}