#include<vector>
#include<iostream>
/*vector
* 1. Sequence Container(객체를 순차적으로 보관, 메모리상에 연속적으로 저장)
* 2. 원소 접근 : O(1)
* 3. 삽입 및 삭제 : 맨 뒤 인덱스에서 작업 시 O(1), 임의의 위치에서 작업시 O(N) 메모리를 한칸씩 뒤로 밀어줘야 하기 때문
*/
using namespace std;

int main()
{
	vector <int> v;

	v.emplace_back(1);//무브 시퀀스를 활용해 임시객체 생성 및 복사하는 작업을 줄여줌

	vector <pair<int, int>> v2;//pair 컨테이너를 저장할 vector

	v2.emplace_back(make_pair(1, 2));//pair를 저장할 땐 이처럼 make_pair를 활용해 준다.
	v2.emplace_back(make_pair(3, 4));//pair를 저장할 땐 이처럼 make_pair를 활용해 준다.
	v2.emplace_back(make_pair(5, 6));//pair를 저장할 땐 이처럼 make_pair를 활용해 준다.



	vector<vector<int>> v3(3, vector<int>(3));//3x3 2차원의 벡터 메모리 할당

	for (auto v : v3[0]) //범위 기반의 포문
		cout << v;

	cout << endl;


	//반복자 사용

	for (auto itr = v2.begin(); itr < v2.end(); ++itr) // auto ==  std::vector<pair<int,int>>::iterator
		cout << itr->first << " " << itr->second << endl;


	auto itr = v3[0].begin(); // auto ==  std::vector<int>::iterator

	for (itr; itr < v3[0].end(); ++itr) 
		cout << *itr;
	cout << endl;

	//capacity, size의 차이
	v.reserve(20);//벡터는 공간이 부족하면 동적으로 사이즈를 재할당 하므로
				  //이 작업의 빈도를 줄이기 위해 reserve 함수를 제공한다.
				 //메모리 할당이나 해제가 잦으면 system call이 빈번해지므로 context switcing 발생, 비효율 적

	cout << "v.size() : " << v.size() << " v.capacity : " <<v.capacity(); //size : 1, capacity : 20
																		 //size는 실제 값이 들어있는 공간의 수, capacity는 할당된 공간의 수임을 알 수 있다.

	return 0;

}