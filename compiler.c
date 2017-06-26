#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
void lexicalAnalyser(int fd);
void tokenCreator(char c);

int tokenArraySize=50,tokenindex=0;
char* tokenList;
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
    return 0;
    
}
void lexicalAnalyser(int fd)
{
    
     int readb=0,lineno=0;
     tokenList=malloc(tokenArraySize * sizeof(char));//initialize the tokenList
     
     do{
            char c;
            readb=read(fd,&c,1);
            
            tokenCreator(c);
            if(c=='\n')
            {
                lineno++;
            }
            printf("%c",c);
            
     }while(readb!=0);
     
     printf("Total Line Numbers %d\n",lineno);
    
    
    
    
}
void tokenCreator(char c)
{
    
 
    
    
    
    
}
