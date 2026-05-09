#include "jobmanager.ih"

void JobManager::result(size_t jobID) const
{
    auto iter = d_map.find(jobID);

    if (iter == d_map.end())
    {
        cout << "Job not found\n";
        return;
    }
    
    auto const &ptrJob = iter->second;
    lock_guard<mutex> lock(ptrJob->d_mutex);

    if (ptrJob->d_status == JobStatus::PENDING || 
        ptrJob->d_status == JobStatus::RUNNING)
    {
        cout << "Job is not finished yet\n";
        return;
    }

    if (ptrJob->d_status == JobStatus::FAILED)
    {
        cout << "Job failed: " << ptrJob->d_errorMsg << '\n';
        return;
    }

    cout << "Lines: " << ptrJob->d_result.d_lineCount << "\n"
            "Words: " << ptrJob->d_result.d_wordCount << "\n"
            "Characters: " << ptrJob->d_result.d_charCount << "\n";
}