/***************************************************************
 * Name:      lista1Main.h
 * Purpose:   Defines Application Frame
 * Author:    Ciro ()
 * Created:   2017-09-18
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#ifndef LISTA1MAIN_H
#define LISTA1MAIN_H

//(*Headers(lista1Frame)
#include <wx/listctrl.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class lista1Frame: public wxFrame
{
    public:

        lista1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~lista1Frame();

    private:

        //(*Handlers(lista1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnTextCtrl6Text(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)
        void OnInserir(wxCommandEvent& event);
        void OnDeletar(wxCommandEvent& event);
        void OnBuscar(wxCommandEvent& event);

        //(*Identifiers(lista1Frame)
        static const long ID_LISTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuInserir;
        static const long idMenuDeletar;
        static const long idMenuBuscar;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(lista1Frame)
        wxTextCtrl* TextCtrl4;
        wxListCtrl* ListCtrl1;
        wxButton* Button4;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl6;
        wxMenuItem* MenuItem4;
        wxStaticText* StaticText8;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxMenuItem* MenuItem3;
        wxButton* Button3;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl8;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl7;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl5;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LISTA1MAIN_H
