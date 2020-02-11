//
//

#ifndef CPPLIB_THREADPOOL_HPP
#define CPPLIB_THREADPOOL_HPP

#include "Mutex.hpp"
#include "Monitor.hpp"
#include "ThreadPoolJobInfo.hpp"
#include <memory>

namespace CppLib {

    template <typename T>
    class LinkedList;

    struct ThreadPoolJobInfo;

    class Thread;

    class ThreadPool {
    private:
        std::unique_ptr<LinkedList<ThreadPoolJobInfo*>> _jobs;
        std::unique_ptr<Mutex> _exclusiveLock;

        std::unique_ptr<LinkedList<Thread*>> _workerThreads;

        int _minWorkerThreads;
        int _maxWorkerThreads;

        std::atomic<int> _parkedThreads;

        bool _continue;

        std::unique_ptr<Monitor::ConditionalLockTarget> _conditionalLock;

        Thread* createThread();

        static void ExecuteThread(void* stt);

    public:
        ThreadPool();

        ~ThreadPool();


        /**
         * Sets the minimum and maximum parked threads in the thread pool.
         * @param minWorkerThreads minimum parked threads.
         * @param maxWorkerThreads maximum parked threads.
         */
        void setWorkerThreads(int minWorkerThreads, int maxWorkerThreads);


        void stop();


        void queueWorkItem(ThreadPoolCallback *callback);

        void queueWorkItem(ThreadPoolCallbackWithState *callback, void* state);
    };

}

#endif //CPPLIB_THREADPOOL_HPP
