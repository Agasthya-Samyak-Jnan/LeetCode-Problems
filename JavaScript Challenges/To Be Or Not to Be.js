
// Link to the Problem : https://leetcode.com/problems/to-be-or-not-to-be/
// Difficulty : Easy


/* HOW TO RETURN  MULTIPLE FUNCTIONS FROM A SINGLE FUNCTION - CLOSURES AND FUNCTIONS IN JS */

/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return { 
        toBe: (val2) => {
            if (val === val2) { return true; }
            else { throw new Error("Not Equal"); }
        } , // Comma Here is VERY VERY IMPORTANT
            // Think of this Comma like this : An array of Functions,seperated by Commas.
        notToBe: (val2) => {
            if (val !== val2) { return true; }
            else { throw new Error("Equal"); }
        }
    }  
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */