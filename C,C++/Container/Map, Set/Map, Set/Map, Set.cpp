#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

/*set, map : 중복 원소 허용하지 않음, 자동으로 정렬되어 원소가 저장됨(Tree의 성질)
								삽입 삭제 및 탐색 -> 평균 : O(log N), 최악 O(N) 트리가 한 쪽으로 쏠릴 경우(트리의 층 수랑 원소의 수가 같게 됨)

* multiset,multimap : 중복 원소를 허용함, find 함수로 원소를 찾을 시 같은 원소가 여러 개 있을 수 있으므로 equal_range()함수를 사용하게 됨  
								삽입 삭제 및 탐색 -> 평균 : O(log N), 최악 O(N) <- 트리가 한 쪽으로 쏠릴 경우(트리의 층 수랑 원소의 수가 같게 됨)

* unordered_set, unordered_map : 해싱을 통해 원소들을 저장한다. 해시 충돌이 적어야 함(같은 키 값으로 최대한 중복이 안되도록 해시함수를 잘 구현)
*								삽입 삭제 및 탐색 -> 평균 : O(1) <- 해시 충돌이 없을 경우, 최악 O(N) <- 모든 원소가 한 키값에 몰릴 경우
*								또한 삽입되는 원소가 많아질 수록 해싱 값들이 늘어나게 되는데 그 때 Rehash가 일어나 O(N)만큼의 코스트가 든다.
* 
* 내 생각엔 unordered_map 컨테이너를 사용해 서버에 접속한 유저객체를 관리할 것 같다.
  많은 유저들이 접속, 종료하면 당연히 삽입 삭제나 탐색이 잦을 것이고 그렇다면 가장 효율적인 컨테이너라고 생각하지만 현업 코드를 보기전엔 모르겠다.
*/
template<class T>
void Set_Print(const set<T>& s)
{
	typename set<T>::iterator itr = s.begin();//Bidirectional(순차적으로만 접근 가능, 랜덤 액세스 x) 반복자 제공

	for (itr; itr != s.end(); ++itr)
		cout << *itr << endl;


}
int main()
{

	cout << "*****Set Exam*****" << endl;

	set<string> s1;

	s1.insert("1 번째 원소"); // 삽입에는 insert 함수 제공
	s1.insert("1 번째 원소");
	s1.insert("1 번째 원소"); // 같은 값을 가진 원소를 세 번 넣었다.

	
	Set_Print(s1); //출력 -> "첫 번째 원소"

	set<short> s2;

	s2.insert(3);
	s2.insert(7);
	s2.insert(15);
	s2.insert(19);
	s2.insert(21);
	s2.insert(19);

	Set_Print(s2);

	s2.erase(7); // 제거는 erase 함수를 사용

	int target = 7;
	auto itr = s2.find(target); // 찾으면 해당 원소의 위치, 아니면 end의 위치를 리턴한다.
	if (itr != s2.end())
		cout << *itr << endl;
	else
		cout << "Can not FInd Element : " << target << endl << endl;
/* 위처럼 중복되는 원소는 허용을 하지 않고, 자동으로 정렬되어 저장된다.
* 이유는 내부적으로 R/B Tree로 구현되어 있기 때문
* 중복을 허용하려면? -> Multiset 사용
*/

	cout << "*****MultiSet Exam*****" << endl;

	multiset<string>ms;

	ms.insert("2번째 원소");
	ms.insert("1번째 원소");
	ms.insert("1번째 원소");
	ms.insert("3번째 원소");

	for (auto itr = ms.begin(); itr != ms.end(); itr++)
		cout << *itr << endl; //중복되는 원소가 모두 출력되는 것을 확인할 수 있다.
							  //또한 Set과 마찬가지로 자동정렬된다.

	auto ms_range = ms.equal_range("1번째 원소");//equal_range() : 인자로 들어간 값의 범위(중복일 경우)를 pair형태로 반환해준다.

	cout << "'1번째 원소'라는 값을 가진 반복자의 범위" << endl;

	for (auto itr = ms_range.first; itr != ms_range.second; ++itr)
		cout << *itr<<endl;//2개 출력



	cout << "*****Map Exam*****" << endl<<endl;

	map<int, string> m;

	m.insert(make_pair(1, "일재용"));//이처럼 Key와 Value를 Pair로 묶어서 삽입해주면 된다.
	m.insert(make_pair(2, "이재용"));
	m.insert(make_pair(5, "오재용"));
	m.insert(make_pair(4, "사재용"));
	m.insert(make_pair(6, "육재용"));


	for (auto itr = m.begin(); itr != m.end(); ++itr)
		cout << itr->first << " : " << itr->second << endl; // 이와같이 pair에 접근하면 되겠다.
															// set과 마찬가지로 자동 정렬된 것을 확인할 수 있다.

	cout <<"키값 2에 대응되는 값은? : " << m[2] << endl<<endl;//[]연산에 키값을 넘겨 밸류를 찾을 수도 있다.
	

	cout << "없는 키값인 3을 통해 값을 찾으려 하면? " << m[3] << endl;

	for (auto itr = m.begin(); itr != m.end(); ++itr)
		cout << itr->first << " : " << itr->second << endl; //이와같이 값이 비어있는 키값 3의 원소가 새로 생성된다. 주의해야함

	 
	cout << "*****Unordered_set,map*****" << endl << endl;

	
	unordered_set<string> u_s;

	u_s.insert("유재용");// insert : O(1)에 수행, 최악의 경우 O(N)
	u_s.insert("유재용");
	u_s.insert("서버");
	u_s.insert("클라이언트");
	u_s.insert("게임공학부");


	for (auto itr = u_s.begin(); itr != u_s.end(); itr++)
		cout << *itr << endl;//중복 허용 안됨, 자동 정렬 안되는 것을 확인

	auto find = u_s.find("유재용");//find : O(1)에 수행, 최악의 경우 O(N)

	if (find == u_s.end())
		cout << "타겟을 찾지 못함"<<endl;
	else
		cout << "타겟을 찾음" << endl;


	unordered_map<int, string> u_m;

	

}


