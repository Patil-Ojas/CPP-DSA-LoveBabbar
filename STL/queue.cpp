
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> s;

    s.push("love");
    s.push("babbar");
    s.push("cpp");

    cout<<"first element: "<<s.front()<<endl;
    s.pop();
    cout<<"first element: "<<s.front()<<endl;
    cout<<"size of stack: "<<s.size()<<endl;
    cout<<"empty or nah: "<<s.empty()<<endl;

    return 0;
}