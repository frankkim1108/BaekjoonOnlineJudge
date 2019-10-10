#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	pair<int, int> space[1000][1002];
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1002; j++) {
			space[i][j] = { 101, 0 };
		}
	}
	int r, c; cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 1; j <= c; j++) {
			int num; cin >> num;
			space[i][j] = { num, 0 };
		}
	}

	for (int i = 1; i < r; i++) {
		for (int j = 1; j <= c; j++) {
			int path = 0;
			pair<int, int> current = space[i][j];
			pair<int, int> n1 = space[i - 1][j - 1];
			pair<int, int> n2 = space[i - 1][j];
			pair<int, int> n3 = space[i - 1][j + 1];

			
			int num1 = 101, num2 = 101, num3 = 101;
			if (n1.second != 3) {
				num1 = n1.first;
			}
			if (n2.second != 2) {
				num2 = n2.first;
			}
			if (n3.second != 1) {
				num3 = n3.first;
			}
			int smallest = min(min(num1,num2),num3);
			if (smallest == num1)
				path = 3;
			else if (smallest == num2)
				path = 2;
			else
				path = 1;

			space[i][j] = { current.first + smallest, path };
		}
	}

	for (int i = 1; i <= c; i++) {
		cout << space[r-1][i].first << " ";
	}

	return 0;
}