/**
 * @return {Function}
 */
var createHelloWorld = function() {
    

    
    return function(...args) {
        var t='Hello World';
        return t;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */