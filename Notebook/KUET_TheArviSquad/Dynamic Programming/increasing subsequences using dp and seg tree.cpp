#include <bits/stdc++.h>
using namespace std;

#define N 100005 // Maximum size of the input array

int t[4*N]; // Segment tree array

// Function to update the segment tree
void upd(int n, int b, int e, int i, int x) {
    // If the update index i is out of the current segment range [b, e], return
    if (b > i || e < i) return;
    
    // If the current segment is exactly the point we want to update
    if (b == e && b == i) {
        // Update the segment tree node with the maximum of its current value and x
        t[n] = max(t[n], x);
        return;
    }
    
    // Otherwise, update the left and right child segments
    int mid = (b + e) >> 1;
    int l = n << 1; // Left child index
    int r = l | 1;  // Right child index
    upd(l, b, mid, i, x); // Update left child
    upd(r, mid + 1, e, i, x); // Update right child
    
    // After updating children, update the current node to be the maximum of its children
    t[n] = max(t[l], t[r]);
}

// Function to query the segment tree for the maximum value in range [i, j]
int query(int nd, int b, int e, int i, int j) {
    // If the query range [i, j] is out of the current segment range [b, e], return a very small value
    if (j < b || e < i) return -1e9;
    
    // If the current segment is completely within the query range, return the node value
    if (i <= b && e <= j) return t[nd];
    
    // Otherwise, query the left and right children segments
    int mid = (b + e) >> 1;
    int l = (nd << 1); // Left child index
    int r = l | 1; // Right child index
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // Return the maximum of left and right query results
}

int a[N], dp[N]; // Input array and dp array to store the lengths of the LIS ending at each position

void solve() {
    int n;
    cin >> n; // Input the size of the array
    set<int> st; // Set to store the unique elements of the array
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // Input the elements of the array
        st.insert(a[i]); // Insert each element into the set
    }
    
    // Map to compress the values in the array to a smaller range [1, size of the set]
    map<int, int> mp;
    int id = 1;
    for (auto x : st) {
        mp[x] = id++;
    }
    
    // Replace each element in the array with its compressed value
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
    }
    
    // Calculate the LIS ending at each position
    for (int i = 1; i <= n; i++) {
        dp[i] = 1; // Initialize dp[i] to 1 (each element is an LIS of length 1 by itself)
        
        // If the current element is not the smallest, query the maximum length of LIS for elements less than the current element
        if (a[i] != 1) {
            int mx = query(1, 1, n, 1, a[i] - 1); // Query for the maximum dp value in the range [1, a[i] - 1]
            mx++;
            dp[i] = max(dp[i], mx); // Update dp[i] to the maximum of its current value and mx
        }
        
        // Update the segment tree with the new dp value for the current element
        upd(1, 1, n, a[i], dp[i]);
    }
    
    // Find the maximum value in the dp array, which represents the length of the longest increasing subsequence
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    
    // Output the result
    cout << ans << "\n";
}
