#ifndef INCLUDED_JOB_
#define INCLUDED_JOB_

#include <string>
#include <iosfwd>
#include <mutex>

enum class JobStatus
{
    PENDING,
    RUNNING,
    DONE,
    FAILED,
    NOT_FOUND
};

std::ostream &operator<<(std::ostream &out, JobStatus const &status);

struct JobResult
{
    size_t d_lineCount = 0;
    size_t d_wordCount = 0;
    size_t d_charCount = 0;
};

struct Job
{
    size_t d_id;
    JobStatus d_status = JobStatus::PENDING;
    std::string d_inputPath;
    JobResult d_result;
    std::string d_errorMsg;
    std::mutex d_mutex;
};

#endif