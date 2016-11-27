/**
   Solution Description: 	Given n and m (make n the smaller #):
   if(n == 1)
   output m
   if(n == 2)
   output (m+3)/4 + (m+2)/4
   otherwise
   output ((n+1)/2)*((m+1)/2) + (n/2)*(m/2)
   http://www.questtosolve.com/browse.php?vol=6
**/
#include <bits/stdc++.h>
using namespace std;
int main (){
	int test;
	scanf ("%d" , &test);
	int n , m;
	int case_;
	for (case_ = 1; case_ <= test; case_++){
		scanf ("%d%d" , &n , &m);
		int ans;
		int x , y;
		x = n; y = m;
		////if (n = 2 && m == 3) ans = 4;
		if (n > m) swap (n , m);
		if (n == 1) ans = m;
		else if (n == 2) ans = ((m + 3) / 4 + (m + 2) / 4) * 2;
		else ans = ((n+1)/2)*((m+1)/2) + ((n/2)*(m/2));
		printf ("Case %d: %d\n" , case_ , ans);
	}
	return 0;
}
