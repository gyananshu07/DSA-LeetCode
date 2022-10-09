class MyCalendarThree {
    map<int,int> m;
public:
    MyCalendarThree() {
        m.clear();
    }
    
    int book(int start, int end) {
        m[start]+=1;
        m[end]-=1;
        int c=0;
        int res=0;
        for(auto &a:m){
            c+=a.second;
            res=max(c,res);
        }
        return res;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */