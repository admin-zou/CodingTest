/*
    这里记录了我在写LeetCode算法题的代码，LeetCode上的题目听说很不错，所以自己去体验了一下，这里只记录了代码，具体的思路没有细说，
  因为有些题目是需要画图分析的，所以我将解题思路以博客的形式写出了，如果你觉得有些代码看不懂，那么你可以去看看我的博客，博客地址：
  URL：  http://blog.csdn.net/column/details/myleetcodetesting.html
*/

// LeetCode 51
class Solution {
public:
	vector<vector<string>> solveNQueens(int n)
	{
		/*
			N后问题是每个位置的皇后会攻击它的横向的，纵向的以及斜线上的皇后
		*/
		vector<vector<string>> ret;
		ret.clear();
		vector<string> oneSolve;
		oneSolve.clear();
		for (int i = 0; i < n; ++i)
		{
			string tmp(n,'.');
			oneSolve.push_back(tmp);
		}

		_solves(ret, oneSolve, n, 0);
		return ret;
	}

	void _solves(vector<vector<string>>&ret, vector<string> oneSolve, int n,int index)
	{
		if (index == n)
		{ 
			/*
			其实这里不需要检查了，能进来的都是合格的
			if (_testQueen(oneSolve, n, n))
			{
				ret.push_back(oneSolve);
			}
			*/
			ret.push_back(oneSolve);
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			oneSolve[index][i] = 'Q';
			if (!_testQueen(oneSolve, index+1,n))
			{//检查当前行，提前做出决策
				oneSolve[index][i] = '.';
				continue;
			}			
			_solves(ret, oneSolve, n, index + 1);
			oneSolve[index][i] = '.';
		}
	}

	bool _testQueen(vector<string>& tmp,int m,int n)
	{ // m行，n列(m可能小于n)

		int i = m-1;
		int j = 0;
		for (; j < n; ++j)
		{
			if (tmp[i][j] == 'Q')
			{
				break;
			}
		}

		// tmp[i][j] == 'Q'
		// 检查行
		for (int k = j + 1; k < n; ++k)
		{ 
			if (tmp[i][k] == 'Q')
			{
				return false;
			}
		}
			
		//检查列
		for (int k = 0; k < i; ++k)
		{
			if (tmp[k][j] == 'Q')
			{
				return false;
			}
		}
		for (int k = i + 1; k < m; ++k)
		{
			if (tmp[k][j] == 'Q')
			{
				return false;
			}
		}
			
		//检查斜线上的
		//左上
		int beginx = i;
		int beginy = j;			
		while (beginx > 0 && beginy > 0)
		{
			if (tmp[--beginx][--beginy] == 'Q')
			{
				return false;
			}
		}
		//右下
		beginx = i;
		beginy = j;
		while (beginx < m-1 && beginy < n-1)
		{
			if (tmp[++beginx][++beginy] == 'Q')
			{
				return false;
			}
		}
		//左下
		beginx = i;
		beginy = j;
		while (beginx<m - 1 && beginy > 0)
		{
			if (tmp[++beginx][--beginy] == 'Q')
			{
				return false;
			}
		}
		//左上
		beginx = i;
		beginy = j;
		while (beginx > 0 && beginy < n - 1)
		{
			if (tmp[--beginx][++beginy] == 'Q')
			{
				return false;
			}
		}
			
		return true;
	}
};

// LeetCode 52
class Solution {
public:
	int totalNQueens(int n)
	{
		int ret = 0;
		vector<string> oneSolve;
		oneSolve.clear();
		for (int i = 0; i < n; ++i)
		{
			string tmp(n, '.');
			oneSolve.push_back(tmp);
		}

		_solves(ret,oneSolve, n, 0);
		
		return ret;	
	}

	void _solves(int &ret,vector<string> oneSolve, int n, int index)
	{
		if (index == n)
		{
			++ret;
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			oneSolve[index][i] = 'Q';
			if (!_testQueen(oneSolve, index + 1, n))
			{//检查当前行，提前做出决策
				oneSolve[index][i] = '.';
				continue;
			}
			_solves(ret, oneSolve, n, index + 1);
			oneSolve[index][i] = '.';
		}
	}

