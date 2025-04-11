#include "MainFrame.h"
#include "wx/wx.h"

enum class IDs : int {
	BUTTON_ID = 2, SLIDER_ID = 3, TEXT_ID = 4
};


static constexpr const char* toString(IDs id) noexcept {
    switch (id) {
	case IDs::BUTTON_ID: return "Button";
	case IDs::SLIDER_ID: return "Slider";
	case IDs::TEXT_ID:   return "Text";
    default:           return "Unknown";
    }
}


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, static_cast<int>(IDs::BUTTON_ID), toString(IDs::BUTTON_ID), wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, static_cast<int>(IDs::SLIDER_ID), 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, static_cast<int>(IDs::TEXT_ID), "Hello World", wxPoint(300, 375), wxSize(200, -1));

	button->Bind(wxEVT_BUTTON, &MainFrame::onButtonClick, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::onSliderChange, this);
	text->Bind(wxEVT_TEXT, &MainFrame::onTextChange, this);

	button->Unbind(wxEVT_BUTTON, &MainFrame::onButtonClick, this);

	CreateStatusBar();
}

void MainFrame::onButtonClick(wxCommandEvent& event)
{
	wxLogStatus("Button clicked!");
}

void MainFrame::onSliderChange(wxCommandEvent& event)
{
	wxString message = wxString::Format("Slider value: %d", event.GetInt());
	wxLogStatus(message);
}

void MainFrame::onTextChange(wxCommandEvent& event)
{
	wxString message = wxString::Format("Text changed: %s", event.GetString());
	wxLogStatus(message);
}
