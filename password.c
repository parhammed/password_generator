#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define random_inital_str "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.+_"

static char *chars = 0;
static size_t chars_len = 0;


void set_random_charset(char* charset){
    char * c;
    chars_len = 0;   
    for (c = charset;*c; c++)
        chars_len++;
    
    chars = calloc(chars_len + 1, sizeof(char));
    for (size_t i = 0; i < chars_len; i++)
        chars[i] = charset[i];

    chars[chars_len] = 0;
}

char random_char(){
    if (!chars){
        char x[] = random_inital_str;

        set_random_charset(&(x[0]));
    }
    size_t index = 0;
    size_t index_max = 0;
    do{
    
        index += rand();
        index_max += RAND_MAX;
    }while (chars_len > index_max);
    
    return chars[index%chars_len];
}

char* random_str(size_t length){
    if (!chars){
        char x[] = random_inital_str;

        set_random_charset(&(x[0]));
    }
    char* password = calloc(length, sizeof(char));
    size_t x = ((chars_len-1) / RAND_MAX);
    for (size_t i = 0; i < length; i++)
    {
        size_t index = 0;
        for (size_t j = 0; j <= x; j++)
            index += rand();

        password[i] = chars[index % chars_len];
    }
    return password;
}

int main(){
    srand(time(NULL));
    char *password =  random_str(rand()%10 + 20);
    printf("%s\n", password);
}
