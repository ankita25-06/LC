class Solution {
public:
    bool isPalindrome(int x) {
    long rev = 0;
    int num = x;
    while (num > 0){
    rev = rev *10 + num%10;
    num = num /10;
   }
    if(rev == x){
        return true;
    }else{
        return false;
    }
    }
};