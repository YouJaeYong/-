//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//
//const int DIR_X[4] = { -1,1,0,0 };
//const int DIR_Y[4] = { 0,0,-1,1 };
//
//queue<pair<int, int>> q;
//int main()
//{
//
//
//
//	int N = 0;
//	int result = 0;
//	cin >> N;
//
//	vector<vector<char>> map(N, vector<char>(N, 0));
//	vector<vector<int>> visit_1(N, vector<int>(N, 0));
//
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> map[i][j];
//		}
//
//	}
//
//	for (int i = 0; i < N; ++i)
//		for (int j = 0; j < N; ++j)
//		{
//			if (!visit_1[i][j])
//			{
//				visit_1[i][j] = 1;
//
//				result++;
//
//				q.push(make_pair(i, j));
//
//				while (!q.empty())
//				{
//
//					int current_x = q.front().first;
//					int current_y = q.front().second;
//
//					q.pop();
//
//
//					for (int i = 0; i < 4; ++i)
//					{
//						if (current_x + DIR_X[i] < N && current_x + DIR_X[i] >= 0 && current_y + DIR_Y[i] < N && current_y + DIR_Y[i] >= 0)
//						{
//							if (!visit_1[current_x + DIR_X[i]][current_y + DIR_Y[i]])
//							{
//								if (map[current_x][current_y] == map[current_x + DIR_X[i]][current_y + DIR_Y[i]])
//								{
//									q.push(make_pair(current_x + DIR_X[i], current_y + DIR_Y[i]));
//									visit_1[current_x + DIR_X[i]][current_y + DIR_Y[i]] = 1;
//								}
//							}
//						}
//					}
//				}
//
//			}
//		}
//
//	cout << result<<" ";
//	result = 0;
//	for(int i=0; i<N; ++i)
//		for (int j = 0; j < N; ++j)
//		{
//			map[i][j] = (map[i][j]=='G')?'R': map[i][j];
//			visit_1[i][j] = 0;
//		}
//
//	for (int i = 0; i < N; ++i)
//		for (int j = 0; j < N; ++j)
//		{
//			if (!visit_1[i][j])
//			{
//				visit_1[i][j] = 1;
//
//				result++;
//
//				q.push(make_pair(i, j));
//
//				while (!q.empty())
//				{
//
//					int current_x = q.front().first;
//					int current_y = q.front().second;
//
//					q.pop();
//
//
//					for (int i = 0; i < 4; ++i)
//					{
//						if (current_x + DIR_X[i] < N && current_x + DIR_X[i] >= 0 && current_y + DIR_Y[i] < N && current_y + DIR_Y[i] >= 0)
//						{
//							if (!visit_1[current_x + DIR_X[i]][current_y + DIR_Y[i]])
//							{
//								if (map[current_x][current_y] == map[current_x + DIR_X[i]][current_y + DIR_Y[i]])
//								{
//									q.push(make_pair(current_x + DIR_X[i], current_y + DIR_Y[i]));
//									visit_1[current_x + DIR_X[i]][current_y + DIR_Y[i]] = 1;
//								}
//							}
//						}
//					}
//				}
//
//			}
//		}
//	cout << result;
//}
//
//
