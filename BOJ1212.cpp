#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

stack<int> ans;


void octtobi(char a) {

	int num = a - '0';
	for (int i = 0; i < 3; i++) {
		ans.push(num % 2);
		num /= 2;
	}
}

int main() {

	vector<int> answer;

	string octnum;
	cin >> octnum;

	for (int i = octnum.length() -1; i >=0; i--) {
		octtobi(octnum[i]);
	}

	while (1) {
		if (ans.size() != 0) {
			if (ans.top() == 0)
				ans.pop();
			else break;
		}
		else break;
	}

	unsigned int size = ans.size();

	if (size != 0) {
		for (int i = 0; i < size; i++) {
			answer.push_back(ans.top());
			ans.pop();
		}

		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i];
		}
	}
	
	else cout << 0;





}