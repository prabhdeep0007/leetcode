/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(MountainArray &mountainArr,int &n)
    {
        int l=0,h=n-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(m==0) m=m+1;
            if(m==n-1) m=m-1;
            int ele=mountainArr.get(m);
            if(ele>mountainArr.get(m-1) && ele< mountainArr.get(m+1))l=m+1;
             else if(ele<mountainArr.get(m-1) && ele>mountainArr.get(m+1)) h=m-1;
            else return m;
        }
        return -1;
    }
    int findtargetinleft(MountainArray &mountainArr,int l,int h,int target)
    {
      while(l<=h)
      {
          int m=(l+h)/2;
          int ele=mountainArr.get(m);
          if(ele>target) h=m-1;
          else if(ele<target) l=m+1;
          else return m;
      }
        return -1;
    }
    int findtargetinright(MountainArray &mountainArr,int l,int h,int target)
    {
        while(l<=h)
      {
          int m=(l+h)/2;
          int ele=mountainArr.get(m);
          if(ele<target) h=m-1;
          else if(ele>target) l=m+1;
          else return m;
      }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
       int n=mountainArr.length();
        int peak=findpeak(mountainArr,n);
        int left=findtargetinleft(mountainArr,0,peak,target);
        if(left!=-1) return left;
        int right=findtargetinright(mountainArr,peak,n-1,target);
        if(right!=-1) return right;
        return -1;
    }
};