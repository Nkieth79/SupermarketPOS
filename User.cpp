#include "User.h"

namespace SupermarketPOS {

    // Default constructor
    User::User()
    {
        userID = "";
        userName = "";
        password = "";
        role = "";
    }

    // Parameterized constructor
    User::User(String^ id, String^ name, String^ pwd, String^ r)
    {
        userID = id;
        userName = name;
        password = pwd;
        role = r;
    }

    // Setters
    void User::setUserID(String^ id) { userID = id; }
    void User::setUserName(String^ name) { userName = name; }
    void User::setPassword(String^ pwd) { password = pwd; }
    void User::setRole(String^ r) { role = r; }

    // Getters
    String^ User::getUserID() { return userID; }
    String^ User::getUserName() { return userName; }
    String^ User::getPassword() { return password; }
    String^ User::getRole() { return role; }

    // Connection string
    String^ User::GetConnectionString()
    {
        return "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=SupermarketPOS;Integrated Security=True";
    }

    // Login method
    bool User::Login(String^ username, String^ pwd)
    {
        try
        {
            SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
            String^ query = "SELECT UserID, Username, Role FROM Users WHERE Username = @username AND PasswordHash = @password AND IsActive = 1";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@username", username);
            cmd->Parameters->AddWithValue("@password", pwd);

            conn->Open();
            SqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read())
            {
                userID = reader["UserID"]->ToString();
                userName = reader["Username"]->ToString();
                role = reader["Role"]->ToString();
                password = pwd;
                conn->Close();
                return true;
            }

            conn->Close();
            return false;
        }
        catch (Exception^)
        {
            return false;
        }
    }

    void User::Logout()
    {
        userID = "";
        userName = "";
        password = "";
        role = "";
    }

    bool User::IsAdmin() { return role == "Admin"; }
    bool User::IsCashier() { return role == "Cashier"; }
}