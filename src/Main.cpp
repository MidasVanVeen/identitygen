// include wxWidgets
#include <wx/wx.h>
#include "Main.h"

Main::Main(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    SetSize(wxSize(660, 320));
    SetTitle(wxT("Identitygen"));

    // create panel
    m_Panel = new wxPanel(this, wxID_ANY);
    // create sizer
    wxBoxSizer* m_sizer = new wxBoxSizer(wxVERTICAL);
    // create labels
    wxStaticText* label_1 = new wxStaticText(m_Panel, wxID_ANY, wxT("Select gender"));
    m_Radio_Male = new wxRadioButton(m_Panel, wxID_ANY, wxT("Male"));
    m_Radio_Female = new wxRadioButton(m_Panel, wxID_ANY, wxT("Female"));
    wxStaticText* label_2 = new wxStaticText(m_Panel, wxID_ANY, wxT("Select fields to be generated"));
    m_Checkbox_Name = new wxCheckBox(m_Panel, wxID_ANY, wxT("Name"));
    m_Checkbox_Address = new wxCheckBox(m_Panel, wxID_ANY, wxT("Address"));
    m_Checkbox_DOB = new wxCheckBox(m_Panel, wxID_ANY, wxT("Date of birth"));
    m_Checkbox_Phonenumber = new wxCheckBox(m_Panel, wxID_ANY, wxT("Phone number"));
    m_Checkbox_Email = new wxCheckBox(m_Panel, wxID_ANY, wxT("Email"));
    m_Checkbox_Height = new wxCheckBox(m_Panel, wxID_ANY, wxT("Height"));
    m_Checkbox_Weight = new wxCheckBox(m_Panel, wxID_ANY, wxT("Weight"));
    wxStaticText* label_3 = new wxStaticText(m_Panel, wxID_ANY, wxT("Press generate to generate the selected fields"));
    gen_btn = new wxButton(m_Panel, 10001, wxT("Generate"));
    wxStaticText* label_4 = new wxStaticText(m_Panel, wxID_ANY, wxT("Generated output:"), wxPoint(350,10));
    output_list = new wxListBox(m_Panel, wxID_ANY, wxPoint(350,30), wxSize(300,250));

    // add elements to sizer
    m_sizer->Add(label_1, 0, 0, 0);
    m_sizer->Add(m_Radio_Male, 0, 0, 0);
    m_sizer->Add(m_Radio_Female, 0, 0, 0);
    m_sizer->Add(label_2, 0, 0, 0);
    m_sizer->Add(m_Checkbox_Name, 0, 0, 0);
    m_sizer->Add(m_Checkbox_Address, 0, 0, 0);
    m_sizer->Add(m_Checkbox_DOB, 0, 0, 0);
    m_sizer->Add(m_Checkbox_Phonenumber, 0, 0, 0);
    m_sizer->Add(m_Checkbox_Email, 0, 0, 0);
    m_sizer->Add(m_Checkbox_Height, 0, wxALL, 0);
    m_sizer->Add(m_Checkbox_Weight, 0, wxALL, 0);
    m_sizer->Add(label_3, 0, wxALL, 0);
    m_sizer->Add(gen_btn, 0, wxALL, 0);
    m_Panel->SetSizer(m_sizer);
    Layout();

    // create seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // load all lines from names database into vector
    std::ifstream namesFILE("data/names.csv");
    std::string nameline;
    while (std::getline(namesFILE, nameline)) {
        this->namefilelines.push_back(nameline);
    }

    // load all lines from address database into vector
    std::ifstream addressFILE("data/address_list.csv");
    std::string addressline;
    while (std::getline(addressFILE, addressline)) {
        this->addressfilelines.push_back(addressline);
    }

    // load all lines from email providers database into vector
    std::ifstream emailFILE("data/emailProviders.csv");
    std::string emailline;
    while (std::getline(emailFILE,emailline)) {
        this->emailfilelines.push_back(emailline);
    }

    // do the same for random words list
    std::ifstream randomwordsFILE("data/random_words.csv");
    std::string randomwordsline;
    while (std::getline(randomwordsFILE, randomwordsline)) {
        this->randomwordsfilelines.push_back(randomwordsline);
    }

}


// event table
BEGIN_EVENT_TABLE(Main, wxFrame)
    // event for generate button
    EVT_BUTTON(10001, Main::Generate)
END_EVENT_TABLE();

