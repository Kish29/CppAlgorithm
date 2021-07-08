//
// Created by 蒋澳然 on 2021/7/8.
//

#include "timemeasure/TimeMeasure.h"

class data_chunk {
public:

    string flag{};
    ul id{};

    data_chunk(string f, ul i) : flag(move(f)), id(i) {}

};

std::mutex mut{};
std::queue<data_chunk> data_queue{};
std::condition_variable data_cond{};

void process(data_chunk &d) {
    // do something here
    Println("data is " + d.flag + ", " + to_string(d.id));
}

data_chunk &produce() {
    return *(new data_chunk("jar", 100));
}

[[noreturn]] void data_preparation_thread() {
    while (true) {
        data_chunk const data = produce();
        std::unique_lock<std::mutex> lk(mut);
        data_queue.emplace(data);
        data_cond.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

[[noreturn]] void data_procession_thread() {
    while (true) {
        std::unique_lock<std::mutex> lk(mut);
        // 等待data_queue不为空的时候，执行后续代码
        data_cond.wait(lk, []() -> bool { return !data_queue.empty(); });
        data_chunk data = data_queue.front();
        data_queue.pop();
        lk.unlock();
        process(data);
    }
}

class Synchronize : public TimeMeasureExe {

public:
    void exe() override {
        thread producer(data_preparation_thread);
        thread consumer(data_procession_thread);
        consumer.join();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        producer.join();
    }
};

/*int main() {
    Synchronize synchronize;
    timeMeasure->measureTime(synchronize);
    Println("exe() has returned");
}*/
