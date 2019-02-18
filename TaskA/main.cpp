#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


const int maxN = 2000;

int s[maxN], up[maxN];
vector<pii> go[maxN];
int tim, ans;

void dfs(int x, int num) {
	tim++;
	s[x] = tim;
	up[x] = tim;

	for (int i = 0; i < go[x].size(); i++) {
		pii y = go[x][i];
		if (s[y.f] == 0) {
			dfs(y.f, y.s);
			up[x] = min(up[x], up[y.f]);
		}
		else
			if (y.s != num)
				up[x] = min(up[x], s[y.f]);
	}

	for (int i = 0; i < go[x].size(); i++) {
		pii y = go[x][i];
		if (y.s != num && up[y.f] > s[x])
			ans++;
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x++; y++;
		go[x].pb(mp(y, i));
		go[y].pb(mp(x, i));
	}

	for (int i = 1; i <= n; i++)
		if (s[i] == 0)
			dfs(i, -1);

	cout << ans << endl;
	
	return 0;
}