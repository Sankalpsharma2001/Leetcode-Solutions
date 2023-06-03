/**
 * @return {Function}
 */
 var hello = "Hello World"
var createHelloWorld = function() {

    return function() {
        
    return hello = "Hello World"; }
};
/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */