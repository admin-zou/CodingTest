/*
    这里记录了我在写LeetCode算法题的代码，LeetCode上的题目听说很不错，所以自己去体验了一下，这里只记录了代码，具体的思路没有细说，
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
class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> last;
		if (n <= 0)
		{
			return last;
		}
		int left = n - 1, right = n;
		string tmp = "(";
		//递归去发现符合条件的情况
		solve(last, tmp, left, right);
		return last;
	}
	
	void solve(vector<string>&last, string tmp, int left, int right)
	{
		if (left == 0)
		{
			while (right)
			{
				tmp.push_back(')');
				--right;
			}
			last.push_back(tmp);
			return;
		}
		tmp.push_back('(');
		solve(last, tmp, left - 1, right);
		if (right > left)
		{//只有这种情况下，才能给tmp的后面加上 ‘)’,否则不行
			tmp.pop_back();
			tmp.push_back(')');
			solve(last, tmp, left, right - 1);
		}
	}
};

//LeetCode 23.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        /*
            合并k个排序链表
            极端情况是n个只有一个节点的链表
            所以不能循环的去做，我想到了归并排序的方法
        */
        
        ListNode *list1;
        ListNode *list2;
        //归并排序
        int len = lists.size();
        if(len == 0)
        {
            return NULL;
        }
        if(len == 1)
        {
            return lists[0];
        }
        
        int mid=len/2;
        domerge(list1,lists,0,mid);
        domerge(list2,lists,mid+1,len-1);
        ListNode *newHead = merge(list1,list2);
        return newHead;
    }   
    
    void domerge(ListNode*& list,vector<ListNode*>&lists,int begin,int end)
    {
        if(begin > end)
        {
            list=NULL;
        }
        if(begin == end) 
        {//返回
            list=lists[begin];
        }
        
        if(end-begin == 1)
        {//合并
            list=merge(lists[begin],lists[end]);  
        }
        
        if(end-begin >1)
        {//继续二分
            int mid = begin+(end-begin)/2;
            ListNode *l1;
            ListNode *l2;
            domerge(l1,lists,begin,mid);
            domerge(l2,lists,mid+1,end);
            list=merge(l1,l2);
        }
    }
    
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        if(l1 == NULL && l2==NULL)
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
        ListNode *ret = NULL;
        if(l1->val <= l2->val)
        {
            ret = l1;
            l1 = l1->next;
        }
        else
        {
            ret = l2;
            l2 = l2->next;
        }
        ret->next = NULL;
        ListNode* cur = ret;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur=cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
            cur->next = NULL;
        }
        if(l1)
        {
            cur->next = l1;
        }
        if(l2)
        {
            cur->next = l2;
        }
        return ret;
    }
};

//LeetCode 24.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        /*
            合并k个排序链表
            极端情况是n个只有一个节点的链表
            所以不能循环的去做，我想到了归并排序的方法
        */
        
        ListNode *list1;
        ListNode *list2;
        //归并排序
        int len = lists.size();
        if(len == 0)
        {
            return NULL;
        }
        if(len == 1)
        {
            return lists[0];
        }
        
        int mid=len/2;
        domerge(list1,lists,0,mid);
        domerge(list2,lists,mid+1,len-1);
        ListNode *newHead = merge(list1,list2);
        return newHead;
    }   
    
    void domerge(ListNode*& list,vector<ListNode*>&lists,int begin,int end)
    {
        if(begin > end)
        {
            list=NULL;
        }
        if(begin == end) 
        {//返回
            list=lists[begin];
        }
        
        if(end-begin == 1)
        {//合并
            list=merge(lists[begin],lists[end]);  
        }
        
        if(end-begin >1)
        {//继续二分
            int mid = begin+(end-begin)/2;
            ListNode *l1;
            ListNode *l2;
            domerge(l1,lists,begin,mid);
            domerge(l2,lists,mid+1,end);
            list=merge(l1,l2);
        }
    }
    
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        if(l1 == NULL && l2==NULL)
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
        ListNode *ret = NULL;
        if(l1->val <= l2->val)
        {
            ret = l1;
            l1 = l1->next;
        }
        else
        {
            ret = l2;
            l2 = l2->next;
        }
        ret->next = NULL;
        ListNode* cur = ret;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur=cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
            cur->next = NULL;
        }
        if(l1)
        {
            cur->next = l1;
        }
        if(l2)
        {
            cur->next = l2;
        }
        return ret;
    }
};

