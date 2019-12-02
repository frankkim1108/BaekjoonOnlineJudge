#include <iostream>
#include <algorithm>
using namespace std;
int max_last[3] = { 0, };
int min_last[3] = { 0, };
int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int current[3] = { 0, };
		for (int j = 0; j < 3; j++) {
			cin >> current[j];
		}
		int max_added[3][3] = { 0, };
		int min_added[3][3] = { 0, };
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == 0) {
					if (k == 0)
						continue;
					else {
						max_added[k][j] += (current[j] + max_last[k - 1 + j]);
					}
				}
				else if (j == 2) {
					if (k == 2)
						continue;
					else {
						max_added[k][j] += (current[j] + max_last[k - 1 + j]);
					}
				}
				else {
					max_added[k][j] += (current[j] + max_last[k - 1 + j]);
				}

			}
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == 0) {
					if (k == 0)
						continue;
					else {
						min_added[k][j] += (current[j] + min_last[k - 1 + j]);
					}
				}
				else if (j == 2) {
					if (k == 2)
						continue;
					else {
						min_added[k][j] += (current[j] + min_last[k - 1 + j]);
					}
				}
				else {
					min_added[k][j] += (current[j] + min_last[k - 1 + j]);
				}
			}
		}
		for (int j = 0; j < 3; j++) {
			int max = 0;
			int min = 987654321;
			for (int k = 0; k < 3; k++) {
				if (max <= max_added[k][j])
					max = max_added[k][j];
				if (j == 0) {
					if (k == 0)
						continue;
					else if (min >= min_added[k][j])
						min = min_added[k][j];

				}
				if (j == 2) {
					if (k == 2)
						continue;
					else if (min >= min_added[k][j])
						min = min_added[k][j];
				}
				else {
					if (min >= min_added[k][j])
						min = min_added[k][j];
				}
			}
			max_last[j] = max;
			min_last[j] = min;
		}
	}
	cout << max(max(max_last[0], max_last[1]), max_last[2]) << " " << min(min(min_last[0], min_last[1]), min_last[2]);
}