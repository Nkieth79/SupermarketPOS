#pragma once

using namespace System;
using namespace System::Data::SqlClient;

namespace SupermarketPOS {

    public ref class User
    {
    private:
        String^ userID;
        String^ userName;
        String^ password;
        String^ role;

    public:
        // Constructors
        User();
        User(String^ id, String^ name, String^ pwd, String^ r);

        // Setters
        void setUserID(String^ id);
        void setUserName(String^ name);
        void setPassword(String^ pwd);
        void setRole(String^ r);

        // Getters
        String^ getUserID();
        String^ getUserName();
        String^ getPassword();
        String^ getRole();

        // Methods
        bool Login(String^ username, String^ pwd);
        void Logout();
        bool IsAdmin();
        bool IsCashier();
        String^ GetConnectionString();
    };
}