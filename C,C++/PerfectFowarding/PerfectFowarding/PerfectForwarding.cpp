#include<iostream>
using namespace std;



//perfect forwarding : 참조 타입을 템플릿 파라미터로 사용하는 템플릿 함수에서
//또 다른 함수로 파라미터를 전달할 때 발생하는 문제를 Forwarding Problem 이라고 얘기합니다.

template<typename T>
void func(T& n) {    //non-perfect forwarding - 참조형태로 받음.
    cout << typeid(n).name() << " : " << n << endl;
}


template<typename T>
T& p_fwd_func(T&& n) //perfect forwarding(&&)
{
    cout << typeid(n).name() << " : " << n << endl;

    /*
    인자 n의 함수 내부에서의 변수 타입
    1.  n == l-value(엄연히 주소값이 있으니까)
    2.  "hwan" == l-value(const char*, 상수성에 의해 l-value)
    3.  1.123 == l-value(이것이 문제가 될 수 있음! 분명 인자로 1.123을 넘겨줄 땐 r-value로서 들어오길 바랐을 텐데?)
    */


    //해결
    return forward<T&>(n);
                           /*
                           n을 생성자로 사용하거나 리턴하는 등으로 다른 곳에 전달할 때
                           의도한 타입으로 전달하기 위해 사용하는 키워드가 'forward'
                           이로써 1.123을 r-value로 전달할 수 있게 되었다.
                           */
}

int main() {

    int n = 10;
    func(n);       //OK
    func("hwan");  //OK
   // func(1.123);   //이친구를 위해 const T& n 타입을 오버로딩 해야하나? 놉!

   
    p_fwd_func(1.123);  //OK
    return 0;
}