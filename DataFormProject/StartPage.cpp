//Application development in popular integrated development environments � 2023 by Myrsini Stasinou is licensed under CC-BY-4.0 
#include "StartPage.h"



using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DataFormProject::StartPage form;//����� ��� Project ��� �������� ��� ������ ���
	
	Application::Run(% form);
}
