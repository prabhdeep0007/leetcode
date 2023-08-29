class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int score=0,maxscore=0,ans=0;
        for(int i=0;i<n;i++)
        {
            score+= customers[i]=='Y'?+1:-1;
            if(score>maxscore)
            {
                maxscore=score;
                ans=i+1;
            }   
        }
        return ans;
    }
};