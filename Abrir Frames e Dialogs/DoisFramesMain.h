/***************************************************************
 * Name:      DoisFramesMain.h
 * Purpose:   Defines Application Frame
 * Author:    CiroboyBR ()
 * Created:   2017-11-03
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#ifndef DOISFRAMESMAIN_H
#define DOISFRAMESMAIN_H

//(*Headers(DoisFramesFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class DoisFramesFrame: public wxFrame
{
    public:

        DoisFramesFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~DoisFramesFrame();

    private:

        //(*Handlers(DoisFramesFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(DoisFramesFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(DoisFramesFrame)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DOISFRAMESMAIN_H
