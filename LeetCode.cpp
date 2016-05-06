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

//LeetCode 8.
class Solution {
public:
	int myAtoi(string str) {
		//+- 12  返回类型为整形，所以不用考虑小数点，遇到小数点就返回了
		int ret = 0;
		int len = str.size();
		if (len == 0)
		{
			return ret;
		}
		bool isminus = false; //正负号
		//int numofpoint=0; //小数点
		int i = 0;
		while (str[i] == ' ')
		{//处理空格
			++i;
		}
		if (str[i] == '-')
		{//开始为 - 符合
			isminus = true;
			i++;
		}
		else if (str[i] == '+')
		{//开始为 + 符合要求
			i++;
		}
		//处理完正负了
		while (i < len)
		{//越界问题，
			if (str[i] >= '0' && str[i] <= '9')
			{//正常数字
			    if (ret > 214748364 && !isminus)
				{//乘以10后越界
					return 2147483647;
				}
				else if (ret > 214748364 && isminus)
				{//乘以10后越界
					return 2147483648;
				}
				ret = ret * 10 + str[i] - '0';
				if (ret >= 2147483647 && !isminus)
				{//加上str[i]后越界
					return 2147483647; //最大整数
				}
				else if (ret >= 2147483648 && isminus)
				{//加上str[i]后越界
					return 2147483648; //最小负整数
				}
				else if (ret < 0 && isminus)
				{
					return 2147483648;
				}
				++i;
			}
			else
			{//不是正常数字
				break;
			}

		}

		if (isminus)
		{//负数
			return ret*(-1);
		}
		else if (ret < 0 && !isminus)
		{
			return 2147483647;
		}
		return ret;
	}
};

//LeetCode 9.
class Solution {
public:
    bool isPalindrome(int x) {
            if( x < 0 )
            {//负数不是回文数
                return false;
            }
            
            int tmp = x;
            int ret = 0;
            while(tmp)
            {//思路是：将回文数字倒序，若何原来的数字相同则是，否则不是。
                ret = ret * 10 + tmp%10;
                tmp/=10;
            }
            
            if(ret == x)
            {
                return true;
            }
        
            return false;
    }
};

//LeetCode 10.
class Solution {
public:
    bool isMatch(string s, string p) {
    //s是主串，p是模式串，拿p去和s匹配;若p为".*"的时候，s无论为什么都可以匹配。
        //if(p.size() == 2 && p[0]=='.' && p[1] == '*')
        //{
        //    return true;
        //}
        //上面的我注释掉的原因是因为，下面的逻辑可以处理上面的，而且我们不能保证p后面有没有空格，所以以上考虑不全面，不可取。
        return match(s.c_str(),p.c_str());
    }
    bool match(const char *s, const char *p)
    {
        if(*s == '\0' && *p == '\0')
        {//两者都结尾了，肯定匹配了 
            return true; 
        }
        if(*p == '\0')
        {//s没有到结尾，但是p到结尾了，false
            return false; 
        }
        //s结束了但是p没有结束，这种情况怎么考虑呢，还是挺复杂的，例如 ""和".*"等情况
        if(*(p+1) == '*')
        {//p的第二个位置上遇到了‘*’  ----> 可以匹配 0个，1个或者多个字符   这样只能递归去测试了
            if((*p == *s) || *p=='.' && *s!='\0')
            {//可以匹配     0个，         或1个            或者多个
                return match(s,p+2) || match(s+1,p+1) || match(s+1,p);
            }
            else
            {//只能匹配0个了
               return match(s,p+2); 
            }
        }
        //没有遇到‘*’
        if( (*p == *s) || (*p == '.' && *s != '\0') )
        {//以上两种情况都做如下处理
            return match(s+1,p+1);
        }
        //s结束了，p没有结束但是却又无法匹配，false
        return false;
    }
};

//LeetCode 11.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int num = height.size(); 
        if(num < 2)
        {
            return 0;
        }
        int maxcontain = 0;
        /*
          从两边向中间逼近，设wid = end -begin ， high = min(height[begin,end]) ，那么最大容量为contain = wid*high 
          要想contain最大，那么wid和high都要尽量的大才能保证，所以我决定采用从两边向中间逼近的方法去测试wid和high的
          乘积的最大值，这样时间复杂度比较小，想一想两个for循环的写法，真的很低效。
        */
        int begin =0;
        int end = num-1;
        while(begin < end)
        {
            int tmp = (end-begin)*min(height[begin],height[end]);
            maxcontain = maxcontain > tmp ? maxcontain:tmp;
            if(height[begin] >= height[end])
            {
                --end;
            }
            else
            {
                ++begin;
            }
        }
        return maxcontain;
    }
};

