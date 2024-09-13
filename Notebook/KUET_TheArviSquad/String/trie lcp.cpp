class Trie {
public:
    class node    {
    public:
        node *child[27];
        int leaf, sz;
        node() {
            for(int i = 0; i < 27; i++) {
                child[i] = nullptr;
            }
            sz = 0;
            leaf = 0;
        }
    } *root;
    Trie () {
        root = new node();
    }
    void insert(string s) {
        node *cur = root;
        for(auto x : s) {
            int id = x - 'a';
            if(cur->child[id] == nullptr) {
                cur->child[id] = new node();
            }
            cur = cur->child[id];
            cur->sz++;
        }
        cur->leaf++;
    }
    void remove(string s) {
        stack<pair<node *, int>> stck;
        node *cur = root;
        for(auto x : s) {
            int id = x - 'a';
            if(cur->child[id] == nullptr) break;
            stck.push({cur, id});
            cur = cur->child[id];
        }
        while(!stck.empty()) {
            auto [x, y] = stck.top();
            stck.pop();
            x->child[y]->sz--;
            if(x->child[y]->sz == 0) {
                x->child[y] = nullptr;
                delete(x->child[y]);
            }

        }
    }
    int findLCP(string s) {
        int cnt = 0;
        node *cur = root;
        for(auto x : s) {
            int id = x - 'a';
            if(cur->child[id] == nullptr) break;
            cnt++;
            cur = cur->child[id];
        }
        return cnt;
    }
};
void solve() {
    Trie mytrie;
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 1; i <= n; i++) {
        string t; cin >> t;
        mytrie.insert(t);
        v.push_back(t);
    }
    for(auto x : v) {
        mytrie.remove(x);
        cout << mytrie.findLCP(x) << "\n";
        mytrie.insert(x);
    }

}  