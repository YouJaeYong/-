//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//
//	int n = 0;//���� ����
//	int result = 0; //���� ����
//	int target = 0;//��ǥ �ݾ�
//	int *coinValue;
//	cin >> n >> target;
//
//	coinValue = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> coinValue[i];
//	}
//
//	
//	for (int i = n-1; i >= 0; --i)
//	{
//		if (coinValue[i] <= target)
//		{
//			int currentResult= target / coinValue[i];//�� ������ ���
//			result += currentResult;
//			target -= currentResult * coinValue[i];
//			if (target == 0)
//			{
//				cout << result;
//				break;
//			}
//		}
//			
//	}
//
//	return 0;
//}

