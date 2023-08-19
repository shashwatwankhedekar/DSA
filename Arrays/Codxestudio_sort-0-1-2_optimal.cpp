//https://www.codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
   int low=0, mid=0, high = n-1;
   while(mid <= high){
       if(arr[mid] == 0){
           swap(arr[low], arr[mid]);
           low++;
           mid++;
       }
       else if(arr[mid] == 1){
           mid++;
       }
       else
       {
           swap(arr[mid], arr[high]);
           high--;
       }
   }
}
