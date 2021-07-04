//
// Created by 蒋澳然 on 2021/7/4.
//

#include "DataStructure.h"
#include "TimeMeasure.h"

class BFSTemplate : public TimeMeasureExe {

public:
    void exe() override {
//        BFS()
    }

    int BFS(const Node<int> &start, const Node<int> &target) const {
        queue<Node<int>> queue{};
        // unordered_set会根据Node<int>计算hash，所以需要一个hash计算的函数
        unordered_set<Node<int>, NodeHash<int>> visited;

        queue.push(start);
        visited.insert(start);

        int step = 0;

        while (!queue.empty()) {
            for (int i = 0; i < queue.size(); ++i) {
                auto cur = queue.front();
                queue.pop();
                for (Node<int> &n: cur.adj) {
                    if (visited.find(n) != visited.end()) {
                        queue.push(n);
                        visited.insert(n);
                    }
                }
            }
            step++;
        }
        return step;
    }

};