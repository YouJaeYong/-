#include<iostream>
#include<vector>
using namespace std;

//1. ���� ���� �Լ� : virtual Ű���带 ��ȯ�� �տ� �ٿ���. �׸���  = 0;
//�Լ��� ���Ǹ� ���� �ʰ�, �ش� �Լ��� ������ Ŭ������ �ڽ� Ŭ�������� ������.
//�Ʒ��� ����ó�� �ڽ� Ŭ�������� �� �����ؾ��ϴ� �Լ��� ���� ��, ��԰� �������� �ʾҴٸ� �����Ϸ��� ���� ���� �ذ��� �� �ִ�.
// 
//2. �߻� Ŭ���� : ���� ���� �Լ��� �ϳ��� �����ϰ� �ִٸ�! �װ��� �߻� Ŭ����
//
//3. �������̽� : Ŭ������ ��� ���� �����Լ��� �̷���� �ִٸ� �װ��� �������̽���� �θ���.
class Character
{
	virtual void Attack() = 0; //���� ���� �Լ�, '��' �ڽ� Ŭ�������� �������̵� �ؼ� ��������� ��.
	virtual void Run() = 0;
};

class Warrior : public Character
{
	void Attack() override
	{
		cout << "�ٰŸ� ����!" << endl;
	}

	void Run() override
	{
		cout << "�ѹ��ѹ�" << endl;
	}
};

class Magician : public Character
{
	void MagicAttack()
	{
		cout << "���Ÿ� ����!" << endl;
	}

	void Run() override
	{
		cout << "�����̵�" << endl;
	}
};

int main()
{

	vector<Character> v;

	v.emplace_back(new Character());//������ ���� �߻�! Ŭ���� ���� ���������Լ��� ���ԵǾ������� ��ü ������ �� �� ����.

	v.emplace_back(new Magician()); // ������ ���� �߻�! Attack�� �������̵� �ؾ��ϴ� ���� ��԰� MagicAttack �Լ��� ���� ����.
	v.emplace_back(new Warrior());// ���� ����.

	

}