	bool _testQueen(vector<string>& tmp, int m, int n)
	{ // m行，n列(m可能小于n)
		int i = m - 1;
		int j = 0;
		for (; j < n; ++j)
		{
			if (tmp[i][j] == 'Q')
			{
				break;
			}
		}
		// tmp[i][j] == 'Q'
		// 检查行
		for (int k = j + 1; k < n; ++k)
		{
			if (tmp[i][k] == 'Q')
			{
				return false;
			}
		}
		//检查列
		for (int k = 0; k < i; ++k)
		{
			if (tmp[k][j] == 'Q')
			{
				return false;
			}
		}
		for (int k = i + 1; k < m; ++k)
		{
			if (tmp[k][j] == 'Q')
			{
				return false;
			}
		}
		//检查斜线上的
		//左上
		int beginx = i;
		int beginy = j;
		while (beginx > 0 && beginy > 0)
		{//
			if (tmp[--beginx][--beginy] == 'Q')
			{
				return false;
			}
		}
		//右下
		beginx = i;
		beginy = j;
		while (beginx < m - 1 && beginy < n - 1)
		{
			if (tmp[++beginx][++beginy] == 'Q')
			{
				return false;
			}
		}
		//左下
		beginx = i;
		beginy = j;
		while (beginx<m - 1 && beginy > 0)
		{
			if (tmp[++beginx][--beginy] == 'Q')
			{
				return false;
			}
		}
		//左上
		beginx = i;
		beginy = j;
		while (beginx > 0 && beginy < n - 1)
		{
			if (tmp[--beginx][++beginy] == 'Q')
			{
				return false;
			}
		}

		return true;
	}
};

// LeetCode 53
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		/*
			查找连续的子数组，使其和最大
		*/

		int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		else if (len == 1)
		{
			return nums[0];
		}

		size_t pos = 0;  //下标
		int cursum = 0;  //保存最大和
		int maxsum = 0;  //当前和
		int max = nums[0]; //数组最为负数，返回最大负数

		//除去开头的负数，并且找到其中的最大的负数，若数组全为负数就要返回该值
		while (pos < len && nums[pos] < 0)
		{
			if (nums[pos] > max)
			{
				max = nums[pos];
			}
			++pos;
		}
		if (pos == len)
		{ //全为负数...
			return max;
		}

		//存在正数
		while (pos < len)
		{
			cursum += nums[pos];
			if (cursum > maxsum)
			{
				maxsum = cursum;
			}
			else if (cursum < 0)
			{ //当前和小于0，直接从下一个位置开始计算
				cursum = 0;
			}
			++pos;
		}

		return maxsum;
	}
};

// LeetCode 54
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		/* 螺旋数组 */
		vector<int> ret;
		ret.clear();
		int x = matrix.size(); //行
		if (x == 0)
		{ //空
			return ret;
		}
		else if (x == 1)
		{ //只有一行
			for (int i = 0; i < matrix[0].size(); ++i)
			{
				ret.push_back(matrix[0][i]);
			}
			return ret;
		}

		int y = matrix[0].size();//列
		if (y == 1)
		{ //只有一列
			for (int i = 0; i < x; ++i)
			{
				ret.push_back(matrix[i][0]);
			}
			return ret;
		}

		for (int i = 0; i <= (y-1) / 2; ++i)
		{
			if (i <= (x-1) / 2)
			{ // 行和列都满足一定条件才能调用遍历函数
				_traverse(matrix, ret, i, x, y);
			}
		}
		return ret;
	}

	void _traverse(vector<vector<int>>& ma, vector<int>&ret, int pos, int x, int y)
	{  //pos为其实位置，该位置 x==y
		
		for (int step1 = pos; step1 < y - pos; ++step1)
		{
			ret.push_back(ma[pos][step1]);
		}

		for (int step2 = pos + 1; step2 < x - pos; ++step2)
		{
			ret.push_back(ma[step2][y - pos - 1]);
		}

		for (int step3 = y - pos - 2; step3 >= pos && x-pos-1 > pos; --step3)
		{ //最后只剩一行的时候易错，行重复
			ret.push_back(ma[x-pos-1][step3]);
		}

		for (int step4 = x - pos - 2; step4 > pos && y-pos-1 > pos ; --step4)
		{ //最后只剩一列的时候易出错，列重复
			ret.push_back(ma[step4][pos]);
		}
	}
};

