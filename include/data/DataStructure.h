//
// Created by 蒋澳然 on 2021/7/3.
//

#ifndef CPPALGORITHM_DATASTRUCTURE_H
#define CPPALGORITHM_DATASTRUCTURE_H

#include "vector"
#include "memory"

using std::unique_ptr;

using std::vector;

template<class T>
struct ListNode {
    T val{};

    struct ListNode<T> *next{};

    bool operator==(const ListNode<T> &rh) {
        return this->val == rh.val;
    }

    ListNode() = default;

    explicit ListNode(T t) : val(t), next(nullptr) {}

    ListNode(const ListNode<T> &rh) {
        this->val = rh.val;
        auto ph = rh.next;
        auto pt = next;
        while (ph) {
            pt = new ListNode<T>;
            pt->val = ph->val;
            pt = pt->next;
            ph = ph->next;
        }
    }

    ListNode &operator=(const ListNode<T> &rh) {
        this->val = rh.val;
        auto ph = rh.next;
        auto pt = next;
        while (ph) {
            pt = new ListNode<T>;
            pt->val = ph->val;
            pt = pt->next;
            ph = ph->next;
        }
        return *this;
    }

};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<class T>
struct Node {

    T val{};

    vector<struct Node<T>> adj{};

    bool operator==(const Node<T> &rh) {
        return this->val == rh.val;
    }

    Node(const Node<T> &rh) {

    }

};

template<class T>
struct NodeHash {

    size_t operator()(const Node<T> &rh) const {
        return std::hash<T>(*this);
    }
};


#endif //CPPALGORITHM_DATASTRUCTURE_H
