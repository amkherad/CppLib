//
//

#ifndef CPPLIB_THREADPOOL_HPP
#define CPPLIB_THREADPOOL_HPP

#include "Mutex.hpp"
#include <memory>

typedef void ThreadPoolCallback();

typedef void ThreadPoolCallbackWithState(void *state);

namespace CppLib {

    template <typename T>
    class LinkedList;

    struct ThreadPoolJobInfo;

    class Thread;

    class ThreadPool {
    private:
        std::unique_ptr<LinkedList<ThreadPoolJobInfo>> _jobs;
        std::unique_ptr<Mutex> _exclusiveLock;

        std::unique_ptr<LinkedList<Thread>> _workerThreads;

    public:
        ThreadPool();

        ~ThreadPool();

        void queueWorkItem(ThreadPoolCallback *callback);

        void queueWorkItem(ThreadPoolCallbackWithState *callback, void* state);
    };

}

#endif //CPPLIB_THREADPOOL_HPP
