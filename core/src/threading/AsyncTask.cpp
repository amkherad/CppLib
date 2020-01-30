//
//

#include "AsyncTask.hpp"

namespace CppLib {

    AsyncTask::AsyncTask() {

    }

    AsyncTask::~AsyncTask() {

    }

    bool AsyncTask::isFinished() {
        return false;
    }

    bool AsyncTask::isError() {
        return false;
    }

    template<typename T>
    T AsyncTask::result() {
        return nullptr;
    }

}