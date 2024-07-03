// Link to the Problem : https://leetcode.com/problems/create-hello-world-function/
// Difficulty : Easy 

/**
 * @return {Function}
 */
/* Method 1 */
var createHelloWorld = function() {
    
    return function () {
        return "Hello World"
    }
};

/* Method 2 */
var createHelloWorld = () => {
    return () => "Hello World"
}

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */

