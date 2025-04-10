#include "MainFrame.h"
#include "wx/wx.h"
#include "wx/spinctrl.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, wxID_ANY, "Click Me", wxPoint(150, 50), wxSize(100,35), wxBU_EXACTFIT);

	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Check Me", wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Hello, World!", wxPoint(0, 150), wxSize(400,-1), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
	staticText->SetForegroundColour(wxColour(*wxRED));

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "Type here", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(-1,125), wxGA_VERTICAL);
	gauge->SetValue(50);

	wxArrayString choices;
	choices.Add("Item C");
	choices.Add("Item A");
	choices.Add("Item B");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	choice->Select(0);

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "0", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radio Box", wxPoint(555,450), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);


}
