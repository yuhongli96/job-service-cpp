#include "functions.ih"

void showStatus(JobManager &jobManager)
{
    cout << "Enter job ID: ";
    size_t jobID;
    cin >> jobID;
    cout << "Job " << jobID << " status: " << jobManager.status(jobID) << '\n';
}