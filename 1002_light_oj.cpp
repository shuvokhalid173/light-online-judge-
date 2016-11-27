/****ALLAH IS ALMIGHTY****/

/**
    light online judge;
    problem name :: country roads;
    problem id   :: 1002;
    catagory     :: minimum_spanning_tree , union_find , dijkstra;
                    first run kruskal or similar mst algorithm to process input;
                    mst algorithm will remove cycle from the given graph;
                    then run dijkstra algorithm to find the maximum distance;
                    while running dijkstra algorithm just update the distance of each node;
    my solution............................
**/

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
#define sfl(x) scanf("%lld",&x)
#define pfl(x) printf("%lld\n",x)

struct point {
    int x , w;
    point () {}
    point (int x_ , int w_) {
        x = x_;
        w = w_;
    }
    bool operator < (const point &pp) const {
        return pp.w < w;
    }
};

struct edge {
    int x , y , z;
    edge () {}
    edge (int x_ , int y_ , int z_) {
        x = x_;
        y = y_;
        z = z_;
    }
    bool operator < (const edge &ed) const {
        return z < ed.z;
    }
};

const int N = 505;
const int inf = (1<<28);
priority_queue < point > Q;
vector < int > G[N];
int dd[N];
vector < int > cost[N];
int ff[N];
vector < edge > vp;

void dijkstra (int src) {
    Q.push (point (src , 0));
    dd[src] = 0;
    while (!Q.empty()) {
        int u = Q.top ().x;
        ///cout << u << endl;
        Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (dd[v] == -inf) {
                dd[v] = max (dd[u] , cost[u][i]);
                Q.push (point (v , dd[v]));
            }
        }
    }
}

void clear__ () {
    for (int i = 0; i < N; i++) {
        dd[i] = -inf;
        G[i].clear ();
        cost[i].clear ();
    }
    vp.clear ();
}

int find__ (int u) {
    if (u != ff[u])
        ff[u] = find__ (ff[u]);
    return ff[u];
}

void get_processing_input (int n) {
    for (int i = 0; i <= n; i++) ff[i] = i;
    sort (vp.begin() , vp.end());
    int cnt = 0;
    for (int i = 0; i < vp.size(); i++) {
        int u = find__ (vp[i].x);
        int v = find__ (vp[i].y);
        if (u != v) {
            ff[u] = v;
            G[vp[i].x].push_back (vp[i].y);
            G[vp[i].y].push_back (vp[i].x);
            cost[vp[i].x].push_back (vp[i].z);
            cost[vp[i].y].push_back (vp[i].z);
            cnt++;
            if (cnt == n - 1) break;
        }
    }
}

int main () {
    int T; sf(T); int tt;
    for (tt = 1; tt <= T; tt++) {
        clear__ ();
        int n , m; sf(n); sf(m);
        for (int i = 0; i < m; i++) {
            int a , b , c;
            sf(a); sf(b); sf(c);
            vp.push_back (edge (a , b , c));
        }
        get_processing_input (n);
        int t; sf(t);
        dijkstra (t);
        printf ("Case %d:\n" , tt);
        for (int i = 0; i < n; i++) {
            if (dd[i] != -inf) pf(dd[i]);
            else puts("Impossible");
        }
    }
}