//LeetCode 12
class Solution {
public:
    string intToRoman(int num) {
     // I(1)    V(5)    X(10)   L(50)   C(100)  D(500)  M(1000)
     //范围 1~3999
        string ret;
        if(num < 1 || num > 3999)
         {
             return ret;
         }
         
       
        if(num >= 1000)
        {
             int numofM = num/1000;
             for(int i=0; i < numofM ;++i)
             {
                 ret.push_back('M');
             }
             num-=1000*numofM;
        }
             
        if(num >= 500)
        {
            if(num >=900)
            {//CM(900)
                ret+="CM";
                num-=900;
            }
            else
            {
                ret.push_back('D');
                num-=500;
            }
        }
             
            
        if(num >= 100)
        {
            if(num >= 400)
            {
                ret+="CD";
                num-=400;
            }
            else
            {
                int numofC = num/100;
                for(int i=0;i<numofC;++i)
                {
                     ret.push_back('C');
                }
                num-=numofC*100;
            }
        }
         
        if(num >= 50)
        {//XC(90)
            if(num>=90)
            {
                ret+="XC";
                num-=90;
            }
            else
            {
                ret.push_back('L');
                num-=50;
            }
        }
             
        if(num >= 10)
        {
            if(num >= 40)
            {
                ret+="XL";
                num-=40;
            }
            else
            {
                int numofX = num/10;
                for(int i = 0; i < numofX; ++i)
                {
                    ret.push_back('X');
                }
                num-=10*numofX;
            }
        }
             
        if(num >= 5)
        {
            if(num == 9)
            {//9(IX)
                ret+="IX";
                num-=9;
            }
            else
            {
                ret.push_back('V');
                num-=5;
            }
        }
             
        if(num >= 1)
        {
            if(num == 4)
            {//4(IV)
                ret+="IV";
            }
            else
            {
                for(int i=0; i < num; ++i)
                {
                     ret.push_back('I');
                }
            }
            num=0;
        }
        
        return ret;
    }
};

//LeetCode 13.
class Solution {
public:
    int romanToInt(string s) {
        //和上道题刚好相反
        int lastnum = 0;
        int len = s.size();
        if(len < 1)
        {
            return lastnum;
        }
        int i = 0;
        while( i < len)
        {
            switch(s[i])
            {
                case 'M': //1000
                        lastnum+=1000;
                        ++i;
                    break;
                case 'D': //500
                        lastnum+=500;
                        i++;
                    break;
                case 'C': //100
                {
                    if(i+1 <len && s[i+1] == 'M') //900
                    {
                        lastnum+=900;
                        i=i+2;
                    }
                    else if(i+1 <len && s[i+1] == 'D') //400
                    {
                        lastnum+=400;
                        i=i+2;
                    }
                    else //100
                    {
                        lastnum+=100;
                        ++i;
                    }
                    break;
                }
                case 'L':
                        lastnum+=50;
                        ++i;
                    break;
                case 'X':
                {
                    if(i+1 <len && s[i+1] == 'C')
                    {
                        lastnum+=90;
                        i=i+2;
                    }
                    else if(i+1 <len && s[i+1] == 'L')
                    {
                        lastnum+=40;
                        i=i+2;
                    }
                    else
                    {
                        lastnum+=10;
                        ++i;
                    }
                    break;
                }
                case 'V':
                {
                    lastnum+=5;
                    ++i;
                    break;
                }
                case 'I':
                {
                    if(i+1 <len && s[i+1] == 'X')
                    {
                        lastnum+=9;
                        i=i+2;
                    }
                    else if(i+1 <len && s[i+1] == 'V')
                    {
                        lastnum+=4;
                        i=i+2;
                    }
                    else
                    {
                        lastnum+=1;
                        ++i;
                    }
                    break;
                }
                default :
                    break;
            }
        }
        
        return lastnum;
    }
};

//LeetCode 14.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            //  最长公共前缀，就是从头开始找这个字符串数组里面有多少个公共的字符
            string ret;
            int numofstr = strs.size();
            if(numofstr == 0)
            {   
                return ret;
            }
            if(numofstr == 1)
            {
                return strs[0];
            }
            //最长公共前缀不可能超过字符串数组中最短的字符串的长度，所以有必要先找到这个最短的字符串
            int mpos = 0;
            for(int i=1; i<numofstr; ++i)
            {
                if(strs[i].size() < strs[mpos].size())
                {   mpos = i;   }
            }
            int maxlen = 0; //记录公共前缀的长度
            int msize = strs[mpos].size();
            bool flag = true; //用于标记么有出现公共字符，可直接退出，而不需要额外的对比
            for(int j=0; j<msize; j++)
            {
                char tmp = strs[mpos][j];
                flag = true;
                for(int k=0; k < numofstr; ++k)
                {
                    if(strs[k][j] != tmp)
                    {
                        flag = false;
                        break;
                    }
                }
                //如果中间出现不一致
                if(!flag)
                {
                    break;
                }
                //全部相同的话
                ++maxlen;
            }
            
            for(int v=0; v<maxlen ;++v)
            {
                ret.push_back(strs[mpos][v]);
            }
            
            return ret;
    }
};

