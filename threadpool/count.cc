#include "threadpool.ih"

void ThreadPool::count(Job &job)
{
    {
        lock_guard<mutex> lock(job.d_mutex);
        job.d_status = JobStatus::RUNNING;
    }

    ifstream in(job.d_inputPath);
                    
    if (!in)                            // check if in opened successfully
    {
        lock_guard<mutex> lock(job.d_mutex);
        job.d_errorMsg = "Cannot open file: " + job.d_inputPath;
        job.d_status = JobStatus::FAILED;
        return;
    }
    
    size_t lineCount = 0;
    size_t wordCount = 0;
    size_t charCount = 0;

    char ch;
    bool insideWord = false;
    bool sawAnyChar = false;
    bool lastWasNewLine = false;

    while (in.get(ch))
    {
        sawAnyChar = true;
        ++charCount;                    // count char

        if (ch == '\n')                 // count line
        {    
            ++lineCount;
            lastWasNewLine = true;
        }
        else 
            lastWasNewLine = false;
        
        if (isspace(static_cast<unsigned char>(ch)))
            insideWord = false;
        else          
        {
            if (!insideWord)            // count word
                ++wordCount;
             
            insideWord = true;           
        }
    }

    if (sawAnyChar && !lastWasNewLine)
        ++lineCount;                    // add the last line that doesn't have '\n'

    // if (charCount % 100000 == 0)
    //     this_thread::sleep_for(chrono::seconds(20));

    {
        lock_guard<mutex> lock(job.d_mutex);

        job.d_result.d_lineCount = lineCount;
        job.d_result.d_wordCount = wordCount;
        job.d_result.d_charCount = charCount;
        job.d_status = JobStatus::DONE;
    }
}