#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int git_pull(){
	char   psBuffer[1024];
	FILE   *pPipe;
	
	//ofstream gitlogfile("gitaddlog.txt");
#ifdef WIN32
	if( (pPipe = _popen("git pull origin", "rb" )) == NULL )
      exit( 1 );
#elif __linux__
	if( (pPipe = popen("git pull origin", "rb" )) == NULL )
      exit( 1 );
#endif

   while(fgets(psBuffer, 1024, pPipe))
   {
      	puts(psBuffer);
      	//gitlogfile << psBuffer << endl;
    } 
    //gitlogfile.close();
    
    if (feof( pPipe))
   {
#ifdef WIN32
    	printf( "\nProcess returned %d\n", _pclose( pPipe ) );
#elif __linux__
		printf( "\nProcess returned %d\n", pclose( pPipe ) );
#endif
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   
   return 0;
}

int git_add(){
	char   psBuffer[1024];
	FILE   *pPipe;
	
	//ofstream gitlogfile("gitaddlog.txt");
#ifdef WIN32
	if( (pPipe = _popen("git add .", "rb" )) == NULL )
      exit( 1 );
#elif __linux__
	if( (pPipe = popen("git add .", "rb" )) == NULL )
      exit( 1 );
#endif

   while(fgets(psBuffer, 1024, pPipe))
   {
      	puts(psBuffer);
      	//gitlogfile << psBuffer << endl;
    } 
    //gitlogfile.close();
    
    if (feof( pPipe))
   {
#ifdef WIN32
    	printf( "\nProcess returned %d\n", _pclose( pPipe ) );
#elif __linux__
		printf( "\nProcess returned %d\n", pclose( pPipe ) );
#endif
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   
   return 0;
}

int git_commit(){
	char   psBuffer[1024];
	FILE   *pPipe;
	
	//ofstream gitlogfile("gitcommitlog.txt");
#ifdef WIN32
	if( (pPipe = _popen("git commit -m \"auto update service\"", "rb" )) == NULL )
      exit( 1 );
#elif __linux__
	if( (pPipe = popen("git commit -m \"auto update service\"", "rb" )) == NULL )
      exit( 1 );
#endif
	
   while(fgets(psBuffer, 1024, pPipe))
   {
      	puts(psBuffer);
      //	gitlogfile << psBuffer << endl;
    } 
    //gitlogfile.close();
    
    if (feof( pPipe))
   {
#ifdef WIN32
    	printf( "\nProcess returned %d\n", _pclose( pPipe ) );
#elif __linux__
		printf( "\nProcess returned %d\n", pclose( pPipe ) );
#endif
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   
   return 0;
}

int git_push(){
	char   psBuffer[1024];
	FILE   *pPipe;
	
	//ofstream gitlogfile("gitpushlog.txt");
#ifdef WIN32
	if( (pPipe = _popen("git push origin", "rb" )) == NULL )
      exit( 1 );
#elif __linux__
	if( (pPipe = popen("git push origin", "rb" )) == NULL )
      exit( 1 );
#endif

   while(fgets(psBuffer, 1024, pPipe))
   {
      	puts(psBuffer);
      //	gitlogfile << psBuffer << endl;
    } 
    //gitlogfile.close();
    
    if (feof( pPipe))
   {
#ifdef WIN32
    	printf( "\nProcess returned %d\n", _pclose( pPipe ) );
#elif __linux__
		printf( "\nProcess returned %d\n", pclose( pPipe ) );
#endif
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   
   return 0;
}

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

	for(int i=0; i < linenum - 1; i++) {
		getline(infile,str);
		tempfile << str << endl;
		//cout << str << endl;
	}
	
   	string cmdnet = "youtube-dl -f 94 -g ";
	cmdnet += neturl;
#ifdef WIN32
   if( (pPipe = _popen(cmdnet.c_str(), "rb" )) == NULL )
      exit( 1 );
#elif __linux__
   if( (pPipe = popen(cmdnet.c_str(), "rb" )) == NULL )
      exit( 1 );
#endif

   while(fgets(psBuffer, 32768, pPipe))
   {
      	puts(psBuffer);
      	//cout << "\n Output is:\n";
      	string t(psBuffer);
      	if (!t.empty() && t[t.length()-1] == '\n') {
    		t.erase(t.length()-1);
		}
      	t += "|Referer=";
      	t += neturl;
      	//cout << t << "\n";
		
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
#ifdef WIN32
    	printf( "\nProcess returned %d\n", _pclose( pPipe ) );
#elif __linux__
		printf( "\nProcess returned %d\n", pclose( pPipe ) );
#endif
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   
   return 0;
}

int update_dm(string dmurl, int linenum) {
	char   psBuffer[32768];
	FILE   *pPipe;
	string str;

	ifstream infile("iptv.m3u");
	ofstream tempfile("temp.txt");
	if (!infile) {
		printf("Error! File not found."); 
		return 1;
	}

	for(int i=0; i < linenum - 1; i++) {
		getline(infile,str);
		tempfile << str << endl;
		//cout << str << endl;
	}
	
   	string cmdnet = "youtube-dl -f hls-480-0 -g ";
	cmdnet += dmurl;
#ifdef WIN32
   if( (pPipe = _popen(cmdnet.c_str(), "rb" )) == NULL )
      exit( 1 );
#elif __linux__
   if( (pPipe = popen(cmdnet.c_str(), "rb" )) == NULL )
      exit( 1 );
#endif	
	
   while(fgets(psBuffer, 32768, pPipe))
   {
      	puts(psBuffer);
      	//cout << "\n Output is:\n";
      	string t(psBuffer);
      	if (!t.empty() && t[t.length()-1] == '\n') {
    		t.erase(t.length()-1);
		}
      	t += "|Referer=";
      	t += dmurl;
      	//cout << t << "\n";
		
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
#ifdef WIN32
    	printf( "\nProcess returned %d\n", _pclose( pPipe ) );
#elif __linux__
		printf( "\nProcess returned %d\n", pclose( pPipe ) );
#endif
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
   string url9 = "https://www.youtube.com/channel/UCSrZ3UV4jOidv8ppoVuvW9Q/live"; //euronews
   string url10 = "https://www.youtube.com/channel/UC4K_LI-Tn3-LshNgG0-YypQ/live"; //cctv4
   string url11 = "https://www.dailymotion.com/embed/video/kxm1wihUkjNiINrAqlg"; //ntv7
   string url12 = "https://www.dailymotion.com/embed/video/kdFzSYy1bHxrForBrar"; //8tv
   string url13 = "https://www.dailymotion.com/embed/video/k1FijVynGNsZ2ZrAGJ0"; //tv9
   string url14 = "https://www.youtube.com/channel/UCWw_gejTX29Yn89LLpcINZQ/live"; //kbs world
   string url15 = "https://www.youtube.com/channel/UCf1y3FvYJYPbgMqHX7ZzeZA/live"; //sbn us
   string url16 = "https://www.youtube.com/channel/UC7E-LYc1wivk33iyt5bR5zQ"; //vaticanmedia
   update_url(url1,151);
   update_url(url2,103);
   update_url(url3,100);
   update_url(url4,97);
   update_url(url5,94);
   update_url(url6,91);
   update_url(url7,67);
   update_url(url8,187);
   update_url(url9,214);
   update_url(url10,217);
   update_dm(url11,220);
   update_dm(url12,223);
   update_dm(url13,226);
   update_url(url14,229);
   update_url(url15,232);
   update_url(url16,244);
   git_add();
   git_commit();
   git_push();
   return 0;
}
