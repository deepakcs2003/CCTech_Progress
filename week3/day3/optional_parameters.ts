
function greet(name:String,greeting?:string):string{
    if(greeting){
        return `${greeting},${name}!`
    }else
    return `hello,${name}`
}
console.log(greet("deepak"));
console.log(greet("deepak","hello welcome back"));


function createUser(username:string,age?:number,email?:string):string{
    let userInfo=`UserName: ${username}`
    if(age!==undefined){
        userInfo+=`,Age: ${age}`
    }
    if(email!=undefined){
        userInfo+=`, email:${email}`
    }
    return userInfo;
}
console.log(createUser("deepak"))
console.log(createUser("deepak",23,"deepak@gmail.com"))
console.log(createUser("deepak",23));
console.log(createUser("deepak",undefined,"deepak@gmail.com"));