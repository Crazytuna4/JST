#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validUsername(char *username){
	FILE *fp= fopen("users.txt", "r");
	char line[512];
	char *token;

	while(!feof(fp)){
		fgets(line,sizeof(line),fp);
		token=strtok(line,"\n");

		if(strcmp(token, username) == 0) 
			return(0);
		int pos=0;
		do{
			fgets(line,sizeof(line),fp);
			pos++;
		}while(pos<3);
	}
}
int addUsername(char *username){
	FILE *fp= fopen("users.txt", "a");

	fputs("\n",fp);
	fputs(username,fp);
	
	fclose(fp);
	return(0);
}

int addPassword(char *password){
	FILE *fp= fopen("users.txt", "a");

	fputs("\n",fp);
	fputs(password,fp);
	
	fclose(fp);
	return(0);
}

int addFullName(char *fullname){
	FILE *fp= fopen("users.txt", "a");

	fputs("\n",fp);
	fputs(fullname,fp);
	
	fclose(fp);
	return(0);
}

int addJob(char *job){
	FILE *fp= fopen("users.txt", "a");

	fputs("\n",fp);
	fputs(job,fp);
	
	fclose(fp);
	return(0);
}

int addToList(char *username){
	FILE *fp= fopen("/home/2015/sjessa3/public_html/cgi-bin/ass4/friends.txt", "a");

	fputs("\n",fp);
	fputs(username,fp);
	
	fclose(fp);
	return(0);
}

int main(int argc, char const *argv[]){
	printf("Content-Type:text/html\n\n");
	char *data = getenv("QUERY_STRING");

	char username[32],password[32],fullname[32],job[32];

	char *token;
	char line[512];
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
	strcpy(fullname,buffer[5]);
	strcpy(job,buffer[7]);
	
	printf("<html>");
printf("<head>");
 	printf("<title>Register</title>");
	printf("<link rel='shortcut icon' href='icon2.png'/>");
	printf("<link rel='stylesheet' type='text/css' href='style.css'>");
printf("</head>");

printf("<body>");
 	printf("<div class='container'>");
		printf("<div class='inner'>");
  			printf("<div class='content'>");
			printf("<h1 style='padding: 21px 0px 0px 0px'>Just Succulent Tuna</h1>");

	if(validUsername(username)==0){
		printf("<h3>Username taken.</h3>");
		printf("<p><a href='website.html'><button type='button'>Welcome Page</button></a>");
		printf("<a href='new_register.html'><button type='button'>Register Page</button></a></p>");
		printf("</html>");
		exit(1);
	}
			
	addUsername(username);
	addPassword(password);
	addFullName(fullname);
	addJob(job);
	addToList(username);
	printf("<h3>Registration complete.</h3>");
	printf("<p><a href='website.html'><button type='button'>Welcome Page</button></a>");
	printf("<a href='new_login.html'><button type='button'>Login Page</button></a></p>");
	printf("</body>");
	printf("</html>");
}
