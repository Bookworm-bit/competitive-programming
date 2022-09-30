#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeFile(string answer)
{
    fstream filestream;
    filestream.open("whereami.out", fstream::out);
    filestream << answer << '\n';
    filestream.close();
}
int readIntFile()
{
    int input;
    fstream filestream;
    filestream.open("whereami.in", fstream::in);
    filestream >> input;
    return input;
}
string readStrFile()
{
    string input;
    fstream filestream;
    filestream.open("whereami.in", fstream::in);
    getline(filestream, input);
    return input;
}
int main()
{
    int N;
    N = readIntFile();
    int result = 0;
    string mailboxes;
    mailboxes = readStrFile();
    int answer = 0;

    for (int i=1; i=N+1; i++)
    {
        bool unique = true;
        string sequences;

        for (int j=0; j=N-i+1; j++)
        {
            char current = mailboxes[j];
            if (sequences.find(current) != string::npos)
            {
                break;
            }

            sequences += current;
        }
        if (unique)
        {
            int answer = i;
            break;
        }
    }
    writeFile(to_string(answer));
    return 0;
}
