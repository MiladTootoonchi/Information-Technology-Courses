# Team 83
# Milad Tootoonchi
# Sania Minaipour
# Makka Dulgaeva

# Task 01:
SELECT COUNT(OrderID) FROM orders;

# Task 02:
SELECT * FROM products
WHERE ProductName LIKE "%ra"
ORDER BY ProductName DESC;

# Task 03:
SELECT ProductID, ProductName, QuantityPerUnit FROM products
WHERE QuantityPerUnit LIKE "%500 g%"
ORDER BY ProductID DESC;

# Task 04:
SELECT * FROM customers
WHERE (
    ContactName LIKE 'M%' OR
    ContactName LIKE 'N%' OR
    ContactName LIKE 'O%' OR
    ContactName LIKE 'P%' OR
    ContactName LIKE 'Q%' OR
    ContactName LIKE 'R%' OR
    ContactName LIKE 'S%'
)
AND City != "México D.F."
ORDER BY ContactName ASC;

# Task 05:
SELECT COUNT(CustomerID) FROM customers
WHERE fax IS NULL;

# Task 06:
SELECT AVG(p.UnitPrice) FROM products p
WHERE p.SupplierID IN (
	SELECT s.SupplierID FROM suppliers s 
	WHERE s.CompanyName = "Karkki Oy"
);

# Task 07:
SELECT SUM(Freight) AS "Total Freight" FROM orders
WHERE CustomerID LIKE "B%S";

# Task 08:
SELECT Count(OrderID) AS "Number of orders", 
AVG(Quantity) AS "Average Quantity" FROM orderdetails;

# Task 09:
SELECT COUNT(DISTINCT ProductID) AS "Number of product types" FROM orderdetails
WHERE ProductID LIKE "4%" OR ProductID LIKE "%3";

# Task 10:
SELECT SUM(UnitsInStock) AS "Total Stock" FROM products
WHERE ProductID LIKE "4%" OR ProductID LIKE "%3";

# Task 11:
SELECT DISTINCT CustomerID FROM orders
WHERE ShipVia = 3 AND ShipName LIKE "R%" AND CustomerID LIKE "%C";

# Task 12:
SELECT CONCAT(FirstName, " ", LastName) AS "Employee Name" FROM employees
WHERE HireDate < "1994-01-01"
AND Title LIKE "%Representative%"
AND PostalCode LIKE "%3";

# Task 13:
SELECT EmployeeID, CustomerID, Freight FROM orders
WHERE (CustomerID LIKE "BO_t%" AND Freight > 50)
OR (CustomerID LIKE "BO_i%" AND Freight > 50);

# Task 14:
SELECT o.EmployeeID, e.LastName, o.CustomerID From Orders o, employees e
WHERE o.EmployeeID = e.EmployeeID
AND o.CustomerID LIKE "BO_t%"
AND e.LastName LIKE "%LL%";