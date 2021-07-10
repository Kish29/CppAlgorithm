//
// Created by 蒋澳然 on 2021/7/11.
// email: 875691208@qq.com
// $desc
//

/* LeetCode 438 */
/* 滑动窗口 */
/* 给定一个字符串s和一个非空字符串p，找到s中所有是p的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串s和 p的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 * */

#include "string"
#include "vector"
#include "unordered_map"
#include "iostream"

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> findAnagrams(const string &org, const string &target) const {
        unordered_map<char, int> needs, window;
        for (const char &c : target) {
            needs[c]++;
        }
        int left = 0, right = 0;
        int satisfiedCount = 0;

        vector<int> indexes;
        indexes.reserve(org.size() / 2);

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
                        indexes.push_back(left);
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
        return indexes;
    }
};