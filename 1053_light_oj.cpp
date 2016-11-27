#include <bits/stdc++.h>
using namespace std;
int main (){
	int t;
	scanf ("%d" , &t);
	int i;
	for (i = 1; i <= t; i++){
		long long a , b , c;
		scanf ("%lld%lld%lld" , &a , &b , &c);
		long long d;
		d = max (max (a , b) , c);
		if (a == b == c)
		printf ("Case %d: no\n" , i);
		else{
			if (d == a && a * a == b * b + c * c){
				printf ("Case %d: yes\n" , i);
			}
			else if (d == b && b * b == a * a + c * c){
				printf ("Case %d: yes\n" , i);
			}
			else if (d == c && c * c == a * a + b * b){
				printf ("Case %d: yes\n" , i);
			}
			else{
				printf ("Case %d: no\n" , i);
			}
		}
	}
}
