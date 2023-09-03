#include <msclr\marshal_cppstd.h>
#include "winform.h"
#include "fileworker.h"
#include "objects.h"

using namespace System;
using namespace System::Windows::Forms;
using utils::is_double;
using utils::is_integer;
using namespace std;

FileWorker* fileworker;
ObjectsList* objlist;

[STAThreadAttribute]
int main()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	fileworker = new FileWorker();
	objlist = new ObjectsList();
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

	if (!is_double(sx) || !is_double(sy) || !is_integer(stime))
	{
		return;
	}
	if (sx.empty() || sy.empty() || name.empty() || type.empty())
	{
		return;
	}

	double dx = stod(sx);
	double dy = stod(sy);
	time_t now;

	if(stime.empty())
	{
		now = time(0);
	}
	else
	{
		now = stoll(stime);
	}

	RawObject tmp = RawObject(name, dx, dy, type, now);
	objlist->add(tmp);

	this->Unsorted_list->Text = convert(objlist->unsorted_str_for_UI);
}

System::Void WinForm::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	stringstream stream;
	objlist->to_str(stream);
	fileworker->save(stream);
	
	//Just for GUI, sorted objexts
	this->TextBox->Text = convert(stream.str());
}

System::Void WinForm::Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	stringstream stream;
	fileworker->load(stream);
	objlist->add(stream);

	//Just for GUI, unsorted objexts
	this->Unsorted_list->Text = convert(objlist->unsorted_str_for_UI);
}

System::Void WinForm::Clear_Click(System::Object^ sender, System::EventArgs^ e)
{
	objlist->clear();
	this->Unsorted_list->Text = System::String::Empty;
}


//Just passes values from the user to objectlist class
System::Void WinForm::intervalBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox2->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_xy[0] = stoi(tmp);
	else
		this->intervalBox2->Text = objlist->intervals_xy[0].ToString();
}
System::Void WinForm::intervalBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox3->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_xy[1] = stoi(tmp);
	else
		this->intervalBox3->Text = objlist->intervals_xy[1].ToString();
}
System::Void WinForm::intervalBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox4->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_xy[2] = stoi(tmp);
	else
		this->intervalBox4->Text = objlist->intervals_xy[2].ToString();
}
System::Void WinForm::intervalBox5_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->intervalBox5->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_xy[3] = stoi(tmp);
	else
		this->intervalBox5->Text = objlist->intervals_xy[3].ToString();
}
System::Void WinForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox2->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_time[0] = stoi(tmp);
	else
		this->textBox2->Text = objlist->intervals_time[0].ToString();
}
System::Void WinForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox3->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_time[1] = stoi(tmp);
	else
		this->textBox3->Text = objlist->intervals_time[1].ToString();
}
System::Void WinForm::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox4->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_time[2] = stoi(tmp);
	else
		this->textBox4->Text = objlist->intervals_time[2].ToString();
}
System::Void WinForm::textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox5->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->intervals_time[3] = stoi(tmp);
	else
		this->textBox5->Text = objlist->intervals_time[3].ToString();
}
System::Void WinForm::textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	string tmp = convert(this->textBox7->Text);

	if (is_integer(tmp) && !tmp.empty())
		objlist->num_obj_for_new_type = stoi(tmp);
	else
		this->textBox7->Text = objlist->num_obj_for_new_type.ToString();
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