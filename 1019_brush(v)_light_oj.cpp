/**********ALLAH IS ALMIGHTY************/
 
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
 
using namespace std;

 
struct point {
    int x , w;
    point () {}
    point (int x_ , int w_) {
        x = x_; w = w_;
    }
    bool operator < (const point &p) const {
        return p.w < w;
    }
};
 
#define inf 100000
vector < int > G[104];
vector < int > cost[104];
priority_queue < point > Q;
int dist[104];
 
void gooo___ () {
    dist[1] = 0;
    Q.push(point (1 , 0));
    while (!Q.empty()) {
        int u = Q.top().x;
        for (int i = 0; i < G[u].size (); i++) {
            int v = G[u][i];
            if (dist[u] + cost[u][i] < dist[v]) {
                dist[v] = dist[u] + cost[u][i];
                Q.push(point (v , dist[v]));
            }
        }
        Q.pop();
    }
}
 
void clear__ () {
    for (int i = 0; i < 104; i++) {
        G[i].clear ();
        cost[i].clear ();
        dist[i] = inf;
    }
}
 
int main () {
    int T; scanf("%d" , &T);
    int t;
    for (int t = 1; t <= T; t++) {
        clear__ ();
        int n , e;
        scanf ("%d%d" , &n , &e);
        for (int i = 0 ; i < e; i++) {
            int u , v , w;
            scanf ("%d%d%d" , &u , &v , &w);
            G[u].push_back (v);
            G[v].push_back (u);
            cost[u].push_back (w);
            cost[v].push_back (w);
        }
        gooo___ ();
        printf ("Case %d: " , t);
        if (dist[n] == inf)
        puts("Impossible");
        else printf ("%d\n" , dist[n]);
    }
}


