-- ============================================================
-- FreshMart POS - Database Schema
-- Target: SQL Server LocalDB (MSSQLLocalDB)
-- Run this script to create all tables required by the app.
-- ============================================================

-- Create the database if it doesn't exist
IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = 'SupermarketPOS')
BEGIN
    CREATE DATABASE SupermarketPOS;
END
GO

USE SupermarketPOS;
GO

-- ============================================================
-- Table: Users
-- ============================================================
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'Users')
BEGIN
    CREATE TABLE Users (
        UserID        INT IDENTITY(1,1) PRIMARY KEY,
        Username      NVARCHAR(50)  NOT NULL,
        PasswordHash  NVARCHAR(100) NOT NULL,
        FullName      NVARCHAR(100) NOT NULL,
        Role          NVARCHAR(20)  NOT NULL,
        IsActive      BIT           NOT NULL DEFAULT 1
    );
END
GO

-- ============================================================
-- Table: Products
-- ============================================================
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'Products')
BEGIN
    CREATE TABLE Products (
        ProductID      INT IDENTITY(1,1) PRIMARY KEY,
        ProductName    NVARCHAR(100)  NOT NULL,
        Barcode        NVARCHAR(50)   NOT NULL,
        SellingPrice   DECIMAL(10,2)  NOT NULL,
        CostPrice      DECIMAL(10,2)  NULL,
        Quantity       INT            NOT NULL DEFAULT 0,
        MinStockLevel  INT            NULL DEFAULT 5,
        IsActive       BIT            NOT NULL DEFAULT 1
    );
END
GO

-- ============================================================
-- Table: Sales
-- ============================================================
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'Sales')
BEGIN
    CREATE TABLE Sales (
        SaleID          INT IDENTITY(1,1) PRIMARY KEY,
        InvoiceNumber   NVARCHAR(50)  NOT NULL,
        UserID          INT           NOT NULL,
        SaleDate        DATETIME      NULL DEFAULT GETDATE(),
        SubTotal        DECIMAL(10,2) NULL,
        VATAmount       DECIMAL(10,2) NULL,
        TotalAmount     DECIMAL(10,2) NULL,
        PaymentMethod   NVARCHAR(20)  NULL,
        AmountTendered  DECIMAL(10,2) NULL,
        ChangeDue       DECIMAL(10,2) NULL
    );
END
GO

-- ============================================================
-- Table: SaleItems
-- ============================================================
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'SaleItems')
BEGIN
    CREATE TABLE SaleItems (
        SaleItemID  INT IDENTITY(1,1) PRIMARY KEY,
        SaleID      INT           NOT NULL,
        ProductID   INT           NOT NULL,
        Quantity    INT           NOT NULL,
        UnitPrice   DECIMAL(10,2) NULL,
        TotalPrice  DECIMAL(10,2) NULL
    );
END
GO

-- ============================================================
-- Table: Returns
-- ============================================================
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'Returns')
BEGIN
    CREATE TABLE Returns (
        ReturnID      INT IDENTITY(1,1) PRIMARY KEY,
        SaleItemID    INT           NOT NULL,
        ProductID     INT           NOT NULL,
        UserID        INT           NOT NULL,
        ReturnDate    DATETIME      NULL DEFAULT GETDATE(),
        RefundAmount  DECIMAL(10,2) NOT NULL,
        Reason        NVARCHAR(200) NOT NULL
    );
END
GO

-- ============================================================
-- Foreign Keys
-- ============================================================
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_Sales_Users')
    ALTER TABLE Sales
        ADD CONSTRAINT FK_Sales_Users FOREIGN KEY (UserID) REFERENCES Users(UserID);
GO

IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_SaleItems_Sales')
    ALTER TABLE SaleItems
        ADD CONSTRAINT FK_SaleItems_Sales FOREIGN KEY (SaleID) REFERENCES Sales(SaleID);
GO

IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_SaleItems_Products')
    ALTER TABLE SaleItems
        ADD CONSTRAINT FK_SaleItems_Products FOREIGN KEY (ProductID) REFERENCES Products(ProductID);
GO

IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_Returns_SaleItems')
    ALTER TABLE Returns
        ADD CONSTRAINT FK_Returns_SaleItems FOREIGN KEY (SaleItemID) REFERENCES SaleItems(SaleItemID);
GO

IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_Returns_Products')
    ALTER TABLE Returns
        ADD CONSTRAINT FK_Returns_Products FOREIGN KEY (ProductID) REFERENCES Products(ProductID);
GO

IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_Returns_Users')
    ALTER TABLE Returns
        ADD CONSTRAINT FK_Returns_Users FOREIGN KEY (UserID) REFERENCES Users(UserID);
GO

PRINT 'FreshMart POS database schema created successfully.';
GO
