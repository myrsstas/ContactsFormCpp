#include "StartPage.h"
//#include "ContactListForm.h"
//#include "AddContactForm.h"



using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DataFormProject::StartPage form;//όνομα του Project και ονομασία της φόρμας μας
	
	Application::Run(% form);
}
