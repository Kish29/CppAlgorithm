//
// Created by 蒋澳然 on 2021/7/4.
//

#ifndef CPPALGORITHM_BASICSTL_H
#define CPPALGORITHM_BASICSTL_H

#include "cstdlib"
#include "cstdio"
#include "ctime"
#include "utility"
#include "unistd.h"
#include "vector"
#include "string"
#include "cstring"
#include "unordered_map"
#include "list"
#include "array"
#include "map"
#include "iostream"
#include "stack"
#include "queue"
#include "set"
#include "unordered_set"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;
// map的底层实现是红黑树，不是hash，搜索的时间复杂度是O(log(N))
// map默认递增排序(中序遍历)
using std::map;
using std::array;
using std::min;
using std::max;
// unordered_map的底层实现是hash，搜索的时间复杂度是O(1)
using std::unordered_map;
using std::iterator;
using std::make_pair;
using std::stack;
using std::queue;
// set的底层实现是红黑树
using std::set;
// unordered_set底层实现是hash
using std::unordered_set;

typedef unsigned long ul;

#endif //CPPALGORITHM_BASICSTL_H
