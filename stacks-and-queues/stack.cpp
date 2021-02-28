#include <iostream>
using namespace std;

void printSeperator() {
  cout << "***************************************************\n";
}

template <class T>
struct Node {
  T value;
  Node* previous;
};

template<class T>
class Stack {
  private:
    struct Node<T> *currentNode;

  public:
    Stack() {
      currentNode = NULL;
    }

    void pop() {
      if (currentNode == NULL) {
        cout << "Stack Empty\n";
        return;
      }

      cout << "Popped " << currentNode->value << " \n";
      currentNode = currentNode->previous;
    }

    void push(T value) {
      struct Node<T> *newNode = new Node<T>;
      newNode->value = value;
      newNode->previous = currentNode;
      currentNode = newNode;
    }

    void display() {
      if (!currentNode) {
        cout << "Stack is empty\n";
        return;
      }

      cout << "Current Stack values are\n";
      printSeperator();
      struct Node<T> *displayNode = currentNode;
      while (displayNode) {
        cout << displayNode->value << " ";
        displayNode = displayNode->previous;
      }
      cout << "\n";
    }
};

template<class T>
void showCommands(Stack<T> stack) {
  printSeperator();
  cout << "\n";
  cout << "Please enter the corresponding number for an action\n";
  printSeperator();
  cout << "1. Display Stack\n";
  cout << "2. Push Item\n";
  cout << "3. Pop Item\n";
  cout << "Any other value to exit\n";
  printSeperator();
  int action;
  cin >> action;
  printSeperator();
  switch(action) {
    case 1:
      stack.display();
      break;
    case 2:
      {
        T pushValue;
        cout << "Please enter value to push\n";
        cin >> pushValue;
        stack.push(pushValue);
      }
      break;
    case 3:
      stack.pop();
      break;
    default:
      cout << "Exiting\n";
      printSeperator();
      return;
  }
  showCommands(stack);
}

int main() {
  Stack<string> intStack;

  showCommands(intStack);
  return 0;
}
