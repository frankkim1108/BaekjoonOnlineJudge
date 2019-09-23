#include <iostream>
using namespace std;

int main() {
	int fibo[] = { 0, 1 };

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fibo[i%2] = fibo[0] + fibo[1];
	}

	cout << fibo[n%2];
}