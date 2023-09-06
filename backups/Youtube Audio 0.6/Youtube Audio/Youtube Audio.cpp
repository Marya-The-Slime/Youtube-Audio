#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <conio.h>

using namespace std;

//-------------------------------------------------- Global Variables --------------------------------------------------

string File_Name = "Path.txt";
string Youtube_Link;

ofstream File_To_Write;
ifstream File_To_Read;
FILE* File_Path;

int File_Size;

string Site_Link = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";

ostringstream Start_Site_Link;

//--------------------------------------------------
int main();
//--------------------------------------------------
void Get_File_Size()
{// Get file size for check if Path to download folder is empty
	fopen_s(&File_Path, "Path.txt", "rb");

	if (File_Path != 0)
	{
		fseek(File_Path, 0, SEEK_END);

		File_Size = ftell(File_Path);

		fclose(File_Path);
	}
	else
	{
		File_To_Write.open(File_Name);
		File_To_Write.close();
		Get_File_Size();
	}
}
//--------------------------------------------------
void Set_Path()
{// Set path from user to file

	string path_to_download;

	std::cout << "Enter path where you want see MP3: " << endl;

	do
	{
		if (getchar() == '\n')
		{
			File_To_Write << path_to_download;

			std::cout << "Path successfully saved" << endl;

			File_To_Write.close();

			break;
		}
		else
		{
			getline(cin, path_to_download);
		}
	} while (_kbhit());

}
//--------------------------------------------------
string Get_Path()
{
	File_To_Read.open(File_Name);

	if (File_To_Read.is_open())
	{
		string path;
		while (getline(File_To_Read, path))
		{
		}
		File_To_Read.close();
		return path;
	}
	else
	{
		std::cout << "Can't read file" << endl;
	}
}
//--------------------------------------------------
void Check_Path()
{// Check if file empty or user want rewrite path

	File_To_Write.open(File_Name, 'a');

	char answer_check;
	string path = Get_Path();

	if (File_Size > 3)
	{
		std::cout << "Your path: " << path << endl;
		std::cout << endl;

		File_To_Write.close();
	}
	else
	{
		if (File_To_Write.is_open())
		{
			Set_Path();
		}
		else
		{
			std::cout << "ERROR with opening file" << endl;;
		}
	}
}
//--------------------------------------------------
void Empty_File()
{
	File_To_Write.open(File_Name, ofstream::out | ofstream::trunc);

	if (File_To_Write.is_open())
	{
		File_To_Write << "";
	}

	File_To_Write.close();

	std::cout << "File was cleared" << endl;
}
//--------------------------------------------------
void Set_Youtube_Link()
{//Set link to youtube video from you want download audio

	do
	{
		if (getchar() == '\t')
		{
			cout << "Work TAB in Set_Youtube_Link" << endl;
			Empty_File();
			Check_Path();
			break;
		}
		if (getchar() == '\n')
		{
			cout << "Work ENTER in Set_Youtube_Link" << endl;
			std::cout << "You link: " << Youtube_Link << endl;
			break;
		}
		else
		{
			getline(cin, Youtube_Link);
		}

	} while (_kbhit());

}
//--------------------------------------------------
int main()
{

	Get_File_Size();

	Check_Path();

	std::cout << "Enter link at youtube video or enter <TAB> to rewrite it: " << endl;

	Set_Youtube_Link();

	Start_Site_Link << "start " << Youtube_Link;

	string start_link = Start_Site_Link.str();

	system(start_link.c_str());
}
//--------------------------------------------------


//--------------------------------------------------
// Program work step by step:
/*
1. Program read text document for get path to download folder
1.1 If text document empty - ask for write path
2. Program ask link to youtube video
2.1 If link not to youtube video - throw exception
3. Send link to site y2mate or edit link youtube.com to youtube.compp(?)
4. Use y2mate scripts for download audio to folder that we set early
*/
//--------------------------------------------------
// Program develop plan:
/*
	Save path to text file
	1. Create text file in program folder ✔
	2. Create function for set path to text file ✔
	2.1 Create function for change path if it needed

	Get path from text file
	1. Create function for get path from text file to variable
	2. Check if the text file already have path
	2.1 Ask user write path if text file empty
	2.2 Give for user choose for changing path
	3. Set path to variable

	Download mp3 from y2mate to folder by path
	1. Set link in to text bar on site
	2. Activate searching script for youtube video on site
	3. Select your video
	4. Select Audio folder
	5. Download mp3 in to folder at path
*/