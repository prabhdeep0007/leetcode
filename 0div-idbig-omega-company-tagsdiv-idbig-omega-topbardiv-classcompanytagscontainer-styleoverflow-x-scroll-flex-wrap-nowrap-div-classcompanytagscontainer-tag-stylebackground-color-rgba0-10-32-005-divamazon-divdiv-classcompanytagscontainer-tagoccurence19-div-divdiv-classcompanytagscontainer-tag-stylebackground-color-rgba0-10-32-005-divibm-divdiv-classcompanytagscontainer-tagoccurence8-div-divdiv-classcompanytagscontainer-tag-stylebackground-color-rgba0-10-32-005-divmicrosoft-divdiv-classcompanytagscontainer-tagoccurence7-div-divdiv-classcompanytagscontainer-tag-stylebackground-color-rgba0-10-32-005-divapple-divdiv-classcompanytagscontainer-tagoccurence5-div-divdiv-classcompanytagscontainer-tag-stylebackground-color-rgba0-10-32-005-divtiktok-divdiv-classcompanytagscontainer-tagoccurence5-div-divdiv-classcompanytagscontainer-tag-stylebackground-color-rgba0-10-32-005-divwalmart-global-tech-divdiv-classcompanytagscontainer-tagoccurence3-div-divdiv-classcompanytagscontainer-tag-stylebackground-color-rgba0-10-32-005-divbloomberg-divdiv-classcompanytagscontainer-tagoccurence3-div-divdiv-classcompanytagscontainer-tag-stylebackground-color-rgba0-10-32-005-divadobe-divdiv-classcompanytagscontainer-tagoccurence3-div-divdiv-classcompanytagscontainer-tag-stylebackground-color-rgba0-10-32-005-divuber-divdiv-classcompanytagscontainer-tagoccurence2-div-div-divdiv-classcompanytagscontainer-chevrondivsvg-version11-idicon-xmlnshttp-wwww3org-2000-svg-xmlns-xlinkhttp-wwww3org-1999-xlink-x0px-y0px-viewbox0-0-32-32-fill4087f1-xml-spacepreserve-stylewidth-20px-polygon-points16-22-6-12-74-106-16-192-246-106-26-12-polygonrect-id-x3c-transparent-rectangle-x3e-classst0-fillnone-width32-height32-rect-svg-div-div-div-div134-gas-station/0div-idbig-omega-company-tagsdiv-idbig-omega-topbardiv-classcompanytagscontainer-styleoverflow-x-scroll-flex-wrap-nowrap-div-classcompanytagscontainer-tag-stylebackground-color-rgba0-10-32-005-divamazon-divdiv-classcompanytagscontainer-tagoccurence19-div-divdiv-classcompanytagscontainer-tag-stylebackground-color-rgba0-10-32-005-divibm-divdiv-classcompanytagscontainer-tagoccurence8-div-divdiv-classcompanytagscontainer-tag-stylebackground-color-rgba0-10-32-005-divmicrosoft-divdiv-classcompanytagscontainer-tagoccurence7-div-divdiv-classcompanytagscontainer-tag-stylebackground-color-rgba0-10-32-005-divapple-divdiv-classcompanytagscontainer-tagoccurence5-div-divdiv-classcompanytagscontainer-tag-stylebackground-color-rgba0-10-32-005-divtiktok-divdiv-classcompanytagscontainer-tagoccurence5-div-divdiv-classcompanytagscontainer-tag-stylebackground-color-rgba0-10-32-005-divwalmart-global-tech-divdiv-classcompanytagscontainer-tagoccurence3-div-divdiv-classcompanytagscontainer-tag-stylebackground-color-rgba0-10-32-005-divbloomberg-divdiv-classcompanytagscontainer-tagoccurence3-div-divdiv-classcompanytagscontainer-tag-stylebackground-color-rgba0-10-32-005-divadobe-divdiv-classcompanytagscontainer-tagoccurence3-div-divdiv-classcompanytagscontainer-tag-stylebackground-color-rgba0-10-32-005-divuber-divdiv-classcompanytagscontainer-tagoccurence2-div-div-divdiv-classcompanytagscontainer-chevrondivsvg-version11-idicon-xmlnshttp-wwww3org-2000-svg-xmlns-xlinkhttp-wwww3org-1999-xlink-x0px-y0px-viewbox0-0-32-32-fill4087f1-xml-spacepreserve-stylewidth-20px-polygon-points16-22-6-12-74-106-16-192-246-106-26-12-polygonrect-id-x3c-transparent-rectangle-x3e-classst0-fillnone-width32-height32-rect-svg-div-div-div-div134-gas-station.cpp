class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        int count=0;
        int sum=0;
        int si=0;
        for(int i=0;i<2*n;i++){
            int c=gas[i%n]-cost[i%n];
            sum+=c;
            if(sum<0){
                sum=c>=0?c:0;
                count=c>=0?1:0;
                si=c>=0?i%n:i%n+1;
            }
            else{
                count++;
                if(count==n)
                    return si;
            }
            
            
            
        }
        
        return -1;
        
        
        
    }
};