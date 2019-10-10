#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int count = 0;
	int space[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			space[i][j] = 101;
		}
	queue < pair< pair<int, int>, int> > position;
	queue < int > oilprice;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> space[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		position.push({ {0 , i}, 0 });
		oilprice.push(space[0][i]);
	}

	while (!position.empty()) {

		int size = position.size();
		
		if (count == N - 1)
			break;
		for (int i = 0; i < size; i++) {
			int top = oilprice.front();
			int path = position.front().second;
			int r = position.front().first.first;
			int c = position.front().first.second;
			position.pop();
			oilprice.pop();
			if (r + 1 < N && c - 1 >= 0 && path != 1)
			{
				position.push({ {r + 1, c - 1}, 1 });
				oilprice.push(space[r + 1][ c - 1] + top);
				
			}
			if (r + 1 < N && path != 2)
			{
				position.push({ { r + 1, c}, 2 });
				oilprice.push(space[r + 1][c] + top);
			}
			if (r + 1 < N && c + 1 < M && path != 3) {
				position.push({ { r + 1, c + 1}, 3 });
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