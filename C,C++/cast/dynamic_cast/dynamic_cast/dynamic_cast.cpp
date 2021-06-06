#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Animal {
public:
    virtual void sound() = 0; // 가상함수
};

class Dog : public Animal {
private:
    string name;
public:
    Dog(string s) : name(s) {};
    void sound() { cout << "아우우우(동생 아님ㅋ)"<<endl; }
    void name_print() { cout << name << endl; }
    void only_dog() { cout << "강아지"<<endl; }
};

class Cat : public Animal {
private:
    string name;
public:
    Cat(string s) : name(s) {};
    void sound() { cout << "냥 냥냥냥냐"<<endl; }
    void name_print() { cout << name << endl; }
    void data() { cout << this << endl; }
    void only_cat() { cout << "고양이"<<endl; }
};

int main() {

    vector<Animal*> v; // 동적 생성한 동물 친구들
    v.emplace_back(new Cat("유미"));// 업캐스팅
    v.emplace_back(new Dog("워윅"));// 업캐스팅

    Cat* cat =NULL;//dummy
    Dog* dog =NULL;//dummy

    /*
    cat = (Cat*)v[1]; // 원래 v[1]은 개 클래스이나 실수로 고양이 클래스로 다운캐스팅한 사례
    dog = (Dog*)v[0]; // 원래 v[0]은 고양이 클래스이나 실수로 개 클래스로 다운캐스팅한 사례
    
    cat->name_print();// 워윅
    cat->sound();//아우우우(동생 아님ㅋ)
    cat->only_cat();// 고양이

    dog->name_print();//       유미
    dog->sound();//     냥 냥냥냥냐
    dog->only_dog();//       강아지

    위와같은 다운캐스팅 과정에서 개발자의 실수를 방지하기 위해 dynamic_cast를 사용한다.
    */

    for (size_t idx = 0; idx < v.size(); idx++) {
        if (cat = dynamic_cast<Cat*>(v[idx])) {//Cat* 으로 다운캐스팅에 성공했다면 
            cat->name_print();
            cat->sound();
            cat->only_cat();
        }
        else {
            dog = dynamic_cast<Dog*>(v[idx]);//실패했다면 -> Cat*이 아니겠지요
            dog->name_print();
            dog->sound();
            dog->only_dog();
        }
    }
    delete cat;
    delete dog;
    return 0;
}