//
//

#include "ThreadPool.hpp"
#include <Thread.hpp>
#include <data/LinkedList.hpp>
#include <ThreadPoolJobInfo.hpp>

namespace CppLib {


    ThreadPool::ThreadPool() {
        _workerThreads = new LinkedList<Thread>();
        _jobs = new LinkedList<ThreadPoolJobInfo>();
        _exclusiveLock = new Mutex();
    }

    ThreadPool::~ThreadPool() {

        _exclusiveLock->waitOne();



        _exclusiveLock->release();

        delete _exclusiveLock;
        delete _jobs;
    }

    void ThreadPool::queueWorkItem(ThreadPoolCallback *callback) {

        _exclusiveLock->waitOne();

        auto job = new ThreadPoolJobInfo();

        job->voidCallback = callback;

        _jobs->append(*job);

        _exclusiveLock->release();

    }

    void ThreadPool::queueWorkItem(ThreadPoolCallbackWithState *callback, void* state) {

        _exclusiveLock->waitOne();

        auto job = new ThreadPoolJobInfo();

        job->state = state;
        job->stateCallback = callback;

        _jobs->append(*job);

        _exclusiveLock->release();

    }
}