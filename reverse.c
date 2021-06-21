#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void swap(char *a,char *b);

int main(int argc,char **argv){
	int fd_r,fd_w;
	char inputFile[256];
	char *buf;
	int fileSize;
	
	strcpy(inputFile,argv[1]);
	fd_r=open(inputFile,'r');
	fd_w=open(inputFile,'w');
	fileSize=lseek(fd_r,0,SEEK_END);
	buf=(char *)malloc(fileSize+1);
	lseek(fd_r,0,SEEK_SET);		
	
	read(fd_r,buf,fileSize);
	for(int i=0; i<fileSize/2; i++){
		swap(buf+i,buf+fileSize-1-i);
	}
	buf[fileSize]='\0';	
	write(1,buf,fileSize);
	return 0;
}

void swap(char *a,char *b){
	char tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

