//
// Created by 蒋澳然 on 2021/7/10.
// email: 875691208@qq.com
// Monotonic Stack 单调栈
//

#ifndef CPPALGORITHM_MSTEMPLATE_H
#define CPPALGORITHM_MSTEMPLATE_H

#include "BasicSTL.h"

// 以LeetCode496题为例，求一个数组nums中，每一个元素后面第一个比他大的元素
vector<int> ms(const vector<int> &nums) {
    vector<int> res(nums.size());
    // 单调栈，保存元素，元素是一个单调递增的或者单调递减的
    stack<int> msStack;
    try {
        for (unsigned long i = nums.size() - 1; i >= 0; i--) {
            // 将单调栈中所有比当前元素小的元素弹出
            while (!msStack.empty() && msStack.top() <= nums.at(i)) {
                msStack.pop();
            }
            // 如果栈为空，则未找到 -1
            res.at(i) = msStack.empty() ? -1 : msStack.top();
            msStack.push(nums.at(i));
        }
    } catch (std::out_of_range &e) {
        // do something
    }
    return res;
}

#endif //CPPALGORITHM_MSTEMPLATE_H
