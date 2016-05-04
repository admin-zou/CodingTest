/*
    这里记录了我在写LeetCode算法题的代码，LeetCode上的题目听说很不错，所以左边自己去体验一下，这里只记录了代码，具体的思路没有细说，
  因为有些题目是需要画图分析的，所以我将解题思路以博客的形式写出了，如果你觉得有些代码看不懂，那么你可以去看看我的博客，博客地址：
  URL：  http://blog.csdn.net/column/details/myleetcodetesting.html
*/


// LeetCode 1.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i=0; i<nums.size(); ++i)
        {
            int first = nums[i];
            for(int j=i+1; j < nums.size(); ++j)
            {
                int second = nums[j];
                if(first + second == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};

// LeetCode 2.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i=0; i<nums.size(); ++i)
        {
            int first = nums[i];
            for(int j=i+1; j < nums.size(); ++j)
            {
                int second = nums[j];
                if(first + second == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
