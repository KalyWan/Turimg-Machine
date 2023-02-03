// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TButton *s;
int pointer = 100;
AnsiString wordbut[200];
int state = 1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	StringGrid1->Cells[0][1] = "Q1";
	Tape(0);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button29Click(TObject *Sender)
{ // �������� � ����� �������
	int a = StringGrid1->RowCount;
	StringGrid1->Cells[0][a] = "Q" + IntToStr(a);
	StringGrid1->RowCount = a + 1;
}

// ---------------------------------------------------------------------------
void DeleteRowFromStringGrid(TStringGrid *Grid, int ARow) {
	// ������� �������� ������
	int count = Grid->RowCount; // ����� �����
	if (count - Grid->FixedRows <= 1)
		return; // ��������� �� ������� ���� ���� ������
	// --------------------------- ������� ������ ����� ------------------------
	for (ARow; ARow < count; ARow++) {
		Grid->Rows[ARow] = Grid->Rows[ARow + 1];
	}
	// -------------------------------------------------------------------------
	Grid->RowCount--;
	Grid->SetFocus();
}

// ----------------------------------------------------------------------------
void __fastcall TForm1::Button30Click(TObject *Sender) {
	// ������� �������� ������ 2
	int row = StringGrid1->Row;
	DeleteRowFromStringGrid(StringGrid1, row);
	RefreshGrid(StringGrid1);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button28Click(TObject *Sender) {
	// �������� � ������ �������
	StringGrid1->RowCount++;
	StringGrid1->MoveRow(StringGrid1->RowCount, 1);
	RefreshGrid(StringGrid1);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::RefreshGrid(TStringGrid *Grid) {
	// ���������� �������
	for (int i = 1; i <= Grid->RowCount; i++) {
		Grid->Cells[0][i] = "Q" + IntToStr(i);
	}
	if (Edit1->Text.Length() != 0) {
		for (int j = 2; j < Grid->ColCount; j++) {
			int c = j - 1;
			String str = Edit1->Text[c];
			Grid->Cells[j][0] = str;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender) {
	// ��������� ��������
	if (Edit1->Text.Length() != 0) {
		AnsiString str = Edit1->Text;
		int Length = str.Length();
		AnsiString last = str[Length];
		for (int i = 1; i < Length; i++) {
			if (last == Edit1->Text[i]) {
				Edit1->Text = Edit1->Text.Delete(Edit1->Text.Length(), 1);
				Edit1->SelStart = Edit1->Text.Length();
			}
		}
	}
	if (StringGrid1->ColCount > 2) {
		StringGrid1->Cols[StringGrid1->ColCount - 1]->Clear();
	}
	StringGrid1->ColCount = Edit1->Text.Length() + 2;
	RefreshGrid(StringGrid1);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender) {
	s = (TButton*)Sender; // ����������� ������� �� ������
	Form2->Position = poOwnerFormCenter;
	Form2->Show();
	Form2->ComboBox1->Clear();
	Form2->ComboBox1->Items->Add("None");
	Form2->ComboBox1->ItemIndex = 0;
	for (int i = 1; i < Edit1->Text.Length() + 1; i++) {
		// ���������� ������ �������
		Form2->ComboBox1->Items->Add(Edit1->Text[i]);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
	delete s;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Tape(int par) {
	// ���������� �����
	TButton *but[] = {
		Button3, Button4, Button5, Button6, Button7, Button8, Button9, Button10,
		Button11, Button12, Button13, Button14, Button15, Button16, Button17,
		Button18, Button19, Button20, Button21, Button22, Button23, Button24,
		Button25, Button26, Button27};
	Memo1->Lines->Clear();
	int j = 0;
	if (par == 0) {
		for (int i = pointer; i < pointer + 25; i++) {
			wordbut[i] = but[j]->Caption;
			j++;

		}
	}
	if (par == 1) {
		for (int i = pointer; i < pointer + 25; i++) {
			but[j]->Caption = wordbut[i];
			j++;

		}
	}
	if (par == 2) {
		for (int i = 1; i < 200; i++) {
			wordbut[i] = "";
		}
		for (int j = 0; j < 25; j++) {
			but[j]->Caption = "";
		}
		pointer = 100;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	// ������ �����
	if (pointer != 172) {
		pointer++;
		Tape(1);
	}
	else {
		ShowMessage("����������� �����");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	// ������ ������
	if (pointer != 28) {
		pointer--;
		Tape(1);
	}
	else {
		ShowMessage("����������� �����");
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender) {
	// ������� ��������
	N7->Checked = false;
	N8->Checked = false;
	N6->Checked = true;
	Timer1->Interval = 500;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender) {
	// ������� ��������
	N6->Checked = false;
	N8->Checked = false;
	N7->Checked = true;
	Timer1->Interval = 200;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender) {
	// ��������� ��������
	N7->Checked = false;
	N6->Checked = false;
	N8->Checked = true;
	Timer1->Interval = 900;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	Logic();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Logic() {

	for (int i = 1; i < StringGrid1->ColCount; i++) {
		if (wordbut[pointer + 12] == StringGrid1->Cells[i][0]) {
			AnsiString temp = StringGrid1->Cells[i][state];
			if (temp == "") {
				Timer1->Enabled = false;
				MessageBox(NULL, L"� ������ ����������� �������", L"������",
					MB_OK | MB_ICONERROR);

				return;
			}
			else {

				if (temp.Pos("<") == 0 && temp.Pos(">") == 0 && temp.Pos
					(".") == 0) {
					Timer1->Enabled = false;
					MessageBox(NULL, L"� ������ ����������� ���������� < ��� >",
						L"������", MB_OK | MB_ICONERROR);

					return;
				}
				else {
					if (temp.SubString(3, 1) > StringGrid1->RowCount - 1 ||
						temp.SubString(3, 1) < 0 || temp.SubString(3, 1) == "")
					{
						Timer1->Enabled = false;
						MessageBox(NULL, L"�� ���������� ������ ���������",
							L"������", MB_OK | MB_ICONERROR);

						return;
					}
					else {
						// �������� �� ����.������ � ������
						if (temp.Pos("<")) {
							if (temp.SubString(1, 1) == "_") {
								wordbut[pointer + 12] = "";
							}
							else {
								wordbut[pointer + 12] = temp.SubString(1, 1);
							}
							Tape(1);
							state = StrToInt(temp.SubString(3, 1));
							if (pointer != 28) {
								pointer--;
								Tape(1);
								i = 1;
							}
							else {
								Timer1->Enabled = false;
								ShowMessage("����������� �����");

							}
						}
						if (temp.Pos(">")) {
							if (temp.SubString(1, 1) == "_") {
								wordbut[pointer + 12] = "";
							}
							else {
								wordbut[pointer + 12] = temp.SubString(1, 1);
							}
							Tape(1);
							state = StrToInt(temp.SubString(3, 1));
							if (pointer != 172) {
								pointer++;
								Tape(1);
								i = 1;
							}
							else {
								Timer1->Enabled = false;
								ShowMessage("����������� �����");
							}
						}
						if (temp.Pos(".")) {
							if (temp.SubString(1, 1) == "_") {
								wordbut[pointer + 12] = "";

							}
							else {
								wordbut[pointer + 12] = temp.SubString(1, 1);
							}
							Tape(1);
							state = StrToInt(temp.SubString(3, 1));
						}
						// ���� � ������ ��������� ����� 0, ��������� ���������
						if (temp.SubString(3, 1) == 0) {
							Timer1->Enabled = false;
							MessageBox(NULL, L"���������� ��������� ���������",
								L"����������", MB_OK | MB_ICONASTERISK);
							return;
						}
						break;
					}
				}
			}
		}
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender) {
	state = 1;
	Timer1->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender) {
	state = 1;
	Timer1->Enabled = false;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender) {
	Logic();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender) {
	// ������ �������� �����
	for (int i = 1; i < StringGrid1->ColCount; i++)
		for (int j = 1; j < StringGrid1->RowCount; j++)
			StringGrid1->Cells[i][j] = "";
	Edit1->Text = "";
	for (int i = StringGrid1->RowCount; i > 1; i--) {
		DeleteRowFromStringGrid(StringGrid1, i);
	}
	StringGrid1->Cells[1][1] = "";
	RefreshGrid(StringGrid1);
	Tape(2);
	Memo1->Lines->Clear();
	Memo2->Lines->Clear();
	state = 1;

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender) {
	// ������ �������� �������
	for (int i = 1; i < StringGrid1->ColCount; i++)
		for (int j = 1; j < StringGrid1->RowCount; j++)
			StringGrid1->Cells[i][j] = "";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender) {
	// �������
	Form3->Position = poOwnerFormCenter;
	Form3->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender) {
	// � ������
	Form4->Position = poOwnerFormCenter;
	Form4->Show();
}
// ---------------------------------------------------------------------------
