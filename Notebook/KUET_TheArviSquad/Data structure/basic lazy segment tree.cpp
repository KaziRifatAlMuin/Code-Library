class SegTlazy {
public:
    // Define macros for left and right child indices
    #define lc (nd << 1)
    #define rc (lc | 1)
    
    // Define a structure to represent each node in the segment tree
    struct node {
        ll val; // Value associated with the node
        node() {}; // Default constructor
        node (ll v) {
            val = v;
        }
    };
    
    // Declare member variables
    vector<int> a; // Input array
    vector<ll> lazy; // Lazy propagation array
    vector<node> t; // Segment tree
    int n; // Size of the array
    
    // Constructors
    SegTlazy() {
        // Clear vectors and set size to 0
        a.clear();
        t.clear();
        lazy.clear();
        n = 0;
    }   
    
    SegTlazy(int n) {
        // Initialize with given size
        this -> n = n;
        a.resize(n + 1, 0);
        t.resize(4*n + 1, node());
        lazy.resize(4*n + 1, 0);
    }
    
    // Function to take input array and build the segment tree
    void takeInput() {
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
    }
    
    // Function to merge information from left and right child nodes
    inline void merge(node &ND, node L, node R) {
        // This function can be overridden based on specific problem requirements
    } 
    
    // Function to propagate lazy updates from a node to its children
    void push(int nd, int b, int e) {
        if(lazy[nd] == 0) return; // No lazy update to propagate
        
        // Lazy update operations for different types of queries
        // Add your explanation here...
        
        // Reset lazy update for the current node
        lazy[nd] = 0;
    }
    
    // Function to build the segment tree recursively
    void build(int nd, int b, int e) {
        lazy[nd] = 0; // Initialize lazy update for the current node
        
        // Base case: leaf node
        if(b == e) {
            t[nd].val = a[b];
            return;
        }
        
        // Divide and conquer to build left and right child nodes
        int mid = b + e >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        
        // Merge information from left and right child nodes
        merge(t[nd], t[lc], t[rc]);
    }
    
    // Function to perform lazy update within a specified range
    void upd(int nd, int b, int e, int i, int j, ll v) {
        // Propagate lazy updates from the current node
        push(nd, b, e);
        
        // Out of range, return
        if(j < b || e < i) return;
        
        // Fully covered range, apply lazy update
        if(i <= b && e <= j) {
            lazy[nd] = v;
            push(nd, b, e);
            return;
        }
        
        // Partially covered range, recursively update left and right child nodes
        int mid = b + e >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        
        // Merge information from updated child nodes
        merge(t[nd], t[lc], t[rc]);
    }
    
    // Function to perform a query within a specified range
    node query(int nd, int b, int e, int i, int j) {
        // Propagate lazy updates from the current node
        push(nd, b, e);
        
        // Out of range, return neutral value
        if(j < b || e < i) return 0;
        
        // Fully covered range, return value of current node
        if(i <= b && e <= j) {
            return t[nd];
        }
        
        // Partially covered range, recursively query left and right child nodes
        int mid = b + e >> 1;
        auto left = query(lc, b, mid, i, j);
        auto right = query(rc, mid + 1, e, i, j);
        
        // Merge information from child nodes and return
        node res;
        merge(res, left, right);
        return res;
    }
};
