//
//

#include <stdio.h>
#include <threading/TaskScheduler.hpp>
#include <iostream>

using namespace std;
using namespace CppLib;



int main(int argc, char* argv[]) {

    TaskScheduler scheduler;

    scheduler.add(
            [](void* stt) {
                cout << "Task1 was called.";
                },
            nullptr
            );

    scheduler.add(
            [](void* stt) {
                cout << "Task2 was called.";
                },
            nullptr
            );

    scheduler.captureCurrentThread();

}