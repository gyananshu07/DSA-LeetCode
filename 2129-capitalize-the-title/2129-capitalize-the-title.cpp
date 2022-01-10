class Solution {
public:
string capitalizeTitle(string t){
    int end=0,n=t.size();
    
	while(end<n){
        //put 'start' at start of current word
        int start=end;   
        
        //keep on converting the letter of current word into lowercase {32 is ASCII of space}
        while(end<n and t[end]!=32) t[end]=tolower(t[end]),  end++;
        
        ///Now make First Capital case -> if length>2
		if(end-start>2) t[start]=toupper(t[start]);
        
        end++; //to go next word
    }
    return t;
}
};