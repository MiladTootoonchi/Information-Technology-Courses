# Team 83
# Milad Tootoonchi
# Sania Minaipour
# Makka Dulgaeva

#Task 01:
SELECT e.EmployeeID, e.FirstName, COUNT(o.OrderID) AS Quantity
FROM employees e
LEFT JOIN orders o ON e.EmployeeID = o.EmployeeID
GROUP BY e.EmployeeID, e.FirstName
ORDER BY Quantity DESC;

#Task 02:
SELECT DISTINCT c1.*
FROM customers c1
JOIN customers c2 ON c1.PostalCode = c2.PostalCode AND c1.CustomerID <> c2.CustomerID
ORDER BY c1.Country ASC;

#Task 03:
SELECT p.ProductName, od.ProductID, COUNT(od.OrderID) AS TimesOrdered
FROM orderdetails od
JOIN products p ON od.ProductID = p.ProductID
GROUP BY od.ProductID, p.ProductName
HAVING COUNT(od.OrderID) > 50
ORDER BY TimesOrdered DESC;

#Task 04:
SELECT p.ProductID, p.ProductName, p.UnitsInStock, SUM(od.Quantity) AS TotalUnitsOrdered
FROM products p
JOIN orderdetails od ON p.ProductID = od.ProductID
WHERE p.Discontinued = 1
GROUP BY p.ProductID, p.ProductName, p.UnitsInStock
HAVING SUM(od.Quantity) > 50;

#Task 05:
SELECT c.ContactName, c.Country
FROM customers c
WHERE c.Country NOT IN (SELECT DISTINCT s.Country FROM suppliers s WHERE s.Country IS NOT NULL)
ORDER BY c.Country ASC;

#Task 06:
SELECT c.ContactName, COUNT(o.OrderID) AS TotalOrders
FROM customers c
JOIN orders o ON c.CustomerID = o.CustomerID
WHERE YEAR(o.OrderDate) = 1994
GROUP BY c.CustomerID, c.ContactName
ORDER BY TotalOrders DESC;

#Task 07:
SELECT e.EmployeeID, CONCAT(e.FirstName, ' ', e.LastName) AS employee_name,
CASE WHEN MOD(e.EmployeeID,2)=1 THEN 'Odd' ELSE 'Even' END AS `EmployeeID status`
FROM employees e;

#Task 08:
SELECT e.EmployeeID, e.FirstName
FROM employees e
JOIN orders o ON e.EmployeeID = o.EmployeeID
GROUP BY e.EmployeeID, e.FirstName
HAVING MIN(o.Freight) > 1000;

#Task 09:
SELECT DISTINCT e.EmployeeID, CONCAT(UPPER(e.FirstName), ' ', LOWER(e.LastName)) AS employee_name
FROM employees e
JOIN orders o ON e.EmployeeID = o.EmployeeID
WHERE o.Freight > 800;

#Task 10:
SELECT c.CustomerID, c.ContactName, ROUND(AVG(od.Quantity),2) AS AvgPurchaseQuantity
FROM customers c
JOIN orders o ON c.CustomerID = o.CustomerID
JOIN orderdetails od ON o.OrderID = od.OrderID
JOIN products p ON od.ProductID = p.ProductID
JOIN categories cat ON p.CategoryID = cat.CategoryID
WHERE cat.CategoryName = 'Beverages'
GROUP BY c.CustomerID, c.ContactName
ORDER BY AvgPurchaseQuantity ASC;

#Task 11:
CREATE TABLE IF NOT EXISTS employee_work_hours (
employee_id INT NOT NULL,
login_hours INT NOT NULL,
working_date DATE,
PRIMARY KEY (employee_id)
);
INSERT INTO employee_work_hours (employee_id, login_hours, working_date) VALUES
(1, 3, '2025-11-01'),
(2, 5, '2025-11-01'),
(3, 1, '2025-11-01'),
(4, 4, '2025-11-01'),
(5, 2, '2025-11-01'),
(6, 6, '2025-11-01'),
(7, 0, '2025-11-01'),
(8, 8, '2025-11-01'),
(9, 3, '2025-11-01');

SELECT * FROM employee_work_hours;

#Task 12:
SELECT e.FirstName AS `Employee Name`, ewh.login_hours
FROM employees e
JOIN employee_work_hours ewh ON e.EmployeeID = ewh.employee_id
WHERE ewh.login_hours > 2
AND (e.TitleOfCourtesy IN ('Mrs.','Ms.') OR e.Notes LIKE '%she%');

#Task 13:
SET SQL_SAFE_UPDATES = 0;
DELETE ewh
FROM employee_work_hours ewh
JOIN employees e ON ewh.employee_id = e.EmployeeID
WHERE e.BirthDate BETWEEN '1950-01-01' AND '1960-05-27';

DROP TABLE IF EXISTS employee_work_hours;

#Task 14:
SELECT orders.CustomerID, customers.ContactName, COUNT(orderdetails.OrderID) AS total_orders -- select customer id, contact name and total orders
FROM customers -- from customers table
INNER JOIN orders ON customers.CustomerID = orders.CustomerID -- join orders to link customers with their orders
INNER JOIN orderdetails ON orders.OrderID = orderdetails.OrderID -- join orderdetails to count order line items per order
GROUP BY orders.CustomerID -- group by the customer to aggregate counts per customer
ORDER BY total_orders DESC; -- order results by the total orders in descending order

#Task 15:
SELECT ROUND(EXP(AVG(LOG(UnitPrice))), 2) AS GeometricMean FROM products;
