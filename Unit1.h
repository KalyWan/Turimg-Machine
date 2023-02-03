// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Mask.hpp>

// ---------------------------------------------------------------------------
namespace SG {
	class TStringGrid : public Grids::TStringGrid {
	public:
		using Grids::TStringGrid::MoveRow;
		using Grids::TStringGrid::MoveColumn;
		using Grids::TStringGrid::DeleteColumn;
	};
};
#define TStringGrid SG::TStringGrid

class TForm1 : public TForm {
__published: // IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TButton *Button1;
	TButton *Button2;
	TPanel *Panel4;
	TPanel *Panel5;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TButton *Button25;
	TButton *Button26;
	TButton *Button27;
	TPanel *Panel6;
	TPanel *Panel7;
	TStringGrid *StringGrid1;
	TPanel *Panel8;
	TMemo *Memo1;
	TLabel *Label1;
	TMemo *Memo2;
	TLabel *Label2;
	TButton *Button28;
	TButton *Button29;
	TButton *Button30;
	TPanel *Panel9;
	TPanel *Panel10;
	TLabel *Label3;
	TEdit *Edit1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TImage *Image1;
	TTimer *Timer1;
	TMenuItem *N9;
	TButton *Button31;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Button28Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);

private: // User declarations
	void __fastcall Logic();
public: // User declarations
	void __fastcall Tape(int par);
	void __fastcall RefreshGrid(TStringGrid *Grid);
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
