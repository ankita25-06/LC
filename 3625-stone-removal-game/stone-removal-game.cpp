class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10)return false;
        int stone = n-10;
        bool turn = false;
        int remove = 9;
        while(stone >= 0){
            if(turn){
                stone -= remove;
                if(stone < 0)return false;
            }else{
                stone -= remove;
                if(stone < 0)return true;
            }
            remove--;
            turn = !turn;
        }
        if(turn && stone == 0)return true;

        return false;
    }
};