//LeetCode 25.
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
    ListNode* reverseKGroup(ListNode* head, int k) 
    { 
        /*
            上个题的优化，现在允许依次逆序k个节点
            若出现节点不足k个时候（可能出现在最后一次中也可能是第一段），"剩下的不能逆序"
            k = 1的时候不需要逆序的
        */
        if(head==NULL || head->next == NULL || k == 1)
        {
            return head;
        }
        
        ListNode *Head = NULL;   //用于返回头结点
        
        ListNode *prev = head;  //用于逆序
        ListNode *cur = prev->next; //用于逆序
        
        ListNode *pprev = head; //用于表示前一段的最后一个节点，用于连接
        ListNode *first = head; //用于标记第一个节点（逆序后该节点是最后一个节点，这个节点很重要）
        ListNode *tmphead = NULL;//用于标记每一逆序段的头结点
        
        while(cur)
        {
            int count = k;
            prev = first;
            cur = prev->next;
            tmphead = prev;
            if(morethank(prev,k))
            {//测试剩下的节点的长度，若不够k的话就不在逆序了
                tmphead->next = NULL;
                while(--count && cur)
                {
                    prev = cur;
                    cur = cur->next;
                    prev->next = tmphead;
                    tmphead = prev;
                    //--count;
                }
                if(Head == NULL)
                {
                    Head = tmphead;
                    //first = cur;
                }
                else
                {
                    pprev->next = tmphead;
                    pprev = first;
                    //first = cur;
                }
                first = cur;
            }
            else
            {//剩余长度不够k则不能逆序了
                if(Head == NULL)
                { //第一段不够
                    Head = head;   
                }
                else
                { // 最后一段长度不够
                    pprev->next = prev;
                }
                break;
            }
        }
        
        return Head;
    }
    
    bool morethank(ListNode *pnode,int k)
    {//1 2 3 4 5     3
        ListNode *tmp = pnode;
        while(k && tmp)
        {
            --k;
            tmp = tmp->next;
        }
        if(k == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//LeetCode 26.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        /*
            1.不准备额外使用空间
            2.返回删除重复节点后的数组长度
            3.数组有序
        */    
        int len = nums.size();
        if(len == 0 || len == 1)
        {
            return len;
        }
        int only = 0; // 用于记录不重复的下标，最后该下标以及以前的部分都是only one 
        int prev = 0;
        int cur = 1;  //用于遍历
        
        
        //找出前面不相同的序列
        while(cur<len && nums[only] != nums[cur])
        {
            ++cur;
            ++only;
        }
        if(cur == len)
        {
            return only+1;
        }
        
        while(cur < len)
        {
           if(nums[cur] == nums[cur-1])
           {
               prev = cur-1;
               while(cur<len && nums[prev] == nums[cur])
               {
                  ++cur;
               }
               nums[only++] = nums[prev];
           }
           else
           {
               nums[only++] = nums[cur++];
               while(cur < len && nums[cur] == nums[cur-1])
               {
                  ++cur;
               }
           }
        }
        
        return only;
    }
};

//LeetCode 27.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        /*
            该题的意思是删除掉数组里面的特定值
        */
        
        int len = nums.size();
        int pos = 0;  //当前值
        int nextpos = 0;  //在前面找是否出现了val值
        int numofval = 0;  //统计出现了几次val值，最后好确定返回的长度
        bool begin = false; //前面的不是val的值不能被覆盖，所以我们需要注意一下
        
        while(nextpos < len)
        {
            if(nums[nextpos] == val)
            {
                begin = true;
                ++numofval;
                nextpos = nextpos+1;
                while(nextpos < len && nums[nextpos] != val)
                {
                    nums[pos++] = nums[nextpos++];
                }
            }
            else
            {
                if(!begin)
                {
                    ++pos;
                }
                ++nextpos;
            }
        }
        
        return len-numofval;
    }
};

