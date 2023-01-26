class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())
        {
            return -1;
        }
        
        int index = haystack.find(needle);
        if(index != string::npos) return index;
        else return -1;
    }
};