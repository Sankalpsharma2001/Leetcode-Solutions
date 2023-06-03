var throttle = function (fn, t) {
    let curArgs = null
    let delay = null

    return function throttler(...args) {
        if (delay) curArgs = args
        else {
            fn(...args)
            delay = setTimeout(_ => {
                delay = null
                if (curArgs) {
                    throttler(...curArgs)
                    curArgs = null
                }
            }, t)
        }
    }
}