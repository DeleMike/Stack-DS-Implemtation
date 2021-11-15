/**ASIGNMENT NO 2
 * MATRIC NO: 207210
 * NAME: Olawole Akindele Michael
 * DEPARTMENT: COMPUTER SCIENCE
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//class to group firstname, middlename and lastname together
class Name
{
public:
    string fName;
    string mName;
    string lName;
};

//a linked list node
struct Node
{
    Name data;
    struct Node *next;
};

//linked list class implementation
class LinkedList
{
private:
    Node *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    //add to the end of the list
    void appendNode(Name data)
    {
        Node *tmp = new Node;
        tmp->data = data;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
            tmp = NULL;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }

    }

    //print out the items in the list
    void display()
    {
        Node *temp = new Node;
        temp = head;
        if (head == NULL)
        {
            cout << "No Nodes in singly linked list" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << "(" << temp->data.fName << "\""
                     << ",\"" << temp->data.mName << "\""
                     << ",\"" << temp->data.lName << "\")-->";
                temp = temp->next;
            }
            cout << "\n"<< endl;
        }
    }

    //sort by first name
     void sortByFirstName()
    {
        struct Node *current = head, *index = NULL;
        string temp;
        string tempMidName, tempLastName;

        if (head == NULL)
        {
            return;
        }
        else
        {
            while (current != NULL)
            {
                index = current->next;

                while (index != NULL)
                {
                    if (current->data.fName > index->data.fName)
                    {
                        temp = current->data.fName;
                        tempMidName = current->data.mName;
                        tempLastName = current->data.lName;

                        current->data.fName = index->data.fName;
                        current->data.mName = index->data.mName;
                        current->data.lName = index->data.lName;

                        index->data.fName = temp;
                        index->data.mName = tempMidName;
                        index->data.lName = tempLastName;
                    }

                    index = index->next;
                }

                current = current->next;
            }
            cout << "sorted by first name" << endl;
        }
    }

    //sort by middle name
    void sortByMiddleName () {
        struct Node *current = head, *index = NULL;
        string temp;
        string tempFirstName, tempLastName;

        if (head == NULL)
        {
            return;
        }
        else
        {
            while (current != NULL)
            {
                index = current->next;

                while (index != NULL)
                {
                    if (current->data.mName > index->data.mName)
                    {
                        temp = current->data.mName;
                        tempFirstName = current->data.fName;
                        tempLastName = current->data.lName;

                        current->data.fName = index->data.fName;
                        current->data.mName = index->data.mName;
                        current->data.lName = index->data.lName;

                        index->data.mName = temp;
                        index->data.fName = tempFirstName;
                        index->data.lName = tempLastName;
                    }

                    index = index->next;
                }

                current = current->next;
            }
            cout << "sorted by middle name" << endl;
        }
    }

    //sort by last name
    void sortByLastName()
    {
        struct Node *current = head, *index = NULL;
        string temp;
        string tempFirstName, tempMidName;

        if (head == NULL)
        {
            return;
        }
        else
        {
            while (current != NULL)
            {
                index = current->next;

                while (index != NULL)
                {
                    if (current->data.lName > index->data.lName)
                    {
                        temp = current->data.lName;
                        tempFirstName = current->data.fName;
                        tempMidName = current->data.mName;

                        current->data.fName = index->data.fName;
                        current->data.mName = index->data.mName;
                        current->data.lName = index->data.lName;

                        index->data.lName = temp;
                        index->data.fName = tempFirstName;
                        index->data.mName = tempMidName;
                    }

                    index = index->next;
                }

                current = current->next;
            }
        }

        cout << "sorted by last name" << endl;
    }

    //save output to file
    void writeToFile() {
        ofstream myFile;
        myFile.open("sort_output.txt");
         Node *temp = new Node;
        temp = head;
        if (head == NULL)
        {
            cout << "No Nodes in singly linked list" << endl;
        }else {
            int iden = 100;
             while (temp != NULL)
            {
                myFile <<  temp->data.fName << " || " << temp->data.mName << " || " << temp->data.lName << " || " << iden << endl;
                temp = temp->next;
                iden += 10;
            }

            cout<< "written to file" << endl;
        }

        myFile.close();
        
    }
};

void menu() {
	cout << "How do you want to sort your file?:\n1) By Firstname \n2) By Middlename \n3) By Lastname \n4) EXIT" << endl;
}

void runProgram()
{
    //ifstream myFileStream("sample_file.txt");
    ifstream myFileStream("sort_input.txt");
    if (!myFileStream.is_open())
    {
        cout << "File failed to open";
        return;
    }

    LinkedList list;
    string firstname, middlename, lastname;

    string line;
    int index = 1;
    Name name;

    while (getline(myFileStream, line))
    {
        stringstream ss(line);

        getline(ss, firstname, ',');
        getline(ss, middlename, ',');
        getline(ss, lastname, ',');

        name.fName = firstname;
        name.mName = middlename;
        name.lName = lastname;

        list.appendNode(name);
    }
    myFileStream.close();


    //===================================================================

    cout << "FILE DATA IS LOADED"<< endl;
    menu();
    //list before sorting
    cout << "before sorting...\n" << endl;
    list.display();
    while(true) {
        cout<< "\nChoose an option: ";
		string option;
		cin >> option;
		cout << "You chose option: " << option << endl;
		cout << "-----------------------------" << endl;

        //check if option selected is within range
		if(option == "1") {
            list.sortByFirstName();
            list.writeToFile();
			menu();
			cout << "-----------------------------" << endl;
		} else if(option == "2") {
			list.sortByMiddleName();
            list.writeToFile();
			menu();
			cout << "-----------------------------" << endl;
		} else if(option == "3") {
		    list.sortByLastName();
            list.writeToFile();
			menu();
			cout << "-----------------------------" << endl;
		}else if(option == "4") {
            cout << "Bye, Thanks for sorting with us :)" << endl;
			cout << "-----------------------------" << endl;
			break;
        } else{
			cout << "Please choose a valid option." << endl;
			menu();
			cout << "-----------------------------" << endl;
		}

         //list after sorting
        cout << "after sorting" << endl;
        list.display();
    }
}


int main()
{
    runProgram();

}