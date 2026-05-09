#include "functions.ih"

size_t defaultWorkerCount()
{
    size_t cpu = thread::hardware_concurrency();
    if (cpu == 0)
        return 2;

    return min<size_t>(cpu, 8);
}