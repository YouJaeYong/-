//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//vector<vector<int>> map;
//int** visited;
//
//const int DIR_X[4] = { 0,0,-1,1 };
//const int DIR_Y[4] = { -1,1,0,0 };
//int N;
//
//int bfs(int x, int y, int count);
//int main()
//{
//	cin >> N;
//
//	int n;
//	for (int i = 0; i < N; ++i)
//	{
//		vector<int> v;
//
//		for (int j = 0; j < N; ++j)
//		{
//			scanf("%1d", &n);
//			v.emplace_back(n);
//		}
//
//		map.emplace_back(v);
//	}
//	int count = 0;
//
//	visited = new int*[N];
//
//	for (int i = 0; i < N; ++i)
//		visited[i] = new int[N] {0, };
//
//
//
//
//	vector<int> houseCount;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//
//			if (map[i][j] == 1&&!visited[i][j])
//			{
//				count++;
//				houseCount.emplace_back(bfs(i, j, count));
//				
//			}
//		}
//	}
//
//	cout << count << endl;
//
//	sort(houseCount.begin(), houseCount.end());
//	for (int i=0;i<houseCount.size();++i)
//	{
//		cout << houseCount[i]+1;
//		if (i != houseCount.size() - 1)
//			cout << endl;
//	}
//
//	return 0;
//}
//
//int bfs(int posX, int posY,int count)
//{
//
//	queue<pair<int, int>> m_queue;
//
//	m_queue.push(make_pair(posX, posY));
//	int houseCount = 0;
//	visited[posX][posY] = count;
//	while (!m_queue.empty())
//	{
//
//		int currentX = m_queue.front().first;
//		int currentY = m_queue.front().second;
//		
//		m_queue.pop();
//		
//		for (int i = 0; i < 4; ++i)
//		{
//			if (currentX +DIR_X[i] >= 0 && currentX + DIR_X[i] < N && currentY + DIR_Y[i] >= 0 && currentY + DIR_Y[i] < N)
//			{
//				
//				if (map[currentX + DIR_X[i]][currentY + DIR_Y[i]] == 1&&!visited[currentX + DIR_X[i]][currentY + DIR_Y[i]])
//				{
//					m_queue.push(make_pair(currentX + DIR_X[i], currentY + DIR_Y[i]));
//					visited[currentX + DIR_X[i]][currentY + DIR_Y[i]] = count;
//					houseCount++;
//				}
//			}
//
//		}
//	}
//
//	return houseCount;
//}