#pragma once

using namespace System;

namespace SupermarketPOS {

    public ref class Sale
    {
    private:
        String^ saleID;
        DateTime saleDate;
        String^ userName;
        double totalAmount;
        double vatAmount;

    public:
        // Constructors
        Sale();
        Sale(String^ id, String^ user, double total, double vat);
        Sale(String^ id, String^ user, DateTime date, double total, double vat);

        // Setters
        void setSaleID(String^ id);
        void setUserName(String^ name);
        void setSaleDate(DateTime date);
        void setVatAmount(double vat);
        void setTotalAmount(double total);

        // Getters
        String^ getSaleID();
        String^ getUserName();
        DateTime getSaleDate();
        String^ getFormattedSaleDate();  
        double getTotalAmount();
        double getVatAmount();

        // Calculations (as per UML)

        double subTotal();   
        double totalAmountCalc(); 
        double vatAmountCalc();    
    };
}