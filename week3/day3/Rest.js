function sum() {
    var numbers = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        numbers[_i] = arguments[_i];
    }
    var ans = 0;
    for (var i = 0; i < numbers.length; i++) {
        ans += numbers[i];
    }
    return ans;
}
console.log(sum(2, 3, 4, 1, 3, 4));
function joinString(jobTitle) {
    var strings = [];
    for (var _i = 1; _i < arguments.length; _i++) {
        strings[_i - 1] = arguments[_i];
    }
    return "".concat(strings.join(', '), " are ").concat(jobTitle);
}
console.log(joinString("MTS", "deepak", "vishwakarma") + " are student");
