/***************************************************************
 * Name:      GerAfazeresMain.h
 * Purpose:   Defines Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-18
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#ifndef GERAFAZERESMAIN_H
#define GERAFAZERESMAIN_H

//(*Headers(GerAfazeresFrame)
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class GerAfazeresFrame: public wxFrame
{
    public:

        GerAfazeresFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GerAfazeresFrame();

    private:

        //(*Handlers(GerAfazeresFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(GerAfazeresFrame)
        static const long ID_LISTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GerAfazeresFrame)
        wxListCtrl* ListCtrl1;
        wxButton* Button1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GERAFAZERESMAIN_H
