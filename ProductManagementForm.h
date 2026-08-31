#pragma once
#include "User.h"
#include "Product.h"
namespace SupermarketPOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Data;
	using namespace System::IO;
	/// <summary>
	/// Summary for ProductManagementForm
	/// </summary>
	public ref class ProductManagementForm : public System::Windows::Forms::Form
	{
	public:
		ProductManagementForm(User^ user)
		{

			loggedInUser = user;
			InitializeComponent();
			SeedProductsFromFile();
			LoadProducts();



		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProductManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}

	internal: System::Windows::Forms::GroupBox^ grpProductDetails;
	private:
	private: System::Windows::Forms::Label^ lblBarcode;
	private: System::Windows::Forms::TextBox^ txtBarcode;
	private: System::Windows::Forms::Label^ lblProductName;
	private: System::Windows::Forms::TextBox^ txtProductName;

	private: System::Windows::Forms::Label^ lblPrice;
	private: System::Windows::Forms::TextBox^ txtPrice;
	private: System::Windows::Forms::Label^ lblCost;
	private: System::Windows::Forms::TextBox^ txtcost;
	private: System::Windows::Forms::Label^ lblQuantity;
	private: System::Windows::Forms::Label^ lblMinStock;
	private: System::Windows::Forms::TextBox^ txtQuantity;
	private: System::Windows::Forms::TextBox^ txtMinStock;
	private: System::Windows::Forms::GroupBox^ grpActions;
	private: System::Windows::Forms::Button^ btnClose;

	private: System::Windows::Forms::Button^ btnRefresh;

	private: System::Windows::Forms::Button^ btnClear;

	private: System::Windows::Forms::Button^ btnDelete;

	private: System::Windows::Forms::Button^ btnUpdate;

	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::DataGridView^ dgvProducts;






	private:
		User^ loggedInUser;






		   DataTable^ productsTable;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Barcode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SellingPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MinStockLevel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CostPrice;
	private: System::Windows::Forms::Label^ label1;
	private:
		bool seeded = false;

	private:
		String^ GetConnectionString()
		{
			return "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=SupermarketPOS;Integrated Security=True";
		}



	internal:

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
			this->grpProductDetails = (gcnew System::Windows::Forms::GroupBox());
			this->txtMinStock = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->lblBarcode = (gcnew System::Windows::Forms::Label());
			this->lblMinStock = (gcnew System::Windows::Forms::Label());
			this->txtBarcode = (gcnew System::Windows::Forms::TextBox());
			this->lblQuantity = (gcnew System::Windows::Forms::Label());
			this->lblProductName = (gcnew System::Windows::Forms::Label());
			this->txtcost = (gcnew System::Windows::Forms::TextBox());
			this->txtProductName = (gcnew System::Windows::Forms::TextBox());
			this->lblCost = (gcnew System::Windows::Forms::Label());
			this->lblPrice = (gcnew System::Windows::Forms::Label());
			this->grpActions = (gcnew System::Windows::Forms::GroupBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->dgvProducts = (gcnew System::Windows::Forms::DataGridView());
			this->ProductID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Barcode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SellingPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MinStockLevel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CostPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grpProductDetails->SuspendLayout();
			this->grpActions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProducts))->BeginInit();
			this->SuspendLayout();
			// 
			// grpProductDetails
			// 
			this->grpProductDetails->Controls->Add(this->txtMinStock);
			this->grpProductDetails->Controls->Add(this->txtPrice);
			this->grpProductDetails->Controls->Add(this->txtQuantity);
			this->grpProductDetails->Controls->Add(this->lblBarcode);
			this->grpProductDetails->Controls->Add(this->lblMinStock);
			this->grpProductDetails->Controls->Add(this->txtBarcode);
			this->grpProductDetails->Controls->Add(this->lblQuantity);
			this->grpProductDetails->Controls->Add(this->lblProductName);
			this->grpProductDetails->Controls->Add(this->txtcost);
			this->grpProductDetails->Controls->Add(this->txtProductName);
			this->grpProductDetails->Controls->Add(this->lblCost);
			this->grpProductDetails->Controls->Add(this->lblPrice);
			this->grpProductDetails->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpProductDetails->Location = System::Drawing::Point(32, 320);
			this->grpProductDetails->Name = L"grpProductDetails";
			this->grpProductDetails->Size = System::Drawing::Size(450, 317);
			this->grpProductDetails->TabIndex = 1;
			this->grpProductDetails->TabStop = false;
			this->grpProductDetails->Text = L"PRODUCT DETAILS";
			// 
			// txtMinStock
			// 
			this->txtMinStock->Location = System::Drawing::Point(170, 231);
			this->txtMinStock->Name = L"txtMinStock";
			this->txtMinStock->Size = System::Drawing::Size(231, 30);
			this->txtMinStock->TabIndex = 13;
			// 
			// txtPrice
			// 
			this->txtPrice->Location = System::Drawing::Point(157, 111);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(244, 30);
			this->txtPrice->TabIndex = 7;
			// 
			// txtQuantity
			// 
			this->txtQuantity->Location = System::Drawing::Point(170, 193);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(231, 30);
			this->txtQuantity->TabIndex = 12;
			// 
			// lblBarcode
			// 
			this->lblBarcode->AutoSize = true;
			this->lblBarcode->Location = System::Drawing::Point(8, 31);
			this->lblBarcode->Name = L"lblBarcode";
			this->lblBarcode->Size = System::Drawing::Size(80, 23);
			this->lblBarcode->TabIndex = 2;
			this->lblBarcode->Text = L"Barcode:";
			// 
			// lblMinStock
			// 
			this->lblMinStock->AutoSize = true;
			this->lblMinStock->Location = System::Drawing::Point(8, 231);
			this->lblMinStock->Name = L"lblMinStock";
			this->lblMinStock->Size = System::Drawing::Size(142, 23);
			this->lblMinStock->TabIndex = 11;
			this->lblMinStock->Text = L"Min Stock Level:";
			// 
			// txtBarcode
			// 
			this->txtBarcode->Location = System::Drawing::Point(117, 29);
			this->txtBarcode->Name = L"txtBarcode";
			this->txtBarcode->Size = System::Drawing::Size(284, 30);
			this->txtBarcode->TabIndex = 3;
			// 
			// lblQuantity
			// 
			this->lblQuantity->AutoSize = true;
			this->lblQuantity->Location = System::Drawing::Point(8, 191);
			this->lblQuantity->Name = L"lblQuantity";
			this->lblQuantity->Size = System::Drawing::Size(156, 23);
			this->lblQuantity->TabIndex = 10;
			this->lblQuantity->Text = L"Quantity in Stock:";
			// 
			// lblProductName
			// 
			this->lblProductName->AutoSize = true;
			this->lblProductName->Location = System::Drawing::Point(8, 71);
			this->lblProductName->Name = L"lblProductName";
			this->lblProductName->Size = System::Drawing::Size(130, 23);
			this->lblProductName->TabIndex = 4;
			this->lblProductName->Text = L"Product Name:";
			// 
			// txtcost
			// 
			this->txtcost->Location = System::Drawing::Point(157, 153);
			this->txtcost->Name = L"txtcost";
			this->txtcost->Size = System::Drawing::Size(244, 30);
			this->txtcost->TabIndex = 9;
			// 
			// txtProductName
			// 
			this->txtProductName->Location = System::Drawing::Point(156, 68);
			this->txtProductName->Name = L"txtProductName";
			this->txtProductName->Size = System::Drawing::Size(245, 30);
			this->txtProductName->TabIndex = 5;
			// 
			// lblCost
			// 
			this->lblCost->AutoSize = true;
			this->lblCost->Location = System::Drawing::Point(8, 151);
			this->lblCost->Name = L"lblCost";
			this->lblCost->Size = System::Drawing::Size(122, 23);
			this->lblCost->TabIndex = 8;
			this->lblCost->Text = L"Cost Price (R):";
			// 
			// lblPrice
			// 
			this->lblPrice->AutoSize = true;
			this->lblPrice->Location = System::Drawing::Point(8, 111);
			this->lblPrice->Name = L"lblPrice";
			this->lblPrice->Size = System::Drawing::Size(143, 23);
			this->lblPrice->TabIndex = 6;
			this->lblPrice->Text = L"Seling price  (R):";
			// 
			// grpActions
			// 
			this->grpActions->Controls->Add(this->btnClose);
			this->grpActions->Controls->Add(this->btnRefresh);
			this->grpActions->Controls->Add(this->btnClear);
			this->grpActions->Controls->Add(this->btnDelete);
			this->grpActions->Controls->Add(this->btnUpdate);
			this->grpActions->Controls->Add(this->btnAdd);
			this->grpActions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpActions->Location = System::Drawing::Point(500, 320);
			this->grpActions->Name = L"grpActions";
			this->grpActions->Size = System::Drawing::Size(460, 300);
			this->grpActions->TabIndex = 2;
			this->grpActions->TabStop = false;
			this->grpActions->Text = L"ACTIONS";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->ForeColor = System::Drawing::Color::White;
			this->btnClose->Location = System::Drawing::Point(240, 160);
			this->btnClose->Name = L"btnClose";
			this->btnClose->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->btnClose->Size = System::Drawing::Size(180, 45);
			this->btnClose->TabIndex = 5;
			this->btnClose->Text = L"CLOSE";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &ProductManagementForm::btnClose_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::DarkCyan;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->ForeColor = System::Drawing::Color::White;
			this->btnRefresh->Location = System::Drawing::Point(30, 160);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(180, 45);
			this->btnRefresh->TabIndex = 4;
			this->btnRefresh->Text = L"REFRESH LIST";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &ProductManagementForm::btnRefresh_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::Gray;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->ForeColor = System::Drawing::Color::White;
			this->btnClear->Location = System::Drawing::Point(240, 100);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(180, 45);
			this->btnClear->TabIndex = 3;
			this->btnClear->Text = L"CLEAR FIELDS";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &ProductManagementForm::btnClear_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::DarkRed;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(30, 100);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(180, 45);
			this->btnDelete->TabIndex = 2;
			this->btnDelete->Text = L"DELETE PRODUCT";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ProductManagementForm::btnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::RoyalBlue;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(240, 40);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(180, 45);
			this->btnUpdate->TabIndex = 1;
			this->btnUpdate->Text = L"UPDATE PRODUCT";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &ProductManagementForm::btnUpdate_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::DarkGreen;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->ForeColor = System::Drawing::Color::White;
			this->btnAdd->Location = System::Drawing::Point(30, 40);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(180, 45);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"ADD PRODUCT";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &ProductManagementForm::btnAdd_Click);
			// 
			// dgvProducts
			// 
			this->dgvProducts->AllowUserToAddRows = false;
			this->dgvProducts->AllowUserToDeleteRows = false;
			this->dgvProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProducts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->ProductID,
					this->Barcode, this->ProductName, this->SellingPrice, this->Quantity, this->MinStockLevel, this->CostPrice
			});
			this->dgvProducts->Location = System::Drawing::Point(32, 64);
			this->dgvProducts->MultiSelect = false;
			this->dgvProducts->Name = L"dgvProducts";
			this->dgvProducts->ReadOnly = true;
			this->dgvProducts->RowHeadersWidth = 51;
			this->dgvProducts->RowTemplate->Height = 24;
			this->dgvProducts->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvProducts->Size = System::Drawing::Size(964, 250);
			this->dgvProducts->TabIndex = 0;
			this->dgvProducts->SelectionChanged += gcnew System::EventHandler(this, &ProductManagementForm::dgvProducts_SelectionChanged);
			// 
			// ProductID
			// 
			this->ProductID->DataPropertyName = L"ProductID";
			this->ProductID->HeaderText = L"ID";
			this->ProductID->MinimumWidth = 6;
			this->ProductID->Name = L"ProductID";
			this->ProductID->ReadOnly = true;
			this->ProductID->Width = 125;
			// 
			// Barcode
			// 
			this->Barcode->DataPropertyName = L"Barcode";
			this->Barcode->HeaderText = L"Barcode";
			this->Barcode->MinimumWidth = 6;
			this->Barcode->Name = L"Barcode";
			this->Barcode->ReadOnly = true;
			this->Barcode->Width = 125;
			// 
			// ProductName
			// 
			this->ProductName->DataPropertyName = L"ProductName";
			this->ProductName->HeaderText = L"Product Name";
			this->ProductName->MinimumWidth = 6;
			this->ProductName->Name = L"ProductName";
			this->ProductName->ReadOnly = true;
			this->ProductName->Width = 125;
			// 
			// SellingPrice
			// 
			this->SellingPrice->DataPropertyName = L"SellingPrice";
			this->SellingPrice->HeaderText = L"Price (R)";
			this->SellingPrice->MinimumWidth = 6;
			this->SellingPrice->Name = L"SellingPrice";
			this->SellingPrice->ReadOnly = true;
			this->SellingPrice->Width = 125;
			// 
			// Quantity
			// 
			this->Quantity->DataPropertyName = L"Quantity";
			this->Quantity->HeaderText = L"Stock";
			this->Quantity->MinimumWidth = 6;
			this->Quantity->Name = L"Quantity";
			this->Quantity->ReadOnly = true;
			this->Quantity->Width = 125;
			// 
			// MinStockLevel
			// 
			this->MinStockLevel->DataPropertyName = L"MinStockLevel";
			this->MinStockLevel->HeaderText = L"Min Stock";
			this->MinStockLevel->MinimumWidth = 6;
			this->MinStockLevel->Name = L"MinStockLevel";
			this->MinStockLevel->ReadOnly = true;
			this->MinStockLevel->Width = 125;
			// 
			// CostPrice
			// 
			this->CostPrice->DataPropertyName = L"CostPrice";
			this->CostPrice->HeaderText = L"Cost Price (R)";
			this->CostPrice->MinimumWidth = 6;
			this->CostPrice->Name = L"CostPrice";
			this->CostPrice->ReadOnly = true;
			this->CostPrice->Width = 125;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(337, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(382, 37);
			this->label1->TabIndex = 3;
			this->label1->Text = L"PRODUCT MANAGEMENT";
			// 
			// ProductManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(1024, 684);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->grpActions);
			this->Controls->Add(this->grpProductDetails);
			this->Controls->Add(this->dgvProducts);
			this->Name = L"ProductManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreshMart POS - Product Management";
			this->grpProductDetails->ResumeLayout(false);
			this->grpProductDetails->PerformLayout();
			this->grpActions->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProducts))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void SeedProductsFromFile()
		{
			if (seeded) return; 

			try
			{
				String^ filePath = Application::StartupPath + "\\products.txt";

				if (!File::Exists(filePath))
				{
					return;  
				}

				SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
				conn->Open();

				array<String^>^ lines = File::ReadAllLines(filePath);

				for each (String ^ line in lines)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length >= 6)
					{
						String^ checkQuery = "SELECT COUNT(*) FROM Products WHERE Barcode = '" + parts[0] + "'";
						SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
						int exists = (int)checkCmd->ExecuteScalar();

						if (exists == 0)
						{
							String^ query = "INSERT INTO Products (Barcode, ProductName, SellingPrice, CostPrice, Quantity, MinStockLevel, IsActive) "
								+ "VALUES ('" + parts[0] + "', '" + parts[1] + "', " + parts[2] + ", " + parts[3] + ", " + parts[4] + ", " + parts[5] + ", 1)";

							SqlCommand^ cmd = gcnew SqlCommand(query, conn);
							cmd->ExecuteNonQuery();
						}
					}
				}

				conn->Close();
				seeded = true;  
				
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error seeding products: " + ex->Message);
			}
		}



		private: void LoadProducts()
		{

			try
			{
				SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
				String^ query = "SELECT ProductID, Barcode, ProductName, SellingPrice, CostPrice, Quantity, MinStockLevel FROM Products WHERE IsActive = 1";
				SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
				productsTable = gcnew DataTable();
				adapter->Fill(productsTable);
				conn->Close();

				// Clear and rebind
				dgvProducts->DataSource = nullptr;
				dgvProducts->DataSource = productsTable;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error loading products: " + ex->Message);
			}
		}


		private:void ClearFields()
	     {
			txtBarcode->Text = "";
			txtProductName->Text = "";
			txtPrice->Text = "";
			txtcost->Text = "";
			txtQuantity->Text = "";
			txtMinStock->Text = "";

		 }

