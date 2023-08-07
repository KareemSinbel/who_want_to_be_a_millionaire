#include "Startscreen.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) 
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    /*millionaire::Startscreen form;
    Application::Run(% form);*/
    //if (form.closed == true)
    //{

    //}
    millionaire::Startscreen^ form = gcnew millionaire::Startscreen();
    form->Show();
    Application::Run();
}