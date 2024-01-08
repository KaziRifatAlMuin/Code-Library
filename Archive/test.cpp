#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    int flag = 0;
    for(int i = 1; i <= n; i++) {
        (i-1) % m == 0 ? flag++ : flag;
        cout << (flag % 2 == 0? "+" : "-") << i;
    }
}