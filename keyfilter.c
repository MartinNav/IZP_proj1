#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Constants defined as macro
#define ADDRESS_LEN 128
#define EN_ALPHABET_LEN 26



//Function definitions
void to_upper(char *arr);
void clean_arr(char *arr, int len);
void cmp_and_save(char *dest, char *param, char *inpt);
void print_non_null_letters(char *arr, int len);
bool is_arr_empty(char *arr, int len);
void cpy_str_arr(char *dest, char *origin);




int main(int argc, char *argv[]){

  char input[ADDRESS_LEN]={0};
  char address[ADDRESS_LEN] ={0};
  char best_match[ADDRESS_LEN]={0};
  char alphabet[EN_ALPHABET_LEN]={0};
  
  if (argc!=1){
    cpy_str_arr(input, argv[1]);
    to_upper(input);
  }
  do {
    clean_arr(address, ADDRESS_LEN);
    scanf("%s",address);
    to_upper(address);
    //Must change because currently empty string is UB
    cmp_and_save(alphabet, input, address);
  } while(address[0]!='\0');


  if (is_arr_empty(alphabet, EN_ALPHABET_LEN)) {
    printf("Not found\n");
  }else if (!is_arr_empty(best_match, ADDRESS_LEN)) {
    //TODO: IMPLEMENT
    printf("IMPLEMENT");
  }else {
    printf("Enable: ");
    print_non_null_letters(alphabet, EN_ALPHABET_LEN);
    printf("\n");
  }


  return 0;

}

void cpy_str_arr(char *dest, char *origin){
  int i = 0;
  while (origin[i]!='\0') {
    dest[i] = origin[i];
    i++;
  }
}

bool is_arr_empty(char *arr, int len){
  for (int i = 0; i < len; i++) {
    if (arr[i]!='\0') {
      return false;
    }
  }
  return true;
}

void print_non_null_letters(char *arr, int len){
  for (int i = 0; i < len; i++) {
    if (arr[i]!='\0'){
      printf("%c",arr[i]);
    }
  }
}
/*
 * dest: pointer to array whe I will save next string
 * param: pointer to parameter array that I will compare with input
 * inpt: pointer to input string
 *
*/
void cmp_and_save(char *dest, char *param, char *inpt){
  int i = 0;

   while(param[i]!='\0'){
    if(inpt[i]==param[i] ){
      
    }else{
      return;
    }
    i++;
  }
  dest[inpt[i]-'A'] = inpt[i];
  printf("%c\n", inpt[i]);
}


void clean_arr(char *arr, int len){
  for (int i = 0; i < len; i++) {
    arr[i] = '\0';
  }
}

void to_upper(char *arr){
  int i = 0;
  while (arr[i]!='\0') {
    if (arr[i]>='a'&&arr[i]<='z') {
      arr[i]-=32;
    }
    i++;
  }
}

