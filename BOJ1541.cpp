#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main() {
	char a;
	int ans = 0;
	int ans2 = 0;
	bool firstminus = false;
	string question;
	string number;

	queue <int> numbers;
	queue <char> signs;

	queue <string> final;

	cin >> question;

	for (int i = 0; i < question.length(); i++) {
		if (question[i] - '0' >= 0 && question[i] - '9' <= 0) {
			number.push_back(question[i]);
		}
		else {
			if (question[i] == '-' && firstminus == false) {
				ans += stoi(number);
				number.clear();
				firstminus = true;
			}
			else if (firstminus == false) {
				ans += stoi(number);
				number.clear();
			}
			else {
				ans2 += stoi(number);
				number.clear();
			}
		}
	}
	ans2 += stoi(number);

	if (!firstminus)
		cout << ans + ans2;
	else
	cout << ans - ans2;
}
