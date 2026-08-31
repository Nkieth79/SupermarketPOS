#pragma once
#include "User.h"
#include <List>
#include "Product.h"
#using <System.dll>
#include "ProductManagementForm.h"
#include "ReturnForm.h"
namespace SupermarketPOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace Microsoft::VisualBasic;
	/// <summary>
	/// Summary for CashierDashboard
	/// </summary>
	public ref class CashierDashboard : public System::Windows::Forms::Form
	{
	public:
		CashierDashboard(User^ user)
		{
			isProcessingPayment = false;
			isClearingCart = false;
			loggedInUser = user;
			
			InitializeComponent();
			InitializeCart();
			dgvCart->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			DisplayCashierInfo();
			SeedProductsFromFile();
			UpdateLowStockMessage();
			originalProductIDs = gcnew List<int>();
			originalStockValues = gcnew List<int>();
			LoadAllProducts();  
			

			// Search and ListBox events
			//txtSearch->TextChanged += gcnew EventHandler(this, &CashierDashboard::txtSearch_TextChanged);
			//lstProducts->SelectedIndexChanged += gcnew EventHandler(this, &CashierDashboard::lstProducts_SelectedIndexChanged);

			// Payment buttons
			//btnClear->Click += gcnew System::EventHandler(this, &CashierDashboard::btnClear_Click);
			//btnCash->Click += gcnew System::EventHandler(this, &CashierDashboard::btnCash_Click);
			//btnCard->Click += gcnew System::EventHandler(this, &CashierDashboard::btnCard_Click);

			// Role-based access
			if (loggedInUser->getRole() != "Admin")
			{
				btnManageStock->Enabled = false;
				btnManageStock->Text = "MANAGE STOCK\n(Admin Access Only)";
			}


			btnManageStock->Click += gcnew System::EventHandler(this, &CashierDashboard::btnManageStock_Click);








			//
			//TODO: Add the constructor code here
			//
		}
		void InitializeCart()
		{
			cartTable = gcnew DataTable();
			cartTable->Columns->Add("Qty", int::typeid);
			cartTable->Columns->Add("Product", String::typeid);
			cartTable->Columns->Add("Price", double::typeid);
			cartTable->Columns->Add("Total", double::typeid);
			dgvCart->DataSource = cartTable;
			UpdateTotals();
			UpdateClearButtonState();
		}
		void DisplayCashierInfo()
		{
			lblCashier->Text = "Cashier: " + loggedInUser->getUserName();
		}
		void UpdateTotals()
		{
			subtotal = 0;
			for each (DataRow ^ row in cartTable->Rows)
			{
				subtotal += (double)row["Total"];
			}
			vatAmount = subtotal * 0.15;
			totalAmount = subtotal + vatAmount;

			lblSubtotal->Text = "Subtotal: R" + subtotal.ToString("0.00");
			lblVAT->Text = "VAT (15%): R" + vatAmount.ToString("0.00");
			lblTotal->Text = "TOTAL: R" + totalAmount.ToString("0.00");
		}
		void AddToCart(String^ productName, double price, int quantity)
		{
			for each (DataRow ^ row in cartTable->Rows)
			{
				if (row["Product"]->ToString() == productName)
				{
					int newQty = (int)row["Qty"] + quantity;
					row["Qty"] = newQty;
					row["Total"] = newQty * price;
					UpdateTotals();
					return;
				}
			}

			DataRow^ newRow = cartTable->NewRow();
			newRow["Qty"] = quantity;
			newRow["Product"] = productName;
			newRow["Price"] = price;
			newRow["Total"] = quantity * price;
			cartTable->Rows->Add(newRow);
			UpdateTotals();
			UpdateClearButtonState();
		}
		void UpdateLowStockMessage()
		{
			lblLowStockAlert->Text = "Low Stock: None";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CashierDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ panelHeader;
	private: System::Windows::Forms::Label^ lblstoreTitle;
	private: System::Windows::Forms::Label^ lblCashier;
	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Panel^ panelLeft;
	private: System::Windows::Forms::TextBox^ txtBarcode;
	private: System::Windows::Forms::Label^ LblBarCode;
private: System::Windows::Forms::Button^ btnAddProduct;
private:
		List<Product^>^ allProducts;
		List<Product^>^ filteredProducts;
private:
	List<int>^ originalProductIDs;
	List<int>^ originalStockValues;
	bool isClearingCart;
	private:
		void UpdateClearButtonState()
		{
			btnClear->Enabled = (cartTable->Rows->Count > 0);

		}












	private: System::Windows::Forms::Button^ btnManageStock;
	private: System::Windows::Forms::Panel^ panelRight;
	private: System::Windows::Forms::DataGridView^ dgvCart;
	private: System::Windows::Forms::Label^ lblCartTitle;
	private: System::Windows::Forms::Label^ lblCartHeader;
	private: System::Windows::Forms::Label^ lblSubtotal;
	private: System::Windows::Forms::Label^ lblVAT;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Button^ btnVoid;
private: System::Windows::Forms::Button^ btnClear;

	private: System::Windows::Forms::Button^ btnCash;
	private: System::Windows::Forms::Button^ btnCard;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblStatus;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblLowStockAlert;


	private:
		User^ loggedInUser;
		DataTable^ cartTable;
		double subtotal;
		double vatAmount;
		bool isProcessingPayment;



private: System::Windows::Forms::TextBox^ txtSearch;

private: System::Windows::Forms::Label^ lblProductList;


private: System::Windows::Forms::ListBox^ lstProducts;
private: System::Windows::Forms::Button^ btnReturn;


	   double totalAmount;

		String^ GetConnectionString()
		{
			return "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=SupermarketPOS;Integrated Security=True";
		}







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
			this->panelHeader = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->lblstoreTitle = (gcnew System::Windows::Forms::Label());
			this->lblCashier = (gcnew System::Windows::Forms::Label());
			this->panelLeft = (gcnew System::Windows::Forms::Panel());
			this->lstProducts = (gcnew System::Windows::Forms::ListBox());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->lblProductList = (gcnew System::Windows::Forms::Label());
			this->btnManageStock = (gcnew System::Windows::Forms::Button());
			this->btnAddProduct = (gcnew System::Windows::Forms::Button());
			this->txtBarcode = (gcnew System::Windows::Forms::TextBox());
			this->LblBarCode = (gcnew System::Windows::Forms::Label());
			this->panelRight = (gcnew System::Windows::Forms::Panel());
			this->btnReturn = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->lblStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lblLowStockAlert = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->btnCard = (gcnew System::Windows::Forms::Button());
			this->btnCash = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnVoid = (gcnew System::Windows::Forms::Button());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblVAT = (gcnew System::Windows::Forms::Label());
			this->lblSubtotal = (gcnew System::Windows::Forms::Label());
			this->lblCartHeader = (gcnew System::Windows::Forms::Label());
			this->dgvCart = (gcnew System::Windows::Forms::DataGridView());
			this->lblCartTitle = (gcnew System::Windows::Forms::Label());
			this->panelLeft->SuspendLayout();
			this->panelRight->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCart))->BeginInit();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::DarkGreen;
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(1212, 60);
			this->panelHeader->TabIndex = 1;
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::White;
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogout->ForeColor = System::Drawing::Color::DarkGreen;
			this->btnLogout->Location = System::Drawing::Point(1000, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(170, 35);
			this->btnLogout->TabIndex = 4;
			this->btnLogout->Text = L"LOGOUT";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &CashierDashboard::btnLogout_Click);
			// 
			// lblstoreTitle
			// 
			this->lblstoreTitle->AutoSize = true;
			this->lblstoreTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblstoreTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblstoreTitle->Location = System::Drawing::Point(3, 0);
			this->lblstoreTitle->Name = L"lblstoreTitle";
			this->lblstoreTitle->Size = System::Drawing::Size(244, 38);
			this->lblstoreTitle->TabIndex = 2;
			this->lblstoreTitle->Text = L"FRESHMART POS";
			// 
			// lblCashier
			// 
			this->lblCashier->AutoSize = true;
			this->lblCashier->BackColor = System::Drawing::Color::Transparent;
			this->lblCashier->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCashier->ForeColor = System::Drawing::Color::OrangeRed;
			this->lblCashier->Location = System::Drawing::Point(366, 14);
			this->lblCashier->Name = L"lblCashier";
			this->lblCashier->Size = System::Drawing::Size(167, 31);
			this->lblCashier->TabIndex = 3;
			this->lblCashier->Text = L"Cashier Name:";
			this->lblCashier->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panelLeft
			// 
			this->panelLeft->BackColor = System::Drawing::Color::Turquoise;
			this->panelLeft->Controls->Add(this->lstProducts);
			this->panelLeft->Controls->Add(this->txtSearch);
			this->panelLeft->Controls->Add(this->lblProductList);
			this->panelLeft->Controls->Add(this->btnManageStock);
			this->panelLeft->Controls->Add(this->btnAddProduct);
			this->panelLeft->Controls->Add(this->txtBarcode);
			this->panelLeft->Controls->Add(this->LblBarCode);
			this->panelLeft->Location = System::Drawing::Point(0, 60);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(447, 540);
			this->panelLeft->TabIndex = 5;
			// 
			// lstProducts
			// 
			this->lstProducts->FormattingEnabled = true;
			this->lstProducts->ItemHeight = 16;
			this->lstProducts->Location = System::Drawing::Point(20, 190);
			this->lstProducts->Name = L"lstProducts";
			this->lstProducts->Size = System::Drawing::Size(400, 292);
			this->lstProducts->TabIndex = 12;
			this->lstProducts->SelectedIndexChanged += gcnew System::EventHandler(this, &CashierDashboard::lstProducts_SelectedIndexChanged);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(20, 150);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(300, 22);
			this->txtSearch->TabIndex = 11;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &CashierDashboard::txtSearch_TextChanged);
			// 
			// lblProductList
			// 
			this->lblProductList->AutoSize = true;
			this->lblProductList->Location = System::Drawing::Point(20, 120);
			this->lblProductList->Name = L"lblProductList";
			this->lblProductList->Size = System::Drawing::Size(60, 16);
			this->lblProductList->TabIndex = 10;
			this->lblProductList->Text = L"Products";
			// 
			// btnManageStock
			// 
			this->btnManageStock->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnManageStock->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnManageStock->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnManageStock->ForeColor = System::Drawing::Color::White;
			this->btnManageStock->Location = System::Drawing::Point(12, 497);
			this->btnManageStock->Name = L"btnManageStock";
			this->btnManageStock->Size = System::Drawing::Size(410, 40);
			this->btnManageStock->TabIndex = 9;
			this->btnManageStock->Text = L"MANAGE STOCK";
			this->btnManageStock->UseVisualStyleBackColor = false;
			this->btnManageStock->Click += gcnew System::EventHandler(this, &CashierDashboard::btnManageStock_Click);
			// 
			// btnAddProduct
			// 
			this->btnAddProduct->BackColor = System::Drawing::Color::DarkGreen;
			this->btnAddProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddProduct->ForeColor = System::Drawing::Color::White;
			this->btnAddProduct->Location = System::Drawing::Point(226, 96);
			this->btnAddProduct->Name = L"btnAddProduct";
			this->btnAddProduct->Size = System::Drawing::Size(174, 40);
			this->btnAddProduct->TabIndex = 2;
			this->btnAddProduct->Text = L"ADD TO CART →";
			this->btnAddProduct->UseVisualStyleBackColor = false;
			this->btnAddProduct->Click += gcnew System::EventHandler(this, &CashierDashboard::btnAddProduct_Click);
			// 
			// txtBarcode
			// 
			this->txtBarcode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBarcode->Location = System::Drawing::Point(20, 45);
			this->txtBarcode->Name = L"txtBarcode";
			this->txtBarcode->Size = System::Drawing::Size(300, 34);
			this->txtBarcode->TabIndex = 1;
			this->txtBarcode->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CashierDashboard::txtBarcode_KeyPress);
			// 
			// LblBarCode
			// 
			this->LblBarCode->AutoSize = true;
			this->LblBarCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblBarCode->Location = System::Drawing::Point(20, 20);
			this->LblBarCode->Name = L"LblBarCode";
			this->LblBarCode->Size = System::Drawing::Size(138, 28);
			this->LblBarCode->TabIndex = 0;
			this->LblBarCode->Text = L"Scan Barcode :";
			// 
			// panelRight
			// 
			this->panelRight->Controls->Add(this->lblCashier);
			this->panelRight->Controls->Add(this->btnReturn);
			this->panelRight->Controls->Add(this->statusStrip1);
			this->panelRight->Controls->Add(this->btnCard);
			this->panelRight->Controls->Add(this->btnCash);
			this->panelRight->Controls->Add(this->btnClear);
			this->panelRight->Controls->Add(this->btnVoid);
			this->panelRight->Controls->Add(this->lblTotal);
			this->panelRight->Controls->Add(this->lblVAT);
			this->panelRight->Controls->Add(this->lblSubtotal);
			this->panelRight->Controls->Add(this->lblCartHeader);
			this->panelRight->Controls->Add(this->dgvCart);
			this->panelRight->Controls->Add(this->lblCartTitle);
			this->panelRight->Location = System::Drawing::Point(453, 66);
			this->panelRight->Name = L"panelRight";
			this->panelRight->Size = System::Drawing::Size(750, 540);
			this->panelRight->TabIndex = 6;
			// 
			// btnReturn
			// 
			this->btnReturn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnReturn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReturn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReturn->ForeColor = System::Drawing::Color::White;
			this->btnReturn->Location = System::Drawing::Point(157, 373);
			this->btnReturn->Name = L"btnReturn";
			this->btnReturn->Size = System::Drawing::Size(120, 40);
			this->btnReturn->TabIndex = 12;
			this->btnReturn->Text = L"RETURN";
			this->btnReturn->UseVisualStyleBackColor = false;
			this->btnReturn->Click += gcnew System::EventHandler(this, &CashierDashboard::btnReturn_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->lblStatus, this->lblLowStockAlert });
			this->statusStrip1->Location = System::Drawing::Point(0, 514);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(750, 26);
			this->statusStrip1->TabIndex = 11;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// lblStatus
			// 
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(97, 20);
			this->lblStatus->Text = L"Status: Ready";
			// 
			// lblLowStockAlert
			// 
			this->lblLowStockAlert->Name = L"lblLowStockAlert";
			this->lblLowStockAlert->Size = System::Drawing::Size(638, 20);
			this->lblLowStockAlert->Spring = true;
			this->lblLowStockAlert->Text = L"Low Stock : None";
			// 
			// btnCard
			// 
			this->btnCard->BackColor = System::Drawing::Color::Blue;
			this->btnCard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCard->ForeColor = System::Drawing::Color::White;
			this->btnCard->Location = System::Drawing::Point(318, 430);
			this->btnCard->Name = L"btnCard";
			this->btnCard->Size = System::Drawing::Size(100, 50);
			this->btnCard->TabIndex = 9;
			this->btnCard->Text = L"CARD";
			this->btnCard->UseVisualStyleBackColor = false;
			this->btnCard->Click += gcnew System::EventHandler(this, &CashierDashboard::btnCard_Click);
			// 
			// btnCash
			// 
			this->btnCash->BackColor = System::Drawing::Color::Green;
			this->btnCash->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCash->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCash->ForeColor = System::Drawing::Color::White;
			this->btnCash->Location = System::Drawing::Point(20, 430);
			this->btnCash->Name = L"btnCash";
			this->btnCash->Size = System::Drawing::Size(120, 50);
			this->btnCash->TabIndex = 8;
			this->btnCash->Text = L"CASH";
			this->btnCash->UseVisualStyleBackColor = false;
			this->btnCash->Click += gcnew System::EventHandler(this, &CashierDashboard::btnCash_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::Orange;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->ForeColor = System::Drawing::Color::White;
			this->btnClear->Location = System::Drawing::Point(157, 434);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(127, 46);
			this->btnClear->TabIndex = 7;
			this->btnClear->Text = L"CLEAR CART";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &CashierDashboard::btnClear_Click);
			// 
			// btnVoid
			// 
			this->btnVoid->BackColor = System::Drawing::Color::Red;
			this->btnVoid->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVoid->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVoid->ForeColor = System::Drawing::Color::White;
			this->btnVoid->Location = System::Drawing::Point(20, 370);
			this->btnVoid->Name = L"btnVoid";
			this->btnVoid->Size = System::Drawing::Size(120, 40);
			this->btnVoid->TabIndex = 6;
			this->btnVoid->Text = L"VOID";
			this->btnVoid->UseVisualStyleBackColor = false;
			this->btnVoid->Click += gcnew System::EventHandler(this, &CashierDashboard::btnVoid_Click);
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->Location = System::Drawing::Point(500, 430);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(190, 38);
			this->lblTotal->TabIndex = 5;
			this->lblTotal->Text = L"TOTAL: R0.00";
			this->lblTotal->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblVAT
			// 
			this->lblVAT->AutoSize = true;
			this->lblVAT->Location = System::Drawing::Point(500, 400);
			this->lblVAT->Name = L"lblVAT";
			this->lblVAT->Size = System::Drawing::Size(111, 16);
			this->lblVAT->TabIndex = 4;
			this->lblVAT->Text = L"VAT (15%): R0.00";
			this->lblVAT->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblSubtotal
			// 
			this->lblSubtotal->AutoSize = true;
			this->lblSubtotal->Location = System::Drawing::Point(500, 370);
			this->lblSubtotal->Name = L"lblSubtotal";
			this->lblSubtotal->Size = System::Drawing::Size(96, 16);
			this->lblSubtotal->TabIndex = 3;
			this->lblSubtotal->Text = L"Subtotal: R0.00";
			this->lblSubtotal->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblCartHeader
			// 
			this->lblCartHeader->AutoSize = true;
			this->lblCartHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCartHeader->Location = System::Drawing::Point(20, 20);
			this->lblCartHeader->Name = L"lblCartHeader";
			this->lblCartHeader->Size = System::Drawing::Size(257, 31);
			this->lblCartHeader->TabIndex = 2;
			this->lblCartHeader->Text = L"CURRENT SALE(CART):";
			// 
			// dgvCart
			// 
			this->dgvCart->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCart->Location = System::Drawing::Point(26, 54);
			this->dgvCart->Name = L"dgvCart";
			this->dgvCart->ReadOnly = true;
			this->dgvCart->RowHeadersWidth = 51;
			this->dgvCart->RowTemplate->Height = 24;
			this->dgvCart->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCart->Size = System::Drawing::Size(700, 300);
			this->dgvCart->TabIndex = 1;
			// 
			// lblCartTitle
			// 
			this->lblCartTitle->AutoSize = true;
			this->lblCartTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCartTitle->Location = System::Drawing::Point(20, 20);
			this->lblCartTitle->Name = L"lblCartTitle";
			this->lblCartTitle->Size = System::Drawing::Size(177, 31);
			this->lblCartTitle->TabIndex = 0;
			this->lblCartTitle->Text = L"CURRENT SALE";
			// 
			// CashierDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Turquoise;
			this->ClientSize = System::Drawing::Size(1212, 646);
			this->Controls->Add(this->panelRight);
			this->Controls->Add(this->panelLeft);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->lblstoreTitle);
			this->Controls->Add(this->panelHeader);
			this->Name = L"CashierDashboard";
			this->Text = L"FreshMart POS - Cashier Dashboard";
			this->panelLeft->ResumeLayout(false);
			this->panelLeft->PerformLayout();
			this->panelRight->ResumeLayout(false);
			this->panelRight->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			void UpdateProductStockDisplay(int productID, int newStock)
			{
				for each (Product ^ product in allProducts)
				{
					if (Convert::ToInt32(product->getProductID()) == productID)
					{
						product->setQuantity(newStock);
						break;
					}
				}

				filteredProducts = gcnew List<Product^>(allProducts);

				String^ searchTerm = txtSearch->Text->Trim()->ToLower();
				if (searchTerm != "")
				{
					filteredProducts = gcnew List<Product^>();
					for each (Product ^ product in allProducts)
					{
						if (product->getProductName()->ToLower()->Contains(searchTerm) ||
							product->getBarCode()->ToLower()->Contains(searchTerm))
						{
							filteredProducts->Add(product);
						}
					}
				}

				UpdateProductList();
			}
			private: 
				void UpdateProductList()
				{
					lstProducts->Items->Clear();

					for each (Product ^ product in filteredProducts)
					{
						lstProducts->Items->Add(product->getProductName() + " - R" + product->getPrice().ToString("0.00") + " (Stock: " + product->getQuantityInStock() + ")");
					}
				}

			private: 
				void RestoreAllStocks()
				{
					for (int i = 0; i < originalProductIDs->Count; i++)
					{
						int productID = originalProductIDs[i];
						int originalStock = originalStockValues[i];

						for each (Product ^ product in allProducts)
						{
							if (Convert::ToInt32(product->getProductID()) == productID)
							{
								product->setQuantity(originalStock);
								break;
							}
						}
					}

					filteredProducts = gcnew List<Product^>(allProducts);
					UpdateProductList();
				}

	private:	void LoadAllProducts()
		{
		
		allProducts = gcnew List<Product^>();
		originalProductIDs->Clear();
		originalStockValues->Clear();

		try
		{
			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			String^ query = "SELECT ProductID, Barcode, ProductName, SellingPrice, Quantity FROM Products WHERE IsActive = 1 ORDER BY ProductName";

			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			conn->Open();
			SqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				String^ id = reader["ProductID"]->ToString();
				String^ barcode = reader["Barcode"]->ToString();
				String^ name = reader["ProductName"]->ToString();
				double price = Convert::ToDouble(reader["SellingPrice"]);
				int stock = Convert::ToInt32(reader["Quantity"]);

				Product^ product = gcnew Product(id, name, barcode, price, stock);
				allProducts->Add(product);

				// Store original stock
				originalProductIDs->Add(Convert::ToInt32(id));
				originalStockValues->Add(stock);
			}
			conn->Close();

			filteredProducts = gcnew List<Product^>(allProducts);
			UpdateProductList();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error loading products: " + ex->Message);
		}



		


		}
	private: 
	void SeedProductsFromFile()
	{
		
		try
		{
			String^ filePath = Application::StartupPath + "\\products.txt";  

			if (!File::Exists(filePath))
			{
				MessageBox::Show("products.txt not found at: " + filePath);
				return;
			}

			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			conn->Open();

			array<String^>^ lines = File::ReadAllLines(filePath);
			int productsAdded = 0;

			for each (String ^ line in lines)
			{
				if (String::IsNullOrWhiteSpace(line)) continue;

				line = line->Trim();
				array<String^>^ parts = line->Split(',');

				if (parts->Length >= 6)
				{
					for (int i = 0; i < parts->Length; i++)
					{
						parts[i] = parts[i]->Trim();
					}

					String^ checkQuery = "SELECT COUNT(*) FROM Products WHERE Barcode = '" + parts[0] + "'";
					SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
					int exists = (int)checkCmd->ExecuteScalar();

					if (exists == 0)
					{
						String^ query = "INSERT INTO Products (Barcode, ProductName, SellingPrice, CostPrice, Quantity, MinStockLevel) "
							"VALUES ('" + parts[0] + "', '" + parts[1] + "', " + parts[2] + ", " + parts[3] + ", " + parts[4] + ", " + parts[5] + ")";

						SqlCommand^ cmd = gcnew SqlCommand(query, conn);
						cmd->ExecuteNonQuery();
						productsAdded++;
					}
				}
			}

			conn->Close();

			if (productsAdded > 0)
				MessageBox::Show("Products seeded successfully! Added " + productsAdded + " products.");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Seed error: " + ex->Message);
		}





	}

		

