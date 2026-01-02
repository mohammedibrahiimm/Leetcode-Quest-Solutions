#define all(v)    v.begin(),v.end()

class Trie {
public:
    //N is number of possible characters in a string
    const static int N = 26;

    //baseChar defines the base character for possible characters
    //like '0' for '0','1','2'... as possible characters in string
    const static char baseChar = 'a';

    struct TrieNode {
        int next[N];
        //if isEnd is set to true , a string ended here
        bool isEnd;
        //freq is how many times this prefix occurs
        int freq;
        TrieNode() {
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
    Trie () {
        tree.push_back(TrieNode());
    }

    //inserting a string in trie
    void insert(const string &s) {
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
        }
        tree[p].isEnd = true;
    }

    bool checkPrefix(const string &s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
                return false;

            p = tree[p].next[s[i] - baseChar];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(all(words));
        string ans;
        Trie trie;
        for (auto &word : words) {
            string temp = word.substr(0, word.size() - 1);
            if (trie.checkPrefix(temp)) {
                trie.insert(word);
                if (ans.size() < word.size())ans = word;
                else if (ans.size() == word.size() && ans > word)ans = word;
            }
        }
        return ans;
    }
};