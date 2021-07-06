//
// Created by 蒋澳然 on 2021/7/6.
//

#include "TimeMeasure.h"

// ok
void lambda1() {
    int (*l)(int) = [](int a) -> int {
        printf("hello world %d\n", a);
        return a + 2;
    };
    int res = l(9);
    printf("%d\n", res);
}

// error，当存在capture时，已经不再是一个简单的函数指针了
void lambda2() {
    /*int t = 100;
    int (*l)(int) = [&t](int a) -> int {
        printf("hello world %d\n", a);
        return a + 2;
    };
    int res = l(9);
    printf("%d\n", res);*/
}

// ok，c++11 function
void lambda3() {
    int a = 100;
    int b = 99;
    std::function<int(int)> l = [x = a, &b](int a) -> int {
        // a被参数覆盖了作用域，使用capture还是参数和编译器有关，所以lambda规范禁止这样写
        printf("hello world %d\n", a);
        printf("outer a is %d, b is %d\n", x, b);
        return a + 2;
    };
    int res = l(9);
    printf("%d\n", res);
}

// ok，c++11 function pointer
std::function<int(int)> *lambda4() {
    int t = 100;
    auto *l = new std::function<int(int)>{
            [=, &t](int a) -> int {
                printf("hello world %d\n", a);
                return a + 2;
            }
    };
    int res = (*l)(9);
    printf("%d\n", res);
    return l;
}

class Lambda : public TimeMeasureExe {

public:
    void exe() override {
        lambda1();
        lambda2();
        lambda3();
        auto func = lambda4();
        delete func;
    }

    ~Lambda() override {
        printf("Lambda destructor called!\n");
    }
};

/*
int main() {
    Lambda lambda;
    timeMeasure->measureTime(lambda);
    return 0;
}*/
