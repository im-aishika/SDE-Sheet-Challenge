#include<bits.stdc++.h>
using namespace std;

class Solution {
  public:
    int subarraysXor(vector<int> &arr, int x) {
      int xxor = 0;
      int cnt = 0;
      unordered_map<int, int> mpp;
      for(auto it: arr) {
        xxor = xxor ^ it;
        if(xxor == x) {
          cnt ++;
        }
        if(mpp.find(xxor ^ x) != mpp.end()) {
          cnt += mpp[xxor ^ x];
        }
        mpp[xxor] += 1;
      }
      return cnt;
    }
}
