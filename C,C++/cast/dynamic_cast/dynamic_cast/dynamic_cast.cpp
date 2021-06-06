#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Animal {
public:
    virtual void sound() = 0; // �����Լ�
};

class Dog : public Animal {
private:
    string name;
public:
    Dog(string s) : name(s) {};
    void sound() { cout << "�ƿ���(���� �ƴԤ�)"<<endl; }
    void name_print() { cout << name << endl; }
    void only_dog() { cout << "������"<<endl; }
};

class Cat : public Animal {
private:
    string name;
public:
    Cat(string s) : name(s) {};
    void sound() { cout << "�� �ɳɳɳ�"<<endl; }
    void name_print() { cout << name << endl; }
    void data() { cout << this << endl; }
    void only_cat() { cout << "�����"<<endl; }
};

int main() {

    vector<Animal*> v; // ���� ������ ���� ģ����
    v.emplace_back(new Cat("����"));// ��ĳ����
    v.emplace_back(new Dog("����"));// ��ĳ����

    Cat* cat =NULL;//dummy
    Dog* dog =NULL;//dummy

    /*
    cat = (Cat*)v[1]; // ���� v[1]�� �� Ŭ�����̳� �Ǽ��� ����� Ŭ������ �ٿ�ĳ������ ���
    dog = (Dog*)v[0]; // ���� v[0]�� ����� Ŭ�����̳� �Ǽ��� �� Ŭ������ �ٿ�ĳ������ ���
    
    cat->name_print();// ����
    cat->sound();//�ƿ���(���� �ƴԤ�)
    cat->only_cat();// �����

    dog->name_print();//       ����
    dog->sound();//     �� �ɳɳɳ�
    dog->only_dog();//       ������

    ���Ͱ��� �ٿ�ĳ���� �������� �������� �Ǽ��� �����ϱ� ���� dynamic_cast�� ����Ѵ�.
    */

    for (size_t idx = 0; idx < v.size(); idx++) {
        if (cat = dynamic_cast<Cat*>(v[idx])) {//Cat* ���� �ٿ�ĳ���ÿ� �����ߴٸ� 
            cat->name_print();
            cat->sound();
            cat->only_cat();
        }
        else {
            dog = dynamic_cast<Dog*>(v[idx]);//�����ߴٸ� -> Cat*�� �ƴϰ�����
            dog->name_print();
            dog->sound();
            dog->only_dog();
        }
    }
    delete cat;
    delete dog;
    return 0;
}