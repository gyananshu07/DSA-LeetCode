class Solution {
public:
    int numberOfMatches(int n) {
        int team=n, matches=0, total=0;
        
        while(team)
        {
            if(team==1) 
            {
                break;
            }
            
            if((team&1)==0)
            {
                matches = team/2;
                team = team/2;
                total = total + matches;
            }
            
            else if((team&1)!=0)
            {
                matches = (team-1)/2;
                team = matches+1;
                total = total +  matches;
            }
        }
        
        return total;
    }
};