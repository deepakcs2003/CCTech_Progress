"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var promptSync = require("prompt-sync");
var prompt = promptSync();
// type BillingLogger={
//     (message:string):string
//     systemName:string
// }
var products = [
    { id: 1, name: "Apple", price: 100, discount: 10 },
    { id: 2, name: "Mobile", price: 20000, discount: 5 },
    { id: 3, name: "Laptop", price: 50000, discount: 15 },
    { id: 4, name: "Headphones", price: 2000, discount: 20 },
    { id: 5, name: "Keyboard", price: 1500, discount: 12 },
    { id: 6, name: "Mouse", price: 800, discount: 8 },
    { id: 7, name: "Monitor", price: 12000, discount: 18 },
    { id: 8, name: "Tablet", price: 18000, discount: 10 },
    { id: 9, name: "Camera", price: 30000, discount: 7 },
    { id: 10, name: "Speaker", price: 4000, discount: 14 },
    { id: 11, name: "Smart Watch", price: 7000, discount: 9 },
    { id: 12, name: "Printer", price: 9000, discount: 11 },
    { id: 13, name: "Router", price: 2500, discount: 6 },
    { id: 14, name: "Power Bank", price: 1500, discount: 13 }
];
while (true) {
    console.log("Please select the option to further process");
    console.log("1. Show menu");
    console.log("2. Buy product");
    console.log("3. Exit");
    var manu = Number(prompt("Enter the choice: "));
    if (manu === 1) {
        for (var i = 0; i < products.length; i++) {
            console.log("Product ID:", products[i].id);
            console.log("Product Name:", products[i].name);
            console.log("Discount:", products[i].discount);
            console.log("Price:", products[i].price);
            console.log("-----------------------------------");
        }
    }
    else if (manu === 2) {
        var productId = Number(prompt("Enter product id: "));
        var quantity = Number(prompt("Enter quantity: "));
        console.log("You selected product id:", productId);
        console.log("Quantity:", quantity);
    }
    else if (manu === 3) {
        console.log("Exiting program...");
        break;
    }
    else {
        console.log("Wrong input. Try again.");
    }
}
