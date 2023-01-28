#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


// determine if input is string, char, int
// determine number of input

void my_pr(const char* format,...){
    // printf("10: %s\n", format);
    char buffer[100] = {0};
    va_list args;
    va_start(args, format);
    // vprintf(format, args);
for (int i = 0; format[i] != '\0'; i++){
 buffer[i] = format[i];

}
// printf("17: %s\n", buffer);
write(1, &buffer, 100);
write(1, "/n", 1);

    
    va_end(args);
}

int main(int argc, char** argv) {
    my_pr("Hello World\n");




}