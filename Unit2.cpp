// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
AnsiString word;
extern TButton *s;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender) {
	word = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
	if (word != "None") {
		s->Caption = word;
		Form1->Tape(0);
	}
	else {
		s->Caption = "";
		Form1->Tape(0);
	}
	Form2->Close();

}
// ---------------------------------------------------------------------------
