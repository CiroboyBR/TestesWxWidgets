/***************************************************************
 * Name:      ContaGrupos32bitsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ciro ()
 * Created:   2017-09-06
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#include "ContaGrupos32bitsApp.h"

//(*AppHeaders
#include "ContaGrupos32bitsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ContaGrupos32bitsApp);

bool ContaGrupos32bitsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ContaGrupos32bitsFrame* Frame = new ContaGrupos32bitsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
