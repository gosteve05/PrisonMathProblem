#include<iostream>
#include<vector>
using namespace std;

const int NUMBER_OF_PRISONERS = 4;

class Drawer
{
private:
    int contents;
    bool visited = false;
public:
    Drawer();
    Drawer(int content) : contents(content){}
    int getContents(){return contents;}
    bool isVisited(){return visited;}
    void setVisited(bool b){visited = b;}
};

vector<Drawer> init()
{
    vector<Drawer> drawers;
    for(int i = 0 ; i<NUMBER_OF_PRISONERS; i++)
    {
        drawers.push_back(i);
    } //assigns them
    for(int i = 0 ; i < NUMBER_OF_PRISONERS; i++)
    {
        swap(drawers[i], drawers[rand()%NUMBER_OF_PRISONERS]);
    } //randomized
    return drawers;
}

int getFirstNotFound(vector<Drawer> drawers)
{
    for(int i = 0 ; i < NUMBER_OF_PRISONERS ; i++)
        if(!drawers[i].isVisited())
            return i;
    exit(1); //error!
}


int count()
{
    vector<Drawer> drawers = init();

    int i;
    int drawersFound = 0;
    while(drawersFound < NUMBER_OF_PRISONERS/2)
    {
        int current = getFirstNotFound(drawers);
        for(i = 0 ; i < NUMBER_OF_PRISONERS/2 ; i++)
        {
            drawers[current].setVisited(true);
            current = drawers[current].getContents();
            drawersFound++;
            if(drawers[current].isVisited())
                break;
        }
        //if(drawersFound >= )
        if(i >= NUMBER_OF_PRISONERS/2)
            return 0;
    }
    return 1;
}
int main()
{
    double counter = 0;
    int trials = 1000000;
    int i;
    for(i = 0 ; i < trials ; i ++)
    {
        counter += count();
    }
    cout << "Count is: " << 100*counter/i << endl;
}