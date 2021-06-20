#include<iostream>
#include <string>
using namespace std;
/*가상 함수(virtual class)
* 상속 관계의 클래스를 힙에 할당할 때(동적 할당) 업캐스팅을 이용하게 되면 몇가지 문제가 생길 수 있다.
* 상속 클래스에서 부모 클래스의 함수를 오버라이딩 한 상황에서 다운캐스팅을 하게되면
* 함수 호출 시에 적절한 자식 클래스의 함수를 찾아야 하는데, virtual 키워드를 붙여주지 않으면 그저 부모클래스의 함수를 호출하게 된다.
* virtual 키워드가 붙은 함수는 virtual 함수가 되고, virtual 함수가 존재하는 클래스에는 v-table가 생성되게 된다.
* v-table에서 다운캐스팅된 자식 클래스의 적절한 함수를 탐색하고 그것을 호출할 수 있게 된다.
* 특히나 '소멸자'에 적절히 붙여줘야 함!
*/
class Base
{
protected:
	int n;
	string s;
public:
	Base() { n = 0; s = ""; cout << "Base 기본 생성자" << endl; }
	Base(int n,const char* s) : n(n), s(s){}
	virtual ~Base() { cout << "Base 소멸자"<<endl; }//다운캐스팅 시 자식 클래스의 소멸자를 적절히 호출시키기 위함
	string getString() { return s; }

	
};

class Derived : public Base
{
public:
	Derived() { n = 0; s = ""; cout << "Derived 기본 생성자" << endl; }
	Derived(int n, const char* s) {  }
	~Derived() { cout << "Derived 소멸자"<<endl; }
};
int main()
{
	Base* A = new Base(1,"1234");
	Base* B = new Derived();//다운캐스팅!

	//...DoSomething..
	cout<<A->getString()<<endl;
	//..
	//
	delete A;
	delete B;//베이스 클래스 소멸자에 virtual키워드가 있으므로 자식,부모클래스의 소멸자가 정확히 호출됨.
			 //virtual 키워드가 없으면 v-table이 없어 적절한 함수호출이 이루어지지 않아 부모클래스의 소멸자만 호출됨
	return 0;
}