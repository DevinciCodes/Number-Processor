#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;

//Function Protoypes 
void ComputeStatistics(ifstream & file, int & count, int & smallest, int & largest, float & average);
void DisplayResults(int count, int smallest, int largest, float average);

//main function to ask input and open file
int main(){
    string filename;//init filename as string
    cout << "Please enter the data file name: ";//ask for user input
    cin >> filename;//store user input into filename
    cout << endl;//format
   

    ifstream myIn;//init myIn var as input file
    myIn.open(filename);//open file user inputed
    assert(myIn);//check if invalid file

   //init variables for computation as types we need
   int count, smallest, largest; 
   float average;

    //Call compute function, with parameters
    ComputeStatistics(myIn, count, smallest, largest, average);

    myIn.close();//close file

    //Call Display funtion to display results
    DisplayResults(count, smallest, largest, average);

    return 0;//exit
}

//void function to compute smallest, largest, and average. Then count total numbers.
void ComputeStatistics(ifstream & file, int & count, int & smallest, int & largest, float & average){
    int value;// init value var, holds each value
    float sum = 0;// init sum to 0
    count = 0; //init count to o

    // If the file contains at least one value, read it
    if (file >> value){
        // Initialize smallest and largest with the first value read
        smallest = value;// Init smallest with the first value
        largest = value;// Init largest with the first value
        sum += value;// Add the value to sum
        count++;// then increment count
        cout << value << endl;// display the value
    }

    // Continue reading the remaining values
    while (file >> value){
        cout << value << endl;// Display the value
        count++;// increment count
        sum += value;// add value to the sum

        //update smallest if the current value is smaller
        if (value < smallest){
            smallest = value;
        }
        //update largest if the current value is larger
        if (value > largest){
            largest = value;
        }

    }
    //Caluclate the average, if no values, handle 0 case
    if (count > 0){
        average = sum / count;
    } else{
        average = 0.0;
    }

}
//Display with cout statements, our result.
void DisplayResults(int count, int smallest, int largest, float average){
    cout << endl;
    cout << "Total " << count << " numbers." << endl;
    cout << "The largest number is " << largest << ", and the smallest number is " << smallest << "." << endl;
    cout << "The average of these numbers is " << fixed << setprecision(1) << average << "." << endl;
    
}