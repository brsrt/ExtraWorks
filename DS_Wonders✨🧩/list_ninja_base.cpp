#include <iostream>  // For standard I/O
#include <cstdlib>   // For malloc

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
    cout << "\n Address of node    Data      Address of next node ";
    Node* temp = start;
    while (temp != nullptr) { // 🧐 Traverse and print each node
        cout << "\n\t" << temp << "\t" << temp->data << "\t" << temp->link;
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

// Main function
int main() {
    // 🦄 Imagine magic happening here
    return 0;
}

