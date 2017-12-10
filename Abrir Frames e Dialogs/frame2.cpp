#include "frame2.h"

//(*InternalHeaders(frame2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(frame2)
const long frame2::ID_BUTTON1 = wxNewId();
const long frame2::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frame2,wxFrame)
	//(*EventTable(frame2)
	//*)
END_EVENT_TABLE()

frame2::frame2(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(frame2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Abrir outro frame"), wxPoint(136,128), wxSize(102,56), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Outro frame"), wxPoint(152,32), wxDefaultSize, 0, _T("ID_STATICTEXT1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frame2::OnButton1Click);
	//*)
}

frame2::~frame2()
{
	//(*Destroy(frame2)
	//*)
}


void frame2::OnButton1Click(wxCommandEvent& event)
{
    frame2 *f = new frame2(0);

    f->Show();
}
