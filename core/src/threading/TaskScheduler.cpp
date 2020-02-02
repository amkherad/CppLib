//
//

#include "TaskScheduler.hpp"
#include "AsyncTask.hpp"
#include <Thread.hpp>

namespace CppLib {

    TaskScheduler::TaskScheduler() {

    }

    TaskScheduler::~TaskScheduler() {

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
        return _tasks.count() == 0;
    }


    void TaskScheduler::release() {
        this->_continue = false;
    }


    void TaskScheduler::schedule(const AsyncTask &asyncTask) {

    }

}