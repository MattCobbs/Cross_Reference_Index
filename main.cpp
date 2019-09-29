//main file for Assignment 2

#include "bstree.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
//include the algorithm library for replace, remove if it didn't work
#include <algorithm>



int main(){

	//create an ifstream to handle the test file
	std::ifstream infile;

	infile.open("testFile.txt");

	//create an ofstream to handle the sample output
	std::ofstream outfile;

	outfile.open("sampleOut.txt");

	//check to make sure that infile was able to open
	//if it was, run the program
	if( infile.is_open() ){

//create variables for use	
//create a string variable to hold the parsed getline values
		std::string holder;
//create a second string variable to hold the second parsed getline values
		std::string testString;
//create a string vector variable to hold all of the words
		std::vector<std::string> wordVector;
//create an int vector variable to hold all of the line numbers for each word
		std::vector<int> lineVector;
//create an int variable set to 1 to keep track of the line numbers
		int lineCounter = 1;
//create a stringstream variable to hold each line of the text
		std::stringstream ss;


	//run a while loop, based off of the getline function parsing on new lines,
	//to keep everything running until a # is found
		while(getline(infile, holder, '\n')){

			if(holder == "#"){
//exit the while loop if getline returns a # 
				break;
			}//end if

			else{	
//using the algorithm library's replace function to change white spaces, and periods to comma's
				std::replace( holder.begin(), holder.end(), ' ', ',');
				std::replace( holder.begin(), holder.end(), '.', ',');

//pass the string variable to the stringstream so getline can use it 
				ss << holder;

//using getline, parse on commas to seperate
				while(getline(ss, testString, ',')){
					testString = testString.substr(0,10);
					testString.append(10 - testString.length(), ' ');
					wordVector.push_back(testString);
					lineVector.push_back(lineCounter);
				}//end while

//create a variable based off of the size of the wordVector
				int vectCount = wordVector.size();

//use a for loop based off of the wordVectors size to remove any vector indexes that don't have anything in them 
				for(int i = 0; i < vectCount; i++){
					std::string numberCheck = wordVector[i];
					char numberCheck2 = numberCheck[0];
	

					if(numberCheck2 == '0' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end if
					else if(numberCheck2 == '1' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '2' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '3' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '4' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '5' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '6' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '7' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '8' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == '9' ){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
					else if(numberCheck2 == ' '){
						wordVector.erase(wordVector.begin()+i);
						lineVector.erase(lineVector.begin()+i);
					}//end else if
				}//end for

				
	
//clear the stringstream
				ss.clear();	
			}//end else
//add one to the variable keeping track of the line number
			lineCounter ++;
		}//end while

//create a bstree object and and give it the value of the two vectors
//at their 0th index 
		Bstree* tree = new Bstree(wordVector[0],lineVector[0]);		

//create an int variable based off of the size of the wordVector
		int loopCounter = wordVector.size();
		
//loop through the vectors and assign the matching values to new nodes
		for(int i = 1; i < loopCounter; i++){
			tree->addNode(wordVector[i], lineVector[i], tree->getRoot());
		}//end for

//print out the bstree in ascending order	
		tree->printTree(tree->getRoot(), outfile);
		delete tree;
	}//end if

//return an error message if the text file is not open
	else{
		std::cout << "Error text file was not able to be opened" << std::endl;
	}//end else

//return 0 to end the program
	return 0;
}//end main	
