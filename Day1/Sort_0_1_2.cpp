/*

Approach 1: Using any basic sorting algorithm.

Approach 2: Since the array contains only 3 elements (i.e 0, 1 and 2), we can do a basic counting sort

Approach 3: Most optimised approach -> Dutch National Flag algorithm (code below)

*/

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
   while(mid <= high) {
       if(arr[mid] == 0) {
           swap(arr[low], arr[mid]);
           low++;
           mid++;
       }
       else if(arr[mid] == 1) {
           mid ++;
       }
       else{
           swap(arr[mid], arr[high]);
           high --;
       }
   }
    
}
