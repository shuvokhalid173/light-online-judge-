/**********ALLAH IS ALMIGHTY************/
 
#include <stdio.h>
///#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <fstream>
#include <utility>
#include <cassert>
#include <ctime>
#include <climits>
#include <functional>
#include <numeric>
#include <memory.h>
 
using namespace std;
 
typedef long long sll;
#define FALSE ios_base::sync_with_stdio(0)
#define TIE cin.tie()
#define TIEE cout.tie()
#define pii pair<int,int>
#define mp_ make_pair
 
const int N = 100003;
int arr[N];
int tree[3 * N];
 
void build (int n , int st , int en) {
    if (st == en) {
        tree[n] = arr[st];
        return ;
    }
    int left = n * 2;
    int right = left + 1;
    int mid = (st + en) / 2;
    build (left , st , mid);
    build (right , mid + 1 , en);
    tree[n] = tree[left] + tree[right];
}
 
int query (int n , int st , int en , int x , int y) {
    if (st > y || en < x) return 0;
    if (st >= x && en <= y) return tree[n];
    int left = n * 2;
    int right = left + 1;
    int mid = (st + en) / 2;
    int pp1 = query (left , st , mid , x , y);
    int pp2 = query (right , mid + 1 , en , x , y);
    return pp1 + pp2;
}
 
void update (int n , int st , int en , int ind , int val) {
    if (ind > en || ind < st) return ;
    if (st >= ind && en <= ind) {
        tree[n] = val;
        return ;
    }
    int left = n * 2;
    int right = left + 1;
    int mid = (st + en) / 2;
    update (left , st , mid , ind , val);
    update (right , mid + 1 , en , ind , val);
    tree[n] = tree[left] + tree[right];
}
 
void go_to_one (int n) {
    int x;  
    scanf ("%d" , &x);
    printf ("%d\n" , arr[x + 1]);
    update (1 , 1 , n , x + 1 , 0);
    arr[x + 1] = 0;
}
 
void go_to_two (int n) {
    int x , y;
    scanf ("%d%d" , &x , &y);
    arr[x + 1] += y;
    update (1 , 1 , n , x + 1 , arr[x + 1]);
}
 
void go_to_three (int n) {
    int x , y;
    scanf ("%d%d" , &x , &y);
    int ans = query (1 , 1 , n , x + 1 , y + 1);
    printf ("%d\n" , ans);
}
 
int main () {
    int T;
    scanf ("%d" , &T);
    for (int cs = 1; cs <= T; cs++) {
        int n , m;
        scanf ("%d%d" , &n , &m);
        for (int i = 1; i <= n; i++)
            scanf ("%d" , &arr[i]);
        build (1 , 1 , n);
        printf ("Case %d:\n" , cs);
        for (int i = 1; i <= m; i++) {
            int ch;
            scanf ("%d" , &ch);
            if (ch == 1) go_to_one (n);
            else if (ch == 2) go_to_two (n);
            else go_to_three (n);
        }  
    }
}
