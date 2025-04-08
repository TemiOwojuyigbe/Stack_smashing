#include <stdio.h>

int cmsc426() {
	char fx3[208];
	FILE *badfile;
	badfile = fopen("badfile", "r");
	fread(fx3, sizeof(char), 300, badfile);
	printf("cmsc426\n");
	return 3;
}
int owojuyigbe(){
	char fx2[208];
	int val = cmsc426();
	printf("owojuyigbe\n");
	return 2;
}
int temi(){
	char fx1[208];
	int val = owojuyigbe();
	if (val == 2){
		printf("temi\n");
		return 1;
	}
	return 0;
}

int main(){
	int ret = temi();
	if (ret == 1){
		printf("Returned properly\n");
	}else{
		printf("Improper return\n");
	}
	return 0;
}
