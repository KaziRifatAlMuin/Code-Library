const int N=1005;
ld a[N][N];
void psum(int n,int m)
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
}
}
}
ld suma(int x1,int y1, int x2,int y2)
{
return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}