class Solution
{
    public:
        class Node
        {
            public:
                Node *links[2];
            bool contains(int bit)
            {
                return links[bit] != NULL;
            }
            void put(int bit, Node *node)
            {
                links[bit] = node;
            }
            Node* get(int bit)
            {
                return links[bit];
            }
        };
    class Trie
    {
        Node * root;
        public:
            Trie()
            {
                root = new Node();
            }
        void insert(int & num)
        {
            Node *node = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) &1;
                if (!node->contains(bit))
                {
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }
        int find(int & num)
        {
            Node *node = root;
            int mx = 0;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) &1;
                if (node->contains(1 - bit))
                {
                    mx = mx | (1 << i);
                    node = node->get(1 - bit);
                }
                else
                    node = node->get(bit);
            }
            return mx;
        }
    };
    vector<int> maximizeXor(vector<int> &nums, vector<vector< int>> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < queries.size(); i++)
        {
            v.push_back({ queries[i][1], { queries[i][0], i } } );
        }
        sort(v.begin(), v.end());
        vector<int> ans(queries.size());
        int j = 0, n = nums.size();
        Trie trie;
        for (int i = 0; i < queries.size(); i++)
        {
            int m = v[i].first;
            int x = v[i].second.first;
            int idx = v[i].second.second;
            while (j < n && nums[j] <= m)
            {
                trie.insert(nums[j++]);
            }
            if (j == 0)
            {
                ans[idx] = -1;
            }
            else
            {
                ans[idx] = trie.find(x);
            }
        }
        return ans;
    }
};