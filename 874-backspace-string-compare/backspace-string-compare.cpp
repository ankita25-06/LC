class Solution {
public:
    bool backspaceCompare(string s, string t) {
     string new_s = "";
     string new_t = "";

     
     for(char c : s){
        if(c != '#'){
            new_s.push_back(c);
        }else{
            if(!new_s.empty()){
                    new_s.pop_back();
                }
        }
     } 

     for(char c : t){
        if(c != '#'){
            new_t.push_back(c);
        }else{
            if(!new_t.empty()){
                    new_t.pop_back();
                }
        }
     }   

     return new_t == new_s;
    }
};