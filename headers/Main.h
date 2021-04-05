#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <wx/image.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

class Main: public wxFrame {
public:
    Main(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);

private:
    std::vector<std::string> namefilelines;
    std::vector<std::string> addressfilelines;
    std::vector<std::string> emailfilelines;
    std::vector<std::string> randomwordsfilelines;

protected:
    wxPanel* m_Panel;
    wxRadioButton* m_Radio_Male;
    wxRadioButton* m_Radio_Female;
    wxCheckBox* m_Checkbox_Name;
    wxCheckBox* m_Checkbox_Address;
    wxCheckBox* m_Checkbox_DOB;
    wxCheckBox* m_Checkbox_Phonenumber;
    wxCheckBox* m_Checkbox_Email;
    wxCheckBox* m_Checkbox_Height;
    wxCheckBox* m_Checkbox_Weight;
    wxButton* gen_btn;
    wxListBox* output_list;
    wxButton* clear_btn;

    DECLARE_EVENT_TABLE();

public:
    virtual void Generate(wxCommandEvent &event); 
    
    void NameGen(bool gender);
    void AddressGen();
    void DOBGen();
    void PhoneNumberGen();
    void EmailGen();
    void HeightGen(bool gender);
    void WeightGen(bool gender);
    void ClearOutput();
}; 


#endif // MAIN_H
