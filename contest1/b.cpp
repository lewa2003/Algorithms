#include <iostream>
#include <vector>

int main ()
{
    int n, m;
    std::cin >> n >> m;
    std::vector <int> graf[n];

    for (int i=0; i<m; ++i){
        int a, b;
        std::cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    std::vector<char> part (n, -1);
    bool ok = true;
    std::vector<int> q (n);
    for (int st=0; st<n; ++st)
        if (part[st] == -1) {
            int h=0, t=0;
            q[t++] = st;
            part[st] = 0;
            while (h<t) {
                int v = q[h++];
                for (size_t i=0; i<graf[v].size(); ++i) {
                    int to = graf[v][i];
                    if (part[to] == -1)
                        part[to] = !part[v],  q[t++] = to;
                    else
                        ok &= part[to] != part[v];
                }
            }
        }
    if (ok)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
