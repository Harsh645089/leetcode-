class Solution {
public:

    //this is by chatgpt and this is just for the reference that how can we use the segment tree  , but as of now kuch samaj nhi aaya

    struct Node {
        int leftLen;
        int rightLen;
        int best;
        int len;

        char leftChar;
        char rightChar;
    };

    vector<Node> tree;

    // Merge two nodes
    Node merge(Node a, Node b) {

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Initially, best is the best of either side
        res.best = max(a.best, b.best);

        // Left prefix
        res.leftLen = a.leftLen;

        if (a.leftLen == a.len && a.rightChar == b.leftChar) {
            res.leftLen = a.len + b.leftLen;
        }

        // Right suffix
        res.rightLen = b.rightLen;

        if (b.rightLen == b.len && a.rightChar == b.leftChar) {
            res.rightLen = b.len + a.rightLen;
        }

        // If the two middle characters are equal,
        // we can join the suffix of a and prefix of b.
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.rightLen + b.leftLen);
        }

        return res;
    }

    // Build segment tree
    void build(string &s, int node, int start, int end) {

        if (start == end) {

            tree[node].leftLen = 1;
            tree[node].rightLen = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];

            return;
        }

        int mid = (start + end) / 2;

        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Update one position
    void update(string &s, int node, int start, int end,
                int index, char c) {

        if (start == end) {

            s[index] = c;

            tree[node].leftLen = 1;
            tree[node].rightLen = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            tree[node].leftChar = c;
            tree[node].rightChar = c;

            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(s, 2 * node, start, mid, index, c);
        }
        else {
            update(s, 2 * node + 1, mid + 1, end, index, c);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }


    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();
        int k = queryCharacters.size();

        tree.resize(4 * n);

        // Build tree using original string
        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < k; i++) {

            int index = queryIndices[i];
            char c = queryCharacters[i];

            // Change character
            update(s, 1, 0, n - 1, index, c);

            // Root contains answer for entire string
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};