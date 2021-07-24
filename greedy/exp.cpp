#include<stdio.h>
#include<unistd.h>
int main(){
	int c = 0;
	c += fork();
	printf("%d", c);
	
	return 0;
}