// LeetCode 55
class Solution {
public:
	int canJump(vector<int>& nums)
	{
		/*这类问题还是使用贪心算法*/
		int length = nums.size();
		int index = 0;
		if (length == 0)
		{
			return 0;
		}

		while (index < length - 1)
		{
			int next = 0;
			int begin = index;
			int onejump = 0;
			for (int i = 1; i <= nums[index]; ++i)
			{
				if (nums[index] >= length - 1 || index + i >= length-1 || index + nums[index + i] >= length-1)
				{			 
					return true;
				}

				if (i + nums[index + i] > onejump && nums[index+i]!= 0)
				{
					next = i;
					onejump = i + nums[index + i];
				}
			}
	
			if (next == 0)
			{ //无法跳出去
				return false;
			}

			index += next;
		}
		
		return (index >= length - 1);
	}
};

// LeetCode 56
struct Interval
{
	int start;
	int end;
	Interval() 
		: start(0)
		, end(0)
	{}
	Interval(int s, int e) 
		: start(s)
		, end(e)
	{}
};
class Solution
{
public:
	vector<Interval> merge(vector<Interval>& intervals)
	{ //[[2,3],[4,5],[6,7],[8,9],[1,10]]
		vector<Interval> ret;
		vector<Interval> tmp = intervals;
		vector<Interval> _swap;
		
		
		while (tmp.size() > 1)
		{
			bool flag = false;
			_swap.clear();
			int pos = 0;
			int next = pos + 1;
			int tail = tmp.size();
			int s = tmp[pos].start;
			int e = tmp[pos].end;
			while (next < tail)
			{
				if (tmp[next].end >= s && tmp[next].start <= e)
				{
					flag = true;
					e = max(e, tmp[next].end);
					s = min(s, tmp[next].start);
				}
				else 
				{
					_swap.push_back(tmp[next]);
				}
				++next;
			}
			
			tmp.clear();
			tmp = _swap;
			if (!flag)
			{
				ret.push_back(Interval(s, e));
			}
			else
			{
				tmp.push_back(Interval(s, e));
			}			
		}

		if (tmp.size() == 1)
		{
			ret.push_back(tmp[0]);
		}
		return ret;
	}
};

// LeetCode 57
struct Interval 
{
     int start;
     int end;
     Interval() : start(0), end(0) 
	 {}
     Interval(int s, int e) : start(s), end(e) 
	 {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
	{		
		vector<Interval> ret;
		ret.clear();

		vector<Interval> tmp;
		tmp.clear();
		
		int s = newInterval.start;
		int e = newInterval.end;
		for (int i = 0; i < intervals.size(); ++i)
		{
			if (intervals[i].end >= s && intervals[i].start <= e)
			{
				e = max(e, intervals[i].end);
				s = min(s, intervals[i].start);
			}
			else
			{
				tmp.push_back(intervals[i]);
			}
		}

		int i = 0;
		while (i < tmp.size() && tmp[i].start < s)
		{
			ret.push_back(tmp[i]);
			++i;
		}
		ret.push_back(Interval(s, e));
		while (i < tmp.size() && tmp[i].start >= e)
		{
			ret.push_back(tmp[i]);
			++i;
		}

		return ret;
	}
};

// LeetCode 58
class Solution {
public:
	int lengthOfLastWord(string s)
	{ /* 返回最后一个单词的长度？*/
		int len = s.size();
		if ((len == 0) || (len == 1 && s[0] == ' '))
		{
			return 0;
		}

		int end = len - 1;
		while (end > 0 && s[end] == ' ')
		{
			--end;
		}
		len = end + 1;


		while (end > 0 && s[end] != ' ')
		{
			--end;
		}

		if (end == 0 && s[0] != ' ')
		{
			return len - end;
		}
		else
		{
			return len - end - 1;
		}
	}
};

// LeetCode 59
class Solution {
public:
	vector<vector<int>> generateMatrix(int n)
	{
		/*蛇形数组*/
		assert(n > 0);
		vector<vector<int>> ret;
		ret.resize(n);
		for (int i = 0; i < n; ++i)
		{
			ret[i].resize(n);
		}
		
		int OneToN = 0;
		for (int i = 0; i <= (n-1) / 2; ++i)
		{
			_Trace(ret, i, OneToN);
		}

		return ret;
	}

