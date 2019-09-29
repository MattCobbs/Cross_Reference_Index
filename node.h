//header file for Node class

#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include <string>
#include <iostream>
#include <vector>


class Node{
	
	private:
			Node* left;
			Node* right;
			
			//Any data that the node stores would go in private
			//Would require all associated functions (getters, setters, ect) to be added as well
			
			std::vector<int> lineNumber;
			std::string word;
			
	public:


			//Null constructor
			Node();
			
			//A non null constructor should be made once the data that the
			//node is storing is established
			Node(std::string temp, int a);
			
			//deconstructor
			~Node();
	
			//Getters and setters for the next and previous members
			Node* getLeft();
			Node* getRight();
			
			void setLeft(Node* temp);
			void setRight(Node* temp);
			
			//Getters and setters for lineNumber and word
			int getLineNumLen();
			int getNumber(int temp);

			std::string getLineNumbers();
			
			std::string getWord();
			

			void setLineNumber(int temp);
			
};//end node class

#endif		
