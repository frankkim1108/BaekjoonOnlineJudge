#include <iostream>
#include <algorithm>
using namespace std;

int space[1002][1002][4];

int main()
{
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			space[i][j][0] = space[i][j][1] = space[i][j][2] = space[i][j][3] = 987654321;
		}
	}
	int r, c; cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			int num;
			cin >> num;
			space[i][j][3] = num;
			space[i][j][1] = num;
			space[i][j][2] = num;
			space[i][j][0] = num;
		}
	}

	for (int i = r-1; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			int num3 = min(space[i + 1][j - 1][1], space[i + 1][j - 1][2]);
			int num2 = min(space[i + 1][j][1], space[i + 1][j][3]);
			int num1 = min(space[i + 1][j + 1][3], space[i + 1][j + 1][2]);
				space[i][j][1] += num1;
				space[i][j][2] += num2;
				space[i][j][3] += num3;
		}
	}
	int small = 987654321;
	for (int i = 1; i <= c; i++) {
		if (small > min(min(space[1][i][1], space[1][i][2]), space[1][i][3]))
			small = min(min(space[1][i][1], space[1][i][2]), space[1][i][3]);
	}

	cout << small;
}