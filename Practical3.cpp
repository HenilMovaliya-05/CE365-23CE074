#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream file("practical1.c");

    string keyword[32] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    string operators = "+-*/%=&|^~<>!";
    string punctuations = ".,;:(){}[]#";

    if (!file.is_open())
    {
        cout << "File not found!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();

    for (size_t i = 0; i < fileContent.size();)
    {

        if (fileContent[i] == '/' && i + 1 < fileContent.size() &&
            fileContent[i + 1] == '/')
        {

            size_t j = i;
            while (j < fileContent.size() && fileContent[j] != '\n')
                j++;
            fileContent.erase(i, j - i);
        }
        else if (fileContent[i] == '/' && i + 1 < fileContent.size() &&
                 fileContent[i + 1] == '*')
        {

            size_t j = i + 2;
            while (j + 1 < fileContent.size() &&
                   !(fileContent[j] == '*' && fileContent[j + 1] == '/'))
                j++;
            j += 2;
            fileContent.erase(i, j - i);
        }
        else
        {
            i++;
        }
    }

    for (size_t i = 0; i < fileContent.size();)
    {

        if (isspace(fileContent[i]))
        {
            i++;
            continue;
        }

        if (isalpha(fileContent[i]) || fileContent[i] == '_')
        {
            size_t j = i;
            while (j < fileContent.size() &&
                   (isalnum(fileContent[j]) || fileContent[j] == '_'))
                j++;

            string str = fileContent.substr(i, j - i);
            bool isKey = false;

            for (int k = 0; k < 32; k++)
            {
                if (str == keyword[k])
                {
                    cout << "Keyword: " << str << endl;
                    isKey = true;
                    break;
                }
            }

            if (!isKey)
                cout << "Identifier: " << str << endl;

            i = j;
        }

        else if (isdigit(fileContent[i]))
        {
            size_t j = i;
            while (j < fileContent.size() && isdigit(fileContent[j]))
                j++;

            cout << "Constant: " << fileContent.substr(i, j - i) << endl;
            i = j;
        }

        else if (fileContent[i] == '\'')
        {
            size_t j = i + 1;
            while (j < fileContent.size() && fileContent[j] != '\'')
                j++;
            j++;

            cout << "Constant: " << fileContent.substr(i, j - i) << endl;
            i = j;
        }

        else if (operators.find(fileContent[i]) != string::npos)
        {
            cout << "Operator: " << fileContent[i] << endl;
            i++;
        }

        else if (punctuations.find(fileContent[i]) != string::npos)
        {
            cout << "Punctuation: " << fileContent[i] << endl;
            i++;
        }

        else
        {
            i++;
        }
    }

    return 0;
}