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

int validLogin(char *username, char *password){
	FILE *fp= fopen("users.txt", "r");
	char line[512];
	char *dashboard;
	char *token;

printf("<html>");
printf("<head>");
 	printf("<title>Login</title>");
	printf("<link rel='shortcut icon' href='icon2.png'/>");
	printf("<link rel='stylesheet' type='text/css' href='style.css'>");
printf("</head>");

printf("<body>");
 	printf("<div class='container'>");
		printf("<div class='inner'>");
  			printf("<div class='content'>");
			printf("<h1 style='padding: 21px 0px 0px 0px'>Just Succulent Tuna</h1>");

	while(fgets(line, sizeof(line), fp) != NULL) {
		token=strtok(line,"\n");
		if(strcmp(token, username) == 0) {
			fgets(line,sizeof(line),fp);
			token=strtok(line,"\n");
			if(strcmp(token,password)==0){
				dashboard=concat("http://cs.mcgill.ca/~sjessa3/cgi-bin/ass4/dashboard.py?username=",username);
				printf("<h3>Login successful. Redirecting.</h3>");
				printf("<meta http-equiv='refresh' content='1;url=%s'/>",dashboard);
				exit(1);
				
			}
			else{
				printf("<h3>Invalid password.</h3>");
				printf("<p><a href='website.html'><button type='button'>Welcome Page</button></a>");
				printf("<a href='new_login.html'><button type='button'>Login Page</button></a></p>");
				printf("</html>");
				exit(1);	
			}
		}
	}
	printf("<h3>Invalid username.</h3>");
	printf("<p><a href='website.html'><button type='button'>Welcome Page</button></a>");
	printf("<a href='new_login.html'><button type='button'>Login Page</button></a></p>");
	printf("</html>");
}

int main(int argc, char const *argv[]){
	printf("Content-Type:text/html\n\n");

	char *data = getenv("QUERY_STRING");
	char username[32], password[32];
 
	char *token;
	char buffer[32][32];
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
