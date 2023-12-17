#include "MemoryTrain.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) {

	srand(time(NULL));

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	MemoryTrain::MemoryTrain form;
	Application::Run(% form);
}

