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
#define inf 1000000
vector  < int > G[105];
bool visited[105];
int level[105];
int levell[105];
queue < int > Q;
 
int gooo (int s , int d , int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        level[i] = 0;
    }
    level[s] = 0;
    Q.push(s);
    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (!visited[v]) {
                level[v] = level[u] + 1;
                Q.push(v);
                visited[v] = true;
            }
        }
        Q.pop();
    }
   
    int max__ = 0;
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            levell[i] = 0;
            visited[i] = false;
        }
        levell[i] = level[i];
        Q.push(i);
        visited[i] = true;
        while (!Q.empty()) {
            int u = Q.front();
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if (!visited[v]) {
                    visited[v] = 1;
                    Q.push(v);
                    levell[v] = levell[u] + 1;
                }
            }
            Q.pop();
        }
        max__ = max (max__ , levell[d]);
    }
    return max__;
}
 
int main () {
    int T; scanf ("%d" , &T);
    int t;
    for (t = 1; t <= T; t++) {
        int n , e;
        scanf ("%d%d" , &n , &e);
        for (int i = 0; i < n; i++)
            G[i].clear ();
        for (int i = 0; i < e; i++) {
            int u , v;
            scanf ("%d%d" , &u , &v);
            G[u].push_back (v);
            G[v].push_back (u);
        }
        int s , d;
        scanf ("%d%d" , &s , &d);
        printf ("Case %d: %d\n" , t , gooo (s , d , n));
    }
}

