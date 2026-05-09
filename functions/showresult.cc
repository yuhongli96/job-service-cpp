#include "functions.ih"

void showResult(JobManager &jobManager)
{
    cout << "Enter job ID: ";
    size_t jobID;               
    cin >> jobID;
    cout << "Job " << jobID << " result:\n";
    jobManager.result(jobID);
}