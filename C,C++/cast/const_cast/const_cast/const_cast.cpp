#include<iostream>

using namespace std;
//�̰� ���� ��Ȳ���� �𸣰���.
//�ּҰ� ������ �����ϰ��ִ� ���� �ٸ���.
//�̷��� �� �Ⱦ��°ǰ� �ͱ� �ѵ� ���ΰ� �� �ʿ��� ��.
int main()
{

	const int a = 10;
	int* b = const_cast<int*> (&a);
	*b = 20;

	cout << &a << " " << b << endl;
	cout << a <<" "<<*b <<endl; 
}