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
#define sfl(x) scanf("%lld",&x)
#define pfl(x) printf("%lld\n",x)

template < typename T > T gcd (T a , T b){if (b == 0) return a;return gcd (b , a % b);}

struct point {
	int x , y , w;
	point () {}
	point (int x_ , int y_ , int w_) {
		x = x_;
		y = y_;
		w = w_;
	}
	bool operator < (const point &pp) const {
		return w < pp.w;
	}
};

vector < point > vv;
int ff[105];


int find__ (int u) {
    if (u != ff[u])
        ff[u] = find__ (ff[u]);
    return ff[u];
}

int MST (int n) {
	for (int i = 0; i <= n; i++) ff[i] = i;
	int tcost = 0 , cnt = 0;
	for (int i = 0; i < vv.size(); i++) {
		int tx = find__ (vv[i].x);
		int ty = find__ (vv[i].y);
		if (tx != ty) {
			ff[tx] = ty;
			tcost += vv[i].w;
			cnt++;
			if (cnt == n) break;
		}
	}
	return tcost;
}

int main () {
	int T; sf(T); int tt;
	for (tt = 1; tt <= T; tt++) {
		vv.clear();
		int n; sf(n);int a , b , c;
		while (scanf ("%d%d%d" , &a , &b , &c)) {
			if (!a && !b && !c) break;
			vv.push_back(point (a , b , c));
		}
		sort (vv.begin() , vv.end());
		printf ("Case %d: " , tt);
		int mn = MST (n);
		reverse (vv.begin() , vv.end());
		int mm = MST (n);
		int tc = mm + mn;
		if (tc % 2 == 0) pf(tc/2);
		else cout << tc << "/2" << endl;
	}
}
