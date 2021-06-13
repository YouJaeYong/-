//#include<iostream>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<algorithm>
//#include<memory.h>
//using namespace std;
//
//int main()
//{
//
//	int n = 0;//정점의 갯수
//	int m = 0;// 간선의 갯수
//	int startPos = 0;
//
//	cin >> n >> m >> startPos;
//
//
//	
//	vector<vector<int>> arr(n,vector<int>(n));
//
//	arr.reserve(n);
//	for (int i = 0; i < m; ++i)
//	{
//		int start, dest = 0;
//		cin >> start >> dest;
//
//		arr[start - 1][dest - 1] = 1;
//		arr[dest-1][start-1] = 1;
//	}
//
//
//	stack<int> dfs;
//
//	dfs.push(startPos);
//	bool* checkFootStep = new bool[n] {false, };
//	while (!dfs.empty())
//	{
//
//		int currentPos = dfs.top();
//		dfs.pop();
//
//
//		
//		currentPos--;//인덱스값으로 보간
//		if (checkFootStep[currentPos])
//			continue;
//		else
//		checkFootStep[currentPos] = true;
//
//		cout << currentPos+1 << " ";
//		vector<int> saved_next;
//
//		for (int i = 0; i < n; ++i)
//		{
//
//			if (arr[currentPos][i] == 1 && !checkFootStep[i])
//			{
//				saved_next.emplace_back(i + 1);
//			}
//
//		}
//
//		sort(saved_next.begin(),saved_next.end(),greater<int>());
//		
//		for(int i=0; i< saved_next.size(); ++i)
//			dfs.push(saved_next[i]);
//	}
//
//	cout << endl;
//	memset(checkFootStep, 0, sizeof(bool)*n);
//	queue<int> bfs;
//	bfs.push(startPos);
//	checkFootStep[startPos-1] = true;
//
//
//	while (!bfs.empty())
//	{
//		int currentPos = bfs.front();
//		bfs.pop();
//
//		cout << currentPos << " ";
//
//		currentPos--;//배열 인덱스로 보간
//
//		
//
//		for (int i = 0; i < n; ++i)
//		{
//			if (arr[currentPos][i] == 1 && !checkFootStep[i])
//			{
//				bfs.push(i+1);//+1은 정점의 값으로 보간(1~n)
//				checkFootStep[i] = true;
//				break;
//			}
//		}
//	}
//
//
//	return 0;
//}