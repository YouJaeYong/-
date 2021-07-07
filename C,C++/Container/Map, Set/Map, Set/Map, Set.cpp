#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

/*set, map : �ߺ� ���� ������� ����, �ڵ����� ���ĵǾ� ���Ұ� �����(Tree�� ����)
								���� ���� �� Ž�� -> ��� : O(log N), �־� O(N) Ʈ���� �� ������ �� ���(Ʈ���� �� ���� ������ ���� ���� ��)

* multiset,multimap : �ߺ� ���Ҹ� �����, find �Լ��� ���Ҹ� ã�� �� ���� ���Ұ� ���� �� ���� �� �����Ƿ� equal_range()�Լ��� ����ϰ� ��  
								���� ���� �� Ž�� -> ��� : O(log N), �־� O(N) <- Ʈ���� �� ������ �� ���(Ʈ���� �� ���� ������ ���� ���� ��)

* unordered_set, unordered_map : �ؽ��� ���� ���ҵ��� �����Ѵ�. �ؽ� �浹�� ����� ��(���� Ű ������ �ִ��� �ߺ��� �ȵǵ��� �ؽ��Լ��� �� ����)
*								���� ���� �� Ž�� -> ��� : O(1) <- �ؽ� �浹�� ���� ���, �־� O(N) <- ��� ���Ұ� �� Ű���� ���� ���
*								���� ���ԵǴ� ���Ұ� ������ ���� �ؽ� ������ �þ�� �Ǵµ� �� �� Rehash�� �Ͼ O(N)��ŭ�� �ڽ�Ʈ�� ���.
* 
* �� ������ unordered_map �����̳ʸ� ����� ������ ������ ������ü�� ������ �� ����.
  ���� �������� ����, �����ϸ� �翬�� ���� ������ Ž���� ���� ���̰� �׷��ٸ� ���� ȿ������ �����̳ʶ�� ���������� ���� �ڵ带 �������� �𸣰ڴ�.
*/
template<class T>
void Set_Print(const set<T>& s)
{
	typename set<T>::iterator itr = s.begin();//Bidirectional(���������θ� ���� ����, ���� �׼��� x) �ݺ��� ����

	for (itr; itr != s.end(); ++itr)
		cout << *itr << endl;


}
int main()
{

	cout << "*****Set Exam*****" << endl;

	set<string> s1;

	s1.insert("1 ��° ����"); // ���Կ��� insert �Լ� ����
	s1.insert("1 ��° ����");
	s1.insert("1 ��° ����"); // ���� ���� ���� ���Ҹ� �� �� �־���.

	
	Set_Print(s1); //��� -> "ù ��° ����"

	set<short> s2;

	s2.insert(3);
	s2.insert(7);
	s2.insert(15);
	s2.insert(19);
	s2.insert(21);
	s2.insert(19);

	Set_Print(s2);

	s2.erase(7); // ���Ŵ� erase �Լ��� ���

	int target = 7;
	auto itr = s2.find(target); // ã���� �ش� ������ ��ġ, �ƴϸ� end�� ��ġ�� �����Ѵ�.
	if (itr != s2.end())
		cout << *itr << endl;
	else
		cout << "Can not FInd Element : " << target << endl << endl;
/* ��ó�� �ߺ��Ǵ� ���Ҵ� ����� ���� �ʰ�, �ڵ����� ���ĵǾ� ����ȴ�.
* ������ ���������� R/B Tree�� �����Ǿ� �ֱ� ����
* �ߺ��� ����Ϸ���? -> Multiset ���
*/

	cout << "*****MultiSet Exam*****" << endl;

	multiset<string>ms;

	ms.insert("2��° ����");
	ms.insert("1��° ����");
	ms.insert("1��° ����");
	ms.insert("3��° ����");

	for (auto itr = ms.begin(); itr != ms.end(); itr++)
		cout << *itr << endl; //�ߺ��Ǵ� ���Ұ� ��� ��µǴ� ���� Ȯ���� �� �ִ�.
							  //���� Set�� ���������� �ڵ����ĵȴ�.

	auto ms_range = ms.equal_range("1��° ����");//equal_range() : ���ڷ� �� ���� ����(�ߺ��� ���)�� pair���·� ��ȯ���ش�.

	cout << "'1��° ����'��� ���� ���� �ݺ����� ����" << endl;

	for (auto itr = ms_range.first; itr != ms_range.second; ++itr)
		cout << *itr<<endl;//2�� ���



	cout << "*****Map Exam*****" << endl<<endl;

	map<int, string> m;

	m.insert(make_pair(1, "�����"));//��ó�� Key�� Value�� Pair�� ��� �������ָ� �ȴ�.
	m.insert(make_pair(2, "�����"));
	m.insert(make_pair(5, "�����"));
	m.insert(make_pair(4, "�����"));
	m.insert(make_pair(6, "�����"));


	for (auto itr = m.begin(); itr != m.end(); ++itr)
		cout << itr->first << " : " << itr->second << endl; // �̿Ͱ��� pair�� �����ϸ� �ǰڴ�.
															// set�� ���������� �ڵ� ���ĵ� ���� Ȯ���� �� �ִ�.

	cout <<"Ű�� 2�� �����Ǵ� ����? : " << m[2] << endl<<endl;//[]���꿡 Ű���� �Ѱ� ����� ã�� ���� �ִ�.
	

	cout << "���� Ű���� 3�� ���� ���� ã���� �ϸ�? " << m[3] << endl;

	for (auto itr = m.begin(); itr != m.end(); ++itr)
		cout << itr->first << " : " << itr->second << endl; //�̿Ͱ��� ���� ����ִ� Ű�� 3�� ���Ұ� ���� �����ȴ�. �����ؾ���

	 
	cout << "*****Unordered_set,map*****" << endl << endl;

	
	unordered_set<string> u_s;

	u_s.insert("�����");// insert : O(1)�� ����, �־��� ��� O(N)
	u_s.insert("�����");
	u_s.insert("����");
	u_s.insert("Ŭ���̾�Ʈ");
	u_s.insert("���Ӱ��к�");


	for (auto itr = u_s.begin(); itr != u_s.end(); itr++)
		cout << *itr << endl;//�ߺ� ��� �ȵ�, �ڵ� ���� �ȵǴ� ���� Ȯ��

	auto find = u_s.find("�����");//find : O(1)�� ����, �־��� ��� O(N)

	if (find == u_s.end())
		cout << "Ÿ���� ã�� ����"<<endl;
	else
		cout << "Ÿ���� ã��" << endl;


	unordered_map<int, string> u_m;

	

}


