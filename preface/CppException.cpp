//
// Created by 蒋澳然 on 2021/7/6.
//

#include "TimeMeasure.h"

class MyException : virtual public std::exception {
    const char *what() const noexcept override {
        return "myexception";
    }
};