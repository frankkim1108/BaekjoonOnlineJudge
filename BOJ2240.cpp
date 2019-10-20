#include <iostream>
#include <algorithm>
using namespace std;

int tree[1001];
int plum[1001][31];

int main()
{
	int T, W;
	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> tree[i];
	}

	for (int i = 1; i <= T; i++) {
		for (int j = W; j >= 0; j--) {

			if (tree[i] % 2 == 1) {
				if (j % 2 == 0) {
					plum[i][j] = max(plum[i - 1][j], plum[i - 1][j + 1]) + 1;
				}
				else {
					plum[i][j] = max(plum[i - 1][j], plum[i - 1][j + 1]);
				}

			}
			else {

				if (j % 2 == 0) {
					plum[i][j] = max(plum[i - 1][j], plum[i - 1][j + 1]);
				}
				else {
					plum[i][j] = max(plum[i - 1][j], plum[i - 1][j + 1]) + 1;
				}
			}
		}
	}


	int ans = 0;
	for (int i = 0; i <= W; i++) {
		ans = max(ans, plum[T][i]);
	}
	cout << ans;
}