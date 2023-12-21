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
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

string Reverse(string);
vector <string> Split(string);

bool InputCheckSecondStep(vector<string>, vector <string>);
bool InputCheckThirdStep(vector<string>, vector <string>);
bool InputCheckForthStep(vector<string>, vector <string>);
bool InputCheckFifthStep(vector<string>, vector <string>);

void Creating();
void OutputGenWord();
void ReadFiles();

namespace MemoryTrain {

	
	const int TotalWordsCount = 5;
	const string LoadLine{ "--------------------" };

	int CorrectInputs{ 0 };

	int TimeMemory[5][2]{ {7000, 15000}, {5000, 10000}, {3000, 7000}, {1500, 5000}, {1000, 3000} };
	
	vector<vector<string>> ConstTotalWords(4);

	vector<vector<string>> PossibleWords;

	string WordsLine;
	string FirstStageWord{};

	vector<string> UsersWordsList{};
	vector<string> GeneratedWords{};

	bool CorrCheck{ false };

	vector<string> Cond{ "На экране на некоторое время отображается слово из 5 букв, а затем пропадает. Ваша задача ввести это же слово, но в обратном порядке. После выводится сообщение о верном или неверном вводе соответсвенно. Затем появляется новое слово с тем же количеством букв. После правильно введенных трех подряд верных 'перевернутых' слов начинают выводиться слова длинее на одну букву и так до тех пор, пока Вы не введете подряд три 'перевернутых' 8 буквенных слова. На этом этап 1 завершается.",
		"На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Вам необходимо ввести эти же слова в произвольном порядке. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться последовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов.", 
		"На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Однако, в отличие от второго этапа, на третьем Вам необходимо ввести эти же слова в том же порядке, в котором они были Вам показаны. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться последовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов.", 
		"Четвертый этап является смесью первого и второго. На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Вам необходимо ввести эти же слова в произвольном порядке, однако сами слова должны быть 'перевернуты'. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться последовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов.", 
		"Пятый этап - слияние первого и третьего. На экране на некоторое время отображается последовательность из 5 различных слов, а затем пропадает. Вам необходимо ввести эти же слова в том же порядке, в котором они были Вам показаны, и они так же должны быть 'перевернуты'. Затем появляется новая последовательность из других 5 слов. После правильно введенных трех подряд последовательностей из 5 слов начинают выводиться последовательности из 6 слов и так до тех пор, пока Вы не введете подряд три правильных последовательности из 8 слов."};

