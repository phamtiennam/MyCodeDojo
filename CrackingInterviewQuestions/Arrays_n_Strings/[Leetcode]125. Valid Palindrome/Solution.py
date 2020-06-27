class Solution(object):
    def isPalindrome(self, s):
        s=s.lower()
        if not s:
            return 1
        left,right = 0,len(s) - 1
        while left < right :
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
            if(s[left] != s[right]):
                return 0
            left += 1
            right -= 1
        return 1
        