//LeetCode 28.
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        /*
            needle在haystack中第一次出现的位置-------->KMP算法
        */
        int hlen = haystack.size();
        int nlen = needle.size();
        if(hlen == 0 && nlen == 0)
        {
            return 0;
        }
        if(nlen == 0 )
        {
            return 0;
        }
        if(hlen == 0)
        {
            return -1;
        }
        //初始化next数组
        int *next = new int[nlen];
        for(int i=0; i<nlen; ++i)
        {
            next[i] = 0;
        }
        
        //构造next数组
        CreteNext(needle,next,nlen);
        
        //开始匹配
        int s=0;
        int p=0;
        while(s < hlen)
        {
            if(haystack[s] == needle[p])
            {
                ++s;
                ++p;
                if(p == nlen)
                {//匹配
                    return s-nlen;
                }
            }
            else if(next[p] == -1)
            {
                ++s;
            }
            else
            {
                p = next[p];
            }
        }
        //循环出来了说明没找到
        delete []next;
        return -1;
    }
    
    void CreteNext(string &need,int*& next, int n)
    {
        int left = 0;
        int right = 1;
        while(right < n)
        {
            if(need[right] == need[left])
            {
                next[right] = next[right-1]+1;
                ++left;
                //++right;
            }
            else if(need[right] == need[0])
            {
                next[right] = 1;
                left = 1;
                //++right;
            }
            else
            {
                left = 0;
                next[right] = 0;
                //++right;
            }
            ++right;
        }
        
        //next数组的数向右平移一位，然后next[0] = -1，netx数组就构造好了
        for(int j=n-1;j>0;--j)
        {
            next[j] = next[j-1];
        }
        next[0] = -1;
    }
};

//LeetCode 29.
class Solution {
public:
	int divide(int dividend, int divisor)
	{
		//求两个数的商
		//1.被除数为0
		if (divisor == 0)
		{//不合法的数
			return 0;
		}
		//2.除数为 0
		if (dividend == 0)
		{//除数为0
			return 0;
		}
		//3.被除数为1
		if (divisor == 1)
		{
			return dividend;
		}
		//4.被除数为2
		else if (divisor == 2)
		{
			return dividend >> 1;
		}
		//5.考虑溢出问题,正数溢出或者负数溢出
		double maxint = pow(2, 31) - 1;
		if (dividend - maxint > 0.000001)
		{
			dividend = int(maxint);
		}
		if (divisor - maxint > 0.000001)
		{
			divisor = int(maxint);
		}
		if(dividend < maxint*(-1) && divisor < maxint*(-1))
		{// 例如：-2147483648 / -2147483648  
		    return 1;
		}
		if (dividend < maxint*(-1))
		{
			dividend = maxint*(-1);
		}
		if (divisor < maxint*(-1))
		{//被除数越界 例如：(1~2147483647) / -2147483648
			//divisor = maxint*(-1);
			return 0;
		}
		//6.考虑正负号
		int minus = 1; //商是否为负数
		if (dividend < 0 && divisor < 0)
		{
			dividend *= -1;
			divisor *= -1;
			if (divisor > dividend)
			{
				return 0;
			}
		}
		else
		{
			if (dividend < 0)
			{
				dividend *= -1;
				minus = -1;
			}
			if (divisor < 0)
			{
				divisor *= -1;
				minus = -1;
			}
		}
		if (dividend == divisor)
		{   //例如： 1 / -1
			return 1*minus;
		}
		//7.被除数为1
		if (divisor == 1)
		{   //例如： -1 / -1
			return dividend;
		}
		else if (divisor == 2)
		{ //例如： -6 / -2
			return dividend >> 1;
		}
		//8.开始求商 25 / 4   -> 6   4<<2--16  25  4<<3--32  所以，商在4~8之间
		int left = 0;
		int right = 1;
		int ret = 0;
		int mybeover = maxint / 2;
		while (dividend > divisor)
		{
			left = 0;
			right = 1;
			while ((divisor << right) < dividend)
			{
				if ((divisor << left) >= mybeover)
				{
					break;
				}
				++left;
				++right;
			}
			ret += 1 << left;
			dividend -= divisor << left;
		}
		return ret*minus;
	}
};

