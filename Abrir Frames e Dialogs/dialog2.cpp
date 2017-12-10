#include "dialog2.h"

//(*InternalHeaders(dialog2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dialog2)
const long dialog2::ID_TEXTCTRL1 = wxNewId();
const long dialog2::ID_TEXTCTRL2 = wxNewId();
const long dialog2::ID_TEXTCTRL3 = wxNewId();
const long dialog2::ID_STATICTEXT1 = wxNewId();
const long dialog2::ID_STATICTEXT2 = wxNewId();
const long dialog2::ID_STATICTEXT3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dialog2,wxDialog)
	//(*EventTable(dialog2)
	//*)
END_EVENT_TABLE()

dialog2::dialog2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(dialog2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(676,450));
	Move(wxDefaultPosition);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(112,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(112,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxPoint(112,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("NOME:"), wxPoint(72,68), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("CPF:"), wxPoint(80,108), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("RG:"), wxPoint(80,148), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	//*)
}

dialog2::~dialog2()
{
	//(*Destroy(dialog2)
	//*)
}

