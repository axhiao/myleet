#include <iostream>
#include <cstring>

using namespace std;

void setf(char* dest, int ldest, int rdest, const char* str, int ltmp, int lstr, int rtmp, int rstr);
char* getPalindrome(const char* str, const char* strlps)
{
  int n = strlen(str);
  int m = strlen(strlps);
  int total =  2 * n - m + 1;
  char* res = new char[total];
  res[total - 1] = '\0';

  int llps = 0;
  int rlps = m - 1;

  int ltmp = 0;
  int rtmp = n - 1;
  int lstr = 0;
  int rstr = n - 1;

  int lres = 0;
  int rres = total - 2; // res[total - 1] = '\0';

  while (llps <= rlps)
  {
    ltmp = lstr;
    rtmp = rstr;
    while (str[lstr] != strlps[llps])
    {
      lstr++;
    }
    while(str[rstr] != strlps[rlps])
    {
      rstr--;
    }
    setf(res, lres, rres, str, ltmp, lstr, rtmp, rstr);
    lres += lstr - ltmp + rtmp - rstr;
    rres -= lstr - ltmp + rtmp - rstr; //
    res[lres++] = str[lstr++];
    res[rres--] = str[rstr--];
    llps++;
    rlps--;
  }

  return res;
}

void setf(char* dest, int ldest, int rdest, const char* str, int ltmp, int lstr, int rtmp, int rstr)
{
  // ldest(++) = [ltmp ... lstr-1] + [rtmp, rtmp-1, ... rstr]
  // rdest(--) = [ltmp, ...., lstr-1] + [rtmp, rtmp-1, ... rstr]
  for (int i = ltmp; i < lstr; i++)
  {
    dest[ldest++] = str[i];
    dest[rdest--] = str[i];
  }
  for (int i = rtmp; i > rstr; i--)
  {
    dest[ldest++] = str[i];
    dest[rdest--] = str[i];
  }
}
int  main()
{
  const char *str = "AB1C2DE34F3GHJ21KL";
  const char *strlps =  "1234321";
  char* res = getPalindrome(str, strlps);
  cout << res << endl;
  cout << strlen(res) << endl;
  cout << 2*strlen(str) - strlen(strlps) << endl;
  return 0;
}
