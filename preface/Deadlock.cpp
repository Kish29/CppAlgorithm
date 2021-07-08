//
// Created by 蒋澳然 on 2021/7/8.
//

/* 使用同一级的耦合相关多次获取锁来表现死锁 */
#include "timemeasure/TimeMeasure.h"

template<class T>
struct LockHolder {
    T val{};
    string name = "default-" + static_cast<string >(val);
    std::mutex lock{};

    LockHolder() = default;

    explicit LockHolder(T v) : val(move(v)) {}
};

template<class T>
void work(T &a, T &b) {
    // do something here
}

template<class T>
void deadlock(LockHolder<T> &l1, LockHolder<T> &l2) {
    // 获取l1的锁
    l1.lock.lock();
    Println(currentThreadName() + " get " + l1.name + " 's lock!\n");
    // 获取l2的锁
    l2.lock.lock();
    Println(currentThreadName() + " get " + l2.name + " 's lock!\n");
    // do something here
    work(l1.val, l2.val);
}

template<class T>
void lockSafe(LockHolder<T> &l1, LockHolder<T> &l2) {
    // 管理l1的锁资源和生命周期，使用defer推迟锁的获取
    std::unique_lock<std::mutex> ul1(l1.lock, std::defer_lock);
    Println(currentThreadName() + " manage " + l1.name + " 's lock!\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 管理l2的锁资源和生命周期，使用defer推迟锁的获取
    std::unique_lock<std::mutex> ul2(l2.lock, std::defer_lock);
    Println(currentThreadName() + " manage " + l2.name + " 's lock!\n");

    // do something here
    std::lock(ul1, ul2);
    Println(currentThreadName() + " lock the two locks");
    work(l1.val, l2.val);
}

template<class T>
void lockSafe2(LockHolder<T> &l1, LockHolder<T> &l2) {
    // do something here
    std::lock(l1.lock, l2.lock);
    Println(currentThreadName() + " lock the two locks");

    // 使用adopt管理l1的锁资源和生命周期
    std::unique_lock<std::mutex> ul1(l1.lock, std::adopt_lock);
    Println(currentThreadName() + " adopt " + l1.name + " 's lock!\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 使用adopt管理l2的锁资源和生命周期
    std::unique_lock<std::mutex> ul2(l2.lock, std::adopt_lock);
    Println(currentThreadName() + " adopt " + l2.name + " 's lock!\n");

    work(l1.val, l2.val);
}

int main() {
    LockHolder<string> l1("jar");
    LockHolder<string> l2("lzy");

    thread t1{[&]() -> void {
        pthread_setname_np("thread-t1");
//        deadlock(l1, l2);
//        lockSafe(l1, l2);
        lockSafe2(l1, l2);
    }};
    thread t2{[&]() -> void {
        pthread_setname_np("thread-t2");
//        deadlock(l2, l1);
//        lockSafe(l2, l1);
        lockSafe2(l2, l1);
    }};

    t1.join();
    t2.join();
}