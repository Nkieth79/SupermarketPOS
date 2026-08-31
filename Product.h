#pragma once

using namespace System;

namespace SupermarketPOS {

    public ref class Product
    {
    private:
        String^ productID;
        String^ productName;
        String^ barCode;
        double price;
        int quantityInStock;
        static double vatRate = 0.15;  // 15% VAT as per UML

    public:
        // Constructors
        Product();
        Product(String^ id, String^ name, String^ barcode, double price, int qty);

        // Setters
        void setProductID(String^ id);
        void setProductName(String^ name);
        void setBarCode(String^ code);
        void setPrice(double price);
        void setQuantity(int qty);

        // Getters
        String^ getProductID();
        String^ getProductName();
        String^ getBarCode();
        double getPrice();
        int getQuantityInStock();

        // Static method for VAT rate
        static double getVatRate();

        // Additional methods
        double calculateVAT();      // Calculate VAT for this product
        double getTotalWithVAT();   // Price + VAT
        bool isLowStock();          // Check if quantity <= 5
    };
}