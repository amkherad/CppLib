//
//

#ifndef CPPLIB_THREADPOOLJOBINFO_HPP
#define CPPLIB_THREADPOOLJOBINFO_HPP


#include "ThreadPool.hpp"

namespace CppLib {

    typedef void ThreadPoolCallback();

    typedef void ThreadPoolCallbackWithState(void *state);


    class ThreadPoolJobInfo {
    private:
        ThreadPoolCallback *_voidCallback;

        ThreadPoolCallbackWithState *_stateCallback;

        void *_state;

        bool _isWithState;

    public:
        explicit ThreadPoolJobInfo(ThreadPoolCallback* callback);

        explicit ThreadPoolJobInfo(ThreadPoolCallbackWithState* callback, void* state);

        void execute();

    };

}

#endif //CPPLIB_THREADPOOLJOBINFO_HPP
