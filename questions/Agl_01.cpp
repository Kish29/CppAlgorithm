//
// Created by 蒋澳然 on 2021/7/4.
//

#include <DataStructure.h>
#include "TimeMeasure.h"

class Agl_01 : public TimeMeasureExe {

public:

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
