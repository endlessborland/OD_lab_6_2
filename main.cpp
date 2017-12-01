//
//  main.cpp
//  od
//
//  Created by Денис Скоробогатов on 01.12.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string readLine();
void printInfo();
vector<int> readNumbers();
int multiply(vector<int>);
vector<int> del(vector<int>);

const int MAXINPUT = 256;


int main()
{
    string input;
    vector<int> array;
    while(true)
    {
        printInfo();
        input = readLine();
        if (input == "insert")
        {
            array = readNumbers();
        }
        if (input == "print")
        {
            for (int i = 0; i < array.size(); i++)
                cout << array[i] << " ";
            cout << endl;
        }
        if (input == "multiply")
        {
            cout << multiply(array) << endl;
        }
        if (input == "delete")
        {
            try {
                array = del(array);
            } catch (...) {
                cout << "No data in an array" << endl;
                continue;
            }
        }
        if (input == "exit")
            break;
    }
    return 0;
}

int multiply(vector<int> array)
{
    int result = 1;
    bool nbz = false;
    for(int i = 0; i < array.size(); i++)
    {
        if (array[i] < 0)
        {
            result *= array[i];
            nbz = true;
        }
    }
    return nbz ? result : 0;
}

vector<int> del(vector<int> array)
{
    int max = array[0];
    vector<int> positions;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    array.erase(remove(array.begin(), array.end(), max), array.end());
    return array;
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

