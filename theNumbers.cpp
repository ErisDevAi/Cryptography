// PICOCTF{THENUMBERSMASON}

#include <iostream>
#include <string>

char numberToChar(int num)
{
  switch (num)
  {
  case 1:
    return 'A';
  case 2:
    return 'B';
  case 3:
    return 'C';
  case 4:
    return 'D';
  case 5:
    return 'E';
  case 6:
    return 'F';
  case 7:
    return 'G';
  case 8:
    return 'H';
  case 9:
    return 'I';
  case 10:
    return 'J';
  case 11:
    return 'K';
  case 12:
    return 'L';
  case 13:
    return 'M';
  case 14:
    return 'N';
  case 15:
    return 'O';
  case 16:
    return 'P';
  case 17:
    return 'Q';
  case 18:
    return 'R';
  case 19:
    return 'S';
  case 20:
    return 'T';
  case 21:
    return 'U';
  case 22:
    return 'V';
  case 23:
    return 'W';
  case 24:
    return 'X';
  case 25:
    return 'Y';
  case 26:
    return 'Z';
  }
}

int main(int argc, char const *argv[])
{
  std::string str = "16 9 3 15 20 6 { 20 8 5 14 21 13 2 5 18 19 13 1 19 15 14 }";
  for (char c : str)
  {
    if (isdigit(c))
    {
      std::cout << numberToChar(c);
    }
    else
      std::cout << c;
  }
  return 0;
}
