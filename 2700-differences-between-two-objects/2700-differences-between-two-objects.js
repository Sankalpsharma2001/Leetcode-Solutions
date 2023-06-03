/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
function objDiff(obj1, obj2) {
    function compareValues(value1, value2) {
        // If either value is not defined, skip it
        if (typeof value1 === 'undefined' || typeof value2 === 'undefined') return;

        // If the value types don't match, output the different values. Array.isArray is also checke because typeof of an object or an array is 'object'
        if (typeof value1 !== typeof value2 || Array.isArray(value1) !== Array.isArray(value2)) {
            return [value1, value2];
        }

        // If both values are an array we need further checks of the array values against each other
        if (Array.isArray(value1) && Array.isArray(value2)) {
            // If either array is empty, it won't have values to compare and we can skip it
            if (!value1.length || !value2.length) return;

            const diff = {};

            for (let i = 0; i < value1.length; i++) {
                // Recursively call compareValues to compare the values in the array
                const comparedValue = compareValues(value1[i], value2[i]);
                // If compareValues returns any differences, store them in an object using the index as the key
                if (comparedValue) diff[i] = comparedValue;
            }

            // Check if diff contains any actual differences, and return it if it does
            if (Object.keys(diff).length) return diff;
            // Otherwise bail out because no further checks are needed
            return;
        } 
        
        // If both values are objects check their properties (we can ignore the typeof array === object problem because we already checked for arrays)
        if (typeof value1 === 'object' && typeof value2 === 'object') {
            // If either object is empty it has nothing to compare and we can ignore it
            if (!Object.keys(value1).length && !Object.keys(value2).length) return;

            // Recursively call compareValues to check properties against each other
            const diff = Object.keys(value1).reduce((acc, key) => {
                const val1 = value1[key];
                const val2 = value2[key];

                const comparedResult = compareValues(val1, val2);

                // If a difference is returned, store it using the object key
                if (comparedResult) {
                    acc[key] = comparedResult;
                }

                return acc;
            }, {});

            // Check if diff contains any actual differences, and return it if it does
            if (Object.keys(diff).length) return diff;
            // Otherwise bail out because no further checks are needed
            return;
        } 
        
        // Compare primitive values agaiinst one another and return the diff array if they don't match
        if (value1 !== value2) {
            return [value1, value2];
        }
    }


    // Return an object of differences after comparing each property using compareValues
    return Object.keys(obj1).reduce((acc, key) => {
        const value1 = obj1[key];
        const value2 = obj2[key];

        const comparedResult = compareValues(value1, value2);

        if (comparedResult) {
            acc[key] = comparedResult;
        }

        return acc;
    }, {});
};