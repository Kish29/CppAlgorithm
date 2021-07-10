//
// Created by 蒋澳然 on 2021/7/10.
// 二分查找框架
//

#include "BasicSTL.h"

#ifndef CPPALGORITHM_BSTEMPLATE_H
#define CPPALGORITHM_BSTEMPLATE_H

// be sure that nums is a sorted array
class BinarySearch {

public:

    // 左边界查找，若数组中由多个值满足target，返回最左边的那个
    int leftBound(const vector<int> &nums, int target) const {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 健壮性
            try {
                if (nums.at(mid) == target) {
                    right = mid;
                } else if (nums.at(mid) < target) {
                    left = mid + 1;
                } else if (nums.at(mid) > target) {
                    right = mid;
                }
            } catch (std::out_of_range &e) {
                cout << e.what() << endl;
            }
        }
        // 假设有一个数比数组中任何一个都要大，那么left最终等于数组大小
        return left == nums.size() ? -1 : left;
    }

    // 右边界查找，若数组中由多个值满足target，返回最右边的那个
    int rightBound(const vector<int> &nums, int target) const {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            try {
                if (nums.at(mid) == target) {
                    left = mid + 1;
                } else if (nums.at(mid) < target) {
                    left = mid + 1;
                } else if (nums.at(mid) > target) {
                    right = mid;
                }
            } catch (std::out_of_range &e) {
                cout << e.what() << endl;
            }
        }
        // 假设有一个数比数组中任何一个都要小，那么left最终等于0
        return left - 1;
    }

    // 规范的二分查找，建议
    int binarySearch(const vector<int> &nums, int target) const {
        int left = 0;
        int right = (int) nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            try {
                if (nums.at(mid) == target) {
                    return mid;
                } else if (nums.at(mid) < target) {
                    left = mid + 1;
                } else if (nums.at(mid) > target) {
                    right = mid - 1;
                }
            } catch (std::out_of_range &e) {
                // record error log
                cout << e.what() << endl;
            }
        }
        return -1;
    }

};

#endif
