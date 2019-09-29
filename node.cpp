//cpp file for node class

#include "node.h"
#include <string>
#include <iostream>
#include <sstream>


//
//constructor
//
Node::Node(){
	
			left = NULL;
			right = NULL;
			//add whatever data type the node is storing
			
}//end null constructor
//////////////////////////////////////////////////////////////////////////
Node::Node(std::string temp, int a){
	//add a non NULL constructor based off of the purpose of the node
	word = temp;
	lineNumber.push_back(a);
	left = NULL;
	right = NULL;
	
}//end constructor
//////////////////////////////////////////////////////////////////////////
//
//Destructor
//
Node::~Node(){
	
	//any objects that the node contains will need
	//to be deleted inside it's destructor

}//end destructor
/////////////////////////////////////////////////////////////////////////
//
//Node functions
//
Node* Node::getLeft(){
	return Node::left;
}//end getLeft

Node* Node::getRight(){
	return Node::right;
}//end getRight

void Node::setLeft(Node* temp){
	Node::left = temp;
}//end setLeft

void Node::setRight(Node* temp){
	Node::right = temp;
}//end setRight
/////////////////////////////////////////////////////////////////////////
//
//LineNumber getter and setter
//
//////////////////////////////////////////////////////////////////////////
//getLineNumLen will return the length of the vector that is used
//to store the line numbers
int Node::getLineNumLen(){
	return lineNumber.size();
}//end getLinNumLen

//getLineNumbers will convert all of the values in the vector
//into one string and then return it
std::string Node::getLineNumbers(){
	int temp = lineNumber.size();	
	std::string holder = "  ";

	

	for(int i = 0; i < temp; i++){
		std::stringstream ss;
		std::string tempWord;

		//clear the string stream
		ss.clear();

		//pass the value from the vector index indicated and pass it to the 
		//temp variable
		ss << lineNumber[i];
		ss >> tempWord;
	
		//add the value from the temp string to the variable being returned
		holder += tempWord;

		//add spacing
		holder += "  ";

		//clear the string stream
		ss.clear();

	}//end for i
	
	return holder;

}//end getLineNumbers

//getNumber will return the value at the vector index
//that is supplied to the function
int Node::getNumber(int temp){
	return lineNumber[temp];
}//end getNumber

//setLineNumber will add a value to the vector that the line numbers are
//stored on
void Node::setLineNumber(int temp){
	lineNumber.push_back(temp);
}//end setLineNumber
/////////////////////////////////////////////////////////////////////////////////////
//
//getWord functions
//
////////////////////////////////////////////////////////////////////////////////////

//getWord will return the string stored in the node
std::string Node::getWord(){
	return word;
}//end getWord

	
/*	
int main(){
	Node* practiceNode = new Node("test", 5);


	
	//std::cout << practiceNode->getLineNumLen() << std::endl;	
	
	practiceNode->setLineNumber(3);
	practiceNode->setLineNumber(7);

	std::cout << practiceNode->getNumber(0) << "  " << practiceNode->getNumber(1) << "  " << practiceNode->getNumber(2) << std::endl;

		
	//std::cout << practiceNode->getLineNumLen() << std::endl;	
	
	
	std::cout << "The following should look like the previous" << std::endl;
	std::cout << practiceNode->getLineNumbers() <<std::endl;	
	
}//end main
	
*/	
	
	
	
	
	
	
	
	
	
	
	
