
// Link to the Problem : https://leetcode.com/problems/counter-ii/
// Difficulty : Easy

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var org = init
    return {
        increment : () => { return ++init; } , 
        decrement : () => { return --init; } ,
        reset : () => { init = org; return init; }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */