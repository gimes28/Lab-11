#include <iostream>
#include "Exception.h"
#include "Graph.h"
using namespace std;

int main() {
    
    Graph nums(5);

    try {
        for (int i = 0; i < 5; i++) {
            for (int j = 3; j < 5; ++j) {
                nums.AddEdge(i, j);
                cout << i << " " << j << " added" << endl;
            }
        }
    }
    catch (Exception e) {
        e.printError();
    }

    if (nums.HasEdge(3, 3)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    
    //cout << &nums.OutEdges(2) << endl;

    //cout << &nums.InEdges(4) << endl;

    //nums.PrintGraph();

    //nums.RemoveEdge(1, 2);
    int userChoice;
    int numVerts;
    bool quit = false;

    cout << "Enter the number of vertices: " << endl;
    cin >> numVerts;
    //Graph nums(numVerts);

    nums.AddEdge(1, 0);
    nums.AddEdge(2, 0);
    nums.AddEdge(3, 0);

    do {
        cout << "Press 1: Add an edge to graph" << endl;
        cout << "Press 2: Remove an edge to graph" << endl;
        cout << "Press 3: Find an edge in the graph" << endl;
        cout << "Press 4: Find the out edges of a set of vertices" << endl;
        cout << "Press 5: Find the in edges of a set of vertices" << endl;
        cout << "Press 6: Traverse list in Depth First Search" << endl;
        cout << "Press 7: Traverse list in Breadth First Search" << endl;
        cout << "Press 8: Display the graph" << endl;
        cout << "Press 9: Quit" << endl;

        cin >> userChoice;
        while (userChoice < 0 || userChoice > 9) {
            cout << "Invalid input, try again" << endl;
            cin >> userChoice;
        }

        if (userChoice == 1) {
            int num1, num2;
            cout << "Enter first number: " << endl;
            cin >> num1;
            cout << "Enter second number: " << endl;
            cin >> num2;
            try {
                nums.AddEdge(num1, num2);
            }
            catch (Exception e) {
                e.printError();
            }
            cout << "-- Successfully Added Edge --" << endl;
        }
        else if (userChoice == 2) {
            int num1, num2;
            cout << "Enter first number: " << endl;
            cin >> num1;
            cout << "Enter second number: " << endl;
            cin >> num2;
            try {
                nums.RemoveEdge(num1, num2);
            }
            catch (Exception e) {
                e.printError();
            }
            cout << "-- Successfully Removed Edge --" << endl;
        }
        else if (userChoice == 3) {
            int num1, num2;
            cout << "Enter first number: " << endl;
            cin >> num1;
            cout << "Enter second number: " << endl;
            cin >> num2;
            try {
                if (nums.HasEdge(num1, num2)) {
                    cout << num1 << " & " << num2 << " are edges" << endl;
                }
                else {
                    cout << num1 << " & " << num2 << " are not edges" << endl;
                }
            }
            catch (Exception e) {
                e.printError();
            }
        }
        else if (userChoice == 4) {
            int num1;
            cout << "Enter the vertex you want the out list of: " << endl;
            cin >> num1;
            Node* temp = nums.OutEdges(num1);
            while (temp != NULL) {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
        else if (userChoice == 5) {
            int num1;
            cout << "Enter the vertex you want the in list of: " << endl;
            cin >> num1;
            Node* temp = nums.InEdges(num1);
            while (temp != NULL) {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
        else if (userChoice == 6) {
            int num1;
            cout << "Enter the vertex you want to start from: " << endl;
            cin >> num1;
            nums.DFS(num1);
            cout << endl;
        }
        else if (userChoice == 7) {
            int num1;
            cout << "Enter the vertex you want to start from: " << endl;
            cin >> num1;
            nums.BFS(num1);
            cout << endl;
        }
        else if (userChoice == 8) {
            nums.PrintGraph();
            cout << endl;
        }
        else if (userChoice == 9) {
            nums.~Graph();
            quit = true;
        }
    } while (!quit);
}