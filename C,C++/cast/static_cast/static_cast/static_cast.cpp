#include<iostream>
#include<vector>
using namespace std;

//dynamic cast : 런타임 시에 런타임 오류를 사용해 위험 방지(특히 다운캐스트 시에). RTTI를 위한 비용이 큰 편
//static_cast : C스타일의 형변환과 비슷하고 컴파일 타임에 오류를 발생시킴. 어떤 형인지 정확히 알 때에 씀.


class Character {

public:
	virtual void DoSomethingPublic()  {};
};

class Magician: public Character {

public:
	void DoSomethingPublic() override { cout << "I'm Magician class" << endl; };

	void OnlyA() { cout << "Magical Attack!" << endl; }


	Magician()
	{

	}

	Magician(Magician&& M)
	{
		cout << "move constructor" << endl;
	}
};

class Warrior : public Character {

public:
	void DoSomethingPublic() override { cout << "I'm Warrior class" << endl; };

	void OnlyB() { cout << "Combat Attack!" << endl; }

	Warrior()
	{

	}

	Warrior(Warrior&& M)
	{
		cout << "move constructor" << endl;
	}
};
int main()
{


	vector<Character*> v;

	v.emplace_back(new Magician  ());//upcasting
	v.emplace_back(new Warrior  ());//upcasting


	Magician* m = new Magician();

	Magician* m2 = static_cast<Magician*>(m);//바로 아랫줄이라서 극단적인 예시지만 무슨 타입인지 정확히 알 때에 사용. 
											//dynamic_cast를 사용해도 되나 효율상 static_cast의 사용이 적절함.

	Magician m3;
	Magician m4 = static_cast<Magician&&>(m3); //이런식으로 move와 비슷하게 사용할 수도 있다고 함.
	m4.OnlyA(); // Magical Attack!


	for (auto loop : v)
	{
		//Warrior* w = static_cast<Warrior*>(loop);//논리적 오류 발생!! 컴파일 시기에는 v 벡터에 뭐가 업캐스팅 되어서 들어갈지 모름
		Warrior* w = dynamic_cast<Warrior*>(loop);//RTTI를 활용해 v의 타입에 대한 질의
		if (w)//w에 대한 캐스트가 성공했다면? not null
			w->OnlyB(); // Combat Attack!

	}
}