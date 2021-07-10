//
// Created by 蒋澳然 on 2021/7/6.
//

#include "unordered_set"
#include "string"
#include "queue"
#include "set"
#include "vector"
#include "utility"
#include "algorithm"

using std::string;
using std::queue;
using std::vector;
using std::set;
using std::unordered_set;
using std::find;
using std::move;

/* LeetCode 752 */

/* BFS搜索 */
/* 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。



示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 * */

class Solution {
public:

    string &plusOne(string &str, int pos) {
        string *newStr = new string(str);
        if (newStr->at(pos) == '9') {
            newStr->at(pos) = '0';
        } else {
            newStr->at(pos)++;
        }
        return *newStr;
    }

    string &minusOne(string &str, int pos) {
        string *newStr = new string(str);
        if (newStr->at(pos) == '0') {
            newStr->at(pos) = '9';
        } else {
            newStr->at(pos)--;
        }
        return *newStr;
    }

    int openLock(vector<string> &deadends, string &target) {
        return BFS(deadends, target);
    }

    int BFS(vector<string> &deadends, string &target) {
        queue<string> store;
        unordered_set<string> visited;
        string start = "0000";

        store.push(start);
        visited.emplace(start);

        int step = 0;

        while (!store.empty()) {
            int sz = store.size();
            for (int i = 0; i < sz; i++) {
                string cur = store.front();
                store.pop();

                if (find(deadends.begin(), deadends.end(), cur) != deadends.end()) {
                    continue;
                }

                if (cur == target) {
                    return step;
                }

                // 构造8种密码的情况
                for (int j = 0; j < 4; j++) {
                    string newStr1 = plusOne(cur, j);
                    if (visited.find(newStr1) == visited.end()) {
                        store.push(newStr1);
                        visited.insert(newStr1);
                    }
                    string newStr2 = minusOne(cur, j);
                    if (visited.find(newStr2) == visited.end()) {
                        store.push(newStr2);
                        visited.insert(newStr2);
                    }
                }

            }
            step++;
        }
        return -1;
    }
};