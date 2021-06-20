#include<iostream>
#include <string>
using namespace std;
/*���� �Լ�(virtual class)
* ��� ������ Ŭ������ ���� �Ҵ��� ��(���� �Ҵ�) ��ĳ������ �̿��ϰ� �Ǹ� ��� ������ ���� �� �ִ�.
* ��� Ŭ�������� �θ� Ŭ������ �Լ��� �������̵� �� ��Ȳ���� �ٿ�ĳ������ �ϰԵǸ�
* �Լ� ȣ�� �ÿ� ������ �ڽ� Ŭ������ �Լ��� ã�ƾ� �ϴµ�, virtual Ű���带 �ٿ����� ������ ���� �θ�Ŭ������ �Լ��� ȣ���ϰ� �ȴ�.
* virtual Ű���尡 ���� �Լ��� virtual �Լ��� �ǰ�, virtual �Լ��� �����ϴ� Ŭ�������� v-table�� �����ǰ� �ȴ�.
* v-table���� �ٿ�ĳ���õ� �ڽ� Ŭ������ ������ �Լ��� Ž���ϰ� �װ��� ȣ���� �� �ְ� �ȴ�.
* Ư���� '�Ҹ���'�� ������ �ٿ���� ��!
*/
class Base
{
protected:
	int n;
	string s;
public:
	Base() { n = 0; s = ""; cout << "Base �⺻ ������" << endl; }
	Base(int n,const char* s) : n(n), s(s){}
	virtual ~Base() { cout << "Base �Ҹ���"<<endl; }//�ٿ�ĳ���� �� �ڽ� Ŭ������ �Ҹ��ڸ� ������ ȣ���Ű�� ����
	string getString() { return s; }

	
};

class Derived : public Base
{
public:
	Derived() { n = 0; s = ""; cout << "Derived �⺻ ������" << endl; }
	Derived(int n, const char* s) {  }
	~Derived() { cout << "Derived �Ҹ���"<<endl; }
};
int main()
{
	Base* A = new Base(1,"1234");
	Base* B = new Derived();//�ٿ�ĳ����!

	//...DoSomething..
	cout<<A->getString()<<endl;
	//..
	//
	delete A;
	delete B;//���̽� Ŭ���� �Ҹ��ڿ� virtualŰ���尡 �����Ƿ� �ڽ�,�θ�Ŭ������ �Ҹ��ڰ� ��Ȯ�� ȣ���.
			 //virtual Ű���尡 ������ v-table�� ���� ������ �Լ�ȣ���� �̷������ �ʾ� �θ�Ŭ������ �Ҹ��ڸ� ȣ���
	return 0;
}