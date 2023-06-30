/**
 * @file move_zeros.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * https://leetcode.cn/problems/move-zeroes/
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(int left , int right){
    string leftStr = to_string(left);
    string rightStr = to_string(right);

    if(leftStr.length() == rightStr.length()){
        return left > right;
    }

    int len = leftStr.length() <= rightStr.length()?leftStr.length():rightStr.length();
    for(int i = 0 ; i < len ; i++){
        if(leftStr[i] > rightStr[i]){
            return false;
        }
    }//end for i
    return leftStr.length() < rightStr.length();
}

string largestNumber(vector<int>& nums) {
    return "";
}

int main(){
    vector<int> nums = {3,30,34,5,9};
    sort(nums.begin() , nums.end() , compare);

    for(auto &v : nums){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}