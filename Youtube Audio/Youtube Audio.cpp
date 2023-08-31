#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <sstream>

using namespace std;

//-------------------------------------------------- Global Variables --------------------------------------------------

string Path_To_File = "Path.txt";
string Youtube_Link;

ofstream File_To_Write;
FILE* File_Path;

int File_Size;

string Site_Link = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";

ostringstream Start_Site_Link;


//--------------------------------------------------
void Get_File_Size()
{// Get file size for check if Path to download folder is empty
   fopen_s(&File_Path, "Path.txt", "rb");

   fseek(File_Path, 0, SEEK_END);

   File_Size = ftell(File_Path);

   fclose(File_Path);
}
//--------------------------------------------------
void Set_Path(string path_to_download)
{// Set path from user to file
   cout << "Enter path where you want see MP3: " << endl;

   getline(cin, path_to_download);

   File_To_Write << path_to_download;

   cout << "Path successfully saved" << endl;

   File_To_Write.close();
}
//--------------------------------------------------
void Check_Path()
{// Check if file empty or user want rewrite path

   string path_to_download;

   File_To_Write.open(Path_To_File, 'a');

   if (File_Size > 2)
   {
      cout << "Path arleady set" << endl;

      File_To_Write.close();
   }
   else
   {
      if (File_To_Write.is_open())
      {
         Set_Path(path_to_download);
      }
      else
      {
         cout << "ERROR with opening file" << endl;;
      }
   }
}
//--------------------------------------------------
void Set_Youtube_Link()
{//Set link to youtube video from you want download audio

   cin >> Youtube_Link;

   cout << endl << "You link: " << Youtube_Link;
}
//--------------------------------------------------
int main()
{
   Get_File_Size();
   Check_Path();

   cout << "Enter link at youtube video: ";

   Set_Youtube_Link();

   Start_Site_Link << "start " << Youtube_Link;

   string start_link = Start_Site_Link.str();

   system(start_link.c_str());
}
//--------------------------------------------------

//--------------------------------------------------
//string Get_Path()
//{
//
//}
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