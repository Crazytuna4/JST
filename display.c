#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char *url, char *username)
{
    	char *result = malloc(strlen(url)+strlen(username)+1);    
	strcpy(result, url);
   	strcat(result, username);
   	return result;
}

int validUsername(char *username){
	FILE *fp= fopen("users.txt", "r");
	char line[512];
	char *token;

	//while(fgets(line, sizeof(line), fp) != NULL) {
	while(!feof(fp)){
		fgets(line,sizeof(line),fp);
		token=strtok(line,"\n");
		if(strcmp(token, username) == 0) 
			return(1);
		int pos=0;
		do{
			fgets(line,sizeof(line),fp);
			pos++;
		}while(pos<3);
	}
}

int main(int argc, char const *argv[]){
	printf("Content-Type:text/html\n\n");

	char *data = getenv("QUERY_STRING");
	char username[32], password[32];
 
	char *token;
	char buffer[4][32];
	char separators[] = "=,&";
	int pos=0;
	token = strtok(data, separators);
	while (token != NULL){
		strcpy (buffer[pos], token);
		pos++;
		token = strtok(NULL, separators);
	}
	strcpy(username,buffer[1]);
	strcpy(password,buffer[3]);

	validLogin(username,password);
}
