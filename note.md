[TOC]

reference

https://github.com/yanzhe-chen/leetcode

LintCode & LeetCode 题解分析 tag分类
https://legacy.gitbook.com/book/aaronice/lintcode/details

http://zxi.mytechroad.com/blog/greedy/leetcode-621-task-scheduler/

http://fisherlei.blogspot.com/

## tag
### string

Number of substrings of a string : $\frac{n(n+1)}{2}$
how to count

1. Number of substrings of length 1 is n (We can choose any of the n characters)
2. Number of substrings of length 2 is n-1 
substring是相邻字符串,不是排列组合问题,长度为2的子字符串
abcde->(ab,bc,cd,de)
3. Number of substrings of length 3 is n-2(We can choose any of the n-2 triplets formed by adjacent)
4. In general, mumber of substrings of length k is n-k+1 where 1 <= k <= n
$n + (n-1) + (n-2) + (n-3) + \cdots 2 + 1= \frac{n(n+1)}{2}$

## leetcode pattern

https://medium.com/leetcode-patterns

backtracking
sliding windows
dfs+bfs
bfs+dfs
iterative travsersal on tree
https://medium.com/@sourabreddy
https://www.reddit.com/r/cscareerquestions/comments/7nsq1l/leetcode_problems_decomposition_into_patterns/
https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/sliding-window-algorithm-template-to-solve-all-the-leetcode-substring-search-problem

task scheduler problem greedy
Partition Equal Subset Sum


https://leetcode.com/problems/can-i-win/
https://leetcode.com/problems/ransom-note/description/
https://leetcode.com/problems/cherry-pickup/
https://leetcode.com/problems/design-twitter/
https://leetcode.com/problems/h-index-ii/description/
https://leetcode.com/problems/expression-add-operators/description/
https://leetcode.com/problems/triangle/
https://leetcode.com/problems/mini-parser/
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
https://leetcode.com/problems/implement-rand10-using-rand7/
https://leetcode.com/problems/task-scheduler/solution/#
https://leetcode.com/problemset/top-100-liked-questions/

770 
https://leetcode.com/problems/basic-calculator-iv/description/
762
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
61
https://leetcode.com/problems/rotate-list/description/
476
https://leetcode.com/problems/number-complement/description/
438
https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
587
https://leetcode.com/problems/erect-the-fence/description/
494
https://leetcode.com/problems/target-sum/
726
https://leetcode.com/problems/number-of-atoms/description/

https://leetcode.com/problems/word-frequency
https://leetcode.com/problems/kth-largest-element-in-an-array
https://leetcode.com/problems/sort-characters-by-frequency
https://leetcode.com/problems/split-array-into-consecutive-subsequences
https://leetcode.com/problems/top-k-frequent-words
https://leetcode.com/problems/subsets-ii/description/
https://leetcode.com/problems/letter-case-permutation/description/
https://leetcode.com/problems/combinations

https://leetcode.com/problems/lru-cache/description/


https://leetcode.com/problems/valid-parentheses/description/
https://leetcode.com/problems/merge-two-sorted-lists/description/
https://leetcode.com/problems/3sum
https://leetcode.com/problems/4sum
https://leetcode.com/problems/multiply-strings
https://leetcode.com/problems/add-binary
https://leetcode.com/problems/sum-of-two-integers
https://leetcode.com/problems/add-strings
https://leetcode.com/problems/add-two-numbers-ii
https://leetcode.com/problems/closest-leaf-in-a-binary-tree
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree
https://leetcode.com/problems/serialize-and-deserialize-binary-tree
https://leetcode.com/problems/reverse-vowels-of-a-string/description/
https://leetcode.com/problems/orderly-queue/description/

## Smallest Good Base @18.06.20

三种尝试

### 暴力遍历


```cpp
for y in 2 to MAX
	estimate max_pow
	value = calc(y, max_pow)
	if value == x:
		break
	else
		y++
```

问题:解空间在2~max之间,每次只能+1时间复杂度太高



### 提示:二分

看到discussion中提到用二分
二分要求有序
固定长度的前提下
yy...y在解空间max~2上是有序的
可以用二分



```cpp
estimate max pow with smallest base, e.g. 2
for i in max_pow to 2
	bin_search(begin,end,x)
```
问题:pow(y,i)在y太大时,发生了溢出


### 进一步缩小解空间的范围

$y^{n-1} < x={1+y+y^2+y^3+\cdots+y^{n-1}} < y^n$

$\sqrt[n]{x} < \sqrt[n]{y^n}=y$

$\sqrt[n-1]{x} > \sqrt[n-1]{y^{n-1}}=y$

$\sqrt[n]{x} < y < \sqrt[n-1]{y^{n-1}}$


为什么 用pow不行,mypow就行,,又溢出了??

## My Calendar I


