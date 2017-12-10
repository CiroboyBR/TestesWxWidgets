/***************************************************************
 * Name:      lista1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ciro ()
 * Created:   2017-09-18
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#include "lista1Main.h"
#include <wx/msgdlg.h>
#include <cstdio>
#include <list>

//(*InternalHeaders(lista1Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/textdlg.h>

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

void limpaLista(wxListCtrl *lista);
void copiaLista(wxListCtrl *listaOrigem, wxListCtrl *listaDestino);
void imprimeLista(wxListCtrl *lista);

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

//(*IdInit(lista1Frame)
const long lista1Frame::ID_LISTCTRL1 = wxNewId();
const long lista1Frame::ID_BUTTON1 = wxNewId();
const long lista1Frame::ID_BUTTON2 = wxNewId();
const long lista1Frame::ID_BUTTON3 = wxNewId();
const long lista1Frame::ID_TEXTCTRL1 = wxNewId();
const long lista1Frame::ID_TEXTCTRL2 = wxNewId();
const long lista1Frame::ID_TEXTCTRL3 = wxNewId();
const long lista1Frame::ID_TEXTCTRL4 = wxNewId();
const long lista1Frame::ID_TEXTCTRL5 = wxNewId();
const long lista1Frame::ID_TEXTCTRL6 = wxNewId();
const long lista1Frame::ID_TEXTCTRL7 = wxNewId();
const long lista1Frame::ID_TEXTCTRL8 = wxNewId();
const long lista1Frame::ID_STATICTEXT1 = wxNewId();
const long lista1Frame::ID_STATICTEXT2 = wxNewId();
const long lista1Frame::ID_STATICTEXT3 = wxNewId();
const long lista1Frame::ID_STATICTEXT4 = wxNewId();
const long lista1Frame::ID_STATICTEXT5 = wxNewId();
const long lista1Frame::ID_STATICTEXT6 = wxNewId();
const long lista1Frame::ID_STATICTEXT7 = wxNewId();
const long lista1Frame::ID_STATICTEXT8 = wxNewId();
const long lista1Frame::ID_BUTTON4 = wxNewId();
const long lista1Frame::ID_PANEL1 = wxNewId();
const long lista1Frame::idMenuQuit = wxNewId();
const long lista1Frame::idMenuInserir = wxNewId();
const long lista1Frame::idMenuDeletar = wxNewId();
const long lista1Frame::idMenuBuscar = wxNewId();
const long lista1Frame::idMenuAbout = wxNewId();
const long lista1Frame::ID_STATUSBAR1 = wxNewId();
//*)
wxListCtrl *listaTemp;

BEGIN_EVENT_TABLE(lista1Frame,wxFrame)
    //(*EventTable(lista1Frame)
    //*)
END_EVENT_TABLE()

lista1Frame::lista1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(lista1Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Cadastro"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1000,800));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(360,160), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(24,112), wxSize(928,446), wxLC_REPORT|wxLC_SORT_ASCENDING, wxDefaultValidator, _T("ID_LISTCTRL1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("INSERIR"), wxPoint(704,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("LISTAR"), wxPoint(704,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("DELETAR"), wxPoint(704,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("001"), wxPoint(72,8), wxSize(96,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("interno "), wxPoint(232,5), wxSize(456,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(72,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("1A"), wxPoint(216,40), wxSize(56,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("01"), wxPoint(312,40), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("MARIA DOLORIA"), wxPoint(392,40), wxSize(296,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl7 = new wxTextCtrl(Panel1, ID_TEXTCTRL7, _("01/01/2017"), wxPoint(72,72), wxSize(96,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    TextCtrl8 = new wxTextCtrl(Panel1, ID_TEXTCTRL8, _("UP PIRS"), wxPoint(232,72), wxSize(144,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("PRONT:"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("NOME:"), wxPoint(184,8), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("ALCUNHA:"), wxPoint(8,43), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("VIV:"), wxPoint(184,43), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("CELA:"), wxPoint(280,43), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("MÃE:"), wxPoint(358,43), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("ENTRADA:"), wxPoint(8,75), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("ORIGEM:"), wxPoint(184,75), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Busca Nome"), wxPoint(792,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Sair\tAlt-F4"), _("Sair do programa"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, idMenuInserir, _("Inserir\tAlt-x"), _("Inserir "), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuDeletar, _("Detelar\tdelete"), _("Deleta o item selecionado."), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu1, idMenuBuscar, _("Buscar\tAlt-f"), _("Busca um Item"), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lista1Frame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lista1Frame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lista1Frame::OnButton3Click);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&lista1Frame::OnTextCtrl1Text);
    Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&lista1Frame::OnTextCtrl6Text);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lista1Frame::OnButton4Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&lista1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&lista1Frame::OnAbout);
    //*)
    //conector para um menu ou atalho de tecla
    Connect(idMenuInserir, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&lista1Frame::OnInserir);
    Connect(idMenuDeletar, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&lista1Frame::OnDeletar);
    Connect(idMenuBuscar, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&lista1Frame::OnBuscar);

    //cria colunas
    ListCtrl1->InsertColumn(0, "PRONT", wxLIST_FORMAT_LEFT, 80);
    ListCtrl1->InsertColumn(1, "NOME", wxLIST_FORMAT_LEFT, 200);
    ListCtrl1->InsertColumn(2, "ALCUNHA", wxLIST_FORMAT_LEFT, 80);
    ListCtrl1->InsertColumn(3, "VIV", wxLIST_FORMAT_LEFT, 30);
    ListCtrl1->InsertColumn(4, "CELA", wxLIST_FORMAT_LEFT, 60);
    ListCtrl1->InsertColumn(5, "MÃE", wxLIST_FORMAT_LEFT, 150);
    ListCtrl1->InsertColumn(6, "ENTRADA", wxLIST_FORMAT_LEFT, 100);
    ListCtrl1->InsertColumn(7, "ORIGEM", wxLIST_FORMAT_LEFT, 100);

    ListCtrl1->SetBackgroundColour(*wxLIGHT_GREY);

    //Temporario
    listaTemp = new wxListCtrl();

    //cria colunas
    listaTemp->InsertColumn(0, "PRONT", wxLIST_FORMAT_LEFT, 80);
    listaTemp->InsertColumn(1, "NOME", wxLIST_FORMAT_LEFT, 200);
    listaTemp->InsertColumn(2, "ALCUNHA", wxLIST_FORMAT_LEFT, 80);
    listaTemp->InsertColumn(3, "VIV", wxLIST_FORMAT_LEFT, 30);
    listaTemp->InsertColumn(4, "CELA", wxLIST_FORMAT_LEFT, 60);
    listaTemp->InsertColumn(5, "MÃE", wxLIST_FORMAT_LEFT, 150);
    listaTemp->InsertColumn(6, "ENTRADA", wxLIST_FORMAT_LEFT, 100);
    listaTemp->InsertColumn(7, "ORIGEM", wxLIST_FORMAT_LEFT, 100);


}

lista1Frame::~lista1Frame()
{
    //(*Destroy(lista1Frame)
    //*)
}

void lista1Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

//insere atraves do menu com atalho ou nao CTRL+X
void lista1Frame::OnInserir(wxCommandEvent& event)
{


    long n = ListCtrl1->GetItemCount();

    for(int u = n; u < n+5; u++)
    {
        wxListItem* item     = new wxListItem();

        item->SetBackgroundColour(*wxWHITE);
        item->SetText(wxT("StringImprestavel"));
        item->SetId(0);

        ListCtrl1->InsertItem(0, *item);


        ListCtrl1->SetItem(0,0, wxString::Format(wxT("%i"),u), -1);
        ListCtrl1->SetItem(0,1, TextCtrl2->GetValue() + wxString::Format(wxT("%i"),u), -1);
        ListCtrl1->SetItem(0,2, TextCtrl3->GetValue(), -1);
        ListCtrl1->SetItem(0,3, TextCtrl4->GetValue(), -1);
        ListCtrl1->SetItem(0,4, TextCtrl5->GetValue(), -1);
        ListCtrl1->SetItem(0,5, TextCtrl6->GetValue(), -1);
        ListCtrl1->SetItem(0,6, TextCtrl7->GetValue(), -1);
        ListCtrl1->SetItem(0,7, TextCtrl8->GetValue(), -1);

    }
}
//Deleta o item selecionado pelo menu ou atalho DELETE
void lista1Frame::OnDeletar(wxCommandEvent& event)
{
    system("CLS");

    if (ListCtrl1->GetItemCount() > -1)
        for (int i = 0; i < ListCtrl1->GetItemCount(); i++)
            if ( (ListCtrl1->GetItemState(i, -1)) != 0)
            {
                printf("\nTamanho Inicial: %d", ListCtrl1->GetItemCount());
                //deleta item
                ListCtrl1->DeleteItem(i);

                break;
            }
}
//Buscar ALT+F
void lista1Frame::OnBuscar(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
//    wxMessageBox(msg, _("Bem Vindo."));
    wxString s ;
    bool achou = false;
    std::list<long int> itensParaDeletar;
    long i = -1;

    s = wxGetTextFromUser("Digite o Nome: ", "1");

    //busca os o resultados
    if (ListCtrl1->GetItemCount() > -1 && s != "")
        for (long i = 0; i < ListCtrl1->GetItemCount(); i++)
        {
            if ( ListCtrl1->GetItemText(i, 1).Find(s) != wxNOT_FOUND )
            {
                achou = true;
                printf("Achou: %s", (const char*)ListCtrl1->GetItemText(i, 1).mbc_str());

                wxListItem* item     = new wxListItem();

                item->SetBackgroundColour(*wxWHITE);
                item->SetText(wxT("StringImprestavel"));
                item->SetId(0);

                listaTemp->InsertItem(0, *item);

                listaTemp->SetItem(0,0, ListCtrl1->GetItemText(i, 0), -1);
                listaTemp->SetItem(0,1, ListCtrl1->GetItemText(i, 1), -1);
                listaTemp->SetItem(0,2, ListCtrl1->GetItemText(i, 2), -1);
                listaTemp->SetItem(0,3, ListCtrl1->GetItemText(i, 3), -1);
                listaTemp->SetItem(0,4, ListCtrl1->GetItemText(i, 4), -1);
                listaTemp->SetItem(0,5, ListCtrl1->GetItemText(i, 5), -1);
                listaTemp->SetItem(0,6, ListCtrl1->GetItemText(i, 6), -1);
                listaTemp->SetItem(0,7, ListCtrl1->GetItemText(i, 7), -1);
            }

        }
        imprimeLista(listaTemp);

   // limpaLista(ListCtrl1);
    //copiaLista(listaTemp, ListCtrl1);


}


//Sobre F1 - (Momentaneamente implementando busca)
void lista1Frame::OnAbout(wxCommandEvent& event)
{/*
    wxString msg = wxbuildinfo(long_f);
//    wxMessageBox(msg, _("Bem Vindo."));
    wxString s ;
    bool achou = false;
    std::list<long int> itensParaDeletar;


    s = wxGetTextFromUser("Digite o Nome: ", "1");



    //busca os o resultados
    if (ListCtrl1->GetItemCount() > -1)
        for (long i = 0; i < ListCtrl1->GetItemCount(); i++)
        {
            printf("Comparou: %s   |   %s\n", (const char*)ListCtrl1->GetItemText(i, 1).mbc_str(), (const char*)s.mbc_str());


            if ( ListCtrl1->GetItemText(i, 1).Find(s) != wxNOT_FOUND )
            {
                achou = true;
                printf("Iguais: %s   |   %s\n", (const char*)ListCtrl1->GetItemText(i, 1).mbc_str(), (const char*)s.mbc_str());

                wxListItem* item     = new wxListItem();

                item->SetBackgroundColour(*wxWHITE);
                item->SetText(wxT("StringImprestavel"));
                item->SetId(0);

                listaTemp->InsertItem(0, *item);

                listaTemp->SetItem(0,0, ListCtrl1->GetItemText(i, 0), -1);
                listaTemp->SetItem(0,1, ListCtrl1->GetItemText(i, 1), -1);
                listaTemp->SetItem(0,2, ListCtrl1->GetItemText(i, 2), -1);
                listaTemp->SetItem(0,3, ListCtrl1->GetItemText(i, 3), -1);
                listaTemp->SetItem(0,4, ListCtrl1->GetItemText(i, 4), -1);
                listaTemp->SetItem(0,5, ListCtrl1->GetItemText(i, 5), -1);
                listaTemp->SetItem(0,6, ListCtrl1->GetItemText(i, 6), -1);
                listaTemp->SetItem(0,7, ListCtrl1->GetItemText(i, 7), -1);
            }

        }

    if (achou == true)
        wxMessageBox(_("Encontrado!"));
    else
        wxMessageBox(_("Não Encontrado!"));

        */
}

//insere os dados na lista
void lista1Frame::OnButton1Click1(wxCommandEvent& event)
{
    //cria item
    wxListItem* item     = new wxListItem();
    //configura item para ser inserido na posição inicial da lista
    item->SetBackgroundColour(*wxRED);
    item->SetText(wxT("Inicial"));
    item->SetId(0);

    //RETORNA O A QUANTIDADE DE ITEMS DA LISTA
    long n = ListCtrl1->GetItemCount();

    ListCtrl1->InsertItem(0, *item);

    //ListCtrl1->SetItem(0,0, wxString::Format(wxT("%i"),n+1), -1);
    ListCtrl1->SetItem(0,0, TextCtrl1->GetValue(), -1);
    ListCtrl1->SetItem(0,1, TextCtrl2->GetValue(), -1);
    ListCtrl1->SetItem(0,2, TextCtrl3->GetValue(), -1);
    ListCtrl1->SetItem(0,3, TextCtrl4->GetValue(), -1);
    ListCtrl1->SetItem(0,4, TextCtrl5->GetValue(), -1);
    ListCtrl1->SetItem(0,5, TextCtrl6->GetValue(), -1);
    ListCtrl1->SetItem(0,6, TextCtrl7->GetValue(), -1);
    ListCtrl1->SetItem(0,7, TextCtrl8->GetValue(), -1);
}

//imprime no terminal
void lista1Frame::OnButton2Click(wxCommandEvent& event)
{
    system("CLS");
    for(long i = 0; i < ListCtrl1->GetItemCount(); i++)
    {
        wxString s = ListCtrl1->GetItemText(i, 1);
        printf("Item|%ld|: %s\n", i, (const char*)s.mbc_str());
    }
}

void lista1Frame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void lista1Frame::OnTextCtrl6Text(wxCommandEvent& event)
{
}

//Deleta todod os itens
void lista1Frame::OnButton3Click(wxCommandEvent& event)
{
    limpaLista(ListCtrl1);
}

//Busca um nome
void lista1Frame::OnButton4Click(wxCommandEvent& event)
{
    bool achou = false;

    if (ListCtrl1->GetItemCount() > -1)
        for (long i = 0; i < ListCtrl1->GetItemCount(); i++)
        {
            printf("Comparou: %s   |   %s\n", (const char*)ListCtrl1->GetItemText(i, 1).mbc_str(), (const char*)TextCtrl2->GetValue().mbc_str());

            if ( ListCtrl1->GetItemText(i, 1) == TextCtrl2->GetValue() )
            {
                achou = true;
                printf("Iguais: %s   |   %s\n", (const char*)ListCtrl1->GetItemText(i, 1).mbc_str(), (const char*)TextCtrl2->GetValue().mbc_str());
                //ListCtrl1->.GetItemCount()
                break;

            }

        }

    if (achou == true)
        wxMessageBox(_("Encontrado!"));
    else
        wxMessageBox(_("Não Encontrado!"));



}

//Limpa a lista
void limpaLista(wxListCtrl *lista)
{
     long n = lista->GetItemCount();

    while ( n > 0)
    {
        lista->DeleteItem(0);
        n--;
    }


}

//Copia uma Lista para outra
void copiaLista(wxListCtrl *listaOrigem, wxListCtrl *listaDestino)
{
    long i = listaOrigem->GetItemCount();

    while ( i > 0)
    {
        wxListItem* item     = new wxListItem();

        item->SetBackgroundColour(*wxWHITE);
        item->SetText(wxT("StringImprestavel"));
        item->SetId(0);

        listaDestino->InsertItem(0, *item);

        listaDestino->SetItem(0,0, listaOrigem->GetItemText(i, 0), -1);
        listaDestino->SetItem(0,1, listaOrigem->GetItemText(i, 1), -1);
        listaDestino->SetItem(0,2, listaOrigem->GetItemText(i, 2), -1);
        listaDestino->SetItem(0,3, listaOrigem->GetItemText(i, 3), -1);
        listaDestino->SetItem(0,4, listaOrigem->GetItemText(i, 4), -1);
        listaDestino->SetItem(0,5, listaOrigem->GetItemText(i, 5), -1);
        listaDestino->SetItem(0,6, listaOrigem->GetItemText(i, 6), -1);
        listaDestino->SetItem(0,7, listaOrigem->GetItemText(i, 7), -1);

        i--;
    }
}

//imprime lista1App
void imprimeLista(wxListCtrl *lista) {
 system("CLS");
    for(long i = 0; i < lista->GetItemCount(); i++)
    {
        wxString s = lista->GetItemText(i, 1);
        printf("Item|%ld|: %s\n", i, (const char*)s.mbc_str());
    }
}

//
int buscaNaLista(wxListCtrl * lista) {

}
