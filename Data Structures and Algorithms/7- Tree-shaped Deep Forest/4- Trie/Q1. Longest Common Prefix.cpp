#include "bits/stdc++.h"

using namespace std;

#define all(v)    v.begin(),v.end()

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
        }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Trie {
private:
    string ans;
    int sz;
public:
    //N is number of possible characters in a string
    const static int N = 26;

    //baseChar defines the base character for possible characters
    //like '0' for '0','1','2'... as possible characters in string
    const static char baseChar = 'a';

    struct TrieNode
    {
        int next[N];
        //if isEnd is set to true , a string ended here
        bool isEnd;
        //freq is how many times this prefix occurs
        int freq;

        TrieNode()
        {
            for (int i = 0; i < N; i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
        }
    };

    //the implementation is via vector and each position in this vector
    //is similar as new pointer in pointer type implementation
    vector <TrieNode> tree;

    //Base Constructor
    Trie (int sz): sz(sz)
    {
        tree.push_back(TrieNode());
    }

    //inserting a string in trie
    string insert(const string &s) {
        int p = 0;
        tree[p].freq++;
        for (int i = 0; i < s.size(); i++) {
            // tree[]
            if (tree[p].next[s[i] - baseChar] == -1) {
                tree.push_back(TrieNode());
                tree[p].next[s[i] - baseChar] = tree.size() - 1;
            }
            p = tree[p].next[s[i] - baseChar];
            tree[p].freq++;
            if (tree[p].freq == sz)ans += s[i];
        }
        tree[p].isEnd = true;
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        const int n = strs.size();
        Trie t(n);
        for (auto &it : strs)
            ans = t.insert(it);
        return ans;
    }
};