#include<bits/stdc++.h>
using namespace std;
char mat[3][3];
int r,c,k=1,t=0;
int w=-1;
void dec(){
    mat[r-1][c-1]='X';
    for(int i=0;i<3;++i){
        if(mat[0][i]==mat[1][i]&&mat[1][i]==mat[2][i]&&mat[1][i]=='X'){
            w=1;
            k=0;
        }
        else if(mat[i][0]==mat[i][1]&&mat[i][1]==mat[i][2]&&mat[i][1]=='X'){
            w=1;
            k=0;
        }
    }
    if(mat[0][0]==mat[1][1]&&mat[2][2]==mat[1][1]&&mat[1][1]=='X'){
        w=1;
        k=0;
    }
    else if(mat[0][2]==mat[1][1]&&mat[1][1]==mat[2][0]&&mat[1][1]=='X'){
        w=1;
        k=0;
    }
    if(t==5) return;
    int r1,c1;
    r1=rand()%3;
    c1=rand()%3;
    while(mat[r1][c1]=='X'||mat[r1][c1]=='O'){
        r1=rand()%3;
        c1=rand()%3;
    }
    mat[r1][c1]='O';
    for(int i=0;i<3;++i){
        if(mat[0][i]==mat[1][i]&&mat[1][i]==mat[2][i]&&mat[1][i]=='O'){
            w=0;
            k=0;
        }
        else if(mat[i][0]==mat[i][1]&&mat[i][1]==mat[i][2]&&mat[i][1]=='O'){
            w=0;
            k=0;
        }
    }
    if(mat[0][0]==mat[1][1]&&mat[2][2]==mat[1][1]&&mat[1][1]=='O'){
        w=0;
        k=0;
    }
    else if(mat[0][2]==mat[1][1]&&mat[1][1]==mat[2][0]&&mat[1][1]=='O'){
        w=0;
        k=0;
    }
}
void printb(){
    cout<<"-------\n";
    for(int i=0;i<3;++i){
        cout<<"|";
        for(int j=0;j<3;++j){
            cout<<mat[i][j]<<"|";
        }
        cout<<"\n-------\n";
    }
}
void game(){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j) mat[i][j]=' ';
    }
    printb();
    cout<<"Enter row and column where you want to place x : ";
    cin>>r>>c;
    system("cls");
    while(k==1&&t<6){
        ++t;
        dec();
        printb();
        if(k==0)break;
        cout<<"Enter row and column where you want to place x : ";
        cin>>r>>c;
        system("cls");
    }
    if(w==1)cout<<"You WIN!!!\n";
    else if(w==0) cout<<"YOU LOSE!!!\n";
    else cout<<"DRAW\n";
}
int main(){
    game();
    cout<<"Thanks for playing!";
}
