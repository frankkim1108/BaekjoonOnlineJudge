#include <iostream>
using namespace std;
int paper[129][129];
int b = 0;
int w = 0;
void check(int n, int startx, int starty) {
	int color = paper[startx][starty];
	for (int i = startx; i < startx + n; i++) {
		for (int j = starty; j < starty + n; j++) {
			if (paper[i][j] != color) {
				check(n / 2, startx, starty);
				check(n / 2, startx + n / 2, starty);
				check(n / 2, startx, starty + n / 2);
				check(n / 2, startx + n / 2, starty + n / 2);
				return;
			}
		}
	}
	if (color == 1)
		b++;
	else w++;
}

int main()
{
	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> paper[i][j];
		}
	}
	check(N , 1, 1);
	cout << w << "\n" << b;
}