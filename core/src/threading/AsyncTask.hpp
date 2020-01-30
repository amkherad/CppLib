//
//

#ifndef CPPLIB_ASYNCTASK_HPP
#define CPPLIB_ASYNCTASK_HPP

namespace CppLib {

    class AsyncTask {

    public:
        AsyncTask();

        ~AsyncTask();


        bool isFinished();

        bool isError();


        template <typename T>
        T result();

    };

}

#endif //CPPLIB_ASYNCTASK_HPP
