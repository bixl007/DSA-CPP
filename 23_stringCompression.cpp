// This code represent my solution for the leetcode question of String Compression(443)

class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int c = 1;
        for(int i = 0; i < chars.size(); i++){
            if(i+1 < chars.size() && chars[i] == chars[i+1]){
                c++;
            }
            else{
                s.push_back(chars[i]);
                if(c > 1){
                    s.append(to_string(c));
                }
                c = 1;
            }
            
        }

        for(int i = 0; i < s.length(); i++){
            chars[i] = s[i];
        }


        return s.length();
    }
};