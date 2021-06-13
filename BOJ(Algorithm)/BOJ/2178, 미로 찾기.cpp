//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//const static int DIR_X[4]={ -1,1,0,0 };
//const static int DIR_Y[4]={ 0,0,-1,1 };
//
//int main()
//{
//	int N=0, M = 0;
//	int k;
//	
//	
//	queue<pair<pair<int, int>,int>> bfs;
//
//
//	cin >> N >> M;
//	vector<vector<int>> map(N);
//	vector < vector<int>> visited(N);
//
//	int result = 1;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			scanf("%1d", &k);
//			map[i].emplace_back(k);
//			visited[i].emplace_back(0);
//		}
//	}
//
//
//	bfs.push(make_pair(make_pair(0, 0),1));
//	visited[0][0] = 1;
//
//	while (!bfs.empty())
//	{
//		
//		int currentX = bfs.front().first.first;
//		int currentY = bfs.front().first.second;
//		int result = bfs.front().second;
//		bfs.pop();
//	
//		
//		if (currentX == N-1 && currentY == M-1)
//		{
//			cout << result;
//			return 0;
//		}
//
//		result++;
//	
//		for (int i = 0; i < 4; ++i)
//		{
//			if (currentX + DIR_X[i] >= 0 && currentX + DIR_X[i] < N && currentY + DIR_Y[i] >= 0 && currentY + DIR_Y[i] < M)
//			{
//				if (map[currentX+ DIR_X[i]][currentY+ DIR_Y[i]]==1&&!visited[currentX + DIR_X[i]][currentY + DIR_Y[i]])
//				{
//					
//					bfs.push(make_pair(make_pair(currentX + DIR_X[i], currentY + DIR_Y[i]),result));
//					visited[currentX + DIR_X[i]][currentY + DIR_Y[i]] = 1;
//
//					
//				}
//			}
//		}
//	}
//
//	return 0;
//}