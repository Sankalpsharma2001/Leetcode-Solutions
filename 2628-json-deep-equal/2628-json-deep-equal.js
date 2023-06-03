/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    // If two primitive data types and they are equal
    if (o1 === o2)
      return true;
    
    // If one obj is array and other is object with same keys returns false
    // And also the case where primitive data types are not equal
    if (String(o1) !== String(o2))
      return false;

    // Same logic goes for array and objects
    if (Object.keys(o1).length !== Object.keys(o2).length)
      return false;
    for (const key in o1) 
        if (!areDeeplyEqual(o1[key], o2[key]))
          return false;
    
    return true;
};

