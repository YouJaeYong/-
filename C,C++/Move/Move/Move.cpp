#include<iostream>
#include<vector>
using namespace std;

/* 
move() : 객체를 복사하지 않고 이동시키기 위해 사용 == 객체를 r-value로 전달시키고 싶을 때 사용
복사를 하게되면 임시객체를 여러번 생성하게 되고 메모리를 잡게 되므로(시스템 콜) 성능이 저하될 수밖에 없다.
이를 방지하고자 복사가 아닌 이동을 채택하는 것! 물론 복사를 해야할 때랑 이동을 해야할 때를 잘 구별해야 한다.
*/
class A
{

	char* s =nullptr;

public: 
	A()//디폴트 생성자
	{

	}
	A(const char* str)
	{
		cout << "생성자 호출"<< endl;
		this->s = new char[sizeof(str)];
		strcpy_s(s, sizeof(s),str);
	}
	A(const A& rhs)//복사를 하는데 원본을 수정하는게 말이 안되므로 const로 보호해준다.
	{
		cout << "복사 호출! " <<endl;
		this->s = new char[sizeof(rhs.s)];
		strcpy_s(s, sizeof(s), rhs.s);
		
	}

	A(A&& rhs) noexcept //이 키워드를 붙여 예외상황이 없음을 명시해야 정상적으로 이동생성자가 호출됨
	{
		cout << "이동 호출!" << endl;
		this->s = rhs.s;
		rhs.s = nullptr;
	}
	void print()
	{
		
		printf("ptr : %p\n", s);
	}

	~A()
	{
		printf("소멸자 ptr : %p\n", s);
		if (s)
			delete[] s;
	
	}
};


int main()
{
	A a("abcd");

	A b = a; //복사
	a.print();//다름
	b.print();//위와 다른 주소
	A c = move(a);//이동
	a.print();//바로 윗 줄에서 move하면서 a의 데이터를 삭제했음. 아무것도 출력 안됨.
	b.print();//c와 다름
	c.print();//a와 같으나, 이제 a는 nullptr

	vector<A> v1;

	v1.push_back(b);//복사
	v1.push_back(move(c));//이동

	a.print();
	b.print();
	c.print();

	return 0;
}