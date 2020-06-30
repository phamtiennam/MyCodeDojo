def isPalindromePermutation(s: str) -> bool:
     dic={}
     count=0
     s=s.lower().strip()
 
     for c in s:
         if c in dic:
             dic[c] += 1
         else:
             dic[c] = 1

     for key,value in dic.items():
         if(value%2 != 0):
              count += 1

     return count <= 1

isPalindromePermutation("Tact Coa")
