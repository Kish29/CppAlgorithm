//
// Created by 蒋澳然 on 2021/7/10.
// email: 875691208@qq.com
//
//

#include "BasicSTL.h"

/* LeetCode 496*/
/* 单调栈 */
/*
 * 给你两个 没有重复元素 的数组nums1 和nums2，其中nums1是nums2的子集。

请你找出 nums1中每个元素在nums2中的下一个比其大的值。

nums1中数字x的下一个更大元素是指x在nums2中对应位置的右边的第一个比x大的元素。如果不存在，对应位置输出 -1 。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
   对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

 * */

class Solution {
public:

    unordered_map<int, int> ms(vector<int> &nums) const {
        unordered_map<int, int> res;
        stack<int> msStack;
        try {
            int sz = (int) nums.size();
            // 在循环变量体里，要时刻记住，不要用unsigned long，否则当i=0时，i-1变成unsigned_long.MAX_VALUE !!!
            for (int i = (int) sz - 1; i >= 0; i--) {
                while (!msStack.empty() && msStack.top() <= nums.at(i)) {
                    msStack.pop();
                }
                res.insert(std::make_pair(nums.at(i), msStack.empty() ? -1 : msStack.top()));
                msStack.push(nums.at(i));
            }
        } catch (std::out_of_range &e) {
            std::cout << e.what() << std::endl;
        }
        return res;
    }

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> larger = ms(nums2);
        vector<int> res(nums1.size());
        try {
            unsigned long sz = nums1.size();
            for (int i = 0; i < sz; i++) {
                res.at(i) = larger.at(nums1.at(i));
            }
        } catch (std::out_of_range &e) {
            std::cout << e.what() << std::endl;
        }
        return res;
    }
};