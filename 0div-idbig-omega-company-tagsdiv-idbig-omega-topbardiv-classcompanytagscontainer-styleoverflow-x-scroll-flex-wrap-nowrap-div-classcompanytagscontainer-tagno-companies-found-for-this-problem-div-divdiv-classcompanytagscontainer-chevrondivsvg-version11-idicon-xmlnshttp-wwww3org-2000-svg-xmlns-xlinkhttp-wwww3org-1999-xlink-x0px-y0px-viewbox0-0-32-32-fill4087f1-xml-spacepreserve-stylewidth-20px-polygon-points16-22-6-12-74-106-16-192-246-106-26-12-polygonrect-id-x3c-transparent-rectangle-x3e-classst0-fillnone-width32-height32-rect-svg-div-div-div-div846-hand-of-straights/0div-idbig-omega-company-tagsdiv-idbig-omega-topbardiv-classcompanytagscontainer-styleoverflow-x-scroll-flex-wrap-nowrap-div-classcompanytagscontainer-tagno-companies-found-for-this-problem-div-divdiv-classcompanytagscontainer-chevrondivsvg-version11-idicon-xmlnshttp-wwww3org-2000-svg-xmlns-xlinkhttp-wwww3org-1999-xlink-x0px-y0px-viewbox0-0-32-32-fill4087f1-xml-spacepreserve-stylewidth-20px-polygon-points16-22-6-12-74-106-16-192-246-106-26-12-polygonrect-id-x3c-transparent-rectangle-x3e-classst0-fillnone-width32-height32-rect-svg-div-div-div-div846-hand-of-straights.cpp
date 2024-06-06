class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        if(hand.size()%groupSize) return false;
        for(int i=0;i<hand.size();i++)
        {
            m[hand[i]]++;
        }
        int temp=hand.size()/groupSize;
        while(temp)
        {
         auto it=m.begin();
        m[it->first]--;
         for(int i=1;i<groupSize;i++)
         {
             if(m.find(it->first+i)==m.end()) return false;
             else
             {
                 m[it->first+i]--;
                 if(m[it->first+i]==0) m.erase(it->first+i);
             }
         }
        if(m[it->first]==0) m.erase(it->first);
         temp--;
        }
        return true;
    }
};