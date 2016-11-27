#include <bits/stdc++.h>

using namespace std; 

struct bits_ {
	int Set (int n , int pos) {return n = n | (1<<pos);}
	int Reset (int n , int pos) {return n = n & ~ (1<<pos);}
	bool check (int n , int pos) {return (bool) (n & (1<<pos));}
}bit;

int dp[1<<16][16]; 
int arr[16][16]; 
int n;

int gooo (int mask , int ind) {
	if (mask == (1<<n) - 1 || ind == n) 
		return 0; 
	if (dp[mask][ind] != -1) 
		return dp[mask][ind];
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		if (!bit.check(mask , i)) {
			ret = max (ret , arr[ind][i] + gooo (bit.Set(mask , i) , ind + 1));
		}
	}
	return dp[mask][ind] = ret;
}

int main () {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset (dp , -1 , sizeof (dp)); 
	cout << gooo (0 , 0) << endl;
}
