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

//LeetCode 3.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 1)
        {
            return 0;
        }
        int maxlen = 0;
        int begin=0;  //从begin到i的字符串中若有重复就将begin前进一位
        for(int i=0; i < s.size(); ++i)
        {
            if(isnotrepeat(s, s[i], begin, i))
            {
                if(i-begin+1 > maxlen)
                { //判断目前无重复串的长度是不是最长的，若是则用maxlen记录它
                    maxlen = i-begin+1;
                }
            }
            else
            {
                while(!isnotrepeat(s,s[i],begin,i))
                { //一直处理，直到下标从begin到i的字符串中无重复字符串为止
                    begin++;    
                }
            }
        }
        return maxlen;
    }
    bool isnotrepeat(string s,char c, int begin,int end)
    { //判断一个字符串序列中是否和目标字符c重复的
        for(int i=begin; i<end; ++i)
        {
            if(s[i] == c)
            {
                return false;
            }
        }
        return true;
    }
};

//LeetCode 4.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1+len2;
        int k = len/2;
        assert(len > 0);
        if(len & 1 != 0)
        {//奇数 ---中位数
            return findkthnum(nums1,0,len1,nums2,0,len2,k + 1);
        }
        else
        {//偶数 ---两中位数的平均值
            return ( findkthnum(nums1,0,len1,nums2,0,len2,k) +
                        findkthnum(nums1,0,len1,nums2,0,len2,k + 1) )/2;
        }
    }
    
    double findkthnum(vector<int> &num1,int begin1,int len1,vector<int>&num2,int begin2,int len2, int k)
    {//寻找第k小的元素
       if(len1 > len2)
       { // 保持nums1，长度小于nums2  --- 为了操作的方便
          return findkthnum(num2,begin2,len2,num1,begin1,len1,k);
       }
       int pa = min(k/2,len1);  //vector
       int pb = k -pa;
       //特殊情况：
       if(len1 == 0)
       { //num1的整个数组的元素都不在中位数范围内，那么中位数可以直接得出了，此时num2的中位数即为所求中位数
           return num2[begin2 + k -1];
       }
       else if(k==1)
       { //此时说明中位数已经可以找到了，前面已经淘汰好了，当前最小的一个值即为所求中位数
           return min(num1[begin1],num2[begin2]);
       }
       //正常情况：
       if(num1[begin1 + pa-1] < num2[begin2 + pb-1])
       { //淘汰num1的前面的pa个
           return findkthnum(num1,begin1+pa,len1-pa,num2,begin2,len2,k-pa);
       }
       else if(num1[begin1 + pa-1] > num2[begin2 + pb-1])
       { //淘汰num2的前pb个数据
           return findkthnum(num1,begin1,len1,num2,begin2+pb,len2-pb,k-pb);
       }
       else
       {// 两者相等，两者都是中位数，返回一个即可 num1[pa-1] == num2[pb-1]
           return num1[begin1 + pa-1];
       }
    }
};

//LeetCode 5.
class Solution {
public:
    string longestPalindrome(string s) {
        //思路：从每个节点依次向左或者向右分析，找到子回文串
        string ret;
        int slen = s.size();
        int maxlen = 1; //表示长度
        int pos = 0; //表示开始位置
        
        for(int i=0; i < slen; ++i)
        {
            int left = i;
            int right = i;
            int len = 0;
        
            while(left>0 && right<(slen-1) && s[left-1] == s[right+1])
            {//例如 aba
                --left;
                ++right;
                len+=2;
            }
            if(len+1 > maxlen)
            {
                maxlen = len+1; //奇数个
                pos = left;
            }
          
            left = i;
            right = i+1;
            len = 0;
            while(left>=0 && right<slen && s[left] == s[right])
            {//例如abba
                ++right;
                --left;
                len += 2;
            }
            
            if(len > maxlen)
            {
                maxlen = len;  //偶数个
                pos = left+1;
            }
        }
            
        for(int j=0; j<maxlen ;++j)
        {
            ret.push_back(s[j+pos]);
        }
        return ret;
    }
};

//LeetCode 6.
class Solution {
public:
    string convert(string s, int numRows) {
        int slen = s.size();
        string ret;
        if(slen <= 0 || numRows < 1)
        {
            return ret;
        }
        int row = numRows;
        if(row == 1)
        {//row=1的时候单独处理一下
            for(int i=0; i<slen;++i)
            {
                //cout<<s[begin];
                ret.push_back(s[i]);
            }
            return ret;
        }
        for(int i = 0; i < row; ++i)
        {
            if(i==0 || i == (row-1) )
            {//第一层和最后一层
                int begin = i;
                while(begin < slen)
                {//row=1的时候无法跳出循环的，所以上面单独处理了row=1的情况
                    //cout<<s[begin];
                    ret.push_back(s[begin]);
                    begin += 2*(row-1);
                }
            }
            else
            {
                int begin = i;
                while(begin  < slen)
                {
                    //cout<<s[begin];
                    ret.push_back(s[begin]);
                    begin += 2*(row-i-1);
                    if(begin >= slen)
                    {   
                        break;
                    }
                    //cout<<s[begin];
                    ret.push_back(s[begin]);
                    begin += 2*i;
                }
            }
        }
        return ret;
    }
};

//LeetCode 7.
class Solution {
public:
	int reverse(int x) {
		bool flag = false;  //正负
		int maxvalue = pow(2, 31) - 1; //防止溢出
		int minvalue = pow(2, 31);
		if (x > maxvalue || x < minvalue*(-1))
		{ return 0; }
		
		if (x < 0)
		{ flag = true; }
		
		int newx = 0;
		while (x)
		{
			if ( (!flag && newx > maxvalue / 10) || (flag && newx < minvalue / 10) )
			{
				newx = 0;
				break;
			}
			newx = newx * 10 + x % 10;
			x /= 10;
		}
		
		if (flag)
		{ return flag*newx; }
		
		return newx;
	}
};

