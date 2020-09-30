#include <iostream>
#include <stdlib.h>

using namespace std;
void print(char a[3][3])
{   cout<<"________________\n";
    for(int i=2;i>=0;i--)
        {
            for(int j=0;j<3;j++)
                cout<<a[i][j]<<"|";
            cout<<endl;
        }
    cout<<"^^^^^^^^^^^^^^^^^\n";
}
int checkwinloose(char a[3][3],char user)
{
    if((a[0][0]==user&&a[0][1]==user&&a[0][2]==user)||(a[1][0]==user&&a[1][1]==user&&a[1][2]==user)||(a[2][0]==user&&a[2][1]==user&&a[2][2]==user)
             ||(a[0][0]==user&&a[1][0]==user&&a[2][0]==user)||(a[0][1]==user&&a[1][1]==user&&a[2][1]==user)||(a[0][2]==user&&a[1][2]==user&&a[2][2]==user)
             ||(a[0][0]==user&&a[1][1]==user&&a[2][2]==user)||(a[2][0]==user&&a[1][1]==user&&a[0][2]==user))
            {
                cout<<"You win";
                return 1;
            }
    return 0;
}
int main()
{
    char a[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    int x,y;
    cout<<"Welcome to the game :D \n";
    char user='X',game='O';
    while(1)
    {
        while(1)
        {
            cout<<"Select row_ ";cin>>x;x-=1;
            cout<<"Select column_ ";cin>>y;y-=1;
            if(a[x][y]=='-')
            {
                a[x][y]=user;
                break;
            }
            cout<<"INVALID MOVE! \n";
        }

        print(a);

        if(checkwinloose(a,user))
            break;

        while(1)
        {
            x=rand()%3;
            y=rand()%3;
            if(a[x][y]=='-')
            {
                a[x][y]=game;
                break;
            }
        }

        print(a);

        if(checkwinloose(a,game))
            break;

    }

    return 0;
}
