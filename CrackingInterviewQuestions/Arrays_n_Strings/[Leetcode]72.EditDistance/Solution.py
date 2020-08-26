class Solution(object):
    def minDistance(self, word1, word2):
        m=len(word1)
        n=len(word2)
        return self.editDistance(word1,word2,m,n)
    def editDistance(self, word1, word2, m, n):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if m == 0:
            return n #insert n characters to become word2
        if n == 0:
            return m #delete m characters to become word2
        
        # If last characters of two strings are same.Ignore last characters and get count for remaining strings.
        if word1[m-1] == word2[n-1]:
            return self.editDistance(word1,word2,m-1,n-1)
        
        #recursively compute minimum cost for all three operations and take minimum of three values.
        return 1 + min(self.editDistance(word1,word2,m,n-1),
                       self.editDistance(word1,word2,m-1,n),
                       self.editDistance(word1,word2,m-1,n-1))
