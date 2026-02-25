type UnionToIntersection<U> = (U extends any ? (k: U) => void : never) extends (
    (k: infer I) => void) ? I : never;

// Example usage
type UnionType = { a: number } | { b: string } | { c: boolean };

type IntersectionType = UnionToIntersection<UnionType>;


const myObject: IntersectionType = {
    a: 22,
    b: "GFG",
    c: true
};

console.log(myObject);


type NameType={name:string}
type AgeType={age:number}
type person=NameType&AgeType
let user:person={
    name:"deepak",
    age:22
}

console.log(user);