#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
	char inputFile[256];
	int fd_r,fd_w;
	int fileSize;
	char* buf;

	strcpy(inputFile,argv[1]);
	fd_r=open(inputFile,O_RDONLY);
	fd_w=open(inputFile,O_WRONLY);
	fileSize=lseek(fd_r,0,SEEK_END);
	lseek(fd_r,0,SEEK_SET);
	buf=(char *)malloc(fileSize+1);
	
	read(fd_r,buf,fileSize);
	buf[fileSize]='\0';
	for(int i=0; i<fileSize; i++){
		if(isupper(buf[i])){
			buf[i]=tolower(buf[i]);
		}
	}

	write(fd_w,buf,fileSize);
	return 0;
}
