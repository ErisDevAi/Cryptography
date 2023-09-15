#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  std::string str = "cvpbPGS{arkg_gvzr_V'yy_gel_2_ebhaqf_bs_ebg13_nSkgmDJE}";
  for (char c : str)
  {
    if (std::isalpha(c))
    {
      char decrypted = c >= 'a' ? (c - 'a' + 13) % 26 + 'a' : (c - 'A' + 13) % 26 + 'A';
      std::cout << decrypted;
    }
    else
      std::cout << c;
  }
  return 0;
}
