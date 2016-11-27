#include <bits/stdc++.h>
using namespace std;
#define sPI 0.8584073464102067615373566167205
int main ()
{
	int test;
	scanf ("%d" , &test);
	int i;
	for (i = 1; i <= test; i++){
		double r;
		scanf ("%lf" , &r);
		printf ("Case %d: %.2lf\n" , i , r * r * sPI);
	}
}
