#include <iostream>
#include <vector>

const int MAXN = 1001;
std::vector<int> graf[MAXN];
bool used[MAXN];
int timer, enter[MAXN], low[MAXN];
int counter = 0;

void dfs (int v, int p = -1) {
	used[v] = true;
	enter[v] = low[v] = timer++;
	for (size_t i=0; i<graf[v].size(); ++i) {
		int to = graf[v][i];
		if (to == p)  continue;
		if (used[to])
			enter[v] = std::min (low[v], enter[to]);
		else {
			dfs (to, v);
			low[v] = std::min (low[v], low[to]);
			if (low[to] > enter[v])
				counter++;
		}
	}
}

void find_bridges(const int n) {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i=0; i<m; ++i){
        int a, b;
        std::cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    find_bridges (n);
    std::cout << counter;
    return 0;
}

