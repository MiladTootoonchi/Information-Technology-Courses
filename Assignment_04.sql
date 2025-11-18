# Team 83
# Milad Tootoonchi
# Sania Minaipour
# Makka Dulgaeva

# Task 01
SELECT * FROM employees
WHERE EmployeeID IN (2, 5, 9);

# Task 02
SELECT * FROM customers c
INNER JOIN orders o ON o.CustomerID = c.CustomerID;

# Task 03
SELECT o.OrderID, c.ContactName FROM customers c
INNER JOIN orders o ON o.CustomerID = c.CustomerID;

# Task 04
SELECT c.ContactName, c.Address, c.City, o.OrderDate FROM customers c
INNER JOIN orders o ON o.CustomerID = c.CustomerID
WHERE o.OrderDate = "1995-05-01";

# Task 05
SELECT p.ProductName, s.CompanyName, s.Country, s.Phone FROM suppliers s
INNER JOIN products p ON p.SupplierID = s.SupplierID
ORDER BY s.Country DESC
LIMIT 25;

# Task 06
SELECT COUNT(*) FROM orders o
RIGHT JOIN customers c ON o.CustomerID = c.CustomerID
ORDER BY ContactName;

# Task 07
SELECT products.ProductName, products.QuantityPerUnit, orderdetails.Quantity FROM orderdetails
INNER JOIN products ON products.ProductID = orderdetails.ProductID
WHERE orderdetails.Quantity > 100;

# Task 08
SELECT orders.EmployeeID, orders.OrderID, customers.ContactName, customers.City FROM orders
INNER JOIN customers ON orders.CustomerID = customers.CustomerID
WHERE orders.EmployeeID BETWEEN 3 AND 6
ORDER BY orders.EmployeeID ASC;

# Task 09
SELECT e.EmployeeID, CONCAT(e.FirstName, " ", e.LastName) AS EmployeeName, o.OrderID, c.ContactName, c.City 
FROM (orders o INNER JOIN customers c ON o.CustomerID = c.CustomerID)
INNER JOIN employees e ON o.EmployeeID = e.EmployeeID
WHERE e.EmployeeID BETWEEN 1 AND 4
ORDER BY e.EmployeeID DESC;

# Task 10
SELECT o.OrderID, o.OrderDate, c.ContactName, c.PostalCode, CONCAT(e.FirstName, " ", e.LastName) AS EmployeeName, e.Photo
FROM (orders o INNER JOIN employees e ON o.EmployeeID = e.EmployeeID)
INNER JOIN customers c ON o.CustomerID = c.CustomerID;

# Task 11
SELECT SUM(od.quantity) AS "Total quantity sold"
FROM (orderdetails od INNER JOIN products p ON od.productID = p.productID)
INNER JOIN categories c ON p.categoryID = c.categoryID
WHERE c.categoryName = 'Produce';