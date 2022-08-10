class Solution {
public:
    string decodeMessage(string key, string message) {
         int n=key.size();
        int m=message.size();
        map<char,char>mp;
        char x='a';
        for(int i=0;i<n;i++)
        {
            if(key[i]!=' ') //If the character is ' ' (blank space) then we will skip.
            {
                if(mp.find(key[i])==mp.end())  //If the element has occured before then we will skip it.
                {
                    mp[key[i]]=x; //We will map the character according to its occurrence
                    x++;
                }
            }
        }
        string s="";
        for(int i=0;i<m;i++)
        {
            if(message[i]==' ') s+=' ';
            else
            {
                s+=mp[message[i]];
            }
        }
        return s;
    }
};