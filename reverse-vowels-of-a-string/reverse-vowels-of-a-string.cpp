class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowel{'a', 'e', 'i', 'o', 'u','A', 'E','I', 'O','U'};
        int lo=0, hi=s.length()-1;
    
        while(lo<hi)
        {
            if(find(vowel.begin(), vowel.end(), s[lo])==vowel.end())
            {
                lo++;
            }
            else if(find(vowel.begin(), vowel.end(), s[hi])==vowel.end())
            {
                hi--;
            }
            else if(find(vowel.begin(), vowel.end(), s[lo])!=vowel.end() && find(vowel.begin(), vowel.end(), s[hi])!=vowel.end())
            {
                swap(s[lo], s[hi]);
                lo++;
                hi--;
            }
        }
        
        return s;
    }
};