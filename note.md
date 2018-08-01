[TOC]

reference

https://github.com/yanzhe-chen/leetcode

LintCode & LeetCode 题解分析 tag分类
https://legacy.gitbook.com/book/aaronice/lintcode/details

http://zxi.mytechroad.com/blog/greedy/leetcode-621-task-scheduler/

http://fisherlei.blogspot.com/



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