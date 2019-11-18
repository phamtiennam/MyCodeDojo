class Solution {
public:
    int firstUniqChar(string s) {
        int array[26] = {};
        
        for(int i=0;i<s.length();i++)
        {
            array[s.at(i) - 'a'] += 1;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if (array[s.at(i) - 'a'] == 1)
                return i;
        }
        return -1;    
    }
};
