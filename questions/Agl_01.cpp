//
// Created by 蒋澳然 on 2021/7/4.
//

#include <DataStructure.h>
#include "TimeMeasure.h"


/* LeetCode 111 */
/* BFS搜索 */
/* 给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5

 * */

class Agl_01 : public TimeMeasureExe {

public:

    //
    int minDepth(TreeNode *root) const {
        using std::queue;
        if (root == nullptr) return 0;
        queue<TreeNode> visit;

        visit.push(*root);

        int depth = 1;

        while (!visit.empty()) {
            ul sz = visit.size();
            // 不要把判断条件写在for循环中，在循环体内，visit的大小动态的改变了
            // for (int i = 0; i < visit.size(); ++i) {
            for (int i = 0; i < sz; i++) {
                TreeNode cur = visit.front();
                visit.pop();

                if (cur.left == nullptr && cur.right == nullptr) {
                    return depth;
                }

                if (cur.left != nullptr) {
                    visit.push(*cur.left);
                }

                if (cur.right != nullptr) {
                    visit.push(*cur.right);
                }

            }
            depth++;
        }
        return depth;
    }

    void exe() override {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        auto depth = minDepth(root);
        cout << depth << endl;
    }

    ~Agl_01() override = default;

};

static string &plusOne(string &str, int pos) {
    auto *newStr = new string(str);
    if (newStr->at(pos) == '9') {
        newStr->at(pos) = '0';
    } else {
        newStr->at(pos)++;
    }
    return *newStr;
}

/*
int main() {
    Agl_01 agl01;
    timeMeasure->measureTime(agl01);
    string start = "0000";
    string plus = plusOne(start, 3);
    cout << plus << endl;
}*/