private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
{

	try
	{
		String^ barcode = txtBarcode->Text->Trim();
		String^ productName = txtProductName->Text->Trim();
		String^ priceText = txtPrice->Text->Trim();

		if (barcode == "" || productName == "" || priceText == "")
		{
			MessageBox::Show("Please fill in Barcode, Product Name, and Price", "Missing Info");
			return;
		}

		SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
		conn->Open();

		// Check if barcode exists
		String^ checkBarcodeQuery = "SELECT COUNT(*) FROM Products WHERE Barcode = @barcode";
		SqlCommand^ checkBarcodeCmd = gcnew SqlCommand(checkBarcodeQuery, conn);
		checkBarcodeCmd->Parameters->AddWithValue("@barcode", barcode);
		int barcodeExists = (int)checkBarcodeCmd->ExecuteScalar();

		if (barcodeExists > 0)
		{
			MessageBox::Show("Product with this barcode already exists!", "Duplicate Barcode");
			conn->Close();
			return;
		}

		// Check if product name already exists
		String^ checkNameQuery = "SELECT COUNT(*) FROM Products WHERE ProductName = @name";
		SqlCommand^ checkNameCmd = gcnew SqlCommand(checkNameQuery, conn);
		checkNameCmd->Parameters->AddWithValue("@name", productName);
		int nameExists = (int)checkNameCmd->ExecuteScalar();

		if (nameExists > 0)
		{
			MessageBox::Show("Product with this name already exists!\nPlease use a different name.", "Duplicate Product Name");
			conn->Close();
			return;
		}

		double price = Convert::ToDouble(priceText);
		double cost = txtcost->Text->Trim() == "" ? 0 : Convert::ToDouble(txtcost->Text);
		int qty = txtQuantity->Text->Trim() == "" ? 0 : Convert::ToInt32(txtQuantity->Text);
		int minStock = txtMinStock->Text->Trim() == "" ? 5 : Convert::ToInt32(txtMinStock->Text);

		// Insert new product
		String^ query = "INSERT INTO Products (Barcode, ProductName, SellingPrice, CostPrice, Quantity, MinStockLevel, IsActive) "
			+ "VALUES (@barcode, @name, @price, @cost, @qty, @minStock, 1)";

		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@barcode", barcode);
		cmd->Parameters->AddWithValue("@name", productName);
		cmd->Parameters->AddWithValue("@price", price);
		cmd->Parameters->AddWithValue("@cost", cost);
		cmd->Parameters->AddWithValue("@qty", qty);
		cmd->Parameters->AddWithValue("@minStock", minStock);

		cmd->ExecuteNonQuery();
		conn->Close();

		MessageBox::Show("Product added successfully!", "Success");
		ClearFields();
		LoadProducts();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message);
	}

}
private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (dgvProducts->SelectedRows->Count == 0)
		{
			MessageBox::Show("Please select a product to update", "No Selection");
			return;
		}

		DataGridViewRow^ row = dgvProducts->SelectedRows[0];

		int productID = 0;
		String^ oldBarcode = "";
		String^ oldName = "";

		if (row->Cells["ProductID"]->Value != nullptr)
			productID = Convert::ToInt32(row->Cells["ProductID"]->Value);

		if (row->Cells["Barcode"]->Value != nullptr)
			oldBarcode = row->Cells["Barcode"]->Value->ToString();

		if (row->Cells["ProductName"]->Value != nullptr)
			oldName = row->Cells["ProductName"]->Value->ToString();

		if (productID == 0)
		{
			MessageBox::Show("Invalid product selected", "Error");
			return;
		}

		String^ newBarcode = txtBarcode->Text->Trim();
		String^ productName = txtProductName->Text->Trim();
		String^ priceText = txtPrice->Text->Trim();

		if (productName == "" || priceText == "")
		{
			MessageBox::Show("Product Name and Price are required", "Missing Info");
			return;
		}

		SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
		conn->Open();

		// ✅ CHECK BARCODE DUPLICATE (only if barcode changed)
		if (newBarcode != oldBarcode)
		{
			String^ checkBarcodeQuery = "SELECT COUNT(*) FROM Products WHERE Barcode = @barcode AND ProductID != @id";
			SqlCommand^ checkBarcodeCmd = gcnew SqlCommand(checkBarcodeQuery, conn);
			checkBarcodeCmd->Parameters->AddWithValue("@barcode", newBarcode);
			checkBarcodeCmd->Parameters->AddWithValue("@id", productID);
			int barcodeExists = (int)checkBarcodeCmd->ExecuteScalar();

			if (barcodeExists > 0)
			{
				MessageBox::Show("Product with this barcode already exists!\nPlease use a different barcode.", "Duplicate Barcode");
				conn->Close();
				return;
			}
		}

		// ✅ CHECK PRODUCT NAME DUPLICATE (only if name changed)
		if (productName != oldName)
		{
			String^ checkNameQuery = "SELECT COUNT(*) FROM Products WHERE ProductName = @name AND ProductID != @id";
			SqlCommand^ checkNameCmd = gcnew SqlCommand(checkNameQuery, conn);
			checkNameCmd->Parameters->AddWithValue("@name", productName);
			checkNameCmd->Parameters->AddWithValue("@id", productID);
			int nameExists = (int)checkNameCmd->ExecuteScalar();

			if (nameExists > 0)
			{
				MessageBox::Show("Product with this name already exists!\nPlease use a different name.", "Duplicate Product Name");
				conn->Close();
				return;
			}
		}

		double price = Convert::ToDouble(priceText);
		double cost = txtcost->Text->Trim() == "" ? 0 : Convert::ToDouble(txtcost->Text);
		int qty = txtQuantity->Text->Trim() == "" ? 0 : Convert::ToInt32(txtQuantity->Text);
		int minStock = txtMinStock->Text->Trim() == "" ? 5 : Convert::ToInt32(txtMinStock->Text);

		String^ query = "UPDATE Products SET Barcode=@barcode, ProductName=@name, SellingPrice=@price, "
			+ "CostPrice=@cost, Quantity=@qty, MinStockLevel=@minStock WHERE ProductID=@id";

		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@id", productID);
		cmd->Parameters->AddWithValue("@barcode", newBarcode);
		cmd->Parameters->AddWithValue("@name", productName);
		cmd->Parameters->AddWithValue("@price", price);
		cmd->Parameters->AddWithValue("@cost", cost);
		cmd->Parameters->AddWithValue("@qty", qty);
		cmd->Parameters->AddWithValue("@minStock", minStock);

		cmd->ExecuteNonQuery();
		conn->Close();

		MessageBox::Show("Product updated successfully!", "Success");
		ClearFields();
		LoadProducts();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message, "Update Error");
	}


}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ClearFields();

}
private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoadProducts();
	ClearFields();

}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) 
{

	this->Close();

}
private: System::Void dgvProducts_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
	

	try
	{
		if (dgvProducts->SelectedRows->Count > 0)
		{
			DataGridViewRow^ row = dgvProducts->SelectedRows[0];

			// Safely get Barcode
			if (row->Cells["Barcode"]->Value != nullptr)
				txtBarcode->Text = row->Cells["Barcode"]->Value->ToString();
			else
				txtBarcode->Text = "";

			// Safely get ProductName
			if (row->Cells["ProductName"]->Value != nullptr)
				txtProductName->Text = row->Cells["ProductName"]->Value->ToString();
			else
				txtProductName->Text = "";

			// Safely get SellingPrice
			if (row->Cells["SellingPrice"]->Value != nullptr)
				txtPrice->Text = row->Cells["SellingPrice"]->Value->ToString();
			else
				txtPrice->Text = "";

			// Safely get CostPrice
			if (row->Cells["CostPrice"]->Value != nullptr)
				txtcost->Text = row->Cells["CostPrice"]->Value->ToString();
			else
				txtcost->Text = "";

			// Safely get Quantity
			if (row->Cells["Quantity"]->Value != nullptr)
				txtQuantity->Text = row->Cells["Quantity"]->Value->ToString();
			else
				txtQuantity->Text = "0";

			// Safely get MinStockLevel
			if (row->Cells["MinStockLevel"]->Value != nullptr)
				txtMinStock->Text = row->Cells["MinStockLevel"]->Value->ToString();
			else
				txtMinStock->Text = "5";
		}
	}
	catch (Exception^ ex)
	{
		System::Diagnostics::Debug::WriteLine(ex->Message);
	}


}
private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) 
{

	try
	{
		if (dgvProducts->SelectedRows->Count == 0)
		{
			MessageBox::Show("Please select a product to delete", "No Selection");
			return;
		}

		// Safely get product info
		DataGridViewRow^ row = dgvProducts->SelectedRows[0];

		int productID = 0;
		String^ productName = "";

		if (row->Cells["ProductID"]->Value != nullptr)
			productID = Convert::ToInt32(row->Cells["ProductID"]->Value);

		if (row->Cells["ProductName"]->Value != nullptr)
			productName = row->Cells["ProductName"]->Value->ToString();

		if (productID == 0)
		{
			MessageBox::Show("Invalid product selected", "Error");
			return;
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show("Delete product '" + productName + "'?\n\nThis will remove it from the system.",
			"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			String^ query = "UPDATE Products SET IsActive = 0 WHERE ProductID = @id";

			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@id", productID);

			conn->Open();
			cmd->ExecuteNonQuery();
			conn->Close();

			MessageBox::Show("Product deleted successfully!", "Success");
			ClearFields();
			LoadProducts();
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message, "Delete Error");
	}

}
};
}
