#include <iostream>
#include <queue>
using namespace std;
#define max 100001

bool grid[100001];

int moveup(int n) {
	return n + 1;
}

int movedown(int n) {
	return n - 1;
}

int teleport(int n) {
	return n * 2;
}

int main() {
	int count = 0;
	
	int N, K;
	int time = 0;
	int found = 0;
	cin >> N >> K;

	queue <pair<int, int> > place;
	place.push({ N,0 });

	while (!place.empty()) {
		if (found)
			break;

		time++;

		int size = place.size();

		for (int i = 0; i < size; i++) {
			int top = place.front().first;
			int dept = place.front().second;
			place.pop();

			if (top == K) {
				found++;
				if (time > dept)
					time = dept;
				continue;
			}

			grid[top] = true;

			if (moveup(top) < max && grid[moveup(top)] == false) {
				place.push({ moveup(top), dept + 1 });
			}
			if (movedown(top) >= 0 && grid[movedown(top)] == false) {
				place.push({ movedown(top), dept + 1 });
			}
			if (teleport(top) < max && grid[teleport(top)] == false) {
				place.push({ teleport(top), dept + 1 });
			}

		}
	}

	cout << time << "\n" << found << "\n";
	
}