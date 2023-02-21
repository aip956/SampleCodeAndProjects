
#include <stdio.h>
#include <stdlib.h>

char* freqAlphabets(char* s) {
    printf ("%s\n", s);
    int ind = 0; 
    int j = 0;
    char* answer[1000] = {};
    

    
    while (s[ind] != '\0') {
        
        // printf("10 ind: %d\n", ind);
        // printf("11 s[ind+2]: %c\n", s[ind+2]);
        if (s[ind+2] == '#'){
            int new_num;
            char letter;
            char num[3] = {};
            num[0] = s[ind];
            num[1] = s[ind + 1];
            num[2] = '\0';
            // printf("num: %s\n", num);      
            new_num = atoi(num);
            // printf("21newnum: %d\n", new_num);
            letter = new_num + 96;
            answer[j] = &letter;
            j++;
            printf("answer, j: %s, %d\n", *answer, j);
            ind = ind + 3;
        }
        else {
            char letter;
            int int_num;
            // printf("else \n");
            // printf("s[ind]: %c\n", s[ind]);
            char else_num[2] = {};
            // printf("26elsenum: %s\n", else_num);
            // printf("28elsenum0: %c\n", else_num[0]);
            else_num[0] = s[ind];
            else_num[1] = '\0';
            //  printf("30elsenum0: %c\n", else_num[0]);
            // printf("31elsenum: %s\n", else_num);
            int_num = atoi(else_num);
            // printf("33intnum: %d\n", int_num);
            letter = int_num + 96;
            // printf("45letter: %c\n", letter);
            answer[j] = &letter;
            j++;
            printf("answer, j: %s, %d\n", *answer, j);
            ind++;
        }



        // ind++;
    }
    printf("%s\n", answer);
    return answer;
}




int main() {
    // char* s[100] = {"10#11#12"};
    char* s[100] = {"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"};
    printf("%s\n", freqAlphabets(*s));
    return 0;
}

