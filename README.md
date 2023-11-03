## Here's the SQL syntax to create the dimension tables and fact table according to your specifications. Please note that I'm providing a simplified example with just a few attributes for each table. You can add more attributes as needed.

--- sql

```
-- Create Time Dimension Table
CREATE TABLE Time (
    time_id INT PRIMARY KEY,
    year INT,
    quarter INT,
    month VARCHAR(10),
    date DATE,
    day VARCHAR(10),
    season VARCHAR(20),
    holiday_flag INT
);

-- Create Customer Dimension Table
CREATE TABLE Customer (
    comp_id INT PRIMARY KEY,
    company_name VARCHAR(100),
    comp_type VARCHAR(50),
    location VARCHAR(100),
    contact VARCHAR(50),
    payment_terms VARCHAR(50),
    orders INT
);

-- Create Truck Dimension Table
CREATE TABLE Truck (
    Truck_noplate VARCHAR(20) PRIMARY KEY,
    cost DECIMAL(10, 2),
    Capacity INT,
    Efficiency DECIMAL(5, 2),
    Insurance DECIMAL(10, 2),
    Driver_id INT,
    Driver_name VARCHAR(50),
    Driver_contact VARCHAR(50),
    ontime_delievery INT
);

-- Create Fact Table with Concatenated Keys
CREATE TABLE TruckTransport_Fact (
    Fact_ID INT PRIMARY KEY,
    concatenated_dim_keys VARCHAR(500), -- Concatenated primary keys
    Total_Revenue DECIMAL(15, 2),
    Driver_Safety DECIMAL(5, 2),
    Order_Frequency INT,
    Route_Efficiency DECIMAL(5, 2)
);
```
In the TruckTransport_Fact table, I've included the concatenated_dim_keys column to store the concatenated primary keys of the dimensions as you requested. However, I strongly recommend against using concatenated keys for reasons mentioned earlier. Instead, it's better to use proper foreign keys to establish relationships between the fact table and dimension tables.

For demonstration purposes, I've used simplified data types and attributes. In a real-world scenario, you might need to adapt the data types and add additional attributes to meet your specific requirements.