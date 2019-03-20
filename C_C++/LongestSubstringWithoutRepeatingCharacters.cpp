/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //create a ASCII Table aray for 256 characters.Each character has its index
        //For example arr['a']=arr[97]
        //The initial value for each element of the array is -2
        int arr[256];
        for(int i=0;i<256;i++)
            arr[i]=-2;
        
        int curlen=0;
        int longest=0;
        
        if(s.size()==0)
            return 0;
       
        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i]] == -2)
            {
                arr[s[i]]=i; //store index of s[i] in array
                curlen++;
            }
            else
            {
                if(longest<curlen){
                    longest=curlen;
                }
                curlen=i-arr[s[i]];
                arr[s[i]]=i;
            }
        }
        if(longest<curlen){
            longest=curlen;
        }
        return longest;
        
    }
};