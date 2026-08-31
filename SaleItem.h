#pragma once

using namespace System;

namespace SupermarketPOS {

    public ref class SaleItem
    {
    private:
        String^ saleItemId;
        String^ saleID;
        String^ productID;
        int quantity;
        double unitPrice;
        double lineTotal;

    public:
        // Constructors
        SaleItem();
        SaleItem(String^ saleItemId, String^ saleID, String^ productID, int qty, double price, double total);
        SaleItem(String^ saleID, String^ productID, int qty, double price);

        // Setters
        void setSaleItemId(String^ id);
        void setSaleID(String^ id);
        void setProductID(String^ id);
        void setQuantity(int qty);
        void setUnitPrice(double price);
        void setLineTotal(double total);

        // Getters
        String^ getSaleItemId();
        String^ getSaleID();
        String^ getProductID();
        int getQuantity();
        double getUnitPrice();
        double getLineTotal();

        // Calculation method (as per UML)
        double calculateLineTotal();
    };
}