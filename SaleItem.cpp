#include "SaleItem.h"

namespace SupermarketPOS {

    // Default Constructor
    SaleItem::SaleItem()
    {
        saleItemId = "";
        saleID = "";
        productID = "";
        quantity = 0;
        unitPrice = 0.0;
        lineTotal = 0.0;
    }

    // Full Parameterized Constructor
    SaleItem::SaleItem(String^ id, String^ sID, String^ pID, int qty, double price, double total)
    {
        saleItemId = id;
        saleID = sID;
        productID = pID;
        quantity = qty;
        unitPrice = price;
        lineTotal = total;
    }

    // Simplified Constructor (calculates lineTotal automatically)
    SaleItem::SaleItem(String^ sID, String^ pID, int qty, double price)
    {
        saleItemId = "";
        saleID = sID;
        productID = pID;
        quantity = qty;
        unitPrice = price;
        lineTotal = calculateLineTotal();
    }

    // Setters
    void SaleItem::setSaleItemId(String^ id) { saleItemId = id; }
    void SaleItem::setSaleID(String^ id) { saleID = id; }
    void SaleItem::setProductID(String^ id) { productID = id; }
    void SaleItem::setQuantity(int qty) { quantity = qty; }
    void SaleItem::setUnitPrice(double price) { unitPrice = price; }
    void SaleItem::setLineTotal(double total) { lineTotal = total; }

    // Getters
    String^ SaleItem::getSaleItemId() { return saleItemId; }
    String^ SaleItem::getSaleID() { return saleID; }
    String^ SaleItem::getProductID() { return productID; }
    int SaleItem::getQuantity() { return quantity; }
    double SaleItem::getUnitPrice() { return unitPrice; }
    double SaleItem::getLineTotal() { return lineTotal; }

    // Calculate line total (quantity × unit price)
    double SaleItem::calculateLineTotal()
    {
        return quantity * unitPrice;
    }
}