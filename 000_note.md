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
https://leetcode.com/problems/valid-number/description/

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
看一下讨论...
https://leetcode.com/problems/subsets/discuss/
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
## 008_String_to_Integer
动手之前仔细构思一下/写完重构一下
代码可以写的更简洁
一次遍历,遍历的同时求累加和
overflow的时候停止遍历,return
"2357"->2357的算法
不必是 `7+ 5*10+3*100+2*1000`
(这个思路导致了,
遍历得到完整的数字串,然后从右向左取每一位求和的写法
依靠完整数字串的长度来判断overflow又要额外处理
0000000000000这种情况,很笨的思路
)
可以是 `0*10+2=2,2*10+3=23,23*10+5=235,235*10+7=2357`
这种写法
不需要依靠完整数字串的长度来判断overflow
不需要考虑"0000000000000"这种情况

判断overflow
由于int_max和int_min不对称,因此
看起来,要根据正负的情况分别考虑
```c++
//v1,不太直观
求sum之前,判断
if (sum > (INT_MAX- ((str[index]-'0'))) / 10)
return (plus==1) ? INT_MAX: INT_MIN; 

//v2,分别判断,不太简洁
if(sum*plus >= INT_MAX) return INT_MAX;
if(sum*plus <= INT_MIN) return INT_MIN;

//v3,简洁直观
求sum之后,判断
int_max  2147483647
int_min -2147483648
看起来,要根据正负的情况分别考虑
+/-2147483647是对称的,需要考虑的是
-2147483648这个值
|int_min| > int_max
按照overflow处理,结果一样
if(sum > INT_MAX)
return (plus==1) ? INT_MAX: INT_MIN;
```
## 3sum,4sum,求和系列
基础知识, 排列组合
$P_n^m=(n-0)(n-1)(n-2)\cdots(n-(m-1))\\
C_n^m=\frac{P_n^m}{m!}$
所以,
从n个数里任取两个,是O(n^2)
从n个数里任取三个,是O(n^3)
3sum 面试
https://zhuanlan.zhihu.com/p/24681450
https://en.wikipedia.org/wiki/3SUM
https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments
vector<vector<int> > threeSum(vector<int> &num) 
{
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) 
    {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) 
        {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else 
            {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) rear--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
## 排列组合
## 493_Reverse_Pairs
笨办法/brute force 
遍历所有pair, 需要$O(n^2)$
基本idea
如果
$T(n)=T(\frac{n}{2})+T(\frac{n}{2})+O(n)\\
则T(n)=O(nlogn)$

//这个公式很厉害,不需要具体的代码实现和算法思路
//就知道了算法时间复杂度比$O(n^2)$低了


问题怎么分?
输入是一个长度为n的数组
分成左一半,右一半
假设我已经知道了怎么算left part和right part的逆序数
现在还需要算 left right之间的逆序对
所以,
combine (合)的时候,怎么实现O(n)呢?
idea:
如果left/right part 已经有序
那么按照归并排序的思路
遍历一遍,就能知道left,right之间的逆序对数目!

为什么遍历一遍,就能知道所有逆序对?

### 归并排序
怎样优雅的实现归并排序?
```
for (; first1 != last1; ++d_first) {
    if (first2 == last2) {
        return std::copy(first1, last1, d_first);
    }
    if (*first2 < *first1) {
        *d_first = *first2;
        ++first2;
    } else {
        *d_first = *first1;
        ++first1;
    }
}
return std::copy(first2, last2, d_first);
```
while
if ...
if ...
怎么调用算法库中的归并排序
从std::merge+copy
到std::inplace_merge
```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return reversePairs(nums.begin(), nums.end());
    }

    int reversePairs(vector<int>::iterator a, vector<int>::iterator b) {
        if (b - a <= 1) return 0;
        auto mid = (distance(a, b) >> 1) + a;
        int vl = reversePairs(a, mid);
        int vr = reversePairs(mid, b);
        int vm = 0;
        for (auto pl = a, pr = mid; pr < b; ++pr) {
            while ((int64_t)*pl <= *pr * (int64_t)2 && pl < mid) ++pl;
            vm += distance(pl, mid);
        }
        inplace_merge(a, mid, b);
        return vl + vr + vm;
    }
};
```
学习排名第一的实现的代码:
我们的思路是一样的,但是显然,这个实现更简洁

+ 我怎么不知道 inplace_merge 这个函数,
+ 函数签名用iterator begin, end  代替 nums, left, right
+ 用四行代码代替了我的helper函数
### profile
要根据场景从算法库中选择sort算法
profile一下
left right 已经有序的情况下
sort 和 inplace merge 的时间复杂度
确实有必要弄清
quicksort merge 
的平均,最好,最坏,时间复杂度
合适会蜕化
quicksort 不是万能的,,

## 017_Letter_Combinations_of_a_Phone_Number
给出未知长度的元素的组合
不知道长度,就不知道写多少重循环
对此,可以用递归解决
问题怎样分,怎样合 这一思想的胜利

backtracking ??
## 019_Remove_Nth_Node_From_End_of_List
循环不变量

二级指针覆盖
pre->next = cur->next

分情况,为什么正确,,

free vs delete
cppman std::free
## 021_Merge_Two_Sorted_Lists
摆脱
```c++
while(l1 & l2)
if(l1)
if(l2)
```
的写法
使用
```c++
for(;l1 1= null)
{
    if(l2 == null)
      return 
}
//l1 == null
return

while (l1 && l2) {
    if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
    } else {
        tail->next = l2;
        l2 = l2->next;
    }
    tail = tail->next;
}

tail->next = l1 ? l1 : l2;
```
https://leetcode.com/problems/merge-k-sorted-lists/description/
https://leetcode.com/problems/merge-sorted-array/description/
https://leetcode.com/problems/sort-list/description/

## 020_Valid_Parentheses
使用stack解决这一问题

看一下官方的思路
https://leetcode.com/articles/valid-parentheses/#

https://leetcode.com/problems/generate-parentheses
https://leetcode.com/problems/longest-valid-parentheses
https://leetcode.com/problems/remove-invalid-parentheses
## 022_Generate_Parentheses
bruteforce
backtracing
算法课上的思路,,剪枝??
看一下官方的solution
https://leetcode.com/articles/generate-parentheses/#
## 024_Swap_Nodes_in_Pairs.cpp
从最简单的case 入手
两个我会不会做,
三个我会不会做
结果怎么合
算法课上学到的思路的胜利

## 215_Kth_Largest_Element_in_an_Array
找数组中第k大的元素

sort(nums.rbegin(), nums.rend());
为什么这样就是 降序了?

用sort是很显然可行的
但是没必要

查看其他solution
std::nth_element - nth_element is a partial sorting algorithm that rearranges elements in [first, last)
std::partition 
这些都是干嘛的?

## Remove系列
### 026_Remove_Duplicates_from_Sorted_Array
去除 有序数组中的重复元素(只保留一个),类似std::unique
[0,0,1,1,1,2,2,3,3,4]->[0,1,2,3,4,?,?,?,?,?]
It doesn't matter what you leave beyond the returned length.
这个要求和v.erase(unique(v.begin,v.end), v.end)中的操作是对应的

思路:双指针,快指针和慢指针
我的思路:
loop invariant:counter
property
index: c-2,c-1,c,...,i-1,i
value: x  ,a  ,a,...,  a,b
counter左边,[0,counter)是已经满足去重性质的部分
counter是待插入位置,遇到`nums[i] != nums[i-1]`的情况
说明来到了连续元素的开始区,插入,++
条件进一步从`nums[i] != nums[i-1]`  
改为`nums[i] != nums[counter-1]`是等价的
因为, nums[c-1,i-1]范围内的值是连续的等值

### 027_Remove_Element
去除数组中的指定元素,类似std::remove
remove([0,1,2,2,3,0,4,2],2)->[0,1,3,0,4]
我的思路:和026类似
条件变为`nums[i] != val`
上述算法 存在问题 **when elements to remove are rare**
数组赋值次数等于 不需要remove的元素的个数
如果要remove的元素很少,那么就会有很多没必要的数组赋值
when elements to remove are rare
数组赋值次数要等于 number of elements to remove
发生赋值的判断条件要改为`nums[i] == val`
这就是solution中的另一算法
### 080_Remove_Duplicates_from_Sorted_Array_II
问题和026类似,区别在于,
026中重复元素保留一个
080中重复元素保留两个
数组赋值条件也从
026中的`if( nums[i] != nums[counter-1])`
修改为`if( nums[i] != nums[counter-2])`即可
why
026中loop invariant:c性质如下
index: c-2,c-1,c,...,i-1,i
value: x  ,a  ,a,...,  a,b
nums[i]和nums[c-1]比,
080中loop invariant:c保证
c左边部分重复元素最多出现两次
那么无非两种可能
index: c-2,c-1,c,...,i-1,i
case1: x  ,a  ,         
case2: a  ,a  ,
nums[i]只要和nums[c-2]不等,即可进行数组赋值


https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
## 282_Expression_Add_Operators.cpp
backtracking
https://leetcode.com/problems/expression-add-operators/solution/#
## 28_Implement_strStr()
strstr implementation
https://www.google.com/search?q=strstr+implementation
kmp 
rabin karp ??
## 206_Reverse_Linked_List
题目描述:转置链表
我的思路:
遍历链表,使用头插法到另一个head
然后return head->next

官方solution 遍历迭代版本

分析转置之前
`ppre <- pre->cur->next -> nnext`
cur之前的元素已经转置完毕,现在处理到cur
转置之后
`ppre <- pre <- cur -- next ->nnext`
即 把cur的next指针指向pre
由于是单链表,要保存pre
欲向前遍历,要保存一个tempNext
```c++
tempNext=cur->next
cur->next = pre
pre=cur
cur=temp
```
官方solution 递归版本
把单链表分成两部分
head->head'sNext
```c++
//注意递归中栈底情况的判断
reverse(head'sNext)
head->next->next=head
```

## 074/240 search 2d matrix
问题描述,在一个给定矩阵中查找某一模板是否存在
第一个问题中矩阵的性质,074
每行有序,每行第一个大于上一行最后一个
即,矩阵按行排列是有序的,因此可以使用二分查找
根据下标转换,把整个矩阵当成一个有序数组,手动进行二分查找
如果仅仅使用每行有序的性质,则可以
for-atuo矩阵,对每行使用std::binary_search查找
第二个问题中矩阵的性质,240
每行有序,每列有序
但是,按行排列,矩阵并不是有序的
对于元素A[i][j]/e有,e的左边都比它小,e的下边都比它大
因此,可以这么查找
A[i][j]从A[0][n-1],即矩阵右上角开始
在左下部分查找target
分 =/>/<的情况
每次只要不等,向左移动一列,或向下移动一行
原问题变为一个规模变小的子问题
时间复杂度为O(m+n)
recommend
https://leetcode.com/problems/dungeon-game/description/
https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
https://leetcode.com/problems/valid-perfect-square/description/
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
https://leetcode.com/problems/nth-magical-number/description/

## 496_Next_Greater_Element_I
A是一个整数数组,B是A的子集
B[j]对应A[i],找到A(i...n)中第一个大于A(i)的元素
记x=B[j]=A[i]  f(x)=Next Greater Element of x
最直观的解法, O(n^2) 使用map
遍历A[,得到map M[A[i]] = i
然后遍历B, 记k=M[B[j]] 
从k到 n-1遍历 A ,找到目标值
但这并不是最优的解法
这是一个stack tag的题目,却没用到stack
改进的解法 使用map+stack
在遍历A的时候,
就通过栈建立了map
这个map直接从 A[i] 映射  f(A[i])
而不是在普通解法中 映射 A[i]
怎么做到的?
遍历A:for e in A
栈中存储着e左边的元素
每次把栈中比e小的元素k都pop出去,建立映射M[k]=e
然后把e入栈
```c++
for (int n : nums) {
    while (s.size() && s.top() < n) {
        m[s.top()] = n;
        s.pop();
    }
    s.push(n);
}
```
https://leetcode.com/problems/next-greater-element-ii
https://leetcode.com/problems/next-greater-element-iii
https://leetcode.com/problems/daily-temperatures

## Single Number
BitManipulation
### 异或操作的性质
0. `x^0 = x 且 x^x = 0`
1. 交换律
2. 结合律
结合律的证明 (A^B)^C=A^(B^C)
往往要依赖把表达式两边展开,最终相等
要想展开,就需要知道 A^B=(A'B+AB')
或者`x ^ y == (~x & y) | (x & ~y)`
3. **自反性质**
是异或最重要的性质,我竟然不知道...
并且我也不能从结合律和A^0=A这一点推出来
不引人临时变量交换两个整数的值,就依赖
异或操作的自反性质
自反性质指的是什么?
a^b^b=(a^(b^b)=a^0)=a
即,一个数和同一个数两次异或,不变 
这个顺序可以根据交换律和结合律来任意调整

### 136_Single_Number1
一个整数数组中,有一个元素出现了一次,其他的出现了两次
找出这个元素
如果不要求常数空间和线性时间复杂度
这确实是一个easy level的题目
想要以S(1)+O(n)条件找到这个数
就需要用到前边补充的异或的自反性质

到后边,的single number 2/3
感觉已经变成了智力,数学题了,,

### Single Number2
http://artori.us/exclusive-or/
### Single Number3
## 268. Missing Number
问题描述
长度为n的数组A
存放了0 1 2 ... n这n+1个数中的n
找到哪个数没存
求sum(0,n)-sum(A) 即可找到 missing number

如果求和溢出的话
可以用前边异或的自反性质

## 070. Climbing Stairs
每次上一层或两层,楼梯有多少种爬法
用动态规划算法解决此问题
动态规划怎么用的?
问题有最优子结构的性质
As we can see this problem can be broken into subproblems, and it contains the optimal substructure property i.e. its optimal solution can be constructed efficiently from optimal solutions of its subproblems, we can use dynamic programming to solve this problem.
The key intuition to solve the problem 
There is NO overlapping between these two solution sets, because we differ in the final step
问题输入的结构
总是假设我们已经找到了问题的解法
爬n层楼梯有A(n)种爬法
找合适的分点,A(n)和子问题的关系
把问题当成决策的过程
分类用加法,分步用乘法
分类
第一步上一层+剩下n-1层的爬法A(n-1)
第一步上二层+剩下n-2层的爬法A(n-2)
A(n)=A(n-1)+A(n-2)
问题的解还是一个斐波那契数列
这是一个easy level的题目
我的错误的思路,是怎么回事
## 121_Best_Time_to_Buy_and_Sell_Stock
问题描述
给定一个数组,第i个元素记录了第i天的股价
限定只能买入卖出一次
找到利润最大的买入卖出时间对(i,j)

最笨的方法,暴力枚举
所有的(i,j)组合,时间复杂度$C_n^2$

实际上,答案(i,j)是确定的
即在最低的那天的买入,在之后的最高的那天卖出
one pass 记录当前是不是最低,当前卖出是不是最大利润

用动态规划解决此问题`Opt(0,n)=max{f(0,x), Opt(1,n)}`
思路也没问题,但是时间复杂度上并不是最优的$T(n)=O(n)+T(n-1)$
