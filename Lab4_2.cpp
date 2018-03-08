//============================================================================
// Name        : Lab4_2.cpp
// Author      : Tess McCorkle
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int* openFile(int num){	//takes in the number of the file, then returns a pointer to the array of integers
	//cout << "in open function" << endl;
	string myFile;
	string sNum = to_string(num);

	//cout << sNum<< endl;

	if(num >= 10){
		myFile = "Raw_data_" + sNum + ".txt";
	}else{
		myFile = "Raw_data_0" + sNum + ".txt";
	}
	cout << myFile << endl;

	ifstream inFS;
	inFS.open(myFile);
	cout << "opening file" << endl;

	//check if the file opens
	if(!inFS.is_open()) {
			cerr << "Could not open the file " << myFile << endl;
			return 0;
	}
	//get the number of characters in the file
	int numElements, maxValue;
	inFS >> numElements;
	inFS >> maxValue;

	int *data = (int*) (malloc( (numElements+1) * sizeof(int) ));	//+1 bc it's saving the size into the array as well as the data
	int i = 1;
	*data = numElements;

	while(!inFS.eof()){
			inFS >> data[i++];
	}
	inFS.close();
	return data;
}

void offsetData(int fileNum, double offset, int* data){
	//loop through the data and add offset value to each data point
	//save new array to a file named "Offset_data_num.txt"
	string myFile;
	int length = *data; //saves the first value in data to the variable length
	ofstream outFile;

	if(fileNum >= 10){
		myFile = "Offset_data_" + to_string(fileNum) + ".txt";
	}else{
		myFile = "Offset_data_0" + to_string(fileNum) + ".txt";
	}

	outFile.open(myFile);
	outFile << *data << " " << offset;

	for(int i = 1; i < length; i++){
		outFile << "\n" << ( data[i] + offset );
	}

	outFile.close();
	cout<< "Done with offset!"<< endl;
}

void scaleData(int fileNum, double scale, int* data){
	//loop through the data and multiply be scale
	//save new array to a file named "Scaled_data_num.txt"
	int length = *data;
	ofstream outFile;
	string myFile;

	if(fileNum >= 10){
		myFile = "Scaled_data_" + to_string(fileNum) + ".txt";
	}else{
		myFile = "Scaled_data_0" + to_string(fileNum) + ".txt";
	}

	outFile.open(myFile);
	outFile << *data << " " << scale;

	for(int i = 1; i < length; i++){
		outFile << "\n" << double(data[i] * scale);
	}

	outFile.close();
	cout<< "Done with scaling!"<< endl;

}

void rename(int fileNum, string newName){
	ifstream inFS;
	ofstream outFS;
	string oldFile;
	int data;

	if(fileNum >= 10){
		oldFile = "Raw_data_" + to_string(fileNum) + ".txt";
	}else{
		oldFile = "Raw_data_0" + to_string(fileNum) + ".txt";
	}
	string newFile = newName + ".txt";

	inFS.open(oldFile);
	outFS.open(newFile);

	while(!(inFS.eof())){
		inFS >> data;
		outFS << data << "\n";
	}

	inFS.close();
	outFS.close();
	cout << "Created copy of " << oldFile << " and saved it to " << newFile << endl;
}

double getAverage(int* data){
	double average;
	int length = *data;

	for(int i = 1; i < length; i++){
		average += data[i];
	}
	average = average/length;
	return average;
}

int getMax(int* data){
	int max = 0;
	int value;
	int length = *data;

	for(int i = 1; i < length; i++){
		value = data[i];
		if(value > max){
			max = value;
		}
	}

	return max;
}

void saveStats(int max, double ave, int fileNum){
	ofstream outFS;
	string file = "Statistics_data_0" + to_string(fileNum) + ".txt";

	outFS.open(file);
	outFS << ave << " " << max;

	outFS.close();

}

void normalizeData(int* data, int fileNum){
	int length = *data;
	int max = getMax(data);
	ofstream outFS;
	string file = "Normalized_data_0" + to_string(fileNum) + ".txt";

	outFS.open(file);

	for(int i = 1; i < length; i++){
		outFS  <<  data[i]/static_cast<double>(max) << "\n";
	}

	outFS.close();
}

void centerData(int* data, int fileNum){

}

void displayError(){
	cout << "Not enough information or wrong format, options include:" <<endl;
	cout << "-n: File number (number needed)\n"
			"-o: offset value (number needed)\n"
			"-s: scale factor (number needed)\n"
			"-r: Rename files (name needed)\n" << endl;
}

int main(int argc, char **argv) {
	//cout << argc <<endl;

	int i = 0;
	int fileNum = 0;
	double offsetVal = 0;
	double scale = 0;
	int stats = 0;
	int normalize = 0;
	int center = 0;
	string newName;

	//NEED TO ADD ERROR CHECKS
	for( int c = 0; c < argc; c++ ){

		//parse the argv command to get the options selected
		if( strncmp(argv[i], "-n", 2) == 0 ){
			fileNum = atoi(argv[i+1]);
			cout << "file number " << fileNum << endl;

		}
		else if( strncmp(argv[i], "-o", 2) == 0 ){
			offsetVal = atof(argv[i+1]);
			cout << "offset value " << offsetVal << endl;
		}
		else if( strncmp(argv[i], "-s", 2) == 0 ){
			scale = atof(argv[i+1]);
			cout << "scale: " << scale << endl;
		}
		else if( strncmp(argv[i], "-r", 2 ) == 0){
			newName = argv[i+1];
			cout << "new name: " << newName << endl;
		}
		else if(strncmp(argv[i], "-h", 2) == 0){
			cout << "Options available:\n-n: File number (value needed)\n"
					"-o: offset value (value needed)\n"
					"-s: scale factor (value needed)\n"
					"-r: Rename files (name needed)\n" << endl;
			return 0;
		}
		else if(strncmp(argv[i], "-S", 2 ) == 0){
			stats = 1;
		}
		else if(strncmp(argv[i], "-N", 2 ) == 0){
			normalize = 1;
		}
		else if(strncmp(argv[i], "-C", 2 ) == 0){
			center = 1;
		}
		i++;
	}

	//Error checks to make sure user has specified which file to open
	if(fileNum == 0){
		displayError();
		return 1;
	}
	int *data = openFile(fileNum);	//open file and get data

	if( offsetVal != 0){
		offsetData(fileNum, offsetVal, data);
	}
	if(scale != 0){
		scaleData(fileNum, scale, data);
	}
	if(newName.size() != 0){
		rename(fileNum, newName);
	}
	if(stats == 1){
		double average = getAverage(data);
		int max = getMax(data);
		saveStats(max, average, fileNum);

	}
	if(normalize == 1){
		normalizeData(data, fileNum);
	}
	if(center == 1){
		centerData(data, fileNum);
	}

	free(data);
	return 0;
}
