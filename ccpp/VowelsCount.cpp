/*
Write a program that reads a file with the following information (yes, some letters are capitalized, and please also keep contents in different lines as shown below.):

ThIs is an exAmple of an Input file

Its cOntent can vary quite a lOt

However the objecTs you use to read It

Should nOt

After reading the file content you should process it and produce an output file showing the number of each vowel in the file.

Number of ‘a’s: X

Number of ‘e’s: Y

Number of ‘i’s: Z

Number of ‘o’s: M

Number of ‘u’s: N

......

Your program should “count” these characters independently if they are upper or lower case. The content of the file you read should be presented in the screen too, exactly as in

the input file. The input and output file names should be provided by the user or you can define directly, is up to you. You need to use at least one function in this program (main

doesn’t count).

For the screenshots of this question include the input and output file too. (No test cases)

Please use programming language C++ */

// ================= Vowels =================
#include <iostream>
#include <fstream>

using namespace std;

void createInputFile()
{
    ofstream myfile;
    myfile.open ("Sample.txt");
    myfile << "ThIs is an exAmple of an Input file" << endl;
    myfile << "Its cOntent can vary quite a lOt" << endl;
    myfile << "However the objecTs you use to read It" << endl;
    myfile << "Should nOt" << endl;
    myfile.close ();
}

void printVowelsCountToFile(int vowels[5])
{
    ofstream outFile;
    outFile.open ("Vowels.txt");
    outFile << "Number of a's :" << vowels[0] << endl;
    outFile << "Number of e's :" << vowels[1] << endl;
    outFile << "Number of i's :" << vowels[2] << endl;
    outFile << "Number of o's :" << vowels[3] << endl;
    outFile << "Number of u's :" << vowels[4] << endl;
    outFile.close ();
}

void countNumberOfVowels(int vowels[5])
{
    ifstream fReader;
    char ch;

    fReader.open ("Sample.txt"); // open file in read mode

    if (!fReader) // print error if file doesnt exists
    {
        cout << "File not present" << endl;
        exit(1);
    }

    while (fReader)
    {
        fReader.get(ch);
        printf("%c",ch);
        switch (ch)
        {
        case 'a':
        case 'A':
            vowels[0]++;
            break;
        case 'e':
        case 'E':
            vowels[1]++;
            break;
        case 'i':
        case 'I':
            vowels[2]++;
            break;
        case 'o':
        case 'O':
            vowels[3]++;
            break;
        case 'u':
        case 'U':
            vowels[4]++;
            break;
        }
    }

    fReader.close ();
}

main ()
{

// Un Comment below Code function call to create sample input file for vowles count.
    createInputFile();

    int num;
    int vowels[5] = {0};

    countNumberOfVowels(vowels);

    printVowelsCountToFile(vowels);
    cout << "Number of a's :" << vowels[0] << endl;
    cout << "Number of e's :" << vowels[1] << endl;
    cout << "Number of i's :" << vowels[2] << endl;
    cout << "Number of o's :" << vowels[3] << endl;
    cout << "Number of u's :" << vowels[4] << endl;


    return 0;
}
