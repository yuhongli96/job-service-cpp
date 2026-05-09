#include "job.ih"

ostream &operator<<(ostream &out, JobStatus const &status)
{
    switch (status)
    {
        case JobStatus::PENDING:
            out << "Pending";
        break;

        case JobStatus::RUNNING:
            out << "Running";
        break;

        case JobStatus::DONE:
            out << "Done";
        break;

        case JobStatus::FAILED:
            out << "Failed";
        break;

        case JobStatus::NOT_FOUND:
            out << "Not found";
        break;
    }
    
    return out;
}