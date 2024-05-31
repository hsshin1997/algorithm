#include <iostream>

#define MAX 5

using namespace std;

class Queue {
    private:
        int arr[MAX]
        int front, rear; 
    
    public: 
        // Contrusctor
        Queue() {
            front = -1;
            rear = -1;
        }

        bool is_full() {
            if (front == 0 && rear == MAX - 1) {
                return true;
            } else {
                return false;
            }
        }

        bool is_empty() {
            if (front == -1) {
                return true;
            } else {
                return false; 
            }
        }

        void en_queue(int number) {
            if (is_full()) {
                cout << "Queue is full";
            } else {
                if (front == - 1) {
                    front = 0;
                }
                rear++;
                arr[rear] = element;
                cout << "Inserted: " << number << endl;
            }
        }

        int de_queue() {
            int number; 
            if (is_empty()) {
                cout << "Queue is empty"<< endl;
                return -1;
            } else {
                number = arr[front];
                if (front >= rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front++;
                }
            }
        }
}