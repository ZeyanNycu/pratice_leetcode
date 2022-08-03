class MyCalendar {
public:
    set < pair<int,int> > interval;
    MyCalendar() {
        interval.clear();
    }
    
    bool book(int start, int end) {
        bool sign = true;
        for(auto it:interval)
        {
            if(end>it.first && end<=it.second)
            {
                sign = false;
                break;
            }
            if(start>=it.first && start<it.second)
            {
                sign = false;
                break;
            }
            if(start<=it.first && end>=it.second)
            {
                sign = false;
                break;
            }
        }
        if(sign) 
        {
            interval.insert(make_pair(start,end));
            return sign;
        }
        return sign;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
