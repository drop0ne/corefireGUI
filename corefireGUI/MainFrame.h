#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
	public:
	MainFrame(const wxString& title);
private:
	void onButtonClick(wxCommandEvent& event);
	void onSliderChange(wxCommandEvent& event);
	void onTextChange(wxCommandEvent& event);
};

