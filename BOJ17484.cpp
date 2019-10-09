#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



int main()
{
	int count = 1;
	int space[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			space[i][j] = 101;
		}
	queue <pair<int, int> > oil;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> space[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		oil.push({ space[0][i], 0 });
	}

	while (!oil.empty()) {
		int size = oil.size();

		for (int i = 0; i < size; i++) {
			int top = oil.front().first;
			int path = oil.front().second;

			if(space)
		}
	}
}