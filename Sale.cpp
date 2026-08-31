#include "Sale.h"

namespace SupermarketPOS {

    // Default Constructor
    Sale::Sale()
    {
        saleID = "";
        userName = "";
        saleDate = DateTime::Now;
        totalAmount = 0.0;
        vatAmount = 0.0;
    }

    // Parameterized Constructor (without date)
    Sale::Sale(String^ id, String^ user, double total, double vat)
    {
        saleID = id;
        userName = user;
        saleDate = DateTime::Now;
        totalAmount = total;
        vatAmount = vat;
    }

    // Parameterized Constructor (with date)
    Sale::Sale(String^ id, String^ user, DateTime date, double total, double vat)
    {
        saleID = id;
        userName = user;
        saleDate = date;
        totalAmount = total;
        vatAmount = vat;
    }

    // Setters
    void Sale::setSaleID(String^ id) { saleID = id; }
    void Sale::setUserName(String^ name) { userName = name; }
    void Sale::setSaleDate(DateTime date) { saleDate = date; }
    void Sale::setVatAmount(double vat) { vatAmount = vat; }
    void Sale::setTotalAmount(double total) { totalAmount = total; }

    // Getters
    String^ Sale::getSaleID() { return saleID; }
    String^ Sale::getUserName() { return userName; }
    DateTime Sale::getSaleDate() { return saleDate; }
    double Sale::getTotalAmount() { return totalAmount; }
    double Sale::getVatAmount() { return vatAmount; }

    // Formatted date string
    String^ Sale::getFormattedSaleDate()
    {
        return saleDate.ToString("yyyy-MM-dd HH:mm:ss");
    }

    // Calculations (as per UML diagram)
    double Sale::subTotal()
    {
        return totalAmount - vatAmount;
    }

    double Sale::totalAmountCalc()
    {
        return totalAmount;
    }

    double Sale::vatAmountCalc()
    {
        return vatAmount;
    }
}