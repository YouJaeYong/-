#include<iostream>

using namespace std;

//포인터<->변수, 포인터<->포인터, 변수<->포인터 간의 자유로운 형변환에 사용
//void* 전달 가능, 주로 패킷 통신이나 해시값을 반환하는 등의 특수한 상황에서만 사용하는 듯
//자유롭지만 그만큼 의도치않은 다양한 상황이 나올 수 있기 때문
struct PACKET_LOGIN
{
	int id;
	char name[10];
	int level;
};

int main()
{
	
	PACKET_LOGIN* p = new PACKET_LOGIN();
	p->id = 100;
	p->level = 10;
	strncpy_s(p->name, "재용",sizeof("재용"));
	char* send_packet = reinterpret_cast<char*>(p);
	//... 해당 패킷 send 했다는 가정...
	//
	//Server-> Client로 이동
	//
	//클라이언트에서 위의 패킷을 recv 했다고 가정

	PACKET_LOGIN* recv_packet = reinterpret_cast<PACKET_LOGIN*>(send_packet);

	cout <<"id : "<< recv_packet->id<<"\n";
	cout <<"name : "<< recv_packet->name<<"\n";
	cout <<"level : "<< recv_packet->level<<"\n";
}