class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = { 0 };
        for (auto letter : magazine) letters[letter - 'a']++;
        for (auto letter : ransomNote) if (letters[letter - 'a'] > 0) letters[letter - 'a']--; else return 0;
        return 1;
    }
};