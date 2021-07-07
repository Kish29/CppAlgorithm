//
// Created by 蒋澳然 on 2021/7/7.
//

#include "TimeMeasure.h"

const double cnm = 2134.121512512616161624124;
const double factor = 123.4212521512512351235;

const unsigned CORE_NUM = std::thread::hardware_concurrency();
std::atomic_int16_t threadCheck(static_cast<int16_t>(CORE_NUM));

void threadWork(int i);

void expensiveFunc();

class UseConcurrency : public TimeMeasureExe {

public:
    void exe() override {
        vector<thread> threadPool{};
        threadPool.reserve(CORE_NUM);
        for (int i = 0; i < CORE_NUM; ++i) {
            threadPool.emplace_back(thread(threadWork, i));
        }
        for (thread &t: threadPool) {
            // join可以简单的看成是阻塞式调用
//            t.join();
            t.detach();
        }
//        Println("Now all background threads are done in " + currentThreadName());
    }
};

class UserSerial : public TimeMeasureExe {
public:
    void exe() override {
        for (int i = 0; i < CORE_NUM; ++i) {
            expensiveFunc();
        }
    }
};

int main() {
    pthread_setname_np("thread-main");
    UseConcurrency useConcurrency;
    UserSerial userSerial;
    timeMeasure->setTimeUnit(MILLISECONDS);
    auto time1 = timeMeasure->measureTime(useConcurrency);
    Println("Waiting for all background threads work done");
    while (threadCheck);
    Println("Now all background threads are done in " + currentThreadName());
    auto time2 = timeMeasure->measureTime(userSerial);
    Println("Use concurrency decrease time " + to_string(((double) (time2 - time1) / (double) time2) * 100) + "%");
}

void threadWork(int i) {
    // change thread name
    string newName = "thread-" + to_string(i);
    pthread_setname_np(newName.c_str());
    expensiveFunc();
    threadCheck--;
}

void expensiveFunc() {
    Println("expensiveFunc called from " + currentThreadName());
    int loop = 10000000;
    double res{};
    for (int i = 0; i < loop; ++i) {
        res = pow(cnm, factor);
    }
}
