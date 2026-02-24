
// type annotation
let myName: string = "deepak";
let age: number = 22;
let isStudent: boolean = true;
const array:(number|string)[]=["GFG", "TypeScript", 500, 20];

console.log("My name is " + myName + " and I am " + age + " years old");

function mul(a:number,b:number):number{
    return a*b;
}
let res=mul(2,3);
console.log(res);

let id: number|string;
id=101;
console.log(id);
id="A101";
console.log(id);

let arr:number[]=[10,20,30,102,32];
for(let i=0;i<arr.length;i++){
    console.log(arr[i]);
}

interface User{
    myName:string;
    age:number;
}

let user1:User={
    myName:"deepak",
    age:20
}

console.log(user1);


class Exployee{
    salary:Number;
    constructor(salary:Number){
        this.salary=salary;
    }
    printSalary():void{
        console.log("this is saltary: "+this.salary);
    }
}

let e1=new Exployee(1000);
e1.salary=2000;
e1.printSalary();


let x:any=123;
console.log(x)
x="deepak"
console.log(x);
x=true;
console.log(x);

function fun():void{
    console.log();
    return ;
}

console.log(fun());

const person:{myName:string,age:number}={
    myName:"deepak",
    age:23
}
console.log(person);
// person["age"]="23";