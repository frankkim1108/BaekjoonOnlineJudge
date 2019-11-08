#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> V;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		V.push_back(num);
	}
	int size = V.size();
	for (int i = 0; i < size; i++) {
		cout << V[i];
	}
}