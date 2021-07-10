//
// Created by 蒋澳然 on 2021/7/8.
//

#include "timemeasure/TimeMeasure.h"

struct empty_stack : public std::exception {
    const char *what() const noexcept override {
        return "empty stack!";
    }
};

template<class T>
class threadsafe_stack {

    // 通过创建一个函数生命周期（通过"{}"确定生命周期）的lock_guard来保证锁的释放
#define GET_LOCK(m) std::lock_guard<std::mutex> lock(m)

private:
    stack<T> data{};
    // mutable的一个经典使用场景就是互斥量，在const成员方法中仍然可以改变
    mutable std::mutex m{};

public:
    threadsafe_stack() : data(stack<int>()) {}

    threadsafe_stack(const threadsafe_stack<T> &other) {
        // 要访问other的data成员
        GET_LOCK(other.m);
        this->data = stack<T>(other.data);
    }

    threadsafe_stack &operator=(const threadsafe_stack<T> &other) = delete;

    void push(T new_value) {
        GET_LOCK(m);
        data.push(move(new_value));
    }

    std::shared_ptr<T> pop() {
        GET_LOCK(m);
//        if (data.empty()) throw empty_stack();
        if (data.empty()) return nullptr;
        shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T &value) {
        GET_LOCK(m);
//        if (data.empty()) throw empty_stack();
        if (data.empty()) return;
        value = data.top();
        data.pop();
    }

    bool empty() const {
        GET_LOCK(m);
        return data.empty();
    }

    size_t size() const {
        GET_LOCK(m);
        return data.size();
    }


};

const unsigned coreNum = thread::hardware_concurrency();
threadsafe_stack<int> tss;
vector<thread> threadPool;

void threadWork(bool flag) {
    // true表示取元素
    if (flag) {
        Println("pop");
        for (int i = 0; i < 10; ++i) {
            tss.pop();
        }
    } else {
        Println("push");
        for (int i = 0; i < 10; ++i) {
            tss.push(uidis(dre));
        }
    }
}

/*
int main() {
    auto seed = time(nullptr);
    srand(seed);
    threadPool.reserve(coreNum);
    for (int i = 0; i < coreNum; ++i) {
        threadPool.emplace_back(thread{threadWork, static_cast<bool >(ubdis(dre))});
    }
    for (thread &t: threadPool) {
        t.join();
    }
    while (!tss.empty()) {
        Println(*tss.pop());
    }
}*/
