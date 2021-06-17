#include<iostream>
#include<memory>
#include<mutex>
using namespace std;
/*
RAII : Resources Acquisition Is Initialize
(나름의 정의로는) 객체가 생성될 때는 자원(메모리)를 확실히 획득하는 것이 보장되어야 하고,
제거될 때도 마찬가지로 가지고 있는 자원을 모두 확실히 반환해야 한다.
예외가 발생하거나 하는 상황에 의해 위의 조건들이 깨져선 안된다.

ex) smart pointer, lock_guard와 같이 클래스를 사용해 스코프가 끝날 때 객체도 자동 해제 되는 것을 이용한 기법들
*/

#define PACKET_SIZE 255

int main()
{



	mutex m;

	lock_guard<mutex> lock(m); //lock_guard 클래스의 생성자에 m을 넣어서 생성해 줌.

	auto_ptr<char> packet(new char[PACKET_SIZE] {'a', 'b', 'c', 'd' }); //auto_ptr이라는 클래스에 포인터를 맡겼다
												  //auto_ptr클래스 안엔 적절한 소멸자가 구현되어 있어, 호출될 시 가지고 있는 자원을 적절히 해제한다.


	if (packet.get()[1] != 'a') // false
		return 0;


	//위의 예외를 통해 리턴이 되어도 mutex가 unlock이 되지 않을 걱정은 안해도 된다.
	//lock_guard 클래스가 적절히 해제해 줌!


}