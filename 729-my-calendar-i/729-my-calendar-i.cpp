class MyCalendar {
public:
    vector<pair<int,int>> vec;
     MyCalendar() {
    
        }

    bool book(int s, int e) {
    for(auto& it:vec){
	//checkig have present s greater than and e less than in the vector
        if(it.first<e and s<it.second)
            return false;
    }
	//insert ine the vector
    vec.push_back({s,e});
    return true;
}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */