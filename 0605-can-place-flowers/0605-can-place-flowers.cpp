class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int remflower = n;
        int bedlen = flowerbed.size();
        if(n == 0) return true;
        if(bedlen == 1){
            if(flowerbed[0] == 0) return true;
            return false;
        }

        while(i < bedlen){
            if(flowerbed[i] == 1){
                //cannot plant here ;
                i = i + 2;
            }
            else if( flowerbed[i] == 0 ){
                //may plant ;
                if(i == 0){
                    if(flowerbed[i+ 1] == 0){
                        remflower--;
                        i = i + 2;
                    }
                    else{
                        i = i + 3;
                    }
                }

                else if(i == bedlen - 1){
                    if(flowerbed[i-1] == 0){
                        remflower--;
                        
                    }
                    i = i + 2;
                }

                else{
                    if( flowerbed[i -1] == 0 && flowerbed[i + 1] == 0){
                        remflower-- ; //planted
                        i = i+ 2;
                    }
                    else{
                        i++;
                    }
                
                }
              
            }
        }

        if(remflower <= 0 ) return true;

        return false;
    }
};