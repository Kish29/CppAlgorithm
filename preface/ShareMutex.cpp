//
// Created by 蒋澳然 on 2021/7/9.
//

#include "timemeasure/TimeMeasure.h"


boost::shared_mutex rw_mtx;
int32_t data = 1;


namespace thread_concurrency {
    void read(string &name) {
        read_lock lck(rw_mtx);
        Println(name + " entered, and read data");
        Println("data is " + to_string(data));
    }

    void write(string &name) {
        write_lock lck(rw_mtx);
        Println(name + " entered, and change data");
        data++;
    }
}


/*
int main() {
    string reader1 = "reader1";
    string reader2 = "reader2";
    string writer1 = "writer1";
    string writer2 = "writer2";
    boost::thread_group tg;
    tg.create_thread([&]() -> void {
        thread_concurrency::write(writer1);
    });
    tg.create_thread([&]() -> void {
        thread_concurrency::write(writer2);
    });
    tg.create_thread([&]() -> void {
        thread_concurrency::read(reader1);
    });
    tg.create_thread([&]() -> void {
        thread_concurrency::read(reader2);
    });
    tg.join_all();
}*/
