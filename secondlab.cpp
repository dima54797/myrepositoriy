#include <iostream> 
#include <string>
#include <ctype.h>
#include <fstream>
using namespace std;

int size_word(string read_string)
{
	string new_str, word = "";
	int temp_back = 1, couter = 0, rec = 0;
	for (char i : read_string) {

		if ((temp_back == 1) && (i != ' ')) {
			couter++;
			new_str = "";
		}

		if (i == ' ') { temp_back = 1; new_str += i; continue; }
		else { temp_back = 0; }

		new_str += i;
	}
	return couter;

}
//some configuration reading
//one more nice code block
//not so good as it could be but OK

int main(int argc, char* argv[]) {
	ifstream in;
	string consol_string, f_string, line;
	int a_con = 0, a_file = 0, f_size = 0, two_arg = 0;




	for (int count = 0; count < argc; ++count)
	{
		if ((a_con == 1) || (a_file == 1))
		{
			consol_string += argv[count];
			consol_string += ' ';
		}

		if (strcmp(argv[count], "-f") == 0)
		{
			if (a_con == 1) {
				two_arg = 1;
				break;
			}
			a_file = 1;
		}

		if (strcmp(argv[count], "-c") == 0)
		{
			if (a_file == 1) {
				two_arg = 1;
				break;
			}
			a_con = 1;
		}

		if (strcmp(argv[count], "-h") == 0)
		{
			cout << "This program counts the number of words.\nArguments :\n\n-v Version\n\n-c Size of word after argument\n\n-f Size of word in file *you must say way to file*\nAll rights reserved.\n";
		}

		if (strcmp(argv[count], "-v") == 0)
		{
			cout << "Version 1.2\n";
		}
	}
	if (two_arg == 1) {
		cout << "\nOnly one argument '-f' or '-c'\n";

	}
	else{
		if (a_file == 1)
		{
			in.open(consol_string);
			while (getline(in, line))
			{
				f_size += size_word(line);
			}
			in.close();
			cout << "Size word : " << f_size;
		}
		else if (a_con == 1)
		{
			cout << "Size word : " << size_word(consol_string);
		}
		else
		{
			cout << "\nEnter some words : ";
			getline(cin, f_string);
			cout << "Size word : " << size_word(f_string);
		}
	}
}
