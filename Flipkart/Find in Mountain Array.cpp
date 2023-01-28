//Leetcode 1095
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
/*
The array is divided into two parts->increasing and decreasing subarray, find the peak element then do binary search on two subarrays
*/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        //1. finding the peak element
        int left=0, right=arr.length()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(arr.get(mid)<arr.get(mid+1)) left=mid+1;
            else right=mid;
        }
        int peak=left;

        //2.binary search on increasing subarray
        left=0,right=peak;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr.get(mid)<target) left=mid+1;
            else if(arr.get(mid)>target) right=mid-1;
            else return mid; //found the answerindex
        }

        //3.binary search on decreasing subarray
        left=peak,right=arr.length()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr.get(mid)<target) right=mid-1;
            else if(arr.get(mid)>target) left=mid+1;
            else return mid;//found the answerindex
        }

        return -1;//not finding the element so return -1
    }
};
