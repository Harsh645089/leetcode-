class MyCalendarTwo {
public:

    vector<pair<int , int>> intervals;
    vector<pair<int , int>> overlap;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {

        //this is to check the triple overlap
        for(auto interval : overlap){
            int start = interval.first;
            int end = interval.second;

            if(startTime < end && start < endTime){
                return false; //as this is already the overlapp reason
            }
        }

        //this is to find the first overlap region if there any and then inserting that in the overlap region 
        for(auto interval : intervals){

            int start = interval.first;
            int end = interval.second;

            if(startTime < end && start < endTime){
                //means this is the overlap and is the first overlap as we have made it till now 

                //so now we need to insert the overlap region in the overlap array

                int overlapStart = max(startTime , start);
                int overlapEnd = min(endTime , end);

                overlap.push_back({overlapStart , overlapEnd});
            }
        }
        
        //inserting the first overlap or clean interval in the intervals
        intervals.push_back({startTime , endTime});

        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */