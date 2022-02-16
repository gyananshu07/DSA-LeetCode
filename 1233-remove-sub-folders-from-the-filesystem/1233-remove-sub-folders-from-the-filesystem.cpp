class Trie{
    public:
    struct trie{
        vector<trie*> children {vector<trie *>(26, NULL)};
        bool iseow=false;
        
    }*Root,*curr;
    
    Trie(){
        Root= new trie();
    }
    
    bool insert(string &s){
        curr=Root;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(s[i]=='/')continue;
            if(!curr->children[c-'a'])
                curr->children[c-'a']=new trie();
            curr=curr->children[c-'a'];
            if(s[i+1]=='/' && curr->iseow==true)
                return false;
        }
        curr->iseow=true;
        return true;
    }
    
    
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>result;
        Trie* trie=new Trie();
         sort(folder.begin(),folder.end());
        for(string &s:folder){
            if(trie->insert(s))
                result.push_back(s);
        }
        return result;
    }
};