//LeetCode 30.
class Solution 
{ 
public: 	
	vector<int> findSubstring(string s, vector<string>& words) 
	{ 
		vector<int> ret;
		ret.clear();
		map<string, int> Map;
		map<string, int> temp;
		Map.clear();
		temp.clear();
		int slen = s.size();
		int wlen = words.size();
		if (slen == 0 || wlen == 0)
		{	return ret;	}
		
		int perlen = words[0].size();
		if ( wlen * perlen > slen)
		{	return ret;	}

		for (int i = 0; i < wlen; ++i)
		{
			Map[words[i]]++;
		}

		for (int i = 0; i + perlen*wlen-1 < slen; ++i)
		{
			int j = i;
			temp.clear();
			while (j <= i + wlen*perlen - 1)
			{
				temp[s.substr(j, perlen)]++;
				if (Map[s.substr(j, perlen)] < temp[s.substr(j, perlen)])
				{//
					break;
				}
				else
				{
					j += perlen;
				}
				if (j>i + wlen*perlen - 1)
				{
					ret.push_back(i);
				}
			}
		}
		return ret;
	} 
};

//LeetCode 31.
class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 0 || len == 1)
		{
			return;
		}
		//从尾部向前找,找到nums[pos] > nums[pos-1]位置
		int pos = len - 1;
		while (pos > 0 && nums[pos] <= nums[pos - 1])
		{
			--pos;
		}

		if (pos == 0)
		{//说明到了最后一个位置，例如 3 2 1 ，此时将它排序即可
			sort(nums.begin(), nums.end());
			return;
		}
		else
		{
			if (pos == len - 1)
			{//pos 在最后一个位置，例如 1 2 3 ，那么此时将nums[pos]与nums[pos-1]互换即可
				swap(nums[pos], nums[pos - 1]);
				return;
			}
			else
			{ //这种情况说明pos在中间位置，举例吧，如：5 4 7 5 3 2   
				int key = nums[pos - 1];
				//找比key值大的数字，即比4大的数，可以看到是5（后面的5）
				int begin = len - 1;
				while (begin > pos && nums[begin] <= key)
				{
					--begin;
				}
				//此时 begin 位置的数字比 key 值大，因为至少pos位置的数比key值大，而且从pos到len-1之间的数字是降序的
				swap(nums[pos - 1], nums[begin]);
				//swap以后序列为 5 5 7 4 3 2，然后从pos位置到len-1位置排序，即7~2排序
				sort(nums.begin() + pos, nums.end());
				return;
			}
		}
	}
};

//LeetCode 32.
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int slen = s.size();
        stack<int> S;
        int maxlen = 0;
        int count = 0;
        for(int i=0; i < slen; ++i)
        {
            if(s[i]=='(')
            {// ‘(’ 压入下标 
                S.push(i);
            }
            else
            {
                if( !S.empty() )
                {//栈不空，则判断是否连续匹配
                    count = S.top(); //栈顶下标
                    if( s[count] == ')')
                    {//这是不合法的位置，不用处理
                        S.push(i);
                    }
                    else
                    {
                        S.pop();
                        if(S.empty())
                        {//全部匹配了栈会空
                            maxlen = i+1;
                        }
                        else
                        {//可能存在不合法的位置，用该位置来计算最长长度
                            count = S.top();
                            if(i-count > maxlen)
                            {
                                maxlen = i-count;
                            }
                        }
                    }
                }
                else
                {//这个位置说明它是不合法的位置，可以发挥一定的作用，用来计算匹配到的最长长度
                    S.push(i);
                }
            }
        }
        return maxlen;
    }
};

