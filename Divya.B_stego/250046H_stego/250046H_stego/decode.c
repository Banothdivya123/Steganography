#include <stdio.h>
#include <string.h>
#include "decode.h"
Status do_decoding(char *argv[],DecodeInfo *decInfo)
{
    // Validate command line arguments and initialize file names
    if(validate_decode_args(argv,decInfo)==failure)
    {
        return failure;
    }
    printf("##  Decoding Procedure started  ##\n");    
    if(open_image_file(decInfo)==failure)
    {
        return failure;
    }
        // Decode and verify magic string to confirm encoded file
    if(decode_magic_string(decInfo)==failure)
    {
        return failure;
    }
    if(decode_secret_file_extn(decInfo)==failure)
    {
        return failure;
    }
    if(decode_secret_file_data(decInfo)==failure)
    {
        return failure;      
    }          
}
/* decode Magic String */
Status decode_magic_string(DecodeInfo *decInfo)
{
    fseek(decInfo->encoded_image_fptr,54,SEEK_SET);
    char header[32];
    fread(header,32,1,decInfo->encoded_image_fptr);
    int magic_len=decode_4byte_from_lsb(header);
    if(magic_len!=strlen(MAGIC_STRING))
    {
        printf("Magic string is not decoded successfully\n");
        return failure;
    }
    printf("Decoding Magic string Signature\n");
    char magic_string[magic_len+1];
    for(int i=0;i<magic_len;i++)
    {
        char header2[8];
        fread(header2,8,1,decInfo->encoded_image_fptr);
        magic_string[i]=decode_1byte_from_lsb(header2);
    }
    magic_string[magic_len]='\0';
    if(strcmp(magic_string,MAGIC_STRING)==0)
    {
        return success;
    }
    else
    {
        printf("Not an encoded file\n");
        return failure;
    }    
}

/* decode secret file extenstion */
Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    printf("Decoding output file Extension\n");
    char header[32];
    fread(header,32,1,decInfo->encoded_image_fptr);
    int ext_len=decode_4byte_from_lsb(header);
    char ext[ext_len+1];
    for(int i=0;i<ext_len;i++)
    {
        char header2[8];
        fread(header2,8,1,decInfo->encoded_image_fptr);
        ext[i]=decode_1byte_from_lsb(header2);
    }
    ext[ext_len]='\0';
    strcat(decInfo->output_fname,ext);
    decInfo->output_fptr=fopen(decInfo->output_fname,"w");
    printf("Opened %s\n",decInfo->output_fname);
    printf("Done.Opened all required files\n");
}

/* decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    printf("Decoding File Size\n");
    char header[32];
    rewind(decInfo->output_fptr);
    fread(header,32,1,decInfo->encoded_image_fptr);
    int file_size=decode_4byte_from_lsb(header);
    printf("Done\n");
    printf("Decoding File Data\n");
    for(int i=0;i<file_size;i++)
    {
        char header2[8];
        fread(header2,8,1,decInfo->encoded_image_fptr);
        char ch=decode_1byte_from_lsb(header2);
        fwrite(&ch,1,1,decInfo->output_fptr);
    }
    printf("Done\n");
    printf("##   Decoding done successfully  ##\n");
}

Status validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    //check if argv[2] is .bmp
    char * ptr1=strstr(argv[2],".bmp");
    if(ptr1==NULL)
    {
        printf("Invalid encoded file name\n");
        return failure;
    }
    if(!strcmp(ptr1,".bmp"))
    {
        decInfo->encoded_image_fname=argv[2];
    }
    else
    {
        printf("Invalid encoded file name\n");
        return failure;
    }
    printf("Its a bmp file\n");
    if(argv[3]==NULL)
    {
        printf("output file not mentioned. Creating output.(encoded extension) as default\n");
        strcpy(decInfo->output_fname,"output");
    }
    else 
    {
        char * ptr=strchr(argv[3],'.');
        if(ptr==NULL)
        {
            strcpy(decInfo->output_fname,argv[3]);
        }
        else
        {
            char buffer[10];
            int i=0;
            while(argv[3][i]!='.')
            {
                buffer[i]=argv[3][i];
                i++;
            }
            buffer[i]='\0';
            strcpy(decInfo->output_fname,buffer);
        }
        
    }
    return success;
    
}
Status open_image_file(DecodeInfo *decInfo)
{
    printf("Opening required files\n");
    // Open encoded BMP image in read mode
    decInfo->encoded_image_fptr = fopen(decInfo->encoded_image_fname, "r"); 

    if (decInfo->encoded_image_fptr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->encoded_image_fname);

    	return failure;
    }
    printf("Opened %s\n",decInfo->encoded_image_fname);
    return success;
}
/* decode 1 byte from LSB of image data array */
char decode_1byte_from_lsb( char *buffer_8)
{
    char ch=0;
    for(int i=0;i<8;i++)
    {
        ch = ch | ((buffer_8[i]&1)<<(7-i));
    }
    return ch;
}
/* decode 4 bytes from LSB of image data array */
int decode_4byte_from_lsb(char *buffer_32)
{
    int ch=0;
    for(int i=0;i<32;i++
    ){
        ch = ch | ((buffer_32[i]&1)<<(31-i));
    }
    return ch;
}