# include <string.h>
# include <stdio.h>
# include <stdlib.h>

long fac(int n) {
	long f;
	for(f=1; n>1; n--) f*=n;
	return f;
}

int swap(char *tekst, int pos, int npos){
	char tmpchr=tekst[pos];
	tekst[pos]=tekst[npos];
	tekst[npos]=tmpchr;
	return 0;
}

int findcombo(char *tekst, int pos){
	int counter=1;
	int npos=pos;
	int len=strlen(tekst);
	int fact=fac(len-pos); //calculate no of combination.
	char *tmpstr=calloc(sizeof(char), len-pos);

	while(counter<=fact) {
		if(pos<(strlen(tekst)-1)) pos++;
		if(fact>2){
			strcpy(tmpstr,tekst);
			counter+=findcombo(tekst,npos+1);
			strcpy(tekst,tmpstr);
			swap(tekst, npos, pos);
		}
		else {
			counter++;
			swap(tekst,npos,pos);
			printf("%s ", tekst);
		}
	}
	free(tmpstr);
	return fact;
}


int main (int argc, char const* argv[])
{
	if(argc==0) {
	    printf("Error: missing argument, string \n");
	    return 1;
    }

	int len=strlen(argv[1]);
	char *str=calloc(sizeof(char), len+1);
	strcpy(str, argv[1]);
	findcombo(str,0);
	free(str);
	printf("\n");
	return fac(len);
}

