
// Link to the Problem : https://leetcode.com/problems/return-length-of-arguments-passed/
// Difficulty : Easy

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
/* "Object.keys(obj)" Method treats "args" as an object containing set of arguments and length function returns number of elements in it. */
var argumentsLength = function(...args) {
    return Object.keys(args).length
};

/* Best Solution */
var argumentsLength = (...args) => args.length

/**
 * argumentsLength(1, 2, 3); // 3
 */