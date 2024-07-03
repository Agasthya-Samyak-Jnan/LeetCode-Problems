
// Link to the Problem : https://leetcode.com/problems/is-object-empty/
// Difficulty : Easy

// @param {Object|Array} obj
// @return {boolean}

/* Using "Object.keys(obj)" Method  */
var isEmpty = function(obj) {
    if (Object.keys(obj).length == 0) { return true; }
    else { return false; }
};

/* _.isEmpty() Method */
var isEmpty = function(obj) {
    if (_.isEmpty(obj)) { return true; }
    else { return false; }
};
