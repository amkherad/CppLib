//
//

#include "Thread.hpp"
#include <pthread.h>


namespace CppLib {

    void CppLib::Thread::yield() {
        pthread_yield();
    }

    void Thread::sleep(unsigned int milliseconds) {

    }
}