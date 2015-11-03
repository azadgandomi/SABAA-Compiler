#include<stdio.h>
#include<stdlib.h>

void write1and1(char* str1, char* str2);


int main()

{
char* s1;
s1 = "Hello";
char* s2;
s2 = "World!\n";
write1and1(s1, s2);
return 0;
}
void write1and1(char* str1, char* str2)
{
printf("%s", str1);
printf("%s", " ");
printf("%s", str2);

}
