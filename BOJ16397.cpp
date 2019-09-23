#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

bool visited[100000] = { false, };

int A(int num) {
	num += 1;
	return num;
}

int B(int num) {
	num *= 2;
	int number = pow(10, int(log10(num)));

	num -= number;

	return num;
}


int main() {
	int N, T, G;
	cin >> N >> T >> G;

	queue< pair<int, int> > BFS;
	BFS.push({ N, 0 });
	visited[N] = true;

	while (!BFS.empty()) {
		int number = BFS.front().first;
		int cnt = BFS.front().second;
		BFS.pop();

		if (cnt > T) {
			cout << "ANG";
			return 0;
		}

		if (number == G) {
			cout << cnt;
			return 0;
		}

		

		if (number + 1 <= 99999 && !visited[A(number)]) {
			BFS.push({ A(number), cnt + 1 });
			visited[A(number)] = true;
		}
		if (number * 2 <= 99999 && !visited[B(number)]) {
			BFS.push({ B(number), cnt + 1 });
			visited[B(number)] = true;
		}

	}

	cout << "ANG";
	return 0;
}