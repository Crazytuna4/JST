#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char csv[100][100];
int count=0;
int query=0;
int totalCount;


int csvStrip(char *line){
	char sep[]=(" ,,");
	char *token;
	int pos=0;
	token=strtok(line,sep);
	while(token!=NULL){
		strcpy(csv[pos],token);
		pos++;
		token = strtok(NULL, sep);
		count++;
	}
	return totalCount=count-1;
}

int main(int argc, char const *argv[]){
	printf("Content-type:text/html\n\n");
	
	char buffer[100][100];
	char *token;
	int pos=0;

	char *data = getenv("QUERY_STRING");
	char separators[]=("+,=");
	token=strtok(data,separators);
	while(token!=NULL){
		strcpy(buffer[pos],token);
		pos++;
		token = strtok(NULL, separators);
		query++;
	}
	int totalQuery=query-1;
	
	char line[512];
	FILE *fp=fopen("web.csv", "rw");
	while(fgets(line,sizeof(line),fp) != NULL){
		int match=0;
		csvStrip(line);
		int i,j;
		for (i=0;i<=query;i++){
			for(j=0;j<=count;j++){
				if(strcmp(buffer[i],csv[j])==0)
					match++;
			}
		}
		double total=(double)match/totalCount;
		if (total>0.6){
			printf("<html>");
			printf("<a href=%s>%s</a>",csv[0],csv[0]);
			printf("</html>");
		}
	}
	return 0;
}
