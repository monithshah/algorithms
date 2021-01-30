/*
  Given a set of N objects.
    * Union command:  connect two objects (Query Type 1)
    * Find/connected query:  is there a path connecting the two objects? (Query Type 2)
  Input Format :
    * First line contains two space seperated integers N and M where N represents the number of points and M represenets number of operations
    * Next M lines contain 3 space seperated integers Q, F and S. Where Q is the query type, F is the first point and S is the second point
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> paths;
vector<int> pathSizes;

int root(int point) {
  while (point != paths.at(point)) {
    paths.at(point) = paths.at(paths.at(point));
    point = paths.at(point);
  }
  return point;
}

void connect(int firstPoint, int secondPoint) {
  int firstPointRoot = root(firstPoint);
  int secondPointRoot = root(secondPoint);
  if (pathSizes[firstPointRoot] > pathSizes[secondPointRoot]) {
    paths.at(secondPointRoot) = firstPointRoot;
    pathSizes.at(firstPointRoot)++;
  } else {
    paths.at(firstPointRoot) = secondPointRoot;
    pathSizes.at(secondPointRoot)++;
  }
}

void checkIfConnected(int firstPoint, int secondPoint) {
  int firstPointRoot = root(firstPoint);
  int secondPointRoot = root(secondPoint);
  if (firstPointRoot == secondPointRoot) {
    cout << "True " << firstPoint << " and " << secondPoint << " have common root at " << firstPointRoot << "\n";
  } else {
    cout << "False " << firstPoint << " and " << secondPoint << " do not have any connections\n";
  }
}

void printPath() {
  cout << "The generated vector array was\n";
  for (int i = 0; i < paths.size(); i++) {
    cout << i << " ";
  }
  cout << "\n";
  for (auto path = paths.begin(); path != paths.end(); path++) {
    cout << *path << " ";
  }
  cout << "\n";
}

int main() {
  int treeSize, numberOfOperations;
  cin >> treeSize;
  cin >> numberOfOperations;
  for (int i = 0; i < treeSize; i++) {
    paths.push_back(i);
    pathSizes.push_back(1);
  }
  vector<vector<int>> operations;
  for (int i = 1; i <= numberOfOperations; i++) {
    vector<int> operation;
    int queryType, firstPoint, secondPoint;
    cin >> queryType;
    cin >> firstPoint;
    cin >> secondPoint;
    operation.push_back(queryType);
    operation.push_back(firstPoint);
    operation.push_back(secondPoint);
    operations.push_back(operation);
  }

  for (auto operationPointer = operations.begin(); operationPointer != operations.end(); operationPointer++) {
    vector<int> operation = *operationPointer;
    int queryType = operation.at(0);
    int firstPoint = operation.at(1);
    int secondPoint = operation.at(2);
    if (queryType == 1) {
      connect(firstPoint, secondPoint);
    } else {
      checkIfConnected(firstPoint, secondPoint);
      printPath();
    }
  }
}
