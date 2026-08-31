#pragma once

#include "User.h"
#include "SaleItem.h"

namespace SupermarketPOS {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;
    using namespace Microsoft::VisualBasic;

    public ref class ReturnForm : public System::Windows::Forms::Form
    {
    public:
        ReturnForm(User^ user)
        {
            loggedInUser = user;
            InitializeComponent();

            selectedSaleItemID = 0;
            selectedProductID = 0;
            selectedPrice = 0;
            selectedPurchasedQty = 0;

            cboReason->DropDownStyle = ComboBoxStyle::DropDownList;
            cboReason->SelectedIndex = 0;
            txtOriginalPrice->ReadOnly = true;
            txtRefundAmount->ReadOnly = true;

            
            numQuantity->ValueChanged += gcnew System::EventHandler(this, &ReturnForm::numQuantity_ValueChanged);
        }

    protected:
        ~ReturnForm()
        {
            if (components)
                delete components;
        }

    private:
        // --- Control declarations (all from designer, plus txtSelectedProduct) ---
        System::Windows::Forms::Label^ lblSearchInstruction;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;
        System::Windows::Forms::DataGridView^ dgvSearchResults;
        System::Windows::Forms::GroupBox^ grpReturnDetails;
        System::Windows::Forms::Label^ lblSelectedProduct;
        System::Windows::Forms::Label^ lblQuantity;
        System::Windows::Forms::TextBox^ txtOriginalPrice;
        System::Windows::Forms::Label^ lblOriginalPrice;
        System::Windows::Forms::Label^ lblReason;
        System::Windows::Forms::NumericUpDown^ numQuantity;
        System::Windows::Forms::TextBox^ txtRefundAmount;
        System::Windows::Forms::Label^ lblRefundAmount;
        System::Windows::Forms::ComboBox^ cboReason;
        System::Windows::Forms::Button^ btnProcessReturn;
        System::Windows::Forms::Button^ btnCancel;
        // <-- ADDED (was missing)
        System::Windows::Forms::Label^ lblManagerNote;
        System::Windows::Forms::DataGridViewTextBoxColumn^ SaleItemID;
        System::Windows::Forms::DataGridViewTextBoxColumn^ Barcode;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ProductName;
        System::Windows::Forms::DataGridViewTextBoxColumn^ Price;

        // --- Data members ---
        User^ loggedInUser;
        int selectedSaleItemID;
        int selectedProductID;
        double selectedPrice;
        String^ selectedProductName;
        int selectedPurchasedQty;
    private: System::Windows::Forms::TextBox^ txtProductDisplay;
    private: System::Windows::Forms::Label^ label1;



        System::ComponentModel::Container^ components;

        String^ GetConnectionString()
        {
            return L"Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=SupermarketPOS;Integrated Security=True";
        }

        void InitializeComponent(void)
        {
            this->lblSearchInstruction = (gcnew System::Windows::Forms::Label());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dgvSearchResults = (gcnew System::Windows::Forms::DataGridView());
            this->SaleItemID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Barcode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ProductName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->grpReturnDetails = (gcnew System::Windows::Forms::GroupBox());
            this->txtProductDisplay = (gcnew System::Windows::Forms::TextBox());
            this->txtRefundAmount = (gcnew System::Windows::Forms::TextBox());
            this->lblRefundAmount = (gcnew System::Windows::Forms::Label());
            this->cboReason = (gcnew System::Windows::Forms::ComboBox());
            this->lblReason = (gcnew System::Windows::Forms::Label());
            this->numQuantity = (gcnew System::Windows::Forms::NumericUpDown());
            this->lblQuantity = (gcnew System::Windows::Forms::Label());
            this->txtOriginalPrice = (gcnew System::Windows::Forms::TextBox());
            this->lblOriginalPrice = (gcnew System::Windows::Forms::Label());
            this->lblSelectedProduct = (gcnew System::Windows::Forms::Label());
            this->btnProcessReturn = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->lblManagerNote = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSearchResults))->BeginInit();
            this->grpReturnDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->BeginInit();
            this->SuspendLayout();
            // 
            // lblSearchInstruction
            // 
            this->lblSearchInstruction->AutoSize = true;
            this->lblSearchInstruction->BackColor = System::Drawing::Color::Transparent;
            this->lblSearchInstruction->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblSearchInstruction->ForeColor = System::Drawing::Color::DarkGreen;
            this->lblSearchInstruction->Location = System::Drawing::Point(29, 93);
            this->lblSearchInstruction->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblSearchInstruction->Name = L"lblSearchInstruction";
            this->lblSearchInstruction->Size = System::Drawing::Size(454, 28);
            this->lblSearchInstruction->TabIndex = 7;
            this->lblSearchInstruction->Text = L"Scan barcode or enter product name to return:";
            // 
            // txtSearch
            // 
            this->txtSearch->BackColor = System::Drawing::Color::WhiteSmoke;
            this->txtSearch->Location = System::Drawing::Point(34, 138);
            this->txtSearch->Margin = System::Windows::Forms::Padding(2);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(449, 22);
            this->txtSearch->TabIndex = 6;
            // 
            // btnSearch
            // 
            this->btnSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(118)),
                static_cast<System::Int32>(static_cast<System::Byte>(210)));
            this->btnSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSearch->ForeColor = System::Drawing::Color::White;
            this->btnSearch->Location = System::Drawing::Point(492, 132);
            this->btnSearch->Margin = System::Windows::Forms::Padding(2);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(126, 35);
            this->btnSearch->TabIndex = 5;
            this->btnSearch->Text = L"SEARCH";
            this->btnSearch->UseVisualStyleBackColor = false;
            this->btnSearch->Click += gcnew System::EventHandler(this, &ReturnForm::btnSearch_Click);
            // 
            // dgvSearchResults
            // 
            this->dgvSearchResults->AllowUserToAddRows = false;
            this->dgvSearchResults->BackgroundColor = System::Drawing::Color::White;
            this->dgvSearchResults->ColumnHeadersHeight = 29;
            this->dgvSearchResults->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->SaleItemID,
                    this->Barcode, this->ProductName, this->Price
            });
            this->dgvSearchResults->Location = System::Drawing::Point(34, 177);
            this->dgvSearchResults->Margin = System::Windows::Forms::Padding(2);
            this->dgvSearchResults->Name = L"dgvSearchResults";
            this->dgvSearchResults->ReadOnly = true;
            this->dgvSearchResults->RowHeadersWidth = 51;
            this->dgvSearchResults->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvSearchResults->Size = System::Drawing::Size(606, 205);
            this->dgvSearchResults->TabIndex = 4;
            this->dgvSearchResults->SelectionChanged += gcnew System::EventHandler(this, &ReturnForm::dgvSearchResults_SelectionChanged);
            // 
            // SaleItemID
            // 
            this->SaleItemID->DataPropertyName = L"SaleItemID";
            this->SaleItemID->HeaderText = L"ID";
            this->SaleItemID->MinimumWidth = 6;
            this->SaleItemID->Name = L"SaleItemID";
            this->SaleItemID->ReadOnly = true;
            this->SaleItemID->Width = 125;
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
            // Price
            // 
            this->Price->DataPropertyName = L"Price";
            this->Price->HeaderText = L"Price";
            this->Price->MinimumWidth = 6;
            this->Price->Name = L"Price";
            this->Price->ReadOnly = true;
            this->Price->Width = 125;
            // 
            // grpReturnDetails
            // 
            this->grpReturnDetails->Controls->Add(this->txtProductDisplay);
            this->grpReturnDetails->Controls->Add(this->txtRefundAmount);
            this->grpReturnDetails->Controls->Add(this->lblRefundAmount);
            this->grpReturnDetails->Controls->Add(this->cboReason);
            this->grpReturnDetails->Controls->Add(this->lblReason);
            this->grpReturnDetails->Controls->Add(this->numQuantity);
            this->grpReturnDetails->Controls->Add(this->lblQuantity);
            this->grpReturnDetails->Controls->Add(this->txtOriginalPrice);
            this->grpReturnDetails->Controls->Add(this->lblOriginalPrice);
            this->grpReturnDetails->Controls->Add(this->lblSelectedProduct);
            this->grpReturnDetails->Location = System::Drawing::Point(34, 386);
            this->grpReturnDetails->Margin = System::Windows::Forms::Padding(2);
            this->grpReturnDetails->Name = L"grpReturnDetails";
            this->grpReturnDetails->Padding = System::Windows::Forms::Padding(2);
            this->grpReturnDetails->Size = System::Drawing::Size(606, 168);
            this->grpReturnDetails->TabIndex = 3;
            this->grpReturnDetails->TabStop = false;
            this->grpReturnDetails->Text = L"RETURN DETAILS";
            // 
            // txtProductDisplay
            // 
            this->txtProductDisplay->BackColor = System::Drawing::Color::White;
            this->txtProductDisplay->ForeColor = System::Drawing::Color::Black;
            this->txtProductDisplay->Location = System::Drawing::Point(174, 19);
            this->txtProductDisplay->Name = L"txtProductDisplay";
            this->txtProductDisplay->ReadOnly = true;
            this->txtProductDisplay->Size = System::Drawing::Size(206, 22);
            this->txtProductDisplay->TabIndex = 9;
            // 
            // txtRefundAmount
            // 
            this->txtRefundAmount->BackColor = System::Drawing::Color::WhiteSmoke;
            this->txtRefundAmount->ForeColor = System::Drawing::Color::DarkGreen;
            this->txtRefundAmount->Location = System::Drawing::Point(458, 72);
            this->txtRefundAmount->Margin = System::Windows::Forms::Padding(2);
            this->txtRefundAmount->Name = L"txtRefundAmount";
            this->txtRefundAmount->ReadOnly = true;
            this->txtRefundAmount->Size = System::Drawing::Size(114, 22);
            this->txtRefundAmount->TabIndex = 0;
            // 
            // lblRefundAmount
            // 
            this->lblRefundAmount->Location = System::Drawing::Point(336, 74);
            this->lblRefundAmount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblRefundAmount->Name = L"lblRefundAmount";
            this->lblRefundAmount->Size = System::Drawing::Size(80, 15);
            this->lblRefundAmount->TabIndex = 1;
            this->lblRefundAmount->Text = L"Refund Amount:";
            // 
            // cboReason
            // 
            this->cboReason->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cboReason->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
                L"Damaged Product", L"Expired Product", L"Wrong Item Received",
                    L"Other"
            });
            this->cboReason->Location = System::Drawing::Point(146, 114);
            this->cboReason->Margin = System::Windows::Forms::Padding(2);
            this->cboReason->Name = L"cboReason";
            this->cboReason->Size = System::Drawing::Size(201, 24);
            this->cboReason->TabIndex = 2;
            // 
            // lblReason
            // 
            this->lblReason->Location = System::Drawing::Point(16, 99);
            this->lblReason->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblReason->Name = L"lblReason";
            this->lblReason->Size = System::Drawing::Size(80, 39);
            this->lblReason->TabIndex = 3;
            this->lblReason->Text = L"Return Reason:";
            // 
            // numQuantity
            // 
            this->numQuantity->Location = System::Drawing::Point(174, 75);
            this->numQuantity->Margin = System::Windows::Forms::Padding(2);
            this->numQuantity->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numQuantity->Name = L"numQuantity";
            this->numQuantity->Size = System::Drawing::Size(96, 22);
            this->numQuantity->TabIndex = 4;
            this->numQuantity->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // lblQuantity
            // 
            this->lblQuantity->Location = System::Drawing::Point(16, 74);
            this->lblQuantity->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblQuantity->Name = L"lblQuantity";
            this->lblQuantity->Size = System::Drawing::Size(119, 20);
            this->lblQuantity->TabIndex = 5;
            this->lblQuantity->Text = L"Quantity to Return:";
            // 
            // txtOriginalPrice
            // 
            this->txtOriginalPrice->BackColor = System::Drawing::Color::White;
            this->txtOriginalPrice->ForeColor = System::Drawing::Color::Black;
            this->txtOriginalPrice->Location = System::Drawing::Point(174, 49);
            this->txtOriginalPrice->Margin = System::Windows::Forms::Padding(2);
            this->txtOriginalPrice->Name = L"txtOriginalPrice";
            this->txtOriginalPrice->ReadOnly = true;
            this->txtOriginalPrice->Size = System::Drawing::Size(135, 22);
            this->txtOriginalPrice->TabIndex = 6;
            // 
            // lblOriginalPrice
            // 
            this->lblOriginalPrice->Location = System::Drawing::Point(16, 48);
            this->lblOriginalPrice->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblOriginalPrice->Name = L"lblOriginalPrice";
            this->lblOriginalPrice->Size = System::Drawing::Size(119, 15);
            this->lblOriginalPrice->TabIndex = 7;
            this->lblOriginalPrice->Text = L"Original Price:";
            // 
            // lblSelectedProduct
            // 
            this->lblSelectedProduct->Location = System::Drawing::Point(16, 22);
            this->lblSelectedProduct->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblSelectedProduct->Name = L"lblSelectedProduct";
            this->lblSelectedProduct->Size = System::Drawing::Size(133, 15);
            this->lblSelectedProduct->TabIndex = 8;
            this->lblSelectedProduct->Text = L"Selected Product:";
            // 
            // btnProcessReturn
            // 
            this->btnProcessReturn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)));
            this->btnProcessReturn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnProcessReturn->ForeColor = System::Drawing::Color::White;
            this->btnProcessReturn->Location = System::Drawing::Point(49, 558);
            this->btnProcessReturn->Margin = System::Windows::Forms::Padding(2);
            this->btnProcessReturn->Name = L"btnProcessReturn";
            this->btnProcessReturn->Size = System::Drawing::Size(120, 29);
            this->btnProcessReturn->TabIndex = 2;
            this->btnProcessReturn->Text = L"Process Return";
            this->btnProcessReturn->UseVisualStyleBackColor = false;
            this->btnProcessReturn->Click += gcnew System::EventHandler(this, &ReturnForm::btnProcessReturn_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCancel->ForeColor = System::Drawing::Color::White;
            this->btnCancel->Location = System::Drawing::Point(354, 558);
            this->btnCancel->Margin = System::Windows::Forms::Padding(2);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(96, 29);
            this->btnCancel->TabIndex = 1;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = false;
            this->btnCancel->Click += gcnew System::EventHandler(this, &ReturnForm::btnCancel_Click);
            // 
            // lblManagerNote
            // 
            this->lblManagerNote->AutoSize = true;
            this->lblManagerNote->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic));
            this->lblManagerNote->ForeColor = System::Drawing::Color::Red;
            this->lblManagerNote->Location = System::Drawing::Point(30, 603);
            this->lblManagerNote->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblManagerNote->Name = L"lblManagerNote";
            this->lblManagerNote->Size = System::Drawing::Size(324, 20);
            this->lblManagerNote->TabIndex = 0;
            this->lblManagerNote->Text = L"Note: Items over R100 require manager approval!";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::DarkGreen;
            this->label1->Location = System::Drawing::Point(215, 22);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(225, 35);
            this->label1->TabIndex = 8;
            this->label1->Text = L"RETURN GOODS";
            // 
            // ReturnForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Silver;
            this->ClientSize = System::Drawing::Size(665, 647);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->lblManagerNote);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnProcessReturn);
            this->Controls->Add(this->grpReturnDetails);
            this->Controls->Add(this->dgvSearchResults);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->lblSearchInstruction);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Margin = System::Windows::Forms::Padding(2);
            this->MaximizeBox = false;
            this->Name = L"ReturnForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"FreshMart POS - Process Return";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSearchResults))->EndInit();
            this->grpReturnDetails->ResumeLayout(false);
            this->grpReturnDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // --------------------------
        // Event handlers
        // --------------------------
        void btnSearch_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ searchTerm = txtSearch->Text->Trim();
            if (searchTerm == "")
            {
                MessageBox::Show("Please enter a barcode or product name.", "Input Required");
                return;
            }
            try
            {
                SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
                String^ query = "SELECT si.SaleItemID, p.Barcode, p.ProductName, si.UnitPrice AS Price, si.Quantity, p.ProductID "
                    + "FROM SaleItems si "
                    + "JOIN Products p ON si.ProductID = p.ProductID "
                    + "JOIN Sales s ON si.SaleID = s.SaleID "
                    + "WHERE p.IsActive = 1 AND (p.Barcode = @search OR p.ProductName LIKE @searchLike)";
                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@search", searchTerm);
                cmd->Parameters->AddWithValue("@searchLike", "%" + searchTerm + "%");
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
                DataTable^ results = gcnew DataTable();
                adapter->Fill(results);
                conn->Close();
                dgvSearchResults->DataSource = results;
                if (results->Rows->Count == 0)
                    MessageBox::Show("No items found for return.", "Not Found");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message);
            }
        }

        void dgvSearchResults_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
           
            if (dgvSearchResults->SelectedRows->Count > 0)
            {
                try
                {
                    DataGridViewRow^ row = dgvSearchResults->SelectedRows[0];

                    // Get SaleItemID from visible column
                    selectedSaleItemID = Convert::ToInt32(row->Cells["SaleItemID"]->Value);

                    // Get ProductName from visible column
                    selectedProductName = row->Cells["ProductName"]->Value->ToString();

                    // Get Price from visible column
                    selectedPrice = Convert::ToDouble(row->Cells["Price"]->Value);

                    // Get ProductID and Quantity from the underlying DataRow (not visible in grid)
                    DataRowView^ rowView = safe_cast<DataRowView^>(row->DataBoundItem);
                    if (rowView != nullptr)
                    {
                        DataRow^ dataRow = rowView->Row;
                        selectedProductID = Convert::ToInt32(dataRow["ProductID"]);
                        selectedPurchasedQty = Convert::ToInt32(dataRow["Quantity"]);
                    }

                    // Update UI
                    txtProductDisplay->Text = selectedProductName;
                    txtOriginalPrice->Text = "R" + selectedPrice.ToString("0.00");
                    txtRefundAmount->Text = "R" + selectedPrice.ToString("0.00");

                    numQuantity->Maximum = selectedPurchasedQty;
                    numQuantity->Minimum = 1;
                    numQuantity->Value = 1;
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error selecting item: " + ex->Message);
                }
            }
          



        }

        void numQuantity_ValueChanged(System::Object^ sender, System::EventArgs^ e)
        {

            int qty = (int)numQuantity->Value;
            double refund = selectedPrice * qty;
            txtRefundAmount->Text = "R" + refund.ToString("0.00");
        }

        void btnProcessReturn_Click(System::Object^ sender, System::EventArgs^ e)
        {
           
            if (selectedSaleItemID == 0)
            {
                MessageBox::Show("Please select an item to return.", "No Selection");
                return;
            }

            // Validate reason
            if (cboReason->SelectedIndex == -1)
            {
                MessageBox::Show("Please select a return reason.", "Missing Reason");
                return;
            }

            // Get quantity and validate
            int returnQty = (int)numQuantity->Value;
            if (returnQty <= 0 || returnQty > selectedPurchasedQty)
            {
                MessageBox::Show("Invalid quantity. Must be between 1 and " + selectedPurchasedQty, "Invalid Quantity");
                return;
            }

            // Calculate refund amount
            double refundAmount = selectedPrice * returnQty;

            // ===== MANAGER APPROVAL - ONLY HERE =====
            if (refundAmount > 100)
            {
                String^ managerPassword = Microsoft::VisualBasic::Interaction::InputBox(
                    "Return Amount: R" + refundAmount.ToString("0.00") + "\n\n"
                    + "Manager approval required for returns over R100.\n\n"
                    + "Enter Manager Password to approve:",
                    "Manager Approval Required",
                    "",
                    -1, -1);

                if (managerPassword != "admin123")
                {
                    MessageBox::Show("Invalid manager password. Return cancelled.", "Access Denied");
                    return;
                }
                else
                {
                    MessageBox::Show("Manager approved. Processing return...", "Approved",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
         
            System::Windows::Forms::DialogResult confirm = MessageBox::Show(
                "Confirm Return:\n\nProduct: " + selectedProductName + "\n" +
                "Quantity: " + returnQty + "\n" +
                "Refund: R" + refundAmount.ToString("0.00") + "\n" +
                "Reason: " + cboReason->SelectedItem->ToString() + "\n\nProceed?",
                "Confirm Return", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

            if (confirm != System::Windows::Forms::DialogResult::Yes) return;

            try
            {
                SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
                conn->Open();

                // Check for duplicate return
                String^ checkReturned = "SELECT COUNT(*) FROM Returns WHERE SaleItemID = @sid";
                SqlCommand^ checkCmd = gcnew SqlCommand(checkReturned, conn);
                checkCmd->Parameters->AddWithValue("@sid", selectedSaleItemID);
                int alreadyReturned = (int)checkCmd->ExecuteScalar();

                if (alreadyReturned > 0)
                {
                    conn->Close();
                    MessageBox::Show("This item has already been returned.", "Duplicate Return");
                    return;
                }

                // Update stock (add back the returned quantity)
                String^ updateStock = "UPDATE Products SET Quantity = Quantity + @qty WHERE ProductID = @pid";
                SqlCommand^ stockCmd = gcnew SqlCommand(updateStock, conn);
                stockCmd->Parameters->AddWithValue("@qty", returnQty);
                stockCmd->Parameters->AddWithValue("@pid", selectedProductID);
                stockCmd->ExecuteNonQuery();

                // Insert into Returns table
                String^ insertReturn = "INSERT INTO Returns (SaleItemID, ProductID, UserID, RefundAmount, Reason) "
                    + "VALUES (@sid, @pid, @uid, @amount, @reason)";
                SqlCommand^ returnCmd = gcnew SqlCommand(insertReturn, conn);
                returnCmd->Parameters->AddWithValue("@sid", selectedSaleItemID);
                returnCmd->Parameters->AddWithValue("@pid", selectedProductID);
                returnCmd->Parameters->AddWithValue("@uid", Convert::ToInt32(loggedInUser->getUserID()));
                returnCmd->Parameters->AddWithValue("@amount", refundAmount);
                returnCmd->Parameters->AddWithValue("@reason", cboReason->SelectedItem->ToString());
                returnCmd->ExecuteNonQuery();

                conn->Close();

                MessageBox::Show("Return processed successfully!\nRefund: R" + refundAmount.ToString("0.00"),
                    "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Clear the form
                txtSearch->Clear();
                txtProductDisplay->Clear();
                txtOriginalPrice->Clear();
                txtRefundAmount->Clear();
                cboReason->SelectedIndex = 0;
                dgvSearchResults->DataSource = nullptr;
                selectedSaleItemID = 0;
                selectedProductID = 0;
                selectedPurchasedQty = 0;
                numQuantity->Value = 1;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message, "Error");
            }
          


        }

        void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    };
}