//
//

#ifndef CPPLIB_THREADPOOLJOBINFO_HPP
#define CPPLIB_THREADPOOLJOBINFO_HPP


#include "ThreadPool.hpp"

class ThreadPoolJobInfo {
public:

    ThreadPoolCallback* _voidCallback;

    ThreadPoolCallbackWithState* _stateCallback;

    void* _state;

};


#endif //CPPLIB_THREADPOOLJOBINFO_HPP
