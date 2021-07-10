//
// Created by 蒋澳然 on 2021/7/11.
// email: 875691208@qq.com
// $desc
//

#include "BasicSTL.h"

/* LeetCode 567 */
/* 滑动窗口，不过注意，这里滑动窗口的大小限制死了，也就是说一旦滑动窗口的大小达到规模，就需要立即判断是否符合要求并缩减规模 */
/* 给定两个字符串s1和s2，写一个函数来判断 s2 是否包含 s1的排列。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

示例 1：

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
示例 2：

输入: s1= "ab" s2 = "eidboaoo"
输出: False

 * */

class Solution {
public:
    bool checkInclusion(const string &target, const string &org) const {
        unordered_map<char, int> needs, window;
        for (const char &c : target) {
            needs[c]++;
        }
        int left = 0, right = 0;
        int satisfiedCount = 0;
        try {
            while (right < org.size()) {
                char add = org.at(right);
                right++;
                if (needs.count(add)) {
                    window[add]++;
                    if (window[add] == needs[add]) {
                        satisfiedCount++;
                    }
                }

                while (right - left >= target.size()) {
                    if (satisfiedCount == needs.size()) {
                        return true;
                    }
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
            cout << e.what() << endl;
        }
        return false;
    }
};