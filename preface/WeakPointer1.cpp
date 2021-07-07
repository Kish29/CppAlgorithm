//
// Created by 蒋澳然 on 2021/7/6.
//

/* 本列子中，Peter持有了父母的ptr，而父母有持有了Peter的ptr，造成循环引用，对象泄漏 */
#include "TimeMeasure.h"

class Person : public std::enable_shared_from_this<Person> {

public:
    string name{};
    shared_ptr<Person> mother{};
    shared_ptr<Person> father{};
//    vector<shared_ptr<Person>> kids{};
    // 或者使用weak_ptr，不直接持有 kids 的ptr
    vector<weak_ptr<Person>> kids{};
    // parents弱引用将造成initFamily函数中parents的生命周期和函数一样
//    weak_ptr<Person> mother{};
//    weak_ptr<Person> father{};

    explicit Person(
            string n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr
    ) : name(move(n)),
        mother(move(m)),
        father(move(f)) {}

    ~Person() {
        Println("delete " + this->name);
    }

    void set() {
        shared_from_this();
    }
    static shared_ptr<Person> initFamily(const string &name) {
        shared_ptr<Person> mom(new Person(name + "'s mom"), getPersonDeleter());
        shared_ptr<Person> father(new Person(name + "'s dad"), getPersonDeleter());
        // 这行代码，循环引用，造成对象泄漏
        shared_ptr<Person> kid(new Person(name, mom, father), getPersonDeleter());
        // 这行代码，可以让ptr的生命周期同 initFamily 函数一样
//        shared_ptr<Person> kid(new Person(name), getPersonDeleter());
        mom->kids.push_back(kid);
        father->kids.push_back(kid);
        return kid;
    }

private:
    static std::function<void(Person *)> getPersonDeleter() {
        return [](Person *p) -> void {
            if (p != nullptr) {
                Println("delete " + p->name + " in deleter");
                delete p;
            }
        };
    }
};

class WeakPtr1 : public TimeMeasureExe {

public:

    void exe() override {
        shared_ptr<Person> p = Person::initFamily("Peter");
        if (p != nullptr) {
            Println(p->name + "'s family exits");
            Println(p->name + " is shared " + std::to_string(p.use_count()) + " times");
            // 注意每个指针的有效性！这是代码健壮性的保证
            if (p->mother != nullptr && p->mother->kids[0].lock() != nullptr) {
                // lock保证在读写的时候，其内部的share_ptr没有在进行对象操作
                Println(p->name + "'s mom's first kid's name is " + p->mother->kids[0].lock()->name);
            }
        }
        p = Person::initFamily("Jim");
        if (p != nullptr) {
            Println(p->name + "'s family exits");
        }
    }
};

//int main() {
//    WeakPtr1 weakPtr1;
//    timeMeasure->measureTime(weakPtr1);
//}