//LeetCode 33.
class Solution {
public:
    int search(vector<int>& nums, int target)
    { //这个题是给一个排序数组，但是数组里面内容被平行移动了，如上例所示，现在要找到tagert所对应的下标
        int len = nums.size();
        
        //特殊情况先考虑掉
        if(len == 0)
        { return -1; }
        if(len == 1 && target!=nums[0])
        { return -1; }
        
        //正常情况，应该不能遍历一边数组吧，这样没有意义，应该也无法通过；虽然顺序被打乱了，但是部分还是有序的，我们还是使用二分查找
        int left = 0;
        int right = len-1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right-left)/2;
            
            if(target == nums[left])
            {
                return left;
            }
            if(target == nums[right])
            {
                return right;
            }
            if(target == nums[mid])
            {
                return mid;
            }
            
            //二分查找
            if(nums[mid] >= nums[left])
            {//左边有序
                if(target > nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {//右边有序
                if(target > nums[mid] && target < nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

//LeetCode 34.
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{ //
		vector<int> ret;
		ret.clear();
		int len = nums.size();
		//非正常情况
		if (len == 0 || target < nums[0] || target > nums[len - 1])
		{
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		int left = 0;
		int right = len - 1;
		int mid = 0;
		//简单的二分查找时不能准确的找到开始和结束点的
		while (left <= right && nums[left]<=target && nums[right]>=target)
		{//有一边找到了target
			mid = left + (right - left) / 2;
			if (nums[mid] == target)
			{
				break;
			}
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

        if(nums[left]>target || nums[right]<target)
        {
            //不合格，最后一起处理
        }
		else if (left == right)
		{
			if (nums[left] == target)
			{
				ret.push_back(left);
				ret.push_back(left);
				return ret;
			}
			else
			{
				//没找到,到最后一起处理
			}
		}
		else
		{ // left < right ，说明nums[mid] == target，那么分别向左找开始点和向右找结束点
			//左边
			int lbegin = left;
			int lend = mid;
			int lmid = 0;
			while (nums[lbegin] != target && nums[lbegin + 1] != target)
			{
				lmid = lbegin + (lend - lbegin) / 2;
				if (nums[lmid] == target)
				{//说明开始部位可能还在左边
					lend = lmid;
				}
				else
				{//nums[lmid]<target,此时说明在右边
					lbegin = lmid;
				}
			}
            //注意临界条件
			if (nums[lbegin] == target)
			{
				ret.push_back(lbegin);
			}
			else
			{
				ret.push_back(lbegin + 1);
			}

			//右边
			int rbegin = mid;
			int rend = right;
			int rmid = 0;
			while (nums[rend] != target && nums[rend - 1] != target)
			{
				rmid = rbegin + (rend - rbegin) / 2;
				if (nums[rmid] == target)
				{//说明结束部位还在右边
					rbegin = rmid;
				}
				else
				{
					rend = rmid;
				}
			}
			//注意临界条件
			if (nums[rend] == target)
			{
				ret.push_back(rend);
			}
			else
			{
				ret.push_back(rend - 1);
			}
			return ret;
		}
		
		//没找到
		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
	}
};

//LeetCode 35.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		
		int left = 0;
		int right = len - 1;
		int mid = 0;
		if (target > nums[right])
		{
			return right + 1;
		}

		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[left] == target)
			{
				return left;
			}
			if (nums[right] == target)
			{
				return right;
			}
			if (nums[mid] == target)
			{
				return mid;
			}

			if (nums[mid] > target)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		
		return left;    
    }
};

//LeetCode 36
class Solution {
public:
	bool isValidSudoku(vector<string>& board)
	{//判断九宫格中的元素是否合法，只判断已填充的元素，未填充的元素不用考虑
		/*
		九宫格的规律是每行每列每宫都包含1~9各一次，所以我们只要判断每行每列每宫的已填充元素是否在1~9之间且无重复即可，所以我们可以使用set来解决此题...
		*/

		char *tmp = new char[9];
		for (int i = 0; i<9; ++i)
		{
			int count = 0;
			for (int j = 0; j<9; ++j)
			{
				tmp[count++] = board[i][j];
			}
			if (!check(tmp))
			{
				return false;
			}

			count = 0;
			for (int j = 0; j<9; ++j)
			{
				tmp[count++] = board[j][i];
			}
			if (!check(tmp))
			{
				return false;
			}

			int x = (i / 3) * 3;
			int y = (i % 3) * 3;
			count = 0;
			for (int j = x; j< x + 3; ++j)
			{				
				for (int k = y; k< y + 3; ++k)
				{
					tmp[count++] = board[k][j];
				}
			}
			if (!check(tmp))
			{
				return false;
			}
		}
		delete[] tmp;
		return true;
	}

	bool check(char* str)
	{
		set<char> S;
		S.clear();
		for (int i = 0; i<9; ++i)
		{
			if (str[i] == '.')
			{
				continue;
			}
			if (str[i] <= '0' && str[i] > '9')
			{
				return false;
			}
			else
			{
				if (S.find(str[i]) == S.end())
				{
					S.insert(str[i]);
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
};

//LeetCode 37
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		/*
		返回类型为void不是很准确，假设该数独没有解的话，那么我们并不知道，到底是错误还是找到解了。
		数独求解，最终还是遇到了，无法避免，那么我们就来战胜它，这类题是“回溯”的代表
		*/
		bool ret = _solveSudoku(board);
		if (ret == true)
		{
			cout << "Find solve" << endl;
		}
		else
		{
			cout << "No Solve " << endl;
		}
	}

	bool _solveSudoku(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
				{
					for (int k = 1; k <= 9; ++k)
					{
						board[i][j] = '0' + k;
						if (isVild(board, i, j) && _solveSudoku(board))
						{//成功则返回
							return true;
						}
						//失败的话该位置再置为下一个测试值，但是先要还原原来的值，因为我们是用board的"引用",所以不能直接跳过
						board[i][j] = '.';
					}
					//1~9都不满足的话,失败
					return false;
				}
			}
		}
		/*
		走到这里说明了一些问题：
		1.成功了,不需要做什么
		2.board中没有‘.’,这样就不会进入if循环，按理说这个时候需要再判断一次board是否是正解，但是没有判断却也没有错...
		*/
		return true;
	}

	bool isVild(vector<vector<char>> &board, int x, int y)
	{
		//横向
		for (int i = 0; i < 9; ++i)
		{
			if (i != y && board[x][i] == board[x][y])
			{//重复出现，非法
				return false;
			}
		}
		//纵向
		for (int i = 0; i < 9; ++i)
		{
			if (i != x && board[i][y] == board[x][y])
			{
				return false;
			}
		}
		//只检查x和y所在的宫内的元素即可    
		int wid = 3 * (x / 3); //x起始位置
		int hig = 3 * (y / 3); //y起始位置
		for (int i = wid; i < wid + 3; ++i)
		{
			for (int j = hig; j < hig + 3; ++j)
			{
				if (i != x && j != y && board[i][j] == board[x][y])
				{
					return false;
				}
			}
		}
		//成功   
		return true;
	}
};

//LeetCode 38
class Solution {
public:
	string countAndSay(int n)
	{
		string ret = "";
		if (n == 0)
		{
			return ret;
		}
		//n == 1
		string tmp = "1";
		if (1 == n)
		{
			return tmp;
		}
		// n > 1
		for (int i = 1; i < n; ++i)
		{
			ret.clear();
			size_t j = 0;
			while (j < tmp.size())
			{
				char ch = tmp[j];
				int num = 1;
				while (j + num < tmp.size() && tmp[j + num] == tmp[j])
				{
					++num;
				}
				if (1 == num)
				{
					ret.push_back('1');
				}
				else
				{
					ret.push_back(num + '0');
				}
				ret.push_back(tmp[j]);
				j += num;
			}
			tmp = ret;
		}

		return ret;
	}
};

//LeetCode 39
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        /*
            看到这个题的第一眼开始，我就想到了这个题和前面讲到的twosum，threesum，foursum不同，这个题目可能是 nsum， 所以n层循环的
        做法不可取，我想到了是否可以回溯：不断加入元素，去测试，若元素的和与target相等则满足题意，若大于target则推出循环，若小于则
        可以继续测试。
        */
        vector<vector<int>> ret;
        ret.clear();
        vector<int> tmp;
        tmp.clear();
        //题目并没有说明candidates是有序的，但是题目要求的结果是不能出现重复的集合，那么我们需要对candidates排序
        sort(candidates.begin(),candidates.end());
        //还是采用递归加上回溯法进行求解
        _findAllSolve(candidates,ret,tmp,target,0);
        return ret;
    }
    
    void _findAllSolve(vector<int>& candidates, vector<vector<int>>& ret,vector<int>& tmp,int target, int index)
    {
        if(target == 0)
        {//此时说明tmp中的集合满足题意，加入到ret中
            ret.push_back(tmp);
            return ;
        }
        else
        {
            for(int i = index; i < candidates.size(); ++i)
            {
                if(candidates[i] > target)
                {//题目中有说明candidates中元素都是非负的，而且candidates被排序过，此时可直接退出
                    return ;
                }
                //target > candidates[i]  那么我们就将candidates[i]加入到tmp中
                tmp.push_back(candidates[i]);
                _findAllSolve(candidates,ret,tmp,target-candidates[i],i);
                //完成上面的过程后需要及时将它们移除，再看看还有其他的解没有
                tmp.pop_back();
            }
        }
    }
};

//LeetCode 40
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        /*
            看到这个题的第一眼开始，我就想到了这个题和前面讲到的twosum，threesum，foursum不同，这个题目可能是 nsum， 所以n层循环的
        做法不可取，我想到了是否可以回溯：不断加入元素，去测试，若元素的和与target相等则满足题意，若大于target则推出循环，若小于则
        可以继续测试。
        */
        vector<vector<int>> ret;
        ret.clear();
        vector<int> tmp;
        tmp.clear();
        //题目并没有说明candidates是有序的，但是题目要求的结果是不能出现重复的集合，那么我们需要对candidates排序
        sort(candidates.begin(),candidates.end());
        //还是采用递归加上回溯法进行求解
        _findAllSolve(candidates,ret,tmp,target,0);
        return ret;
    }
    
    void _findAllSolve(vector<int>& candidates, vector<vector<int>>& ret,vector<int>& tmp,int target, int index)
    {
        if(target == 0)
        {//此时说明tmp中的集合满足题意，加入到ret中
            ret.push_back(tmp);
            return ;
        }
        else
        {
            for(int i = index; i < candidates.size(); ++i)
            {
                if(candidates[i] > target)
                {//题目中有说明candidates中元素都是非负的，而且candidates被排序过，此时可直接退出
                    return ;
                }
                //target > candidates[i]  那么我们就将candidates[i]加入到tmp中
                tmp.push_back(candidates[i]);
                _findAllSolve(candidates,ret,tmp,target-candidates[i],i);
                //完成上面的过程后需要及时将它们移除，再看看还有其他的解没有
                tmp.pop_back();
            }
        }
    }
};

