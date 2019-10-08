#include <iostream>
#include <vector>
using namespace std;

bool check[30][30];
int movx[4] = { 0, 0, 1, -1 };
int movy[4] = { 1, -1, 0 , 0 };
double result = 0;
double p[4];
int N;

void dfs(int x, int y, int n, double per) {

	if (check[x][y])
		return;
	
	if (n == N) {
		result += per;
		check[x][y] = false;
		return;
	}
	else {
		check[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (!check[x + movx[i]][y + movy[i]]) {
				dfs(x + movx[i], y + movy[i], n + 1, per*p[i]);
				check[x + movx[i]][y + movy[i]] = false;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++) {
		double pos;
		cin >> pos;
		p[i] = pos / 100;
	}
	dfs(15, 15, 0, 1);
	cout.precision(10);
	cout << result;
}