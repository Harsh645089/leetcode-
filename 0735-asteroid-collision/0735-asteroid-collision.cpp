class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {

        stack<pair<int , int>> st;
        int n =  asteroid.size();
        int i = n-1;
        vector<bool> dead(n , 0);
        
        while(i >= 0){
            if(asteroid[i] >= 0){
                //means positive
                bool alive = true;
                while(!st.empty() && alive){
                    int astro = abs(st.top().first);
                    int idx = st.top().second;

                    if(asteroid[i] > astro){
                        st.pop();
                        dead[idx]  = true;
                    }
                    else if(asteroid[i] < astro){
                        dead[i] = true;
                        alive = false;
                    }
                    else{
                        st.pop();
                        dead[idx]  = true;
                        dead[i] = true;
                        alive = false;
                    }
                }
                i--;
            }
            else{
                st.push({asteroid[i] , i});
                i--;
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(dead[i] == false){
                ans.push_back(asteroid[i]);
            }
        }

        return ans;
    }
};