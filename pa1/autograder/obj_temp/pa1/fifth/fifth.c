#include <stdio.h>
#include<string.h>
#include <stdlib.h>
/*void con(char *original, char *add){
  while(*original)
    original++;
  while(*add){
    *original=*add;
    add++;
    orginal++;
  }//ehilr close
  *original='\0';
  }*/
int main(int argc, char *argv[]){
  int isLowercaseVowel;
  int isUppercaseVowel; 
  //  char s[]=argv[1];
  //printf("%d\n",argc);
  //char s[]=malloc(argc*sizeof(argv[1]));
  //  printf("%s\n",argv[2]);
  for(int i=1;i<argc;i++){
      char* s=argv[i];
      // printf("%s\n",a);
      // strcat(s,b);
  
  int n=strlen(s);
  for(int i=0;i<n;i++){
isLowercaseVowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
    // evaluates to 1 (true) if c is an uppercase vowel
 isUppercaseVowel = (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U');
      if(isLowercaseVowel || isUppercaseVowel)
    printf("%c",s[i]);
      else 
	continue;
  }//for closed
  }//for closed for all words
  return 0;
} 
