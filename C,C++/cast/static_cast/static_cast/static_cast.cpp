#include<iostream>
#include<vector>
using namespace std;

//dynamic cast : ��Ÿ�� �ÿ� ��Ÿ�� ������ ����� ���� ����(Ư�� �ٿ�ĳ��Ʈ �ÿ�). RTTI�� ���� ����� ū ��
//static_cast : C��Ÿ���� ����ȯ�� ����ϰ� ������ Ÿ�ӿ� ������ �߻���Ŵ. � ������ ��Ȯ�� �� ���� ��.


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

	Magician* m2 = static_cast<Magician*>(m);//�ٷ� �Ʒ����̶� �ش����� �������� ���� Ÿ������ ��Ȯ�� �� ���� ���. 
											//dynamic_cast�� ����ص� �ǳ� ȿ���� static_cast�� ����� ������.

	Magician m3;
	Magician m4 = static_cast<Magician&&>(m3); //�̷������� move�� ����ϰ� ����� ���� �ִٰ� ��.
	m4.OnlyA(); // Magical Attack!


	for (auto loop : v)
	{
		//Warrior* w = static_cast<Warrior*>(loop);//���� ���� �߻�!! ������ �ñ⿡�� v ���Ϳ� ���� ��ĳ���� �Ǿ ���� ��
		Warrior* w = dynamic_cast<Warrior*>(loop);//RTTI�� Ȱ���� v�� Ÿ�Կ� ���� ����
		if (w)//w�� ���� ĳ��Ʈ�� �����ߴٸ�? not null
			w->OnlyB(); // Combat Attack!

	}
}