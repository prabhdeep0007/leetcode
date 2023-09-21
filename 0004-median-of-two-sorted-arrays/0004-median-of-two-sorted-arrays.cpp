class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        int ind1=(n+m)/2-1,ind2=(n+m)/2;
        int ele1=0,ele2=0;
        int idx=0;
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                 if(idx==ind1)
                 {
                  ele1=nums1[i];   
                 }
                if(idx==ind2)
                {
                    ele2=nums1[i];
                }
                i++;
                idx++;
            }
            else
            {
                if(idx==ind1)
                 {
                  ele1=nums2[j];   
                 }
                if(idx==ind2)
                {
                    ele2=nums2[j];
                }
                j++;
                idx++;
            }
        }
        while(i<n)
        {
                if(idx==ind1)
                 {
                  ele1=nums1[i];   
                 }
                if(idx==ind2)
                {
                    ele2=nums1[i];
                }
                i++;
                idx++;
        }
        while(j<m)
        {
            if(idx==ind1)
                 {
                  ele1=nums2[j];   
                 }
                if(idx==ind2)
                {
                    ele2=nums2[j];
                }
                j++;
                idx++; 
        }
        if((n+m)%2==0) return (double)(ele1+ele2)/2;
        return ele2;
    }
};