//
//

#ifndef CPPLIB_TASKSCHEDULER_HPP
#define CPPLIB_TASKSCHEDULER_HPP

namespace CppLib {

    typedef void TaskCallback(void *state);

    class AsyncTask;

    class TaskScheduler {
    private:

    public:
        TaskScheduler();

        ~TaskScheduler();


        int captureCurrentThread();

        void release();


        void add(TaskCallback *fn, void *state);

        void flush();

    };

}

#endif //CPPLIB_TASKSCHEDULER_HPP
