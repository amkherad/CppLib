//
//

#ifndef CPPLIB_CONDITIONALLOCKTARGET_HPP
#define CPPLIB_CONDITIONALLOCKTARGET_HPP

#include <pthread.h>

namespace CppLib {

    class ConditionalLockTarget {
    private:
        __pthread_mutex_s _mutex;
        __pthread_cond_s _condition;

    public:
        ConditionalLockTarget();

        void* getMutex();
        void* getTargetPtr();
    };

}

#endif //CPPLIB_CONDITIONALLOCKTARGET_HPP
