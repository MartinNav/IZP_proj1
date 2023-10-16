/*
 *  Author: Martin Navrátil (xnavram00@stud.fit.vutbr.cz)
 *  
 * */


#include<stdio.h>
#include<stdbool.h>

//Constants defined as macro
#define ADDRESS_LEN 128
//To represent number of printable ascii characters (I support even special characters)
#define ALPHABET 127


//Function definitions
void to_upper(char *arr);
void clean_arr(char *arr, int len);
void cmp_and_save(char *dest,const char *param, const char *inpt);
void print_non_null_letters(const char *arr, int len);
bool is_arr_empty(const char *arr, int len);
void cpy_str_arr(char *dest, const char *origin);
int get_prefix_end_indx(const char *prefix,const char *str);




int main(int argc, char *argv[]){

  char input[ADDRESS_LEN]={0};
  char address[ADDRESS_LEN] ={0};
  char best_match[ADDRESS_LEN]={0};
  char alphabet[ALPHABET]={0};
  int match_count = 0; 
  if (argc==1) {
    //Will let the state to be as is
  }
  else if (argc==2){
    cpy_str_arr(input, argv[1]);
    to_upper(input);
  }else{
    printf("Error:Too many arguments\n");
    return -1;
  }
  do {
    clean_arr(address, ADDRESS_LEN);
    //These weird characters are here to accept spaces as part of adress and not to handle them as separate address
    scanf("%[^\n]%*c",address);
    to_upper(address);
    cmp_and_save(alphabet, input, address);
    if (get_prefix_end_indx(input, address)>0) {
      cpy_str_arr(best_match, address);
      match_count++;

    }
  } while(address[0]!='\0');


  if (is_arr_empty(alphabet, ALPHABET)&&match_count==0) {
    printf("Not found\n");
  }else if (match_count==1) {
    printf("Found: %s\n", best_match);
  }else {
    printf("Enable: ");
    print_non_null_letters(alphabet, ALPHABET);
    printf("\n");
  }


  return 0;

}

/*
 * This function will return end index of prefix substring if there is any otherwise it will return negative number 
 * */

int get_prefix_end_indx(const char *prefix,const char *str){
  int i = 0;
  while (prefix[i]!='\0') {
    if (prefix[i]==str[i]) {
      i++;
    }else{
      return -1;
    }
  }

  return i;
}
/*This function will be copying chars from one array to another until it hits null terminator
 * */
void cpy_str_arr(char *dest, const char *origin){
  int i = 0;
  while (origin[i]!='\0') {
    dest[i] = origin[i];
    i++;
  }
}

bool is_arr_empty(const char *arr, int len){
  for (int i = 0; i < len; i++) {
    if (arr[i]!='\0') {
      return false;
    }
  }
  return true;
}
/*
 * !This function contains side effects
 * It will take array as reference and itterate througth the array until it will hit end of array specified by the 'len' parameter
 * This function makes lots of syscalls (by calling printf)
 * */
void print_non_null_letters(const char *arr, int len){
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
void cmp_and_save(char *dest,const char *param, const char *inpt){
  int i= get_prefix_end_indx(param, inpt);
  if(i!=-1)
  dest[inpt[i]-1] = inpt[i];
}

/*
 *This function will take array by reference and array length by value and than it will fill the array by null characters 
 *
 * */
void clean_arr(char *arr, int len){
  for (int i = 0; i < len; i++) {
    arr[i] = '\0';
  }
}
/*
*Will convert small letters in alphabeth to upper case (Non engish alphabeth characters will be ignored)
* */
void to_upper(char *arr){
  int i = 0;
  while (arr[i]!='\0') {
    if (arr[i]>='a'&&arr[i]<='z') {
      arr[i]-=32;
    }
    i++;
  }
}

