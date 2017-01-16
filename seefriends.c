#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char friends[128][128];
int work = 0;

char* concat(char *url, char *username)
{
    	char *result = malloc(strlen(url)+strlen(username)+1);    
	strcpy(result, url);
   	strcat(result, username);
   	return result;
}

void initBuffer (char *inputLine){
	char *string=inputLine;
	char separators[] = " ,'\n'";
	char *token;
	int pos=0;

	token = strtok(string, separators);
	while (token != NULL){
		strcpy (friends[pos], token);
		pos++;
		work++;
		token = strtok(NULL, separators);
	}
}


bool hasNextToken(){
	if (strcmp(friends[work + 1], "") == 0)
		return 0;
	else 
		return 1;
}

char *nextToken(){
	//int temp = work;
	work++;
	/*if (strcmp(friends[work +1], "") == 0) 
		return NULL;
	else */
		return friends[work];
}

void myRewind(){
	
	int i;
	for (i=0;i!=work;i++)
		strcpy(friends[i],"");
	work = 0;

}

int main(int argc, char const *argv[]){
	printf("Content-Type:text/html\n\n");
	printf("<html>");

	FILE *fp= fopen("/home/2015/sjessa3/public_html/cgi-bin/ass4/friends.txt", "r");
	char line[512];

	char *profile;
	char *username;
	char *hidden;
	char *full;
	char *dashboard;

	char *data = getenv("QUERY_STRING");
	char buffer[128][128];
	char *token;
	char separators[] = "=";
	int pos=0;
	
	token = strtok(data, separators);
	while (token != NULL){
		strcpy (buffer[pos], token);
		pos++;
		token = strtok(NULL, separators);
	}
	username=buffer[1];
	
printf("<html>");
printf("<head>");
 	printf("<title>See Friends</title>");
	printf("<link rel='shortcut icon' href='icon2.png'/>");
	printf("<link rel='stylesheet' type='text/css' href='http://cs.mcgill.ca/~sjessa3/cgi-bin/ass4/style.css'>");
printf("</head>");

printf("<body>");
 	printf("<div class='container'>");
		printf("<div class='inner'>");
  			printf("<div class='content'>");
			printf("<h1>Just Succulent Tuna</h1>");
	

	while (fgets(line,sizeof(line),fp) != NULL){
		initBuffer(line);
		//printf("%s and %s//", username, friends[0]);
		if(strcmp(username,friends[0])==0){
			work=0;
			if (hasNextToken()==1){
				
				while(hasNextToken()==1){
					
					char *temp = nextToken();

					printf("<p style='font-size:18px'>%s  ",temp);
					profile=concat("http://cs.mcgill.ca/~sjessa3/cgi-bin/ass4/profile.py?username=",temp);
					hidden=concat("&hidden=",username);
					full=concat(profile,hidden);
					printf("<a href='%s'><button type='button'>See profile</button></a></p>",full);
				}
			}
			
			else{
				printf("<h3>No friends :( </h3>");
			}
			dashboard=concat("http://cs.mcgill.ca/~sjessa3/cgi-bin/ass4/dashboard.py?username=",username);
			printf("<a href='%s'><button small button type='button'>Back</button></a></p>",dashboard);	
		}

		myRewind();
	}
	printf("</body>");
	printf("</html>");
}
