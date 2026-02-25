// name funtion
function add(a:number,b:number):number{
    return a+b
}

//2️⃣ Anonymous Function
const sub=function(a:number,b:number):number{
    return a-b;
}
console.log(add(2,3))
console.log(sub(4,3))

//arrow funtion and Default Parameter
const mul=(a:number,b:number=5):number =>{
    return a*b
}
console.log(mul(2));
console.log(mul(3,4));

// void return type
function logMessage(message:string):void{
    console.log("this is log file: "+message);
}
logMessage("server is running okay");

//Rest Parameters

function sum(...numbers:number[]):number{
    return numbers.reduce((acc,curr)=>acc+curr);
}

console.log(sum(2,3,4,2,1));

// function fun(person:string):string;
// function fun(person:string,age:number):string;

function fun(person:string,age?:number):string{
    if(age!=undefined){
        return `hello, ${person},you are ${age} year old!`;
    }
    return `hello, ${person}`
}
console.log(fun("deepak"));
console.log(fun("deepak",23));

function performOperation(a:number,b:number,callbacks:(result:number)=>void){
    let result=a+b;
    callbacks(result);
}
performOperation(2,3,(result)=>{
    console.log("this is ans: "+result);
})

