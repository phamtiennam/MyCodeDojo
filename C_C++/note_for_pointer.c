
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Interview at Aztech SG.Pointer
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_07_01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main(int argc, char const *argv[])
{

char c = 'A';
char a[] = "Hello world";

char *ptr1 = &c;
char *ptr2 = a;      // Points to the 'H' of "Hello world"
char *ptr3 = &a[0];  // Also points to the 'H' of "Hello world"
char *ptr4 = &a[6];  // Points to the 'w' of "world"
char *ptr5 = a + 6;  // Also points to the 'w' of "world"


printf(" char *ptr2=a ->=%s\n", ptr2);
printf(" char *ptr3=a[0] ->=%s\n", ptr3);
printf(" char *ptr4=a[6] ->=%s\n", ptr4);
printf(" char *ptr5=a+6 ->=%s\n", ptr5);


printf("======================\n");
	char *s="mnfsdfsgs";
	printf("s=%s\n",s );
	s++;
	printf("s++; ->= %s\n",s );
printf("======================\n");

	printf("=s=%d\n",*s); 
	printf("=s1=%d\n",s[1]); 
	printf("=s2=%c\n",s[2]); 
	printf("=s3=%d\n",s[3]); 
	printf("=s4=%d\n",s[4]); 
	printf("=s0=%d\n",s[0]); 
	printf("%s\n",s+s[1]-s[3]); //it points to somewhere

	return 0; 
}
