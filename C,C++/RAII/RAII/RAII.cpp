#include<iostream>
#include<memory>
#include<mutex>
using namespace std;
/*
RAII : Resources Acquisition Is Initialize
(������ ���Ƿδ�) ��ü�� ������ ���� �ڿ�(�޸�)�� Ȯ���� ȹ���ϴ� ���� ����Ǿ�� �ϰ�,
���ŵ� ���� ���������� ������ �ִ� �ڿ��� ��� Ȯ���� ��ȯ�ؾ� �Ѵ�.
���ܰ� �߻��ϰų� �ϴ� ��Ȳ�� ���� ���� ���ǵ��� ������ �ȵȴ�.

ex) smart pointer, lock_guard�� ���� Ŭ������ ����� �������� ���� �� ��ü�� �ڵ� ���� �Ǵ� ���� �̿��� �����
*/

#define PACKET_SIZE 255

int main()
{



	mutex m;

	lock_guard<mutex> lock(m); //lock_guard Ŭ������ �����ڿ� m�� �־ ������ ��.

	auto_ptr<char> packet(new char[PACKET_SIZE] {'a', 'b', 'c', 'd' }); //auto_ptr�̶�� Ŭ������ �����͸� �ð��
												  //auto_ptrŬ���� �ȿ� ������ �Ҹ��ڰ� �����Ǿ� �־�, ȣ��� �� ������ �ִ� �ڿ��� ������ �����Ѵ�.


	if (packet.get()[1] != 'a') // false
		return 0;


	//���� ���ܸ� ���� ������ �Ǿ mutex�� unlock�� ���� ���� ������ ���ص� �ȴ�.
	//lock_guard Ŭ������ ������ ������ ��!


}