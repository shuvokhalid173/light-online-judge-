#include <bits/stdc++.h>

using namespace std; 

typedef long long sll; 
const int N = 1234; 
sll dp[N][N]; 
string ss; 

sll gooo (sll i , sll j) {
	if (i > j) return 0; 
	if (dp[i][j] != -1) 
		return dp[i][j]; 
	if (ss[i] == ss[j]) 
		gooo (i + 1 , j - 1); 
	else {
		return dp[i][j] = 1 + min (gooo (i + 1 , j) , gooo (i , j - 1));
    }
}

int main () {
	sll T; 
	cin >> T; 
	for (sll tt = 1; tt <= T; tt++) {
		memset (dp , -1 , sizeof (dp)); 
		cin >> ss; 
		printf ("Case %lld: %lld\n" , tt , gooo (0 , ss.size() - 1));
		ss.clear(); 
	}
}
