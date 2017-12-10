/***************************************************************
 * Name:      lista1App.cpp
 * Purpose:   Code for Application Class
 * Author:    Ciro ()
 * Created:   2017-09-18
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#include "lista1App.h"

//(*AppHeaders
#include "lista1Main.h"
#include <wx/image.h>
//*)
#include <wx/textdlg.h>
#include <wx/msgdlg.h>

IMPLEMENT_APP(lista1App);

bool lista1App::OnInit()
{
   // wxString login, senha;
   // login = wxGetTextFromUser("LOGIN: ", "SysInternos 1.5");
    //senha = wxGetTextFromUser("SENHA: ", "SysInternos 1.5");

   // if(login == "login" && senha == "senha" ) {
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	lista1Frame* Frame = new lista1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
 //   }
  //  else{
  //      wxMessageBox("Dados incorretos!", _("Acesso não autorizado."));
  //      wxExit();
   // }

}
