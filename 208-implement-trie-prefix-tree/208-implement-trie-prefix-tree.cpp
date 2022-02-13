class Trie {
public:
    struct Node
    {
        Node* arr[26];
        bool flag=false;
        
        bool contains(char ch)
        {
            return (arr[ch-'a'] != NULL);
        }
        
        void put(char ch, Node* newNode)
        {
            arr[ch-'a'] = newNode; 
        }
        
        Node* getNext(char ch)
        {
            return arr[ch-'a'];
        }
        
        void setFlag()
        {
            flag=true;
        }
        
        bool isFlagSet()
        {
            return flag;
        }
    };
    Node* trie;
    
    Trie()
    {
         trie = new Node();
    }
    
    void insert(string word)
    {
        Node* temp = trie;
        for(int i=0; i<word.size(); i++)
        {
            if(!temp->contains(word[i])) //check in temp->arr
            {
                Node* newNode = new Node(); //createv a new node
                temp->put(word[i], newNode); //put that in trie
            }
            temp = temp->getNext(word[i]);
        }
        temp->setFlag();
    }
    
    bool search(string word)
    {
        Node* temp = trie;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->contains(word[i])) //check in temp->arr
            {
                temp = temp->getNext(word[i]);
            }
            
            else
            {
                return false;
            }
        }
        
        return (temp->flag==true)? true: false;
    }
    
    bool startsWith(string word)
    {
        Node* temp = trie;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->contains(word[i])) //check in temp->arr
            {
                temp = temp->getNext(word[i]);
            }
            
            else
            {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */