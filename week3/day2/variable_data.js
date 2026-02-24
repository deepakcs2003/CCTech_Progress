// type annotation
var myName = "deepak";
var age = 22;
var isStudent = true;
var array = ["GFG", "TypeScript", 500, 20];
console.log("My name is " + myName + " and I am " + age + " years old");
function mul(a, b) {
    return a * b;
}
var res = mul(2, 3);
console.log(res);
var id;
id = 101;
console.log(id);
id = "A101";
console.log(id);
var arr = [10, 20, 30, 102, 32];
for (var i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}
var user1 = {
    myName: "deepak",
    age: 20
};
console.log(user1);
var Exployee = /** @class */ (function () {
    function Exployee(salary) {
        this.salary = salary;
    }
    Exployee.prototype.printSalary = function () {
        console.log("this is saltary: " + this.salary);
    };
    return Exployee;
}());
var e1 = new Exployee(1000);
e1.salary = 2000;
e1.printSalary();
var x = 123;
console.log(x);
x = "deepak";
console.log(x);
x = true;
console.log(x);
function fun() {
    console.log();
    return;
}
console.log(fun());
var person = {
    myName: "deepak",
    age: 23
};
console.log(person);
person["age"] = "23";
