/*
* This is sample code generated by rpcgen.
* These are only templates and you can use them
* as a guideline for developing your own functions.
* Jordi Farr�s-ls25887
*/

#include "xat.h"
static int numLinies=0;
char **
	getchat_1_svc(void *argp, struct svc_req *rqstp)
{
	FILE *log;
	log = fopen("log.txt","r");
	char *historial=(char *)malloc(sizeof(char)*3000);
	char linia[520];

	if (log==NULL) {
		log = fopen("log.txt", "w+");
		memset (historial,' ',3000);
	}
	else{
		fgets(linia, 520, log);

		while(!feof(log)) {
			strcat(historial,linia);
			fgets(linia, 520, log);


		}
		fclose(log);
	}
	/*
	* insert server code here
	*/

	return &historial;
}

void *
	write_1_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;
	numLinies++;
	FILE *log;
	log = fopen("log.txt","a");
	if (log==NULL) printf("error obrint log\n");
	else{
		fprintf(log,"%s",*argp);
		fclose(log);
	}
	/*
	* insert server code here
	*/

	return (void *) &result;
}

int *
	numlinies_1_svc(void *argp, struct svc_req *rqstp)
{


	/*
	* insert server code here
	*/

	return &numLinies;
}
