#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int check[12], visit[12];
vector<string> words;
char A[102];
int N, com;;
long long dab;

void dfs(int d, int sum, string word)

{
	string ans = word;
	cout << d << endl;
	cout << bitset<32>(sum) << endl;
	cout << ans << endl;

	if (d == N - 1)
	{
		if (sum == com) dab++;
		return;
	}
	if (d + 1 < N)
	{
		dfs(d + 1, sum | check[d + 1], ans + " " + words[d+1]);
		dfs(d + 1, sum, ans + "");
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < 26; i++) com |= 1 << i;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		words.push_back(A);
		for (int j = 0; j < strlen(A); j++) {
			check[i] |= (1 << (A[j] - 'a'));
			
		}cout << bitset<32>(check[i]) << endl;
	}
	dfs(-1, 0, "");
	cout << dab << endl;
}