#include<iostream>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int par, chi;
	int case_num = 1;
	while (cin >> par >> chi) {
		map<long long int, int> inner;
		bool is_tree = true;
		int inner_zero_count = 0;
		if (par == -1 && chi == -1) break;
		while (par && chi) {
			inner[par];
			++inner[chi];
			cin >> par >> chi;
		}
		for (auto i : inner) {
			if (i.second > 1) is_tree = false;
			if (!i.second) inner_zero_count++;
		}
		if (inner_zero_count != 1 && !inner.empty()) is_tree = false;
		if (is_tree) {
			cout << "Case " << case_num << " is a tree.\n";
		}
		else {
			cout << "Case " << case_num << " is not a tree.\n";
		}
		case_num++;
	}
}