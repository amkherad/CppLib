//
//

#include "TaskScheduler.hpp"
#include "AsyncTask.hpp"
#include <Thread.hpp>
#include <ThreadPool.hpp>

namespace CppLib {

    TaskScheduler::TaskScheduler(const ThreadPool& threadPool) {

        this->_continue = true;

        this->_tasks = new LinkedList<AsyncTask*>();
        this->_threadPool = const_cast<ThreadPool*>(&threadPool);

    }


    int TaskScheduler::captureCurrentThread() {

        this->_continue = true;

        // continue to execute async tasks while release is not called.
        while (this->_continue) {

            // tries to pull a task from the task queue and execute it on current captured thread (current execution context).
            if (!this->pullAndExecute()) {

                if (this->_continue && this->isEmpty()) {

                    // yields the remaining time-slice to another job.
                    Thread::yield();

                }
            }

        }

        return 0;

    }

    bool TaskScheduler::pullAndExecute() {

    }

    bool TaskScheduler::isEmpty() {
        return _tasks->count() == 0;
    }


    void TaskScheduler::release() {
        this->_continue = false;
    }


    void TaskScheduler::schedule(const AsyncTask &asyncTask) {

        this->_threadPool->queueWorkItem(asyncTask)

    }

}