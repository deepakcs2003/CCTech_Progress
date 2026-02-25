var greet = function (name) {
    return "hello,".concat(name);
};
greet.description = "A funtion to greet users";
console.log(greet("deepak"));
console.log(greet.description);
//addition funtion
var add = function (a, b) {
    return a + b;
};
add.operation = "Addition";
var multiply = function (a, b) {
    return a * b;
};
multiply.operation = "Multiplication";
// adding  propetry
console.log("".concat(add.operation, ": ").concat(add(4, 3)));
console.log("".concat(multiply.operation, ":").concat(multiply(3, 4)));
