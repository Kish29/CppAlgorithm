//
// Created by 蒋澳然 on 2021/7/4.
//

#include "TimeMeasure.h"
#include "vector"

using std::vector;

class Permute : public TimeMeasureExe {

    vector<vector<int>> res{};

    bool contains(const vector<int> &container, int target) const {
        if (container.empty()) return false;
        if (container.size() == 1) {
            return container[0] == target;
        }
        unsigned long rh = container.size() - 1;
        unsigned long rl = 0;
        while (rl < rh) {
            if (container[rl] == target || container[rh] == target) {
                return true;
            }
            rl++, rh--;
        }
        return false;
    }

public:

    void permute(const vector<int> &choices) {
        res.clear();
        vector<int> track;
        backtrack(track, choices);
    }

    void backtrack(vector<int> &track, const vector<int> &choices) {
        if (track.size() == choices.size()) {
            this->res.push_back(track);
            return;
        }
        for (int choice : choices) {
            if (contains(track, choice)) {
                // if (std::find(track.begin(), track.end(), choice) != track.end()) {
                continue;
            }
            track.push_back(choice);
            backtrack(track, choices);
            track.pop_back();
        }
    }

    void exe() override {
        vector<int> choices{};
        choices.push_back(1);
        choices.push_back(2);
        choices.push_back(3);
        permute(choices);

        for (vector<int> &r: res) {
            printf("[");
            for (int &i : r) {
                printf("%cnm, ", i);
            }
            printf("]\n");
        }
    }

};

/*int main() {
    Permute permute;
    timeMeasure->measureTime(permute);
}*/
