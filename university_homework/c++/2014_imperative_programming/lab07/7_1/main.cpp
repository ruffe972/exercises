#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int nerdsNumber = 3;
//noSolution and noSaviour should be equal only to 0 because of the arrays initialization
const int noSolution = 0;
const int noSaviour = 0;


int findSolution(int saviour[], int solution[], int student)
{
    if (saviour[student] != noSaviour && solution[student] == noSolution)
        solution[student] = findSolution(saviour, solution, saviour[student]);
    return solution[student];
}


int main()
{
    cout << "The numeration starts from 1. Enter the amount of students: " << endl;
    int studentsNumber;
    cin >> studentsNumber;
    //int saviour[studentsNumber + 1];
    int* saviour = new int[studentsNumber + 1]();

    cout << endl << "Input format: student<' '>his saviour. An empty line stops the input." << endl;
    cin.get();
    while (cin.get() != '\n')
    {
        cin.unget();
        int student = 0;
        cin >> student;
        cin >> saviour[student];
        cin.get();
    }
    int* solution = new int[studentsNumber + 1]();

    cout << "Output format: student - test variant ";
    cout << "(or " << noSolution << " if the student is a dumbass)" << endl;
    for (int student = 1; student <= nerdsNumber; student++)
    {
        solution[student] = student;
        saviour[student] = student;
        cout << student << ' ' << student << endl;
    }
    for (int student = nerdsNumber + 1; student <= studentsNumber; student++)
    {
        findSolution(saviour, solution, student);
        cout << student << ' ' << solution[student] << endl;
    }
    cout << endl;
    delete[] saviour;
    delete[] solution;
    return 0;
}
