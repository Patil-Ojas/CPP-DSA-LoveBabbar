
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(50);
    q.push(72);

    cout<<q.size()<<endl;

    q.pop();

    cout<<q.size()<<endl;

    cout<<q.empty()<<endl;
    cout<<!q.empty()<<endl;

    return 0;
}