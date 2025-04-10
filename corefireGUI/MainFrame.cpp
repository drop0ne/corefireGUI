#include "MainFrame.h"
#include "wx/wx.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(this, wxID_ANY, "Click Me", wxPoint(150, 50), wxSize(100,35));
}

MainFrame::~MainFrame()
{
}
