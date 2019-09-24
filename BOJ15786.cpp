#include <string>
#include <iostream>
using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		bool c = false;
		for (int j = 0, idx = 0; x[j]; j++) {
			if (x[j] == s[idx]) idx++;
			if (idx == n) {
				c = true;
				break;
			}
		}
		if (c) cout << "true\n";
		else cout << "false\n";
	}
}