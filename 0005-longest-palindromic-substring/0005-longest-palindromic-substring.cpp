class Solution {
public:
    void Length(string &s, int i, int j, int &x, int &y, int &maxLength){
        
        
        while(i>=0&&j<s.size()&&s[i]==s[j]){
            
            if(j-i+1>maxLength){
                maxLength=j-i+1;
                x=i;
                y=j;
            }
            
            i--;
            j++;
        }
       
        
    }
    
    
    string longestPalindrome(string s) {
        //neetcode c++
        int n=s.size();
        int x=0,y=0;
        int maxLength=0;
        for(int i=0;i<n;i++){
            Length(s,i,i,x,y,maxLength);
            Length(s,i,i+1,x,y,maxLength);
        }
        string ans="";
        for(int i=x;i<=y;i++) ans+=s[i];
        return ans;
        
    }
};