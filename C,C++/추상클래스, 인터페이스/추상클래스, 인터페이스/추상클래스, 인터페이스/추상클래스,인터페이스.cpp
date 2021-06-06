#include<iostream>
#include<vector>
using namespace std;

//1. 순수 가상 함수 : virtual 키워드를 반환형 앞에 붙여줌. 그리고  = 0;
//함수의 정의를 하지 않고, 해당 함수를 포함한 클래스의 자식 클래스에서 정의함.
//아래의 예시처럼 자식 클래스에서 꼭 정의해야하는 함수가 있을 때, 까먹고 정의하지 않았다면 컴파일러의 힘을 빌려 해결할 수 있다.
// 
//2. 추상 클래스 : 순수 가상 함수를 하나라도 포함하고 있다면! 그것은 추상 클래스
//
//3. 인터페이스 : 클래스가 모두 순수 가상함수로 이루어져 있다면 그것은 인터페이스라고 부른다.
class Character
{
	virtual void Attack() = 0; //순수 가상 함수, '꼭' 자식 클래스에서 오버라이드 해서 정의해줘야 함.
	virtual void Run() = 0;
};

class Warrior : public Character
{
	void Attack() override
	{
		cout << "근거리 공격!" << endl;
	}

	void Run() override
	{
		cout << "뚜벅뚜벅" << endl;
	}
};

class Magician : public Character
{
	void MagicAttack()
	{
		cout << "원거리 공격!" << endl;
	}

	void Run() override
	{
		cout << "비행이동" << endl;
	}
};

int main()
{

	vector<Character> v;

	v.emplace_back(new Character());//컴파일 에러 발생! 클래스 내에 순수가상함수가 포함되어있으면 객체 선언을 할 수 없다.

	v.emplace_back(new Magician()); // 컴파일 에러 발생! Attack을 오버라이드 해야하는 것을 까먹고 MagicAttack 함수를 새로 만듦.
	v.emplace_back(new Warrior());// 문제 없음.

	

}