//
//

#include "ThreadPool.hpp"
#include <Thread.hpp>
#include <data/LinkedList.hpp>
#include <ThreadPoolJobInfo.hpp>
#include <Monitor.hpp>

namespace CppLib {


    ThreadPool::ThreadPool() {

        _continue = true;

        _workerThreads = std::make_unique<LinkedList<Thread *>>();
        _jobs = std::make_unique<LinkedList<ThreadPoolJobInfo *>>();
        _exclusiveLock = std::make_unique<Mutex>();

        _minWorkerThreads = 0;
        _maxWorkerThreads = 100;

    }

    ThreadPool::~ThreadPool() {

        this->stop();

        for (int i = 0; i < _jobs->count(); i++) {

            ThreadPoolJobInfo *job = _jobs->get(i);

            delete job;
        }

        for (int i = 0; i < _workerThreads->count(); i++) {

            Thread *thread = _workerThreads->get(i);

            delete thread;
        }

    }

    void ThreadPool::queueWorkItem(ThreadPoolCallback *callback) {

        _exclusiveLock->waitOne();

        auto job = new ThreadPoolJobInfo(callback);

        _jobs->append(job);

        _exclusiveLock->release();

        Monitor::pulseOne(*this->_conditionalLock);

    }

    void ThreadPool::queueWorkItem(ThreadPoolCallbackWithState *callback, void *state) {

        _exclusiveLock->waitOne();

        auto job = new ThreadPoolJobInfo(callback, state);

        _jobs->append(job);

        _exclusiveLock->release();

        Monitor::pulseOne(*this->_conditionalLock);

    }

    void ThreadPool::setWorkerThreads(int minWorkerThreads, int maxWorkerThreads) {

        auto threads = _workerThreads->count();

        auto threadsToBeCreated = 0;

        if (threads < minWorkerThreads) {

            threadsToBeCreated = minWorkerThreads - threads;
        }

        if (threadsToBeCreated > 0) {

            for (int i = 0; i < threadsToBeCreated; i++) {

                Thread *thread = this->createThread();

                _workerThreads->append(thread);

            }
        }

        this->_minWorkerThreads = minWorkerThreads;
        this->_maxWorkerThreads = maxWorkerThreads;
    }

    Thread *ThreadPool::createThread() {

        auto thread = new Thread(ExecuteThread, this);

        return thread;
    }

    void ThreadPool::ExecuteThread(void *stt) {

        auto that = static_cast<ThreadPool *>(stt);

        while (that->_continue) {

            ThreadPoolJobInfo *jobInfo = nullptr;

            that->_exclusiveLock->waitOne();

            if (that->_jobs->count() > 0) {

                jobInfo = that->_jobs->pop();

            }

            that->_exclusiveLock->release();


            if (jobInfo != nullptr) {

                jobInfo->execute();

            }

            if (!that->_continue) {

                return;

            }

            //that->_parkedThreads

            Monitor::wait(*that->_conditionalLock);

        }
    }

    void ThreadPool::stop() {

        //TODO: synchronization required.
        _continue = false;

        Monitor::pulseAll(*this->_conditionalLock);

        for (int i = 0; i < _workerThreads->count(); i++) {

            Thread *thread = _workerThreads->get(i);

            thread->join();

        }

    }
}