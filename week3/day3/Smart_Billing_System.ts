// import promptSync = require("prompt-sync");
// const prompt = promptSync();

type Product = {
  id: number;
  name: string;
  price: number;
  discount: number;
};

const products: Product[] = [
  { id: 1, name: "Apple", price: 100, discount: 10 },
  { id: 2, name: "Mobile", price: 20000, discount: 5 },
  { id: 3, name: "Laptop", price: 50000, discount: 15 }
];

while (true) {
  console.log("\nPlease select the option:");
  console.log("1. Show menu");
  console.log("2. Buy product");
  console.log("3. Exit");

  let manu: number = Number(prompt("Enter choice: "));

  if (manu === 1) {
    productDetails(products);   // array pass kar rahe hain

  } else if (manu === 2) {
    let productId: number = Number(prompt("Enter product id: "));
    let quantity: number = Number(prompt("Enter quantity: "));

    const selected = products.find(p => p.id === productId);

    if (selected) {
      productDetails(selected);  // single product pass
      console.log("Quantity:", quantity);

      const finalPrice =
        selected.price -
        (selected.price * selected.discount) / 100;

      console.log("Total Bill:", finalPrice * quantity);
    } else {
      console.log("Invalid Product ID");
    }

  } else if (manu === 3) {
    console.log("Exiting...");
    break;

  } else {
    console.log("Wrong input!");
  }
}

/* ============================= */
/* 🔥 FUNCTION OVERLOADING */
/* ============================= */

function productDetails(product: Product): void;
function productDetails(products: Product[]): void;

function productDetails(item: any): void {
  if (Array.isArray(item)) {
    for (let i = 0; i < item.length; i++) {
      printProduct(item[i]);
    }
  } else {
    printProduct(item);
  }
}

function printProduct(product: Product): void {
  console.log("Product ID:", product.id);
  console.log("Product Name:", product.name);
  console.log("Discount:", product.discount);
  console.log("Price:", product.price);
  console.log("-----------------------------");
}