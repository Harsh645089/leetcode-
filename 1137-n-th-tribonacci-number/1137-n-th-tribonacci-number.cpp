class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int curr = 0;
        int third = 0;
        int second = 1;
        int prev = 1;

        for(int i = 3 ; i <= n ; i++){
            curr = third + second + prev;
            third  = second;
            second = prev;
            prev = curr;
        }

        return prev;
    }
};