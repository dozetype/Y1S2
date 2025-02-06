/////////////////Question 1/////////////////////////

#include <stdio.h>
#include <string.h>
void processString(char *str, int *totVowels, int *totDigits);
int main(){
    char str[50], *p;
    int totVowels, totDigits;
    printf("Enter the string: \n");
    fgets(str, 50, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}
void processString(char *str, int *totVowels, int *totDigits){
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    *totVowels = 0;
    *totDigits = 0;
    while(*str){ //checking if there is a char at this pointer
        for(int i=0; i<5; i++){ //checking vowels
            if(*str==vowels[i] || *str==vowels[i]+32)
                *totVowels+=1;
        }
        if(*str>='0' && *str<='9') //checking digits
            *totDigits+=1;
        *str++; //next char
    }
}

///////////////////Question 2////////////////////////////////////////////////

// #include <stdio.h>
// #include <string.h>
// char *stringncpy(char *s1, char *s2, int n);
// int main(){
//     char targetStr[40], sourceStr[40], *target, *p;
//     int length;
//     printf("Enter the string: \n");
//     fgets(sourceStr, 40, stdin);
//     if (p=strchr(sourceStr,'\n')) *p = '\0';
//     printf("Enter the number of characters: \n");
//     scanf("%d", &length);
//     target = stringncpy(targetStr, sourceStr, length);
//     printf("stringncpy(): %s\n", target);
//     return 0;
// }
// char *stringncpy(char *s1, char *s2, int n){
//     int i=0;
//     while(i<n && s2[i]){ //check size and s2 index
//         s1[i] = s2[i]; //appending chars
//         s1[i+1] = '\0'; //making sure it a string
//         i++;
//     }
//     return s1;
// }

//////////////Question 3 Dumb AHH qn/////////////////////////////////////////////

// #include <stdio.h>
// #include <string.h>
// #define INIT_VALUE 999
// int stringcmp(char *s1, char *s2);
// int main(){
//     char source[80], target[80], *p;
//     int result = INIT_VALUE;
//     printf("Enter a source string: \n");
//     fgets(source, 80, stdin);
//     if (p=strchr(source,'\n')) *p = '\0';
//     printf("Enter a target string: \n");
//     fgets(target, 80, stdin);
//     if (p=strchr(target,'\n')) *p = '\0';
//     result = stringcmp(source, target);
//     if (result == 1)
//         printf("stringcmp(): greater than");
//     else if (result == 0)
//         printf("stringcmp(): equal");
//     else if (result == -1)
//         printf("stringcmp(): less than");
//     else
//         printf("stringcmp(): error");
//     return 0;
// }
// int stringcmp(char *s1, char *s2){
//     int result = strcmp(s1, s2);
//     if(result==0) return 0;
//     else if(result<0) return -1;
//     else return 1;
// }

////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <string.h>
// #define M1 "How are ya, sweetie?"
// char M2[40] = "Beat the clock.";
// char *M3 = "chat";
// int main(){
//     char words[80],*p;
//     printf(M1);
//     puts(M1);
//     puts(M2);
//     puts(M2+1);
//     fgets(words, 80, stdin); /* user inputs : win a toy. */
//     if (p=strchr(words,'\n')) *p = '\0';
//     puts(words);
//     scanf("%s", words+6); /* user inputs : snoopy. */
//     puts(words);
//     words[3] = '\0';
//     puts(words);
//     while (*M3) puts(M3++);
//     puts(--M3);
//     puts(--M3);
//     M3 = M1;
//     puts(M3);
//     return 0;
// }

/////////////////////////////////////////////////////////////