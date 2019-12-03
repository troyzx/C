//
//  main.c
//  week11
//
//  Created by Troy on 2019/11/7.
//  Copyright © 2019 Troy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen("test.txt", "w");
    /*
    fputc('a',fp);
    fclose(fp);
    */
    char a;
    char *str=NULL;
    while((a=fgetc(fp))!=EOF){
        
    }
    
    fread(str,sizeof(char),1,fp);
    printf("%s\n",str);
    
   
    return 0;
}
