//Application development in popular integrated development environments � 2023 by Myrsini Stasinou is licensed under CC-BY-4.0 
#pragma once

namespace DataFormProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::IO;


	/// <summary>
	/// Summary for ContactListForm
	/// </summary>
	public ref class ContactListForm : public System::Windows::Forms::Form
	{
	public:

		System::Windows::Forms::Form^ form1;

	public:
		System::Windows::Forms::Form^ form3;

		String^ connectionString = L"datasource=localhost; port=3306; uid=root; database=contacts_form; SslMode=none;";

	public:

	public:


	
	public:
		
		MySqlConnection^ connectionDB = gcnew MySqlConnection(connectionString);

		ContactListForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ContactListForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ contactsDataGridView;
	private: System::Windows::Forms::Button^ addContactButton;
	private: System::Windows::Forms::Button^ exportDataButton;
	private: System::Windows::Forms::Button^ exitButton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->contactsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->addContactButton = (gcnew System::Windows::Forms::Button());
			this->exportDataButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contactsDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// contactsDataGridView
			// 
			this->contactsDataGridView->AllowUserToAddRows = false;
			this->contactsDataGridView->AllowUserToDeleteRows = false;
			this->contactsDataGridView->AllowUserToOrderColumns = true;
			this->contactsDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->contactsDataGridView->Location = System::Drawing::Point(12, 45);
			this->contactsDataGridView->Name = L"contactsDataGridView";
			this->contactsDataGridView->ReadOnly = true;
			this->contactsDataGridView->Size = System::Drawing::Size(606, 397);
			this->contactsDataGridView->TabIndex = 0;
			// 
			// addContactButton
			// 
			this->addContactButton->Location = System::Drawing::Point(13, 13);
			this->addContactButton->Name = L"addContactButton";
			this->addContactButton->Size = System::Drawing::Size(113, 23);
			this->addContactButton->TabIndex = 1;
			this->addContactButton->Text = L"Add New Contact";
			this->addContactButton->UseVisualStyleBackColor = true;
			this->addContactButton->Click += gcnew System::EventHandler(this, &ContactListForm::addContactButton_Click);
			// 
			// exportDataButton
			// 
			this->exportDataButton->Location = System::Drawing::Point(534, 13);
			this->exportDataButton->Name = L"exportDataButton";
			this->exportDataButton->Size = System::Drawing::Size(84, 23);
			this->exportDataButton->TabIndex = 2;
			this->exportDataButton->Text = L"Export Data";
			this->exportDataButton->UseVisualStyleBackColor = true;
			this->exportDataButton->Click += gcnew System::EventHandler(this, &ContactListForm::exportDataButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(543, 452);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 23);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ContactListForm::exitButton_Click);
			// 
			// ContactListForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 491);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->exportDataButton);
			this->Controls->Add(this->addContactButton);
			this->Controls->Add(this->contactsDataGridView);
			this->Name = L"ContactListForm";
			this->Text = L"Contact List";
			this->VisibleChanged += gcnew System::EventHandler(this, &ContactListForm::ContactListForm_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contactsDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();

	}

	private: System::Void addContactButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		form3->Show();

	}


	private: System::Void ContactListForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {

		MySqlCommand^ sqlCommand = gcnew MySqlCommand("select * from contacts;", connectionDB);
		MySqlDataReader^ dataReader;
		DataTable^ sqlDataTable = gcnew DataTable();

		try {
			connectionDB->Open();
			dataReader = sqlCommand->ExecuteReader();
			sqlDataTable->Load(dataReader);
			dataReader->Close();
			connectionDB->Close();

			contactsDataGridView->DataSource = sqlDataTable;

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, L"Contact List", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}


	private: System::Void exportDataButton_Click(System::Object^ sender, System::EventArgs^ e) {
		//String^ filename = "ExportedContacts.txt";
		
		SaveFileDialog^ saveFile = gcnew SaveFileDialog();
		
		saveFile->Filter = "Text File|*.txt";
		saveFile->FileName = "ExportedContacts.txt";
		saveFile->Title = "Save Text File";

		if (saveFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			//String^ txtPath = "C:\\Users\\myrsi\\Desktop\\ExportedContacts.txt";
				
			String^ path = saveFile->FileName;

			StreamWriter^ writer = gcnew StreamWriter(File::Create(path));

			MySqlCommand^ sqlCommand = gcnew MySqlCommand("select * from contacts;", connectionDB);
			connectionDB->Open();
			MySqlDataReader^ dataReader = sqlCommand->ExecuteReader();
			int  columnCount = dataReader->FieldCount;
			String^ listOfColumns;

			//String^  listOfColumns = String::Empty;

			while (dataReader->Read())
			{
				for (int i = 0; i <= columnCount - 1; i++)
				{
					listOfColumns = listOfColumns + dataReader[i]->ToString() + ";";
				}
				listOfColumns = listOfColumns + System::Environment::NewLine;
			}
			writer->WriteLine(listOfColumns);
			writer->Close();
			dataReader->Close();
			connectionDB->Close();
		
		}
	
		
	}


};
}
