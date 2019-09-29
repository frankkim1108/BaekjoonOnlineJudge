#include <iostream>
#include <vector>
using namespace std;

vector <int> in[5000];
vector <int> nodes;


bool firstrule() {
	int count = 0;
	for (int i = 0; i < nodes.size(); i++) {
		if (in[nodes[i]].size() == 0)
			count++;
	}
	if (count == 1)
		return true;
	else return false;
}
bool secondrule() {
	for (int i = 0; i < nodes.size(); i++) {
		if (in[nodes[i]].size() >= 2)
			return false;
		else continue;
	}
	return true;
}

int main()
{
	int i = 1;

	while (1) {
		bool flag[5000] = { false, };
		while (1) {
			int start;
			int end;
			cin >> start >> end;
			if (start == -1 && end == -1) {
				return 0;
			}
			else if (start != 0 || end != 0) {
				in[end].push_back(start);
				if (!flag[start]) {
					nodes.push_back(start);
					flag[start] = true;
				}
				if (!flag[end]) {
					nodes.push_back(end);
					flag[end] = true;
				}
			}
			else {
				if (firstrule() && secondrule()) {
					cout << "Case " << i << " is a tree.\n";
					break;
				}

				else {
					cout << "Case " << i << " is not a tree.\n";
					break;
				}
			}
		}
		i++;
		for (int i = 0; i < 5000; i++) {
			in[i].clear();
		}
		nodes.clear();
		
	}
}