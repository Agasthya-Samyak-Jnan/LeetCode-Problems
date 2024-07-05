// Link to the Problem : https://leetcode.com/problems/array-reduce-transformation/
// Difficulty : Easy

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    for (i=0;i<nums.length;i++) {
        init = fn(init,nums[i]);
    }
    return init;
};