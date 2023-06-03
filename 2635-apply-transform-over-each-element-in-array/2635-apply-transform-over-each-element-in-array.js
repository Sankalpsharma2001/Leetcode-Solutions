/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newarr = [];
    for(let i =0;i<arr.length;i++){
        let elem= fn(arr[i], i)
        newarr.push(elem);
    }
    return newarr
};