人家都是存booked event
我的思路是在timeline上挖洞,存avilable time

链表一点都不好用
比起vector<pair<int,int>>
明明这个遍历起来很方便,,,

就算用了链表能解决,我的写法也很不优雅


逻辑判断方面,,我想的那么复杂,人家一条if语句就有了

```cpp

for (auto p:v) {
	if (p.first <= s && p.second > s) return false;
	if (s <= p.first && e > p.first) return false;
}
v.push_back({s,e});


if( start < cur->end and end > cur->start)
	return false;
```

看一下完整的solution
对比一下我的logical差在哪里

## Wiggle Subsequence
数组为空的情况
两数相减，差值比较，为0的情况

这些情况，不出错，我写代码的时候，就没考虑到

另外，看一下solution，，
## 152_Maximum_Product_Subarray
dynamic programming
问题是,状态转移方程是怎么想出来的?
## 053_Maximum_Subarray
我是看了思路,知道了关系公式才ac的
152的鼻祖,,,
编程珠玑讲的多一点
https://en.wikipedia.org/wiki/Kadane%27s_Algorithm
总结思考一下
## 274. H-Index
不知道为什么对的
没捋清
下标的问题,,,算法的逻辑
## 532_K-diff_Pairs_in_an_Array
选择合适的数据结构和思路
把时间复杂度从O(n^2)降到了O(n)
使用set记录<i,j>的排列  O(n^2)
使用map记录数字m的出现次数, find(m+k)
处理corner case 
k=0, empty list


## 416_Partition_Equal_Subset_Sum

## 187_Repeated_DNA_Sequences
三个关键点
+ 在所有长度为10的子字符串中搜索即可!
+ 使用hash搜索
+ 使用位操作,来hash编码,节省空间
位操作技巧用到了与或,异或的一些规律
根据i,计算需要的位移数
access特定的位

我一开始的思路,暴力搜索
```cpp
对每个子字符串在原字符串中搜索出现的次数
for sub_i in str
 mpa<str,int> str_cnt
 while True
  pos = s.find(sub_i,pos)     
  if(pos == string::npos)
   break;
  else
   ++pos;
   str_cnt[sub_i]++;                  
```
存在的问题是,空间复杂度太高,submi之后报错超时或内存不足

实际上,不需要在原字符串中每次pos+1去搜索
在所有长度为10的子字符串中搜索即可!

再然后,这个搜索可以hash,map来代替
相同的子字符串map之后得到同一hash值,map[key]++

### 再次改进
不用存map,根据count来返回结果
用set来存放key,遍历子字符串的时候,count, >1的时候insert
要用set 而非 vector存放key,不然count的时候超时
## 394_Decode_String
corner case
两个错误/两次提交失败,测试用例

+ `3[a2[b]] 3[2[b]]`
2[b]变成bb入栈的时候,栈顶可能是str也可能是[
+ 新入一个type1型的token的时候,也要判断栈顶是str还是[


怎么学会,用递归来自动处理corner case?
递归版这么短
https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C++-solution
```cpp
class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};
```

## 347_Top_K_Frequent_Elements
数据结构的胜利?
先遍历,map cnt
然后cnt map 我用的set
好像效率更高的solution用的是heap?? try it
## 338_Counting_Bits
题目提升不要使用标准库
但是我用了标准库,好像beats 98%
看一下,没用库的思路是什么
这个思路才是这个题目的意义
https://leetcode.com/problems/number-of-1-bits/description/
## 287_Find_the_Duplicate_Number
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right){
            int mid = (left + right) / 2;
            /*
            if (nums[mid] >= mid + 1){
                left = mid + 1;
            }
            else{
                right = mid;
            }
            */
            if (nums[mid] >= mid + 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left];
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        if (nums.empty())
            return -1;
            
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];

        }
        slow = 0;
        
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];

        }
        
        return slow;
    }
