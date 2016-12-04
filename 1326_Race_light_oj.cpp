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
 
const int N = 1002;
const int mod = 10056;
int dp[N][N];
int dpp[N][N];
int save[N];
 
int main () {
    dp[0][0] = 1; dpp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][1] = i;
        dp[i][i] = 1;
        dp[i][0] = 1;
        dpp[i][0] = 0;
    }
    save[0] = 1;
    for (int i = 1; i < N; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod;
            dp[i][j] %= mod;
            sum += (dp[i][j] * save[i - j]) % mod;
        }
        save[i] = sum % mod;
    }
    int T; scanf ("%d" , &T);
    int t;
    for (t = 1; t <= T; t++) {
        int n; scanf ("%d" , &n);
        printf ("Case %d: %d\n" , t , (save[n] + mod) % mod);
    }
}
///http://codeforces.com/contest/118/problem/D
