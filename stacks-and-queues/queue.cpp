#include <iostream>
using namespace std;

void printSeperator() {
  cout << "***************************************************\n";
}

template <class T>
struct Node {
  T value;
  Node* next;
};

template<class T>
class Queue {
  private:
    struct Node<T> *firstNode, *lastNode;

  public:
    Queue() {
      firstNode = NULL;
      lastNode = NULL;
    }

    void pop() {
      if (firstNode == NULL) {
        cout << "Queue Empty\n";
        return;
      }

      cout << "Popped " << firstNode->value << " \n";
      firstNode = firstNode->next;
    }

    void push(T value) {
      struct Node<T> *newNode = new Node<T>;
      newNode->value = value;
      if (firstNode == NULL) {
        firstNode = newNode;
      } else {
        lastNode->next = newNode;
      }
      lastNode = newNode;
    }

    void display() {
      if (firstNode == NULL) {
        cout << "Queue is empty\n";
        return;
      }

      cout << "Current Queue values are\n";
      printSeperator();
      struct Node<T> *displayNode = firstNode;
      while (displayNode) {
        cout << displayNode->value << " ";
        displayNode = displayNode->next;
      }
      cout << "\n";
    }
};

template<class T>
void showCommands(Queue<T> queue) {
  printSeperator();
  cout << "\n";
  cout << "Please enter the corresponding number for an action\n";
  printSeperator();
  cout << "1. Display Queue\n";
  cout << "2. Push Item\n";
  cout << "3. Pop Item\n";
  cout << "Any other value to exit\n";
  printSeperator();
  int action;
  cin >> action;
  printSeperator();
  switch(action) {
    case 1:
      queue.display();
      break;
    case 2:
      {
        T pushValue;
        cout << "Please enter value to push\n";
        cin >> pushValue;
        queue.push(pushValue);
      }
      break;
    case 3:
      queue.pop();
      break;
    default:
      cout << "Exiting\n";
      printSeperator();
      return;
  }
  showCommands(queue);
}

int main() {
  Queue<string> intQueue;

  showCommands(intQueue);
  return 0;
}
