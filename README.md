
---

Inventory Manager in C

This project is an Inventory Manager written in C. It allows the user to insert, list, update, and remove products from an inventory, as well as save and load data from a text file. The system is designed to be simple and efficient, operating through an interactive menu in the terminal.

Features

Insert Product: Adds a new product to the inventory with details such as name, quantity, section, price, expiration date, supplier, and more.

List Products: Displays a list of all registered products, showing their details.

Update Product: Allows updating the information of an existing product.

Remove Product: Deletes a specific product from the inventory.

Save/Load Products: Saves data to a file (produtos.txt) and automatically loads the data when the program starts.


Product Structure

Each product has the following fields:

Product Name: First and last name (no spaces between words).

Section: An integer representing the section where the product is located.

Quantity: The available quantity of the product in stock.

Price: The product's price.

Expiration Date: The date when the product expires (dd/mm/yyyy).

Category: Type of product (e.g., electronics, food, etc.).

Supplier: Supplier's name.

Entry Date: The date the product was added to the inventory (dd/mm/yyyy).


Validations

The code includes basic validations to ensure data integrity:

Expiration and Entry Dates: Verifies that days are between 1 and 31, and months are between 1 and 12.

Product Limit: The program allows registering up to 100 products. If the limit is reached, the user is notified.


Future Features

Improved date validations to account for months with fewer than 31 days.

Support for more input validations, such as ensuring quantity and price are positive numbers.


How to Run

1. Clone this repository.


2. Compile the code using a C compiler (e.g., gcc):

gcc inventory_manager.c -o inventory_manager


3. Run the program:

./inventory_manager


4. Follow the menu instructions to insert, list, update, or remove products.




---

