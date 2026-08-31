#pragma once
#include "UserManagementForm.h"
namespace SupermarketPOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for UserManagementForm
	/// </summary>
	public ref class UserManagementForm : public System::Windows::Forms::Form
	{
	public:
		UserManagementForm(void)
		{
			InitializeComponent();
			cboRole->SelectedIndex = 0; 
			LoadUsers();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvUsers;
	private: System::Windows::Forms::GroupBox^ grpUserDetails;
	private: System::Windows::Forms::Label^ lblConfirmPassword;
	private: System::Windows::Forms::Label^ lblRole;


	private: System::Windows::Forms::Label^ lblPassword;

	private: System::Windows::Forms::Label^ lblFullName;

	private: System::Windows::Forms::Label^ lblUserName;
	private: System::Windows::Forms::ComboBox^ cboRole;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtUsername;
	private: System::Windows::Forms::TextBox^ txtConfirmPassword;
	private: System::Windows::Forms::TextBox^ txtFullName;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colUserID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colUsername;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFullName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colRole;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIsActive;
	private: System::Windows::Forms::GroupBox^ grpActions;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDisable;

	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnResetPassword;
	private: System::Windows::Forms::Button^ btnClose;

	private: System::Windows::Forms::Button^ btnRefresh;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblStatus;
	private: System::Windows::Forms::Label^ label1;
	private:
		DataTable^ usersTable;
	private:
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
			this->dgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->colUserID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colUsername = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFullName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colRole = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colIsActive = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpUserDetails = (gcnew System::Windows::Forms::GroupBox());
			this->cboRole = (gcnew System::Windows::Forms::ComboBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtFullName = (gcnew System::Windows::Forms::TextBox());
			this->lblConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->lblRole = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblFullName = (gcnew System::Windows::Forms::Label());
			this->lblUserName = (gcnew System::Windows::Forms::Label());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->grpActions = (gcnew System::Windows::Forms::GroupBox());
			this->btnResetPassword = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->btnDisable = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->lblStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->BeginInit();
			this->grpUserDetails->SuspendLayout();
			this->grpActions->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvUsers
			// 
			this->dgvUsers->AllowUserToAddRows = false;
			this->dgvUsers->AllowUserToDeleteRows = false;
			this->dgvUsers->BackgroundColor = System::Drawing::Color::Silver;
			this->dgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colUserID, this->colUsername,
					this->colFullName, this->colRole, this->colIsActive
			});
			this->dgvUsers->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->dgvUsers->Location = System::Drawing::Point(26, 88);
			this->dgvUsers->MultiSelect = false;
			this->dgvUsers->Name = L"dgvUsers";
			this->dgvUsers->ReadOnly = true;
			this->dgvUsers->RowHeadersVisible = false;
			this->dgvUsers->RowHeadersWidth = 51;
			this->dgvUsers->RowTemplate->Height = 24;
			this->dgvUsers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvUsers->Size = System::Drawing::Size(918, 199);
			this->dgvUsers->TabIndex = 0;
			this->dgvUsers->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UserManagementForm::dgvUsers_CellContentClick);
			this->dgvUsers->SelectionChanged += gcnew System::EventHandler(this, &UserManagementForm::dgvUsers_SelectionChanged);
			// 
			// colUserID
			// 
			this->colUserID->DataPropertyName = L"UserID";
			this->colUserID->HeaderText = L"ID";
			this->colUserID->MinimumWidth = 6;
			this->colUserID->Name = L"colUserID";
			this->colUserID->ReadOnly = true;
			this->colUserID->Width = 125;
			// 
			// colUsername
			// 
			this->colUsername->DataPropertyName = L"Username";
			this->colUsername->HeaderText = L"Username";
			this->colUsername->MinimumWidth = 6;
			this->colUsername->Name = L"colUsername";
			this->colUsername->ReadOnly = true;
			this->colUsername->Width = 125;
			// 
			// colFullName
			// 
			this->colFullName->DataPropertyName = L"FullName";
			this->colFullName->HeaderText = L"Full Name";
			this->colFullName->MinimumWidth = 6;
			this->colFullName->Name = L"colFullName";
			this->colFullName->ReadOnly = true;
			this->colFullName->Width = 125;
			// 
			// colRole
			// 
			this->colRole->DataPropertyName = L"Role";
			this->colRole->HeaderText = L"Role";
			this->colRole->MinimumWidth = 6;
			this->colRole->Name = L"colRole";
			this->colRole->ReadOnly = true;
			this->colRole->Width = 125;
			// 
			// colIsActive
			// 
			this->colIsActive->DataPropertyName = L"IsActive";
			this->colIsActive->HeaderText = L"Active";
			this->colIsActive->MinimumWidth = 6;
			this->colIsActive->Name = L"colIsActive";
			this->colIsActive->ReadOnly = true;
			this->colIsActive->Width = 125;
			// 
			// grpUserDetails
			// 
			this->grpUserDetails->BackColor = System::Drawing::Color::White;
			this->grpUserDetails->Controls->Add(this->cboRole);
			this->grpUserDetails->Controls->Add(this->txtPassword);
			this->grpUserDetails->Controls->Add(this->txtUsername);
			this->grpUserDetails->Controls->Add(this->txtConfirmPassword);
			this->grpUserDetails->Controls->Add(this->txtFullName);
			this->grpUserDetails->Controls->Add(this->lblConfirmPassword);
			this->grpUserDetails->Controls->Add(this->lblRole);
			this->grpUserDetails->Controls->Add(this->lblPassword);
			this->grpUserDetails->Controls->Add(this->lblFullName);
			this->grpUserDetails->Controls->Add(this->lblUserName);
			this->grpUserDetails->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->grpUserDetails->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpUserDetails->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->grpUserDetails->Location = System::Drawing::Point(26, 293);
			this->grpUserDetails->Name = L"grpUserDetails";
			this->grpUserDetails->Size = System::Drawing::Size(484, 289);
			this->grpUserDetails->TabIndex = 1;
			this->grpUserDetails->TabStop = false;
			this->grpUserDetails->Text = L"USER DETAILS";
			// 
			// cboRole
			// 
			this->cboRole->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRole->FormattingEnabled = true;
			this->cboRole->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Cashier", L"Admin" });
			this->cboRole->Location = System::Drawing::Point(105, 193);
			this->cboRole->Name = L"cboRole";
			this->cboRole->Size = System::Drawing::Size(250, 31);
			this->cboRole->TabIndex = 10;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(122, 110);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(313, 30);
			this->txtPassword->TabIndex = 9;
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(120, 35);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(315, 30);
			this->txtUsername->TabIndex = 8;
			// 
			// txtConfirmPassword
			// 
			this->txtConfirmPassword->Location = System::Drawing::Point(187, 150);
			this->txtConfirmPassword->Name = L"txtConfirmPassword";
			this->txtConfirmPassword->Size = System::Drawing::Size(248, 30);
			this->txtConfirmPassword->TabIndex = 7;
			// 
			// txtFullName
			// 
			this->txtFullName->Location = System::Drawing::Point(122, 72);
			this->txtFullName->Name = L"txtFullName";
			this->txtFullName->Size = System::Drawing::Size(313, 30);
			this->txtFullName->TabIndex = 6;
			// 
			// lblConfirmPassword
			// 
			this->lblConfirmPassword->AutoSize = true;
			this->lblConfirmPassword->Location = System::Drawing::Point(20, 150);
			this->lblConfirmPassword->Name = L"lblConfirmPassword";
			this->lblConfirmPassword->Size = System::Drawing::Size(161, 23);
			this->lblConfirmPassword->TabIndex = 4;
			this->lblConfirmPassword->Text = L"Confirm Password:";
			// 
			// lblRole
			// 
			this->lblRole->AutoSize = true;
			this->lblRole->Location = System::Drawing::Point(29, 193);
			this->lblRole->Name = L"lblRole";
			this->lblRole->Size = System::Drawing::Size(50, 23);
			this->lblRole->TabIndex = 3;
			this->lblRole->Text = L"Role:";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(20, 113);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(90, 23);
			this->lblPassword->TabIndex = 2;
			this->lblPassword->Text = L"Password:";
			// 
			// lblFullName
			// 
			this->lblFullName->AutoSize = true;
			this->lblFullName->Location = System::Drawing::Point(20, 75);
			this->lblFullName->Name = L"lblFullName";
			this->lblFullName->Size = System::Drawing::Size(96, 23);
			this->lblFullName->TabIndex = 1;
			this->lblFullName->Text = L"Full Name:";
			// 
			// lblUserName
			// 
			this->lblUserName->AutoSize = true;
			this->lblUserName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->lblUserName->Location = System::Drawing::Point(20, 35);
			this->lblUserName->Name = L"lblUserName";
			this->lblUserName->Size = System::Drawing::Size(94, 23);
			this->lblUserName->TabIndex = 0;
			this->lblUserName->Text = L"Username:";
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::RoyalBlue;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(109, 220);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(180, 45);
			this->btnUpdate->TabIndex = 11;
			this->btnUpdate->Text = L"UPDATE USER";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &UserManagementForm::btnUpdate_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(131, 605);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 2;
			// 
			// grpActions
			// 
			this->grpActions->BackColor = System::Drawing::Color::White;
			this->grpActions->Controls->Add(this->btnUpdate);
			this->grpActions->Controls->Add(this->btnResetPassword);
			this->grpActions->Controls->Add(this->btnClose);
			this->grpActions->Controls->Add(this->btnRefresh);
			this->grpActions->Controls->Add(this->btnDisable);
			this->grpActions->Controls->Add(this->btnAdd);
			this->grpActions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpActions->ForeColor = System::Drawing::Color::DarkGreen;
			this->grpActions->Location = System::Drawing::Point(516, 293);
			this->grpActions->Name = L"grpActions";
			this->grpActions->Size = System::Drawing::Size(428, 289);
			this->grpActions->TabIndex = 3;
			this->grpActions->TabStop = false;
			this->grpActions->Text = L"ACTIONS";
			// 
			// btnResetPassword
			// 
			this->btnResetPassword->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnResetPassword->Location = System::Drawing::Point(224, 158);
			this->btnResetPassword->Name = L"btnResetPassword";
			this->btnResetPassword->Size = System::Drawing::Size(168, 47);
			this->btnResetPassword->TabIndex = 12;
			this->btnResetPassword->Text = L"RESET PASSWORD";
			this->btnResetPassword->UseVisualStyleBackColor = true;
			this->btnResetPassword->Click += gcnew System::EventHandler(this, &UserManagementForm::btnResetPassword_Click);
			// 
			// btnClose
			// 
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(224, 107);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(168, 45);
			this->btnClose->TabIndex = 3;
			this->btnClose->Text = L"CLOSE";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &UserManagementForm::btnClose_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->Location = System::Drawing::Point(39, 107);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(168, 45);
			this->btnRefresh->TabIndex = 2;
			this->btnRefresh->Text = L"REFRESH LIST";
			this->btnRefresh->UseVisualStyleBackColor = true;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &UserManagementForm::btnRefresh_Click);
			// 
			// btnDisable
			// 
			this->btnDisable->Location = System::Drawing::Point(39, 158);
			this->btnDisable->Name = L"btnDisable";
			this->btnDisable->Size = System::Drawing::Size(168, 47);
			this->btnDisable->TabIndex = 1;
			this->btnDisable->Text = L"DISABLE USER";
			this->btnDisable->UseVisualStyleBackColor = true;
			this->btnDisable->Click += gcnew System::EventHandler(this, &UserManagementForm::btnDisable_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::DarkGreen;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->ForeColor = System::Drawing::Color::White;
			this->btnAdd->Location = System::Drawing::Point(39, 46);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(353, 45);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"ADD USER";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &UserManagementForm::btnAdd_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->lblStatus });
			this->statusStrip1->Location = System::Drawing::Point(0, 585);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(975, 26);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"Ready";
			// 
			// lblStatus
			// 
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(53, 20);
			this->lblStatus->Text = L"Ready:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkGreen;
			this->label1->Location = System::Drawing::Point(287, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 43);
			this->label1->TabIndex = 5;
			this->label1->Text = L"USER MANAGEMENT";
			// 
			// UserManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(975, 611);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->grpActions);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->grpUserDetails);
			this->Controls->Add(this->dgvUsers);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"UserManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreshMart POS - User Management";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->EndInit();
			this->grpUserDetails->ResumeLayout(false);
			this->grpUserDetails->PerformLayout();
			this->grpActions->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		void LoadUsers()
		{
			try
			{
				SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
				String^ query = "SELECT UserID, Username, FullName, Role, IsActive FROM Users ORDER BY UserID";
				SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
				usersTable = gcnew DataTable();
				adapter->Fill(usersTable);
				conn->Close();
				dgvUsers->DataSource = usersTable;

				// Format the IsActive column to show "Yes/No"
				if (dgvUsers->Columns->Contains("IsActive"))
				{
					dgvUsers->Columns["IsActive"]->DefaultCellStyle->Format = "Yes;No";
				}

				lblStatus->Text = "Ready: " + usersTable->Rows->Count + " users loaded";
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error loading users: " + ex->Message);
			}
		}

		void ClearFields()
		{
			txtUsername->Clear();
			txtFullName->Clear();
			txtPassword->Clear();
			txtConfirmPassword->Clear();
			cboRole->SelectedIndex = 0;
		}

		bool ValidateFields()
		{
			if (txtUsername->Text->Trim() == "")
			{
				MessageBox::Show("Please enter username", "Validation Error");
				txtUsername->Focus();
				return false;
			}
			if (txtFullName->Text->Trim() == "")
			{
				MessageBox::Show("Please enter full name", "Validation Error");
				txtFullName->Focus();
				return false;
			}
			if (txtPassword->Text != txtConfirmPassword->Text)
			{
				MessageBox::Show("Passwords do not match", "Validation Error");
				txtPassword->Clear();
				txtConfirmPassword->Clear();
				txtPassword->Focus();
				return false;
			}
			return true;
		}
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!ValidateFields()) return;

	try
	{
		SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
		conn->Open();

		// Check if username exists
		String^ checkQuery = "SELECT COUNT(*) FROM Users WHERE Username = @username";
		SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
		checkCmd->Parameters->AddWithValue("@username", txtUsername->Text->Trim());
		int exists = (int)checkCmd->ExecuteScalar();

		if (exists > 0)
		{
			MessageBox::Show("Username already exists!", "Duplicate");
			conn->Close();
			return;
		}

		// Insert new user (DO NOT insert UserID - it's auto-generated)
		String^ query = "INSERT INTO Users (Username, PasswordHash, FullName, Role, IsActive) "
			+ "VALUES (@username, @password, @fullname, @role, 1)";

		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@username", txtUsername->Text->Trim());
		cmd->Parameters->AddWithValue("@password", txtPassword->Text); 
		cmd->Parameters->AddWithValue("@fullname", txtFullName->Text->Trim());
		cmd->Parameters->AddWithValue("@role", cboRole->SelectedItem->ToString());
		cmd->ExecuteNonQuery();

		conn->Close();

		MessageBox::Show("User added successfully!", "Success");
		ClearFields();
		LoadUsers();  // Refresh the grid
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message);
	}
	


}
private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{


	if (dgvUsers->SelectedRows->Count == 0)
	{
		MessageBox::Show("Please select a user to update", "No Selection");
		return;
	}

	// FIXED: Use column index
	int userID = Convert::ToInt32(dgvUsers->SelectedRows[0]->Cells[0]->Value);
	String^ currentUsername = dgvUsers->SelectedRows[0]->Cells[1]->Value->ToString();

	try
	{
		SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

		// Check if username exists (excluding current)
		String^ checkQuery = "SELECT COUNT(*) FROM Users WHERE Username = @username AND UserID != @id";
		SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
		checkCmd->Parameters->AddWithValue("@username", txtUsername->Text->Trim());
		checkCmd->Parameters->AddWithValue("@id", userID);
		conn->Open();
		int exists = (int)checkCmd->ExecuteScalar();

		if (exists > 0)
		{
			MessageBox::Show("Username already exists!", "Duplicate");
			conn->Close();
			return;
		}

		// Update user
		String^ query = "UPDATE Users SET Username=@username, FullName=@fullname, Role=@role WHERE UserID=@id";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@id", userID);
		cmd->Parameters->AddWithValue("@username", txtUsername->Text->Trim());
		cmd->Parameters->AddWithValue("@fullname", txtFullName->Text->Trim());
		cmd->Parameters->AddWithValue("@role", cboRole->SelectedItem->ToString());
		cmd->ExecuteNonQuery();
		conn->Close();

		MessageBox::Show("User updated successfully!", "Success");
		ClearFields();
		LoadUsers();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message);
	}




}
private: System::Void btnResetPassword_Click(System::Object^ sender, System::EventArgs^ e)
{


	if (dgvUsers->SelectedRows->Count == 0)
	{
		MessageBox::Show("Please select a user", "No Selection");
		return;
	}

	String^ newPassword = Microsoft::VisualBasic::Interaction::InputBox(
		"Enter new password for user:",
		"Reset Password",
		"",
		-1, -1);

	if (newPassword == "") return;

	// FIXED: Use column index
	int userID = Convert::ToInt32(dgvUsers->SelectedRows[0]->Cells[0]->Value);

	try
	{
		SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
		String^ query = "UPDATE Users SET PasswordHash = @password WHERE UserID = @id";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@id", userID);
		cmd->Parameters->AddWithValue("@password", newPassword);
		conn->Open();
		cmd->ExecuteNonQuery();
		conn->Close();

		MessageBox::Show("Password reset successfully!", "Success");
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message);
	}




}
private: System::Void btnDisable_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dgvUsers->SelectedRows->Count == 0)
	{
		MessageBox::Show("Please select a user", "No Selection");
		return;
	}


	int userID = Convert::ToInt32(dgvUsers->SelectedRows[0]->Cells[0]->Value);
	String^ username = dgvUsers->SelectedRows[0]->Cells[1]->Value->ToString();

	System::Windows::Forms::DialogResult result = MessageBox::Show("Disable user '" + username + "'?\n\nThey will no longer be able to login.",
		"Confirm Disable", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		try
		{
			SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
			String^ query = "UPDATE Users SET IsActive = 0 WHERE UserID = @id";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@id", userID);
			conn->Open();
			cmd->ExecuteNonQuery();
			conn->Close();

			MessageBox::Show("User disabled successfully!", "Success");
			ClearFields();
			LoadUsers();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message);
		}
	}

}
private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
{


	LoadUsers();
	ClearFields();





}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
{

	this->Close();



}
private: System::Void dgvUsers_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (dgvUsers->SelectedRows->Count > 0)
	{
		DataGridViewRow^ row = dgvUsers->SelectedRows[0];

		// Fix: Use the actual column names from your DataGridView
		txtUsername->Text = row->Cells["colUsername"]->Value->ToString();
		txtFullName->Text = row->Cells["colFullName"]->Value->ToString();

		String^ role = row->Cells["colRole"]->Value->ToString();

		if (role == "Admin")
			cboRole->SelectedIndex = 1;
		else
			cboRole->SelectedIndex = 0;

		txtPassword->Clear();
		txtConfirmPassword->Clear();
	}
	
}
private: System::Void dgvUsers_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