//LeetCode 41
class Solution {
public:
	int firstMissingPositive(vector<int>& nums)
	{
	    //这个题用位图或者哈希表都可以，不过使用bitset不是很方便，其大小决定不了，我还是开辟了nums.size()+1 大小的数组，若是连续全部都可以放下，不连续的话肯定会在中间断开的，没必要全部统计位置了
		const size_t len = nums.size();
		vector<int> tmp;
		tmp.resize(len + 1);
		for (size_t i = 0; i < len; ++i)
		{
			if (nums[i] > 0 && nums[i] <= len)
			{
				tmp[nums[i]] = 1;
			}
		}

		for (size_t i = 1; i < len + 1; ++i)
		{
			if (tmp[i] == 0)
			{
				return i;
			}
		}

		return len + 1;
	}
};

//LeetCode 42
class Solution {
public:
	int trap(vector<int>& height)
	{
	    /*
	        这个题又是个数字游戏题，我做完了后发现它充满着陷阱，很难一次想到所有情况，调试了很多次才写好的，不过庆幸的是，这个题的问题很容易发现，我建议在动手之前请多画图，多联系生活列出一些特殊情况里帮助分析。
	    */
	    
		int area = 0;
		int len = height.size();
		int begin = 0;
		int end = 0;

		while (begin < len)
		{
			end = begin;
			//找最低谷
			while (end < len-1 && height[end] > height[end + 1] && height[begin]>0)
			{
				++end;
			}
			if (end == begin)
			{//没找到
				++begin;
				continue;
			}

            //找比构成面积的连续最高位置
			int newbegin = end;
			while (end + 1 < len && height[end] <= height[end+1])
			{
				++end;
			}
			if (end == newbegin)
			{
				begin = end+1;
				continue;
			}

            //可能存在更高的位置，需要去找找看
			if(height[begin] > height[end])
			{
			    //还需要找最高位置
			    int nbegin = end;
			    int nend = end;
			    int maxheigh = height[end]; //记录最高位置
			    
			    while (nend < len)
			    {
				    if (height[nend] > maxheigh)
				    {
					    end = nend;
					    maxheigh = height[nend];
					    if (maxheigh > height[begin])
						{//找到了高于height[begin]的位置就可以跳出循环了，因为此时已经是能够构成的最大容器了
							break;
						}
				    }
				    ++nend;
			    }
            }
            
            //选择begin和end的较小者，用来计算容器
			int h = min(height[begin], height[end]);
			for (size_t i = begin; i < end + 1; ++i)
			{
				int val = h - height[i];
				if (val > 0)
				{
					area += val;
				}
			}
			begin = end;
		}

		return area;
	}
};

