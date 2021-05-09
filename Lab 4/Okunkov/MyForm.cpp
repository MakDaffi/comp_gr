#include "Transform.h"
#include <fstream>
#include <sstream>
#include "Figure.h"
#include "Clip.h"
#include "MyForm.h"
#include "Matrix.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Okunkov::MyForm form;
	Application::Run(% form);
}
