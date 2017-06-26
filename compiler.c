#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

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
            int readb=0,lineno=0;
            do{
            char c;
            readb=read(fd,&c,1);
            if(c=='\n')
            {
                lineno++;
            }
            printf("%c",c);
            }while(readb!=0);
            printf("Total Line Numbers %d\n",lineno);
        }
    }
    
    
    
        return 0;
    
}
