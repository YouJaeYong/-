#include<iostream>
using namespace std;



//perfect forwarding : ���� Ÿ���� ���ø� �Ķ���ͷ� ����ϴ� ���ø� �Լ�����
//�� �ٸ� �Լ��� �Ķ���͸� ������ �� �߻��ϴ� ������ Forwarding Problem �̶�� ����մϴ�.

template<typename T>
void func(T& n) {    //non-perfect forwarding - �������·� ����.
    cout << typeid(n).name() << " : " << n << endl;
}


template<typename T>
T& p_fwd_func(T&& n) //perfect forwarding(&&)
{
    cout << typeid(n).name() << " : " << n << endl;

    /*
    ���� n�� �Լ� ���ο����� ���� Ÿ��
    1.  n == l-value(������ �ּҰ��� �����ϱ�)
    2.  "hwan" == l-value(const char*, ������� ���� l-value)
    3.  1.123 == l-value(�̰��� ������ �� �� ����! �и� ���ڷ� 1.123�� �Ѱ��� �� r-value�μ� ������ �ٶ��� �ٵ�?)
    */


    //�ذ�
    return forward<T&>(n);
                           /*
                           n�� �����ڷ� ����ϰų� �����ϴ� ������ �ٸ� ���� ������ ��
                           �ǵ��� Ÿ������ �����ϱ� ���� ����ϴ� Ű���尡 'forward'
                           �̷ν� 1.123�� r-value�� ������ �� �ְ� �Ǿ���.
                           */
}

int main() {

    int n = 10;
    func(n);       //OK
    func("hwan");  //OK
   // func(1.123);   //��ģ���� ���� const T& n Ÿ���� �����ε� �ؾ��ϳ�? ��!

   
    p_fwd_func(1.123);  //OK
    return 0;
}