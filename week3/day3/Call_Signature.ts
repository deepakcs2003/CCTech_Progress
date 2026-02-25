 type GreetingFuntion={
    (name:string):string,
    description:string
 }

 const greet:GreetingFuntion=(name:string)=>{
    return `hello,${name}`;
 }

 greet.description="A funtion to greet users"
 console.log(greet("deepak"))
 console.log(greet.description);


 type calculator={
    (a:number,b:number):number;
    operation:string
 }
 //addition funtion
const add:calculator=(a:number,b:number)=>{
    return a+b;
 }
add.operation="Addition"

const multiply:calculator=(a:number,b:number)=>{
    return a*b;
}
multiply.operation="Multiplication"

// adding  propetry
console.log(`${add.operation}: ${add(4,3)}`);
console.log(`${multiply.operation}:${multiply(3,4)}`);
