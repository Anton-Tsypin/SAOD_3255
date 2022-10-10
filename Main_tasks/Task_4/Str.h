#include <cstring>
#include <iostream>

class Str{
  char* m_pszText;
public:
  Str()
    { m_pszText = new char[1]{0}; }

  Str(const char * p){
    if(p){
      m_pszText = new char [strlen(p) + 1];
      strcpy_s(m_pszText, strlen(p) + 1, p);
    }
    else{
      m_pszText = new char[1]{0};
    }
  }
  Str(const Str &s){
    m_pszText = new char[strlen(s.m_pszText) + 1];
    strcpy_s(m_pszText, strlen(s.m_pszText + 1), s.m_pszText);
  }

  const Str& operator = (const Str &s){
    if(&s == this) return *this;
    delete [] m_pszText;

    m_pszText = new char[strlen(s.m_pszText) + 1];
    strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);

    return *this;
  }

  Str & operator += (const char *sz){
    strcat(m_pszText, sz);
    return *this;
  }

  Str operator +(const char *sz) const{
    Str new_str;
    new_str += m_pszText;
    new_str += sz;
    return new_str;
  }

  operator const char*() const{ 
    return m_pszText; 
  }

  ~Str() { delete []m_pszText; }
};
  