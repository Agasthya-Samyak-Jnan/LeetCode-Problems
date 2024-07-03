
// Link to the Problem : https://leetcode.com/problems/counter/
// Difficulty : Easy

/**
 * @param {number} n 'n' is a normal variable declaration like we do in C/C++
 * @return {Function} counter
 */
var createCounter = function(n) {
    return () => n++;
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
