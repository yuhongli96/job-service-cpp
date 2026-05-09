#include "jobmanager.ih"

void JobManager::list() const
{
    for (auto const &element : d_map)
    {
        lock_guard<mutex> lock(element.second->d_mutex);
        cout << '[' << element.first << "] " << element.second->d_status << '\n';
    }
}