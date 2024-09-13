int findPowerOfP(int n, int p)
{
int count = 0;
int r=p;
while (r <= n) {
// calculating floor(n/r)
// and adding to the count
count += (n / r);
// increasing the power of p
// from 1 to 2 to 3 and so on
r = r * p;
}
return count;
}
vector<pair<int, int> > ans;
ans.push_back(make_pair(i, count)); 
// count how many times i divide
int largestPowerOfK(int n, int k)
{
vector<pair<int, int>> vec;
vec = primeFactorsofK(k);
int ans = INT_MAX;
for (int i = 0; i < vec.size(); i++) {
ans = min(ans, 
    findPowerOfP(n, vec[i].first) / vec[i].second);
}
return ans;
}