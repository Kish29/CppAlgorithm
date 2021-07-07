//
// Created by 蒋澳然 on 2021/7/5.
//

#include "TimeMeasure.h"

void SharedPointer();

void SharedPointer2();

void UniquePointer();

void WeakPointer();

class SmartPointer : public TimeMeasureExe {

public:
    void exe() override {
//        SharedPointer();
        UniquePointer();
//        WeakPointer();
    }

};

class ZeroException : public std::exception {
public:
    const char *what() const noexcept override {
        return "progress divide 0!\n";
    }
};

class TestStreamOutTimeCost : public TimeMeasureExe {
public:
    void exe() override {
        const int time = 1000000;
        for (int i = 0; i < time; ++i) {
            cout << i << "\t";
        }
        cout << endl;
    }
};

class TestBufferOutTimeCost : public TimeMeasureExe {
public:
    void exe() override {
        const int time = 1000000;
        for (int i = 0; i < time; ++i) {
            printf("%cnm\t", i);
        }
        printf("\n");
    }
};

//int main() {
//    SmartPointer smartPointer;
//    timeMeasure->measureTime(smartPointer);
//    TestStreamOutTimeCost timeCost1;
//    TestBufferOutTimeCost timeCost2;
//    auto time1 = timeMeasure->measureTime(timeCost1);
//    auto time2 = timeMeasure->measureTime(timeCost2);
//    Println("IO - Steam use time " + to_string(time1));
//    Println("IO - Steam use time " + to_string(time2));
//}

void SharedPointer() {
    /*shared_ptr<string> *pNico = new shared_ptr<string>(new string("nico"), [](string *str) -> void {
        cout << "delete " << *str << endl;
        delete str;
    });*/

    /*shared_ptr<string> pNico(new string("nico"), [](string *str) -> void {
        cout << "delete " << *str << endl;
        delete str;
    });*/
    shared_ptr<string> pNico(new string("nico"), std::default_delete<string>());
    shared_ptr<string> pJutta(new string("jutta"), [](string *str) -> void {
        cout << "delete " << *str << endl;
        delete str;
    });

    /*shared_ptr<string> *pJutta = new shared_ptr<string>(new string("jutta"), [](string *str) -> void {
        cout << "delete " << *str << endl;
        delete str;
    });*/
//    shared_ptr<string> pNico = std::make_shared<string>("nico");
//    shared_ptr<string> pJar;
//    pJar = std::make_shared<string>("jar");
//    shared_ptr<string> pJutta = std::make_shared<string>("jutta");

    // 首字母大写
//    (*(*pNico))[0] = 'N';
//    (*pJutta)->replace(0, 1, "J");

    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");
    // 放进容器中
    vector<shared_ptr<string>> whoMadeCoffee;
    // push_back会调用复制构造函数
//    whoMadeCoffee.push_back(*pJutta);
//    whoMadeCoffee.push_back(*pJutta);
//    whoMadeCoffee.push_back(*pNico);
//    whoMadeCoffee.push_back(*pJutta);
//    whoMadeCoffee.push_back(*pNico);

    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    for (const shared_ptr<string> &name: whoMadeCoffee) {
        cout << *name << "\t";
    }
    printf("\n");

    *pNico = "Nicolai";
    for (const shared_ptr<string> &name: whoMadeCoffee) {
        cout << *name << "\t";
    }
    printf("\n");

    cout << "use_count:\t" << whoMadeCoffee.at(0).use_count() << endl;

    // new分配必须释放
//    delete pNico;
//    delete pJutta;

}

class Person {
public:
    string name{};

    explicit Person(string n) : name(move(n)) {}

    ~Person() {
        Println("delete " + name + " in destructor");
    }
};

//Person ppp("Nico");

void UniquePointer() {
    // unique_ptr必须显示指出lambda
    unique_ptr<Person, void (*)(Person *)> upP(new Person("jiang ao ran"), [](Person *p) -> void {
        if (p != nullptr) {
            Println("delete " + p->name);
            delete p;
        }
    });
    // 或者这样
    int a = 100;
    unique_ptr<Person, function<void(Person *)>> upP1(new Person("jiang ao ran"), [&a](Person *p) -> void {
        Println("a is " + to_string(a));
        if (p != nullptr) {
            Println("delete " + p->name);
            delete p;
        }
    });
    // 或者这样
    auto dp = [&a](Person *p) -> void {
        Println("a is " + to_string(a));
//        Println("ppp's name is " + ppp.name);
        if (p != nullptr) {
            Println("delete " + p->name);
            delete p;
        }
    };
    unique_ptr<Person, decltype(dp)> upP2(new Person("jiang ao ran"), dp);
}

void WeakPointer() {
    shared_ptr<string> pJar(new string("jiang ao ran"), [](string *str) -> void {
        printf("delete %s\n", str->c_str());
        delete str;
    });
    weak_ptr<string> pwJar(pJar);
    Println(*pJar);
    pwJar.lock()->replace(0, 1, "l");
    // only pJar has this pointer
    Println(pJar.use_count());
    Println(*pJar);
}

void SharedPointer2() {
    shared_ptr<int> pNum(new int[10], [](const int *nums) -> void {
        delete[] nums;
    });
    shared_ptr<int> pNum1(new int[10]);
    unique_ptr<int> pNum0_5(new int[10]);
    shared_ptr<int> pNum2(new int[10], std::default_delete<int[]>());
}
