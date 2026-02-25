function greet(name, greeting) {
    if (greeting) {
        return "".concat(greeting, ",").concat(name, "!");
    }
    else
        return "hello,".concat(name);
}
console.log(greet("deepak"));
console.log(greet("deepak", "hello welcome back"));
function createUser(username, age, email) {
    var userInfo = "UserName: ".concat(username);
    if (age !== undefined) {
        userInfo += ",Age: ".concat(age);
    }
    if (email != undefined) {
        userInfo += ", email:".concat(email);
    }
    return userInfo;
}
console.log(createUser("deepak"));
console.log(createUser("deepak", 23, "deepak@gmail.com"));
console.log(createUser("deepak", 23));
console.log(createUser("deepak", undefined, "deepak@gmail.com"));
