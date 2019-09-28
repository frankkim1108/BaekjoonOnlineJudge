#include <iostream>
#include <vector>
using namespace std;
int a[9][9];
int b[9][9];
bool flag = false;
vector <pair<int, int> > vec;
vector <pair<int, int> > ve[9];
void func(int n)
{
	if (n == vec.size())
	{
		flag = true;
		return;
	}
	bool check[10];
	for (int i = 0; i < 10; i++)
		check[i] = true;
	for (int i = 0; i < 9; i++)
	{
		check[a[vec[n].first][i]] = false;
		check[a[i][vec[n].second]] = false;
	}
	for (int i = 0; i < 9; i++)
	{
		check[a[ve[b[vec[n].first][vec[n].second]][i].first][ve[b[vec[n].first][vec[n].second]][i].second]] = false;
	}
	for (int i = 1; i < 10; i++)
	{
		if (check[i])
		{
			a[vec[n].first][vec[n].second] = i;
			func(n + 1);
			if (flag)
				return;
			a[vec[n].first][vec[n].second] = 0;
		}
	}
}
int main()
{
	int c[9][9] = {
	   {0,0,0,1,1,1,2,2,2},
	   { 0,0,0,1,1,1,2,2,2 },
	   { 0,0,0,1,1,1,2,2,2 },
	   {3,3,3,4,4,4,5,5,5},
	   { 3,3,3,4,4,4,5,5,5 },
	   { 3,3,3,4,4,4,5,5,5 },
	   {6,6,6,7,7,7,8,8,8},
	   { 6,6,6,7,7,7,8,8,8 },
	   { 6,6,6,7,7,7,8,8,8 }
	};
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			b[i][j] = c[i][j];
			ve[b[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
				vec.push_back(make_pair(i, j));
		}
	}
	func(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}