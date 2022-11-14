#include <iostream>
#include "main.h"

int main(){

  // Тесты хешей и сдвигов

  PH* test = new PH(5);
  size_t hash1 = test -> Hash("abcde");
  size_t hash2 = test -> Hash("bcdef");
  size_t shifted_hash = test -> Shift(hash1, 'a', 'f');
  if(hash2 == shifted_hash){ std::cout << "  YES";} else { std::cout << "  NO"; } std::cout << std::endl;
  delete test;

  std::cout << std::endl;

  PH* test2 = new PH(7);
  size_t hash3 = test2 -> Hash("aabbccd");
  size_t hash4 = test2 -> Hash("abbccdd");
  size_t shifted_hash2 = test2 -> Shift(hash3, 'a', 'd');
  if(hash4 == shifted_hash2){ std::cout << "  YES";} else { std::cout << "  NO"; } std::cout << std::endl;
  delete test2;

  std::cout << std::endl;

  PH* test3 = new PH(20);
  size_t hash5 = test3 -> Hash("GTAGTGTGTCTACGTCTTTA");
  size_t hash6 = test3 -> Hash("TAGTGTGTCTACGTCTTTAT");
  size_t shifted_hash3 = test3 -> Shift(hash5, 'G', 'T');
  if(hash6 == shifted_hash3){ std::cout << "  YES";} else { std::cout << "  NO"; } std::cout << std::endl;
  delete test3;

  std::cout << std::endl;


  // Тест поиска в тексте с несколькими хешами

  char text[] = "abbbaaababaaabab";
  const char* substrs[] = {"bbb", "aaa", "bab", "aba"};
  std::cout << "text: ";
  for(int i=0; i<strlen(text); i++){ std::cout << text[i]; } std::cout << std::endl << "substrings: ";
  for(size_t j=0; j<4; j++){
    for(int i=0; i<strlen(substrs[j]); i++){ std::cout << substrs[j][i]; } std::cout << " | ";
  } std::cout << std::endl;
  
  find_in_text(text, substrs, 4);

  return 0;
}