private: System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e)
{

	String^ barcode = txtBarcode->Text->Trim();

	if (barcode == "")
	{
		
		if (lstProducts->SelectedIndex >= 0)
		{
			Product^ selected = filteredProducts[lstProducts->SelectedIndex];

			
			if (selected->getQuantityInStock() > 0)
			{
				AddToCart(selected->getProductName(), selected->getPrice(), 1);

				// Reduce stock display
				int currentStock = selected->getQuantityInStock();
				UpdateProductStockDisplay(Convert::ToInt32(selected->getProductID()), currentStock - 1);

				txtBarcode->Clear();
				txtBarcode->Focus();
			}
			else
			{
				MessageBox::Show(selected->getProductName() + " is out of stock!", "Stock Error");
			}
		}
		else
		{
			MessageBox::Show("Please scan a barcode or select a product", "Input Required");
		}
		return;
	}

	// Find product by barcode
	for each (Product ^ product in allProducts)
	{
		if (product->getBarCode() == barcode)
		{
			if (product->getQuantityInStock() > 0)
			{
				AddToCart(product->getProductName(), product->getPrice(), 1);

				// Reduce stock display
				int currentStock = product->getQuantityInStock();
				UpdateProductStockDisplay(Convert::ToInt32(product->getProductID()), currentStock - 1);

				txtBarcode->Clear();
				txtBarcode->Focus();
			}
			else
			{
				MessageBox::Show(product->getProductName() + " is out of stock!", "Stock Error");
			}
			return;
		}
	}

	MessageBox::Show("Product not found!\nBarcode: " + barcode, "Not Found");
	txtBarcode->SelectAll();

}
private: System::Void btnVoid_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dgvCart->SelectedRows->Count == 0)
	{
		MessageBox::Show("Please select an item to void", "No Selection");
		return;
	}

	DataGridViewRow^ selectedRow = dgvCart->SelectedRows[0];
	String^ productName = selectedRow->Cells["Product"]->Value->ToString();
	int currentQty = Convert::ToInt32(selectedRow->Cells["Qty"]->Value);

	
	String^ input = Microsoft::VisualBasic::Interaction::InputBox(
		"Item: " + productName + "\nCurrent quantity: " + currentQty + "\n\nHow many items do you want to void?",
		"Void Quantity",
		"1",
		-1, -1);

	int voidQty = 1;
	if (!Int32::TryParse(input, voidQty))
	{
		MessageBox::Show("Invalid quantity entered. Void cancelled.", "Error");
		return;
	}

	if (voidQty <= 0 || voidQty > currentQty)
	{
		MessageBox::Show("Invalid quantity. Must be between 1 and " + currentQty, "Error");
		return;
	}

	
	if (loggedInUser->getRole() != "Admin")
	{
		String^ password = Microsoft::VisualBasic::Interaction::InputBox(
			"Manager authorization required.\nEnter Manager Password to void item:",
			"Manager Override",
			"",
			-1, -1);

		if (password != "admin123")
		{
			MessageBox::Show("Invalid Manager Password. Void cancelled.", "Access Denied");
			return;
		}
	}

	// Calculate new quantity
	int newQty = currentQty - voidQty;

	if (newQty == 0)
	{
		// Remove entire row
		DataRowView^ rowView = safe_cast<DataRowView^>(selectedRow->DataBoundItem);
		DataRow^ row = rowView->Row;
		cartTable->Rows->Remove(row);
	}
	else
	{
		// Update quantity in cart
		selectedRow->Cells["Qty"]->Value = newQty;
		double price = Convert::ToDouble(selectedRow->Cells["Price"]->Value);
		selectedRow->Cells["Total"]->Value = newQty * price;
	}

	// Restore stock for voided items
	for each (Product ^ product in allProducts)
	{
		if (product->getProductName() == productName)
		{
			int currentStock = product->getQuantityInStock();
			UpdateProductStockDisplay(Convert::ToInt32(product->getProductID()), currentStock + voidQty);
			break;
		}
	}

	UpdateTotals();
	MessageBox::Show("Voided " + voidQty + " x " + productName, "Void Successful");
}
private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e)
{

	RestoreAllStocks();
	loggedInUser->Logout();
	this->Close();

}
private: System::Void txtBarcode_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{

	if (e->KeyChar == (char)13) // Enter key
	{
		btnAddProduct_Click(sender, gcnew System::EventArgs());
		e->Handled = true;
	}





}
	   private:
		   void ProcessCashPayment()
		   {
			   // Ask for amount tendered
			   if (isProcessingPayment) return;

			   isProcessingPayment = true;

			   // Ask for amount tendered
			   if (cartTable->Rows->Count == 0)
			   {
				   MessageBox::Show("Cart is empty! Please add items first.", "No Items");
				   isProcessingPayment = false;
				   return;
			   }

			   // Show total amount due
			   MessageBox::Show("Total amount due: " + lblTotal->Text, "Amount Due");

			   // Ask for amount tendered
			   String^ input = Microsoft::VisualBasic::Interaction::InputBox(
				   "Total Amount: " + lblTotal->Text + "\n\nEnter amount tendered by customer:",
				   "Cash Payment",
				   totalAmount.ToString("0.00"),
				   -1, -1);

			   // Check if user cancelled
			   if (input == "")
			   {
				   MessageBox::Show("Payment cancelled by user.", "Cancelled");
				   isProcessingPayment = false;
				   return;
			   }

			   double amountTendered;
			   if (!Double::TryParse(input, amountTendered))
			   {
				   MessageBox::Show("Invalid amount entered. Please enter a valid number.", "Error");
				   isProcessingPayment = false;
				   return;
			   }

			   // Check if amount is sufficient
			   if (amountTendered < totalAmount)
			   {
				   double shortAmount = totalAmount - amountTendered;
				   MessageBox::Show("Insufficient payment!\n\n"
					   + "Total: R" + totalAmount.ToString("0.00") + "\n"
					   + "Tendered: R" + amountTendered.ToString("0.00") + "\n"
					   + "Short by: R" + shortAmount.ToString("0.00") + "\n\n"
					   + "Please ask customer for more money.",
					   "Payment Declined", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   isProcessingPayment = false;
				   return;  // Payment declined - don't process sale
			   }

			   // Calculate change
			   double change = amountTendered - totalAmount;

			   // Show change
			   if (change > 0)
			   {
				   MessageBox::Show("Payment Accepted!\n\n"
					   + "Total: R" + totalAmount.ToString("0.00") + "\n"
					   + "Tendered: R" + amountTendered.ToString("0.00") + "\n"
					   + "Change Due: R" + change.ToString("0.00") + "\n\n"
					   + "Proceeding with sale...",
					   "Change Due", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
			   else
			   {
				   MessageBox::Show("Payment Accepted!\n\n"
					   + "Total: R" + totalAmount.ToString("0.00") + "\n"
					   + "Tendered: R" + amountTendered.ToString("0.00") + "\n"
					   + "Exact amount received.\n\n"
					   + "Proceeding with sale...",
					   "Payment Accepted", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }

			   // Disable entire form to prevent Enter key from triggering
			   this->Enabled = false;

			   // Process the sale
			   ProcessSale("Cash", amountTendered, change);

			   // Re-enable entire form
			   this->Enabled = true;

			   isProcessingPayment = false;
			  
			
		   }

 private: 
	void ProcessSale(String^ paymentMethod, double amountTendered, double change)
	{
		try
		{
			String^ invoiceNo = "INV-" + DateTime::Now.ToString("yyyyMMddHHmmss");

			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			String^ saleQuery = "INSERT INTO Sales (InvoiceNumber, UserID, SubTotal, VATAmount, TotalAmount, PaymentMethod, AmountTendered, ChangeDue) "
				+ "VALUES (@InvoiceNo, @UserID, @Subtotal, @VAT, @Total, @PaymentMethod, @AmountTendered, @ChangeDue); SELECT SCOPE_IDENTITY();";

			SqlCommand^ saleCmd = gcnew SqlCommand(saleQuery, conn);
			saleCmd->Parameters->AddWithValue("@InvoiceNo", invoiceNo);
			saleCmd->Parameters->AddWithValue("@UserID", Convert::ToInt32(loggedInUser->getUserID()));
			saleCmd->Parameters->AddWithValue("@Subtotal", subtotal);
			saleCmd->Parameters->AddWithValue("@VAT", vatAmount);
			saleCmd->Parameters->AddWithValue("@Total", totalAmount);
			saleCmd->Parameters->AddWithValue("@PaymentMethod", paymentMethod);
			saleCmd->Parameters->AddWithValue("@AmountTendered", amountTendered);
			saleCmd->Parameters->AddWithValue("@ChangeDue", change);

			conn->Open();
			int saleID = Convert::ToInt32(saleCmd->ExecuteScalar());

			for each (DataRow ^ row in cartTable->Rows)
			{
				String^ productName = row["Product"]->ToString();
				int qty = (int)row["Qty"];
				double price = (double)row["Price"];
				double total = (double)row["Total"];

				String^ getProductQuery = "SELECT ProductID, Quantity FROM Products WHERE ProductName = @ProductName";
				SqlCommand^ productCmd = gcnew SqlCommand(getProductQuery, conn);
				productCmd->Parameters->AddWithValue("@ProductName", productName);
				SqlDataReader^ reader = productCmd->ExecuteReader();
				int productID = 0;
				int currentStock = 0;
				if (reader->Read())
				{
					productID = Convert::ToInt32(reader["ProductID"]);
					currentStock = Convert::ToInt32(reader["Quantity"]);
				}
				reader->Close();

				String^ itemQuery = "INSERT INTO SaleItems (SaleID, ProductID, Quantity, UnitPrice, TotalPrice) "
					+ "VALUES (@SaleID, @ProductID, @Qty, @Price, @Total)";
				SqlCommand^ itemCmd = gcnew SqlCommand(itemQuery, conn);
				itemCmd->Parameters->AddWithValue("@SaleID", saleID);
				itemCmd->Parameters->AddWithValue("@ProductID", productID);
				itemCmd->Parameters->AddWithValue("@Qty", qty);
				itemCmd->Parameters->AddWithValue("@Price", price);
				itemCmd->Parameters->AddWithValue("@Total", total);
				itemCmd->ExecuteNonQuery();

				int newStock = currentStock - qty;
				String^ stockQuery = "UPDATE Products SET Quantity = @NewStock WHERE ProductID = @ProductID";
				SqlCommand^ stockCmd = gcnew SqlCommand(stockQuery, conn);
				stockCmd->Parameters->AddWithValue("@NewStock", newStock);
				stockCmd->Parameters->AddWithValue("@ProductID", productID);
				stockCmd->ExecuteNonQuery();
			}

			conn->Close();

			String^ receipt = GenerateReceiptWithChange(invoiceNo, paymentMethod, amountTendered, change);
			MessageBox::Show(receipt, "RECEIPT - " + invoiceNo, MessageBoxButtons::OK, MessageBoxIcon::Information);

			cartTable->Clear();
			UpdateTotals();
			UpdateClearButtonState();
			LoadAllProducts();

			lblStatus->Text = "Status: Sale Completed - " + paymentMethod;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error processing sale: " + ex->Message, "Error");
		}
				 





	 }


	private:		
		String^ GenerateReceiptWithChange(String^ invoiceNo, String^ paymentMethod, double amountTendered, double change)
			   {
			String^ receipt = "=========================================\n";
			receipt += "           FRESHMART POS                \n";
			receipt += "        " + DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss") + "       \n";
			receipt += "=========================================\n";
			receipt += "Invoice: " + invoiceNo + "\n";
			receipt += "Cashier: " + loggedInUser->getUserName() + "\n";
			receipt += "=========================================\n";
			receipt += "Qty  Product              Price       \n";
			receipt += "=========================================\n";

			for each (DataRow ^ row in cartTable->Rows)
			{
				String^ line = String::Format("{0,-3} {1,-20} R{2,8:F2}",
					row["Qty"], row["Product"], row["Price"]);
				receipt += line + "\n";
			}

			receipt += "=========================================\n";
			receipt += String::Format("Subtotal:                    R{0,8:F2}\n", subtotal);
			receipt += String::Format("VAT (15%):                   R{0,8:F2}\n", vatAmount);
			receipt += String::Format("TOTAL:                       R{0,8:F2}\n", totalAmount);
			receipt += "=========================================\n";
			receipt += String::Format("Payment: {0}\n", paymentMethod);
			receipt += String::Format("Amount Tendered:             R{0,8:F2}\n", amountTendered);

			if (change > 0)
			{
				receipt += String::Format("Change:                      R{0,8:F2}\n", change);
			}

			receipt += "=========================================\n";
			receipt += "     THANK YOU FOR SHOPPING!        \n";
			receipt += "=========================================";

			return receipt;
			   }




private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (isProcessingPayment) return;
	if (isClearingCart) return;

	if (cartTable->Rows->Count == 0)
	{
		return;
	}

	isClearingCart = true;

	// Disable the button during processing – DO NOT RE-ENABLE IT HERE
	btnClear->Enabled = false;
	Application::DoEvents();

	System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to clear the entire cart?\n\nAll items will be removed.",
		"Clear Cart",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		cartTable->Clear();
		UpdateTotals();
		lblStatus->Text = "Status: Cart cleared";
		MessageBox::Show("Cart has been cleared!", "Cart Cleared",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	// IMPORTANT: Do NOT re-enable the button here – let it stay disabled.
	// The button will be re-enabled only when a new item is added.

	isClearingCart = false;
	

}
	   void ProcessSale(String^ paymentMethod)
	   {
		   try
		   {
			   String^ invoiceNo = "INV-" + DateTime::Now.ToString("yyyyMMddHHmmss");

			   SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			   String^ saleQuery = "INSERT INTO Sales (InvoiceNumber, UserID, SubTotal, VATAmount, TotalAmount, PaymentMethod) " +
				   "VALUES (@InvoiceNo, @UserID, @Subtotal, @VAT, @Total, @PaymentMethod); SELECT SCOPE_IDENTITY();";

			   SqlCommand^ saleCmd = gcnew SqlCommand(saleQuery, conn);
			   saleCmd->Parameters->AddWithValue("@InvoiceNo", invoiceNo);
			   saleCmd->Parameters->AddWithValue("@UserID", Convert::ToInt32(loggedInUser->getUserID()));
			   saleCmd->Parameters->AddWithValue("@Subtotal", subtotal);
			   saleCmd->Parameters->AddWithValue("@VAT", vatAmount);
			   saleCmd->Parameters->AddWithValue("@Total", totalAmount);
			   saleCmd->Parameters->AddWithValue("@PaymentMethod", paymentMethod);

			   conn->Open();
			   int saleID = Convert::ToInt32(saleCmd->ExecuteScalar());

			   for each (DataRow ^ row in cartTable->Rows)
			   {
				   String^ productName = row["Product"]->ToString();
				   int qty = (int)row["Qty"];
				   double price = (double)row["Price"];
				   double total = (double)row["Total"];

				   String^ getProductQuery = "SELECT ProductID, Quantity FROM Products WHERE ProductName = @ProductName";
				   SqlCommand^ productCmd = gcnew SqlCommand(getProductQuery, conn);
				   productCmd->Parameters->AddWithValue("@ProductName", productName);
				   SqlDataReader^ reader = productCmd->ExecuteReader();
				   int productID = 0;
				   int currentStock = 0;
				   if (reader->Read())
				   {
					   productID = Convert::ToInt32(reader["ProductID"]);
					   currentStock = Convert::ToInt32(reader["Quantity"]);
				   }
				   reader->Close();

				   String^ itemQuery = "INSERT INTO SaleItems (SaleID, ProductID, Quantity, UnitPrice, TotalPrice) " +
					   "VALUES (@SaleID, @ProductID, @Qty, @Price, @Total)";
				   SqlCommand^ itemCmd = gcnew SqlCommand(itemQuery, conn);
				   itemCmd->Parameters->AddWithValue("@SaleID", saleID);
				   itemCmd->Parameters->AddWithValue("@ProductID", productID);
				   itemCmd->Parameters->AddWithValue("@Qty", qty);
				   itemCmd->Parameters->AddWithValue("@Price", price);
				   itemCmd->Parameters->AddWithValue("@Total", total);
				   itemCmd->ExecuteNonQuery();

				   int newStock = currentStock - qty;
				   String^ stockQuery = "UPDATE Products SET Quantity = @NewStock WHERE ProductID = @ProductID";
				   SqlCommand^ stockCmd = gcnew SqlCommand(stockQuery, conn);
				   stockCmd->Parameters->AddWithValue("@NewStock", newStock);
				   stockCmd->Parameters->AddWithValue("@ProductID", productID);
				   stockCmd->ExecuteNonQuery();
			   }

			   conn->Close();

			   String^ receipt = GenerateReceipt(invoiceNo, paymentMethod);
			   MessageBox::Show(receipt, "RECEIPT - " + invoiceNo, MessageBoxButtons::OK, MessageBoxIcon::Information);

			   cartTable->Clear();
			   UpdateTotals();
			   CheckLowStock();

			   lblStatus->Text = "Status: Sale Completed - " + paymentMethod;
		   }
		   catch (Exception^ ex)
		   {
			   MessageBox::Show("Error processing sale: " + ex->Message, "Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
	   }
	   String^ GenerateReceipt(String^ invoiceNo, String^ paymentMethod)
	   {
		   String^ receipt = "=========================================\n";
		   receipt += "           FRESHMART POS                \n";
		   receipt += "        " + DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss") + "       \n";
		   receipt += "=========================================\n";
		   receipt += "Invoice: " + invoiceNo + "\n";
		   receipt += "Cashier: " + loggedInUser->getUserName() + "\n";
		   receipt += "=========================================\n";
		   receipt += "Qty  Product              Price       \n";
		   receipt += "=========================================\n";

		   for each (DataRow ^ row in cartTable->Rows)
		   {
			   String^ line = String::Format("{0,-3} {1,-20} R{2,8:F2}",
				   row["Qty"], row["Product"], row["Price"]);
			   receipt += line + "\n";
		   }

		   receipt += "=========================================\n";
		   receipt += String::Format("Subtotal:                    R{0,8:F2}\n", subtotal);
		   receipt += String::Format("VAT (15%):                   R{0,8:F2}\n", vatAmount);
		   receipt += String::Format("TOTAL:                       R{0,8:F2}\n", totalAmount);
		   receipt += "=========================================\n";
		   receipt += String::Format("Payment: {0}\n", paymentMethod);
		   receipt += "=========================================\n";
		   receipt += "     THANK YOU FOR SHOPPING!        \n";
		   receipt += "=========================================";

		   return receipt;
	   }
	   void CheckLowStock()
	   {
		   try
		   {
			   SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			   String^ query = "SELECT ProductName, Quantity, MinStockLevel FROM Products WHERE Quantity <= MinStockLevel AND IsActive = 1";

			   SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			   conn->Open();
			   SqlDataReader^ reader = cmd->ExecuteReader();

			   String^ lowStockItems = "";
			   int count = 0;

			   while (reader->Read())
			   {
				   String^ productName = reader["ProductName"]->ToString();
				   int quantity = Convert::ToInt32(reader["Quantity"]);
				   int minLevel = Convert::ToInt32(reader["MinStockLevel"]);
				   lowStockItems += "• " + productName + " (Stock: " + quantity + ", Min: " + minLevel + ")\n";
				   count++;
			   }
			   conn->Close();

			   if (count > 0)
			   {
				   lblLowStockAlert->Text = "Low Stock Alert: " + count + " item(s) need reorder";
				   MessageBox::Show("LOW STOCK ALERT!\n\nThe following items need reordering:\n\n" + lowStockItems,
					   "Inventory Alert", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   }
			   else
			   {
				   lblLowStockAlert->Text = "Low Stock: None";
			   }
		   }
		   catch (Exception^ ex)
		   {
			   System::Diagnostics::Debug::WriteLine(ex->Message);
		   }
	   }

private: System::Void btnCash_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isProcessingPayment) return;

	if (cartTable->Rows->Count == 0)
	{
		MessageBox::Show("Cart is empty! Add items first.", "No Items");
		return;
	}

	isProcessingPayment = true;

	// Disable all relevant buttons to prevent re-click
	btnCash->Enabled = false;
	btnCard->Enabled = false;
	btnClear->Enabled = false;
	btnVoid->Enabled = false;

	Application::DoEvents(); // Force UI to update

	String^ input = Microsoft::VisualBasic::Interaction::InputBox(
		"Total Amount: " + lblTotal->Text + "\n\nEnter amount tendered by customer:",
		"Cash Payment",
		totalAmount.ToString("0.00"),
		-1, -1);

	if (input == "")
	{
		MessageBox::Show("Payment cancelled.", "Cancelled");
		// Re-enable buttons
		btnCash->Enabled = true;
		btnCard->Enabled = true;
		btnVoid->Enabled = true;
		UpdateClearButtonState();   // re-evaluate clear button state
		isProcessingPayment = false;
		return;
	}

	double amountTendered;
	if (!Double::TryParse(input, amountTendered))
	{
		MessageBox::Show("Invalid amount! Please enter a valid number.", "Error");
		btnCash->Enabled = true;
		btnCard->Enabled = true;
		btnVoid->Enabled = true;
		UpdateClearButtonState();
		isProcessingPayment = false;
		return;
	}

	if (amountTendered < totalAmount)
	{
		MessageBox::Show("Insufficient payment!\n\nTotal: " + lblTotal->Text +
			"\nTendered: R" + amountTendered.ToString("0.00") +
			"\nShort: R" + (totalAmount - amountTendered).ToString("0.00"),
			"Payment Declined", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		btnCash->Enabled = true;
		btnCard->Enabled = true;
		btnVoid->Enabled = true;
		UpdateClearButtonState();
		isProcessingPayment = false;
		return;
	}

	double change = amountTendered - totalAmount;

	if (change > 0)
	{
		MessageBox::Show("Change Due: R" + change.ToString("0.00"), "Change",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	// Disable entire form to prevent Enter key from triggering during processing
	this->Enabled = false;

	ProcessSale("Cash", amountTendered, change);

	// Re-enable entire form
	this->Enabled = true;

	// ✅ LOW STOCK CHECK AFTER FORM IS ACTIVE
	CheckLowStock();

	// Re-enable buttons after sale is complete
	btnCash->Enabled = true;
	btnCard->Enabled = true;
	btnVoid->Enabled = true;
	// Clear button state depends on cart (now empty, so it will be disabled)
	UpdateClearButtonState();
	isProcessingPayment = false;

	
}
private: System::Void btnCard_Click(System::Object^ sender, System::EventArgs^ e)
{


	if (isProcessingPayment) return;

	if (cartTable->Rows->Count == 0)
	{
		MessageBox::Show("Cart is empty! Add items first.", "No Items");
		return;
	}

	isProcessingPayment = true;

	// Disable all relevant buttons to prevent re-click
	btnCash->Enabled = false;
	btnCard->Enabled = false;
	btnClear->Enabled = false;
	btnVoid->Enabled = false;

	Application::DoEvents(); // Force UI to update

	// Disable entire form to prevent Enter key from triggering during processing
	this->Enabled = false;

	ProcessSale("Card", totalAmount, 0);

	// Re-enable entire form
	this->Enabled = true;

	// ✅ LOW STOCK CHECK AFTER FORM IS ACTIVE
	CheckLowStock();

	// Re-enable buttons after sale is complete
	btnCash->Enabled = true;
	btnCard->Enabled = true;
	btnVoid->Enabled = true;
	// Clear button state depends on cart (now empty, so it will be disabled)
	UpdateClearButtonState();
	isProcessingPayment = false;

}


private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{

	String^ searchTerm = txtSearch->Text->Trim()->ToLower();

	if (searchTerm == "")
	{
		filteredProducts = gcnew List<Product^>(allProducts);
	}
	else
	{
		filteredProducts = gcnew List<Product^>();

		for each (Product ^ product in allProducts)
		{
			if (product->getProductName()->ToLower()->Contains(searchTerm) ||
				product->getBarCode()->ToLower()->Contains(searchTerm))
			{
				filteredProducts->Add(product);
			}
		}
	}

	UpdateProductList();

	// Auto-highlight if only one item left
	if (filteredProducts->Count == 1)
	{
		lstProducts->SelectedIndex = 0;
	}




}
private: System::Void lstProducts_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{



	if (lstProducts->SelectedIndex >= 0)
	{
		Product^ selected = filteredProducts[lstProducts->SelectedIndex];
		txtBarcode->Text = selected->getBarCode();
	}









}
private: System::Void btnManageStock_Click(System::Object^ sender, System::EventArgs^ e) 
{



	ProductManagementForm^ productForm = gcnew ProductManagementForm(loggedInUser);
	productForm->ShowDialog();
	LoadAllProducts();




}
private: System::Void btnReturn_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReturnForm^ returnForm = gcnew ReturnForm(loggedInUser);
	returnForm->ShowDialog();
}
};
}
