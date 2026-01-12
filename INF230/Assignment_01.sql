# Group 83
# Milad Tootoonchi
# Makka Dulgaeva
# Sania Minaipour

# Task 01
SELECT * FROM categories;

# Task 02
SELECT ProductName, QuantityPerUnit, UnitPrice 
FROM products;

# Task 03
SELECT DISTINCT ContactTitle FROM customers;

# Task 04
SELECT DISTINCT Title FROM employees;

# Task 05
SELECT * FROM orders
WHERE OrderDate = '1996-05-17 00:00:00';

# Task 06
SELECT * FROM orders
WHERE OrderDate >= '1996-05-17 00:00:00';

# Task 07
SELECT * FROM products
WHERE UnitPrice > 40;

# Task 08
SELECT * FROM products
WHERE UnitPrice BETWEEN 30 AND 40;

# Task 09
SELECT o.OrderID, 
(SELECT c.ContactName FROM customers c WHERE c.CustomerID = o.CustomerID) AS ContactName
FROM orders o;

# Task 10
SELECT o.OrderDate, c.ContactName, c.Address, c.City 
FROM orders o, customers c
WHERE c.CustomerID = o.CustomerID;

# Task 11
SELECT * FROM customers
WHERE City = "London" or City = "Buenos Aires";

# Task 12
SELECT * FROM customers
WHERE Country = "USA" AND NOT City = "Portland";

# Task 13
SELECT * FROM orderdetails
WHERE ProductID IN (SELECT ProductID FROM products WHERE ProductName = "Tofu");

# Task 14
SELECT FirstName, LastName From employees e, orders o
Where e.EmployeeID = o.EmployeeID AND o.orderID = "10369";

# Task 15
SELECT FirstName, LastName FROM employees
WHERE EmployeeID IN (SELECT EmployeeID FROM orders WHERE OrderID = 10369);