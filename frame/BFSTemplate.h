//
// Created by 蒋澳然 on 2021/7/10.
// BFS广度优先搜索框架
//

#ifndef CPPALGORITHM_BFSTEMPLATE_H
#define CPPALGORITHM_BFSTEMPLATE_H

#include "BasicSTL.h"
#include "data/DataStructure.h"

int BFS(const Node<int> &start, const Node<int> &target) {
    // 记录需要访问的节点
    queue<Node<int>> traverse;
    set<Node<int>> visited;

    traverse.push(start);
    visited.emplace(start);

    // 可以在这里定义需要求解的问题
    int diffusion = 0;

    while (!traverse.empty()) {
        // 将当前待访问的所有节点出列
        // 注意，只能使用for-index循环，不然里面的操作会实时改变queue的大小
        unsigned long sz = traverse.size();
        for (int i = 0; i < sz; ++i) {
            // 拿到第一个节点
            auto cur = traverse.front();
            traverse.pop();
            for (auto &node : cur.adj) {
                // 如果没有访问过，加入到待访问队列中
                if (visited.find(node) != visited.end()) {
                    traverse.push(node);
                    visited.emplace(node);
                }
            }
        }
        // 扩散了一圈
        diffusion++;
    }
    return diffusion;
}

#endif //CPPALGORITHM_BFSTEMPLATE_H
