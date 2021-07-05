//
// Created by 蒋澳然 on 2021/7/5.
//

#include "TimeMeasure.h"

void SequenceContainer();

void AssociatedContainer();

void UnorderedContainer();

void SpecialContainer();

int main() {
//    SequenceContainer();
//    AssociatedContainer();
    UnorderedContainer();
}

void SequenceContainer() {
    // vector
    Println("vector:");
    vector<int> vc;
    // 末尾推入/入驻 push_back==emplace_back
    vc.push_back(1);
    vc.emplace_back(1);

    // 某处插入/入驻 insert==emplace
    vc.insert(vc.begin(), 1);
    vc.emplace(vc.begin(), 1);
    VectorPrint(vc);

    // 弹出某个元素
    vc.pop_back();
    VectorPrint(vc);

    // 访问/赋值
    vc[0] = 1;
    vc.at(0) = 1;
    vc.back() = 1;
    vc.front() = 1;
    Println(vc[0]);
    Println(vc.at(0));
    Println(vc.front());
    Println(vc.back());

    VectorPrint(vc);

    // dequeue
    Println("\ndequeue:");
    deque<int> dq;
    // 末尾插入
    dq.push_back(1);
    dq.emplace_back(1);
    // 头部插入
    dq.push_front(1);
    dq.emplace_front(1);

    // 某处插入/入驻
    dq.insert(dq.begin(), 1);
    dq.emplace(dq.begin(), 1);
    DequeuePrint(dq);

    // 弹出末尾元素
    dq.pop_back();
    // 弹出头部元素
    dq.pop_front();
    DequeuePrint(dq);

    // 赋值/访问
    dq[0] = 1;
    dq.at(0) = 1;
    dq.back() = 1;
    dq.front() = 1;
    Println(dq[0]);
    Println(dq.at(0));
    Println(dq.back());
    Println(dq.front());
    DequeuePrint(dq);

    // array
    Println("\narray:");
    array<int, 4> a{};
    a.fill(2);
    ArrayPrint(a);
    // 赋值/访问
    a[0] = 1;
    a.at(0) = 1;
    a.back() = 1;
    a.front() = 1;
    Println(a[0]);
    Println(a.at(0));
    Println(a.back());
    Println(a.front());
    ArrayPrint(a);

    // list
    Println("list:");
    list<int> l;
    // 末尾插入
    l.push_back(1);
    l.emplace_back(1);
    // 头部插入
    l.push_front(1);
    l.emplace_front(1);

    // 某处插入
    l.insert(l.begin(), 1);
    l.emplace(l.begin(), 1);
    ListPrint(l);

    // 弹出末尾
    l.pop_back();
    // 弹出头部
    l.pop_front();
    ListPrint(l);

    // 赋值/访问，无法随机访问
    l.back() = 1;
    l.front() = 1;
    Println(l.back());
    Println(l.front());
    ListPrint(l);

    // forward_list
    Println("forward_list:");
    // 单向链表
    forward_list<int> fl;
    // 插入
    fl.push_front(1);
    fl.emplace_front(1);

    // 某处插入
    fl.insert_after(fl.begin(), 2);
    fl.emplace_after(fl.begin(), 2);

}

// 大多是红黑树实现
void AssociatedContainer() {
    Println("关联容器是红黑树实现");
    // set
    Println("set:");
    set<string> s;
    // 插入
    s.emplace("banana");
    s.insert("apple");
    s.insert("apple");
    s.insert("apple");
    s.insert("apple");
    SetPrint(s);

    // 删除
    s.erase("apple");
    SetPrint(s);

    Println("\nmultiset:");
    multiset<string> ms;

    ms.insert("banana");
    ms.emplace("apple");
    ms.emplace("apple");
    ms.emplace("apple");
    ms.emplace("apple");
    MultisetPrint(ms);

    ms.erase("apple");
    MultisetPrint(ms);

    Println("\nmap:");
    // Java使用Integer封装基本类型来使用hashCode
    // C++使用pair来封装key-value来使用hashCode
    map<string, int> m;
    m.emplace(make_pair("banana", 2));
    m.insert(make_pair("apple", 1));
    m.insert(make_pair("apple", 1));
    m.insert(make_pair("apple", 1));
    m.insert(make_pair("apple", 1));
    MapPrint(m);
    m.erase("apple");
    MapPrint(m);

    Println("\nmultimap:");
    multimap<string, int> mm;
    mm.emplace(make_pair("banana", 2));
    mm.insert(make_pair("apple", 1));
    mm.insert(make_pair("apple", 1));
    mm.insert(make_pair("apple", 1));
    mm.insert(make_pair("apple", 1));
    MultimapPrint(mm);
    mm.erase("apple");
    MultimapPrint(mm);
}

void UnorderedContainer() {
    Println("无序容器是HashTable实现，一般采用链表解冲突");
    Println("unordered_set:");
    Println("\nunordered_multiset:");
    Println("\nunordered_map:");
    Println("\nunordered_multimap:");
}

void SpecialContainer() {
    // queue
    Println("特殊容器");
    queue<int> q;
    // 末尾添加 push==emplace
    q.push(0);
    q.emplace(0);
    // 访问最前面元素
    q.front();
    // 访问末尾元素
    q.back();
    // 弹出
    q.pop();
    for (int i = 0; i < 6; ++i) {
        q.push(i);
        q.emplace(i);
    }
    QueuePrint(q);

    // stack
    stack<int> s;
    // 末尾添加
    s.push(0);
    s.emplace(0);
}
