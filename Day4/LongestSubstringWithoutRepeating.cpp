//Leetcode Problem #3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp; //element -> last occurence of the element
        int n = s.size();
        int len = 0;
        int left = 0, right = 0;
        
        while(left < n && right < n) {
            //when the current character is not present in the map
            if(mpp.find(s[right]) == mpp.end()){
                //updating the map (element ---> last index of its occurence)
                 mpp[s[right]] = right;
            }
            //when the current character is already present in the map
            else{
                //if the last occurence of the current element is before the current window range
                //no need to update the value of left, just update the last index of the current element in the map
                if(mpp[s[right]] < left){
                     mpp[s[right]] = right;
                }
                //update the position of left, of the new sliding window range & also update the last index of the current element in the map
                else{
                     left = mpp[s[right]] + 1;
                     mpp[s[right]] = right;
                }
            }
            
            len = max(len, right-left+1);
            right ++;
        }
        
        return len;
    }
};