//LeetCode 15.
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//三数之和为0，至少一个数小于0，至少一个数大于0  排序之后从两边向中间遍历
		vector<vector<int>> last;
		int len = nums.size();
		if (len < 3)
		{
			return last;
		}
	   //1.排序
		sort(nums.begin(), nums.end());
		/*
		 for (int i = 1; i<len; ++i)
		 {//插入排序时间复杂度为O(n^2),所以还是用vector自带的排序
		    int tmp = nums[i];
		    int begin = i - 1;
		    while (begin >= 0 && nums[begin] > tmp)
		    {
		        nums[begin + 1] = nums[begin];
		        --begin;
		    }
		    nums[begin + 1] = tmp;
		 }
        */
	   //2.从两边向中间遍历，最左边的数字加上最右边的数字，然后找数字中和他们的和
		for (int left = 0; left < len - 2 && nums[left] <=0 ; ++left)
		{
		    if(left > 0 && nums[left] == nums[left-1])
		    {//left 和 left-1 位置元素相等，但是第一次不能处理
		        continue;
		    }
			int lpos = left + 1;
			int rpos = 0;
			while (lpos < len-1)
			{ //尝试了好多次，实验结果证明lpos和rpos不能从两边向中间遍历，++lpos和--rpos的到底谁先执行无法确定，所以还得像暴力求解那样
			    if(lpos != left+1 && nums[lpos] == nums[lpos-1])
			    {//说明了此时left+1对应的值已经求出值了，需要处理掉相同的lpos值
			        ++lpos;
			        continue;
			    }
			    rpos = lpos+1;
				while (lpos < rpos && nums[left] + nums[lpos] + nums[rpos] <= 0)
				{
				    if (lpos < rpos && nums[left] + nums[lpos] + nums[rpos] == 0)
				    {
					    vector<int> tmp;
					    tmp.push_back(nums[left]);
					    tmp.push_back(nums[lpos]);
					    tmp.push_back(nums[rpos]);
					    last.push_back(tmp);
					    break;   //处理完后跳出本次循环
				    }
				    else if(rpos < len-1)
				    {
				        ++rpos;
				    }
				    else
				    {
				        break;
				    }
				}
				++lpos;   //执行到这里不要忘记了改变lpos的值，否则可能死循环
			}
		}
		return last;
	}
};

//LeetCode 16.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int gap = 0; //差距，即和target的接近程度
        int sum = 0;
        int len = nums.size(); //元素个数
        if(len < 3)
        {
            return -1;
        }
        //初始化gap
        sum = nums[0]+nums[1]+nums[2];
        gap = target > sum ? (target-sum):(sum-target);
        for(int begin = 0 ; begin < len-2; ++begin)
        {
            if(begin > 0 && nums[begin] == nums[begin-1])
            {
                ++begin;
                continue;
            }
            int pos1 = begin+1;
            while(pos1 < len-1)
            {
                int pos2 = pos1+1;
                while(pos2 < len)
                {
                    int tmpsum = nums[begin] + nums[pos1]+nums[pos2];
                    if(tmpsum == target)
                    {
                        return target;
                    }
                    else if(abs(tmpsum - target) < gap)
                    {
                        sum = tmpsum;
                        gap = abs(tmpsum - target);
                    }
                    ++pos2;
                }
                ++pos1;
            }
        }
        return sum;
    }
};

//LeetCode 17.
class Solution {
public:
	vector<string> letterCombinations(string digits)
	{//个人觉得输入不应该有非数字字符，
		//输入一系列数字，分别从每个数字对应的字符中依次选择一个构成字符串，
		vector<string> last;
		//去除数字字符'0'和'1',这样计算起来不麻烦,
		string newdig;
		for (int i = 0; i<digits.size(); ++i)
		{
			if (digits[i] >= '0' && digits[i] <= '9' && digits[i] != '0' && digits[i] != '1')
			{//就算非数字字符，我就将他过滤掉
				newdig.push_back(digits[i]);
			}
		}
		//存储数字对应的值
		vector<string> array = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		int len = newdig.size();
		if (len == 0)
		{
			return last;
		}
		for (int i = 0; i < array[newdig[0] - '0'].size(); ++i)
		{//第一个有字符数字的字符个数
			string tmp;
			tmp.push_back(array[newdig[0] - '0'][i]);
			addch(last, tmp, array, digits, 1, len);
		}
		return last;
	}

