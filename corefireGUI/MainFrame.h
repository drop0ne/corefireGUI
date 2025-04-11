#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
	public:
	MainFrame(const wxString& title);
private:
	void onAnyClick(wxCommandEvent& event);
	void onButton1Click(wxCommandEvent& event);
	void onButton2Click(wxCommandEvent& event);
	void onClose(wxCloseEvent& event);
};

