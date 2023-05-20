/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
  let cache;
  let pending = false;
  let res = (...args) => {
      if(!pending){
          cache = undefined;
          pending = true;
          setTimeout(()=>{
              pending = false;
              if(cache!==undefined){
                  res(...cache);
              }
          },t);
          fn(...args);
      } else {
          cache = args;
      }
  }
  return res;
};


/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */