//
// Created by 蒋澳然 on 2021/7/11.
// email: 875691208@qq.com
// monotonic_queue 单调队列
//

#ifndef CPPALGORITHM_MQTEMPLATE_H
#define CPPALGORITHM_MQTEMPLATE_H

#include "BasicSTL.h"

template<class T>
class monotonic_queue {
private:
    // 核心：双链表，支持头部和尾部添加以及删除元素
    deque<T> data{};

public:
    // 核心思想：在push的时候，在队列末尾添加元素，需要把前面比自己小的元素都从尾部删掉
    void push(const T &value) {
        while (!data.empty() && data.back() < value) {
            data.pop_back();
        }
        data.push_back(value);
    }

    T max() const {
        // 注意，data按照逻辑是不可能为空，但仍然最好判断一下
//        if (data.empty()) return T();
        return data.front();
    }

    // 在队头移除值为value的元素
    void pop(const T &value) {
        if (value == data.front()) {
            data.pop_front();
        }
    }
};

/* LeetCode 239 */
/* 窗口在滑动的过程中，窗口里的元素用单调队列保存，可以在O(1)的时间复杂度内找到最大值 */
/* 给你一个整数数组 nums，有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
 * */

vector<int> monotonicQueue(const vector<int> &nums, int k) {
    monotonic_queue<int> window{};
    vector<int> res{};
    res.reserve(nums.size() - k + 1);
    try {
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                // 先把窗口填满 (k - 1) 个元素
                // 注意，是 k - 1 个元素
                // 因为后面窗口移动的时候，会动态添加元素，在那里更新最大值
                window.push(nums.at(i));
            } else {    // 窗口向前移动
                // 加入新的元素
                window.push(nums.at(i));
                res.push_back(window.max());
                // 移除最左侧的元素
                window.pop(nums.at(i - k + 1));
            }
        }
    } catch (std::out_of_range &e) {
        cout << e.what() << endl;
    }
    return res;
}

#endif //CPPALGORITHM_MQTEMPLATE_H
