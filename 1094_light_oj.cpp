/****ALLAH IS ALMIGHTY****/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
typedef long long sll;
#define sfl(x) scanf ("%lld",&x)
#define pfl(x) printf("%lld\n",x)

struct edge {
    int u , w;
    edge () {}
    edge (int u_ , int w_) {
        u = u_;
        w = w_;
    }
    bool operator < (const edge &pp) const {
        return pp.w < w;
    }
};

const int N = 30000 + 5;
vector < int > G[N];
priority_queue < edge > Q;
int dd[N];
vector < int > cost[N];
const int inf = (1<<28);

void dijkstra (int src) {
    for (int i = 0; i < N; i++)
        dd[i] = inf;
    dd[src] = 0;
    Q.push (edge (src , 0));
    while (!Q.empty()) {
        int u = Q.top().u;
        Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (dd[u] + cost[u][i] < dd[v]) {
                dd[v] = dd[u] + cost[u][i];
                Q.push(edge (v , dd[v]));
            }
        }
    }
}

void clear__ (){
    for (int i = 0; i < N; i++) {
        G[i].clear ();
        cost[i].clear ();
    }
}
int main () {
    int T; sf(T); int tt;
    for (tt = 1; tt <= T; tt++) {
        clear__ ();
        int n; sf(n);
        for (int i = 1; i < n; i++) {
            int x , y , z;
            sf(x); sf(y); sf(z);
            G[x].push_back (y);
            G[y].push_back (x);
            cost[x].push_back (z);
            cost[y].push_back (z);
        }
        int mx = -inf;
        for (int i = 0; i < n; i++) {
            dijkstra (i);
            int mm = -inf;
            for (int j = 0; j < n; j++)
                mm = max (mm , dd[j]);
            mx = max (mx , mm);
        }
        printf ("Case %d: %d\n" , tt , mx);
    }
}
