#pragma once
#include "emailValidation.h"
#include <string>
#include <regex>
#include "msclr\marshal_cppstd.h"


namespace DataFormProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for AddContactForm
	/// </summary>
	public ref class AddContactForm : public System::Windows::Forms::Form
	{
	public:

		System::Windows::Forms::Form^ form2;

		AddContactForm(void)
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
		~AddContactForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ nameTB;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ surnameTB;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ phoneTB;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ emailTB;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ addressTB;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ notesTB;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ nextEntryButton;
	private: System::Windows::Forms::Button^ backToListButton;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ cityTB;
	private: System::Windows::Forms::DateTimePicker^ dateOfBirthTB;


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
			this->nameTB = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->surnameTB = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->phoneTB = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->emailTB = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->addressTB = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->notesTB = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nextEntryButton = (gcnew System::Windows::Forms::Button());
			this->backToListButton = (gcnew System::Windows::Forms::Button());
			this->dateOfBirthTB = (gcnew System::Windows::Forms::DateTimePicker());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cityTB = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// nameTB
			// 
			this->nameTB->Location = System::Drawing::Point(118, 74);
			this->nameTB->Name = L"nameTB";
			this->nameTB->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->nameTB->Size = System::Drawing::Size(212, 20);
			this->nameTB->TabIndex = 3;
			this->nameTB->Leave += gcnew System::EventHandler(this, &AddContactForm::nameTB_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Name :";
			// 
			// surnameTB
			// 
			this->surnameTB->Location = System::Drawing::Point(118, 125);
			this->surnameTB->Name = L"surnameTB";
			this->surnameTB->Size = System::Drawing::Size(212, 20);
			this->surnameTB->TabIndex = 5;
			this->surnameTB->Leave += gcnew System::EventHandler(this, &AddContactForm::surnameTB_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Surname :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Date Of Birth :";
			// 
			// phoneTB
			// 
			this->phoneTB->Location = System::Drawing::Point(118, 208);
			this->phoneTB->MaxLength = 10;
			this->phoneTB->Name = L"phoneTB";
			this->phoneTB->Size = System::Drawing::Size(212, 20);
			this->phoneTB->TabIndex = 9;
			this->phoneTB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddContactForm::phoneTB_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 261);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Email :";
			// 
			// emailTB
			// 
			this->emailTB->Location = System::Drawing::Point(118, 254);
			this->emailTB->Name = L"emailTB";
			this->emailTB->Size = System::Drawing::Size(212, 20);
			this->emailTB->TabIndex = 11;
			this->emailTB->Leave += gcnew System::EventHandler(this, &AddContactForm::emailTB_Leave);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 306);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Address :";
			// 
			// addressTB
			// 
			this->addressTB->Location = System::Drawing::Point(118, 306);
			this->addressTB->Name = L"addressTB";
			this->addressTB->Size = System::Drawing::Size(212, 20);
			this->addressTB->TabIndex = 13;
			this->addressTB->Leave += gcnew System::EventHandler(this, &AddContactForm::addressTB_Leave);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(25, 355);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"City :";
			// 
			// notesTB
			// 
			this->notesTB->Location = System::Drawing::Point(118, 397);
			this->notesTB->Multiline = true;
			this->notesTB->Name = L"notesTB";
			this->notesTB->Size = System::Drawing::Size(212, 104);
			this->notesTB->TabIndex = 17;
			this->notesTB->Leave += gcnew System::EventHandler(this, &AddContactForm::noteTB_Leave);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(25, 397);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Notes :";
			// 
			// nextEntryButton
			// 
			this->nextEntryButton->Location = System::Drawing::Point(28, 555);
			this->nextEntryButton->Name = L"nextEntryButton";
			this->nextEntryButton->Size = System::Drawing::Size(75, 23);
			this->nextEntryButton->TabIndex = 18;
			this->nextEntryButton->Text = L"Next Entry";
			this->nextEntryButton->UseVisualStyleBackColor = true;
			this->nextEntryButton->Click += gcnew System::EventHandler(this, &AddContactForm::nextEntryButton_Click);
			// 
			// backToListButton
			// 
			this->backToListButton->Location = System::Drawing::Point(232, 555);
			this->backToListButton->Name = L"backToListButton";
			this->backToListButton->Size = System::Drawing::Size(100, 23);
			this->backToListButton->TabIndex = 19;
			this->backToListButton->Text = L"Back To List";
			this->backToListButton->UseVisualStyleBackColor = true;
			this->backToListButton->Click += gcnew System::EventHandler(this, &AddContactForm::backToListButton_Click);
			// 
			// dateOfBirthTB
			// 
			this->dateOfBirthTB->CustomFormat = L"yyyy-MM-dd";
			this->dateOfBirthTB->DropDownAlign = System::Windows::Forms::LeftRightAlignment::Right;
			this->dateOfBirthTB->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateOfBirthTB->Location = System::Drawing::Point(120, 167);
			this->dateOfBirthTB->Name = L"dateOfBirthTB";
			this->dateOfBirthTB->Size = System::Drawing::Size(212, 20);
			this->dateOfBirthTB->TabIndex = 7;
			this->dateOfBirthTB->Value = System::DateTime(2023, 2, 26, 1, 27, 18, 0);
			this->dateOfBirthTB->ValueChanged += gcnew System::EventHandler(this, &AddContactForm::dateOfBirthTB_ValueChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 215);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Phone Number : ";
			// 
			// cityTB
			// 
			this->cityTB->Location = System::Drawing::Point(118, 355);
			this->cityTB->Name = L"cityTB";
			this->cityTB->Size = System::Drawing::Size(212, 20);
			this->cityTB->TabIndex = 15;
			this->cityTB->Leave += gcnew System::EventHandler(this, &AddContactForm::cityTB_Leave);
			// 
			// AddContactForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 603);
			this->Controls->Add(this->cityTB);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->backToListButton);
			this->Controls->Add(this->nextEntryButton);
			this->Controls->Add(this->notesTB);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->addressTB);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->emailTB);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->phoneTB);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dateOfBirthTB);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->surnameTB);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->nameTB);
			this->Controls->Add(this->label2);
			this->Name = L"AddContactForm";
			this->Text = L"Add Contact ";
			this->Load += gcnew System::EventHandler(this, &AddContactForm::AddContactForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    private: System::Void backToListButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        form2->Show();
        
		//TODO: reset all fields

    }
    private: System::Void nextEntryButton_Click(System::Object^ sender, System::EventArgs^ e) {
        //TODO: save all variables
		
		String^ name = nullptr;
		String^ surname = nullptr;

		String^ today = DateTime::Today.Date.ToString("yyyy-MM-dd");
		String^ dateOfBirth = nullptr;

		String^ phoneNumber = nullptr;
		String^ email = nullptr;
		String^ address = nullptr;
		String^ city = nullptr;
		String^ notes = nullptr;
		
		nameTB->Text !="" ? name = nameTB->Text : name = "-";
		surnameTB->Text != "" ? surname = surnameTB->Text : "-";
		dateOfBirthTB->Text != today ? dateOfBirth = dateOfBirthTB->ToString() : dateOfBirth = "-";
		phoneTB->Text != "" ? phoneNumber = phoneTB->Text : phoneNumber = "-";
		emailTB->Text != "" ? email = emailTB->Text : email = "-";
		addressTB->Text != "" ? address = addressTB->Text : address = "-";
		cityTB->Text !="" ? city = cityTB->Text : city = "-";
		notesTB->Text != "" ? notes = notesTB->Text :notes = "-";

		//MessageBox::Show(name + " " + surname + " " + dateOfBirth + " " + phoneNumber + " " + email + " " + address + " " + city + " " + notes);
		//MessageBox::Show(dateOfBirthTB->Text + "\n" + dateOfBirth + "\n" + today);


		//TODO: sqlite connection
		String^ connectionString = L"datasource=localhost; port=3306; uid=root; database=contacts_form";
        MySqlConnection^ connectionDB = gcnew MySqlConnection(connectionString);

		try{
        
        MySqlCommand^ sqlCommand = gcnew MySqlCommand("insert into contacts (name, surname, date_of_birth, phone_number, email, address, city, notes) values  ;", connectionDB);
		}
		catch (Exception^ ex) {

		}
        //INSERT INTO `contacts` (`ID`, `name`, `surname`, `date_of_birth`, `phone_number`, `email`, `address`, `city`, `notes`) VALUES (NULL, 'fggfdfgdfdgfgd', 'fgdfgdfdgfgd', '2023-01-11', '6979282546', 'fdgfdgfgd', 'gfdgfdgfd', 'gfddfggdf', '');

       //TODO: apothikeysi olwn twn stoixeiwn stin basi
     

        //TODO: clear ola ta pedia
        /*nameTB->Text = "";
        surnameTB->Text = "";
        dateOfBirthTB->ResetText();
        phoneTB->Text = "";
        emailTB->Text = "";
        addressTB->Text = "";
        cityTB->Text = "";
        notesTB->Text = "";*/

    }
    private: System::Void nameTB_Leave(System::Object^ sender, System::EventArgs^ e) {

        nameTB->Text = nameTB->Text->ToUpper();

    }
    private: System::Void surnameTB_Leave(System::Object^ sender, System::EventArgs^ e) {

        surnameTB->Text = surnameTB->Text->ToUpper();

    }

    private: System::Void addressTB_Leave(System::Object^ sender, System::EventArgs^ e) {

        addressTB->Text = addressTB->Text->ToUpper();

    }

    private: System::Void cityTB_Leave(System::Object^ sender, System::EventArgs^ e) {

        cityTB->Text = cityTB->Text->ToUpper();

    }

    private: System::Void noteTB_Leave(System::Object^ sender, System::EventArgs^ e) {

        notesTB->Text = notesTB->Text->ToUpper();

    }

    private: System::Void phoneTB_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

        if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) {
            e->Handled = true;
        }
    }

    private: System::Void emailTB_Leave(System::Object^ sender, System::EventArgs^ e) {

        //System::String^ email = emailTB->Text;

        if (!(String::IsNullOrEmpty(emailTB->Text))) {

            msclr::interop::marshal_context context;
            std::string emailToCheck = context.marshal_as<std::string>(emailTB->Text);

            bool emailValidation = isEmailValid1(emailToCheck);

            if (emailValidation == false) {
                MessageBox::Show("Please enter a valid email address", "Unvalid email address", MessageBoxButtons::OK,
                    MessageBoxIcon::Exclamation);
                emailTB->Clear();
                emailTB->Focus();

            }

        }
    }

	private: System::Void AddContactForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//dateOfBirthTB->Format = DateTimePickerFormat::Short;
		dateOfBirthTB->MaxDate = DateTime::Today;
		dateOfBirthTB->Value = DateTime::Today;
	}


	private: System::Void dateOfBirthTB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
