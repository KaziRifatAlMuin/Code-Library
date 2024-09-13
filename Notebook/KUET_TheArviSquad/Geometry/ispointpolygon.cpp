#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { 
    return (x > eps) - (x < -eps); }
struct PT {
double x, y;
PT() { x = 0, y = 0; }
PT(double x, double y) : x(x), y(y) {}
PT(const PT &p) : x(p.x), y(p.y)    {}
PT operator + (const PT &a) const { 
    return PT(x + a.x, y + a.y); }
PT operator - (const PT &a) const { 
    return PT(x - a.x, y - a.y); }
PT operator * (const double a) const { 
    return PT(x * a, y * a); }
};
inline double cross(PT a, PT b) { 
    return a.x * b.y - a.y * b.x; }
inline int orientation(PT a, PT b, PT c) { 
    return sign(cross(b - a, c - a)); }
bool is_point_on_seg(PT a, PT b, PT p) {
if (fabs(cross(p - b, a - b)) < eps) {
if (p.x < min(a.x, b.x) - eps || 
    p.x > max(a.x, b.x) + eps) return false;
if (p.y < min(a.y, b.y) - eps || 
    p.y > max(a.y, b.y) + eps) return false;
return true;
}
return false;
}

bool is_point_on_polygon(vector<PT> &p, const PT& z) {
int n = p.size();
for (int i = 0; i < n; i++) {
if (is_point_on_seg(p[i], p[(i + 1) % n], z)) 
    return 1;
}
return 0;
}
// returns 1e9 if the point is on the polygon 
int winding_number(vector<PT> &p, const PT& z) { // O(n)
if (is_point_on_polygon(p, z)) return 1e9;
int n = p.size(), ans = 0;
for (int i = 0; i < n; ++i) {
int j = (i + 1) % n;
bool below = p[i].y < z.y;
if (below != (p[j].y < z.y)) {
auto orient = orientation(z, p[j], p[i]);
if (orient == 0) return 0;
if (below == (orient > 0)) ans += below ? 1 : -1;
}
}
return ans;
}
// k = -1 inside, k = 0 boundary k = 1 outside
int is_point_in_polygon(vector<PT> &p, 
const PT& z) { // O(n)
int k = winding_number(p, z);
return k == 1e9 ? 0 : k == 0 ? 1 : -1;
}