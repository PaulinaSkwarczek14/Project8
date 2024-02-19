#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

const int N = 10;

bool visited[N] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int A[N][N] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
    { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
};

struct slistEl
{
    slistEl* next;
    int data;
};

class queue
{
private:
    slistEl* head;
    slistEl* tail;

public:
    queue();
    ~queue();
    bool empty(void);
    int  front(void);
    void push(int v);
    void pop(void);
};


queue::queue()
{
    head = tail = NULL;
}

queue::~queue()
{
    while (head) pop();
}

bool queue::empty(void)
{
    return !head;
}


int queue::front(void)
{
    if (head) return head->data;
    else     return MAXINT;
}

void queue::push(int v)
{
    slistEl* p = new slistEl;
    p->next = NULL;
    p->data = v;
    if (tail) tail->next = p;
    else     head = p;
    tail = p;
}

void queue::pop(void)
{
    if (head)
    {
        slistEl* p = head;
        head = head->next;
        if (!head) tail = NULL;
        delete p;
    }
}

void DFS(int v)
{
    int currentNode = v;
    int graphSize = N;
    visited[currentNode] = true;
    std::cout << "Node ["<<currentNode<<"] visited\n";
    for (int i = 0; i < graphSize; i++) {
        if ((A[currentNode][i] == 1) && visited[i] == false) {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    queue bfsQueue;
    bfsQueue.push(v);
    visited[v] = true;
    int graphSize = N;
    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();
        std::cout << "BFS CurrentNode[" << currentNode << "]\n";
        for (int i = 0; i < graphSize; i++) {
            if ((A[currentNode][i] == 1) && visited[i] == false) {
                bfsQueue.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int i;

    setlocale(LC_CTYPE, "Polish");

    cout << "Przejscie grafu w glab - DFS(1):" << endl;
    DFS(1);
    cout << endl;

    for (i = 0; i < N; i++)
        visited[i] = false;

    cout << "Przejscie grafu wszerz - BFS(1):" << endl;
    BFS(1);
    cout << endl;

    return 0;
}

