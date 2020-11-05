/* ------------------------------------------------------------------|
给出一个区间的集合，请合并所有重叠的区间。

 

示例 1:

输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：56 ms, 在所有 C++ 提交中击败了66.55%的用户
*	内存消耗：14.9 MB, 在所有 C++ 提交中击败了14.28%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int left = intervals[0][0];
    int right = intervals[0][1];


    for (auto x : intervals) {
        if (x[0] > right || x[1] < left) {
            res.push_back({ left,right });
            left = x[0];
            right = x[1];
        }
        else {
            left = min(left, x[0]);
            right = max(right, x[1]);
        }
    }
    res.push_back({ left,right });

    return res;
}