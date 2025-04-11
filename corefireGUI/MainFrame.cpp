#include "MainFrame.h"
#include "wx/wx.h"

enum class IDs : int {
	BUTTON_ID1 = 0, BUTTON_ID2 = 1
};


static constexpr const char* toString(IDs id) noexcept {
    switch (id) {
	case IDs::BUTTON_ID1: return "Button One";
	case IDs::BUTTON_ID2: return "Button Two";
		default:           return "Unknown";
    }
}


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, static_cast<int>(IDs::BUTTON_ID1), toString(IDs::BUTTON_ID1), wxPoint(300, 100), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, static_cast<int>(IDs::BUTTON_ID2), toString(IDs::BUTTON_ID2), wxPoint(300, 200), wxSize(200, 50));
	
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::onClose, this);
	this->Bind(wxEVT_BUTTON, &MainFrame::onAnyClick, this);
	button1->Bind(wxEVT_BUTTON, &MainFrame::onButton1Click, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::onButton2Click, this);

	CreateStatusBar();
}

void MainFrame::onAnyClick(wxCommandEvent& event)
{
	wxLogMessage("Button clicked!");
}

void MainFrame::onButton1Click(wxCommandEvent& event)
{
	wxLogStatus("Button 1 clicked!");
	event.Skip();
}

void MainFrame::onButton2Click(wxCommandEvent& event)
{
	wxLogStatus("Button 2 clicked!");
}

void MainFrame::onClose(wxCloseEvent& event)
{
	wxLogMessage("Closing the application.");
	event.Skip();  // passes theevent to the base class to handle the event
	// or this->Destroy();
}
