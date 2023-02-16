#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXLINE 1024
int KMPindex (char S[],char T[]);
void getnext(char T[],int next[]);
int main()
{
char filename[64],s[81],line [MAXLINE];
FILE *fp;
scanf("%s",filename);
scanf("%s",s);
if((fp = fopen(filename,"r"))==NULL){
   printf("Can't open file %s!\n",filename);
   return -1;
}
while(fgets(line ,MAXLINE-1, fp)!=NULL){
    if(KMPindex(line,s)>=0)
    printf("%s\n",line);
}
fclose(fp);
return 0;
}
int KMPindex(char S[ ], char T[ ]) {
int i = 0, j=0, *next;
next = (int *)malloc(sizeof(int)*(strlen(T)+1));
getnext(T, next); //求next
while ( S[i]!='\0' && T[j]!='\0') {
if (S [i] == T[j] ) {
i++;
j++ ;
}
else
//j回退到相应位置开始匹配， i不变
(j == 0) ? i++ :( j = next[j]);
}
free(next);
if ( T[j] == '\0') //匹配成功，返回匹配位置
return i-j;
else
return -1;
}
void getnext(char T[], int next[])
{
int i = 0, j = -1;
next[0] = -1;
while (T[i] != '\0')
{
if (j == -1 || T[i] == T[j])
{ // i为后缀位置； j为前缀位置
i++;
system("pause");
j++;
next[i] = j;
}
else
j = next[j]; //若字符不同，则j值回溯
}
}
