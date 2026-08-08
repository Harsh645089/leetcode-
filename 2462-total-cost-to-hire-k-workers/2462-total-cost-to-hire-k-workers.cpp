class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();

        priority_queue<int , vector<int> , greater<int> > left;
        priority_queue<int , vector<int> , greater<int> > right;

        vector<bool> inserted(n , 0);

        int high1 = candidates - 1;
        int high2 = n - candidates;

        

        for(int i = 0 ; i <= high1 ; i++){
            left.push(costs[i]);
            inserted[i] = 1;
        }

        for(int i = high2 ; i < n ; i++){
            if(inserted[i] == 0){
                right.push(costs[i]);
                inserted[i] = 1;
            }
        }

        long long cost = 0;

        while(k > 0 && !right.empty() && !left.empty()){
            int leftmin = left.top();
            int rightmin = right.top();

            if(leftmin <= rightmin){
                cost += leftmin;
                left.pop();
                high1++;
                if(high1 < n && inserted[high1] == 0){
                    left.push(costs[high1]);
                    inserted[high1] = 1;
                }
            }
            else{
                cost+= rightmin;
                right.pop();
                high2--;
                if(high2 >= 0 && inserted[high2] == 0){
                    right.push(costs[high2]);
                    inserted[high2] = 1;
                }
            }

            k--;
        }

        if(k != 0){
            if(!left.empty()){
                while(k >0){
                    int leftmin = left.top();
                    cost += leftmin;
                    left.pop();
                    k--;
                }
            }
            else{
                while(k >0){
                    int rightmin = right.top();
                    cost += rightmin;
                    right.pop();
                    k--;
                }
            }
        }

        return cost;
    }
};