#include<iostream>

using namespace std;

//������<->����, ������<->������, ����<->������ ���� �����ο� ����ȯ�� ���
//void* ���� ����, �ַ� ��Ŷ ����̳� �ؽð��� ��ȯ�ϴ� ���� Ư���� ��Ȳ������ ����ϴ� ��
//���������� �׸�ŭ �ǵ�ġ���� �پ��� ��Ȳ�� ���� �� �ֱ� ����
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
	strncpy_s(p->name, "���",sizeof("���"));
	char* send_packet = reinterpret_cast<char*>(p);
	//... �ش� ��Ŷ send �ߴٴ� ����...
	//
	//Server-> Client�� �̵�
	//
	//Ŭ���̾�Ʈ���� ���� ��Ŷ�� recv �ߴٰ� ����

	PACKET_LOGIN* recv_packet = reinterpret_cast<PACKET_LOGIN*>(send_packet);

	cout <<"id : "<< recv_packet->id<<"\n";
	cout <<"name : "<< recv_packet->name<<"\n";
	cout <<"level : "<< recv_packet->level<<"\n";
}