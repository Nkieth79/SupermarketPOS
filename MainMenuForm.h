#pragma once
#include "CashierDashboard.h"
#include "User.h"
#include "ProductManagementForm.h"
#include "ReportsForm.h"
#include "UserManagementForm.h"
namespace SupermarketPOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
	
		MainMenuForm(User^ user)
		{
			loggedInUser = user;
			InitializeComponent();
			SetAccessByRole(user->getRole());
			
			// Display cashier name
			lblCashierName->Text = user->getUserName();
		}


	public:
		void SetCashierName(String^ name)
		{
			lblCashierName->Text = name;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSales;
	private: System::Windows::Forms::Button^ btnLogout;
	protected:

	private: System::Windows::Forms::Button^ btnReports;

	private: System::Windows::Forms::Button^ btnProductMgmt;
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblCashierName;
	private:
		User^ loggedInUser;
	private: System::Windows::Forms::Button^ btnManageUser;

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
			this->btnSales = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnReports = (gcnew System::Windows::Forms::Button());
			this->btnProductMgmt = (gcnew System::Windows::Forms::Button());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblCashierName = (gcnew System::Windows::Forms::Label());
			this->btnManageUser = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnSales
			// 
			this->btnSales->BackColor = System::Drawing::Color::DarkGreen;
			this->btnSales->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSales->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSales->ForeColor = System::Drawing::Color::White;
			this->btnSales->Location = System::Drawing::Point(25, 170);
			this->btnSales->Name = L"btnSales";
			this->btnSales->Size = System::Drawing::Size(220, 200);
			this->btnSales->TabIndex = 0;
			this->btnSales->Text = L"SALES / CHECKOUT";
			this->btnSales->UseVisualStyleBackColor = false;
			this->btnSales->Click += gcnew System::EventHandler(this, &MainMenuForm::btnSales_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::Gray;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Location = System::Drawing::Point(281, 456);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(220, 40);
			this->btnLogout->TabIndex = 1;
			this->btnLogout->Text = L"LOGOUT";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &MainMenuForm::btnLogout_Click);
			// 
			// btnReports
			// 
			this->btnReports->BackColor = System::Drawing::Color::Orange;
			this->btnReports->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReports->ForeColor = System::Drawing::Color::White;
			this->btnReports->Location = System::Drawing::Point(534, 170);
			this->btnReports->Name = L"btnReports";
			this->btnReports->Size = System::Drawing::Size(220, 200);
			this->btnReports->TabIndex = 2;
			this->btnReports->Text = L"REPORTS";
			this->btnReports->UseVisualStyleBackColor = false;
			this->btnReports->Click += gcnew System::EventHandler(this, &MainMenuForm::btnReports_Click);
			// 
			// btnProductMgmt
			// 
			this->btnProductMgmt->BackColor = System::Drawing::Color::RoyalBlue;
			this->btnProductMgmt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProductMgmt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProductMgmt->ForeColor = System::Drawing::Color::White;
			this->btnProductMgmt->Location = System::Drawing::Point(281, 170);
			this->btnProductMgmt->Name = L"btnProductMgmt";
			this->btnProductMgmt->Size = System::Drawing::Size(220, 200);
			this->btnProductMgmt->TabIndex = 3;
			this->btnProductMgmt->Text = L"PRODUCT MANAGEMENT";
			this->btnProductMgmt->UseVisualStyleBackColor = false;
			this->btnProductMgmt->Click += gcnew System::EventHandler(this, &MainMenuForm::btnProductMgmt_Click);
			// 
			// lblWelcome
			// 
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::Black;
			this->lblWelcome->Location = System::Drawing::Point(257, 95);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(124, 30);
			this->lblWelcome->TabIndex = 4;
			this->lblWelcome->Text = L"Welcome :";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblTitle
			// 
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTitle->Location = System::Drawing::Point(143, 35);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(500, 60);
			this->lblTitle->TabIndex = 5;
			this->lblTitle->Text = L"FRESHMART POS";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblCashierName
			// 
			this->lblCashierName->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCashierName->ForeColor = System::Drawing::Color::Black;
			this->lblCashierName->Location = System::Drawing::Point(375, 95);
			this->lblCashierName->Name = L"lblCashierName";
			this->lblCashierName->Size = System::Drawing::Size(204, 30);
			this->lblCashierName->TabIndex = 6;
			this->lblCashierName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnManageUser
			// 
			this->btnManageUser->BackColor = System::Drawing::Color::Gold;
			this->btnManageUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnManageUser->Location = System::Drawing::Point(25, 376);
			this->btnManageUser->Name = L"btnManageUser";
			this->btnManageUser->Size = System::Drawing::Size(729, 74);
			this->btnManageUser->TabIndex = 7;
			this->btnManageUser->Text = L"USER MANAGEMENT";
			this->btnManageUser->UseVisualStyleBackColor = false;
			this->btnManageUser->Click += gcnew System::EventHandler(this, &MainMenuForm::btnManageUser_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SteelBlue;
			this->ClientSize = System::Drawing::Size(822, 553);
			this->Controls->Add(this->btnManageUser);
			this->Controls->Add(this->lblCashierName);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblWelcome);
			this->Controls->Add(this->btnProductMgmt);
			this->Controls->Add(this->btnReports);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnSales);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreshMart POS - Main Menu";
			this->Load += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		private:
			void SetAccessByRole(String^ role)
			{

				if (role == "Admin")
				{
					btnProductMgmt->Enabled = true;
					btnReports->Enabled = true;
					btnManageUser->Enabled = true;   
					btnManageUser->Visible = true;   
				}
				else // Cashier
				{
					btnProductMgmt->Enabled = false;
					btnReports->Enabled = false;
					btnManageUser->Enabled = false; 
					btnManageUser->Visible = false;   
				}
			}



	private: System::Void btnSales_Click(System::Object^ sender, System::EventArgs^ e)
	{

		this->Hide();
		CashierDashboard^ cashierForm = gcnew CashierDashboard(loggedInUser);
		cashierForm->ShowDialog();
		this->Show();



	}
private: System::Void btnProductMgmt_Click(System::Object^ sender, System::EventArgs^ e) 
{

	ProductManagementForm^ productForm = gcnew ProductManagementForm(loggedInUser);
	productForm->ShowDialog();



}
private: System::Void btnReports_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportsForm^ reportForm = gcnew ReportsForm(loggedInUser);
	reportForm->ShowDialog();


}
private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e)
{

	System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to logout?", "Confirm Logout",
		MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		this->Close();
	}

}
private: System::Void btnManageUser_Click(System::Object^ sender, System::EventArgs^ e)
{

	UserManagementForm^ userForm = gcnew UserManagementForm();
	userForm->ShowDialog();


}
private: System::Void MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
