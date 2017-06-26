#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <regex.h>

void lexicalAnalyser(int fd);
void tokenCreator(char c);
int matchregex(const char *string, char *pattern);

int tokenArraySize=50,tokenindex=0,leximsListSize=50,leximsListindex=0;
char* tokenList;
char* leximsList;
const char *predefinedTokens[] = {"Start","{","}","(",")",";","=","<","++","+","int","float"};

int main(int argc, char *argv[])
{
    
    if ( argc != 2 ) 
    {
       
        printf( "usage: %s filename\n", argv[0] );
    }
    else 
    {
        
        int fd=open(argv[1], O_RDONLY, 0);

        
        if ( fd == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
           lexicalAnalyser(fd);
        }
        
    }
    
    
    free(tokenList);
    free(leximsList);
    return 0;
    
}
void lexicalAnalyser(int fd)
{
    
     int readb=0,lineno=0;
     tokenList=malloc(tokenArraySize * sizeof(char));//initialize the tokenList
     leximsList=malloc(leximsListSize * sizeof(char));//initialize the leximsList
     
     do{
            char c;
            readb=read(fd,&c,1);
            
            
            //tokenCreator(c);
            
            if(c=='\n')
            {
                lineno++;
            }else if(c!=' '){
               leximsList[leximsListindex]=c;
               leximsListindex++;
                
            }
            printf("%c",c);
            
     }while(readb!=0);
    int i;
     for(i=0;i<leximsListSize;i++)
     {
         printf("%c",leximsList[i]);
         
     }
     
     printf("\nTotal Line Numbers %d\n",lineno);
    
    
    
    
}
void tokenCreator(char c)
{
    
 
   // printf("Regex st %d",matchregex(predefinedTokens, "[Start]+"));
    
    
    
}
int matchregex(const char *string, char *pattern)
{
    int    status;
    regex_t    re;

    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        return(0);      /* Report error. */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return(0);      /* Report error. */
    }
    return(1);
}
