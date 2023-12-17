#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

string Return_Word(int, int);
string Reverse(string);
vector <string> Split(string);

bool InputCheckFirstStep(string, string);
bool InputCheckSecondStep(vector<string>, vector <string>);
bool InputCheckThirdStep(vector<string>, vector <string>);
bool InputCheckForthStep(vector<string>, vector <string>);
bool InputCheckFifthStep(vector<string>, vector <string>);
void Creating();
void OutputGenWord();
namespace MemoryTrain {

	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	const int TotalWordsCount = 5;
	const int TotalGenWords = 400;
	const string LoadLine{ "--------------------" };

	string Processed_Words[TotalGenWords]{};
	int Num_Word{ 0 };

	int CorrectInputs{ 0 };
	int TimeMemory[5][2]{ {7000, 15000}, {5000, 10000}, {3000, 7000}, {1500, 5000}, {1000, 3000} };
	string WordsLine;
	string FirstStageWord{};
	vector<string> UsersWordsList{};
	vector<string> GeneratedWords{};
	bool GameOver{ false };
	bool CorrCheck{ false };

	/// <summary>
	/// Сводка для MemoryTrain
	/// </summary>
	vector<string> Cond{ "На экране на некоторое время отображается слово из 5 букв, а затем пропадает. Пользователь вводит с клавиатуры это же слово, но в обратном порядке('перевернутым'). После выводится сообщение о верном\\неверном вводе. Затем появляется новое слово с тем же количеством букв и ожидается новый ввод 'перевернутого' слова. После правильно введенных трех подряд верных 'перевернутых' слов начинают выводиться слова длинее на одну букву и так до тех пор, пока Вы не введете подряд три 'перевернутых' 8 буквенных слова. На этом этап 1 завершается.",
		"На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Вам необходимо ввести эти же слова в произвольном порядке. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться послдовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов.", 
		"На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Однако в отличие от второго этапа на третьем Вам необходимо ввести эти же слова в том же порядке, в котором они были Вам показаны. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться послдовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов.", 
		"Четвертый этап является смесью первого и второго. На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Вам необходимо ввести эти же слова в произвольном порядке, однако сами слова должны быть 'перевернуты'. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться послдовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов.", 
		"Пятый этап - слияние первого и третьего. На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Вам необходимо ввести эти же слова в том же порядке, в котором они были Вам показаны, и они так же должны быть 'перевернуты'. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться послдовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов."};

