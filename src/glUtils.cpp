//
// Created by Laurens on 6-7-2016.
//

#include <glew.h>
#include <cstdio>
#include <cstdlib>

char* filetobuf(char *file);

int compileShader(GLuint shaderID, char* shaderPath){
    int isCompiled;
    char *shaderSource = filetobuf(shaderPath);
    glShaderSource(shaderID, 1, (const char**)&shaderSource, 0);
    glCompileShader(shaderID);
    glGetShaderiv(shaderID,GL_COMPILE_STATUS,&isCompiled);
    if(isCompiled == GL_FALSE){
        int maxLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
        char *infolog = (char*) malloc(maxLength);
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, infolog);
        printf("Error compiling shader: %s\n Error log:\n%s", shaderPath, infolog);
        free(infolog);
        return 0;
    }else{
        printf("%s was succesfully compiled to run on the hardware\n", shaderPath);
        fflush(stdout);
    }
    return 1;
}

char* filetobuf(char *file){
    FILE *fptr;
    long length;
    char *buf;

    fptr = fopen(file, "rb"); /* Open file for reading */
    if (!fptr) /* Return NULL on failure */
        return NULL;
    fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
    length = ftell(fptr); /* Find out how many bytes into the file we are */
    buf = (char*)malloc(length+1); /* Allocate a buffer for the entire length of the file and a null terminator */
    fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
    fread(buf, length, 1, fptr); /* Read the contents of the file in to the buffer */
    fclose(fptr); /* Close the file */
    buf[length] = 0; /* Null terminator */

    return buf; /* Return the buffer */
}

