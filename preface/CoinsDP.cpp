//
// Created by 蒋澳然 on 2021/7/4.
//

#include "TimeMeasure.h"

class CoinsDP : public TimeMeasureExe {

public:

    // 普通递归解法
    int coinsDPNormal(int target, const vector<int> &faceValues) const {
        if (target == 0) return 0;
        if (target < 0) return -1;
        int res = target;
        for (int faceValue: faceValues) {
            int sub = coinsDPNormal(target - faceValue, faceValues);
            if (sub == -1) continue;
            res = min(sub + 1, res);
        }
        return res;
    }

    // 带备忘录的递归解法
    int coinsRecorderEntry(int target, const vector<int> &faceValues) const {
        unordered_map<int, int> recorder;
        return coinsRecorder(target, faceValues, recorder);
    }

    int coinsRecorder(int target, const vector<int> &faceValues, unordered_map<int, int> &recorder) const {
        if (target == 0) return 0;
        if (target < 0) return -1;
        if (recorder.find(target) != recorder.end()) {
            return recorder.find(target)->second;
        }
        int res = target;
        for (int faceValue: faceValues) {
            int sub = coinsRecorder(target - faceValue, faceValues, recorder);
            if (sub == -1) continue;
            res = min(sub + 1, res);
//            recorder.insert(make_pair(target, res));
            recorder.emplace(target, res);
        }
        return res;
    }

    // 迭代法
    int coinsIteration(int target, const vector<int> &faceValues) const {
        if (target <= 0) return 0;
        vector<int> dp(target + 1);
        // initialize
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = i;
        }
        for (int i = 1; i <= target; ++i) {
            for (int faceValue: faceValues) {
                if (i - faceValue < 0) continue;
                dp[i] = min(dp[i], dp[i - faceValue] + 1);
            }
        }
        return dp[target];
    }


    void exe() override {
        int n = 89;
        vector<int> faceValues = {1, 5, 10, 20, 50, 100};
        int minCoinsNum = coinsIteration(n, faceValues);
        cout << "min coins num -> " << minCoinsNum << endl;
    }

};

vector<int> *test1(int n) {
    auto *res = new vector<int>;
    res->push_back(1);
    res->push_back(2);
    res->push_back(3);
    return res;
}

const vector<int> *test2(int n) {
    auto *res = new vector<int>;
    res->push_back(1);
    res->push_back(2);
    res->push_back(3);
    return res;
}

