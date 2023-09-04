#include <msclr\marshal_cppstd.h>
#include "winform.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using utils::is_integer;


[STAThreadAttribute]
int main()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	WinForm form;

	Application::Run(% form);
}

System::Void WinForm::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	string name = convert(this->NameBox->Text);
	string sx = convert(this->XBox->Text);
	string sy = convert(this->YBox->Text);
	string type = convert(this->TypeBox->Text);
	string stime = convert(this->TimeBox->Text);
	string unsorted_str_for_UI = api->get_unsorted_str();

	api->add(name, sx, sy, type, stime);

	//Just for GUI, unsorted objexts
	this->Unsorted_list->Text = convert(unsorted_str_for_UI);
}

System::Void WinForm::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	stringstream stream;
	api->save(stream);

	//Just for GUI, sorted objexts
	this->TextBox->Text = convert(stream.str());
}

System::Void WinForm::Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	stringstream stream;
	api->load(stream);

	//Just for GUI, unsorted objexts
	string unsorted_str_for_UI = api->get_unsorted_str();
	this->Unsorted_list->Text = convert(unsorted_str_for_UI);
}

System::Void WinForm::Clear_Click(System::Object^ sender, System::EventArgs^ e)
{
	api->clear();
	this->Unsorted_list->Text = System::String::Empty;
}


//Just passes values from the user to objectlist class
System::Void WinForm::intervalBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox2->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_xy0(stoi(tmp));
	else
		this->intervalBox2->Text = api->get_interval_xy0().ToString();
}
System::Void WinForm::intervalBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox3->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_xy1(stoi(tmp));
	else
		this->intervalBox3->Text = api->get_interval_xy1().ToString();
}
System::Void WinForm::intervalBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox4->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_xy2(stoi(tmp));
	else
		this->intervalBox4->Text = api->get_interval_xy2().ToString();
}
System::Void WinForm::intervalBox5_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox5->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_xy3(stoi(tmp));
	else
		this->intervalBox5->Text = api->get_interval_xy3().ToString();
}
System::Void WinForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox2->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_time0(stoi(tmp));
	else
		this->textBox2->Text = api->get_interval_time0().ToString();
}
System::Void WinForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox3->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_time1(stoi(tmp));
	else
		this->textBox3->Text = api->get_interval_time1().ToString();
}
System::Void WinForm::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox4->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_time2(stoi(tmp));
	else
		this->textBox4->Text = api->get_interval_time2().ToString();
}
System::Void WinForm::textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox5->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_interval_time3(stoi(tmp));
	else
		this->textBox5->Text = api->get_interval_time3().ToString();
}
System::Void WinForm::textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox7->Text);

	if (is_integer(tmp) && !tmp.empty())
		api->set_num(stoi(tmp));
	else
		this->textBox7->Text = api->get_num().ToString();
}

//Utils
string WinForm::convert(System::String^ convertable)
{
	return msclr::interop::marshal_as<std::string>(convertable);
}

System::String^ WinForm::convert(std::string convertable)
{
	return msclr::interop::marshal_as<System::String^>(convertable)->Replace("\n", "\r\n");
}