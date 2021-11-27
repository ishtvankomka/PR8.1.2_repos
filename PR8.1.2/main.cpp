#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* s, int i)
{
    if (s[i] != '\0')
    {
        if ((s[i] == 'A' &&
            s[i + 1] == 'G' &&
            s[i + 2] == 'A') ||
            (s[i] == 'O' &&
                s[i + 1] == 'G' &&
                s[i + 2] == 'O'))
        {
            return true;
        }
        return Include(s, i + 1);
    }
    else
    return false;
}
char* Change(char* dest, const char* str, char* t, int i)
{
    if ( str[i+2] != 0 )
    {
        if ((str[i] == 'A' &&
                str[i + 1] == 'G' &&
                str[i + 2] == 'A') ||
                (str[i] == 'O' &&
                str[i + 1] == 'G' &&
                str[i + 2] == 'O'))
        {
            strcat(t, "**");
            return Change(dest, str, t+2, i+3);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
        if ( Include(str, 0))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    return 0;
}
