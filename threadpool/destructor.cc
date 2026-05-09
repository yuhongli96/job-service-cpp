#include "threadpool.ih"

ThreadPool::~ThreadPool()
{
    stop();
}