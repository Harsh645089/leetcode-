class Solution {
public:
    int partition(vector<int> &nums  , int low , int high ){

        int randomidx = low + rand() % (high - low + 1); // Generates a random index in the range [low, high]
        swap(nums[randomidx] , nums[high]); // this is needed to improve the speed of algo


        int pivot = nums[high];
        int i = low;

        for(int j = low ; j < high ; j++){
            if(nums[j] < pivot){
                swap(nums[j] , nums[i]);
                i++;
            }
        }

        swap(nums[i] , nums[high]); //cannot use pivot here as it is only the copy of the nums[high] not the nums[high] so if i used that then nothing will chnage in the array 

        return i;
    }
    
    int quickselect(vector<int> &nums  , int low , int high ,int &idx){

        if(low > high) return -1;
        
        int pivotidx = partition(nums , low , high);

        if(pivotidx == idx) return nums[pivotidx];

        else if(pivotidx < idx) return quickselect(nums , pivotidx + 1 , high , idx);

        return quickselect(nums , low , pivotidx -1 , idx);
    }


    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = n - k ; //if it is a sorted array then the kth element from the right is the kth largest element so the its idx from left is n - k so i need to find the correct element of this idx

        return quickselect(nums , 0 , n-1 , idx);

        
    }
};