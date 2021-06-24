#include<vector>
#include<iostream>
/*vector
* 1. Sequence Container(��ü�� ���������� ����, �޸𸮻� ���������� ����)
* 2. ���� ���� : O(1)
* 3. ���� �� ���� : �� �� �ε������� �۾� �� O(1), ������ ��ġ���� �۾��� O(N) �޸𸮸� ��ĭ�� �ڷ� �о���� �ϱ� ����
*/
using namespace std;

int main()
{
	vector <int> v;

	v.emplace_back(1);//���� �������� Ȱ���� �ӽð�ü ���� �� �����ϴ� �۾��� �ٿ���

	vector <pair<int, int>> v2;//pair �����̳ʸ� ������ vector

	v2.emplace_back(make_pair(1, 2));//pair�� ������ �� ��ó�� make_pair�� Ȱ���� �ش�.
	v2.emplace_back(make_pair(3, 4));//pair�� ������ �� ��ó�� make_pair�� Ȱ���� �ش�.
	v2.emplace_back(make_pair(5, 6));//pair�� ������ �� ��ó�� make_pair�� Ȱ���� �ش�.



	vector<vector<int>> v3(3, vector<int>(3));//3x3 2������ ���� �޸� �Ҵ�

	for (auto v : v3[0]) //���� ����� ����
		cout << v;

	cout << endl;


	//�ݺ��� ���

	for (auto itr = v2.begin(); itr < v2.end(); ++itr) // auto ==  std::vector<pair<int,int>>::iterator
		cout << itr->first << " " << itr->second << endl;


	auto itr = v3[0].begin(); // auto ==  std::vector<int>::iterator

	for (itr; itr < v3[0].end(); ++itr) 
		cout << *itr;
	cout << endl;

	//capacity, size�� ����
	v.reserve(20);//���ʹ� ������ �����ϸ� �������� ����� ���Ҵ� �ϹǷ�
				  //�� �۾��� �󵵸� ���̱� ���� reserve �Լ��� �����Ѵ�.
				 //�޸� �Ҵ��̳� ������ ������ system call�� ��������Ƿ� context switcing �߻�, ��ȿ�� ��

	cout << "v.size() : " << v.size() << " v.capacity : " <<v.capacity(); //size : 1, capacity : 20
																		 //size�� ���� ���� ����ִ� ������ ��, capacity�� �Ҵ�� ������ ������ �� �� �ִ�.

	return 0;

}