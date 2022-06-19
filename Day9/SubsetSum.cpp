void func(int i, int sum, vector<int> &nums, vector<int> &ds) {
    if(i == nums.size()){
        ds.push_back(sum);
        return;
    }
    //at every index I have the option of either picking the element or not 
    //case 1: pick the element
    func(i+1, sum + nums[i], nums, ds);
    
    //case 2: not pick the element
    func(i+1, sum, nums, ds);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ds;
    func(0, 0, num, ds);
    sort(ds.begin(), ds.end());
    return ds;
}
