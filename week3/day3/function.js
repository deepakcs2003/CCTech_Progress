// name funtion
function add(a, b) {
    return a + b;
}
//2️⃣ Anonymous Function
var sub = function (a, b) {
    return a - b;
};
console.log(add(2, 3));
console.log(sub(4, 3));
//arrow funtion and Default Parameter
var mul = function (a, b) {
    if (b === void 0) { b = 5; }
    return a * b;
};
console.log(mul(2));
console.log(mul(3, 4));
// void return type
function logMessage(message) {
    console.log("this is log file: " + message);
}
logMessage("server is running okay");
//Rest Parameters
function sum() {
    var numbers = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        numbers[_i] = arguments[_i];
    }
    return numbers.reduce(function (acc, curr) { return acc + curr; });
}
console.log(sum(2, 3, 4, 2, 1));
// function fun(person:string):string;
// function fun(person:string,age:number):string;
function fun(person, age) {
    if (age != undefined) {
        return "hello, ".concat(person, ",you are ").concat(age, " year old!");
    }
    return "hello, ".concat(person);
}
console.log(fun("deepak"));
console.log(fun("deepak", 23));
function performOperation(a, b, callbacks) {
    var result = a + b;
    callbacks(result);
}
performOperation(2, 3, function (result) {
    console.log("this is ans: " + result);
});
