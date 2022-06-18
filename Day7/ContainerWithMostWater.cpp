int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n-1;
    int maxi = 0;
    while(left < right) {
        if(height[left] < height[right]) {
            maxi = max(maxi, (right - left) * height[left]);
            left ++;
        }
        else {
            maxi = max(maxi, (right - left) * height[right]);
            right --;
        }
    }
    return maxi;
}
