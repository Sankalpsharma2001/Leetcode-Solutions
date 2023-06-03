/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    final = {};

    for(const x of this){
        final[fn(x)] = final[fn(x)] || [];
        final[fn(x)].push(x);
    }

    return final;
};
/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */