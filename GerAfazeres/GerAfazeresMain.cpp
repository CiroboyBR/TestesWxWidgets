/***************************************************************
 * Name:      GerAfazeresMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-18
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "GerAfazeresMain.h"
#include <wx/msgdlg.h>
#include <wx/datetime.h>
#include "CadastraAfazer.h"
#include "Tarefa.h"

//(*InternalHeaders(GerAfazeresFrame)
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

//(*IdInit(GerAfazeresFrame)
const long GerAfazeresFrame::ID_LISTCTRL1 = wxNewId();
const long GerAfazeresFrame::ID_BUTTON1 = wxNewId();
const long GerAfazeresFrame::ID_BUTTON2 = wxNewId();
const long GerAfazeresFrame::idMenuQuit = wxNewId();
const long GerAfazeresFrame::idMenuAbout = wxNewId();
const long GerAfazeresFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GerAfazeresFrame,wxFrame)
    //(*EventTable(GerAfazeresFrame)
    //*)
END_EVENT_TABLE()

GerAfazeresFrame::GerAfazeresFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GerAfazeresFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("Gerenciador de Afazeres 0.1"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL, _T("id"));
    SetClientSize(wxSize(1024,768));
    ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxPoint(48,136), wxSize(480,544), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING, wxDefaultValidator, _T("ID_LISTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("CADASTRAR"), wxPoint(64,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("REMOVER"), wxPoint(176,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Sair\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("Arquivo"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Sobre\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ajuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GerAfazeresFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GerAfazeresFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GerAfazeresFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GerAfazeresFrame::OnAbout);
    //*)

    //cria colunas
    ListCtrl1->InsertColumn(0, "ID", wxLIST_FORMAT_CENTER, 80);
    ListCtrl1->InsertColumn(1, "PRIORIDADE", wxLIST_FORMAT_CENTER, 80);
    ListCtrl1->InsertColumn(2, "DATA DA CRIAÇÃO", wxLIST_FORMAT_CENTER, 80);
    ListCtrl1->InsertColumn(3, "DESCRIÇÃO", wxLIST_FORMAT_LEFT, 400);


    ListCtrl1->SetBackgroundColour(*wxLIGHT_GREY);
}

GerAfazeresFrame::~GerAfazeresFrame()
{
    //(*Destroy(GerAfazeresFrame)
    //*)
}

void GerAfazeresFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GerAfazeresFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

//CADASTRAR
void GerAfazeresFrame::OnButton1Click(wxCommandEvent& event)
{
        wxListItem* item     = new wxListItem();

        item->SetBackgroundColour(*wxWHITE);
        item->SetText(wxT("StringImprestavel"));
        item->SetId(0);

        ListCtrl1->InsertItem(0, *item);

        CadastraAfazer c(0);
        c.ShowModal();

        ListCtrl1->SetItem(0,0, _("1"), -1);
        ListCtrl1->SetItem(0,1, c.getPrioridade(), -1);
        ListCtrl1->SetItem(0,2, c.getData(), -1);
        ListCtrl1->SetItem(0,3, c.getDescricao(), -1);



}

//REMOVER
void GerAfazeresFrame::OnButton2Click(wxCommandEvent& event)
{
     if (ListCtrl1->GetItemCount() > -1)
        for (int i = 0; i < ListCtrl1->GetItemCount(); i++)
            if ( (ListCtrl1->GetItemState(i, -1)) != 0)
            {
                //deleta item
                ListCtrl1->DeleteItem(i);

                break;
            }

}
