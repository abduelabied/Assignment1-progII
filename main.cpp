#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    char ListOfChar[8]= {'1','2','3','4','5','6','7','8'};
    char CharMatrix[4][4];
    char CharMatrix2[4][4];
    srand(time(0));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            CharMatrix[i][j]='*';
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            CharMatrix2[i][j]='*';
        }
    }
//Make the number is random
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<2; j++)
        {
            int m,n;
            m=rand()%4;
            n=rand()%4;
            while(CharMatrix[m][n]!='*')
            {
                m=rand()%4;
                n=rand()%4;
            }
            CharMatrix[m][n]=ListOfChar[i];
        }
    }
    cout<<"Welcome To Memory Matching Game\n";

//Display the board
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<CharMatrix2[i][j];
        }
        cout<<endl;
    }

//Begining of the game
for(int i=0; i<20; i++){
    for(int j=0; j<20; j++)
    while(CharMatrix2[i][j] =='*'){

    int c1,c2,r1,r2;
    cout<<"Plese choose your first card row and column"<<endl;

    cin>>r1>>c1;
    r1--;
    c1--;
    //check if the number of row and column more than 4
    //or less than 1
    while(r1 > 4 || r1 < 0 || c1 > 4 || c1 < 0){
        cout<<"Please Enter your row and column number from 1 to 4 \n";
        cin>>r1>>c1;
        r1--;
        c1--;

    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if((i==r1)&&(j==c1))
            {
                CharMatrix2[i][j]=CharMatrix[i][j];

            }
            cout<<CharMatrix2[i][j];


        }
        cout<<endl;
    }
    cout<<"Plese choose your sconed card row and column from 1 to 4"<<endl;
    cin>>r2>>c2;
    r2--;
    c2--;
    //check if the position of the second card like the position of the first card or no
    while(r2==r1 &&c2==c1){
        cout<<"Plese choose another card row and column"<<endl;
        cin>>r2>>c2;
        r2--;
        c2--;
    }


    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if((i==r2)&&(j==c2))
            {
                CharMatrix2[i][j]=CharMatrix[i][j];

            }
            cout<<CharMatrix2[i][j];


        }
        cout<<endl;

    }
    cout<<endl<<endl;

//check if the number of the first card equal the number of second card
//if the two numbers are same then uncover them
//if the two number are not the same then cover them again
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(CharMatrix2[r1][c1]==CharMatrix2[r2][c2])
        {
                CharMatrix2[r2][c2]=CharMatrix2[r1][c1];

        }
            else
            {
                CharMatrix2[r1][c1]='*';
                CharMatrix2[r2][c2]='*';

            }
        cout<<CharMatrix2[i][j];

    }
    cout<<endl;
    }
}
}
cout<<"Congratulation You Win";

    return 0;

}
