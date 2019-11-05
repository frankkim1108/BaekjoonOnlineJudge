#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n, i;
	cin >> n;
	int a[10001];
	int res[10001];
	stack<int> s;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	s.push(0);
	for (i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]) {
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		res[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}