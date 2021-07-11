//
// Created by 蒋澳然 on 2021/7/12.
// email: 875691208@qq.com
// $desc
//

#include "BasicSTL.h"

/* 278. 第一个错误的版本 */
/* 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用bool isBadVersion(version)接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例 1：

输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false
调用 isBadVersion(5)-> true
调用 isBadVersion(4)-> true
所以，4 是第一个错误的版本。
示例 2：

输入：n = 1, bad = 1
输出：1

 * */

bool isBadVersion(int version);

// left_bound 左边界收缩
int firstBadVersion(int n) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

/* 704. 二分查找 */
/* 给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 * */

int search(const vector<int> &nums, int target) {
    int left = 0, right = (int) nums.size() - 1;
    try {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums.at(mid) == target) {
                return mid;
            } else if (nums.at(mid) < target) {
                left = mid + 1;
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            }
        }
    } catch (std::out_of_range &e) {
        // do something
    }
    return -1;
}