```
这些提交都什么道理?

Next challenges: First Missing PositiveSingle NumberLinked List Cycle IIMissing NumberSet Mismatch
## 233_Number_of_Digit_One
此问题要求一次遍历就得到结果
比如是要保留已经计算出的结果

core idea:`res[i] = left part * right part`

First, consider O(n) time and O(n) space solution.
then
O(n) time and O(1) space

从左向右遍历的时候
res[i]=left part
从右向左遍历的时候
res[i]=right part
## 075_Sort_Colors
couting sort 思路 o(2n) two pass
one pass的solution
一次遍历,in place sort
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), zero=0, two=n-1;
        for(int i=0;i<=two;){
            if(nums[i]==0){
                swap(nums[i],nums[zero]);
                zero++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[two]);
                two--;
            }
            else
                i++;
        }
    }
};
```
sort之后的nums是这样一个数组
[0000...111....2222]
zero two是1范围的左右边界
zero左边的都是0
two右边的都是1
i从0到two开始遍历
遇到0, 交换到zero左边, zero++, i++
遇到1, i++
遇到2, 交换到two右边, two--, i++
## 078_Subsets
给出一个list的所有子集
子集数是2^n
我是遍历0~(2^n-1),然后用bitset(i)
如果n=100,2^100这个数字已经无法用size_t表示了,也就无法遍历了
100个元素的list的所有子集就不能求了??
一定有其他高效的算法吧??
## 046_Permutations
给出一个长度为n的vector的全排列
我的思路
看成一个n位的n进制的数
全排列对应的数在0-n^n中
全排列各位之和=0+1+...+(n-1)
且全排列中不含重复元素
遍历0-n^n,根据进制转换,求得(i)的排列,
根据上述两条性质,判断次排列是不是一个全排列
000
001
002
010
011
012
.
.
.
222
## 001_Two_Sum
找到数组中哪两个数之和=目标值
我的naive的思路
$C_n^2=\frac{n(n-1)}{2}
两重for循环, 
判断
nums[i]+nums[j] ?= target $

最优解的思路,
空间换时间
把遍历过的value->index存起来
在map中find target-nums[i]

既然可以在map中在find,那么直接在原始数组中find(要注意判断!=i)会怎样
结果表明,比在find中慢
因为map find和vector find算法不同
## 002_add_two_numbers
这个题的解法和归并排序很像
但是我的写法
要在while loop 内部再判断一边条件
否则会多出一个node
因为我每次new 的 node是下一轮的
很丑陋
要想避免这个多出的判断,new 的node必须是用于这一轮的

怎么避免这一个多出的判断 -- 引入header node
第一次也尝试了,但是当时没写对,
```
header=new node
cur=header
while 
cur->next=new node
cur=cur->next
```
## sliding window pattern/双指针 思想
同样是滑动窗口的思路
我的solution还是没有别人的快?!
https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b
https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/sliding-window-algorithm-template-to-solve-all-the-leetcode-substring-search-problem
### 003_Longest_Substring_Without_Repeating_Characters.cpp

https://leetcode.com/submissions/detail/176867828/
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string max, curr;
        size_t lens=s.length();
        for (size_t i=0; i< lens; ++i)
        {
            size_t pos=curr.find(s[i]);
            if (pos != string::npos)
            {
                if (curr.length() > max.length()) max=curr;
                curr=curr.substr(pos+1);
            }
            curr+=s[i];
        }
        if (curr.length() > max.length()) max=curr;
        return max.length();
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> s1;
        int len = s.length();
        int i = 0, j = 0, max_len = 0;
        while (i < len)
        {
            if (s1.find(s[i]) == s1.end())
            {
                s1.insert(s[i]);
                i++;
                max_len = max(max_len, i - j);
            }
            else
            {
                s1.erase(s[j++]);
            }
        }
        return max_len;
    }
};
```
### 076_Minimum_Window_Substring
https://leetcode.com/submissions/detail/177087471/
### 438_Find_All_Anagrams_in_a_String
https://leetcode.com/submissions/detail/177085375/
## 007_Reverse_Integer
这是一道easy 难度的题目
但是却submit 了好几次,才ac
solution有两种
第一种是一步步取余数
代码简洁优雅
第二种是number->string->number
即
to_string stoi/stoll
需要注意int32_t/int64_t表示范围的判断
## 006_ZigZag_Conversion
官方给出的solution 有两种
+ Approach 1: Sort by Row
遍历string,每个string属于哪一行是确定的
```
for c in string
rows[row_number]=c
row_number++/--(topmost/bottommost 变号)
for row in rows
res += row
```
这个思路更简洁
+ Approach 2: Visit by Row
遍历行,每行都有哪些index属于这一行是确定的
## 005_Longest_Palindromic_Substring
一个长度为n的string共有n(n+1)/2个子字符串
这些子字符串的下标i,j是一个上三角矩阵
这些子字符串可以按长度k分为k=1层,k=2层..k=n层
+ 暴力解法
遍历每个子字符串,是O(n^2)
对每个子字符串判断是否回文,是O(n)
所以,暴力解法时间复杂度是O(n^3)
+ 动态规划
怎样利用已经计算过的信息,减少不必要的计算
怎么得到动态规划的关系式?
clue:k+1层子字符串可以利用k层子字符串的信息
利用动态规划,可以把暴力解法的O(n^3)降到O(n^2)
从超时变成ac
+ Expand Around Center
进一步降低空间复杂度到O(n^2),即不再需要dp中的表
思路转变
从所有substring中找回文-->从所有可能的center中找
所有substring是n^2, 
所有center却一共可能有2n-1个,对每个center向两边扩展,确定是否回文,复杂度O(n)
时间复杂度O(n^2)
+ Manacher's Algorithm