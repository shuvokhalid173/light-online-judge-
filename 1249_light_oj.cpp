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

struct cls_ {
    string ss;
    int x;
    cls_ () {}
    cls_ (string ss_ , int x_) {
        ss = ss_;
        x = x_;
    }
    bool operator < (const cls_ &pp) const {
        return x < pp.x;
    }
};

string sst;
vector < cls_ > vv;

int main () {
    int T; sf(T); int tt;
    for (tt = 1; tt <= T; tt++) {
        vv.clear();
        int n; sf(n); int sz = n - 1;
        while (n--) {
            cin >> sst;
            int a , b , c;
            sf(a); sf(b); sf(c);
            vv.push_back (cls_ (sst , a * b * c));
            sst.clear();
        }
        sort (vv.begin() , vv.end());
        printf ("Case %d: " , tt);
        if (vv[0].x == vv[sz].x) puts("no thief");
        else cout << vv[sz].ss << " took chocolate from " << vv[0].ss << endl;
    }
}
