#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "ArgumentManager.h"

using namespace std;


const int size = 20; // initialize matrix size



//start class matrix
class matrix
{
	ifstream input;
	ofstream output;
public :
	void read (double m[size][size]); //function read use to input data to variable matrix
	void print (double m[size][size]);//function print use to out put data
	matrix(int count);//constructor with 1 parameter

	void matrixMul(double m[size][size]);//function matrixMul use to make matrix A*A

private: 
	double mat[size][size];
	int si;
}; 
// end class matrix

//start function read
void matrix::read(double m[size][size])
{
	string a;
	input.open("3.txt");
std:getline(input , a );


	for (int i = 0 ; i<si ; i++)
		for (int j = 0 ; j < si ; j++)
			{
				input >> m[i][j];
				mat[i][j] = m[i][j];
			}
		input.close();
}
//end function read 

//start function print
void matrix::print(double m[size][size])
{
	output.open("a1.txt");

	for (int i = 0; i <si ; i++)
	{
		for (int j = 0 ; j < si ; j++)
		{
			output<< setw(8) <<left<< fixed <<  setprecision(2) <<mat[i][j] ;
		}
		output <<endl;
	}
}

//start function matrix multilication
void matrix::matrixMul(double m[size][size])
{
	double temp = 0;
	for (int i = 0; i < si ; i++)
		{
			for (int z= 0; z < si ; z++)
			{
			for(int j = 0; j < si; j++)
			{
			
			 temp = temp + m[i][j]*m[j][z];
		
			}

	
			mat[i][z] = temp;
			temp = 0;
			}
		}

	
}
//end function matrix mulitication

// start matrix construction
matrix::matrix(int count)
{
	if(count <0 || count > 20)
		si = 20;
	else
		si = count -1 ;

	for (int i = 0; i< count ; i++)
		for (int j = 0; j < count ; j++)
			mat[i][j] = 0;
}
//end matrix construction



int main() {
	ifstream input;
	ofstream output;
	
	string example;
	int count = 0;
	input.open("3.txt"); //open test data
   if (input.fail()) //check for file open failure
{
    cout << "Error opening file. NO file found" << endl;
    cout << "Note that the program will halt" << endl;//error prompt
}

else if (input.peek() == std::ifstream::traits_type::eof())
{
    cout << "File is empty" << endl;
    cout << "Note that program will halt" << endl; // error prompt
}
else
{
    //run the file

	while(getline(input, example))
		count++;
	input.close();

	matrix matrix1(count);

	double m[size][size];
	matrix1.read(m);

	matrix1.matrixMul(m);
	matrix1.print(m);
	


	output.close();
}
	system("pause");
	return 0;

}