#include "CadastraAfazer.h"

//(*InternalHeaders(CadastraAfazer)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(CadastraAfazer)
//*)

BEGIN_EVENT_TABLE(CadastraAfazer,wxDialog)
	//(*EventTable(CadastraAfazer)
	//*)
END_EVENT_TABLE()

CadastraAfazer::CadastraAfazer(wxWindow* parent)
{
	//(*Initialize(CadastraAfazer)
	wxXmlResource::Get()->LoadObject(this,parent,_T("CadastraAfazer"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	DatePickerCtrl1 = (wxDatePickerCtrl*)FindWindow(XRCID("ID_DATEPICKERCTRL1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));


	Connect(XRCID("ID_TEXTCTRL3"),wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CadastraAfazer::OnTextCtrl3Text);
	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CadastraAfazer::OnButton1Click);
	//*)


}

CadastraAfazer::~CadastraAfazer()
{
	//(*Destroy(CadastraAfazer)
	//*)
}

wxString CadastraAfazer::getPrioridade() {return prioridade;}

wxString CadastraAfazer::getData() {return data;}

wxString CadastraAfazer::getDescricao() {return descricao;}




void CadastraAfazer::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void CadastraAfazer::OnButton1Click(wxCommandEvent& event)
{
    prioridade = TextCtrl1->GetValue();
    data = DatePickerCtrl1->GetValue().Format("%d/%m/%Y");
    descricao = TextCtrl3->GetValue();

   this->Close(0);

}