	public ref class MemoryTrain : public System::Windows::Forms::Form
	{
	public:
		MemoryTrain(void)
		{
			ReadFiles();
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

	void ReadFiles() {
		
		fstream file;
		string Word;
		for (int i = 0;i < 4;i++) {
			ConstTotalWords[i].resize(100);
			switch (i) {
				case 0:
					file.open("5_letters.txt");
					for (int j = 0;!file.eof();getline(file, Word), ConstTotalWords[i][j++] = Word.substr(0, 5 + i));
					break;
				case 1:
					file.open("6_letters.txt");
					for (int j = 0;!file.eof();getline(file, Word), ConstTotalWords[i][j++] = Word.substr(0, 5 + i));
					break;
				case 2:
					file.open("7_letters.txt");
					for (int j = 0;!file.eof();getline(file, Word), ConstTotalWords[i][j++] = Word.substr(0, 5 + i));
					break;
				case 3:
					file.open("8_letters.txt");
					for (int j = 0;!file.eof();getline(file, Word), ConstTotalWords[i][j++] = Word.substr(0, 5 + i));
					break;
			}
			file.close();
		}
		PossibleWords = ConstTotalWords;
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
					GenWords[j] = "";
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
					GenWords[j] = "";
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
			this->Message = (gcnew System::Windows::Forms::Label());
			this->Header = (gcnew System::Windows::Forms::Label());
			this->Condition = (gcnew System::Windows::Forms::Label());
			this->PreparingLine = (gcnew System::Windows::Forms::Label());
			this->GenLine = (gcnew System::Windows::Forms::Label());
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
			this->UsersInput = (gcnew System::Windows::Forms::RichTextBox());
			this->HardLevelList->SuspendLayout();
			this->NumStageList->SuspendLayout();
			this->SuspendLayout();
			// 
			// Message
			// 
			this->Message->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Message->Font = (gcnew System::Drawing::Font(L"Roboto", 20));
			this->Message->ForeColor = System::Drawing::Color::Black;
			this->Message->Location = System::Drawing::Point(0, 0);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(100, 23);
			this->Message->TabIndex = 20;
			this->Message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Header
			// 
			this->Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->Header->Dock = System::Windows::Forms::DockStyle::Top;
			this->Header->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Header->ForeColor = System::Drawing::Color::White;
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(699, 100);
			this->Header->TabIndex = 0;
			this->Header->Text = L"Выберите уровень сложности и желаемый этап";
			this->Header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Condition
			// 
			this->Condition->Font = (gcnew System::Drawing::Font(L"Roboto", 16));
			this->Condition->ForeColor = System::Drawing::Color::Black;
			this->Condition->Location = System::Drawing::Point(25, 70);
			this->Condition->Name = L"Condition";
			this->Condition->Size = System::Drawing::Size(650, 300);
			this->Condition->TabIndex = 0;
			// 
			// PreparingLine
			// 
			this->PreparingLine->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->PreparingLine->Font = (gcnew System::Drawing::Font(L"Roboto", 50));
			this->PreparingLine->ForeColor = System::Drawing::Color::Black;
			this->PreparingLine->Location = System::Drawing::Point(0, 0);
			this->PreparingLine->Name = L"PreparingLine";
			this->PreparingLine->Size = System::Drawing::Size(700, 50);
			this->PreparingLine->TabIndex = 0;
			this->PreparingLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GenLine
			// 
			this->GenLine->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GenLine->Font = (gcnew System::Drawing::Font(L"Roboto", 30, System::Drawing::FontStyle::Bold));
			this->GenLine->ForeColor = System::Drawing::Color::Black;
			this->GenLine->Location = System::Drawing::Point(0, 0);
			this->GenLine->Name = L"GenLine";
			this->GenLine->Size = System::Drawing::Size(100, 23);
			this->GenLine->TabIndex = 0;
			this->GenLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GenLine->Enabled = false;
			// 
			// CheckedLine
			// 
			this->CheckedLine->AutoSize = true;
			this->CheckedLine->Dock = System::Windows::Forms::DockStyle::Top;
			this->CheckedLine->Font = (gcnew System::Drawing::Font(L"Roboto", 20));
			this->CheckedLine->ForeColor = System::Drawing::Color::Black;
			this->CheckedLine->Location = System::Drawing::Point(0, 0);
			this->CheckedLine->MaximumSize = System::Drawing::Size(700, 300);
			this->CheckedLine->MinimumSize = System::Drawing::Size(700, 100);
			this->CheckedLine->Name = L"CheckedLine";
			this->CheckedLine->Size = System::Drawing::Size(700, 100);
			this->CheckedLine->TabIndex = 19;
			this->CheckedLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HardLevel1
			// 
			this->HardLevel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->HardLevel1->Checked = true;
			this->HardLevel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->HardLevel1->FlatAppearance->BorderSize = 0;
			this->HardLevel1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->HardLevel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->HardLevel1->Location = System::Drawing::Point(7, 44);
			this->HardLevel1->Name = L"HardLevel1";
			this->HardLevel1->Size = System::Drawing::Size(141, 34);
			this->HardLevel1->TabIndex = 4;
			this->HardLevel1->TabStop = true;
			this->HardLevel1->Text = L"1 Уровень";
			this->HardLevel1->UseVisualStyleBackColor = false;
			this->HardLevel1->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel2
			// 
			this->HardLevel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->HardLevel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel2->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel2->FlatAppearance->BorderSize = 0;
			this->HardLevel2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->HardLevel2->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel2->Location = System::Drawing::Point(7, 91);
			this->HardLevel2->Name = L"HardLevel2";
			this->HardLevel2->Size = System::Drawing::Size(141, 34);
			this->HardLevel2->TabIndex = 5;
			this->HardLevel2->Text = L"2 Уровень";
			this->HardLevel2->UseVisualStyleBackColor = false;
			this->HardLevel2->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel3
			// 
			this->HardLevel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->HardLevel3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel3->FlatAppearance->BorderSize = 0;
			this->HardLevel3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->HardLevel3->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel3->Location = System::Drawing::Point(7, 138);
			this->HardLevel3->Name = L"HardLevel3";
			this->HardLevel3->Size = System::Drawing::Size(141, 34);
			this->HardLevel3->TabIndex = 6;
			this->HardLevel3->Text = L"3 Уровень";
			this->HardLevel3->UseVisualStyleBackColor = false;
			this->HardLevel3->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel4
			// 
			this->HardLevel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->HardLevel4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel4->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel4->FlatAppearance->BorderSize = 0;
			this->HardLevel4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->HardLevel4->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel4->Location = System::Drawing::Point(7, 184);
			this->HardLevel4->Name = L"HardLevel4";
			this->HardLevel4->Size = System::Drawing::Size(141, 34);
			this->HardLevel4->TabIndex = 7;
			this->HardLevel4->Text = L"4 Уровень";
			this->HardLevel4->UseVisualStyleBackColor = false;
			this->HardLevel4->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// HardLevel5
			// 
			this->HardLevel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->HardLevel5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HardLevel5->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->HardLevel5->FlatAppearance->BorderSize = 0;
			this->HardLevel5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->HardLevel5->ForeColor = System::Drawing::Color::AliceBlue;
			this->HardLevel5->Location = System::Drawing::Point(7, 231);
			this->HardLevel5->Name = L"HardLevel5";
			this->HardLevel5->Size = System::Drawing::Size(141, 34);
			this->HardLevel5->TabIndex = 8;
			this->HardLevel5->Text = L"5 Уровень";
			this->HardLevel5->UseVisualStyleBackColor = false;
			this->HardLevel5->Click += gcnew System::EventHandler(this, &MemoryTrain::HardLevel_CheckedChanged);
			// 
			// Stage1
			// 
			this->Stage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Stage1->Checked = true;
			this->Stage1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Stage1->FlatAppearance->BorderSize = 0;
			this->Stage1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->Stage1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Stage1->Location = System::Drawing::Point(7, 44);
			this->Stage1->Name = L"Stage1";
			this->Stage1->Size = System::Drawing::Size(141, 34);
			this->Stage1->TabIndex = 9;
			this->Stage1->TabStop = true;
			this->Stage1->Text = L"1 Этап";
			this->Stage1->UseVisualStyleBackColor = false;
			this->Stage1->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage2
			// 
			this->Stage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Stage2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage2->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Stage2->FlatAppearance->BorderSize = 0;
			this->Stage2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->Stage2->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage2->Location = System::Drawing::Point(7, 91);
			this->Stage2->Name = L"Stage2";
			this->Stage2->Size = System::Drawing::Size(141, 34);
			this->Stage2->TabIndex = 10;
			this->Stage2->Text = L"2 Этап";
			this->Stage2->UseVisualStyleBackColor = false;
			this->Stage2->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage3
			// 
			this->Stage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Stage3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Stage3->FlatAppearance->BorderSize = 0;
			this->Stage3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->Stage3->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage3->Location = System::Drawing::Point(7, 138);
			this->Stage3->Name = L"Stage3";
			this->Stage3->Size = System::Drawing::Size(141, 34);
			this->Stage3->TabIndex = 11;
			this->Stage3->Text = L"3 Этап";
			this->Stage3->UseVisualStyleBackColor = false;
			this->Stage3->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage4
			// 
			this->Stage4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Stage4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage4->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Stage4->FlatAppearance->BorderSize = 0;
			this->Stage4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->Stage4->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage4->Location = System::Drawing::Point(7, 184);
			this->Stage4->Name = L"Stage4";
			this->Stage4->Size = System::Drawing::Size(141, 34);
			this->Stage4->TabIndex = 12;
			this->Stage4->Text = L"4 Этап";
			this->Stage4->UseVisualStyleBackColor = false;
			this->Stage4->Click += gcnew System::EventHandler(this, &MemoryTrain::NumStage_CheckedChanged);
			// 
			// Stage5
			// 
			this->Stage5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Stage5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stage5->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Stage5->FlatAppearance->BorderSize = 0;
			this->Stage5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F));
			this->Stage5->ForeColor = System::Drawing::Color::AliceBlue;
			this->Stage5->Location = System::Drawing::Point(7, 231);
			this->Stage5->Name = L"Stage5";
			this->Stage5->Size = System::Drawing::Size(141, 34);
			this->Stage5->TabIndex = 13;
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
			this->HardLevelList->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HardLevelList->ForeColor = System::Drawing::Color::Black;
			this->HardLevelList->Location = System::Drawing::Point(21, 184);
			this->HardLevelList->Name = L"HardLevelList";
			this->HardLevelList->Size = System::Drawing::Size(233, 288);
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
			this->NumStageList->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumStageList->ForeColor = System::Drawing::Color::Black;
			this->NumStageList->Location = System::Drawing::Point(267, 184);
			this->NumStageList->Name = L"NumStageList";
			this->NumStageList->Size = System::Drawing::Size(201, 288);
			this->NumStageList->TabIndex = 16;
			this->NumStageList->TabStop = false;
			this->NumStageList->Text = L"Номер Этапа";
			// 
			// Confirm
			// 
			this->Confirm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Confirm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Confirm->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Confirm->FlatAppearance->BorderSize = 2;
			this->Confirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Confirm->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.25F));
			this->Confirm->ForeColor = System::Drawing::Color::AliceBlue;
			this->Confirm->Location = System::Drawing::Point(501, 434);
			this->Confirm->Name = L"Confirm";
			this->Confirm->Size = System::Drawing::Size(189, 38);
			this->Confirm->TabIndex = 17;
			this->Confirm->Text = L"Подтвердить";
			this->Confirm->UseVisualStyleBackColor = false;
			this->Confirm->Click += gcnew System::EventHandler(this, &MemoryTrain::Confirm_CheckedChanged);
			// 
			// Start
			// 
			this->Start->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Start->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Start->FlatAppearance->BorderSize = 2;
			this->Start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Start->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18.25F));
			this->Start->ForeColor = System::Drawing::Color::AliceBlue;
			this->Start->Location = System::Drawing::Point(350, 460);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(350, 40);
			this->Start->TabIndex = 0;
			this->Start->Text = L"Начать";
			this->Start->UseVisualStyleBackColor = false;
			this->Start->Click += gcnew System::EventHandler(this, &MemoryTrain::Start_CheckedChanged);
			// 
			// Continue
			// 
			this->Continue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Continue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Continue->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Continue->FlatAppearance->BorderSize = 2;
			this->Continue->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Continue->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18.25F));
			this->Continue->ForeColor = System::Drawing::Color::AliceBlue;
			this->Continue->Location = System::Drawing::Point(350, 460);
			this->Continue->Name = L"Continue";
			this->Continue->Size = System::Drawing::Size(350, 40);
			this->Continue->TabIndex = 22;
			this->Continue->Text = L"Продолжить";
			this->Continue->UseVisualStyleBackColor = false;
			this->Continue->Click += gcnew System::EventHandler(this, &MemoryTrain::Continue_CheckedChanged);
			// 
			// Home
			// 
			this->Home->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)));
			this->Home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Home->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Home->FlatAppearance->BorderSize = 2;
			this->Home->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Home->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18.25F));
			this->Home->ForeColor = System::Drawing::Color::AliceBlue;
			this->Home->Location = System::Drawing::Point(0, 460);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(350, 40);
			this->Home->TabIndex = 21;
			this->Home->Text = L"Главное меню";
			this->Home->UseVisualStyleBackColor = false;
			this->Home->Click += gcnew System::EventHandler(this, &MemoryTrain::Home_CheckedChanged);
			// 
			// UsersInput
			// 
			this->UsersInput->BackColor = System::Drawing::Color::FromArgb(104, 138, 144);
			this->UsersInput->Font = (gcnew System::Drawing::Font(L"Roboto", 20));
			this->UsersInput->ForeColor = System::Drawing::Color::White;
			this->UsersInput->Location = System::Drawing::Point(25, 150);
			this->UsersInput->Name = L"UsersInput";
			this->UsersInput->Size = System::Drawing::Size(650, 250);
			this->UsersInput->TabIndex = 18;
			this->UsersInput->Text = L"";
			this->UsersInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MemoryTrain::UsersInput_KeyPress);
			// 
			// MemoryTrain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(699, 500);
			this->MaximizeBox = false;
			this->Controls->Add(this->Confirm);
			this->Controls->Add(this->NumStageList);
			this->Controls->Add(this->HardLevelList);
			this->Controls->Add(this->Header);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Roboto", 0.25F));
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

		int Num;
		int Letters;
		switch (Stage) {
		case 1:
			GeneratedWords.resize(1);
			Letters = CorrectInputs / 3;
			Num = rand() % (PossibleWords[Letters].size());

			GeneratedWords[0] = PossibleWords[Letters][Num];
			WordsLine = GeneratedWords[0];

			for (int i = Num; i < PossibleWords[Letters].size() - 1;PossibleWords[Letters][i] = PossibleWords[Letters][i + 1], i++);
			PossibleWords[Letters].pop_back();


			break;
		case 2:
		case 3:
		case 4:
		case 5:
			WordsLine = {};
			GeneratedWords.resize(5 + CorrectInputs / 3);

			for (int i = 0;i < TotalWordsCount + CorrectInputs / 3; i++){
				Letters = rand() % (4);
				Num = rand() % (PossibleWords[Letters].size());

				GeneratedWords[i] = PossibleWords[Letters][Num];

				for (int j = Num; j < PossibleWords[Letters].size() - 1;PossibleWords[Letters][j] = PossibleWords[Letters][j + 1], j++);
				PossibleWords[Letters].pop_back();

				WordsLine += GeneratedWords[i] + ' ';
			}
			break;
		}

	}
	private: void OutputGenWord() {
		this->Controls->Clear();
		Creating();
		this->Header->Text = Stage + L" Этап " + (CorrectInputs / 3 + 1) + L" Стадия." +
			L" Правильно введено: " + CorrectInputs % 3;
		this->GenLine->Text = L"";
		this->GenLine->Text = gcnew System::String(WordsLine.c_str());
		this->Controls->Add(this->GenLine);
		this->GenLine->Show();

		this->Controls->Add(this->PreparingLine);
		this->PreparingLine->Show();
		this->Controls->Add(this->Header);
		for (int k = 19; k > 0;k -= 2) {
			this->PreparingLine->Text = gcnew System::String(LoadLine.substr(0, k).c_str());

			Application::DoEvents();
			if (this->GenLine->Text->Length <= 8) Sleep(TimeMemory[HardLevel][0] / 10);
			else Sleep(TimeMemory[HardLevel][1] / 10);
		}

		this->GenLine->Hide();
		this->PreparingLine->Hide();

		this->Controls->Add(this->UsersInput);
		this->UsersInput->Text = L"";
		this->UsersInput->Show();
		this->UsersInput->Enabled = true;
		this->UsersInput->Focus();

	}
	private: void OutputCond() {
		Controls->Clear();

		this->Header->Text = L"Правила " + (Stage)+L" этапа";
		this->Header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->Header->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 20, System::Drawing::FontStyle::Bold));

		this->Condition->Text = gcnew System::String(Cond[Stage - 1].c_str());
		this->Condition->Show();
		this->Controls->Add(this->Header);
		this->Controls->Add(this->Condition);
		this->Controls->Add(this->Home);
		this->Controls->Add(this->Start);

	}

	private: System::Void HardLevel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->HardLevel1->ForeColor = System::Drawing::Color::AliceBlue;
		this->HardLevel2->ForeColor = System::Drawing::Color::AliceBlue;
		this->HardLevel3->ForeColor = System::Drawing::Color::AliceBlue;
		this->HardLevel4->ForeColor = System::Drawing::Color::AliceBlue;
		this->HardLevel5->ForeColor = System::Drawing::Color::AliceBlue;
		RadioButton^ radiobutton = safe_cast<RadioButton^>(sender);
		radiobutton->ForeColor = System::Drawing::Color::FromArgb(178, 255, 255);
		this->HardLevel = radiobutton->Text[0] - 49;
	}
	private: System::Void NumStage_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Stage1->ForeColor = System::Drawing::Color::AliceBlue;
		this->Stage2->ForeColor = System::Drawing::Color::AliceBlue;
		this->Stage3->ForeColor = System::Drawing::Color::AliceBlue;
		this->Stage4->ForeColor = System::Drawing::Color::AliceBlue;
		this->Stage5->ForeColor = System::Drawing::Color::AliceBlue;
		RadioButton^ radiobutton = safe_cast<RadioButton^>(sender);
		radiobutton->ForeColor = System::Drawing::Color::FromArgb(178, 255, 255);
		this->Stage = radiobutton->Text[0] - 48;
	}
	private: System::Void Confirm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Header->Size = System::Drawing::Size(700, 50);
		this->Header->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 20, System::Drawing::FontStyle::Bold));
		OutputCond();
	}
	private: System::Void Home_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Home->Size = System::Drawing::Size(350, 40);
		Stage = 1;
		HardLevel = 1;
		CorrectInputs = 0;
		this->Controls->Clear();
		InitializeComponent();
	}
	
	private: System::Void Continue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		CorrectInputs = (CorrectInputs / 3) * 3;
		OutputGenWord();
	}

	private: System::Void UsersInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		
		if (this->UsersInput->Text->Length >= 102) {
			e->Handled = true;
			this->UsersInput->Text = this->UsersInput->Text->Substring(0,102);
			this->UsersInput->Select(this->UsersInput->Text->Length, 0);
		}
		if (e->KeyChar == 13) {

			e->Handled = true;
			this->CheckedLine->Text = L"";
			this->UsersInput->Enabled = false;
			this->UsersInput->Select(this->UsersInput->Text->Length, 0);
			this->UsersInput->Text = this->UsersInput->Text->ToUpper();
			string UsersString{};

			for (int i = 0; i < this->UsersInput->Text->Length; i++)
				if (this->UsersInput->Text[i] == 32) UsersString += this->UsersInput->Text[i];
				else  if (UsersInput->Text[i] != '\n') UsersString += this->UsersInput->Text[i] - 848;
			
			gcnew System::String(UsersString.c_str());

			this->UsersInput->Hide();
			this->Controls->Add(this->CheckedLine);
			this->Controls->Add(this->Header);

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

				this->Message->ForeColor = System::Drawing::Color::FromArgb(30, 155, 30);
				this->Message->Text = gcnew System::String(UsersString.c_str()) + L"\n\nВЕРНО!";
				this->Controls->Add(Message);

				this->PreparingLine->Show();
				for (int k = 19; k > 0;k -= 2) {
					this->PreparingLine->Text = gcnew System::String(LoadLine.substr(0, k).c_str());
				
					Application::DoEvents();
					Sleep(100);
				}

				CorrectInputs++;
				if (CorrectInputs == 12) {
					CorrectInputs = 0;
					
					PossibleWords = ConstTotalWords;

					Stage++;
					if (Stage <= 5) OutputCond();

					else {
						this->CheckedLine->Hide();
						this->PreparingLine->Hide();
						this->Message->ForeColor = System::Drawing::Color::Black;
						this->Message->Text = L"Вы завершили последний пятый этап. Пройдите обратно на начальную страницу или закройте программу.";
						
						this->Home->Size = System::Drawing::Size(700,40);

						this->Controls->Add(this->Home);
						this->Controls->Add(this->Message);
						this->Home->Show();
						this->Message->Show();

					}
				}
				else OutputGenWord();
			}

			else {
				PossibleWords = ConstTotalWords;

				this->CheckedLine->Text = this->GenLine->Text;
				this->Message->ForeColor = System::Drawing::Color::FromArgb(155, 30, 30);
				this->Message->Text = L"\n\n" + gcnew System::String(UsersString.c_str()) + L"\n\n" + L"ВЫ ОШИБЛИСЬ!";
				this->Controls->Add(this->Home);
				this->Controls->Add(this->Continue);
				this->Controls->Add(this->Message);
			}
			UsersString = "";
		}
		
		else if ((!(L'а' <= e->KeyChar && e->KeyChar <= L'я') &&
				!(L'А' <= e->KeyChar && e->KeyChar <= L'Я') && e->KeyChar != 8
			&& e->KeyChar != 32)) {
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
		this->Message->ForeColor = System::Drawing::Color::Black;
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




