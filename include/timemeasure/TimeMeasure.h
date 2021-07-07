//
// Created by 蒋澳然 on 2021/7/3.
//

#ifndef CPPALGORITHM_TIMEMEASURE_H
#define CPPALGORITHM_TIMEMEASURE_H

#include "BasicSTL.h"

const int SECOND_2_NANO = 1000000000;

enum TimeUnit {
    NANOSECONDS,
    MICROSECONDS,
    MILLISECONDS,
    SECONDS
};


class TimeMeasureExe {

public:
    virtual void exe() = 0;

    virtual ~TimeMeasureExe() {
        printf("Class-TimeMeasureExe destructor called!\n");
    };
};


class TimeMeasure {

    TimeUnit unit = NANOSECONDS;

public:

    TimeMeasure() = default;

    // 禁止编译器为我们生成默认复制构造函数和赋值构造函数
    // copy constructor
    TimeMeasure(const TimeMeasure &tm) = delete;

    // copy assignment
    TimeMeasure &operator=(const TimeMeasure &tm) = delete;

    ~TimeMeasure() = default;

    explicit TimeMeasure(TimeUnit u) : unit(u) {}

    void setTimeUnit(TimeUnit u = MICROSECONDS) {
        this->unit = u;
    }

    uint64_t measureTime(TimeMeasureExe &exe) const {
        struct timespec startTime{}, endTime{};
        clock_gettime(CLOCK_REALTIME, &startTime);
        exe.exe();
        clock_gettime(CLOCK_REALTIME, &endTime);
        uint64_t duration = (endTime.tv_sec - startTime.tv_sec) * SECOND_2_NANO + (endTime.tv_nsec - startTime.tv_nsec);
        switch (this->unit) {
            case MICROSECONDS:
                duration /= 1000;
                printf("duration -> %llu µs\n", duration);
                break;
            case MILLISECONDS:
                duration /= 1000000;
                printf("duration -> %llu ms\n", duration);
                break;
            case SECONDS:
                duration /= SECOND_2_NANO;
                printf("duration -> %llu s\n", duration);
                break;
            case NANOSECONDS:
            default:
                printf("duration -> %llu ns\n", duration);
                break;
        }
        return duration;
    }

};

static TimeMeasure *const timeMeasure = new TimeMeasure(MICROSECONDS);

#endif //CPPALGORITHM_TIMEMEASURE_H
