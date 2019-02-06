/***************************************************************
 * Name:      GerAfazeresApp.cpp
 * Purpose:   Code for Application Class
 * Author:    CiroboyBR ()
 * Created:   2018-09-18
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "GerAfazeresApp.h"

//(*AppHeaders
#include "GerAfazeresMain.h"
#include <wx/xrc/xmlres.h>
#include <wx/image.h>
//*)

IMPLEMENT_APP(GerAfazeresApp);

bool GerAfazeresApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    wxXmlResource::Get()->InitAllHandlers();
    wxsOK = wxsOK && wxXmlResource::Get()->Load(_T("CadastraAfazer.xrc"));
    if ( wxsOK )
    {
    	GerAfazeresFrame* Frame = new GerAfazeresFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
