function greet(person:string):string;
function greet(person:string,age:number):string;

function greet(person:string,age?:number):string{
    if(age!==undefined){
        return `hello, ${person}! your age is ${age}`
    }
    return `Hello, ${person}`
}
console.log(greet("Alice"))
console.log(greet("deepak",23))


function combine(a:number,b:number):number;
function combine(a:string,b:string):string;

function combine(a:any,b:any):any{
    return a+b;
}
console.log(combine(2,3))
console.log(combine("deepak ","Vishwakarma"))


function fetchData(id:number):string;
function fetchData(query:string):string[];

function fetchData(param:any):any{
    if(typeof param==="number"){
        return `data for id: ${param}`
    }else{
        return [`return for query: ${param}`]
    }
}
console.log(fetchData(24))
console.log(fetchData("seaching itmes"))