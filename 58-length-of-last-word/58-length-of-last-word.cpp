class Solution {
public:
    /*
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
    */
    
    
    int lengthOfLastWord(string s) {
        
        int len = 0;
        
        for(int i = s.length()-1; i>=0; i--)
        {
            if(s[i] != ' ')
                len++;
            else if(len > 0)
                return len;
        }
        
        return len;
    }
};