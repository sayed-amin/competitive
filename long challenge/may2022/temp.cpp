// C++ program to find minimum XOR value in an array.
#include <bits/stdc++.h>
using namespace std;
#define INT_SIZE 32
vector<vector<int> > g;
vector<int> v1;
vector<vector<int> > subtree;
vector<vector<int> > v;
// A Trie Node
struct TrieNode
{
    int value; // used in leaf node
    TrieNode *Child[2];
};

// Utility function to create a new Trie node
TrieNode *getNode()
{
    TrieNode *newNode = new TrieNode;
    newNode->value = 0;
    newNode->Child[0] = newNode->Child[1] = NULL;
    return newNode;
}

// utility function insert new key in trie
void insert(TrieNode *root, int key)
{
    TrieNode *temp = root;

    // start from the most significant bit, insert all
    // bit of key one-by-one into trie
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = (key & (1 << i));

        // Add a new Node into trie
        if (temp->Child[current_bit] == NULL)
            temp->Child[current_bit] = getNode();

        temp = temp->Child[current_bit];
    }

    // store value at leafNode
    temp->value = key;
}

// Returns minimum XOR value of an integer inserted
// in Trie and given key.
int minXORUtil(TrieNode *root, int key)
{
    TrieNode *temp = root;

    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = (key & (1 << i));

        // Traversal Trie, look for prefix that has
        // same bit
        if (temp->Child[current_bit] != NULL)
            temp = temp->Child[current_bit];

        // if there is no same bit.then looking for
        // opposite bit
        else if (temp->Child[1 - current_bit] != NULL)
            temp = temp->Child[1 - current_bit];
    }

    // return xor value of minimum bit difference value
    // so we get minimum xor value
    return key ^ temp->value;
}

// Returns minimum xor value of pair in arr[0..n-1]
int minXOR(vector<int> arr, int n)
{
    int min_xor = INT_MAX; // Initialize result

    // create a True and insert first element in it
    TrieNode *root = getNode();
    insert(root, arr[0]);

    // Traverse all array element and find minimum xor
    // for every element
    for (int i = 1; i < n; i++)
    {
        // Find minimum XOR value of current element with
        // previous elements inserted in Trie
        min_xor = min(min_xor, minXORUtil(root, arr[i]));

        // insert current array value into Trie
        insert(root, arr[i]);
    }
    return min_xor;
}

void dfs(int v, int par = -1)
{
    subtree[v].push_back(v);
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
        subtree[v].push_back(child);
        for (auto i : subtree[child])
        {
            if (i == child)
                continue;
            subtree[v].push_back(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    g.clear();
    v1.clear();
    subtree.clear();
    g.resize(n + 1);
    v1.resize(n + 1);
    subtree.resize(n + 1);
    v.resize(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v1[i];
    }
    dfs(1);
    for (int i = 0; i < subtree.size(); i++)
    {
        for (int j = 0; j < subtree[i].size(); j++)
            v[i].push_back(v1[subtree[i][j]]);
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].size() == 1)
            cout << -1 << " ";
        else
        {

            cout << minXOR(v[i], v[i].size()) << " ";
        }
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
