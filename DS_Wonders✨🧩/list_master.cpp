#include <iostream>  // For standard I/O
#include <cstdlib>   // For malloc and rand
#include <ctime>     // For seeding random number generator

using namespace std; // To avoid typing std:: everywhere

// Node structure with data and link to the next node
struct Node {
    int data;
    Node* link;
};

// Function to create a new node and add it to the end of the list
Node* create(Node* start, int item) {
    Node* temp;
    if (start == nullptr) { // 🧐 If the list is empty
        start = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
        start->data = item; // Set node data
        start->link = nullptr; // End of list
    } else {
        temp = start;
        while (temp->link != nullptr) { // ⏳ Traverse to the end
            temp = temp->link;
        }
        temp->link = (Node*)malloc(sizeof(Node)); // Add new node
        temp = temp->link;
        temp->data = item;
        temp->link = nullptr; // End of list
    }
    return start;
}

// Function to print the linked list
void printList(Node* start) {
    cout << "\nAddress of node    Data      Address of next node\n";
    Node* temp = start;
    while (temp != nullptr) { // 🧐 Traverse and print each node
        cout << "\t" << temp << "\t" << temp->data << "\t" << temp->link << "\n";
        temp = temp->link;
    }
}

// Function to insert a node at the beginning
Node* insertFirst(Node* start, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 🧙 Create new node
    newNode->data = item;
    newNode->link = start; // Link new node to the old first node
    return newNode; // New node is now the start of the list
}

// Function to insert a node in the middle
Node* insertMiddle(Node* start, int item, int loc) {
    Node* temp = start;
    int i = 1;
    while (i < loc - 1 && temp != nullptr) { // 🧭 Traverse to the specified location
        temp = temp->link;
        i++;
    }
    if (temp != nullptr) { // 😅 Check if the location is valid
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = item;
        newNode->link = temp->link; // Insert node
        temp->link = newNode;
    } else {
        cout << "Location out of bounds! 🚨\n"; // 🚨 Location is invalid
    }
    return start;
}

// Function to insert a node at the end
Node* insertLast(Node* start, int item) {
    Node* temp = start;
    while (temp->link != nullptr) { // ⏳ Traverse to the end
        temp = temp->link;
    }
    Node* newNode = (Node*)malloc(sizeof(Node)); // 🧙 Create new node
    newNode->data = item;
    newNode->link = nullptr; // End of list
    temp->link = newNode; // Link old last node to new node
    return start;
}

// Function to create a random linked list
Node* createRandomList(int numNodes) {
    if (numNodes <= 0) {
        cout << "Number of nodes must be positive! 🚫\n";
        return nullptr;
    }

    srand(time(0)); // Seed the random number generator
    Node* start = nullptr;

    for (int i = 0; i < numNodes; ++i) {
        int randomData = rand() % 100; // Generate random data (0-99)
        start = create(start, randomData); // Add node to the list
    }

    cout << "Random list created with " << numNodes << " nodes! 🎲\n";
    return start;
}

// Main function
int main() {
    Node* start = nullptr; // 🏁 Initialize an empty list

    int choice, item, loc, numNodes;

    while (true) { // 🎩 The magic never stops!
        cout << "\nLinked List Menu:\n";
        cout << "1. Add node at end\n";
        cout << "2. Add node at beginning\n";
        cout << "3. Add node in the middle\n";
        cout << "4. Print list\n";
        cout << "5. Create a random list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to add at end: ";
                cin >> item;
                start = create(start, item);
                cout << "Node added at the end! 🎉\n";
                break;
            case 2:
                cout << "Enter data to add at beginning: ";
                cin >> item;
                start = insertFirst(start, item);
                cout << "Node added at the beginning! 🚀\n";
                break;
            case 3:
                cout << "Enter data to add in the middle: ";
                cin >> item;
                cout << "Enter position to insert at: ";
                cin >> loc;
                start = insertMiddle(start, item, loc);
                cout << "Node added in the middle! 🎯\n";
                break;
            case 4:
                cout << "Printing the linked list...\n";
                printList(start);
                break;
            case 5:
                cout << "Enter the number of nodes for the random list: ";
                cin >> numNodes;
                start = createRandomList(numNodes);
                break;
            case 6:
                cout << "Exiting... Have a great day! 🌟\n";
                return 0; // 👋 Goodbye!
            default:
                cout << "Invalid choice, try again! 😅\n";
                break;
        }
    }

    return 0;
}
