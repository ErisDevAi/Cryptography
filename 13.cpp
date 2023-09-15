#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  std::string str = "cvpbPGS{abg_gbb_onq_bs_n_ceboyrz}";
  for (char c : str)
  {
    if (std::isalpha(c))
    {
      char decrypted = c >= 'a' ? (c + 13 - 'a') % 26 + 'a' : (c + 13 - 'A') % 26 + 'A';
      std::cout << decrypted;
    }
    else
      std::cout << c;
  }
  return 0;
}
