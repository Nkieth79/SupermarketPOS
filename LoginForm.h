#pragma once
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include "User.h"
#include "CashierDashboard.h"
#include "MainMenuForm.h"
namespace SupermarketPOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::IO;


	//public ref class CashierDashboard;
	//public ref class AdminDashboard;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			SeedUsersFromFile();
			
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picLogo1;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblSubtitle;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblUsername;
	private: System::Windows::Forms::TextBox^ txtUsername;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnCancel;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->picLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// picLogo1
			// 
			this->picLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picLogo1.Image")));
			this->picLogo1->Location = System::Drawing::Point(164, 12);
			this->picLogo1->Name = L"picLogo1";
			this->picLogo1->Size = System::Drawing::Size(226, 105);
			this->picLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picLogo1->TabIndex = 0;
			this->picLogo1->TabStop = false;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTitle->Location = System::Drawing::Point(140, 120);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(263, 41);
			this->lblTitle->TabIndex = 1;
			this->lblTitle->Text = L"FRESHMART POS";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSubtitle->ForeColor = System::Drawing::Color::Gray;
			this->lblSubtitle->Location = System::Drawing::Point(208, 161);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(111, 23);
			this->lblSubtitle->TabIndex = 2;
			this->lblSubtitle->Text = L"System Login";
			this->lblSubtitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(144, 395);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(231, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"© 2026 FreshMart. All rights reserved.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->Location = System::Drawing::Point(80, 200);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(87, 23);
			this->lblUsername->TabIndex = 4;
			this->lblUsername->Text = L"Username";
			this->lblUsername->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(170, 198);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(250, 31);
			this->txtUsername->TabIndex = 5;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPassword->Location = System::Drawing::Point(80, 250);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(80, 23);
			this->lblPassword->TabIndex = 6;
			this->lblPassword->Text = L"Password";
			this->lblPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(170, 248);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(250, 31);
			this->txtPassword->TabIndex = 7;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::DarkGreen;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(170, 310);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(120, 40);
			this->btnLogin->TabIndex = 8;
			this->btnLogin->Text = L"LOGIN";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::DimGray;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->ForeColor = System::Drawing::Color::White;
			this->btnCancel->Location = System::Drawing::Point(300, 310);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(120, 40);
			this->btnCancel->TabIndex = 9;
			this->btnCancel->Text = L"CANCEL";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(508, 464);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblSubtitle);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->picLogo1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreshMart POS - Login";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			private:
				// Connection string for your database
				String^ GetConnectionString()
				{
					return "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=SupermarketPOS;Integrated Security=True";
				}

				// Seed users from text file
				void SeedUsersFromFile()
				{
				
					try
					{
						String^ filePath = Application::StartupPath + "\\users.txt";

						if (!File::Exists(filePath))
						{
							MessageBox::Show("users.txt not found at: " + filePath);
							return;
						}

						SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
						conn->Open();

						array<String^>^ lines = File::ReadAllLines(filePath);
						int usersAdded = 0;

						for each (String ^ line in lines)
						{
							if (String::IsNullOrWhiteSpace(line)) continue;

							line = line->Trim();
							array<String^>^ parts = line->Split(',');

							if (parts->Length >= 5)  
							{
							
								for (int i = 0; i < parts->Length; i++)
								{
									parts[i] = parts[i]->Trim();
								}

							
								String^ checkQuery = "SELECT COUNT(*) FROM Users WHERE Username = '" + parts[0] + "'";
								SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
								int exists = (int)checkCmd->ExecuteScalar();

								if (exists == 0)
								{
									String^ query = "INSERT INTO Users (Username, PasswordHash, FullName, Role, IsActive) "
										"VALUES ('" + parts[0] + "', '" + parts[1] + "', '"
										+ parts[2] + "', '" + parts[3] + "', " + parts[4] + ")";

									SqlCommand^ cmd = gcnew SqlCommand(query, conn);
									cmd->ExecuteNonQuery();
									usersAdded++;
								}
							}
						}

						conn->Close();

						if (usersAdded > 0)
							MessageBox::Show("Users seeded successfully! Added " + usersAdded + " users.");
						else
							MessageBox::Show("No new users added. Users already exist.");
					}
					catch (Exception^ ex)
					{
						MessageBox::Show("Seed error: " + ex->Message);
					}





				}

				

				

	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		String^ username = txtUsername->Text->Trim();
		String^ password = txtPassword->Text;

		if (username == "" || password == "")
		{
			MessageBox::Show("Please enter username and password", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		User^ currentUser = gcnew User();

		if (currentUser->Login(username, password))
		{
			// Get user info after successful login
			String^ loggedInName = currentUser->getUserName();
			String^ loggedInRole = currentUser->getRole();
			String^ loggedInID = currentUser->getUserID();

			MessageBox::Show("Welcome " + loggedInName + "!\nRole: " + loggedInRole,
				"Login Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			this->Hide();

			MainMenuForm^ mainMenu = gcnew MainMenuForm(currentUser);
			mainMenu->ShowDialog();

			this->Show();
			txtUsername->Clear();
			txtPassword->Clear();
		}
		else
		{
			MessageBox::Show("Invalid username or password", "Login Failed",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txtPassword->Clear();
			txtUsername->Focus();
		}


	}
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Clear both text boxes
	txtUsername->Text = "";
	txtPassword->Text = "";

	txtUsername->Focus();
}
};
}
