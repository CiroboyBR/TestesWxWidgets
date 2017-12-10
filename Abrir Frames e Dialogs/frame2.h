#ifndef FRAME2_H
#define FRAME2_H

//(*Headers(frame2)
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class frame2: public wxFrame
{
	public:

		frame2(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~frame2();

		//(*Declarations(frame2)
		wxButton* Button1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(frame2)
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		//*)

	private:

		//(*Handlers(frame2)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
