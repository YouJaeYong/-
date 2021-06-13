//#include<iostream>
//
//
//using namespace std;
//
//int main()
//{
//	int n;
//
//	cin >> n;
//
//
//	int target = 1000 - n;
//
//	int* changeList = new int[6]{ 500,100,50,10,5,1 };
//	int listIndex = 0;
//	int result = 0;
//	while (target != 0)
//	{
//		if (listIndex > 5)
//			return 0;
//		result+=target / changeList[listIndex];
//		target = target % changeList[listIndex];
//		listIndex++;
//	}
//	cout << result;
//	return 0;
//}