int d[N][N];
int main() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        if (d[i][k] + d[k][j] < d[i][j] - EPS)
        d[i][j] = d[i][k] + d[k][j]; 
      }
    }
  }
  return 0;
}