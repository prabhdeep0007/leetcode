class MyCalendar {
public:
    multiset<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        s.insert({start,+1});
        s.insert({end,-1});
        int sum=0;
        for(auto it:s)
        {
            sum+=it.second;
            if(sum>1)
            {
             s.erase(s.find({start,+1}));
             s.erase(s.find({end,-1}));
            return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */