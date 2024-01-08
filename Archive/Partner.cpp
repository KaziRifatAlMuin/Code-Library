#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
using namespace std;
bitset<1000001> Primes;
vector<int> primes;
bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
  return a.second < b.second;
}
void SieveOfEratosthenes(int n) {
  Primes[0] = 1;
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (Primes[i / 2] == 0) {
      primes.push_back(i);
      for (int j = 3 * i; j <= n; j += 2 * i) Primes[j / 2] = 1;
    }
  }
}
int random(int a, int b, int mod) {
  static unsigned long long seed = 123412;
  seed = ((unsigned long long)a * seed + b) % mod;
  return seed;
}int main() {
  srand(time(NULL));  SieveOfEratosthenes(1000000);  vector<int> cool = {};  vector<int> cute = {19, 21, 31, 39, 57, 60, 79,  81,82, 84, 87, 89, 93, 95, 108, 109};
  for (int i = 1; i < 122; i++) {
    if (*lower_bound(cute.begin(), cute.end(), i) != i) cool.push_back(i);
  }  vector<pair<int, int>> lst, lst1;
  map<pair<int, int>, int> mp;for (auto i : cool)for (auto j : cute) lst1.push_back(make_pair(i, j));
  int pushes = 10000;
  while (pushes--)for (auto i : lst1) lst.push_back(i);
 unsigned long long seed = 0;
  shuffle(lst.begin(), lst.end(), default_random_engine(seed));
  int mod = primes[lower_bound(primes.begin(), primes.end(), (int)lst.size())-primes.begin()];
  //cout << mod << endl;
  int tries = 1000000;
  if (mod == 0) mod = primes[primes.size() - 1];
  while (tries--) {
    srand(time(NULL));
    int a = random(primes[rand() % 2000], primes[rand() % 1000], mod);
    // cout << a << endl;
    mp[lst[a]]++;
  }
  vector<pair<pair<int, int>, int>> s;
  for (auto i : mp) s.push_back(i);
  sort(s.begin(), s.end(), cmp);
  reverse(s.begin(), s.end());
  int ma = 0;
  for (auto i : s) {
    if (i.second > ma) ma = i.second;
  }
  int a, b;
  //cin >> a;
  int freq[122] = {0};
  for (auto i : s) {
    if (1.0L * i.second / ma * 100 > 70 && freq[i.first.first]== 0) {
      cout << i.first.first << " and " << i.first.second << " : "
           << 1.0L * i.second / ma * 100 << "%" << endl;
        freq[i.first.first]++;
    }
  }
}
