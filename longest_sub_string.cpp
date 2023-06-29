/**
 * @file longest_sub_string.cpp
 * @brief 
 * @version 0.1
 * @date 2023-06-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * 
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int lengthOfLongestSubstring(string &s) {
    if(s.empty()){
        return 0;
    }

    unordered_set<char> charSet;

    int left = 0;
    int right = 0;
    int maxSubLength = 0;
    const int len = s.length();
    while(right < len){
        char ch = s[right];
        if(charSet.find(ch) == charSet.end()){ //not found
            charSet.insert(ch);

            int curLength = right - left + 1;
            if(curLength >= maxSubLength){
                maxSubLength = curLength;
            }

            right++;
        }else{
            ch = s[left];
            charSet.erase(ch);
            left++;
        }
    }//end while
    return maxSubLength;
}

int main(){

    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}