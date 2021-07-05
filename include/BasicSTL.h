//
// Created by 蒋澳然 on 2021/7/4.
//

#ifndef CPPALGORITHM_BASICSTL_H
#define CPPALGORITHM_BASICSTL_H

/* Basic Lib */
#include "iostream"
#include "cstdlib"
#include "ctime"
#include "utility"
#include "unistd.h"
#include "string"
#include "cstring"

/* STL Container */
/* Sequence Container */
#include "array"
#include "vector"
#include "deque"
#include "list"

/* Associated Container */
#include "set"
#include "map"

/* Unordered Container */
#include "unordered_set"
#include "unordered_map"

/* Special Container */
#include "stack"
#include "queue"


using std::cout;
using std::endl;
using std::string;

using std::iterator;
// 序列容器的底层实现是：数组+扩容复制 / 链表
using std::array;
using std::vector;
using std::deque;
using std::list;

using std::make_pair;
// 关联容器的底层实现是：红黑树
using std::set;
using std::multiset;
using std::map;
using std::multimap;
using std::min;
using std::max;

// 无序容器的底层实现是：Hash Table + 链表解冲突
using std::unordered_set;
using std::unordered_multiset;
using std::unordered_map;
using std::unordered_multimap;

// 特殊容器
using std::stack;
using std::queue;
using std::pair;

typedef unsigned long ul;

template<class T>
static void Println(const T &t) {
    cout << t << endl;
}

template<class T>
static void Print(const T &t) {
    cout << t;
}

template<class T>
static void VectorPrint(const vector<T> &v) {
    auto iter = v.begin();
    printf("Size<%lu> [", v.size());
    while (iter < v.end()) {
        if (iter + 1 < v.end()) {
            cout << *iter << ", ";
        } else {
            cout << *iter;
        }
        iter++;
    }
    printf("]\n");
}

template<class T>
static void QueuePrint(queue<T> q) {
    printf("Size<%lu> [", q.size());
    while (!q.empty()) {
        if (q.size() == 1) {
            cout << q.front();
        } else {
            cout << q.front() << ", ";
        }
        q.pop();
    }
    printf("]\n");
}

template<class T>
static void DequeuePrint(deque<T> dq) {
    printf("Size<%lu> [", dq.size());
    while (!dq.empty()) {
        if (dq.size() == 1) {
            cout << dq.front();
        } else {
            cout << dq.front() << ", ";
        }
        dq.pop_front();
    }
    printf("]\n");
}

template<class T, size_t sz>
static void ArrayPrint(const array<T, sz> &a) {
    auto iter = a.begin();
    printf("Size<%lu> [", a.size());
    while (iter < a.end()) {
        if (iter + 1 < a.end()) {
            cout << *iter << ", ";
        } else {
            cout << *iter;
        }
        iter++;
    }
    printf("]\n");
}

template<class T>
static void ListPrint(list<T> l) {
    printf("Size<%lu> [", l.size());
    while (!l.empty()) {
        if (l.size() == 1) {
            cout << l.front();
        } else {
            cout << l.front() << ", ";
        }
        l.pop_front();
    }
    printf("]\n");
}

template<class T>
static void SetPrint(const set<T> &s) {
    printf("Size<%lu> [", s.size());
    for (const T &t: s) {
        cout << t << ", ";
    }
    printf("]\n");
}

template<class T>
static void MultisetPrint(const multiset<T> &ms) {
    printf("Size<%lu> [", ms.size());
    for (const T &t: ms) {
        cout << t << ", ";
    }
    printf("]\n");
}

template<class K, class V>
static void MapPrint(const map<K, V> &m) {
    printf("Size<%lu> [", m.size());
    for (const pair<K, V> &kv: m) {
        cout << "{" << kv.first << "," << kv.second << "}" << ", ";
    }
    printf("]\n");
}

template<class K, class V>
static void MultimapPrint(const multimap<K, V> &mm) {
    printf("Size<%lu> [", mm.size());
    for (const pair<K, V> &kv: mm) {
        cout << "{" << kv.first << "," << kv.second << "}" << ", ";
    }
    printf("]\n");
}

template<class T>
static void StackPrint(stack<T> s) {
    printf("Size<%lu> [", s.size());
    while (!s.empty()) {
        if (s.size() == 1) {
            cout << s.top();
        } else {
            cout << s.top() << ", ";
        }
        s.pop();
    }
    printf("]\n");
}

#endif //CPPALGORITHM_BASICSTL_H
