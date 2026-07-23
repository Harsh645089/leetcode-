class Solution {
public:
    long long hoursneeded(vector<int>& piles, int speed){
        long long hours = 0;
        for(auto bananas : piles){
            hours += (bananas + speed -1)/speed; //this is nothing but the ceiluing of  the (bananas/speed) but this is the mathematical way to represent it
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minspeed = 1; //means one banana at a time
        int maxspeed = *max_element(piles.begin() , piles.end());

        int low = minspeed;
        int high = maxspeed;
        int k ;

        while(low <= high){
            int mid = low + (high - low)/2 ;
            long long reqhours = hoursneeded(piles , mid );
            if(reqhours > h){
                //means speed is low so move to higher speed
                low = mid + 1;
            }
            else{
                //this works but lets look for smaller if possible
                k = mid;
                high = mid -1;
            }
        }

        return k;

    }
};