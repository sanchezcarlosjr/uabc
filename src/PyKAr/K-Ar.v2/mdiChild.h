//---------------------------------------------------------------------------
#ifndef mdiChildH
#define mdiChildH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ComCtrls.hpp>
//---------------------------------------------------------------------------
class TRichTextForm : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit;
private:	// User declarations
public:		// User declarations
	__fastcall TRichTextForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TRichTextForm *RichTextForm;
//---------------------------------------------------------------------------
#endif
