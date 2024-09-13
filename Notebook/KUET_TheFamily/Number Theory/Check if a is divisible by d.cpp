/*
check if a [-10^200 10^200] is divisible by b 
*/
void solve()
{
    string a;
    int b;
    cin >> a >> b;
    if(b<0) b *= -1;
    int pos = 0;
    if(a[0] == '-') pos = 1;
    ll sum = (a[pos++]-'0')%b;
    for(int i=pos;i<a.size();i++)
    {
        sum = (10*sum + (a[i] - '0')) % b;
    }
    if(sum == 0) cout << "divisible\n";
    else cout << "not divisible\n";
}