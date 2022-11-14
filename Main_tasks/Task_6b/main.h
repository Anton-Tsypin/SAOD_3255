#include <iostream>
#include <cstring>
#include <cmath>

class PH{
  const unsigned short k = 2;
  const unsigned short Q = 65521;

  public:
    size_t len;
    unsigned long long* kp;

    PH(size_t L){
      std::cout << "PH created: ";
      len = L+1;
      kp = new unsigned long long[len];
      for(size_t i=0; i<len; i++){
        unsigned long long n = pow(k, i);
        kp[i] = n % Q;
        std::cout << kp[i] << " ";
      }
      std::cout << std::endl;
    }

    ~PH(){
      std::cout << "PH deleted" << std::endl;
      delete[] kp;
    }

    size_t Hash(const char* s){
      size_t hash = 0;
      size_t num;

      for(size_t i=0; i<len-1; i++){
        num = s[i];
        hash += num * kp[len-2-i];
        // std::cout << std::endl << num << " " << len-1-i << std::endl;
      }
      hash = hash % Q;

      std::cout << "Created hash = " << hash << " for string "; 
      for(size_t i=0; i<len-1; i++){ std::cout << s[i]; }; 
      std::cout << std::endl;  

      return hash;
    }

    size_t Shift(size_t h, char pref, char suff){
      size_t num1 = pref;
      size_t num2 = suff;

      size_t hash = ((k * h) - (num1 * kp[len-1]) + num2) % Q;

      std::cout << "Shifted hash " << h << " to " << hash; // << std::endl;  

      return hash;
    }
};

void find_in_text(char* text, const char** substrs, size_t substrs_count){
  size_t text_len = strlen(text);
  size_t substr_len = strlen(substrs[0]);
  PH* pol_hash = new PH(substr_len);
  size_t hashes[5]; 
  
  for(size_t i=0; i<substrs_count; i++){
    hashes[i] = pol_hash -> Hash(substrs[i]);
  } std::cout << std::endl;

  size_t current_hash;
  char* current_substr = new char[substr_len+1];
  
  for(size_t i=0; i<(text_len-substr_len)+1; i++){
    strncpy(current_substr, &text[i], substr_len); current_substr[substr_len] = 0;
    current_hash = pol_hash -> Hash(current_substr);

    for(size_t j=0; j<substrs_count; j++){
      bool flag = false;
      if(current_hash == hashes[j]){
        if(strcmp(current_substr, substrs[j]) == 0){
          std::cout << "substring " << substrs[j] << " success with index " << i << std::endl << std::endl;
        }
      }
    }
  }

  delete pol_hash;
}
