//
// Created by 蒋澳然 on 2021/7/10.
// 深度优先搜索框架
//

#ifndef CPPALGORITHM_DFSTEMPLATE_H
#define CPPALGORITHM_DFSTEMPLATE_H

#include "BasicSTL.h"

// DFS的结果保存
const list<vector<int>> results{};

// void DFS(vector<int> &track, const vector<int> &choices);
// 以全排列为例子
void backtrack(vector<int> &track, const vector<int> &choices) {
    // 满足条件，比如全排列这里是从choices中选择完了序列
    if (track.size() == choices.size()) {
        results.push_back(track);
        return;
    }
    // 从路径中选择
    for (const int i : choices) {
        // 剔除不符合的条件，比如全排列这里是剔除已经添加的选择
        if (std::find(track.begin(), track.end()) != track.end()) {
            continue;
        }
        // 做选择
        track.push_back(i);
        // 进入下一层选择
        backtrack(track, choices);
        // 回退选择
        track.pop_back();
    }
}

#endif //CPPALGORITHM_DFSTEMPLATE_H
