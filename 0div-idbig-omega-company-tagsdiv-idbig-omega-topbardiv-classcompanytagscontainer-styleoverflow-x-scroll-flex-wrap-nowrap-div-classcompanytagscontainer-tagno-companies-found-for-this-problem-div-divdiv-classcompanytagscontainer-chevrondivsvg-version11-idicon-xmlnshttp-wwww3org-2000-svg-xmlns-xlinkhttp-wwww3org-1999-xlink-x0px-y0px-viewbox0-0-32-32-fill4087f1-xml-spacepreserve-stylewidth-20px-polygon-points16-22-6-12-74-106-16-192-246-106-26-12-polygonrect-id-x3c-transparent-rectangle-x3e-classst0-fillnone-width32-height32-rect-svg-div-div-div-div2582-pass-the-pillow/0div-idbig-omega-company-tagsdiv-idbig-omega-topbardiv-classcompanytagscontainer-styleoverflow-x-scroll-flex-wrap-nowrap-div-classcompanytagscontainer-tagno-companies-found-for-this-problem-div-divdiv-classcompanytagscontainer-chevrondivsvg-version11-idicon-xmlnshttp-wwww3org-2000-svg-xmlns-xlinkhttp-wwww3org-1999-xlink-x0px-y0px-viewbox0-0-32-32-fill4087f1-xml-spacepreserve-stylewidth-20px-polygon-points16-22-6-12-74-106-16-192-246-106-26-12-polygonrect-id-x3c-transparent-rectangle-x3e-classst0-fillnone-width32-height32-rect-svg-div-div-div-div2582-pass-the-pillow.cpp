class Solution {
public:
    int passThePillow(int n, int time) {
     bool f=true;
     int i=1;
     while(time--)
     {
         if(f) i++;
         else i--;
         if(i==n) f=false;
         if(i==1) f=true;
     }
    return i;
    }
};