	void _Trace(vector<vector<int>>& mesh, int pos, int& count)
	{
		int n = mesh.size();
		for (int i = pos; i < n - pos; ++i)
		{
			mesh[pos][i] = ++count;
		}

		for (int i = pos + 1; i < n-pos; ++i)
		{
			mesh[i][n-pos-1] = ++count;
		}

		for (int i = n - pos - 2; i >= pos && pos < n/2; --i)
		{
			mesh[n-pos-1][i] = ++count;
		}

		for (int i = n - pos - 2; i>pos && pos < n / 2; --i)
		{
			mesh[i][pos] = ++count;
		}
	}
};

// LeetCode 60
class Solution {
public:
	string getPermutation(int n, int k)
	{ //1~n 的全排列的 第k个数
		string ret;
		ret.clear();
		if (n == 1 && k != 1 || k > factorial(n))
		{
			return ret;
		}

		vector<int> v;
		v.clear();
		for (int i = 1; i <= n; ++i)
		{
			v.push_back(i);
		}

		int begin = 0;
		int pos = 0;

		while (k > 0)
		{
			begin = 1;
			int offset = 0;
			int nums = 0;

			while ((nums = factorial(begin)) < k)
			{
				++ begin;
			}
			nums /= begin;
			pos = n - begin;

			if (begin > n+1)
			{ //不存在
				return ret;
			}

			int temp = 0;
			int jump = 0;
			while (temp+nums < k)
			{
				temp += nums;
				++jump;
			}

			if (jump > 0)
			{
				swap(v[pos], v[pos+jump]);
				sort(v.begin() + pos + 1, v.end());
			}

			k -= jump*nums;
		
			if (k <= 1)
			{ //
				for (int i=0;i<n;++i)
				{
					ret.push_back(v[i] + '0');
				}
				return ret;
			}
		}
		return ret;
	}

	int factorial(int n)
	{ //求阶乘
		int ret = 1;
		for (int i = 2; i <= n; ++i)
		{
			ret *= i;
		}

		return ret;
	}	
};

// LeetCode 61
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (head == NULL || head->next == NULL || k == 0)
		{
			return head;
		}
		
		ListNode* newHead = NULL;

		int lenOfList = 1;
		ListNode * tmp = head;
		while (tmp->next)
		{
			++lenOfList;
			tmp = tmp->next;
		}
		//注意，此时tmp指向最后一个节点，因为lenOfList开始时的值为1

		k %= lenOfList;
		if (k == 0)
		{
			return head;
		}

		ListNode* cur = head;
		for (int i = 0; i < lenOfList - k - 1; ++i)
		{
			cur = cur->next;
		}
		newHead = cur->next;
		cur->next = NULL;
		tmp->next = head;

		return newHead;
	}
};

// LeetCode 62
class Solution {
public:
	int uniquePaths(int m, int n)
	{
		assert(m <= 100);
		assert(n <= 100);
		if (m == 1 || n == 1)
		{
			return 1;
		}
		//第一行,最后一列
		int sum = 1;
		vector<int> v1(m, 0);
		vector<int> v2(m, 1);
		int end = n - 1;
		while (end > 0)
		{
			int tmp = 0;
			v1 = v2;
			for (int i = 1; i < m; ++i)
			{
				tmp += v1[i];
			}
			sum += tmp;

			int total = 0;
			for (int i = m - 1; i > 0; --i)
			{
				total += v1[i];
				v2[i] = total;
			}
			--end;
		}
		return sum;
	}

};

// LeetCode 63



// LeetCode 72 (word1 -> word2)
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector< vector<int> > Dt(word1.size()+1, vector<int> (word2.size()+1));
        
        for(int i=0; i<word1.size()+1; ++i){
            for(int j=0; j<word2.size()+1; ++j){
                if(0 == i){
                    Dt[i][j] = j;
                }else if(0 == j)
                {
                    Dt[i][j] = i;
                }else{
                    Dt[i][j] = min( Dt[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0:1), min(Dt[i-1][j]+1,Dt[i][j-1]+1));
                }
                
            }
        }
        return Dt[word1.size()][word2.size()];
    }
};
