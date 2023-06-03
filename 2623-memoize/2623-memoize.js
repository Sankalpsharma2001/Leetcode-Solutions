/**
 * @param {Function} fn
 */
function memoize(fn) {
     let cache={};
    return function(...args) {
        let key=JSON.stringify(args);//Since the arguments are an array of numbers (i.e. valid JSON), a convenient way to convert them into a string key is with JSON.stringify().
        if(key in cache){
            return cache[key];
        }else{
            let ans=fn(...args);
            cache[key]=ans;
            return ans;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */