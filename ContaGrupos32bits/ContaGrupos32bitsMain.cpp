/***************************************************************
 * Name:      ContaGrupos32bitsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ciro ()
 * Created:   2017-09-06
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#include "ContaGrupos32bitsMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ContaGrupos32bitsFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/textfile.h>
#include <wx/html/htmprint.h>
#include <fstream>      // std::ifstream
#include <list>
#include <vector>
#include <cstdlib>
#include <clocale>
#include <stdexcept>
#include <string>

using namespace std;

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(ContaGrupos32bitsFrame)
const long ContaGrupos32bitsFrame::ID_TEXTCTRL1 = wxNewId();
const long ContaGrupos32bitsFrame::ID_TEXTCTRL2 = wxNewId();
const long ContaGrupos32bitsFrame::ID_BUTTON1 = wxNewId();
const long ContaGrupos32bitsFrame::ID_BUTTON2 = wxNewId();
const long ContaGrupos32bitsFrame::ID_STATICTEXT1 = wxNewId();
const long ContaGrupos32bitsFrame::ID_STATICTEXT2 = wxNewId();
const long ContaGrupos32bitsFrame::ID_BUTTON3 = wxNewId();
const long ContaGrupos32bitsFrame::ID_PANEL1 = wxNewId();
const long ContaGrupos32bitsFrame::ID_MENUITEM1 = wxNewId();
const long ContaGrupos32bitsFrame::ID_MENUITEMIMPRIMIR = wxNewId();
const long ContaGrupos32bitsFrame::idMenuAbout = wxNewId();
const long ContaGrupos32bitsFrame::ID_STATUSBAR1 = wxNewId();
//*)


BEGIN_EVENT_TABLE(ContaGrupos32bitsFrame,wxFrame)
    //(*EventTable(ContaGrupos32bitsFrame)
    //*)
END_EVENT_TABLE()

ContaGrupos32bitsFrame::ContaGrupos32bitsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ContaGrupos32bitsFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Contador de Vivências 1.0 - 2017"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,600));
    SetHelpText(_("Imprime o resultado."));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(232,312), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(32,90), wxSize(320,336), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(504,90), wxSize(248,326), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("CONTAR"), wxPoint(368,112), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetHelpText(_("Contabiliza as quantidades inseridas e gera o resultado."));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("LIMPAR"), wxPoint(368,176), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetHelpText(_("Limpa as informações inseridas, bem como os resultados."));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _(".:: GRUPOS ::."), wxPoint(144,64), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _(".:: RESULTADO ::."), wxPoint(568,60), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("IMPRIMIR"), wxPoint(368,240), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("SAIR\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEMIMPRIMIR, _("IMPRIMIR\tCtrl+p"), _("Imprime o resultado da contagem."), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuBar1->Append(Menu1, _("ARQUIVO"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("SOBRE\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("AJUDA"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    HtmlEasyPrinting1 = new wxHtmlEasyPrinting(_T("wxHtmlEasyPrinting"), this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContaGrupos32bitsFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContaGrupos32bitsFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContaGrupos32bitsFrame::OnButton3Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ContaGrupos32bitsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ContaGrupos32bitsFrame::OnAbout);
    //*)
    Connect(ID_MENUITEMIMPRIMIR,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ContaGrupos32bitsFrame::OnAbout);
}

ContaGrupos32bitsFrame::~ContaGrupos32bitsFrame()
{
    //(*Destroy(ContaGrupos32bitsFrame)
    //*)
}

void ContaGrupos32bitsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ContaGrupos32bitsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Feito por: CiroboyBR\nTodos os direitos reservados\nCopyright © 2017";
    wxMessageBox(msg, _("Sobre"));
}

void ContaGrupos32bitsFrame::OnButton1Click(wxCommandEvent& event)
{
    //-------------------------------Linguagem-----------------
    //setlocale(LC_ALL, "Portuguese");
    //------------------------------ Linguagem-----------------

    TextCtrl2->Clear();

    string sc,  viv, viv_anterior, nome;
    list<string> lista;
    int qtd = 0, contagem = 0, total = 0;
    int linhas = TextCtrl1->GetNumberOfLines();


    for(int i = 0; i <= linhas; i++)
    {
        lista.push_back(TextCtrl1->GetLineText(i).ToStdString());
        qtd++;
    }

    lista.sort();

    while (lista.size() > 0)
    {
        if (lista.size() == qtd)
        {
            contagem = 1;
            nome = lista.front();
        }
        else
        {
            if (nome == lista.front() )
            {
                contagem++;
            }
            else
            {
                cout << endl << nome << ": " << contagem;
                wxString nometemp(nome);
                //string snum = std::to_string(contagem);
                wxString conttmp;
                conttmp << contagem;

                if (nome != " " && nome != "" && nome != "VIV" && nome != "VIV " )
                {
                    TextCtrl2->SetValue(TextCtrl2->GetValue() + nometemp + ": " + conttmp + "\n");
                    total += contagem;
                }
                else
                    printf("\nCtemp: %d\n", contagem);



                contagem = 1;

                if ( lista.size() > 0 )
                    nome = lista.front();



            }
        }

        //  cout << lista.front() << endl;
        //cout << "--"<< lista.front()<< "--"<< endl;
        lista.pop_front();
    }
    cout << endl << nome << ": " << contagem;
    //string string_tmp = std::to_string(contagem);
    wxString str_tmp;
    str_tmp << contagem;
    wxString nometemp(nome);

    if (nome != " " && nome != "" && nome != "VIV" && nome != "VIV " )
    {
        TextCtrl2->SetValue(TextCtrl2->GetValue() + nometemp + ": " + str_tmp + "\n");
        total += contagem;
    }
    else
        printf("\nCtemp: %d\n", contagem);

    cout << endl <<"----------------------------";
    TextCtrl2->SetValue(TextCtrl2->GetValue() + "------\n");
    cout << endl << "Total: " <<  total <<endl << endl;
    wxString totalwx;
    totalwx << total;
    TextCtrl2->SetValue(TextCtrl2->GetValue() + "Total: " + totalwx + "\n\n");
    cout << endl <<"Linhas: " << TextCtrl1->GetNumberOfLines();
}

void ContaGrupos32bitsFrame::OnButton2Click(wxCommandEvent& event)
{
    TextCtrl1->Clear();
    TextCtrl2->Clear();
}

void ContaGrupos32bitsFrame::OnButton3Click(wxCommandEvent& event)
{
   wxString strHTML = "<html> \n";
   wxString conteudo;

   //insere o conteúdo de TextCrl2 na wxString
   int linhas = TextCtrl2->GetNumberOfLines();
   for (int i = 0; i <= linhas; i++) {
     conteudo.Append("<br>");//nova linha
     conteudo.Append(TextCtrl2->GetLineText(i));//copia linha N do TextCtrl

   }

    conteudo.Append("<br>");//nova linha

   for (int i = 0; i <= linhas; i++) {
     conteudo.Append("<br>");//nova linha
     conteudo.Append(TextCtrl2->GetLineText(i));//copia linha N do TextCtrl

   }

  //configura o conteúdo a ser ipresso
   strHTML = strHTML + "<b>" +  conteudo + "</b>";
   strHTML = strHTML + "</html>";

   //instancia do HtmlEasyPrint
   wxHtmlEasyPrinting easyPrint("Question to HTML Easy Printing", this);

   //Configura informações extar de título e cOstantes do sistema.
   easyPrint.SetHeader(wxString("CONTAGEM DOS GRUPOS - ") + wxT("DATA: @DATE@  ||   HORA: @TIME@)<hr>"), wxPAGE_ALL);
   easyPrint.PreviewText(strHTML);
}
