//
// Created by 蒋澳然 on 2021/7/5.
//

#include <memory>

#include "TimeMeasure.h"

void SharedPointer();

void SharedPointer2();

void UniquePointer();

void WeakPointer();

class SmartPointer : public TimeMeasureExe {

public:
    void exe() override {
        SharedPointer();
        UniquePointer();
        WeakPointer();
    }

};

class ZeroException : public std::exception {
public:
    const char *what() const noexcept override {
        return "progress divide 0!\n";
    }
};

//int main() {
//    SmartPointer smartPointer;
//    timeMeasure->measureTime(smartPointer);
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

void UniquePointer() {

}

void WeakPointer() {

}

void SharedPointer2() {
    shared_ptr<int> pNum(new int[10], [](const int *nums) -> void {
        delete[] nums;
    });
    shared_ptr<int> pNum1(new int[10]);
    unique_ptr<int> pNum0_5(new int[10]);
    shared_ptr<int> pNum2(new int[10], std::default_delete<int[]>());
}
