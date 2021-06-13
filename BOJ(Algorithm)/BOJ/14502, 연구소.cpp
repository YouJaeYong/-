#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

int main()

{
	int width, height = 0;



	cin >> height >> width;

	vector <vector<int>> map(height, vector<int>(width));
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			scanf("%d", &map[i][j]);


	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if(map[i][j]==0)

		}
	}
}