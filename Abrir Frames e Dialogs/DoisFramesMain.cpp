/***************************************************************
 * Name:      DoisFramesMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    CiroboyBR ()
 * Created:   2017-11-03
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "DoisFramesMain.h"
#include <wx/msgdlg.h>
#include "frame2.h"
#include "dialog2.h"

//(*InternalHeaders(DoisFramesFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(DoisFramesFrame)
const long DoisFramesFrame::ID_STATICTEXT1 = wxNewId();
const long DoisFramesFrame::ID_BUTTON1 = wxNewId();
const long DoisFramesFrame::ID_BUTTON2 = wxNewId();
const long DoisFramesFrame::idMenuQuit = wxNewId();
const long DoisFramesFrame::idMenuAbout = wxNewId();
const long DoisFramesFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DoisFramesFrame,wxFrame)
    //(*EventTable(DoisFramesFrame)
    //*)
END_EVENT_TABLE()

DoisFramesFrame::DoisFramesFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DoisFramesFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(413,457));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxPoint(152,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("frame2"), wxPoint(128,96), wxSize(160,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Dialog"), wxPoint(128,168), wxSize(160,48), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DoisFramesFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DoisFramesFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DoisFramesFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DoisFramesFrame::OnAbout);
    //*)
}

DoisFramesFrame::~DoisFramesFrame()
{
    //(*Destroy(DoisFramesFrame)
    //*)
}

void DoisFramesFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void DoisFramesFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void DoisFramesFrame::OnButton1Click(wxCommandEvent& event)
{
    frame2 *f = new frame2(0);

    f->Show();

}

void DoisFramesFrame::OnButton2Click(wxCommandEvent& event)
{
    dialog2 *d = new dialog2(0);
    d->ShowModal();

    delete(d);
}
