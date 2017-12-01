#include <iostream>
#include <vector>

using namespace std;
string readLine();
void printInfo();
const int MAXINPUT = 256;


int main()
{
    string input;
    printInfo();
    input = readLine();
    if (input == "insert")
    {

    }
    return 0;
}


void printInfo()
{
    cout << "Insert a command" << endl;
    cout << "\"insert\" to insert an array" << endl;
    cout << "\"print\" to print a command" << endl;
    cout << "\"multiply\" to multiply all numbers below zero and print the result" << endl;
    cout << "\"delete\" to delete max numbers" << endl;
    cout << "\"exit\" to exit" << endl;
}

string readLine()
{
    char* input = (char*)calloc(1, sizeof(char)); /* init the array */
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if (i < MAXINPUT)
        {
            input = (char*)realloc(input, (i+1) * sizeof(char));
            input[i] = c;
            i++;
        }
    }
    input = (char*)realloc(input, (i + 1) * sizeof(char)); /* finishing a string */
    input[i] = '\0';
    return string(input);
}

vector<int> readNumbers()
{
    std::string data = readLine();
    std::stringstream iss(data);
    int number;
    std::vector<int> myNumbers;
    while (iss >> number)
    {
        myNumbers.push_back(number);
    }
    return myNumbers;
}
