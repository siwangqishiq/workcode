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
#include <vector>

using namespace std;

void doMove(vector<int> &nums , int start){
    int index = start + 1;
    while(index < nums.size()){
        if(nums[index] == 0){
            break;
        }

        int tmp = nums[index];
        nums[index] = nums[index - 1];
        nums[index - 1] = tmp;

        index++;
    }//end while
}

void moveZeroes(vector<int>& nums){
    for(int i = nums.size() -1 ; i>=0 ;i--){
        if(nums[i] == 0){
            doMove(nums , i);
        }
    }//end for i
}

int main(){
    vector<int> nums = {0};
    moveZeroes(nums);
    for(auto &v : nums){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}