
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

int mysys(char *jpgpath)
{
	char cWindowsDirectory[MAX_PATH];  
	char cmd[1000]="\\bin\\call.exe ";
	/*get the executable file path*/

	strcat(cmd,jpgpath);
	/*add the jpeg file path to the cmd*/

	/*get current directory path of the process*/  
	LPTSTR cWinDir = malloc(sizeof(TCHAR)*MAX_PATH);  
	GetCurrentDirectory(MAX_PATH, cWinDir);  
  
	LPTSTR sConLin = strcat(cWinDir ,cmd);  
#if 1
	printf("%d\n",MAX_PATH);
	printf("%s\n",sConLin);
#endif

	STARTUPINFO si;  
	PROCESS_INFORMATION pi;  
  
	ZeroMemory(&si, sizeof(si));  
	ZeroMemory(&pi, sizeof(pi));
	
	/*create a child process 
	and then exec the cmd*/
	if(CreateProcess(NULL,sConLin,NULL,NULL,0,0,NULL,NULL,&si,&pi)){  
		printf("create process success\n");  
		CloseHandle(pi.hProcess);   
		CloseHandle(pi.hThread);   
	}else{
		printf("failed to create process\n"); 
		return -1;
	}
	


	return 0;
}



