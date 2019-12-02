#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	
	while (1)
	{
		string sentence;
		getline(cin, sentence);
		if (sentence == ".")
			break;
		bool flag = false;
		stack<char> par;
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] == '(')
			{
				par.push('(');
			}
			else if (sentence[i] == ')') {
				if (par.empty() || par.top() != '(') {
					flag = true;
					break;
				}
				else
					par.pop();
			}
			else if (sentence[i] == '[')
			{
				par.push('[');
			}
			else if (sentence[i] == ']')
			{
				if (par.empty() || par.top() != '[') {
					flag = true;
					break;
				}
				else
					par.pop();
			}
			else continue;
		}
		if (flag == true) {
			cout << "no" << "\n";
			continue;
		}
		if (par.empty()) {
			cout << "yes" << "\n";
			continue;
		}
		else
			cout << "no" << "\n";
	}
}