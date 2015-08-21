#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

string reverseStr(int num)
{
    bool negative = num < 0 ? true : false;
    if (negative)
        num = abs(num);
    stringstream ss;
    ss << num % 10;
    if (num / 10 != 0)
        ss << reverseStr(num / 10);
    if (negative)
        ss << '-';
    return ss.str();
}
int main(int argc, char* argv[])
//int main(int argc, char** argv) 
{
    if (argc < 2)
    {
        cout << "Usage: please input an integer!" << endl;
        exit(1);
    }
    stringstream ss(argv[1]);
    int num;
    ss >> num;
    cout << reverseStr(num) << endl;

    return 0;
}
