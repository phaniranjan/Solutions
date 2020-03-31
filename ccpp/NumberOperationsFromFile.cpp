================== C++ Code ==================

#include <iostream>
#include <fstream>

using namespace std;

main ()
{
// If running on online debugger create file with the following codeblock
    /*
    ofstream myfile;
    myfile.open ("Sample.txt");
    myfile << 1325 << endl;
    myfile << 4893 << endl;
    myfile << 3471 << endl;
    myfile << 21952 << endl;
    myfile << 9521 << endl;
    myfile << 10743;
    myfile.close ();
    */

    std::ifstream fReader;
    fReader.open ("Sample.txt"); // open file in read mode
    int num;
    long count = 0, sum = 0, average = 0;

    if (!fReader) // print error if file doesnt exists
    {
        std::cout << "File not present" << endl;
        return 0;
    }

    while (fReader >> num) // read one by one number from file and calculate count/sum
    {
        count++;
        sum += num;
    }

    average = sum / count; // calcualte average

    std::cout << "The number of elements :" << count << std::endl;
    std::cout << "The sum of elements :" << sum << std::endl;
    std::cout << "The average of elements :" << average << std::endl;

    fReader.close ();

    return 0;
}
