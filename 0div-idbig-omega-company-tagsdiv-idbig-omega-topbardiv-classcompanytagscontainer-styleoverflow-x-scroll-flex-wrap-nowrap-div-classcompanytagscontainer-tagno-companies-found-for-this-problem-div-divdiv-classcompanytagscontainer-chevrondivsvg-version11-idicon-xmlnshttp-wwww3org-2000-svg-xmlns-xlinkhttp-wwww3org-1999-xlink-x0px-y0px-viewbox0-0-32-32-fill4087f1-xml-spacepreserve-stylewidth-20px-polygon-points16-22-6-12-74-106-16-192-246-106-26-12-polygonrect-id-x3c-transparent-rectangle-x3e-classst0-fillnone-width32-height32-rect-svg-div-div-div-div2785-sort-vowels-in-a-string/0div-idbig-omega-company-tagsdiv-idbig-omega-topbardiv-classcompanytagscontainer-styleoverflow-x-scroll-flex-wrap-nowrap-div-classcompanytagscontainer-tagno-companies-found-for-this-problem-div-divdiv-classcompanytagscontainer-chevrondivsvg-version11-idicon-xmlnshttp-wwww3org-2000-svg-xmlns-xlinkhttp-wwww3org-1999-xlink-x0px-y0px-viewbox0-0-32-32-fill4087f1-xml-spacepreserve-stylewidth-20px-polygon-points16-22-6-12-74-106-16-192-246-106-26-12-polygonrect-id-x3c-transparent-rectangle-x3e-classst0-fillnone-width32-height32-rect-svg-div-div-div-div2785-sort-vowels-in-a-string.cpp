class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u' || c=='A'|| c=='E'|| c=='I'||c=='O'|| c=='U') return true;
        return false;
    }
    string sortVowels(string s) {
     vector<char> vowel; 
        int n=s.size();
     for(int i=0;i<n;i++)
     {
      if(isvowel(s[i])) vowel.push_back(s[i]);   
     }
       int j=0;
        sort(begin(vowel),end(vowel));
        string ans="";
        for(int i=0;i<n;i++)
        {
           if(isvowel(s[i]))
           {
               ans+=vowel[j];
               j++;
           }
           else ans+=s[i];
        }
        return ans;
        
    }
};