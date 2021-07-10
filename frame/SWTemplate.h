//
// Created by 蒋澳然 on 2021/7/10.
// Sliding Window 滑动窗口搜索框架
//

#ifndef CPPALGORITHM_SWTEMPLATE_H
#define CPPALGORITHM_SWTEMPLATE_H

#include "BasicSTL.h"

// 以LeetCode上76题为例子
/*
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"

 **/

string slidingWindow(const string &org, const string &target) {
    // 分别保存需要查找的目标和滑动窗口
    unordered_map<char, int> needs, window;
    // 初始化needs
    for (const char &c : target) {
        needs[c]++;
    }
    // 滑动窗口的左右双指针
    int left = 0, right = 0;
    // 保存window中满足target字符的个数，满足了，说明窗口需要缩小
    int satisfiedCount = 0;

    // 额外代码
    // start和len是为了后续返回截取字符串
    int start = 0, sublen = INT32_MAX;
    try {
        while (right < org.size()) {
            // 这里扩大滑动窗口
            // 代码写这儿
            // 待添加字符
            char add = org.at(right);
            right++;
            // 如果待添加存在于needs中，我们把它加入滑动窗口，并判断此时滑动窗口中该字符
            // 的数量是否恰好等于needs中该字符的数量，因为needs中的字符可能有重复
            if (needs.count(add)) {
                window[add]++;
                if (window[add] == needs[add]) {
                    satisfiedCount++;
                }
            }

            // while (window needs shrink)
            // 这里是满足的字符数量
            while (satisfiedCount == needs.size()) {
                // 缩小窗口
                // 代码写这儿
                // 更新len
                if (right - left < sublen) {
                    start = left;
                    sublen = right - left;
                }
                // 待移除字符
                char remove = org.at(left);
                left++;
                if (needs.count(remove)) {
                    if (window[remove] == needs[remove]) {
                        satisfiedCount--;
                    }
                    window[remove]--;
                }
            }
        }
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
    return sublen == INT32_MAX ? "" : org.substr(start, sublen);
}


#endif //CPPALGORITHM_SWTEMPLATE_H