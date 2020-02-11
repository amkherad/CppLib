//
//

#include "Thread.hpp"
#include <pthread.h>


namespace CppLib {

    Thread::Thread(ThreadCallback *callback) {

    }

    Thread::Thread(ThreadCallbackWithState *callback, void *state) {

    }

    void Thread::join() {

    }



    void CppLib::Thread::yield() {
        pthread_yield();
    }

    void Thread::sleep(unsigned int milliseconds) {

    }

    void Thread::ensureInitialized(void **ptr, void *(*initilizer)()) {

    }
}