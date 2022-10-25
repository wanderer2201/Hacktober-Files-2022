// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> idkw;
        if(x<0) return false;
        int temp=x;
        while(temp){
            idkw.push_back(temp%10);
            temp/=10;
        }
        int l=0,r=idkw.size()-1;
        while(l<r){
            if(idkw[l]!=idkw[r]) return false;
            l++;r--;
        }
        return true;
    }
};
