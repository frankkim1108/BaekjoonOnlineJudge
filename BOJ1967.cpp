#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

vector< pair<int,int> > graph[10001];
bool visited[10001];

int x = 0;
int farpoint = 0;
void dfs(int start, int distance) {
	if (visited[start] == true)
		return;
	else
	visited[start] = true;

	if (x < distance) {
		x = distance;
		farpoint = start;
	}

	for (int i = 0; i < graph[start].size(); i++) {
			dfs(graph[start][i].first, graph[start][i].second + distance);
		}
			
}

int main() {

	int max = 0;
	int n;
	cin >> n;
	
	

	for (int i = 1; i < n; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		graph[from].push_back(make_pair(to,dist));
		graph[to].push_back(make_pair(from, dist));
	}

	dfs(1, 0);
	for (int i = 0; i < 10001; i++) {
		visited[i] = 0;
	}
	x = 0;
	dfs(farpoint, x);
	
	cout << x;
}