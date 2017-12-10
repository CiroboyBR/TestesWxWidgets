/***************************************************************
 * Name:      DoisFramesApp.cpp
 * Purpose:   Code for Application Class
 * Author:    CiroboyBR ()
 * Created:   2017-11-03
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "DoisFramesApp.h"

//(*AppHeaders
#include "DoisFramesMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(DoisFramesApp);

bool DoisFramesApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	DoisFramesFrame* Frame = new DoisFramesFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
