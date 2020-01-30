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

        // continue to execute async tasks while release is not called.
        while (this->_continue) {

            // tries to pull a task from the task queue and execute it on current captured thread (current execution context).
            if (!this->pullAndExecute()) {

                if (this->_continue) {

                    // yields the remaining time-slice to another job.
                    Thread::yield();

                }
            }

        }

    }

    bool TaskScheduler::pullAndExecute() {

    }


    void TaskScheduler::release() {

    }


    void TaskScheduler::schedule(const AsyncTask &asyncTask) {

    }

}