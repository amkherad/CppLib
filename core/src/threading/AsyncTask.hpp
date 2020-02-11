//
//

#ifndef CPPLIB_ASYNCTASK_HPP
#define CPPLIB_ASYNCTASK_HPP

namespace CppLib {

    template <typename T>
    class AsyncTask {

    public:
        AsyncTask();

        ~AsyncTask();


        bool isFinished();

        bool isError();


        T wait();


        T result();

    };

}

#endif //CPPLIB_ASYNCTASK_HPP
