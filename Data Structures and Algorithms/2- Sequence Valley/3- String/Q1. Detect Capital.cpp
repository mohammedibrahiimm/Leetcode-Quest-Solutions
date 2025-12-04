class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCnt = 0;
        auto isCapital = [&](const char& c)->bool{
            return 'A' <= c && c <= 'Z';
        };
        for (auto &it : word) capitalCnt += isCapital(it);
        return !capitalCnt || capitalCnt == word.size() || capitalCnt == 1 && isCapital(word[0]);
    }
};