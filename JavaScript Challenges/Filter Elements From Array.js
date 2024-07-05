// Link to the Problem : https://leetcode.com/problems/filter-elements-from-array/
// Difficulty : Easy

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var newarr = [];
    for (i=0;i<arr.length;i++) {
        if (fn(arr[i],i)) {newarr.push(arr[i]); }
    }
    return newarr;
};