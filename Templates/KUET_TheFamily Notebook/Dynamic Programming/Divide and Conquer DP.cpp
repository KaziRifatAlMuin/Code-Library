#define inf LLONG_MAX
typedef long long ll;

ll G, L; // Total group, cell size
ll dp[8001][801], cum[8001];
ll C[8001]; // Value of each cell

// Calculate the cost between two indices in the cumulative sum array
inline ll cost(ll l, ll r) {
    return (cum[r] - cum[l - 1]) * (r - l + 1);
}

// Function to recursively calculate the optimal partition
void fn(ll g, ll st, ll ed, ll r1, ll r2) {
    if (st > ed) return;
    ll mid = (st + ed) / 2, pos = -1;

    dp[mid][g] = inf;

    // Iterate through possible positions and update the optimal partition
    for (int i = r1; i <= r2; i++) {
        ll tcost = cost(i, mid) + dp[i - 1][g - 1];
        if (tcost < dp[mid][g]) {
            dp[mid][g] = tcost;
            pos = i;
        }
    }

    // Recursively calculate optimal partition for the left and right sides
    fn(g, st, mid - 1, r1, pos);
    fn(g, mid + 1, ed, pos, r2);
}

int main() {
    // Calculate the cumulative sum array
    for (int i = 1; i <= L; i++)
        cum[i] = cum[i - 1] + C[i];

    // Initialize the base case for dp array
    for (int i = 1; i <= L; i++)
        dp[i][1] = cost(1, i);

    // Calculate optimal partitions for each group
    for (int i = 2; i <= G; i++)
        fn(i, 1, L, 1, L);

    // Your code logic continues here
    // ...

    return 0;
}
