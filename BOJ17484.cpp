#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



int main()
{
	int count = 0;
	int space[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			space[i][j] = 101;
		}
	queue < pair< pair<int, int>, int> > oil;
	queue < int > oilprice;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> space[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		oil.push({ {0 , i}, 0 });
		oilprice.push(space[0][i]);
	}

	while (!oil.empty()) {

		int size = oil.size();
		
		if (count == N - 1)
			break;
		for (int i = 0; i < size; i++) {
			int top = oilprice.front();
			int path = oil.front().second;
			int r = oil.front().first.first;
			int c = oil.front().first.second;
			oil.pop();
			oilprice.pop();
			if (r + 1 < N && c - 1 >= 0 && path != 1)
			{
				oil.push({ {r + 1, c - 1}, 1 });
				oilprice.push(space[r + 1][ c - 1] + top);
				
			}
			if (r + 1 < N && path != 2)
			{
				oil.push({ { r + 1, c}, 2 });
				oilprice.push(space[r + 1][c] + top);
			}
			if (r + 1 < N && c + 1 < M && path != 3) {
				oil.push({ { r + 1, c + 1}, 3 });
				oilprice.push(space[r + 1][c + 1] +top);
			}
		}
		count++;
	}

	int size = oilprice.front();
	int min = 987654321;
	while (!oilprice.empty()) {
		if (min > oilprice.front()) {
			min = oilprice.front();
			
		}
		oilprice.pop();
	}
	cout << min;
}