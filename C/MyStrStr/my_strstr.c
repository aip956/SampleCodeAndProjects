#include <stdio.h>
#include <stddef.h>
#include <string.h>


char* my_strstr(char* haystack, char* needle) {
    int i = 0, j = 0, k = 0, m = 0, count = 0;
    int haystackstart;
    int jvsk;
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len2 == 0) {
        return haystack;
    }
    for (j = 0; haystack[j] !='\0'; j++) {
        count = 0;
        if (haystack[j] == needle[0]) {
            haystackstart = j;
            jvsk = j;   
            for (k = 0; k < len2; k++) {
                if (haystack[jvsk] == needle[k]) {
                    jvsk++;
                    count++;
                    if (count == len2) {
                        return &haystack[haystackstart];
                        break;
                    }
                };
            };
        };
    };
    return NULL;  
}

int main() {
    char str[100] = "mississippi";
    char subStr[100] = "issip";
    printf("my_strstr -> %s\n", my_strstr(str, subStr));
    printf("str: %s\n", str);
  return 0;
}
