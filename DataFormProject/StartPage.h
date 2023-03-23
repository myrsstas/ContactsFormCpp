#pragma once
#include "ContactListForm.h"
#include "AddContactForm.h"


namespace DataFormProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for StartPage
	/// </summary>
	public ref class StartPage : public System::Windows::Forms::Form
	{

		public: ContactListForm^ form2;
		public: AddContactForm^ form3;
		
		String^ connectionString = L"datasource=localhost; port=3306; uid=root; database=contacts_form;";
		MySqlConnection^ connectionDB = gcnew MySqlConnection(connectionString);


	public:
		StartPage(void)
		{
			InitializeComponent();

			form2 = gcnew ContactListForm();
			form3 = gcnew AddContactForm();
			form2->form1 = this;
			form2->form3 = form3;
			form3->form2 = form2;
			

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer;
	private: System::Windows::Forms::Button^ startFromZeroButton;
	private: System::Windows::Forms::Label^ startLabel;
	private: System::Windows::Forms::Button^ uploadButton;
	private: System::Windows::Forms::Button^ browseButton;
	private: System::Windows::Forms::TextBox^ filepathTextBox;
	private: System::Windows::Forms::Label^ uploadLabel;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

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
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->startFromZeroButton = (gcnew System::Windows::Forms::Button());
			this->startLabel = (gcnew System::Windows::Forms::Label());
			this->uploadButton = (gcnew System::Windows::Forms::Button());
			this->browseButton = (gcnew System::Windows::Forms::Button());
			this->filepathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->uploadLabel = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer
			// 
			this->splitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer->Location = System::Drawing::Point(0, 0);
			this->splitContainer->Name = L"splitContainer";
			this->splitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->startFromZeroButton);
			this->splitContainer->Panel1->Controls->Add(this->startLabel);
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->uploadButton);
			this->splitContainer->Panel2->Controls->Add(this->browseButton);
			this->splitContainer->Panel2->Controls->Add(this->filepathTextBox);
			this->splitContainer->Panel2->Controls->Add(this->uploadLabel);
			this->splitContainer->Size = System::Drawing::Size(426, 351);
			this->splitContainer->SplitterDistance = 161;
			this->splitContainer->TabIndex = 0;
			// 
			// startFromZeroButton
			// 
			this->startFromZeroButton->Location = System::Drawing::Point(158, 89);
			this->startFromZeroButton->Name = L"startFromZeroButton";
			this->startFromZeroButton->Size = System::Drawing::Size(110, 23);
			this->startFromZeroButton->TabIndex = 1;
			this->startFromZeroButton->Text = L"Start From Zero";
			this->startFromZeroButton->UseVisualStyleBackColor = true;
			this->startFromZeroButton->Click += gcnew System::EventHandler(this, &StartPage::startFromZeroButton_Click);
			// 
			// startLabel
			// 
			this->startLabel->AutoSize = true;
			this->startLabel->Location = System::Drawing::Point(92, 53);
			this->startLabel->Name = L"startLabel";
			this->startLabel->Size = System::Drawing::Size(219, 13);
			this->startLabel->TabIndex = 0;
			this->startLabel->Text = L"To start a new list, click on \"Start From Zero\"";
			// 
			// uploadButton
			// 
			this->uploadButton->Location = System::Drawing::Point(285, 97);
			this->uploadButton->Name = L"uploadButton";
			this->uploadButton->Size = System::Drawing::Size(75, 23);
			this->uploadButton->TabIndex = 3;
			this->uploadButton->Text = L"Upload";
			this->uploadButton->UseVisualStyleBackColor = true;
			this->uploadButton->Click += gcnew System::EventHandler(this, &StartPage::uploadButton_Click);
			// 
			// browseButton
			// 
			this->browseButton->Location = System::Drawing::Point(178, 94);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(33, 23);
			this->browseButton->TabIndex = 2;
			this->browseButton->Text = L"...";
			this->browseButton->UseVisualStyleBackColor = true;
			// 
			// filepathTextBox
			// 
			this->filepathTextBox->Location = System::Drawing::Point(72, 97);
			this->filepathTextBox->Name = L"filepathTextBox";
			this->filepathTextBox->Size = System::Drawing::Size(100, 20);
			this->filepathTextBox->TabIndex = 1;
			// 
			// uploadLabel
			// 
			this->uploadLabel->AutoSize = true;
			this->uploadLabel->Location = System::Drawing::Point(69, 54);
			this->uploadLabel->Name = L"uploadLabel";
			this->uploadLabel->Size = System::Drawing::Size(291, 13);
			this->uploadLabel->TabIndex = 0;
			this->uploadLabel->Text = L"If you used this app before, and have a file, please upload it.";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// StartPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 351);
			this->Controls->Add(this->splitContainer);
			this->Name = L"StartPage";
			this->Text = L"Start Page";
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel1->PerformLayout();
			this->splitContainer->Panel2->ResumeLayout(false);
			this->splitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void startFromZeroButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//removeAllRecords();

		//TODO: Close this form and open the next one
		this->Hide();
		form2->Show();

			
		}
	private: System::Void removeAllRecords() {
		//TODO: add connection to DB
		//TODO: clear DB from previous data

		MySqlCommand^ command = gcnew MySqlCommand("truncate table contacts;", connectionDB);
		try {
			connectionDB->Open();
			command->ExecuteNonQuery();
			connectionDB->Close();

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, L"Start Page", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
	}
	private: System::Void uploadButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
