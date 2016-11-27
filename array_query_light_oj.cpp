#include <bits/stdc++.h>

using namespace std; 

const int N = 123; 
int arr[N] , brr[N * 3]; 
const int inf = (1<<28); 

void build (int n , int l , int r) {
	if (l == r) {
		brr[n] = arr[l]; 
		return ; 
	}
	int ll = n * 2; 
	int rr = ll + 1; 
	int mm = (l + r) / 2; 
	build (ll , l , mm); 
	build (rr , mm + 1 , r); 
	brr[n] = min (brr[ll] , brr[rr]); 
}

int get_min (int n , int l , int r , int i , int j) {
	if (l > j || r < i) return inf; 
	if (l >= i && r <= j) return brr[n]; 
	int ll = n * 2; 
	int rr = ll + 1; 
	int mm = (l + r) / 2;
	int a = get_min (ll , l , mm , i , j); 
	int b = get_min (rr , mm + 1 , r , i , j); 
	return min (a , b); 
}

int main () {
	int T; 
	scanf ("%d" , &T); 
	for (int t = 1; t <= T; t++) {
		int n , q; 
		scanf ("%d%d" , &n , &q); 
		for (int i = 1; i <= n; i++) 
			scanf ("%d" , arr + i);
		build (1 , 1 , n);  
		while (q--) {
			int a , b; 
			scanf ("%d%d" , &a , &b); 
			cout << get_min (1 , 1 , n , a , b) << endl;
		}
	}
}
