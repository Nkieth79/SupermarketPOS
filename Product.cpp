#include "Product.h"

namespace SupermarketPOS {

    // Default Constructor
    Product::Product()
    {
        productID = "";
        productName = "";
        barCode = "";
        price = 0.0;
        quantityInStock = 0;
    }

    // Parameterized Constructor
    Product::Product(String^ id, String^ name, String^ barcode, double p, int qty)
    {
        productID = id;
        productName = name;
        barCode = barcode;
        price = p;
        quantityInStock = qty;
    }

    // Setters
    void Product::setProductID(String^ id) { productID = id; }
    void Product::setProductName(String^ name) { productName = name; }
    void Product::setBarCode(String^ code) { barCode = code; }
    void Product::setPrice(double p) { price = p; }
    void Product::setQuantity(int qty) { quantityInStock = qty; }

    // Getters
    String^ Product::getProductID() { return productID; }
    String^ Product::getProductName() { return productName; }
    String^ Product::getBarCode() { return barCode; }
    double Product::getPrice() { return price; }
    int Product::getQuantityInStock() { return quantityInStock; }

    // Static VAT rate
    double Product::getVatRate() { return vatRate; }

    // Calculate VAT amount for this product
    double Product::calculateVAT()
    {
        return price * vatRate;
    }

    // Get price including VAT
    double Product::getTotalWithVAT()
    {
        return price + calculateVAT();
    }

    // Check if stock is low (5 or less)
    bool Product::isLowStock()
    {
        return quantityInStock <= 5;
    }
}