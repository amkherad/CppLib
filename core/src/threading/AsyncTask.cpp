//
//

#include "AsyncTask.hpp"

namespace CppLib {

    template<typename T>
    AsyncTask<T>::AsyncTask() {

    }

    template<typename T>
    AsyncTask<T>::~AsyncTask() {

    }

    template<typename T>
    bool AsyncTask<T>::isFinished() {
        return false;
    }

    template<typename T>
    bool AsyncTask<T>::isError() {
        return false;
    }

    template<typename T>
    T AsyncTask<T>::result() {
        return nullptr;
    }

    template<typename T>
    T AsyncTask<T>::wait() {
        return nullptr;
    }

}