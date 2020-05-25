#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <string>
#include <cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int update_url(string neturl, int linenum) {
	char   psBuffer[32768];
	FILE   *pPipe;
	string str;

	ifstream infile("iptv.m3u");
	ofstream tempfile("temp.txt");
	if (!infile) {
		printf("Error! File not found."); 
		return 1;
	}

	for(unsigned int i=0; i < linenum - 1; i++) {
		getline(infile,str);
		tempfile << str << endl;
		//cout << str << endl;
	}
	
   	string cmdnet = "youtube-dl -f 94 -g ";
	cmdnet += neturl;
   if( (pPipe = _popen(cmdnet.c_str(), "rb" )) == NULL )
      exit( 1 );
	
   while(fgets(psBuffer, 32768, pPipe))
   {
      	puts(psBuffer);
      	cout << "\n Output is:\n";
      	string t(psBuffer);
      	if (!t.empty() && t[t.length()-1] == '\n') {
    		t.erase(t.length()-1);
		}
      	t += "|Referer=";
      	t += neturl;
      	cout << t << "\n";
		
		tempfile << t << endl;
		getline(infile,str);
   } 
   
   while(getline(infile,str)) {
		tempfile << str << endl;
		//cout << str << endl;
   }

	// close file
	infile.close();
	tempfile.close();
	
	remove("iptv.m3u");
   rename("temp.txt", "iptv.m3u");
   remove("temp.txt");
   
   if (feof( pPipe))
   {
     printf( "\nProcess returned %d\n", _pclose( pPipe ) );
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   
   return 0;
}

int main(int argc, char** argv) {
   string url1 = "https://www.youtube.com/channel/UCcZg5r9hBqK_VPUT2I7eYVw/live"; //bernama
   string url2 = "https://www.youtube.com/channel/UCQo_L_h_01NjLYiNHUnjEJw/live"; //reformed21
   string url3 = "https://www.youtube.com/channel/UCTR1wO3hnYzBs0BJIQAyZKw/live"; //hope channel
   string url4 = "https://www.youtube.com/channel/UCER4rvDnRBPr_ncYW4UCZjg/live"; //tvone
   string url5 = "https://www.youtube.com/channel/UC5BMIWZe9isJXLZZWPWvBlg/live"; //kompastv
   string url6 = "https://www.youtube.com/channel/UC1-ATnDVEwKT6-0aEeJ2ibA/live"; //net
   string url7 = "https://www.youtube.com/channel/UCzVtD2LBJ29L6Tz4YzLLAcg/live"; //gprtv
   string url8 = "https://www.youtube.com/channel/UCoMdktPbSTixAyNGwb-UYkQ/live"; //skynews
   update_url(url1,151);
   update_url(url2,103);
   update_url(url3,100);
   update_url(url4,97);
   update_url(url5,94);
   update_url(url6,91);
   update_url(url7,67);
   update_url(url8,187);
   return 0;
   system("git add .");
   system("git commit -m \"auto update\"");
   system("git push");
   
}
