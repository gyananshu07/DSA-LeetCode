class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(),n=needle.size();
        int i=0;
        while(i<m){
            string str;
            if(haystack[i]==needle[0])  str=haystack.substr(i,n);
            if(str==needle) return i;
            i++;
        }
        return -1;
    }
};