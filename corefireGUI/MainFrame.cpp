#include "MainFrame.h"
#include "wx/wx.h"

enum class IDs : int {
	BUTTON_ID = 2
};

static constexpr const char* toString(IDs id) noexcept {
    switch (id) {
	case IDs::BUTTON_ID: return "Button";
    default:           return "Unknown";
    }
}


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, static_cast<int>(IDs::BUTTON_ID), toString(IDs::BUTTON_ID), wxPoint(300, 275), wxSize(200, 50));

	CreateStatusBar();

}
