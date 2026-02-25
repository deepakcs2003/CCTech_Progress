function sum(...numbers:number[]):number{
    let ans:number=0;
    for(let i=0;i<numbers.length;i++){
        ans+=numbers[i];
    }
    return ans;
}


console.log(sum(2,3,4,1,3,4,))

function joinString(jobTitle:string,...strings:string[]):string{
    return `${strings.join(', ')} are ${jobTitle}`;
}

console.log(joinString("MTS","deepak","vishwakarma")+" are student");