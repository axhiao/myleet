#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

bool haveOne(char* start, char* end); // [start, end)  != [end]
void permutation(char*, char*);
void uniquePermutation(char* pstr, char* begin);
void combination(const string& str, vector<char>& vc, int pos);




int main()
{
  // char pstr[] = "122";
  // permutation(pstr, pstr);
  // cout << "-----------" << endl;
  // uniquePermutation(pstr, pstr);

  string str("123");
  std::vector<char> v;
  combination(str, v, 0);
  return 0;
}


void permutation (char* pstr, char* begin)
{
  if (pstr == NULL || begin == NULL)
  {
    return;
  }
  if (*begin == '\0')
  {
    printf("%s\n",pstr);
  }

  for (char* pc = begin; *pc != '\0'; pc++)
  {
    std::swap(*begin, *pc);
    permutation(pstr, begin + 1);
    std::swap(*begin, *pc);
  }
}


void uniquePermutation(char* pstr, char* begin)
{
  if (pstr == NULL || begin == NULL)
  {
    return;
  }
  if (*begin == '\0')
  {
    printf("%s\n",pstr);
    return;
  }
  for (char* pc = begin; *pc != '\0'; pc++)
  {
    if (!haveOne(begin, pc))
    {
      std::swap(*begin, *pc);
      uniquePermutation(pstr, begin + 1);
      std::swap(*begin, *pc);
    }
  }
}

bool haveOne(char* start, char* end) // [start, end)  != [end]
{
  for (char* pc = start; pc < end; pc++)
  {
    if (*pc == *end)
          return true;
  }
  return false;
}

void combination(const string& str, vector<char>& vc, int pos)
{
  // output
  for (int i = 0; i < vc.size(); i++)
  {
    cout << vc[i];
  }
  cout << endl;

  for (int i = pos; i < str.size(); i++)
  {
    vc.push_back(str[i]);
    combination(str, vc, i+1);
    vc.erase(vc.begin()+vc.size()-1);
  }
}
