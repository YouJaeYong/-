#include<iostream>

using namespace std;
//이게 무슨 상황인지 모르겠음.
//주소가 같은데 참조하고있는 값은 다르다.
//이래서 잘 안쓰는건가 싶긴 한데 공부가 더 필요할 듯.
int main()
{

	const int a = 10;
	int* b = const_cast<int*> (&a);
	*b = 20;

	cout << &a << " " << b << endl;
	cout << a <<" "<<*b <<endl; 
}