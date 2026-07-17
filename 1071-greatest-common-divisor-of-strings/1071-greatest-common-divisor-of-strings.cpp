class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int str1Len = str1.size();
        int str2Len = str2.size();

        string ans = "";

        for(int i = 1 ; i <= str1Len ; i++){
            //working on  string 1
            string x = str1.substr(0 , i);
            int xLen = x.size();

            if(str1Len % xLen == 0 && str2Len % xLen == 0){
                //means we can consider it
                int factor = str1Len / xLen ;

                string temp = "";

                for(int j = 0 ; j < factor ; j++){
                    temp+=x;
                }

                if(temp == str1){
                    factor = str2Len / xLen ;
                    string temp2 = "";

                    for(int j = 0 ; j < factor ; j++){
                        temp2+=x;
                    }

                    if(temp2 == str2){
                        if(ans.size() < xLen){
                            ans = x;
                        }
                    }
                }
            }
        }

        return ans;
    }
};