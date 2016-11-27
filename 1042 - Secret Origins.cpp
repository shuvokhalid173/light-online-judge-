#include <bits/stdc++.h>
using namespace std;
typedef long long sll;
sll call (sll n);
int main ()
{
    int T;
    scanf ("%d" , &T);
    int i;
    for (i = 1; i <= T; i++){
        sll N;
        scanf ("%lld" , &N);
        sll temp = call (N);
        while (N++){
            if (temp == call (N)){
                break;
            }
        }
        printf ("Case %d: %lld\n" , i , N);
    }
}
sll call (sll n)
{
    sll counter = 0;
    for (sll i = 1; i <= n; i *= 2){
        if (n&i){
            counter++;
        }
    }
    return counter;
}