//LeetCode 43
class Solution {
public:
	string multiply(string num1, string num2)
	{
		/*
		这个题的意思是返回两个大数相乘的结果
		两个乘数可以很大且非负
		不能将字符串转化为int
		不能使用大数相关的库
		*/

		string ret = "";
		int sz1 = num1.size();
		int sz2 = num2.size();
        if (sz1 == 1 && num1[0] == '0' || sz2 == 1 && num2[0] == '0')
		{
			ret.push_back('0');
			return ret;
		}
		
		//先往右进位，最后将结果逆置一下
		for (int i = sz1-1; i >=0; --i)
		{
			int begin = sz1 - i - 1;
			for (int j = sz2-1; j >= 0; --j)
			{
				int tmp = (num1[i] - '0') * (num2[j] - '0');
				carrybit(ret, begin, tmp);
				++begin;
			}
		}

		//逆序
		reverse(ret);

		return ret;
	}

	void carrybit(string& str, int begin, int num)
	{
		const int first = begin;
		if (num == 0)
		{
			if (begin >= str.size())
			{  // 相乘的结果为 0 且出现在最后面的位置，这个时候得补上0，否则缺位
				str.push_back('0');
			}
		}

		while (num)
		{
			int cur = num % 10;
			if (begin >= str.size())
			{//在最后面的位置上添加的时候得添加‘字符’
				str.push_back(cur + '0');
				++begin;
			}
			else
			{//在中间的位置上只需要加‘整数’
				str[begin++] += cur;
			}
			num /= 10;
		}

		//判断当前位是否产生进位
		int bigger = str[first] - '0';
		if (bigger >= 10)
		{//判断当前位是否产生了进位，若进位则处理进位
			curcarrybit(str, first, bigger);
		}
	}
	
	//进位处理函数
	void curcarrybit(string &str, int  begin, int num)
	{
		int first = begin;
		while (num)
		{
			int cur = num % 10;
			if (begin >= str.size())
			{
				str.push_back(cur + '0');
				++begin;
			}
			else
			{
				if (first == begin)
				{//当前位产生进位，留下余下的，所以用赋值语句
					str[begin++] = (cur + '0');
				}
				else
				{//进位的数目补到后面的位置上
					str[begin++] += cur;
				}
			}
			num /= 10;
		}
	}

	//翻转字符串
	void reverse(string & s)
	{
		int right = s.size() - 1;
		int left = 0;
		while (left < right)
		{
			swap(s[left], s[right]);
			++left;
			--right;
		}
	}
};

