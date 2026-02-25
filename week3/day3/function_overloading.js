function greet(person, age) {
    if (age !== undefined) {
        return "hello, ".concat(person, "! your age is ").concat(age);
    }
    return "Hello, ".concat(person);
}
console.log(greet("Alice"));
console.log(greet("deepak", 23));
function combine(a, b) {
    return a + b;
}
console.log(combine(2, 3));
console.log(combine("deepak ", "Vishwakarma"));
function fetchData(param) {
    if (typeof param === "number") {
        return "data for id: ".concat(param);
    }
    else {
        return ["return for query: ".concat(param)];
    }
}
console.log(fetchData(24));
console.log(fetchData("seaching itmes"));
