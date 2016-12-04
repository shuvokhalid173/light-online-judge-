**********ALLAH IS ALMIGHTY************/
 
#include <stdio.h>
/// #include <conio.h> it causes compilation error
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
#define mp make_pair
const int N = 123;
 
int main () {
    sll T; cin >> T;
    for (sll cs = 1; cs <= T; cs++) {
        sll n , m;
        cin >> n >> m;
        sll ans = 0;
        for (sll i = 0; i < n; i++) {
            sll sum = 0;
            for (sll j = 0; j < m; j++) {
                sll x; cin >> x;
                sum += x;
            }
            ans ^= sum;
        }
        printf ("Case %lld: " , cs);
        puts(ans ? "Alice" : "Bob");
    }
}
