/*     [Leetcode] 438. Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> valList = new ArrayList();
        int[] smap = new int[26];
        int[] pmap = new int[26];
        if(s.length() < p.length())
            return valList;
        
        for(int i=0;i<p.length();i++){
            smap[s.charAt(i) -'a']++;
            pmap[p.charAt(i) -'a']++;
        }
        if(matches(smap,pmap))
            valList.add(0);
        for(int i=0; i < s.length() - p.length();i++)
        {
            smap[s.charAt(i+p.length())-'a']++;
            smap[s.charAt(i)-'a']--;
            if(matches(smap,pmap))
                valList.add(i+1);
        }
        return valList;      
    }
    public boolean matches(int[] smap,int[] pmap){
        for (int i=0;i<26;i++){
           if(smap[i] != pmap[i])
               return false;
        }
        return true;
        
    }
}

/*

To see more coding interview questions like this -> Find me at

Facebook:
        https://www.facebook.com/PracticeCoding/

Instagram:
       https://www.instagram.com/techtripshd/

*/
