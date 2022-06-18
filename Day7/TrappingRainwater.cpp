#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    int left = 0;
    int right = n-1;
    long maxWater = 0;
    long maxleft = 0;
    long maxright = 0;
    while(left <= right) {
        if(height[left] <= height[right]) {
            if(maxleft <= height[left]) {
                maxleft = height[left];
            }
            else {
                maxWater += (maxleft - height[left]);
            }
            left ++;
        }
        else {
            if(maxright <= height[right]) {
                maxright = height[right];
            }
            else {
                maxWater += (maxright - height[right]);
            }
            right --;
        }
    }
    return maxWater;
}
