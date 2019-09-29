//header file for bstree class

#ifndef BSTREE_H_EXISTS
#define BSTREE_H_EXISTS
#include "node.h"
#include <fstream>
#include <string>

class Bstree{
	
	private:
		Node* root;
	
	
	
	public:
		//null constructor
		Bstree();

		//non-null constructor
		Bstree(std::string temp, int a);	

		//destructor
		~Bstree();	
		//function for the destructor to call that deletes all of the children of root
		void deleteChildren(Node* temp);

		//have a method to get the root
		Node* getRoot();

		//have a method to add a node
		Node* createNode(std::string temp, int a);		
		
		void addNode(std::string temp, int a, Node* b);
	
		//have a method that outfiles the binary search tree 
		//into an output file, in alphabetical order
		void printTree(Node* temp, std::ofstream &outfile); 
		 
		




};//end Bstree

#endif
	
