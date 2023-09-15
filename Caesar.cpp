#include <iostream>
#include <string>

std::string giaiMaCaesar(std::string banMa, int k)
{
  std::string ketQua = "";

  for (char &c : banMa)
  {
    if (isalpha(c))
    {
      char coBan = islower(c) ? 'a' : 'A';
      c = coBan + ((c - coBan - k + 26) % 26);
    }
    ketQua += c;
  }

  return ketQua;
}

int main(int argc, char const *argv[])
{
  std::string maHoa = "picoCTF{gvswwmrkxlivyfmgsrhnrisegl}";
  std::cout << "Ma hoa truoc khi giai " << maHoa;
  std::cout << std::endl;
  for (int k = 1; k < 27; k++)
  {
    std::cout << k << ". "
              << "Ma hoa sau khi giai " << giaiMaCaesar(maHoa, k);
    std::cout << std::endl;
  }

  return 0;
}
// crossingtherubicondjneoach