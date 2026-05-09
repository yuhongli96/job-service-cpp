#include "functions.ih"

void list(JobManager &jobManager)
{
    cout << "Jobs:\n";
    jobManager.list();
}