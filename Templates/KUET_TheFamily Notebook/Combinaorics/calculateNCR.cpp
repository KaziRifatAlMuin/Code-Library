int factorialModM(int n, int m) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % m;
    }
    return result;
}

// Function to calculate modular inverse using extended Euclidean algorithm
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}
// Function to calculate nCr modulo m using factorials and modular inverse
int nCrModM(int n, int r, int m) {
    if (r == 0) return 1;
    int num = factorialModM(n, m);
    int den = (factorialModM(r, m) * factorialModM(n - r, m)) % m;
    return (num * modInverse(den, m)) % m;
}
