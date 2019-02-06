#ifndef CADASTRAAFAZER_H
#define CADASTRAAFAZER_H

//(*Headers(CadastraAfazer)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CadastraAfazer: public wxDialog
{
	public:

		CadastraAfazer(wxWindow* parent);
		virtual ~CadastraAfazer();
		wxString getPrioridade();
		wxString getData();
		wxString getDescricao();

		//(*Declarations(CadastraAfazer)
		wxDatePickerCtrl* DatePickerCtrl1;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(CadastraAfazer)
		//*)

	private:

		//(*Handlers(CadastraAfazer)
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)
		wxString prioridade;
		wxString data;
		wxString descricao;

		DECLARE_EVENT_TABLE()
};

#endif
