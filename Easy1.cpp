#include <iostream>
#include <string>

std::string decryptCaesar(std::string ciphertext, std::string key)
{
  std::string plaintext = "";

  for (size_t i = 0; i < ciphertext.length(); i++)
  {
    char c = ciphertext[i];

    if (isalpha(c))
    {
      char base = islower(c) ? 'a' : 'A';
      int shift = key[i % key.length()] - base;
      c = base + ((c - base - shift + 26) % 26);
    }

    plaintext += c;
  }

  return plaintext;
}

int main()
{
  std::string ciphertext = "UFJKXQZQUNB";
  std::string key = "SOLVECRYPTO";

  std::string decryptedText = decryptCaesar(ciphertext, key);

  std::cout << "Decrypted message: " << decryptedText << std::endl;

  return 0;
}
