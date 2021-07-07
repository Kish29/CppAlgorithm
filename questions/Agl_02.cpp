//
// Created by 蒋澳然 on 2021/7/6.
//

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
using std::find;
using std::move;

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
        set<string> visited;
        string start = "0000";

        store.push(start);
        visited.insert(start);

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