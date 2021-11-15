/**ASIGNMENT NO 1
 * MATRIC NO: 207210
 * NAME: Olawole Akindele Michael
 * DEPARTMENT: COMPUTER SCIENCE
*/

#include <iostream>

using namespace std;

#define MAX 5

class Stack{
	
	private: 
		int top;
		int data;
		
		//check if stack is full
		bool isFull() {
			if(top == MAX){
				return true;
			}else{
				return false;
			}
		}
		
		//check if stack is empty
		bool isEmpty() {
			if(top == 0){
				return true;
			}else{
				return false;
			}
		}
		
	//initialize variables
	public:
		int stack[MAX] = {};
		//bool exitApp = false;
		Stack() {
			top = 0;
			data = -1;
		}
		
		//add value to stack
		void push(int data) {
			//if it is not full then allow then add to stack
			if(!isFull()) {
				stack[top] = data;
				top = top + 1;
				cout <<"\n" << data << " is added to stack" << endl;
			}else{
				cout << "\nFailed to add. Stack is full." << endl;
			}
		}
		
		//remove value from top of stack
		int pop() {
		//if it is not empty then remove top element
		
			if(!isEmpty()) {
				data = stack[--top];
				cout << "\n" << data << " is removed from stack" << endl;
				stack[top] = 0;
				return data;
				
			} else {
				cout << "\nFailed to pop. Empty Stack." << endl;
				return -1;
			}
			
		}
		
		//display all values in stack
		void display() {
			cout << "Stack: ";
			if(top==0){
				cout << "Stack Empty. Nothing to display." << endl;
				//cout << "" << endl;
				return;
			}
			for(int n=0;  n<top; n++) {
				cout << stack[n] << " ";
			}
			cout << "" << endl;
		}
};

// greetings
void greetings() {
	cout << "Welcome to the Stack --- The MAX value for your Stack is 5" << endl; 
}

// menu
void menu() {
	cout << "Which operation do you wish to perform:\n1) PUSH \n2) POP \n3) DISPLAY \n4) EXIT" << endl;
}

void runStack() {
	Stack stack;
	bool isDone = false;
	
	while(true) {
		cout<< "\nChoose an option: ";
		string option;
		cin >> option;
		cout << "You chose option: " << option << endl;
		cout << "-----------------------------" << endl;
		
		//check if option selected is within range
		if(option == "1") {
			string pushVal;
			bool isCorrectVal = false;
			while (true) {

				//break this inner loop once user enters correct value.
				if(isCorrectVal) {
					break;
				}

				//do this atleast once or as many times the user enters a wrong value.
				try {
					cout << "Enter value to push to stack: ";
					cin >> pushVal;	
					int pushInt = stoi(pushVal); //convert to integer
					stack.push(pushInt);
					isCorrectVal = true;
					menu();
				} catch(const std::exception& e) {
					cout << "Wrong input. You tried entering a letter." << endl;
					isCorrectVal = false;
				}	
			}
			cout << "-----------------------------" << endl;
		} else if(option == "2") {
			int poppedVal;
			poppedVal = stack.pop();
			menu();
			cout << "-----------------------------" << endl;
		} else if(option == "3") {
			cout << "\nDisplaying stack..." << endl;
			stack.display();
			menu();
			cout << "-----------------------------" << endl;
		} else if(option == "4") {
			cout << "Bye, Thanks for stacking with us :)" << endl;
			cout << "-----------------------------" << endl;
			break;
		}else{
			cout << "Please choose a valid option." << endl;
			menu();
			cout << "-----------------------------" << endl;
		}
	}
}

int main() {
	greetings();
	menu();
	runStack();
}
