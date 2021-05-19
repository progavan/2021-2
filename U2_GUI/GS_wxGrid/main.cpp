// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
/*
#include "wx/colordlg.h"
#include "wx/fontdlg.h"
#include "wx/numdlg.h"
#include "wx/aboutdlg.h"
*/
#include "wx/grid.h"
/*
#include "wx/headerctrl.h"
#include "wx/generic/gridctrl.h"
#include "wx/generic/grideditors.h"
*/
#include "main.h"
// ----------------------------------------------------------------------------
// wxWin macros
// ----------------------------------------------------------------------------

wxIMPLEMENT_APP(GSwxGridApp);

// ============================================================================
// implementation
// ============================================================================
// ----------------------------------------------------------------------------
// GSwxGridApp
// ----------------------------------------------------------------------------

bool GSwxGridApp::OnInit()
{
    GridFrame *frame = new GridFrame;
    frame->Show(true);

    return true;
}

//#define SET_SIZES_OF_INDIVIDUAL_ROWS_AND_COLS
//#define SET_GRID_CELL_CONTENT_AS_STRINGS
//#define SPECIFY_CELLS_AS_READ_ONLY
//#define SPECIFY_COLOURS_FOR_GRID_CELL_CONTENTS
//#define SPECIFY_A_COLUMN_WILL_STORE_NUMERIC_VALUES
GridFrame::GridFrame()
: wxFrame( (wxFrame *)NULL, wxID_ANY,
            "wxWidgets grid class demo",
            wxDefaultPosition,
            //wxDefaultSize )
            wxSize(900, 300))

{
 // Create a wxGrid object
 grid = new wxGrid( this,
                    -1,
                    wxPoint( 0, 0 ),
                    //wxSize( 400, 300 ) );
                    wxDefaultSize);
 // Then we call CreateGrid to set the dimensions of the grid
 // (100 rows and 10 columns in this example)
 //grid->CreateGrid( 100, 10 );
 grid->CreateGrid( 10, 10 );
#ifdef SET_SIZES_OF_INDIVIDUAL_ROWS_AND_COLS
 // We can set the sizes of individual rows and columns
 // in pixels
 grid->SetRowSize( 0, 60 );
 grid->SetColSize( 0, 120 );
#endif // SET_SIZES_OF_INDIVIDUAL_ROWS_AND_COLS
#ifdef SET_GRID_CELL_CONTENT_AS_STRINGS
 // And set grid cell contents as strings
 grid->SetCellValue( 0, 0, "wxGrid is good" );
#endif // SET_GRID_CELL_CONTENT_AS_STRINGS
#ifdef SPECIFY_CELLS_AS_READ_ONLY
 // We can specify that some cells are read->only
 grid->SetCellValue( 0, 3, "This is read->only" );
 grid->SetReadOnly( 0, 3 );
#endif // SPECIFY_CELLS_AS_READ_ONLY
#ifdef SPECIFY_COLOURS_FOR_GRID_CELL_CONTENTS
 // Colours can be specified for grid cell contents
 grid->SetCellValue(3, 3, "green on grey");
 grid->SetCellTextColour(3, 3, *wxGREEN);
 grid->SetCellBackgroundColour(3, 3, *wxLIGHT_GREY);
#endif // SPECIFY_COLOURS_FOR_GRID_CELL_CONTENTS
#ifdef SPECIFY_A_COLUMN_WILL_STORE_NUMERIC_VALUES
 // We can specify that some cells will store numeric
 // values rather than strings. Here we set grid column 5
 // to hold floating point values displayed with width of 6
 // and precision of 2
 grid->SetColFormatFloat(5, 6, 2);
 grid->SetCellValue(0, 6, "3.1415");
#endif // SPECIFY_A_COLUMN_WILL_STORE_NUMERIC_VALUES
}

GridFrame::~GridFrame()
{
#if wxUSE_LOG
    delete wxLog::SetActiveTarget(m_logOld);
#endif // wxUSE_LOG
}