	public ref class MemoryTrain : public System::Windows::Forms::Form
	{
	public:
		MemoryTrain(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MemoryTrain()
		{
			if (components)
			{
				delete components;
			}
		}

	string Return_Word(int letters, int Word_Index) {

		string Word{};
		fstream file;

		bool Flag = false;

		switch (letters) {
		case 5:
			file.open("5_letters.txt");
			break;
		case 6:
			file.open("6_letters.txt");
			break;
		case 7:
			file.open("7_letters.txt");
			break;
		case 8:
			file.open("8_letters.txt");
			break;
		}

		if (file.is_open()) {
			for (int lineno = 1; (lineno <= Word_Index) && getline(file, Word); lineno++);
			for (int i = 0; !Flag && i < Num_Word; i++)
				Flag = (Processed_Words[i] == Word);
		}
		else {
			cout << "Error. Cannot open file" << endl;
		}

		file.close();
		if (Flag) return "";

		return Word.substr(0, letters);
	}

	string Reverse(string Line) {
		
		int StartCheck = Line.find_first_not_of(" ");
		int EndCheck = Line.find_last_not_of(" ");
		string Result{};
		for (int i = StartCheck;i <= EndCheck;i ++)
			Result += Line[EndCheck - i];
		Result.resize(EndCheck - StartCheck + 1);
		return Result;
	}

	vector <string> Split(string UsersLine) {

		vector <string> UsersEnteredWords;
		int StartCheck = UsersLine.find_first_not_of("     ");
		while (StartCheck != -1) {
			UsersEnteredWords.push_back(
				UsersLine.substr(StartCheck, (UsersLine.find_first_of(" ", StartCheck) - StartCheck)));

			StartCheck = UsersLine.find_first_not_of(" ", UsersLine.find_first_of(" ", StartCheck));
		}
		return UsersEnteredWords;
	}

	bool InputCheckSecondStep(vector<string> UsersWords, vector <string> GenWords) {
		if (size(UsersWords) != size(GenWords)) return false;
		for (int i = 0;i < size(GenWords);i++) {
			bool flag = false;
			for (int j = 0;!flag && j < size(GenWords);j++) {
				if (UsersWords.back() == GenWords[j]) {
					UsersWords.pop_back();
					flag = true;
				}
			}
			if (!flag)
				return false;
		}
		return true;
	}
	bool InputCheckThirdStep(vector<string> UsersWords, vector <string> GenWords) {
		if (size(UsersWords) != size(GenWords)) return false;
		for (int i = 0;i < size(GenWords);i++) {
			if (UsersWords[i] != GenWords[i]) return false;
		}
		return true;
	}
	bool InputCheckForthStep(vector<string> UsersWords, vector <string> GenWords) {
		if (size(UsersWords) != size(GenWords)) return false;
		for (int i = 0;i < size(GenWords);i++) {
			bool flag = false;
			for (int j = 0;!flag && j < size(GenWords);j++) {
				if (Reverse(UsersWords.back()) == GenWords[j]) {
					UsersWords.pop_back();
					flag = true;
				}
			}
			if (!flag)
				return false;
		}
		return true;
	}
	bool InputCheckFifthStep(vector<string> UsersWords, vector <string> GenWords) {
		if (size(UsersWords) != size(GenWords)) return false;
		for (int i = 0;i < size(GenWords);i++) {
			if (Reverse(UsersWords[i]) != GenWords[i]) return false;
		}
		return true;
	}
	
	private: System::Windows::Forms::Label^ StartText;
	private: System::Windows::Forms::Label^ Condition;
	private: System::Windows::Forms::Label^ Header;
	private: System::Windows::Forms::Label^ GenLine;
	private: System::Windows::Forms::Label^ PreparingLine;
	private: System::Windows::Forms::Label^ CheckedLine;
	private: System::Windows::Forms::Label^ Message;
	private: System::Windows::Forms::Label^ Buff;
	private: System::Windows::Forms::RadioButton^ HardLevel1;
	private: System::Windows::Forms::RadioButton^ HardLevel2;
	private: System::Windows::Forms::RadioButton^ HardLevel3;
	private: System::Windows::Forms::RadioButton^ HardLevel4;
	private: System::Windows::Forms::RadioButton^ HardLevel5;
	private: System::Windows::Forms::RadioButton^ Stage1;
	private: System::Windows::Forms::RadioButton^ Stage2;
	private: System::Windows::Forms::RadioButton^ Stage3;
	private: System::Windows::Forms::RadioButton^ Stage4;
	private: System::Windows::Forms::RadioButton^ Stage5;

	private: System::Windows::Forms::GroupBox^ HardLevelList;
	private: System::Windows::Forms::GroupBox^ NumStageList;

	private: System::Windows::Forms::Button^ Confirm;
	private: System::Windows::Forms::Button^ Start;
	private: System::Windows::Forms::Button^ Home;
	private: System::Windows::Forms::Button^ Continue;

	private: System::Windows::Forms::RichTextBox^ UsersInput;

	private: int HardLevel{ 1 }, Stage{ 1 };

	private: 
	
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MemoryTrain::typeid));
			this->StartText = (gcnew System::Windows::Forms::Label());
			this->Message = (gcnew System::Windows::Forms::Label());
			this->CheckedLine = (gcnew System::Windows::Forms::Label());
			this->HardLevel1 = (gcnew System::Windows::Forms::RadioButton());
			this->HardLevel2 = (gcnew System::Windows::Forms::RadioButton());
			this->HardLevel3 = (gcnew System::Windows::Forms::RadioButton());
			this->HardLevel4 = (gcnew System::Windows::Forms::RadioButton());
			this->HardLevel5 = (gcnew System::Windows::Forms::RadioButton());
			this->Stage1 = (gcnew System::Windows::Forms::RadioButton());
			this->Stage2 = (gcnew System::Windows::Forms::RadioButton());
			this->Stage3 = (gcnew System::Windows::Forms::RadioButton());
			this->Stage4 = (gcnew System::Windows::Forms::RadioButton());
			this->Stage5 = (gcnew System::Windows::Forms::RadioButton());
			this->HardLevelList = (gcnew System::Windows::Forms::GroupBox());
			this->NumStageList = (gcnew System::Windows::Forms::GroupBox());
			this->Confirm = (gcnew System::Windows::Forms::Button());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->Continue = (gcnew System::Windows::Forms::Button());
			this->Home = (gcnew System::Windows::Forms::Button());
			this->Buff = (gcnew System::Windows::Forms::Label());
			this->Header = (gcnew System::Windows::Forms::Label());
			this->Condition = (gcnew System::Windows::Forms::Label());
			this->PreparingLine = (gcnew System::Windows::Forms::Label());
			this->GenLine = (gcnew System::Windows::Forms::Label());
			this->UsersInput = (gcnew System::Windows::Forms::RichTextBox());
			this->HardLevelList->SuspendLayout();
			this->NumStageList->SuspendLayout();
			this->SuspendLayout();
			// 
			// StartText
			// 
			this->StartText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StartText->Dock = System::Windows::Forms::DockStyle::Top;
			this->StartText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F));
			this->StartText->ForeColor = System::Drawing::Color::AliceBlue;
			this->StartText->Location = System::Drawing::Point(0, 0);
			this->StartText->Name = L"StartText";
			this->StartText->Size = System::Drawing::Size(700, 100);
			this->StartText->TabIndex = 1;
			this->StartText->Text = L"Выберите уровень сложности и желаемый этап";
			// 
			// HardLevel1
			// 
			this->HardLevel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->HardLevel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->HardLevel1->FlatAppearance->BorderSize = 3;
			this->HardLevel1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->HardLevel1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HardLevel1->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->HardLevel1->ForeColor = System::Drawing::Color::Orange;
			this->HardLevel1->Location = System::Drawing::Point(6, 43);
			this->HardLevel1->Name = L"HardLevel1";
			this->HardLevel1->Size = System::Drawing::Size(141, 35);
			this->HardLevel1->TabIndex = 4;
			this->HardLevel1->TabStop = true;
			this->HardLevel1->Text = L"1 Уровень";
			this->HardLevel1->UseVisualStyleBackColor = false;
			this->HardLevel1->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel2
			// 
			this->HardLevel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->HardLevel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->HardLevel2->FlatAppearance->BorderSize = 3;
			this->HardLevel2->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->HardLevel2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HardLevel2->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->HardLevel2->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel2->Location = System::Drawing::Point(6, 90);
			this->HardLevel2->Name = L"HardLevel2";
			this->HardLevel2->Size = System::Drawing::Size(141, 35);
			this->HardLevel2->TabIndex = 5;
			this->HardLevel2->TabStop = true;
			this->HardLevel2->Text = L"2 Уровень";
			this->HardLevel2->UseVisualStyleBackColor = false;
			this->HardLevel2->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel3
			// 
			this->HardLevel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->HardLevel3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel3->FlatAppearance->BorderSize = 3;
			this->HardLevel3->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->HardLevel3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HardLevel3->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->HardLevel3->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel3->Location = System::Drawing::Point(6, 137);
			this->HardLevel3->Name = L"HardLevel3";
			this->HardLevel3->Size = System::Drawing::Size(141, 35);
			this->HardLevel3->TabIndex = 6;
			this->HardLevel3->TabStop = true;
			this->HardLevel3->Text = L"3 Уровень";
			this->HardLevel3->UseVisualStyleBackColor = false;
			this->HardLevel3->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel4
			// 
			this->HardLevel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->HardLevel4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel4->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel4->FlatAppearance->BorderSize = 3;
			this->HardLevel4->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->HardLevel4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HardLevel4->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->HardLevel4->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel4->Location = System::Drawing::Point(6, 184);
			this->HardLevel4->Name = L"HardLevel4";
			this->HardLevel4->Size = System::Drawing::Size(141, 35);
			this->HardLevel4->TabIndex = 7;
			this->HardLevel4->TabStop = true;
			this->HardLevel4->Text = L"4 Уровень";
			this->HardLevel4->UseVisualStyleBackColor = false;
			this->HardLevel4->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel5
			// 
			this->HardLevel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->HardLevel5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel5->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel5->FlatAppearance->BorderSize = 3;
			this->HardLevel5->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->HardLevel5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HardLevel5->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->HardLevel5->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel5->Location = System::Drawing::Point(6, 231);
			this->HardLevel5->Name = L"HardLevel5";
			this->HardLevel5->Size = System::Drawing::Size(141, 35);
			this->HardLevel5->TabIndex = 8;
			this->HardLevel5->TabStop = true;
			this->HardLevel5->Text = L"5 Уровень";
			this->HardLevel5->UseVisualStyleBackColor = false;
			this->HardLevel5->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// Stage1
			// 
			this->Stage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->Stage1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Stage1->FlatAppearance->BorderSize = 3;
			this->Stage1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->Stage1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stage1->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->Stage1->ForeColor = System::Drawing::Color::Orange;
			this->Stage1->Location = System::Drawing::Point(6, 43);
			this->Stage1->Name = L"Stage1";
			this->Stage1->Size = System::Drawing::Size(141, 35);
			this->Stage1->TabIndex = 9;
			this->Stage1->TabStop = true;
			this->Stage1->Text = L"1 Этап";
			this->Stage1->UseVisualStyleBackColor = false;
			this->Stage1->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage2
			// 
			this->Stage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->Stage2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage2->FlatAppearance->CheckedBackColor = System::Drawing::Color::RosyBrown;
			this->Stage2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stage2->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->Stage2->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage2->Location = System::Drawing::Point(6, 90);
			this->Stage2->Name = L"Stage2";
			this->Stage2->Size = System::Drawing::Size(141, 35);
			this->Stage2->TabIndex = 10;
			this->Stage2->TabStop = true;
			this->Stage2->Text = L"2 Этап";
			this->Stage2->UseVisualStyleBackColor = false;
			this->Stage2->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage3
			// 
			this->Stage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->Stage3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage3->FlatAppearance->CheckedBackColor = System::Drawing::Color::RosyBrown;
			this->Stage3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stage3->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->Stage3->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage3->Location = System::Drawing::Point(6, 137);
			this->Stage3->Name = L"Stage3";
			this->Stage3->Size = System::Drawing::Size(141, 35);
			this->Stage3->TabIndex = 11;
			this->Stage3->TabStop = true;
			this->Stage3->Text = L"3 Этап";
			this->Stage3->UseVisualStyleBackColor = false;
			this->Stage3->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage4
			// 
			this->Stage4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->Stage4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage4->FlatAppearance->CheckedBackColor = System::Drawing::Color::RosyBrown;
			this->Stage4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stage4->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->Stage4->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage4->Location = System::Drawing::Point(6, 184);
			this->Stage4->Name = L"Stage4";
			this->Stage4->Size = System::Drawing::Size(141, 35);
			this->Stage4->TabIndex = 12;
			this->Stage4->TabStop = true;
			this->Stage4->Text = L"4 Этап";
			this->Stage4->UseVisualStyleBackColor = false;
			this->Stage4->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage5
			// 
			this->Stage5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->Stage5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage5->FlatAppearance->CheckedBackColor = System::Drawing::Color::RosyBrown;
			this->Stage5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stage5->Font = (gcnew System::Drawing::Font(L"Roboto", 10.25F));
			this->Stage5->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage5->Location = System::Drawing::Point(6, 231);
			this->Stage5->Name = L"Stage5";
			this->Stage5->Size = System::Drawing::Size(141, 35);
			this->Stage5->TabIndex = 13;
			this->Stage5->TabStop = true;
			this->Stage5->Text = L"5 Этап";
			this->Stage5->UseVisualStyleBackColor = false;
			this->Stage5->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// HardLevelList
			// 
			this->HardLevelList->Controls->Add(this->HardLevel1);
			this->HardLevelList->Controls->Add(this->HardLevel2);
			this->HardLevelList->Controls->Add(this->HardLevel3);
			this->HardLevelList->Controls->Add(this->HardLevel4);
			this->HardLevelList->Controls->Add(this->HardLevel5);
			this->HardLevelList->Font = (gcnew System::Drawing::Font(L"Roboto", 15.25F));
			this->HardLevelList->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevelList->Location = System::Drawing::Point(20, 184);
			this->HardLevelList->Name = L"HardLevelList";
			this->HardLevelList->Size = System::Drawing::Size(233, 287);
			this->HardLevelList->TabIndex = 15;
			this->HardLevelList->TabStop = false;
			this->HardLevelList->Text = L"Уровень Сложности";
			// 
			// NumStageList
			// 
			this->NumStageList->Controls->Add(this->Stage1);
			this->NumStageList->Controls->Add(this->Stage3);
			this->NumStageList->Controls->Add(this->Stage5);
			this->NumStageList->Controls->Add(this->Stage2);
			this->NumStageList->Controls->Add(this->Stage4);
			this->NumStageList->Font = (gcnew System::Drawing::Font(L"Roboto", 15.25F));
			this->NumStageList->ForeColor = System::Drawing::Color::AliceBlue;
			this->NumStageList->Location = System::Drawing::Point(268, 184);
			this->NumStageList->Name = L"NumStageList";
			this->NumStageList->Size = System::Drawing::Size(200, 287);
			this->NumStageList->TabIndex = 16;
			this->NumStageList->TabStop = false;
			this->NumStageList->Text = L"Номер Этапа";
			// 
			// Confirm
			// 
			this->Confirm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->Confirm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Confirm->FlatAppearance->BorderSize = 0;
			this->Confirm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Confirm->Font = (gcnew System::Drawing::Font(L"Roboto", 15.25F));
			this->Confirm->ForeColor = System::Drawing::Color::AliceBlue;
			this->Confirm->Location = System::Drawing::Point(500, 434);
			this->Confirm->Name = L"Confirm";
			this->Confirm->Size = System::Drawing::Size(188, 37);
			this->Confirm->TabIndex = 17;
			this->Confirm->Text = L"Подтвердить";
			this->Confirm->UseVisualStyleBackColor = false;
			this->Confirm->Click += gcnew System::EventHandler(this, &MemoryTrain::Confirm_CheckedChanged);
			// 
			// Header
			// 
			this->Header->Dock = System::Windows::Forms::DockStyle::Top;
			this->Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->Header->ForeColor = System::Drawing::Color::AliceBlue;
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(700, 50);
			this->Header->TabIndex = 0;
			// 
			// Condition
			// 
			this->Condition->Font = (gcnew System::Drawing::Font(L"Roboto", 15));
			this->Condition->ForeColor = System::Drawing::Color::AliceBlue;
			this->Condition->Location = System::Drawing::Point(25, 70);
			this->Condition->Name = L"Condition";
			this->Condition->Size = System::Drawing::Size(650, 300);
			this->Condition->TabIndex = 0;
			// 
			// Start
			// 
			this->Start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Start->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Start->Font = (gcnew System::Drawing::Font(L"Roboto", 18.25F));
			this->Start->ForeColor = System::Drawing::Color::AliceBlue;
			this->Start->Location = System::Drawing::Point(25, 100);
			this->Start->Margin = System::Windows::Forms::Padding(100);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(70, 40);
			this->Start->TabIndex = 0;
			this->Start->Text = L"Начать";
			this->Start->Click += gcnew System::EventHandler(this, &MemoryTrain::Start_CheckedChanged);
			// 
			// PreparingLine
			// 
			this->PreparingLine->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->PreparingLine->Font = (gcnew System::Drawing::Font(L"Roboto", 50));
			this->PreparingLine->ForeColor = System::Drawing::Color::AliceBlue;
			this->PreparingLine->Location = System::Drawing::Point(0, 0);
			this->PreparingLine->Name = L"PreparingLine";
			this->PreparingLine->Size = System::Drawing::Size(700, 50);
			this->PreparingLine->TabIndex = 0;
			this->PreparingLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GenLine
			// 
			this->GenLine->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GenLine->Font = (gcnew System::Drawing::Font(L"Roboto", 30));
			this->GenLine->ForeColor = System::Drawing::Color::AliceBlue;
			this->GenLine->Location = System::Drawing::Point(0, 0);
			this->GenLine->Name = L"GenLine";
			this->GenLine->Size = System::Drawing::Size(100, 23);
			this->GenLine->TabIndex = 0;
			this->GenLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// UsersInput
			// 
			this->UsersInput->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->UsersInput->Font = (gcnew System::Drawing::Font(L"Roboto", 20));
			this->UsersInput->ForeColor = System::Drawing::Color::White;
			this->UsersInput->Location = System::Drawing::Point(25, 150);
			this->UsersInput->Name = L"UsersInput";
			this->UsersInput->Size = System::Drawing::Size(650, 250);
			this->UsersInput->TabIndex = 18;
			this->UsersInput->Select(0,0);
			this->UsersInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MemoryTrain::UsersInput_KeyPress);
			// 
			// CheckedLine
			// 
			this->CheckedLine->Font = (gcnew System::Drawing::Font(L"Roboto", 20));
			this->CheckedLine->ForeColor = System::Drawing::Color::White;
			this->CheckedLine->Dock = System::Windows::Forms::DockStyle::Top;
			this->CheckedLine->AutoSize = true;
			this->CheckedLine->MinimumSize = System::Drawing::Size(700, 100);
			this->CheckedLine->MaximumSize = System::Drawing::Size(700, 300);
			this->CheckedLine->Name = L"CheckedLine";
			this->CheckedLine->TabIndex = 19;
			this->CheckedLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Message
			// 
			this->Message->Font = (gcnew System::Drawing::Font(L"Roboto", 20));
			this->Message->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Message->Name = L"Message";
			this->Message->TabIndex = 20;
			this->Message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Home
			// 
			this->Home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Home->Font = (gcnew System::Drawing::Font(L"Roboto", 18.25F));
			this->Home->ForeColor = System::Drawing::Color::AliceBlue;
			this->Home->Location = System::Drawing::Point(0, 460);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(350, 40);
			this->Home->TabIndex = 21;
			this->Home->Text = L"Главное меню";
			this->Home->Click += gcnew System::EventHandler(this, &MemoryTrain::Home_CheckedChanged);
			// 
			// Start
			// 
			this->Continue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Continue->Font = (gcnew System::Drawing::Font(L"Roboto", 18.25F));
			this->Continue->ForeColor = System::Drawing::Color::AliceBlue;
			this->Continue->Location = System::Drawing::Point(350, 460);
			this->Continue->Name = L"Continue";
			this->Continue->Size = System::Drawing::Size(350, 40);
			this->Continue->TabIndex = 22;
			this->Continue->Text = L"Продолжить";
			this->Continue->Click += gcnew System::EventHandler(this, &MemoryTrain::Continue_CheckedChanged);
			//
			// Buff
			// 
			this->Buff->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Buff->Size = System::Drawing::Size(350, 40);
			// 
			// MemoryTrain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->Confirm);
			this->Controls->Add(this->NumStageList);
			this->Controls->Add(this->HardLevelList);
			this->Controls->Add(this->StartText);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MemoryTrain";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Тренажер памяти";
			this->HardLevelList->ResumeLayout(false);
			this->NumStageList->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: void Creating() {
		switch (Stage) {

		case 1:
			GeneratedWords.resize(1);
			do {
				GeneratedWords[0] = Return_Word(5 + CorrectInputs / 3, 1 + rand() % (100));
			} while (GeneratedWords[0] == "");
			Processed_Words[Num_Word++] = GeneratedWords[0];
			WordsLine = GeneratedWords[0];

			break;
		case 2:
		case 3:
		case 4:
		case 5:
			WordsLine = {};
			GeneratedWords.resize(5 + CorrectInputs / 3);
			for (int i = 0;i < TotalWordsCount + CorrectInputs / 3; i++) {
				do {
					GeneratedWords[i] = Return_Word(5 + rand() % (4), 1 + rand() % (100));
				} while (GeneratedWords[i] == "");
				WordsLine += GeneratedWords[i] + ' ';
				Processed_Words[Num_Word++] = GeneratedWords[i];
			}
			break;
		}

	}
	private: void OutputGenWord() {
		Controls->Clear();
		Creating();
		this->Header->Text = Stage + L" Этап " + (CorrectInputs / 3 + 1) + L" Стадия." +
			L" Правильно введено: " + CorrectInputs % 3;
		this->GenLine->Text = L"";
		this->GenLine->Text = gcnew System::String(WordsLine.c_str());
		this->Controls->Add(this->GenLine);
		GenLine->Show();

		this->Controls->Add(this->PreparingLine);
		PreparingLine->Show();
		this->Controls->Add(this->Header);
		for (int k = 19; k > 0;k -= 2) {
			this->PreparingLine->Text = gcnew System::String(LoadLine.substr(0, k).c_str());

			Application::DoEvents();
			if (this->GenLine->Text->Length <= 8) Sleep(TimeMemory[HardLevel][0] / 10);
			else Sleep(TimeMemory[HardLevel][1] / 10);
		}

		GenLine->Hide();
		PreparingLine->Hide();

		this->Controls->Add(this->UsersInput);
		UsersInput->Text = L"";
		UsersInput->Show();
		UsersInput->Focus();

	}
	private: void OutputCond() {
		Controls->Clear();

		this->Header->Text = L"Правила " + (Stage)+L" этапа";
		this->Header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));

		this->Condition->Text = gcnew System::String(Cond[Stage - 1].c_str());
		this->Condition->Show();
		this->Controls->Add(this->Header);
		this->Controls->Add(this->Condition);
		this->Controls->Add(this->Start);

	}

	private: System::Void HardLevel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		HardLevel1->ForeColor = System::Drawing::Color::AliceBlue;
		HardLevel2->ForeColor = System::Drawing::Color::AliceBlue;
		HardLevel3->ForeColor = System::Drawing::Color::AliceBlue;
		HardLevel4->ForeColor = System::Drawing::Color::AliceBlue;
		HardLevel5->ForeColor = System::Drawing::Color::AliceBlue;
		RadioButton^ radiobutton = safe_cast<RadioButton^>(sender);
		radiobutton->ForeColor = System::Drawing::Color::Orange;
		HardLevel = radiobutton->Text[0] - 49;
	}
	private: System::Void NumStage_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Stage1->ForeColor = System::Drawing::Color::AliceBlue;
		Stage2->ForeColor = System::Drawing::Color::AliceBlue;
		Stage3->ForeColor = System::Drawing::Color::AliceBlue;
		Stage4->ForeColor = System::Drawing::Color::AliceBlue;
		Stage5->ForeColor = System::Drawing::Color::AliceBlue;
		RadioButton^ radiobutton = safe_cast<RadioButton^>(sender);
		radiobutton->ForeColor = System::Drawing::Color::Orange;
		Stage = radiobutton->Text[0] - 48;
	}
	private: System::Void Confirm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		OutputCond();
	}
	private: System::Void Home_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		CorrectInputs = 0;
		for (int i = 0;i < Num_Word; i++)
			Processed_Words[i] = "";
		Num_Word = 0;
		this->Controls->Clear();
		this->Controls->Add(this->Confirm);
		this->Controls->Add(this->NumStageList);
		this->Controls->Add(this->HardLevelList);
		this->Controls->Add(this->StartText);
	}
	
	private: System::Void Continue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		CorrectInputs = (CorrectInputs / 3) * 3;
		OutputGenWord();
	}

	private: System::Void UsersInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if (e->KeyChar == 13) {

			e->Handled = true;
			UsersInput->Select(UsersInput->Text->Length, 0);
			UsersInput->Text = UsersInput->Text->ToUpper();
			CheckedLine->Text = UsersInput->Text;
			string UsersString{};

			for (int i = 0; i < UsersInput->Text->Length - 1; i++)
				if (UsersInput->Text[i] == 32) UsersString += UsersInput->Text[i];
				else  if (UsersInput->Text[i] != 84) UsersString += UsersInput->Text[i] - 848;
			
			UsersInput->Hide();
			Controls->Add(CheckedLine);
			Controls->Add(Header);

			UsersWordsList = Split(UsersString);

			switch (Stage) {
				case 1:
				case 5:
					CorrCheck = InputCheckFifthStep(UsersWordsList, GeneratedWords);
					break;
				case 2:
					CorrCheck = InputCheckSecondStep(UsersWordsList, GeneratedWords);
					break;
				case 3:
					CorrCheck = InputCheckThirdStep(UsersWordsList, GeneratedWords);
					break;
				case 4:
					CorrCheck = InputCheckForthStep(UsersWordsList, GeneratedWords);
					break;
			}

			if (CorrCheck) {
				this->Message->ForeColor = System::Drawing::Color::FromArgb(100, 255, 100);
				this->Message->Text = L"ВЕРНО!";
				this->Controls->Add(Message);

				PreparingLine->Show();
				for (int k = 19; k > 0;k -= 2) {
					this->PreparingLine->Text = gcnew System::String(LoadLine.substr(0, k).c_str());
				
					Application::DoEvents();
					Sleep(100);
				}
				CorrectInputs++;
				if (CorrectInputs == 12) {
					Stage++;
					CorrectInputs = 0;
					OutputCond();
				}
				else OutputGenWord();
			}

			else {
				this->Message->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
				this->Message->Text = GenLine->Text + L"\n\n" + L"ВЫ ОШИБЛИСЬ!";
				this->Controls->Add(Home);
				this->Controls->Add(Continue);
				this->Controls->Add(Message);
			}
			UsersString = "";
		}
		
		/*else if (UsersInput->Text->Length < 102 && L'а' <= e->KeyChar && e->KeyChar <= L'я') {
			UsersInput->Text = UsersInput->Text->ToUpper();
			UsersInput->Select(UsersInput->Text->Length, 0);
		}*/
		else if ((!(L'а' <= e->KeyChar && e->KeyChar <= L'я') &&
				!(L'А' <= e->KeyChar && e->KeyChar <= L'Я') && e->KeyChar != 8
			&& e->KeyChar != 32) || UsersInput->Text->Length == 102) {
			e->Handled = true;
		}

	}
	
	private: System::Void Start_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Controls->Clear();
		this->Controls->Add(this->Header);
		this->Controls->Add(this->PreparingLine);
		Condition->Hide();
		PreparingLine->Show();
		this->Header->Text = Stage + L" Этап " + (CorrectInputs / 3 + 1) + L" Стадия." +
			L" Правильно введено: " + CorrectInputs % 3;
		this->Controls->Add(this->Message);
		this->Message->Text = "Приготовьтесь!";
		this->Message->ForeColor = System::Drawing::Color::White;
		Message->Show();
		for (int k = 19; k > 0;k -= 2) {
			this->PreparingLine->Text = gcnew System::String(LoadLine.substr(0, k).c_str());
			this->PreparingLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			Application::DoEvents();
			Sleep(100);
		}
		OutputGenWord();
	}



};

	


}




