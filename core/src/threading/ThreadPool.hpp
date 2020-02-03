//
//

#ifndef CPPLIB_THREADPOOL_HPP
#define CPPLIB_THREADPOOL_HPP

#include "Mutex.hpp"

typedef void ThreadPoolCallback();

typedef void ThreadPoolCallbackWithState(void *state);

namespace CppLib {

    template <typename T>
    class LinkedList;

    struct ThreadPoolJobInfo;

    class Thread;

    class ThreadPool {
    private:
        LinkedList<ThreadPoolJobInfo>* _jobs;
        Mutex* _exclusiveLock;

        LinkedList<Thread>* _workerThreads;

    public:
        ThreadPool();

        ~ThreadPool();

        void queueWorkItem(ThreadPoolCallback *callback);

        void queueWorkItem(ThreadPoolCallbackWithState *callback, void* state);
    };

}

#endif //CPPLIB_THREADPOOL_HPP
