/***************************************************************
 * Name:      ContaGrupos32bitsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ciro ()
 * Created:   2017-09-06
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#ifndef CONTAGRUPOS32BITSMAIN_H
#define CONTAGRUPOS32BITSMAIN_H

//(*Headers(ContaGrupos32bitsFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/html/htmprint.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class ContaGrupos32bitsFrame: public wxFrame
{
    public:

        ContaGrupos32bitsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ContaGrupos32bitsFrame();

    private:

        //(*Handlers(ContaGrupos32bitsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(ContaGrupos32bitsFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEMIMPRIMIR;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ContaGrupos32bitsFrame)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxButton* Button2;
        wxHtmlEasyPrinting* HtmlEasyPrinting1;
        wxMenuItem* MenuItem3;
        wxButton* Button3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CONTAGRUPOS32BITSMAIN_H
