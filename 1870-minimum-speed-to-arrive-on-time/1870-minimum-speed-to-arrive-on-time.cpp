class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if((double)dist.size()-1 >= hour) return -1;
        int l=1,r=1e7;

        while(l<r){
            int mid = l+(r-l)/2;
            if(helper(dist,hour,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    
    bool helper(vector<int>& dist, double hour, int speed){
        double time = 0;
        for (auto &d : dist) {
            time = ceil(time);
            time +=  (double) d/speed;
            if (time > hour) return false;
        }
        return true;
    }
};