#include <iostream>
#include <iomanip>
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
 
#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
 
 
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
 
 
#define ssdli(x) scanf("%lld",&x)
#define spdli(x) printf("%lld\n",x);
#define sdii(x,y) scanf("%d%d",&x,&y)
#define SDs(x) scanf("%s",x)
#define uu first
#define vv second
 
using namespace std;
#define limit 10002
long long  dp[limit];
long long n;
long long coin[limit];
long long coin_change (long long taka){
	long long i , j;
	dp[0] = 1;
	for (i = 0; i < n; i++){
		for (j = coin[i]; j <= taka; j++){
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	return dp[taka];
}
int main(){
	
	long long i;
	for (i = 1; i <= 21; i++)
	coin[i - 1] = i * i * i;
	n = 21;
	long long taka;
	while (ssdli (taka)!=EOF){
	    memset (dp , 0 , sizeof (dp));
		spdli (coin_change  (taka));
	}
}
