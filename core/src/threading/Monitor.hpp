//
//

#ifndef CPPLIB_MONITOR_HPP
#define CPPLIB_MONITOR_HPP

namespace CppLib {

    class Monitor {
    public:
        class ConditionalLockTarget {

        };

        static void* createLockTarget();

        static void pulseOne(const ConditionalLockTarget &lockTarget);

        static void pulseAll(const ConditionalLockTarget &lockTarget);

        static void wait(const ConditionalLockTarget &lockTarget);

        static void wait(const ConditionalLockTarget &lockTarget, unsigned int timeoutInMilliseconds);

    };

}

#endif //CPPLIB_MONITOR_HPP