// function triggered when generate button is pressed
void Main::Generate(wxCommandEvent &event)
{
    ClearOutput();
    // check what checkboxes are checked
    if (m_Checkbox_Name->GetValue())
    {
        NameGen(m_Radio_Male->GetValue());
    }
    if (m_Checkbox_Address->GetValue())
    {
        AddressGen();
    }
    if (m_Checkbox_DOB->GetValue())
    {
        DOBGen();
    }
    if (m_Checkbox_Phonenumber->GetValue())
    {
        PhoneNumberGen();
    }
    if (m_Checkbox_Email->GetValue())
    {
        EmailGen();
    }
    if (m_Checkbox_Height->GetValue())
    {
        HeightGen(m_Radio_Male->GetValue());
    }
    if (m_Checkbox_Weight->GetValue())
    {
        WeightGen(m_Radio_Male->GetValue());
    }

    // indicate event has passed
    event.Skip();
}

void Main::NameGen(bool gender)
{
    using std::string;

    // gen random line number
    int randomNumber = std::rand()%3345;
    // fetch line from lines vector
    string fullString = this->namefilelines[randomNumber];
    string firstName;
    // first column = male name
    string maleName = fullString.substr(0, fullString.find(","));
    // remove first column
    fullString.erase(0,maleName.length() + 1);
    // first column = female name
    string femaleName = fullString.substr(0, fullString.find(","));
    // remove first column
    fullString.erase(0,femaleName.length() + 1);
    // first column = last name
    string lastName = fullString.substr(0, fullString.find(","));
    // set name acordingly
    if (gender) {
        firstName = maleName;
    }
    else {
        firstName = femaleName;
    }
    // add to output list
    output_list->AppendString("Name: " + firstName + " " + lastName);
}

void Main::AddressGen()
{
    using std::string;

    // same as namegen
    int randomNumber = std::rand()%1048574;
    string fullString = this->addressfilelines[randomNumber];
    string zipCode = fullString.substr(0,fullString.find(","));
    fullString.erase(0,zipCode.length()+1);
    string streetName = fullString.substr(0,fullString.find(","));
    fullString.erase(0,streetName.length()+1);
    string streetName_2 = fullString.substr(0,fullString.find(","));
    fullString.erase(0,streetName_2.length()+1);
    string number = fullString.substr(0,fullString.find(","));
    fullString.erase(0,number.length()+1);
    string number_2 = fullString.substr(0,fullString.find(","));
    fullString.erase(0,number_2.length()+1);
    string county = fullString.substr(0,fullString.find(","));

    output_list->AppendString("Zipcode: " + zipCode);
    output_list->AppendString("Address: " + streetName + " " + streetName_2);
    output_list->AppendString("House number: " + number + number_2);
    output_list->AppendString("County: " + county);
}

void Main::DOBGen()
{
    using std::rand;
    // generate random values
    int day = rand()%29 + 1;
    int month = rand()%12 + 1;
    int year = rand()%60 + 1940;

    // add to output list
    output_list->AppendString("Date of birth: " + std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year));
}

void Main::PhoneNumberGen()
{
    using std::rand;
    using std::to_string;
    // gen random values
    int areacode = rand()%788 + 201;
    int num1 = rand()%9 + 1;
    int num2 = rand()%9 + 1;
    int num3 = rand()%9 + 1;
    int num4 = rand()%9 + 1;
    int num5 = rand()%9 + 1;
    int num6 = rand()%9 + 1;
    int num7 = rand()%9 + 1;

    // add to output list
    output_list->AppendString("Phone number: (" + to_string(areacode) + ") " + to_string(num1)+to_string(num2)+to_string(num3) + "-" + to_string(num4)+to_string(num5)+to_string(num6)+to_string(num7));
}

void Main::EmailGen()
{
    using std::string;
    using std::rand;

    // take random email provider from email provider vector
    string provider = emailfilelines[rand()%7 + 1];
    // take two random words from random words vector
    string word1 = randomwordsfilelines[rand()%800 + 1];
    string word2 = randomwordsfilelines[rand()%800 + 1];
    // gen random number and convert to string
    string number = std::to_string(rand()%100);

    // add to output list
    output_list->AppendString("Email: " + word1 + number + word2 + provider);
}

void Main::HeightGen(bool gender)
{
    // average male height = 176 cm
    int maleheight = std::rand()%10 + 170;
    // average female height = 163 cm
    int femaleheight = std::rand()%10 + 158;
    int height;
    // set height accordingly
    if (gender) {
        height = maleheight;
    }
    else {
        height = femaleheight;
    }

    // add to output list
    output_list->AppendString("Height: " + std::to_string(height) + "cm");
}

void Main::WeightGen(bool gender)
{
    // average weight for men in the usa is 90kg
    int maleweight = std::rand()%10 + 85;
    // average weight for women in the usa is 70 kg
    int femaleweight = std::rand()%10 + 65;
    int weight;
    // set weight accordingly
    if (gender) {
        weight = maleweight;
    }
    else {
        weight = femaleweight;
    }

    // add to output
    output_list->AppendString("Weight: " + std::to_string(weight) + "kg");
}

void Main::ClearOutput()
{
    // clear output list
    output_list->Clear();
}
