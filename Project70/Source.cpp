#include <iostream>
#include <cstring>

class MyString
{
private:
    char* str;
    int length;
    static int objectCount;

public:

    MyString() : length(0)
    {
        str = new char[81];
        str[0] = '\0';
        objectCount++;
    }


    MyString(int size) : length(0)
    {
        str = new char[size + 1];
        str[0] = '\0';
        objectCount++;
    }


    MyString(const char* input)
    {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
        objectCount++;
    }


    ~MyString()
    {
        delete[] str;
        objectCount--;
    }


    void input()
    {
        std::cout << "Введите строку: ";
        std::cin.getline(str, 81);
        length = strlen(str);
    }


    void output() const
    {
        std::cout << str << std::endl;
    }


    void MyStrcpy(const MyString& obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }


    bool MyStrStr(const char* substr) const
    {
        return strstr(str, substr) != nullptr;
    }


    int MyChr(char c) const
    {
        char* pos = strchr(str, c);
        return (pos) ? (pos - str) : -1;
    }


    int MyStrLen() const {
        return length;
    }


    void MyStrCat(const MyString& b)
    {
        char* newStr = new char[length + b.length + 1];
        strcpy(newStr, str);
        strcat(newStr, b.str);
        delete[] str;
        str = newStr;
        length += b.length;
    }


    void MyDelChr(char c)
    {
        char* newStr = new char[length + 1];
        int newLength = 0;

        for (int i = 0; i < length; i++)
        {
            if (str[i] != c)
            {
                newStr[newLength++] = str[i];
            }
        }
        newStr[newLength] = '\0';
        delete[] str;
        str = newStr;
        length = newLength;
    }


    int MyStrCmp(const MyString& b) const
    {
        if (strcmp(str, b.str) < 0) return -1;
        if (strcmp(str, b.str) > 0) return 1;
        return 0;
    }


    MyString operator+(const MyString& b)
    {
        MyString result(length + b.length);
        strcpy(result.str, str);
        strcat(result.str, b.str);
        result.length = length + b.length;
        return result;
    }


    MyString& operator++()
    {
        MyStrCat(MyString(" "));
        return *this;
    }

    static int getObjectCount()
    {
        return objectCount;
    }
};


int MyString::objectCount = 0;

int main()
{
    MyString str1("Hello");
    MyString str2(" World!");

    str1.MyStrCat(str2);
    str1.output();

    std::cout << "Количество объектов: " << MyString::getObjectCount() << std::endl;

    str1.MyDelChr('o');
    str1.output();

    return 0;
}