#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char **argv){
	char inputFile[256];
	char outputFile[256];
	int fd_r,fd_w;
	int fileSize;
	char *buf;

	strcpy(inputFile,argv[1]);
	strcpy(outputFile,argv[2]);
	
	fd_r=open(inputFile,O_RDONLY);
	fd_w=open(outputFile,O_WRONLY);

	if(fd_w < 0){
		open(outputFile,O_CREAT);
		fd_w=open(outputFile,O_WRONLY);
	}
	
	fileSize=lseek(fd_r,0,SEEK_END);
	buf=(char *)malloc(fileSize+1);
	lseek(fd_r,0,SEEK_SET);

	read(fd_r,buf,fileSize);
	buf[fileSize]='\0';
	write(fd_w,buf,fileSize);
	return 0;
}
