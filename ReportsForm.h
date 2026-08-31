#pragma once
#include "Sale.h"
#include "User.h"
#using <System.dll>
#include<List>
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

	/// <summary>
	/// Summary for ReportsForm
	/// </summary>
	public ref class ReportsForm : public System::Windows::Forms::Form
	{
	public:
		ReportsForm(User^ user)
		{
			


			loggedInUser = user;
			InitializeComponent();

			
			dtpTo->Value = DateTime::Now;
			dtpFrom->Value = DateTime::Now.AddDays(-7);

			
			LoadReport();






		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReportsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dtpFrom;
	protected:
	private: System::Windows::Forms::DateTimePicker^ dtpTo;
	private: System::Windows::Forms::Button^ btnGenerate;
	private: System::Windows::Forms::GroupBox^ grpSummary;
	private: System::Windows::Forms::Label^ lblTotalSalesTitle;
	private: System::Windows::Forms::Label^ lblTotalSales;
	private: System::Windows::Forms::Label^ lblTotalVATTitle;
	private: System::Windows::Forms::Label^ lblTotalVAT;
	private: System::Windows::Forms::Label^ lblTransactionCountTitle;
	private: System::Windows::Forms::Label^ lblTransactionCount;
	private: System::Windows::Forms::DataGridView^ dgvSales;
	private: System::Windows::Forms::Button^ btnExport;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SaleDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CashierName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TotalAmount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PaymentMethod;
	private:
		User^ loggedInUser;
	private: System::Windows::Forms::Label^ lblFrom;
	private: System::Windows::Forms::Label^ lblTo;
	private: System::Windows::Forms::Label^ label1;

		   DataTable^ salesTable;

	private:
		String^ GetConnectionString()
		{
			return "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=SupermarketPOS;Integrated Security=True";
		}


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
			this->dtpFrom = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpTo = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->grpSummary = (gcnew System::Windows::Forms::GroupBox());
			this->lblTotalSalesTitle = (gcnew System::Windows::Forms::Label());
			this->lblTotalSales = (gcnew System::Windows::Forms::Label());
			this->lblTotalVATTitle = (gcnew System::Windows::Forms::Label());
			this->lblTotalVAT = (gcnew System::Windows::Forms::Label());
			this->lblTransactionCountTitle = (gcnew System::Windows::Forms::Label());
			this->lblTransactionCount = (gcnew System::Windows::Forms::Label());
			this->dgvSales = (gcnew System::Windows::Forms::DataGridView());
			this->SaleDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashierName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TotalAmount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PaymentMethod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnExport = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblFrom = (gcnew System::Windows::Forms::Label());
			this->lblTo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSales))->BeginInit();
			this->SuspendLayout();
			// 
			// dtpFrom
			// 
			this->dtpFrom->Location = System::Drawing::Point(100, 61);
			this->dtpFrom->Name = L"dtpFrom";
			this->dtpFrom->Size = System::Drawing::Size(200, 22);
			this->dtpFrom->TabIndex = 0;
			// 
			// dtpTo
			// 
			this->dtpTo->Location = System::Drawing::Point(350, 60);
			this->dtpTo->Name = L"dtpTo";
			this->dtpTo->Size = System::Drawing::Size(200, 22);
			this->dtpTo->TabIndex = 1;
			// 
			// btnGenerate
			// 
			this->btnGenerate->BackColor = System::Drawing::Color::DarkGreen;
			this->btnGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGenerate->ForeColor = System::Drawing::Color::White;
			this->btnGenerate->Location = System::Drawing::Point(600, 56);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(150, 35);
			this->btnGenerate->TabIndex = 2;
			this->btnGenerate->Text = L"Generate";
			this->btnGenerate->UseVisualStyleBackColor = false;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &ReportsForm::btnGenerate_Click);
			// 
			// grpSummary
			// 
			this->grpSummary->Location = System::Drawing::Point(20, 100);
			this->grpSummary->Name = L"grpSummary";
			this->grpSummary->Size = System::Drawing::Size(919, 100);
			this->grpSummary->TabIndex = 3;
			this->grpSummary->TabStop = false;
			this->grpSummary->Text = L"groupBox1";
			// 
			// lblTotalSalesTitle
			// 
			this->lblTotalSalesTitle->AutoSize = true;
			this->lblTotalSalesTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalSalesTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTotalSalesTitle->Location = System::Drawing::Point(50, 130);
			this->lblTotalSalesTitle->Name = L"lblTotalSalesTitle";
			this->lblTotalSalesTitle->Size = System::Drawing::Size(118, 28);
			this->lblTotalSalesTitle->TabIndex = 4;
			this->lblTotalSalesTitle->Text = L"Total Sales:";
			// 
			// lblTotalSales
			// 
			this->lblTotalSales->AutoSize = true;
			this->lblTotalSales->BackColor = System::Drawing::Color::White;
			this->lblTotalSales->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalSales->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTotalSales->Location = System::Drawing::Point(50, 155);
			this->lblTotalSales->Name = L"lblTotalSales";
			this->lblTotalSales->Size = System::Drawing::Size(91, 38);
			this->lblTotalSales->TabIndex = 5;
			this->lblTotalSales->Text = L"R0.00";
			// 
			// lblTotalVATTitle
			// 
			this->lblTotalVATTitle->AutoSize = true;
			this->lblTotalVATTitle->BackColor = System::Drawing::Color::White;
			this->lblTotalVATTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalVATTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTotalVATTitle->Location = System::Drawing::Point(400, 130);
			this->lblTotalVATTitle->Name = L"lblTotalVATTitle";
			this->lblTotalVATTitle->Size = System::Drawing::Size(201, 28);
			this->lblTotalVATTitle->TabIndex = 6;
			this->lblTotalVATTitle->Text = L"Total VAT Collected:";
			// 
			// lblTotalVAT
			// 
			this->lblTotalVAT->AutoSize = true;
			this->lblTotalVAT->BackColor = System::Drawing::Color::White;
			this->lblTotalVAT->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalVAT->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTotalVAT->Location = System::Drawing::Point(400, 155);
			this->lblTotalVAT->Name = L"lblTotalVAT";
			this->lblTotalVAT->Size = System::Drawing::Size(66, 28);
			this->lblTotalVAT->TabIndex = 7;
			this->lblTotalVAT->Text = L"R0.00";
			// 
			// lblTransactionCountTitle
			// 
			this->lblTransactionCountTitle->AutoSize = true;
			this->lblTransactionCountTitle->BackColor = System::Drawing::Color::White;
			this->lblTransactionCountTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTransactionCountTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTransactionCountTitle->Location = System::Drawing::Point(750, 130);
			this->lblTransactionCountTitle->Name = L"lblTransactionCountTitle";
			this->lblTransactionCountTitle->Size = System::Drawing::Size(135, 28);
			this->lblTransactionCountTitle->TabIndex = 8;
			this->lblTransactionCountTitle->Text = L"Transactions:";
			// 
			// lblTransactionCount
			// 
			this->lblTransactionCount->AutoSize = true;
			this->lblTransactionCount->BackColor = System::Drawing::Color::White;
			this->lblTransactionCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTransactionCount->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTransactionCount->Location = System::Drawing::Point(750, 155);
			this->lblTransactionCount->Name = L"lblTransactionCount";
			this->lblTransactionCount->Size = System::Drawing::Size(33, 38);
			this->lblTransactionCount->TabIndex = 9;
			this->lblTransactionCount->Text = L"0";
			// 
			// dgvSales
			// 
			this->dgvSales->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dgvSales->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dgvSales->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSales->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->SaleDate, this->InvoiceNumber,
					this->CashierName, this->TotalAmount, this->PaymentMethod
			});
			this->dgvSales->Location = System::Drawing::Point(20, 220);
			this->dgvSales->Name = L"dgvSales";
			this->dgvSales->RowHeadersWidth = 51;
			this->dgvSales->RowTemplate->Height = 24;
			this->dgvSales->Size = System::Drawing::Size(919, 350);
			this->dgvSales->TabIndex = 10;
			// 
			// SaleDate
			// 
			this->SaleDate->DataPropertyName = L"SaleDate";
			this->SaleDate->HeaderText = L"Date";
			this->SaleDate->MinimumWidth = 6;
			this->SaleDate->Name = L"SaleDate";
			this->SaleDate->ReadOnly = true;
			this->SaleDate->Width = 65;
			// 
			// InvoiceNumber
			// 
			this->InvoiceNumber->DataPropertyName = L"InvoiceNumber";
			this->InvoiceNumber->HeaderText = L"Invoice#";
			this->InvoiceNumber->MinimumWidth = 6;
			this->InvoiceNumber->Name = L"InvoiceNumber";
			this->InvoiceNumber->ReadOnly = true;
			this->InvoiceNumber->Width = 86;
			// 
			// CashierName
			// 
			this->CashierName->DataPropertyName = L"CashierName";
			this->CashierName->HeaderText = L"Cashier";
			this->CashierName->MinimumWidth = 6;
			this->CashierName->Name = L"CashierName";
			this->CashierName->ReadOnly = true;
			this->CashierName->Width = 82;
			// 
			// TotalAmount
			// 
			this->TotalAmount->DataPropertyName = L"TotalAmount";
			this->TotalAmount->HeaderText = L"Amount (R)";
			this->TotalAmount->MinimumWidth = 6;
			this->TotalAmount->Name = L"TotalAmount";
			this->TotalAmount->ReadOnly = true;
			this->TotalAmount->Width = 102;
			// 
			// PaymentMethod
			// 
			this->PaymentMethod->DataPropertyName = L"PaymentMethod";
			this->PaymentMethod->HeaderText = L"Payment";
			this->PaymentMethod->MinimumWidth = 6;
			this->PaymentMethod->Name = L"PaymentMethod";
			this->PaymentMethod->ReadOnly = true;
			this->PaymentMethod->Width = 89;
			// 
			// btnExport
			// 
			this->btnExport->BackColor = System::Drawing::Color::DarkGreen;
			this->btnExport->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExport->ForeColor = System::Drawing::Color::White;
			this->btnExport->Location = System::Drawing::Point(686, 590);
			this->btnExport->Name = L"btnExport";
			this->btnExport->Size = System::Drawing::Size(120, 40);
			this->btnExport->TabIndex = 11;
			this->btnExport->Text = L"Export";
			this->btnExport->UseVisualStyleBackColor = false;
			this->btnExport->Click += gcnew System::EventHandler(this, &ReportsForm::btnExport_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(834, 590);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 40);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ReportsForm::button1_Click);
			// 
			// lblFrom
			// 
			this->lblFrom->AutoSize = true;
			this->lblFrom->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFrom->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblFrom->Location = System::Drawing::Point(40, 60);
			this->lblFrom->Name = L"lblFrom";
			this->lblFrom->Size = System::Drawing::Size(54, 23);
			this->lblFrom->TabIndex = 13;
			this->lblFrom->Text = L"From:";
			// 
			// lblTo
			// 
			this->lblTo->AutoSize = true;
			this->lblTo->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTo->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTo->Location = System::Drawing::Point(308, 60);
			this->lblTo->Name = L"lblTo";
			this->lblTo->Size = System::Drawing::Size(36, 23);
			this->lblTo->TabIndex = 14;
			this->lblTo->Text = L"To :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkGreen;
			this->label1->Location = System::Drawing::Point(344, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(152, 37);
			this->label1->TabIndex = 15;
			this->label1->Text = L"REPORTS";
			// 
			// ReportsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblTo);
			this->Controls->Add(this->lblFrom);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnExport);
			this->Controls->Add(this->dgvSales);
			this->Controls->Add(this->lblTransactionCount);
			this->Controls->Add(this->lblTransactionCountTitle);
			this->Controls->Add(this->lblTotalVAT);
			this->Controls->Add(this->lblTotalVATTitle);
			this->Controls->Add(this->lblTotalSales);
			this->Controls->Add(this->lblTotalSalesTitle);
			this->Controls->Add(this->grpSummary);
			this->Controls->Add(this->btnGenerate);
			this->Controls->Add(this->dtpTo);
			this->Controls->Add(this->dtpFrom);
			this->Name = L"ReportsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreshMart POS - Sales Reports";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSales))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




	private:	void UpdateSummary()
		{
			double totalSales = 0;
			double totalVAT = 0;
			int transactionCount = salesTable->Rows->Count;

			for each (DataRow ^ row in salesTable->Rows)
			{
				double amount = Convert::ToDouble(row["TotalAmount"]);
				totalSales += amount;
				totalVAT += amount * 0.15;  
			}

			lblTotalSales->Text = "R" + totalSales.ToString("0.00");
			lblTotalVAT->Text = "R" + totalVAT.ToString("0.00");
			lblTransactionCount->Text = transactionCount.ToString();
		}

	private:	void LoadReport()
		{
		
		try
		{
			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			String^ query = "SELECT s.SaleID, s.SaleDate, s.InvoiceNumber, u.Username AS CashierName, "
				+ "s.TotalAmount, s.VATAmount, s.PaymentMethod "
				+ "FROM Sales s "
				+ "JOIN Users u ON s.UserID = u.UserID "
				+ "WHERE CAST(s.SaleDate AS DATE) >= CAST(@fromDate AS DATE) AND CAST(s.SaleDate AS DATE) <= CAST(@toDate AS DATE) "
				+ "ORDER BY s.SaleDate DESC";

			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@fromDate", dtpFrom->Value);
			cmd->Parameters->AddWithValue("@toDate", dtpTo->Value);

			SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
			DataTable^ salesData = gcnew DataTable();
			adapter->Fill(salesData);
			conn->Close();

			dgvSales->DataSource = salesData;

			double totalSales = 0;
			double totalVAT = 0;

			for each (DataRow ^ row in salesData->Rows)
			{
				totalSales += Convert::ToDouble(row["TotalAmount"]);
				totalVAT += Convert::ToDouble(row["VATAmount"]);
			}

			lblTotalSales->Text = "R" + totalSales.ToString("0.00");
			lblTotalVAT->Text = "R" + totalVAT.ToString("0.00");
			lblTransactionCount->Text = salesData->Rows->Count.ToString();

			dgvSales->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
			dgvSales->DefaultCellStyle->WrapMode = DataGridViewTriState::False;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error loading report: " + ex->Message);
		}





		}

	private:
		
		void UpdateSummaryWithSales(List<Sale^>^ salesList)
		   {
			   double totalSales = 0;
			   double totalVAT = 0;
			   int transactionCount = salesList->Count;

			   for each (Sale ^ sale in salesList)
			   {
				   totalSales += sale->getTotalAmount();
				   totalVAT += sale->getVatAmount();
			   }

			   lblTotalSales->Text = "R" + totalSales.ToString("0.00");
			   lblTotalVAT->Text = "R" + totalVAT.ToString("0.00");
			   lblTransactionCount->Text = transactionCount.ToString();
		   }






	private: System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		if (dtpFrom->Value > dtpTo->Value)
		{
			MessageBox::Show("'From' date cannot be later than 'Tostep ' date.\nPlease select a valid date range.",
				"Invalid Date Range", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Validation 2: Check if date range is reasonable (max 1 year)
		TimeSpan dateRange = dtpTo->Value - dtpFrom->Value;
		if (dateRange.Days > 365)
		{
			MessageBox::Show("Date range cannot exceed 365 days.\nPlease select a smaller range.",
				"Date Range Too Large", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Validation 3: Check if From date is not in the future
		if (dtpFrom->Value > DateTime::Now)
		{
			MessageBox::Show("'From' date cannot be in the future.\nPlease select a valid date.",
				"Invalid Date", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// If all validations pass, load the report
		LoadReport();
     








	}
private: System::Void btnExport_Click(System::Object^ sender, System::EventArgs^ e)
{

	try
	{
		SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
		saveDialog->Filter = "CSV File|*.csv";
		saveDialog->Title = "Export Sales Report";
		saveDialog->FileName = "SalesReport_" + DateTime::Now.ToString("yyyyMMdd_HHmmss");

		if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamWriter^ sw = gcnew StreamWriter(saveDialog->FileName);

			// Write headers
			sw->WriteLine("Sale ID,Date,Invoice Number,Cashier,Amount (R),VAT (R),Payment Method");

			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			String^ query = "SELECT s.SaleID, s.SaleDate, s.InvoiceNumber, u.Username AS CashierName, "
				+ "s.TotalAmount, s.VATAmount, s.PaymentMethod "
				+ "FROM Sales s "
				+ "JOIN Users u ON s.UserID = u.UserID "
				+ "WHERE CAST(s.SaleDate AS DATE) >= CAST(@fromDate AS DATE) AND CAST(s.SaleDate AS DATE) <= CAST(@toDate AS DATE) "
				+ "ORDER BY s.SaleDate DESC";

			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@fromDate", dtpFrom->Value);
			cmd->Parameters->AddWithValue("@toDate", dtpTo->Value);

			conn->Open();
			SqlDataReader^ reader = cmd->ExecuteReader();

			int rowCount = 0;

			while (reader->Read())
			{
				String^ saleID = reader["SaleID"]->ToString();
				String^ saleDate = Convert::ToDateTime(reader["SaleDate"]).ToString("yyyy-MM-dd HH:mm:ss");
				String^ invoiceNumber = reader["InvoiceNumber"]->ToString();
				String^ cashierName = reader["CashierName"]->ToString();
				String^ totalAmount = Convert::ToDouble(reader["TotalAmount"]).ToString("0.00");
				String^ vatAmount = Convert::ToDouble(reader["VATAmount"]).ToString("0.00");
				String^ paymentMethod = reader["PaymentMethod"]->ToString();

				sw->WriteLine(saleID + "," + saleDate + "," + invoiceNumber + "," +
					cashierName + "," + totalAmount + "," + vatAmount + "," + paymentMethod);

				rowCount++;
			}

			conn->Close();
			sw->Close();

			MessageBox::Show("Report exported successfully!\n\n" + rowCount + " transactions exported to:\n" + saveDialog->FileName,
				"Export Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error exporting: " + ex->Message, "Export Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}


}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{

	this->Close();

}
};
}
