class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int remflower = n;
        int bedlen = flowerbed.size();

        for(int i = 0 ; i < bedlen ; i++){
            if(flowerbed[i] == 0){
                bool leftbed = (i == 0 || flowerbed[i-1] == 0);
                bool rightbed = (i == bedlen-1 || flowerbed[i+ 1] == 0);

                if(leftbed && rightbed){
                    flowerbed[i] = 1;
                    remflower--;

                    if(remflower == 0) return true;
                }
            }
        }
        return remflower <= 0;
    }
};