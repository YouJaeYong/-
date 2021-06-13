#include<iostream>
#include<vector>
using namespace std;

/* 
move() : ��ü�� �������� �ʰ� �̵���Ű�� ���� ��� == ��ü�� r-value�� ���޽�Ű�� ���� �� ���
���縦 �ϰԵǸ� �ӽð�ü�� ������ �����ϰ� �ǰ� �޸𸮸� ��� �ǹǷ�(�ý��� ��) ������ ���ϵ� ���ۿ� ����.
�̸� �����ϰ��� ���簡 �ƴ� �̵��� ä���ϴ� ��! ���� ���縦 �ؾ��� ���� �̵��� �ؾ��� ���� �� �����ؾ� �Ѵ�.
*/
class A
{

	char* s =nullptr;

public: 
	A()//����Ʈ ������
	{

	}
	A(const char* str)
	{
		cout << "������ ȣ��"<< endl;
		this->s = new char[sizeof(str)];
		strcpy_s(s, sizeof(s),str);
	}
	A(const A& rhs)//���縦 �ϴµ� ������ �����ϴ°� ���� �ȵǹǷ� const�� ��ȣ���ش�.
	{
		cout << "���� ȣ��! " <<endl;
		this->s = new char[sizeof(rhs.s)];
		strcpy_s(s, sizeof(s), rhs.s);
		
	}

	A(A&& rhs) noexcept //�� Ű���带 �ٿ� ���ܻ�Ȳ�� ������ ����ؾ� ���������� �̵������ڰ� ȣ���
	{
		cout << "�̵� ȣ��!" << endl;
		this->s = rhs.s;
		rhs.s = nullptr;
	}
	void print()
	{
		
		printf("ptr : %p\n", s);
	}

	~A()
	{
		printf("�Ҹ��� ptr : %p\n", s);
		if (s)
			delete[] s;
	
	}
};


int main()
{
	A a("abcd");

	A b = a; //����
	a.print();//�ٸ�
	b.print();//���� �ٸ� �ּ�
	A c = move(a);//�̵�
	a.print();//�ٷ� �� �ٿ��� move�ϸ鼭 a�� �����͸� ��������. �ƹ��͵� ��� �ȵ�.
	b.print();//c�� �ٸ�
	c.print();//a�� ������, ���� a�� nullptr

	vector<A> v1;

	v1.push_back(b);//����
	v1.push_back(move(c));//�̵�

	a.print();
	b.print();
	c.print();

	return 0;
}