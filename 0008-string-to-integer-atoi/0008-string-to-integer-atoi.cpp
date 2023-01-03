class Solution {
public:
    int myAtoi(string s)
    {        
        long int ans=0;
        int i=0;
        
        //remove white sapces
        while(i<s.length() && s[i] == ' ') i++;
        
        short sign=1;
        
        if(s[i] == '-')
        {
            sign = -1*sign;
            i++;
        }
        
        else if(s[i] == '+')
        {
            i++;
        }
        
        for(; i<s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                ans = ans*10 + (s[i]-'0');
                
                if(ans >= INT_MAX)
                    break;
            }
            
            else 
                break;
        }
        
        ans = sign * ans;
        
        if(ans >= INT_MAX)
            return INT_MAX;
        
        else if(ans<=INT_MIN)
            return INT_MIN;
        
        return int(ans);
    }
};