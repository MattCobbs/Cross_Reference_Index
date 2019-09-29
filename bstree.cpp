//cpp file for bstree class

#include "bstree.h"
#include "node.h"

#include <iostream>

int compareWords(std::string a, std::string b);



//constructor
Bstree::Bstree(){
	root = NULL;
}//end null constructor

//non-null constructor
Bstree::Bstree(std::string temp, int a){
	Node* n = new Node(temp,a);
	root = n;

}//end non-null constructor

//destructor
Bstree::~Bstree(){
	deleteChildren(root);
}//end destructor	

//function for destructor to call that deletes all children
void Bstree::deleteChildren(Node* temp){
	if(temp != NULL){
		if(temp->getLeft() != NULL){
			deleteChildren(temp->getLeft());
		}//end if

		if(temp->getRight() != NULL){
			deleteChildren(temp->getRight());
		}//end if
		delete temp;
	}//end if
}//end deleteChildren

Node* Bstree::getRoot(){
	if(root == NULL){
		return NULL;
	}//end if

	else{
		return root;
	}//end else
}//end getRoot



Node* Bstree::createNode(std::string temp, int a){
	Node* n = new Node(temp,a);
	return n;
}//end createNode


void Bstree::addNode(std::string temp, int a, Node* b){
	std::string compareable = b->getWord();	

	if(root == NULL){
		root = createNode(temp, a);
	}//end if

	else if(compareWords(temp, compareable) == 0){
		//if the two words are the same add the line number
		//to the vector		
		b->setLineNumber(a);
	}//end else if

	else if(compareWords(temp, compareable) == 2){
		//if the left word is worth more: check if the 
		//left Node* is null, if it is create a new node with the 
		//string and int
		if(b->getLeft() == NULL){
			Node* child = new Node(temp, a);
			b->setLeft(child);
		}//end if

		//if it isn't recursively call the addNodePoint()
		//to find the next place for the word to go
		else if(b->getLeft() != NULL){
			addNode(temp,a, b->getLeft());
		}//end else if

		//leave an else containing an error message to help debug
		else{
			std::cout << "Error in bstree::addNode()" << std::endl << "Traversing left is not working" << std::endl;
		}//end else
	}//end else if

	else if(compareWords(temp, compareable) == 1){
		//if the left word is worth less: check if the right
		//Node* is null, if it is create a new node with the 
		//string and int
		if(b->getRight() == NULL){
			Node* child = new Node(temp, a);
			b->setRight(child);
		}//end if

		//if it isn't, reqursively call the addNodePoint()
		//to find the next place for the word to go
		else if(b->getRight() != NULL){
			addNode(temp,a, b->getRight());
		}//end else if

		//leave an else containing an error message to help debug
		else{	
			std::cout << "Error in bstree::addNode()" << std::endl << "Traversing right is not working" << std::endl;
		}//end else
	}//end else if

	else{
		std::cout << "The new word and Node's word are not being compared" << std::endl;
	}//end else

}//end addNode

void Bstree::printTree(Node* temp, std::ofstream &outfile){
	
	if(Bstree::getRoot() != NULL){
		if(temp->getLeft() != NULL){
			printTree(temp->getLeft(), outfile);
			outfile << temp->getWord();
			outfile << temp->getLineNumbers() << std::endl;
		}//end if
	
		else{
			outfile << temp->getWord();
			outfile << temp->getLineNumbers() << std::endl;
		}//end else

		if(temp->getRight() != NULL){
			printTree(temp->getRight(), outfile);
		}//end if

		else{		
		}//end else

	}//end if

	else{
		outfile << "There is nothing in the text file" << std::endl;
	}//end else


}//end printTree




//compare function
int compareWords(std::string a, std::string b){
	
	if((a.compare(0,10,b,0,10)) == 0){
		//have a cout statement while testing
		return 0;
	}//end if

	else if((a.compare(0,10,b,0,10)) > 0){
		//cout statement while testing
		return 1;
	}//end else if

	else if((a.compare(0,10,b,0,10)) < 0){
		//cout statement while testing
		return 2;
	}//end else if

	else{
		std::cout << "This should not appear" << std::endl;
	}//end else

}//end compareWord function





////////////////////////////////////////////////////////////////////////////


/*	
int main(){

	Bstree* testTree = new Bstree("set",1);

	testTree->addNode("an", 1, testTree->getRoot());

	testTree->addNode("integer", 2, testTree->getRoot());

	testTree->addNode("variable", 3, testTree->getRoot());

	testTree->addNode("x1", 3, testTree->getRoot());

	testTree->addNode("to", 4, testTree->getRoot());
	testTree->addNode("be", 4, testTree->getRoot());
	testTree->addNode("2", 4, testTree->getRoot());
	testTree->addNode("set", 4, testTree->getRoot());
	testTree->addNode("y2", 4, testTree->getRoot());
	testTree->addNode("to", 4, testTree->getRoot());
	testTree->addNode("be", 5, testTree->getRoot());

	testTree->addNode("2", 5, testTree->getRoot());
	testTree->addNode("yes", 5, testTree->getRoot());
	testTree->addNode("y2", 5, testTree->getRoot());
	testTree->addNode("is", 5, testTree->getRoot());
	testTree->addNode("a", 5, testTree->getRoot());
	testTree->addNode("variable", 5, testTree->getRoot());
	testTree->addNode("yes", 5, testTree->getRoot());
	testTree->addNode("y2", 5, testTree->getRoot());
	testTree->addNode("is", 5, testTree->getRoot());
	testTree->addNode("an", 5, testTree->getRoot());
	testTree->addNode("integer", 5, testTree->getRoot());
	testTree->addNode("add", 5, testTree->getRoot());
	testTree->addNode("y2", 5, testTree->getRoot());
	testTree->addNode("to", 5, testTree->getRoot());
	testTree->addNode("x1", 5, testTree->getRoot());
	testTree->addNode("print", 5, testTree->getRoot());
	testTree->addNode("the", 5, testTree->getRoot());
	testTree->addNode("result", 5, testTree->getRoot());
	testTree->addNode("convert", 5, testTree->getRoot());
	testTree->addNode("the", 5, testTree->getRoot());
	testTree->addNode("result", 5, testTree->getRoot());
	testTree->addNode("to", 5, testTree->getRoot());
	testTree->addNode("an", 5, testTree->getRoot());
	testTree->addNode("integer", 5, testTree->getRoot());
	testTree->addNode("thank", 5, testTree->getRoot());
	testTree->addNode("you", 5, testTree->getRoot());
	testTree->addNode("#", 5, testTree->getRoot());


	testTree->printTree(testTree->getRoot());

}//end main
*/






