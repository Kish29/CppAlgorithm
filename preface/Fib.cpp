//
// Created by 蒋澳然 on 2021/7/3.
//

#include "TimeMeasure.h"

class Fib : public TimeMeasureExe {

    const int SAMPLE = 80;

public:

    long fibRecursive(int n) {
        if (n <= 0) return 0;
        if (n == 1 || n == 2) return 1;
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    long fibLoop(int n) {
        if (n <= 0) return 0;
        if (n == 1 || n == 2) return 1;
        long n1 = 1, n2 = 1;
        long res{};
        for (int i = 3; i <= n; ++i) {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
        }
        return res;
    }

    void exe() override {
        long res = fibLoop(SAMPLE);
        printf("res -> %ld\n", res);
    }

    ~Fib() override = default;
};

/*int main() {
    Fib fib;
    timeMeasure->measureTime(fib);
}*/
