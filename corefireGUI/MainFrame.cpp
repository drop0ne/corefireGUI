#include "MainFrame.h"
#include "wx/wx.h"

enum class IDs : int {
	BUTTON_ID_Defualt = 0, BUTTON_ID1 = 1, BUTTON_ID2 = 2
};

static constexpr const char* toString(IDs id) noexcept {
    switch (id) {
	case IDs::BUTTON_ID_Defualt: return "Close Program";
	case IDs::BUTTON_ID1: return "Button One";
	case IDs::BUTTON_ID2: return "Button Two";
		default:           return "Unknown";
    }
}

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxButton* defaultButton = new wxButton(panel, static_cast<int>(IDs::BUTTON_ID_Defualt), toString(IDs::BUTTON_ID_Defualt), wxPoint(300, 250), wxSize(200, 100));
	
	defaultButton->Bind(wxEVT_BUTTON, &MainFrame::onClickClose, this);

	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true);// saving the status bar to local variable and giving it a double buffer, to eliminate flickering

	panel->Bind(wxEVT_MOTION, &MainFrame::onMouseEvent, this);
	defaultButton->Bind(wxEVT_MOTION, &MainFrame::onMouseEvent, this);
}

void MainFrame::onMouseEvent(wxMouseEvent& event)
{
	wxPoint mousePosition = wxGetMousePosition();
	mousePosition = this->ScreenToClient(mousePosition);
	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePosition.x, mousePosition.y);
	wxLogStatus(message);
}

void MainFrame::onClickClose(wxCommandEvent& event)
{
	Destroy();
}