    //递归
	void addch(vector<string> &last, string tmp, vector<string>& arr, const string &newdig, int begin, int end)
	{
		if (begin == end)
		{
			last.push_back(tmp);
			return;
		}
		else
		{
			for (int i = 0; i < arr[newdig[begin] - '0'].size(); ++i)
			{
				tmp.push_back(arr[newdig[begin] - '0'][i]);
				addch(last, tmp, arr, newdig, begin + 1, end);
				tmp.pop_back();
			}
		}
	}
};

//LeetCode 18.
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > last;
		int len = nums.size();
		if (len < 4)
		{
			return last;
		}
		//1.排序
		sort(nums.begin(), nums.end());
		//遍历
		//特殊处理一下，若最小的四个数的和比target还大或者最大的四个数的和比target还大，那么我们直接退出
		if (nums[len - 1] + nums[len - 2] + nums[len - 3] + nums[len - 4] < target)
		{
			return last;
		}
		if (nums[0] + nums[1] + nums[2] + nums[3] > target)
		{
			return last;
		}
        //循环遍历，不能重复，那么必须得一个一个的试，因为排序了，所以情况的复杂性减少了很多
		for (int i = 0; i < len - 3; ++i)
		{ //1层
			while (i > 0 && nums[i] == nums[i - 1])
			{//处理重复数字，但是第一次遍历到的时候不能处理掉，否则可能错过一些解
				++i;
			}
			for (int j = i + 1; j<len - 2; ++j)
			{ //2层
				while (j > i + 1 && nums[j] == nums[j - 1])
				{//处理重复数字，但是第一次遍历到的时候不能处理掉，否则可能错过一些解
					++j;
				}
				int pos1 = j + 1;
				while (pos1 < len - 1)
				{ //3层
					while (pos1>j + 1 && nums[pos1] == nums[pos1 - 1])
					{//处理重复数字，但是第一次遍历到的时候不能处理掉，否则可能错过一些解
						++pos1;
					}
					int pos2 = pos1 + 1;
					while (pos2 < len && nums[i] + nums[j] + nums[pos1] + nums[pos2] < target)
					{
						++pos2;
					}
					if (pos2 == len)
					{
						++pos1;
						continue;
					}
					if (nums[i] + nums[j] + nums[pos1] + nums[pos2] == target)
					{
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[pos1]);
						tmp.push_back(nums[pos2]);
						last.push_back(tmp);
						++pos1;
						continue;
					}
					if (nums[i] + nums[j] + nums[pos1] + nums[pos2] > target)
					{//
						++pos1;
						continue;
					}
				}
			}
		}
		return last;
	}
};

//LeetCode 19.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //删除链表的倒数第n个节点，这个题的思路是快慢指针，快指针先走n步，然后快慢一起走
        if(head == NULL || n < 0)
        {
            return NULL;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        int m=n+1; //返回被删除位置的前一个位置
        while(fast && m)
        {
            fast=fast->next;
            --m;
        }
        if(m >1)
        {//链表的长度不够n,为什么控制条件要大于1呢，因为我找的是被删除节点的前一个节点
            return NULL;
        }
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        if(m == 1)
        {//删除的节点是头结点
            head = head->next;
            delete slow;
        }
        else
        {
            ListNode *toBedel = slow->next;
            slow->next=slow->next->next;
            delete toBedel;
        }
        return head;
    }
};

//LeetCode 20.
class Solution {
public:
    bool isValid(string s) 
    {
        int len=s.size();
        if(len == 0 )
        {
            return true;
        }
        //定义一个栈结构来实现判断
        stack<char> S;
        int begin = 0;
        while(begin < len)
        {
            if(s[begin] == '(' || s[begin] == '{' || s[begin] == '[')
            {
                S.push(s[begin]);
            }
            else if(s[begin] == ')' || s[begin] == '}' || s[begin] == ']' )
            {
                if(S.empty())
                { //此时栈空可以说明不匹配
                    return false;
                }
                char tmpch = S.top();
                if (s[begin] == ')' && tmpch == '('
					|| s[begin] == '}' && tmpch == '{'
					|| s[begin] == ']' && tmpch == '[')
                {
                    S.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            
            ++begin;
        }
        
        if(S.empty())
        {//全部匹配了栈才会为空
            return true;
        }
        return false;
    }
};

//LeetCode 21.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        //类似于从两个链表上取下节点，放到newHead中去
        if(l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode * newHead=NULL;
        if(l1->val <= l2->val)
        {
            newHead=l1;
            l1=l1->next;
        }
        else
        {
             newHead=l2;
             l2=l2->next;
        }
        newHead->next = NULL;
        ListNode *cur = newHead;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1=l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
            cur->next=NULL;
        }
        
        if(l1)
        {//说明 l2 完了，只剩 l1 了
            cur->next = l1;    
        }
        if(l2)
        {//说明 l1 完了，只剩 l2 了
            cur->next=l2;
        }
        
        return newHead;
    }
};

//LeetCode 22.

