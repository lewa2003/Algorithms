#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 2000000;

int us[maxN];
vector<int> go[maxN];

void no() {
	cout << "NO\n";
	exit(0);
}

void dfs(int x, int l) {
	if (l % 2 == 0)
		us[x] = 2;
	else
		us[x] = 1;

	for (int i = 0; i < go[x].size(); i++) {
		int y = go[x][i];
		if (us[y] == 0)
			dfs(y, l + 1);
		else
			if (us[y] == us[x])
				no();
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		go[x].pb(y);
		go[y].pb(x);
	}

	for (int i = 1; i <= n; i++)
		if (us[i] == 0)
			dfs(i, 1);

	cout << "YES\n";
	
	return 0;
}