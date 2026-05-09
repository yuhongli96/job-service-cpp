#include "benchmark.ih"

namespace
{
    bool parseWorkerCount(int argc, char **argv, size_t &workerCount)
    {
        if (argc != 2)
            return false;

        string input = argv[1];

        size_t pos = 0;

        try
        {
            workerCount = stoul(input, &pos);

            if (pos != input.size())    // input is not pure numbers
                return false;

            if (workerCount > defaultWorkerCount() || workerCount == 0)
                return false;

            return true;
        }
        catch (exception const &)
        {
            return false;
        }
    }

    void usage(char const *programName)
    {
        cerr << "Usage: " << programName << " <worker-count>\n" <<
                "<worker-count> needs to be larger than 0 and smaller than " << defaultWorkerCount() + 1 << "\n"
                "Example: " << programName << " 4\n";
    }
}

int main(int argc, char **argv)
{
    size_t workerCount = 0;
    if (!parseWorkerCount(argc, argv, workerCount))
    {
        usage(argv[0]);
        return 1;
    }

    JobManager manager{workerCount};
        
    vector<string> files(10, "tests/large.txt"s);

    vector<size_t> jobIDs;

    auto start = chrono::steady_clock::now();

    for (auto const &file : files)
    {
        size_t id = manager.submit(file);
        jobIDs.push_back(id);
    }

    bool allFinished = false;

    while (!allFinished)
    {
        allFinished = true;

        for (size_t id : jobIDs)
        {
            JobStatus status = manager.status(id);

            if (status == JobStatus::PENDING ||
                status == JobStatus::RUNNING)
            {
                allFinished = false;
                break;
            }            
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    auto end = chrono::steady_clock::now();

    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    manager.stop();

    cout << "Benchmark finished\n";
    cout << "Jobs: " << jobIDs.size() << '\n';
    cout << "Total time: " << milliseconds << " ms\n";

    double seconds = milliseconds / 1000.0;
    std::cout << "Throughput: " << jobIDs.size() / seconds << " jobs/sec\n";
}