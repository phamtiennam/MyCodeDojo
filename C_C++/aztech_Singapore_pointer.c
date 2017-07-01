
//Description:Interview in Aztech.Question about pointer
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_07_01
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	char *s="12345";
	int *ptr=(int *)s;
	s++;
	printf("%s\n", s); //Char 1 byte,point to next 1 letter to the right,showing 2345
	ptr++;
	printf("%s\n", ptr);// int 4 byte,point 4 letters to the right,showing 5
	ptr++;
	printf("%s\n", ptr);// int 4 byte,point 4 letters to the right,showing %s
	
	return 0;
}
