//
//

#ifndef CPPLIB_TASKSCHEDULER_HPP
#define CPPLIB_TASKSCHEDULER_HPP

#include <LinkedList.hpp>
#include <memory>

namespace CppLib {

    class AsyncTask;
    class ThreadPool;

    class TaskScheduler {
    private:
        /**
         * Determines if captureCurrentThread method should continue to block the calling thread.
         *
         * @remarks Because this field is has been double checked in captureCurrentThread method,
         *          it's been marked as volatile to force compiler to read the value from memory instead of caching it in a register.
         */
        volatile bool _continue;

        ThreadPool* _threadPool;

        LinkedList<AsyncTask*>* _tasks;

    public:
        explicit TaskScheduler(const ThreadPool& threadPool);

        ~TaskScheduler();


        /**
         * Captures the calling thread to execute pending async tasks in task queue on the calling thread. (mainly the main thread)
         */
        int captureCurrentThread();

        /**
         * Releases the captured thread.
         */
        void release();


        /**
         * Pops one task from the async task queue and executes it on the calling thread.
         * @return true if a task was executed, otherwise false.
         */
        bool pullAndExecute();

        /**
         * Determines whether there are any more async tasks to be executed or not.
         * @return
         */
        bool isEmpty();

        /**
         * Schedules a new AsyncTask for async execution in the current TaskScheduler.
         * @param fn
         * @param state
         */
        void schedule(const AsyncTask& asyncTask);

    };

}

#endif //CPPLIB_TASKSCHEDULER_HPP
