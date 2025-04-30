#include <bits/stdc++.h>
using namespace std;

// must use (r - l + 1) for split for range [l, r]
// ALERT!!!!!! the template is 0-based

typedef long long ll;
// Define the modulus as per the problem statement
const int MOD = 998244353;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// treap Class
struct treap {
    // node Structure
    struct node {
        ll val, sum;
        int size, prior;
        bool rev;
        ll mul_lazy, add_lazy;
        node* left;
        node* right;

        // Constructor for node
        node(ll _val) {
            val = _val % MOD;
            sum = val;
            size = 1;
            prior = rnd();
            rev = false;
            mul_lazy = 1;
            add_lazy = 0;
            left = right = nullptr;
        }
    };

    typedef node* pnode;
    pnode root;

    treap() : root(nullptr) {
        srand(time(0)); // Initialize random seed
    }

    // Utility Functions
    int sz(pnode t) {
        return t ? t->size : 0;
    }

    ll get_sum(pnode t) {
        return t ? t->sum : 0;
    }

    // Update function to recalculate sum and size
    void upd(pnode t) {
        if (t) {
            t->size = sz(t->left) + sz(t->right) + 1;
            t->sum = (get_sum(t->left) + t->val + get_sum(t->right)) % MOD;
        }
    }

    // Push down lazy updates
    void push(pnode t) {
        if (!t) return;

        // Handle reversal
        if (t->rev) {
            swap(t->left, t->right);
            if (t->left) t->left->rev ^= 1;
            if (t->right) t->right->rev ^= 1;
            t->rev = false;
        }

        // Handle linear updates (a_i = b * a_i + c)
        if (t->mul_lazy != 1 || t->add_lazy != 0) {
            // Apply to left child
            if (t->left) {
                t->left->val = (t->left->val * t->mul_lazy + t->add_lazy) % MOD;
                t->left->sum = (t->left->sum * t->mul_lazy + t->add_lazy * sz(t->left)) % MOD;
                t->left->mul_lazy = (t->left->mul_lazy * t->mul_lazy) % MOD;
                t->left->add_lazy = (t->left->add_lazy * t->mul_lazy + t->add_lazy) % MOD;
            }

            // Apply to right child
            if (t->right) {
                t->right->val = (t->right->val * t->mul_lazy + t->add_lazy) % MOD;
                t->right->sum = (t->right->sum * t->mul_lazy + t->add_lazy * sz(t->right)) % MOD;
                t->right->mul_lazy = (t->right->mul_lazy * t->mul_lazy) % MOD;
                t->right->add_lazy = (t->right->add_lazy * t->mul_lazy + t->add_lazy) % MOD;
            }

            // Reset current node's lazy values
            t->mul_lazy = 1;
            t->add_lazy = 0;
        }
    }

    // Split treap into left and right treaps with left containing first 'key' elements
    void split(pnode t, int key, pnode& l, pnode& r) {
        if (!t) {
            l = r = nullptr;
            return;
        }
        push(t);
        if (sz(t->left) >= key) {
            split(t->left, key, l, t->left);
            r = t;
        }
        else {
            split(t->right, key - sz(t->left) - 1, t->right, r);
            l = t;
        }
        upd(t);
    }

    // Merge two treaps l and r
    void merge_treap(pnode& t, pnode l, pnode r) {
        push(l);
        push(r);
        if (!l || !r) {
            t = l ? l : r;
        }
        else if (l->prior > r->prior) {
            merge_treap(l->right, l->right, r);
            t = l;
        }
        else {
            merge_treap(r->left, l, r->left);
            t = r;
        }
        upd(t);
    }

    // Insert a value at position pos
    void insert(int pos, ll val) {
        pnode new_node = new node(val);
        pnode t1, t2;
        split(root, pos, t1, t2);
        merge_treap(t1, t1, new_node);
        merge_treap(root, t1, t2);
    }

    // Erase a node at position pos
    void erase(int pos) {
        pnode t1, t2, t3;
        split(root, pos, t1, t2);
        split(t2, 1, t2, t3);
        // Optional: delete t2 to free memory
        merge_treap(root, t1, t3);
    }

    // Reverse a range [l, r)
    void reverse_range(int l, int r) {
        pnode t1, t2, t3;
        split(root, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            t2->rev ^= 1;
        }
        merge_treap(t2, t2, t3);
        merge_treap(root, t1, t2);
    }

    // Apply linear transformation a_i = b * a_i + c on range [l, r)
    void update_range(int l, int r, ll b, ll c) {
        pnode t1, t2, t3;
        split(root, l, t1, t2);
        split(t2, r - l, t2, t3);
        if (t2) {
            t2->val = (t2->val * b + c) % MOD;
            t2->sum = (t2->sum * b + c * sz(t2)) % MOD;
            t2->mul_lazy = (t2->mul_lazy * b) % MOD;
            t2->add_lazy = (t2->add_lazy * b + c) % MOD;
        }
        merge_treap(t2, t2, t3);
        merge_treap(root, t1, t2);
    }

    // Query the sum on range [l, r)
    ll query_sum(int l, int r) {
        pnode t1, t2, t3;
        split(root, l, t1, t2);
        split(t2, r - l, t2, t3);
        ll res = get_sum(t2);
        merge_treap(t2, t2, t3);
        merge_treap(root, t1, t2);
        return res % MOD;
    }

    // In-order traversal to print the treap (for debugging)
    void inorder_traversal(pnode t, vector<ll>& arr) {
        if (!t) return;
        push(t);
        inorder_traversal(t->left, arr);
        arr.push_back(t->val);
        inorder_traversal(t->right, arr);
    }

    // Print the treap in-order (for debugging)
    void print_treap() {
        vector<ll> arr;
        inorder_traversal(root, arr);
        for (auto x : arr) cout << x << ' ';
        cout << '\n';
    }

    // Get the size of the treap
    int get_size() {
        return sz(root);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    treap treap;

    int N, Q;
    cin >> N >> Q;

    // Insert initial array elements
    for(int i = 0; i < N; ++i){
        ll x;
        cin >> x;
        treap.insert(i, x);
    }

    while(Q--){
        int type;
        cin >> type;
        if(type == 0){
            int i;
            ll x;
            cin >> i >> x;
            treap.insert(i, x);
        }
        else if(type == 1){
            int i;
            cin >> i;
            treap.erase(i);
        }
        else if(type == 2){
            int l, r;
            cin >> l >> r;
            treap.reverse_range(l, r);
        }
        else if(type == 3){
            int l, r;
            ll b, c;
            cin >> l >> r >> b >> c;
            treap.update_range(l, r, b, c);
        }
        else if(type == 4){
            int l, r;
            cin >> l >> r;
            ll res = treap.query_sum(l, r);
            cout << res << "\n";
        }
    }

    // Optional: Print final array (for debugging)
    // treap.print_treap();

    return 0;
}
