//
//

#ifndef CPPLIB_THREADPOOLJOBINFO_HPP
#define CPPLIB_THREADPOOLJOBINFO_HPP


#include "ThreadPool.hpp"

struct ThreadPoolJobInfo {
public:

    ThreadPoolCallback* voidCallback;

    ThreadPoolCallbackWithState* stateCallback;

    void* state;

};


#endif //CPPLIB_THREADPOOLJOBINFO_HPP
