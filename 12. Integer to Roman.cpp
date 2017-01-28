class Solution {
public:
    // 83.74%, ok
    string intToRoman(int num) {
        // {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        string ans;
        while(num / 1000) {ans += 'M'; num -= 1000;}
        if(num / 900) {ans += "CM"; num -= 900;}
        else if(num / 500) {ans += 'D'; num -= 500;}
        else if(num / 400) {ans += "CD"; num -= 400;}
        while(num / 100) {ans += 'C'; num -= 100;}
        if(num / 90) {ans += "XC"; num -= 90;}
        else if(num / 50) {ans += 'L'; num -= 50;}
        else if(num / 40) {ans += "XL"; num -= 40;}
        while(num / 10) {ans += 'X'; num -= 10;}
        if(num == 4) ans += "IV";
        else if(num == 9) ans += "IX";
        else{
            if(num / 5) {ans += 'V'; num -= 5;}
            while(num) {ans += 'I'; num -= 1;}
        }
        return ans;
    }

    // more elegant: 83.74%, ok
    string intToRoman(int num){
        int value[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for(int i = 0; i < 13; i++){
            while(num / value[i]){
               ans += roman[i];
               num -= value[i];
            }
        }
        return ans;
    }
};
