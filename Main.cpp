#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args)
{
   // Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SupermarketPOS::LoginForm^ loginForm = gcnew SupermarketPOS::LoginForm();
    Application::Run(loginForm);

    return 0;
}