/*
    ###=== Versiunea 0.1.2 ===###
    Devlogs:
        Update notes 0.0.01:
            -Added joc
        Update notes 0.0.02:
            -Added money storage for slots and roulette
        Update notes 0.0.03:
            -Added different accounts
        Update notes 0.0.04:
            -Added passwords for additional protection
        Update notes 0.0.05:
            -Added news and account and passwords correction
        Update notes 0.0.06:
            -Added colors and COOL animations
        Update notes 0.0.07:
            -Added COOL lobby with news and other activities coming soon
        Update notes 0.0.08:
            -Fixed a bug where you couldn't leave the game( not really a bug xD ;) :) )
        Update notes 0.0.09:
            -Now you have to write the color you want to bet on
        Update notes 0.0.10:
            -Fixed money for every account
        Update notes 0.0.11:
            -Fixed a bug where you could bet a negative sum of money
        Update notes 0.0.12:
            -Added graphics settings
        Update notes 0.0.13
            -Added HackerManMode in settings
        Update notes 0.0.14
            -Added Bitcoin Miner
        Update notes 0.015
            -Added dice spin game
        Update notes 0.0.16
            -Drastically improved the experience in the dice spin game(added animations and more)
        Update notes 0.0.17
            -Improved the login phase
        Update notes 0.0.18
            -Bug fixes and other improvements
        Update notes 0.0.19
            -Improved the Unreal Codbloks engine

        *--UPDATE 0.1.0--**
            -Optimized and improved the source
            -Added full (almost) login protection
            -The roulette is now *****
            -Finally 0.1.0 btw xD

        Update notes 0.1.1
            -Minor bufixes and improvements
        Update notes 0.1.2
            -updated roulette for more realistic movement
*/



#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

double speedhack = 1;
int a=4,b=3,c=2,d=1,e=0,f=32,g=31,h=30,i=29,p,j,m,randomj,randomj1,randomj2,randomj3,randomj4,joc=3,x,r,gameon=1,z[1001],k,total=0,ok,l,poz=0,ii,done=0,done2,usermoney[1001];
int grafici=2,hmm=0,randommoney;
int dicenr,thatdice,dice,actdice,currentmoney,iiiii,spinsleft;
int dicerow[51],dicespinned,altiiiii;
string cont,parola,contuser,parolauser,culoare;
///ws=GetLargestConsoleWindowSize();
///SetConsoleWindowInfo(GetLargestConsoleWindowSize());

int lobby();

inline void pause()
{
    cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string dummy;
    cout << "Press any key to continue . . .";
    getline(cin, dummy);
}

inline void fullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

inline void clrscr(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

inline bool login()
{
        ///SetConsoleWindowInfo(GetLargestConsoleWindowSize());
        ///system("mode 650");
        int login_again=0,login_done=0,login_poz=0,login_i=0;
        while(login_done==0)
        {
            cout<<"Username: ";
            cin>>contuser;
            ifstream qwerty("conturi.in");
            login_poz=0; ///total e citit intai!=nume cont
            while(qwerty>>cont)
                if(contuser==cont)
                {
                    login_done=1;
                    poz=login_poz;
                    cout<<"Found!";
                    break;
                }else login_poz++;
            qwerty.close();
            if(login_done==1)
                break;
            cout<<"Incorrect username!"<<'\n';
            Sleep(speedhack*1500);
            clrscr();
            cout<<"Try again? ( 1 - Yes ; 0 - Exit )"<<'\n';
            login_again=_getch();
            login_again-='0';
            clrscr();
            if(login_again==0)
                return 0;
        }
        clrscr();
        login_done=0;
        while(login_done==0)
        {
            cout<<"Username: "<<contuser<<'\n';
            cout<<"Password: ";
            parolauser=_getch();
            cout<<'*';
            login_i=0;
            while(parolauser[login_i]!=13)
            {
                login_i++;
                parolauser+=_getch();
                if(parolauser[login_i]!=13)
                    cout<<'*';
            }
            cout<<'\n';
            parolauser.resize(login_i);
            ifstream qwerty("parole.in");
            for(login_i=1;login_i<=poz;login_i++)
                qwerty>>parola;
            qwerty.close();
            if(parolauser==parola)
            {
                login_done=1;
                cout<<"We are signing you in. Please wait!";
                Sleep(speedhack*1000);
                break;
            }else cout<<"Incorrect password!"<<'\n';
            Sleep(speedhack*1500);
            clrscr();
            cout<<"Try again ( 1 ) , Change account ( 2 ) , Exit ( 3 ) ?"<<'\n';
            login_again=_getch();
            login_again-='0';
            clrscr();
            if(login_again==2)
                login();
            else if(login_again==3)
                return 0;
        }
        //-
        ifstream qwerty("money.in");
        for(login_i=1;login_i<=poz;login_i++)
            qwerty>>m;
        qwerty.close();
        //-
        return 1;
}

void sloturi()
{
    if(hmm==1)
        system("color 0A");
    else
        system("color 07");
    pause();
    if(m>0){
    clrscr();
    m=m-100000;
    /*ofstream money("money.in");
    money<<m;
    money.close();
    cout<<endl;*/
    for( i = 1; i < 30; ++i) {
    r = rand() % 9 + 1;
    cout<<"\n     ---------------\n";
    cout<<"    | S L O T U R I |\n";
    cout<<"     ---------------\n";
    cout<<' '<<"\n       ----------"<<endl;
    cout<<"      |"<<r<<' '<<'*'<<' '<<'*'<<' '<<'*'<<' '<<'*'<<' '<<"|"<<endl;
    cout<<' '<<"      ----------"<<' '<<endl<<endl;
    Sleep(speedhack*10);
    clrscr();
    }
    r = rand() % 9 + 1;
    cout<<"\n     ---------------\n";
    cout<<"    | S L O T U R I |\n";
    cout<<"     ---------------\n";
    cout<<' '<<"\n       ----------"<<endl;
    cout<<"      |"<<r<<' '<<'*'<<' '<<'*'<<' '<<'*'<<' '<<'*'<<' '<<"|"<<endl;
    cout<<' '<<"      ----------"<<' '<<endl<<endl;
    a = r;
    clrscr();
    for( i = 1; i < 30; ++i) {
        r = rand() % 9 + 1;
        cout<<"\n     ---------------\n";
        cout<<"    | S L O T U R I |\n";
        cout<<"     ---------------\n";
        cout<<' '<<"\n       ----------"<<endl;
        cout<<"      |"<<a<<' '<<r<<' '<<'*'<<' '<<'*'<<' '<<'*'<<' '<<"|"<<endl;
        cout<<' '<<"      ----------"<<' '<<endl<<endl;
        Sleep(speedhack*10);
        clrscr();
    }
    r = rand() % 9 + 1;
    cout<<"\n     ---------------\n";
    cout<<"    | S L O T U R I |\n";
    cout<<"     ---------------\n";
    cout<<' '<<"\n       ----------"<<endl;
    cout<<"      |"<<a<<' '<<r<<' '<<'*'<<' '<<'*'<<' '<<'*'<<' '<<"|"<<endl;
    cout<<' '<<"      ----------"<<' '<<endl<<endl;
    b = r;
    clrscr();
    for( i = 1; i < 30; ++i) {
        r = rand() % 9 + 1;
        cout<<"\n     ---------------\n";
        cout<<"    | S L O T U R I |\n";
        cout<<"     ---------------\n";
        cout<<' '<<"\n       ----------"<<endl;
        cout<<"      |"<<a<<' '<<b<<' '<<r<<' '<<'*'<<' '<<'*'<<' '<<"|"<<endl;
        cout<<' '<<"      ----------"<<' '<<endl<<endl;
        Sleep(speedhack*10);
        clrscr();
    }
    r = rand() % 9 + 1;
    cout<<"\n     ---------------\n";
    cout<<"    | S L O T U R I |\n";
    cout<<"     ---------------\n";
    cout<<' '<<"\n       ----------"<<endl;
    cout<<"      |"<<a<<' '<<b<<' '<<r<<' '<<'*'<<' '<<'*'<<' '<<"|"<<endl;
    cout<<' '<<"      ----------"<<' '<<endl<<endl;
    c = r;
    clrscr();
    for( i = 1; i < 30; ++i) {
        r = rand() % 9 + 1;
        cout<<"\n     ---------------\n";
        cout<<"    | S L O T U R I |\n";
        cout<<"     ---------------\n";
        cout<<' '<<"\n       ----------"<<endl;
        cout<<"      |"<<a<<' '<<b<<' '<<c<<' '<<r<<' '<<'*'<<' '<<"|"<<endl;
        cout<<' '<<"      ----------"<<' '<<endl<<endl;
        Sleep(speedhack*10);
        clrscr();
    }
    r = rand() % 9 + 1;
    cout<<"\n     ---------------\n";
    cout<<"    | S L O T U R I |\n";
    cout<<"     ---------------\n";
    cout<<' '<<"\n       ----------"<<endl;
    cout<<"      |"<<a<<' '<<b<<' '<<c<<' '<<r<<' '<<'*'<<' '<<"|"<<endl;
    cout<<' '<<"      ----------"<<' '<<endl<<endl;
    d = r;
    clrscr();
    for( i = 1; i < 30; ++i) {
        r = rand() % 9 + 1;
        cout<<"\n     ---------------\n";
        cout<<"    | S L O T U R I |\n";
        cout<<"     ---------------\n";
        cout<<' '<<"\n       ----------"<<endl;
        cout<<"      |"<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<r<<' '<<"|"<<endl;
        cout<<' '<<"      ----------"<<' '<<endl<<endl;
        Sleep(speedhack*10);
        clrscr();
    }
    r = rand() % 9 + 1;
    cout<<"\n     ---------------\n";
    cout<<"    | S L O T U R I |\n";
    cout<<"     ---------------\n";
    cout<<' '<<"\n       ----------"<<endl;
    cout<<"      |"<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<r<<' '<<"|"<<endl;
    cout<<' '<<"      ----------"<<' '<<endl<<endl;
        }else {
            cout<<"Not enough money! Do you wish to deposit more?"<<'\n';
                cin>>p;
                if(p == 1)
                {
                    cout<<"Introduce money"<<'\n';
                    cin>>p;
                    while (p < 100000)
                    {
                        cout<<"Minimum 100000 money!"<<endl;
                        cin>>p;
                    }
                    m=m+p;
                    cout<<"Money: "<<m<<'\n';
                }
        }

    if(a==b && a==c || a==b && a==d || a==b && a==r || a==c && a==d || a==c && a==r || a==d && a==r || b==c && b==d || b==d && b==r || c==d && c==r || b==c && b==r)
        m=m+200000;
    if(a==b && a==c && a==d || a==b && a==c && a==r || b==c && b==d && b==r || a==c && a==d && a==r || a==b && a==d && a==r)
        m=m+1000000;
    if(a==b && a==c && a==d && a==r)
        m=m+10000000;
    cout<<"Money: "<<m<<'\n';
    usermoney[poz]=m;
    ofstream money("money.in");
    for(j=1;j<=total;j++)
    {
        money<<usermoney[j]<<'\n';
    }
    money.close();
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"1-Continue ; 0-Back to lobby"<<endl;
    joc=_getch()-'0';
    while(joc!=1 && joc!=0)
    {
        cout<<"\nPlease enter a valid number: ";
        joc=_getch()-'0';
    }
    if(joc==0)
        lobby();
    else sloturi();
    clrscr();
}

void ruleta()
{
    int oc=1;
    if(oc)
    {
    a=4;
    b=3;
    c=2;
    d=1;
    e=0;
    f=32;
    g=31;
    h=30;
    i=29;
    oc=0;
    }
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    ///bani si pariu
    pause();
    clrscr();
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"              |          "<<'\n';
    cout<<" ------------------------------"<<'\n';
    cout<<" |";
    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
        cout<<" |"<<'\n';
        cout<<" ------------------------------"<<'\n';
        cout<<"              |         "<<'\n';
        if(hmm==1)
            SetConsoleTextAttribute(hConsole,10);
        else
            SetConsoleTextAttribute(hConsole,15);
        if(hmm)
            SetConsoleTextAttribute(hConsole,10);
        else
            SetConsoleTextAttribute(hConsole,15);
        cout<<"Money: "<<m<<'\n';
        cout<<"To bet on red, write red.\nTo bet on black, write black.\nTo bet on green write green. "<<'\n';
        cout<<"If you want to pass, write pass"<<'\n';

        cin>>culoare;
        cout<<'\n';
        while(culoare!="pass" && culoare!="red" && culoare!="blue" && culoare!="black" && culoare!="green")
        {
            cout<<"Please enter a valid color: ";
            cin>>culoare;
        }
        if (culoare!="pass")
        {
            p=-1;
            while(p<1)
            {
                cout<<"Bet money (x2 for red and black, and x14 for green)"<<'\n';
                cin>>p;
                if(p<0)
                    cout<<"Please bet a positive sum of money.\n";
                while(p>m)
                {
                    cout<<"Not enough money! Do you wish to deposit more?"<<'\n';
                    cin>>p;
                    if(p==1)
                    {
                        cout<<"Introduce money"<<'\n';
                        cin>>p;
                        m=m+p;
                        usermoney[poz]=m;
                        ofstream money("money.in");
                        for(j=1;j<=total;j++)
                        {
                            money<<usermoney[j]<<'\n';
                        }
                        money.close();
                        cout<<"Money: "<<m<<'\n';
                        cout<<"Bet money"<<'\n';
                        cin>>p;


                    }
                    else
                    {
                        cout<<"Bet a smaller sum"<<'\n';
                        cin>>p;
                        if(p<1)
                            cout<<"Please bet a positive sum of money.\n";
                    }
                }
            }
            m=m-p;
            ofstream money("money.in");
            money<<m;
            money.close();
        }

        Sleep(speedhack*1000);
        cout<<"3... ";
        Sleep(speedhack*1000);
        cout<<"2... ";
        Sleep(speedhack*1000);
        cout<<"1... ";
        Sleep(speedhack*1000);
        cout<<"DRAWING!";
        clrscr();
        cout<<" |"<<'\n';
        cout<<"           DRAWING!      "<<'\n';
        cout<<"               |          "<<'\n';
        cout<<"-----------------------------"<<'\n';
        cout<<"| ";
        if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
        cout<<" |"<<'\n';
        cout<<" -----------------------------"<<'\n';
        cout<<"               |         "<<'\n';
        ///bani si pariu
///corpul ruletei
randomj = rand() % 25 + 5;
randomj1 = rand() % 75 + 30;
randomj2 = rand() % 10  + 3;
randomj3 = rand() % 3 + 1;
randomj4 = rand() % 2 + 1;
for (j = 1; j <=randomj1 ; ++j) {
    i = i + 1;
    h = h + 1;
    g = g + 1;
    f = f + 1;
    e = e + 1;
    d = d + 1;
    c = c + 1;
    b = b + 1;
    a = a + 1;
    if (a / 33 == 1)
        a = 0;
    if (b / 33 == 1)
        b = 0;
    if (c / 33 == 1)
        c = 0;
    if (d / 33 == 1)
        d = 0;
    if (e / 33 == 1)
        e = 0;
    if (f / 33 == 1)
        f = 0;
    if (g / 33 == 1)
        g = 0;
    if (h / 33 == 1)
        h = 0;
    if (i / 33 == 1)
        i = 0;
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"            DRAWING!      "<<'\n';
    cout<<"               |          "<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<" |";
    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"|"<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<"               |         "<<'\n';
Sleep(speedhack*10);
clrscr();
}
for (j = 1; j <= randomj2 ; ++j) {
    i = i + 1;
    h = h + 1;
    g = g + 1;
    f = f + 1;
    e = e + 1;
    d = d + 1;
    c = c + 1;
    b = b + 1;
    a = a + 1;
    if (a / 33 == 1)
        a = 0;
    if (b / 33 == 1)
        b = 0;
    if (c / 33 == 1)
        c = 0;
    if (d / 33 == 1)
        d = 0;
    if (e / 33 == 1)
        e = 0;
    if (f / 33 == 1)
        f = 0;
    if (g / 33 == 1)
        g = 0;
    if (h / 33 == 1)
        h = 0;
    if (i / 33 == 1)
        i = 0;
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"            DRAWING!      "<<'\n';
    cout<<"               |          "<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<" |";
    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"|"<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<"               |         "<<'\n';
    Sleep(speedhack*50);
    clrscr();
    }
       for (j = 1; j <= randomj3 ; ++j) {
    i = i + 1;
    h = h + 1;
    g = g + 1;
    f = f + 1;
    e = e + 1;
    d = d + 1;
    c = c + 1;
    b = b + 1;
    a = a + 1;
    if (a / 33 == 1)
        a = 0;
    if (b / 33 == 1)
        b = 0;
    if (c / 33 == 1)
        c = 0;
    if (d / 33 == 1)
        d = 0;
    if (e / 33 == 1)
        e = 0;
    if (f / 33 == 1)
        f = 0;
    if (g / 33 == 1)
        g = 0;
    if (h / 33 == 1)
        h = 0;
    if (i / 33 == 1)
        i = 0;
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"            DRAWING!      "<<'\n';
    cout<<"               |          "<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<" |";
    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"|"<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<"               |         "<<'\n';
    Sleep(speedhack*100);
    clrscr();
    }
       for (j = 1; j <= randomj ; ++j) {
    i = i + 1;
    h = h + 1;
    g = g + 1;
    f = f + 1;
    e = e + 1;
    d = d + 1;
    c = c + 1;
    b = b + 1;
    a = a + 1;
    if (a / 33 == 1)
        a = 0;
    if (b / 33 == 1)
        b = 0;
    if (c / 33 == 1)
        c = 0;
    if (d / 33 == 1)
        d = 0;
    if (e / 33 == 1)
        e = 0;
    if (f / 33 == 1)
        f = 0;
    if (g / 33 == 1)
        g = 0;
    if (h / 33 == 1)
        h = 0;
    if (i / 33 == 1)
        i = 0;
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"            DRAWING!      "<<'\n';
    cout<<"               |          "<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<" |";

    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"|"<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<"               |         "<<'\n';
    Sleep(speedhack*250);
    clrscr();
    }
    for (j = 1; j <=  randomj4 ; ++j) {
    i = i + 1;
    h = h + 1;
    g = g + 1;
    f = f + 1;
    e = e + 1;
    d = d + 1;
    c = c + 1;
    b = b + 1;
    a = a + 1;
    if (a / 33 == 1)
        a = 0;
    if (b / 33 == 1)
        b = 0;
    if (c / 33 == 1)
        c = 0;
    if (d / 33 == 1)
        d = 0;
    if (e / 33 == 1)
        e = 0;
    if (f / 33 == 1)
        f = 0;
    if (g / 33 == 1)
        g = 0;
    if (h / 33 == 1)
        h = 0;
    if (i / 33 == 1)
        i = 0;
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"            DRAWING!      "<<'\n';
    cout<<"               |          "<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<" |";
    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"|"<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<"               |         "<<'\n';
    Sleep(speedhack*500);
    clrscr();
    }
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    cout<<"            DRAWING!      "<<'\n';
    cout<<"               |          "<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<" |";
    if(i%2==0 && i!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(i%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if(h%2==0 && h!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(h%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if(g%2==0 && g!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(g%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if(f%2==0 && f!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(f%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if(e%2==0 && e!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(e%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if(d%2==0 && d!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(d%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if(c%2==0 && c!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(c%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if(b%2==0 && b!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(b%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if(a%2==0 && a!=0)
        SetConsoleTextAttribute(hConsole,9);
    else if(a%2==1)
        SetConsoleTextAttribute(hConsole,12);
    else SetConsoleTextAttribute(hConsole,10);
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';
    if(e==0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,10);
    if(e%2==1 && grafici!=1)
        SetConsoleTextAttribute(hConsole,12);
    if(e%2==0 && e!=0 && grafici!=1)
        SetConsoleTextAttribute(hConsole,9);
    /*if (i < 10)
        cout<<' '<<i<<' ';
    else
        cout<<i<<' ';
    if (h < 10)
        cout<<' '<<h<<' ';
    else
        cout<<h<<' ';
    if (g < 10)
        cout<<' '<<g<<' ';
    else
        cout<<g<<' ';
    if (f < 10)
        cout<<' '<<f<<' ';
    else
        cout<<f<<' ';
    if (e < 10)
        cout<<' '<<e<<' ';
    else
        cout<<e<<' ';
    if (d < 10)
        cout<<' '<<d<<' ';
    else
        cout<<d<<' ';
    if (c < 10)
        cout<<' '<<c<<' ';
    else
        cout<<c<<' ';
    if (b < 10)
        cout<<' '<<b<<' ';
    else
        cout<<b<<' ';
    if (a < 10)
        cout<<' '<<a<<' ';
    else
        cout<<a<<' ';*/
    cout<<"|"<<'\n';
    cout<<" -----------------------------"<<'\n';
    cout<<"               |         "<<'\n';
        ///corpul ruletei
        ///system ( "color 09" );      /// 09 - albastru 0A - verde 0C- rosu
        /**  if(e==0 && grafici!=1)
                system("color 0A");
            if(e%2==1 && grafici!=1)
                system("color 0C");
            if(e%2==0 && e!=0 && grafici!=1)
                system("color 09");
        **/
        if(culoare!="pass")
        {
            int rig=rand()%5;
            ///e = ( e!=0 && culoare == "green" ? 33 : e);
            if(culoare=="red" && e%2==1)
            {
                if(rig!=0)
                {m=m+2*p;
                cout<<"Ai castigat "<<2*p<<" bani!!\n";}
                else
                {
                    clrscr();
                    i = i + 1;
                    h = h + 1;
                    g = g + 1;
                    f = f + 1;
                    e = e + 1;
                    d = d + 1;
                    c = c + 1;
                    b = b + 1;
                    a = a + 1;
                    if (a / 33 == 1)
                        a = 0;
                    if (b / 33 == 1)
                        b = 0;
                    if (c / 33 == 1)
                        c = 0;
                    if (d / 33 == 1)
                        d = 0;
                    if (e / 33 == 1)
                        e = 0;
                    if (f / 33 == 1)
                        f = 0;
                    if (g / 33 == 1)
                        g = 0;
                    if (h / 33 == 1)
                        h = 0;
                    if (i / 33 == 1)
                        i = 0;
                    if(e==0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,10);
                    if(e%2==1 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,12);
                    if(e%2==0 && e!=0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,9);
                    cout<<"            DRAWING!      "<<'\n';
                    cout<<"               |          "<<'\n';
                    cout<<" -----------------------------"<<'\n';
                    cout<<" |";
                    if(i%2==0 && i!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(i%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (i < 10)
                        cout<<' '<<i<<' ';
                    else
                        cout<<i<<' ';
                    if(h%2==0 && h!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(h%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (h < 10)
                        cout<<' '<<h<<' ';
                    else
                        cout<<h<<' ';
                    if(g%2==0 && g!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(g%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (g < 10)
                        cout<<' '<<g<<' ';
                    else
                        cout<<g<<' ';
                    if(f%2==0 && f!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(f%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (f < 10)
                        cout<<' '<<f<<' ';
                    else
                        cout<<f<<' ';
                    if(e%2==0 && e!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(e%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (e < 10)
                        cout<<' '<<e<<' ';
                    else
                        cout<<e<<' ';
                    if(d%2==0 && d!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(d%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (d < 10)
                        cout<<' '<<d<<' ';
                    else
                        cout<<d<<' ';
                    if(c%2==0 && c!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(c%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (c < 10)
                        cout<<' '<<c<<' ';
                    else
                        cout<<c<<' ';
                    if(b%2==0 && b!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(b%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (b < 10)
                        cout<<' '<<b<<' ';
                    else
                        cout<<b<<' ';
                    if(a%2==0 && a!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(a%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (a < 10)
                        cout<<' '<<a<<' ';
                    else
                        cout<<a<<' ';
                    if(e==0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,10);
                    if(e%2==1 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,12);
                    if(e%2==0 && e!=0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,9);
                    cout<<"|"<<'\n';
                    cout<<" -----------------------------"<<'\n';
                    cout<<"               |         "<<'\n';
                    Sleep(speedhack*500);
                }
            }
            if((culoare=="blue" || culoare=="black") && e%2==0 && e!=0)
            {
                if(rig!=0)
                {m=m+2*p;
                cout<<"Ai castigat "<<2*p<<" bani!!\n";}
                else
                {
                    clrscr();
                    i = i + 1;
                    h = h + 1;
                    g = g + 1;
                    f = f + 1;
                    e = e + 1;
                    d = d + 1;
                    c = c + 1;
                    b = b + 1;
                    a = a + 1;
                    if (a / 33 == 1)
                        a = 0;
                    if (b / 33 == 1)
                        b = 0;
                    if (c / 33 == 1)
                        c = 0;
                    if (d / 33 == 1)
                        d = 0;
                    if (e / 33 == 1)
                        e = 0;
                    if (f / 33 == 1)
                        f = 0;
                    if (g / 33 == 1)
                        g = 0;
                    if (h / 33 == 1)
                        h = 0;
                    if (i / 33 == 1)
                        i = 0;
                    if(e==0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,10);
                    if(e%2==1 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,12);
                    if(e%2==0 && e!=0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,9);
                    cout<<"            DRAWING!      "<<'\n';
                    cout<<"               |          "<<'\n';
                    cout<<" -----------------------------"<<'\n';
                    cout<<" |";
                    if(i%2==0 && i!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(i%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (i < 10)
                        cout<<' '<<i<<' ';
                    else
                        cout<<i<<' ';
                    if(h%2==0 && h!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(h%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (h < 10)
                        cout<<' '<<h<<' ';
                    else
                        cout<<h<<' ';
                    if(g%2==0 && g!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(g%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (g < 10)
                        cout<<' '<<g<<' ';
                    else
                        cout<<g<<' ';
                    if(f%2==0 && f!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(f%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (f < 10)
                        cout<<' '<<f<<' ';
                    else
                        cout<<f<<' ';
                    if(e%2==0 && e!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(e%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (e < 10)
                        cout<<' '<<e<<' ';
                    else
                        cout<<e<<' ';
                    if(d%2==0 && d!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(d%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (d < 10)
                        cout<<' '<<d<<' ';
                    else
                        cout<<d<<' ';
                    if(c%2==0 && c!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(c%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (c < 10)
                        cout<<' '<<c<<' ';
                    else
                        cout<<c<<' ';
                    if(b%2==0 && b!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(b%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (b < 10)
                        cout<<' '<<b<<' ';
                    else
                        cout<<b<<' ';
                    if(a%2==0 && a!=0)
                        SetConsoleTextAttribute(hConsole,9);
                    else if(a%2==1)
                        SetConsoleTextAttribute(hConsole,12);
                    else SetConsoleTextAttribute(hConsole,10);
                    if (a < 10)
                        cout<<' '<<a<<' ';
                    else
                        cout<<a<<' ';
                    if(e==0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,10);
                    if(e%2==1 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,12);
                    if(e%2==0 && e!=0 && grafici!=1)
                        SetConsoleTextAttribute(hConsole,9);
                    cout<<"|"<<'\n';
                    cout<<" -----------------------------"<<'\n';
                    cout<<"               |         "<<'\n';
                    Sleep(speedhack*500);

                }
            }
            if(culoare=="green" && e==0)
            {
                m=m+14*p;
                cout<<"JACKPOT!!! Ai castigat "<<14*p<<" bani!!\n";
                for(i=1; i<10; i++)
                {
                    system("color 0C");
                    Sleep(speedhack*100);
                    system("color 0A");
                    Sleep(speedhack*100);
                    system("color 09");
                    Sleep(speedhack*100);
                }
                system("color 0A");
            }
        }
        cout<<"\nMoney: "<<m;
        usermoney[poz]=m;
        ofstream money("money.in");
        for(j=1;j<=total;j++)
        {
            money<<usermoney[j]<<'\n';
        }
        money.close();
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"1-Continue ; 0-Back to lobby"<<endl;
        joc=_getch()-'0';
        while(joc!=1 && joc!=0)
        {
            cout<<'\n'<<"Please enter a valid number: ";
            joc=_getch()-'0';
        }
        if(joc==0)
            lobby();
        else ruleta();
        if(hmm)
        system("color 0A");
        else
        system("color 07");
        clrscr();
}
void bitcoin()
{
    clrscr();
    if(hmm==0)
        system("color 07");
    else
        system("color 0A");
    cout<<"-----------------\n";
    cout<<"| Bitcoin Miner |\n";
    cout<<"-----------------\n\n";
    cout<<"You have "<<m<<" Money\n";
    cout<<"1-Farm Money ; 0-Back to lobby\n";
    joc=_getch()-'0';
    while(joc!=1 && joc!=0)
    {
        cout<<'\n'<<"Please enter a valid number: ";
        joc=_getch()-'0';
    }
    if(joc==0)
        lobby();
    else
    {
        for(j=1;j<=3;j++)
        {

            clrscr();
            cout<<'\n';
            cout<<"       /---\\             \n";
            cout<<"      /  |  \\            \n";
            cout<<"         |      _______   \n";
            cout<<"         |     |   $   |  \n";
            cout<<"         |     |BITCOIN|  \n";
            cout<<"         |     |_______|  \n";
            cout<<"|---|\n";
            Sleep(speedhack*400);
            clrscr();
            cout<<'\n';
            cout<<"         /___\\           \n";
            cout<<"        / /   \\          \n";
            cout<<"         /      _______   \n";
            cout<<"        /      |   $   |  \n";
            cout<<"       /       |BITCOIN|  \n";
            cout<<"      /        |_______|  \n";
            cout<<"|$--|\n";
            Sleep(speedhack*400);
            clrscr();
            cout<<'\n';
            cout<<"        _____             \n";
            cout<<"           / \\           \n";
            cout<<"          /   \\ _______   \n";
            cout<<"         /     |   $   |  \n";
            cout<<"        /      |BITCOIN|  \n";
            cout<<"       /       |_______|  \n";
            cout<<"|$$-|\n";
            Sleep(speedhack*400);
            clrscr();
            cout<<'\n';
            cout<<"        _____             \n";
            cout<<"           / \\           \n";
            cout<<"          /   \\    ___   \n";
            cout<<"         /        _|   |  \n";
            cout<<"        /       _/TCOIN|  \n";
            cout<<"       /       |_______|  \n";
            cout<<"|$$$|\n";
            Sleep(speedhack*400);
            clrscr();
        }
        randommoney=rand()%11+5;
        cout<<"+"<<randommoney<<'!';
        Sleep(speedhack*400);
        m+=randommoney;
        usermoney[poz]=m;
        ofstream money("money.in");
        for(j=1;j<=total;j++)
        {
            money<<usermoney[j]<<'\n';
        }
        money.close();
        bitcoin();
    }
}
//----------------------------------------------------------------------------------------------------
void zarurile()
{
    int zeta=0,randomdice=0;
    done=0;
    done2=0;
    clrscr();
    dicespinned=0;
    currentmoney=0;
    while(done==0)
    {
        cout<<"Number of dices: ";
        cin>>dicenr;
        if(dicenr<=50 && dicenr>0)
            done=1;
        else if(dicenr>50)
            {
                clrscr();
                cout<<"Maximum 50 spins!";
                Sleep(speedhack*1000);
                clrscr();
            }
        else
            {
                clrscr();
                cout<<"You trying to get me?";
                Sleep(speedhack*1000);
                clrscr();
            }
    }
    while(done2==0)
    {
        cout<<endl<<"Dice dots: ";
        cin>>thatdice;
        if(thatdice<=6 && thatdice>0)
            done2=1;
        else if(thatdice>6)
            {
                clrscr();
                cout<<"Man...";
                Sleep(speedhack*1000);
                clrscr();
            }
        else
            {
                clrscr();
                cout<<"Really?";
                Sleep(speedhack*1000);
                clrscr();
            }
    }
    clrscr();
    spinsleft=dicenr;
    dicerow[0]=-1;
    for(dice=1;dice<=dicenr;dice++)
    {
        randomdice=rand()%7+4;
        cout<<"Spins left: "<<spinsleft<<endl;
        cout<<"Recent: ";
        for(altiiiii=1;altiiiii<=dicespinned;altiiiii++)
            cout<<dicerow[altiiiii]<<' ';
        cout<<endl<<endl;
        switch(actdice)
        {
            case 1: cout<<"                   -------     "<<endl;
                    cout<<"                   |     |     "<<endl;
                    cout<<"                   |  .  |     "<<endl;
                    cout<<"                   |     |     "<<endl;
                    cout<<"                   -------     "<<endl;
                    break;
            case 2: cout<<"                   -------     "<<endl;
                    cout<<"                   |     |     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   |     |     "<<endl;
                    cout<<"                   -------     "<<endl;
                    break;
            case 3: cout<<"                   -------     "<<endl;
                    cout<<"                   |.    |     "<<endl;
                    cout<<"                   |  .  |     "<<endl;
                    cout<<"                   |    .|     "<<endl;
                    cout<<"                   -------     "<<endl;
                    break;
            case 4: cout<<"                   -------     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   |     |     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   -------     "<<endl;
                    break;
            case 5: cout<<"                   -------     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   |  .  |     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   -------     "<<endl;
                    break;
            case 6: cout<<"                   -------     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   |.   .|     "<<endl;
                    cout<<"                   -------     "<<endl;
                    break;
        }
        Sleep(speedhack*1000);
        for(iiiii=1;iiiii<=randomdice;iiiii++)
        {
            zeta=0;
            while(zeta<=9)
            {
                cout<<"Spins left: "<<spinsleft<<endl;
                cout<<"Recent: ";
                for(altiiiii=1;altiiiii<=dicespinned;altiiiii++)
                    cout<<dicerow[altiiiii]<<' ';
                cout<<endl<<endl;
                switch(zeta%5)
                {
                    case 0:     cout<<"                   --------     "<<endl;
                                cout<<"                   |      |     "<<endl;
                                cout<<"                   |      |     "<<endl;
                                cout<<"                   |      |     "<<endl;
                                cout<<"                   --------     "<<endl;
                                break;
                    case 1:     cout<<"           _______           "<<endl;
                                cout<<"          |\\      \\        "<<endl;
                                cout<<"          | \\______\\       "<<endl;
                                cout<<"          | |      |         "<<endl;
                                cout<<"          | |      |         "<<endl;
                                cout<<"          \\ |      |        "<<endl;
                                cout<<"           \\--------        "<<endl;
                                break;
                    case 2:     cout<<"                  ________       "<<endl;
                                cout<<"                 /|      |       "<<endl;
                                cout<<"                / |      |       "<<endl;
                                cout<<"                | |      |       "<<endl;
                                cout<<"                | /------/       "<<endl;
                                cout<<"                |/______/        "<<endl;
                                break;
                    case 3:     cout<<"                          _______      "<<endl;
                                cout<<"                         /      /|     "<<endl;
                                cout<<"                        /_____ / |     "<<endl;
                                cout<<"                       |      |  |     "<<endl;
                                cout<<"                       |      |  |     "<<endl;
                                cout<<"                       |      | /      "<<endl;
                                cout<<"                       --------/       "<<endl;
                                break;
                    case 4:     cout<<"               ________           "<<endl;
                                cout<<"               |      |\\         "<<endl;
                                cout<<"               |      | \\        "<<endl;
                                cout<<"               |      | |         "<<endl;
                                cout<<"               \\------\\ |       "<<endl;
                                cout<<"                \\______\\|       "<<endl;
                                break;
                }
                zeta++;
                if(iiiii==randomdice-1 || iiiii==randomdice)
                    Sleep(speedhack*30);
                clrscr();
            }
        }
        spinsleft--;
        cout<<"Spins left: "<<spinsleft<<endl;
        cout<<"Recent: ";
        for(iiiii=1;iiiii<=dicespinned;iiiii++)
            cout<<dicerow[iiiii]<<' ';
        cout<<endl;
        actdice=rand() % 6 + 1;
        switch(actdice)
        {
            case 1: cout<<"           _______           "<<endl;
                    cout<<"          |\\      \\        "<<endl;
                    cout<<"          | \\______\\       "<<endl;
                    cout<<"          | |      |         "<<endl;
                    cout<<"          | |   .  |         "<<endl;
                    cout<<"          \\ |      |        "<<endl;
                    cout<<"           \\--------        "<<endl;
                    break;
            case 2: cout<<"           _______           "<<endl;
                    cout<<"          |\\      \\        "<<endl;
                    cout<<"          | \\______\\       "<<endl;
                    cout<<"          | |      |         "<<endl;
                    cout<<"          | |.    .|         "<<endl;
                    cout<<"          \\ |      |        "<<endl;
                    cout<<"           \\--------        "<<endl;
                    break;
            case 3: cout<<"           _______           "<<endl;
                    cout<<"          |\\      \\        "<<endl;
                    cout<<"          | \\______\\       "<<endl;
                    cout<<"          | |.     |         "<<endl;
                    cout<<"          | |   .  |         "<<endl;
                    cout<<"          \\ |     .|        "<<endl;
                    cout<<"           \\--------        "<<endl;
                    break;
            case 4: cout<<"           _______           "<<endl;
                    cout<<"          |\\      \\        "<<endl;
                    cout<<"          | \\______\\       "<<endl;
                    cout<<"          | |.    .|         "<<endl;
                    cout<<"          | |      |         "<<endl;
                    cout<<"          \\ |.    .|        "<<endl;
                    cout<<"           \\--------        "<<endl;
                    break;
            case 5: cout<<"           _______           "<<endl;
                    cout<<"          |\\      \\        "<<endl;
                    cout<<"          | \\______\\       "<<endl;
                    cout<<"          | |.    .|         "<<endl;
                    cout<<"          | |   .  |         "<<endl;
                    cout<<"          \\ |.    .|        "<<endl;
                    cout<<"           \\--------        "<<endl;
                    break;
            case 6: cout<<"           _______           "<<endl;
                    cout<<"          |\\      \\        "<<endl;
                    cout<<"          | \\______\\       "<<endl;
                    cout<<"          | |.    .|         "<<endl;
                    cout<<"          | |.    .|         "<<endl;
                    cout<<"          \\ |.    .|        "<<endl;
                    cout<<"           \\--------        "<<endl;
                    break;
        }
        dicespinned++;
        dicerow[dicespinned]=actdice;
        if(actdice==thatdice)
            currentmoney=currentmoney+300;
        else
            currentmoney=currentmoney-100;
        if(actdice==dicerow[dicespinned-1] && actdice==thatdice)
            currentmoney=currentmoney+1000;
        else if(actdice==dicerow[dicespinned-1])
            currentmoney=currentmoney+50;
        Sleep(speedhack*2500);
        clrscr();
    }
    cout<<"Dices: ";
    for(iiiii=1;iiiii<=dicenr;iiiii++)
        cout<<dicerow[iiiii]<<' ';
    cout<<endl;
    cout<<"Profit :"<<currentmoney<<endl;
    //--
    m=m+currentmoney;
    usermoney[poz]=m;
    ofstream money("money.in");
    for(j=1;j<=total;j++)
    {
        money<<usermoney[j]<<'\n';
    }
    money.close();
    cout<<total;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"1-Continue ; 0-Back to lobby"<<endl;
    joc=_getch()-'0';
    while(joc!=1 && joc!=0)
    {
        cout<<'\n'<<"Please enter a valid number: ";
        joc=_getch()-'0';
    }
    if(joc==0)
        lobby();
    else zarurile();
}

void blackjack()
{
    clrscr();
    int bjstart=2,bjsum,colour;
    string bjcards[19][11];
    bjcards[1][1]=" ---------------";
    bjcards[1][2]=" |             |";
    bjcards[1][3]=" |    _   _    |";
    bjcards[1][4]=" |   / \\ / \\   |";
    bjcards[1][5]=" |   |  v  |   |";
    bjcards[1][6]=" |    \\   /    |";
    bjcards[1][7]=" |      v      |";
    bjcards[1][8]=" |             |";
    bjcards[1][9]=" |             |";
    bjcards[1][10]=" ---------------";
    bjcards[2][1]=" ---------------";
    bjcards[2][2]=" |             |";
    bjcards[2][3]=" |    ----     |";
    bjcards[2][4]=" |   /    \\    |";
    bjcards[2][5]=" |        |    |";
    bjcards[2][6]=" |     __/     |";
    bjcards[2][7]=" |    /        |";
    bjcards[2][8]=" |   |_____    |";
    bjcards[2][9]=" |             |";
    bjcards[2][10]=" ---------------";
    bjcards[3][1]=" ---------------";
    bjcards[3][2]=" |             |";
    bjcards[3][3]=" |    ----     |";
    bjcards[3][4]=" |        |    |";
    bjcards[3][5]=" |     ___|    |";
    bjcards[3][6]=" |        |    |";
    bjcards[3][7]=" |        |    |";
    bjcards[3][8]=" |    ----     |";
    bjcards[3][9]=" |             |";
    bjcards[3][10]=" ---------------";
    bjcards[4][1]=" ---------------";
    bjcards[4][2]=" |      __     |";
    bjcards[4][3]=" |     /  |    |";
    bjcards[4][4]=" |    /   |    |";
    bjcards[4][5]=" |   /    |    |";
    bjcards[4][6]=" |  |_____|    |";
    bjcards[4][7]=" |        |    |";
    bjcards[4][8]=" |        |    |";
    bjcards[4][9]=" |             |";
    bjcards[4][10]=" ---------------";
    bjcards[5][1]=" ---------------";
    bjcards[5][2]=" |    ______   |";
    bjcards[5][3]=" |   |         |";
    bjcards[5][4]=" |   |         |";
    bjcards[5][5]=" |   |_____    |";
    bjcards[5][6]=" |         \\   |";
    bjcards[5][7]=" |         |   |";
    bjcards[5][8]=" |   ______/   |";
    bjcards[5][9]=" |             |";
    bjcards[5][10]=" ---------------";
    bjcards[6][1]=" ---------------";
    bjcards[6][2]=" |    _____    |";
    bjcards[6][3]=" |   /         |";
    bjcards[6][4]=" |   |         |";
    bjcards[6][5]=" |   |_____    |";
    bjcards[6][6]=" |   |     \\   |";
    bjcards[6][7]=" |   |     |   |";
    bjcards[6][8]=" |   \\_____|   |";
    bjcards[6][9]=" |             |";
    bjcards[6][10]=" ---------------";
    bjcards[7][1]=" ---------------";
    bjcards[7][2]=" |    ______   |";
    bjcards[7][3]=" |         /   |";
    bjcards[7][4]=" |        /    |";
    bjcards[7][5]=" |     __/_    |";
    bjcards[7][6]=" |      /      |";
    bjcards[7][7]=" |     /       |";
    bjcards[7][8]=" |    /        |";
    bjcards[7][9]=" |             |";
    bjcards[7][10]=" ---------------";
    bjcards[8][1]=" ---------------";
    bjcards[8][2]=" |    _____    |";
    bjcards[8][3]=" |   /     \\   |";
    bjcards[8][4]=" |   |     |   |";
    bjcards[8][5]=" |   \\_____/   |";
    bjcards[8][6]=" |   /     \\   |";
    bjcards[8][7]=" |   |     |   |";
    bjcards[8][8]=" |   \\_____/   |";
    bjcards[8][9]=" |             |";
    bjcards[8][10]=" ---------------";
    bjcards[9][1]=" ---------------";
    bjcards[9][2]=" |    _____    |";
    bjcards[9][3]=" |   /     \\   |";
    bjcards[9][4]=" |   |     |   |";
    bjcards[9][5]=" |   \\_____|   |";
    bjcards[9][6]=" |         |   |";
    bjcards[9][7]=" |         |   |";
    bjcards[9][8]=" |    _____/   |";
    bjcards[9][9]=" |             |";
    bjcards[9][10]=" ---------------";
    bjcards[10][1]=" ---------------";
    bjcards[10][2]=" |       ___   |";
    bjcards[10][3]=" |  /|  /   \\  |";
    bjcards[10][4]=" |   |  |   |  |";
    bjcards[10][5]=" |   |  |   |  |";
    bjcards[10][6]=" |   |  |   |  |";
    bjcards[10][7]=" |   |  |   |  |";
    bjcards[10][8]=" |   |  \\___/  |";
    bjcards[10][9]=" |             |";
    bjcards[10][10]=" ---------------";
    bjcards[10][1]=" ---------------";
    bjcards[11][2]=" |   ________  |";
    bjcards[11][3]=" |        |    |";
    bjcards[11][4]=" |        |    |";
    bjcards[11][5]=" |        |    |";
    bjcards[11][6]=" |        |    |";
    bjcards[11][7]=" |   |    |    |";
    bjcards[11][8]=" |   \\____/    |";
    bjcards[11][9]=" |             |";
    bjcards[11][10]=" ---------------";
    bjcards[12][1]=" ---------------";
    bjcards[12][2]=" |    _____    |";
    bjcards[12][3]=" |   /     \\   |";
    bjcards[12][4]=" |   |     |   |";
    bjcards[12][5]=" |   |     |   |";
    bjcards[12][6]=" |   |     |   |";
    bjcards[12][7]=" |   |     |   |";
    bjcards[12][8]=" |   \\____\\/   |";
    bjcards[12][9]=" |         \\   |";
    bjcards[12][10]=" ---------------";
    bjcards[13][1]=" ---------------";
    bjcards[13][2]=" |             |";
    bjcards[13][3]=" |     |  /    |";
    bjcards[13][4]=" |     | /     |";
    bjcards[13][5]=" |     |/      |";
    bjcards[13][6]=" |     |\\      |";
    bjcards[13][7]=" |     | \\     |";
    bjcards[13][8]=" |     |  \\    |";
    bjcards[13][9]=" |             |";
    bjcards[13][10]=" ---------------";
    bjcards[14][1]=" ---------------";
    bjcards[14][2]=" |      ^      |";
    bjcards[14][3]=" |     / \\     |";
    bjcards[14][4]=" |    /   \\    |";
    bjcards[14][5]=" |   /     \\   |";
    bjcards[14][6]=" |   |     |   |";
    bjcards[14][7]=" |   \\_/^\\_/   |";
    bjcards[14][8]=" |      |      |";
    bjcards[14][9]=" |             |";
    bjcards[14][10]=" ---------------";
    bjcards[15][1]=" ---------------";
    bjcards[15][2]=" |      _      |";
    bjcards[15][3]=" |     / \\     |";
    bjcards[15][4]=" |    /   \\    |";
    bjcards[15][5]=" |   /     \\   |";
    bjcards[15][6]=" |   \\     /   |";
    bjcards[15][7]=" |    \\   /    |";
    bjcards[15][8]=" |     \\_/     |";
    bjcards[15][9]=" |             |";
    bjcards[15][10]=" ---------------";
    bjcards[16][1]=" ---------------";
    bjcards[16][2]=" |     ___     |";
    bjcards[16][3]=" |    /   \\    |";
    bjcards[16][4]=" |   _\\   /_   |";
    bjcards[16][5]=" |  /  \\ /  \\  |";
    bjcards[16][6]=" |  |       |  |";
    bjcards[16][7]=" |  \\__/|\\__/  |";
    bjcards[16][8]=" |      |      |";
    bjcards[16][9]=" |             |";
    bjcards[16][10]=" ---------------";
    bjcards[17][1]=" ---------------";
    bjcards[17][2]=" |o-----------o|";
    bjcards[17][3]=" | |o /___\\ o| |";
    bjcards[17][4]=" | | /|   |\\ | |";
    bjcards[17][5]=" | |/ |   | \\| |";
    bjcards[17][6]=" | |\\ |   | /| |";
    bjcards[17][7]=" | | \\|___|/ | |";
    bjcards[17][8]=" | |o \\   / o| |";
    bjcards[17][9]=" |o-----------o|";
    bjcards[17][10]=" ---------------";
    bjcards[18][1]=" ---------------";
    bjcards[18][2]=" |             |";
    bjcards[18][3]=" |             |";
    bjcards[18][4]=" |             |";
    bjcards[18][5]=" |             |";
    bjcards[18][6]=" |             |";
    bjcards[18][7]=" |             |";
    bjcards[18][8]=" |             |";
    bjcards[18][9]=" |             |";
    bjcards[18][10]=" ---------------";
    /*for(int w=1;w<=10;w++)
       {
            for(int v=12;v<=17;v++)
            {
                cout<<bjcards[v][w];
            }
            cout<<'\n';
       }*/
    cout<<"    -------------"<<'\n';
    cout<<"    | BLACKJACK |"<<'\n';
    cout<<"    -------------"<<'\n'<<'\n';
    for(int v=1;v<=10;v++)
        cout<<"   "<<bjcards[14][v]<<'\n';
    cout<<"Welcome to Blackjack! Place a sum to bet: ";
    cin>>bjsum;
    for(j=1;j<=3;j++)
    {
        clrscr();
        cout<<"    -------------"<<'\n';
        cout<<"    | BLACKJACK |"<<'\n';
        cout<<"    -------------"<<'\n'<<'\n';
        cout<<"    Shuffling.";
        Sleep(500);
        clrscr();
        cout<<"    -------------"<<'\n';
        cout<<"    | BLACKJACK |"<<'\n';
        cout<<"    -------------"<<'\n'<<'\n';
        cout<<"    Shuffling..";
        Sleep(500);
        clrscr();
        cout<<"    -------------"<<'\n';
        cout<<"    | BLACKJACK |"<<'\n';
        cout<<"    -------------"<<'\n'<<'\n';
        cout<<"    Shuffling...";
        Sleep(500);
    }
    clrscr();
    cout<<"    -------------"<<'\n';
    cout<<"    | BLACKJACK |"<<'\n';
    cout<<"    -------------"<<'\n'<<'\n';
    cout<<"       DRAWING"<<'\n';
    clrscr();
    int bjon=1;
    for(int w=1;w<=10;w++)
    {
        for(int v=1;v<=6;v++)
            cout<<bjcards[18][w]<<' ';
        cout<<'\n';
    }
    cout<<"\n\n\n          -------------\n          | BLACKJACK |\n          -------------\n\n\n\n";
    for(int w=1;w<=10;w++)
    {
        for(int v=1;v<=6;v++)
            cout<<bjcards[18][w]<<' ';
        cout<<'\n';
    }
}
int lobby()
{
        if(hmm==1)
            system("color 0A");
        else
            system("color 07");
        clrscr();
        cout<<"                ----------- "<<'\n';
        cout<<"               |           |\n";
        cout<<"               | L O B B Y |"<<'\n';
        cout<<"               |           |\n";
        cout<<"                ----------- "<<'\n';
        cout<<"\n\n";
        cout<<" --------\n";
        cout<<"|  News  |\n";
        cout<<" --------\n";
        int news=rand()%5+1;
        switch(news)
        {
            case 1: cout<<" --------------------------------------------------\n";
                    cout<<"|Casinoul din Las Vegas a dat faliment dupa ce.....|"<<endl;
                    cout<<" --------------------------------------------------\n";
                    break;
            case 2: cout<<" ----------------------------------\n";
                    cout<<"|Noul nostru Casino va permite.....|"<<endl;
                    cout<<" ----------------------------------\n";
                    break;
            case 3: cout<<" ------------------------------\n";
                    cout<<"|Casinoul nostru va ajunge.....|"<<endl;
                    cout<<" ------------------------------\n";
                    break;
            case 4: cout<<" -----------------------------------------------------\n";
                    cout<<"|Oamenii pierd multi bani la pariurui. Dar , aici.....|"<<endl;
                    cout<<" -----------------------------------------------------\n";
                    break;
            case 5: cout<<" ----------------------\n";
                    cout<<"|Un tip a castigat.....|"<<endl;
                    cout<<" ----------------------\n";
                    break;
        }
        cout<<"1-Sloturi ; 2-Ruleta ; 3-Bitcoin Miner; 4-Dice Spin; 9-News; 0-Exit"<<endl;
        joc=_getch()-'0';
        if(joc==0){
            bool exit;
            cout<<"\nAre you sure you want to exit?\nTo return to lobby press 1.\nTo exit press 0."<<endl;
            exit=_getch()-'0';
            if(exit==0)
                return 0;
            else lobby();
        }
        else if(joc==1) sloturi();
        else if(joc==2) ruleta();
        else if(joc==3) bitcoin();
        else if(joc==4) zarurile();
        else if(joc==5) blackjack();
        else if(joc==9){
            cout<<" ---------------------------------------------------------------------------\n";
            cout<<"|Casinoul din Las Vegas a dat faliment dupa ce un tip a castigat toti banii.|"<<endl;
            cout<<"|Noul nostru Casino va permite sa aveti suma mult mai mare de bani.         |"<<endl;
            cout<<"|Casinoul nostru va ajunge foarte curand la dimensiunea de 1GB.             |"<<endl;
            cout<<"|Oamenii pierd multi bani la pariurui. Dar , aici pierzi si mai multi.      |"<<endl;
            cout<<"|Un tip a castigat 100000000 de euro.                                       |"<<endl;
            cout<<" ---------------------------------------------------------------------------\n";
            pause();
            clrscr();
            lobby();
        }
        else{
            while(joc>9 || joc<0)
             {
                 cout<<"\nPlease enter a valid number: ";
                 joc=_getch()-'0';
             }
            if(joc==0){
                bool exit;
                cout<<"\nAre you sure you want to exit?\nTo return to lobby press 1.\nTo exit press 0."<<endl;
                exit=_getch()-'0';
                if(exit==0)
                    return 0;
                    else lobby();
            }
            else if(joc==1) sloturi();
            else if(joc==2) ruleta();
            else if(joc==3) bitcoin();
            else if(joc==4) zarurile();
            else if(joc==9){
                cout<<" ---------------------------------------------------------------------------\n";
                cout<<"|Casinoul din Las Vegas a dat faliment dupa ce un tip a castigat toti banii.|"<<endl;
                cout<<"|Noul nostru Casino va permite sa aveti suma mult mai mare de bani.         |"<<endl;
                cout<<"|Casinoul nostru va ajunge foarte curand la dimensiunea de 1GB.             |"<<endl;
                cout<<"|Oamenii pierd multi bani la pariurui. Dar , aici pierzi si mai multi.      |"<<endl;
                cout<<"|Un tip a castigat 100000000 de euro.                                       |"<<endl;
                cout<<" ---------------------------------------------------------------------------\n";
                pause();
                clrscr();
                lobby();
            }
        }
}
//------------------------------------------------------------------------------------------------------------MAIN
int main()
{
    int setari=1;
    ///fullscreen();
    srand(time(0));
    cout<<"Welcome!"<<'\n';
    pause();
    clrscr();
    if(login()==0)
        return 0;
    ifstream qwerty("conturi.in");
    qwerty>>total;
    qwerty.close();
    ifstream qwert("money.in");
    for(i=1;i<=total;i++)
        qwert>>usermoney[i];
    qwert.close();
    while(setari!=0)
    {
        clrscr();
        cout<<"1-Settings"<<endl;
        cout<<"0-Continue"<<endl;
        setari=_getch();
        setari-='0';
        clrscr();
        if(setari==1)
        {
            cout<<"1-Graphics"<<endl;
            cout<<"2-HackerManMode"<<endl;
            cout<<"3-Developer Options"<<endl;
            cout<<"0-Exit"<<endl;
            setari=_getch();
            setari-='0';
            clrscr();
            if(setari==1)
            {
                int op=0;
                cout<<"1-Low"<<endl<<"2-Medium"<<endl<<"3-High"<<endl<<"4-Toggle fullscreen";
                grafici=_getch();
                grafici-='0';
                while(grafici==4){
                    //cout<<"1-Low"<<endl<<"2-Medium"<<endl<<"3-High"<<endl<<"4-Toggle fullscreen";
                    if(grafici==4)
                        fullscreen();
                    grafici=_getch();
                    grafici-='0';
                }
                /**if(grafici!=4)
                {
                    op=grafici;
                }
                if(grafici==4)
                {
                    fullscreen();
                    if(op)
                    {
                        grafici=op;
                    }
                }**/
            }
            if(setari==2)
            {
                cout<<"1-ON"<<endl;
                cout<<"0-OFF"<<endl;
                hmm=_getch();
                hmm-='0';
            }
            if(setari==3)
            {
                cout<<"Password: ";
                cin>>parolauser;
                if(parolauser=="******")
                {
                    cout<<"Speedhack: ";
                    cin>>speedhack;
                }
            }
        }
    }
    ///NEWS-------------------------------------------------------------------------------------------
        if(grafici==3 || grafici==2)
        {
            system("color 0C");
            cout<<"               ---------------"<<'\n';
            cout<<"               |             |"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0E");
            cout<<"               ---------------"<<'\n';
            cout<<"               |            P|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0A");
            cout<<"               ---------------"<<'\n';
            cout<<"               |           Pa|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0B");
            cout<<"               ---------------"<<'\n';
            cout<<"               |          Pac|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0D");
            cout<<"               ---------------"<<'\n';
            cout<<"               |         Paca|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0C");
            cout<<"               ---------------"<<'\n';
            cout<<"               |        Paca-|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0E");
            cout<<"               ---------------"<<'\n';
            cout<<"               |       Paca-P|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0A");
            cout<<"               ---------------"<<'\n';
            cout<<"               |      Paca-Pa|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0B");
            cout<<"               ---------------"<<'\n';
            cout<<"               |     Paca-Pac|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0D");
            cout<<"               ---------------"<<'\n';
            cout<<"               |    Paca-Paca|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0C");
            cout<<"               ---------------"<<'\n';
            cout<<"               |   Paca-Pacan|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0E");
            cout<<"               ---------------"<<'\n';
            cout<<"               |  Paca-Pacane|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0A");
            cout<<"               ---------------"<<'\n';
            cout<<"               | Paca-Pacanel|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0B");
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*350);
            clrscr();
            system("color 0D");
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*400);
            system("color 0C");
            Sleep(speedhack*400);
            clrscr();
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            system("color 0E");
            Sleep(speedhack*400);
            clrscr();
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            system("color 0A");
            Sleep(speedhack*400);
            clrscr();
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            system("color 0B");
            Sleep(speedhack*400);
            clrscr();
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            system("color 0D");
            Sleep(speedhack*400);
            clrscr();
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            if(hmm==1)
                system("color 0A");
            else
                system("color 07");
            clrscr();
            if(grafici==3)
                for(int i=1;i<=5;i++)
                {
                    switch (i)
                    {
                    case 1: system("color 0C");
                            break;
                    case 2: system("color 0E");
                            break;
                    case 3: system("color 0A");
                            break;
                    case 4: system("color 0B");
                            break;
                    case 5: system("color 0D");
                            break;
                    }
                    cout<<"               ---------------           "<<'\n';
                    cout<<"             _ |Paca-Pacanele| _         "<<'\n';
                    cout<<"            /  ---------------  \\        "<<'\n';
                    cout<<"           *                     *       "<<'\n';
                    Sleep(speedhack*200);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"            /  ---------------  \\        "<<'\n';
                    cout<<"           /                     \\       "<<'\n';
                    cout<<"          *                       *      "<<'\n';
                    Sleep(speedhack*200);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"           /                     \\       "<<'\n';
                    cout<<"          |                       |      "<<'\n';
                    cout<<"          *                       *      "<<'\n';
                    Sleep(speedhack*100);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"         \\|/                      \\|/    "<<'\n';
                    cout<<"        --*--                    --*--   "<<'\n';
                    cout<<"         /|\\                      /|\\    "<<'\n';
                    Sleep(speedhack*100);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"        \\ | /                    \\ | /   "<<'\n';
                    cout<<"         \\|/                      \\|/    "<<'\n';
                    cout<<"      ----*----                ----*---- "<<'\n';
                    cout<<"         /|\\                      /|\\    "<<'\n';
                    cout<<"        / | \\                    / | \\   "<<'\n';
                    Sleep(speedhack*100);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"        \\ | /                    \\ | /   "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"      --  *  --                --  *  -- "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"        / | \\                    / | \\   "<<'\n';
                    Sleep(speedhack*100);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"       /\\ | /\\                  /\\ | /\\  "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"       _     _                  _     _  "<<'\n';
                    cout<<"      /       \\                /       \\ "<<'\n';
                    cout<<"        / | \\                    / | \\   "<<'\n';
                    cout<<"        | | |                    | | |   "<<'\n';
                    Sleep(speedhack*100);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"       /\\ | /\\                  /\\ | /\\  "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"       _     _                  _     _  "<<'\n';
                    cout<<"      /       \\                /       \\ "<<'\n';
                    cout<<"        / | \\                    / | \\   "<<'\n';
                    cout<<"        | | |                    | | |   "<<'\n';
                    Sleep(speedhack*200);
                    clrscr();
                    cout<<"               ---------------           "<<'\n';
                    cout<<"               |Paca-Pacanele|           "<<'\n';
                    cout<<"               ---------------           "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"      /       \\                /       \\ "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"     /         \\              /         \\ "<<'\n';
                    cout<<"                                         "<<'\n';
                    cout<<"        | | |                    | | |   "<<'\n';
                    Sleep(speedhack*400);
                    clrscr();
                }
        }else if(grafici==1)
        {
            cout<<"               ---------------"<<'\n';
            cout<<"               |Paca-Pacanele|"<<'\n';
            cout<<"               ---------------"<<'\n';
            Sleep(speedhack*2000);
        }
        if(hmm==1)
            system("color 0A");
        else
            system("color 07");
        clrscr();
        if(lobby()==0)
            return 0;


            /*
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmmdhhhhyyyyyyyyyyyyyyyyysssssoooooooooo-...+ssoyhmmmmmmmNNNNmmdddddddmmmmmmmmmdddmmmmmmmNNNNmo:-....--::-------....................----.-.....-----::///+osyyhdhyo++////+ossoo+oosssyyyyyyyyyyhhhhhhhhhhhhddmNNNMMMMMMMMNhsosdmNNNNNNNds+//+syyyyhmNNNNNNNNNNNNNMMMNNNNNmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNmhhyyyyhhyyyhhhhhhhhhhhhhhhhhhhhdddddhhhhhhdddddddhdddddddddddddddddddddddddddddddddddddmmmhssssoo+++++++++oosssyyhhddmmmmNNNNmmmmmmmmNNNNNNNNNNNmddmmmmdd
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmddhhhhhyyyyyyyyyyyyyyysssssoooooooooo:...:sssydmmmNNNmNNNNmmmdddddddmmmmmmmmddmmmmmmmmNNNNh+-....--:://///:-----..................-----...------::::/+osyyyhddhyss+/:/+ss+//+osssyhhhhhyyyyyhhhhhhhhddmmNNNMMMMMMMMMMMNho++sdNNNNNNNds///+ssssyhmNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNmmmmhhyyyyhhhyyhhhhhhhhhhhhhhhhhhhhdddddhhhhhhdddddddhhdddddddddddddddddddddddddddddddddddddmmdysssoo+//////++ooossyyhhddmmmmmmmmmmmmmmmmNNNNNNNNMNmmdmmmmddd
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhhhhhhyyyyyyyyyyyyyyysssssoooooooosso....+ssydmmmNNNNNNNNNmmdddddmmmmmmmmmmmdmmmmmmmNNNNNy/-...---:/++oo+/:------................-------------:::://+osyyyhdddhyo+//+o+//:/+osssydmmmmdddddddddmmmNNNNNNNMMMMMMMMMMMMNdo//+sdmNNNNNds+/++osssydmNNNNNNNNNMMMNNNNmmmmmmmmmddmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNmmmmmmdhyyyyhhhhyhhhhhhhhhhhhhhhhhhhhddddhhhhhhhhhdddddhddddddddddddddddddddddddddddddddddddddmmmdssoo+///////++oossyyhhddmmmmmmmmmmmmmmmmNNNNNNNNNNNmmmmmmmddd
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddhhhhhyyyyyyyyyyyyyyyyssssoooooosssss/...:syhmmmmmNNNNNNNNmmdddddmmmmmmmmmmmdmmmmmmmmNNNdo:-...--::/+osso+:::------......-------------------::::///++osyyyhhddhso++++///////+osyhdmNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMNds+//oshmNNNmhs+/++oossydmNNNNNNNNNNNNNNmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNmmmmNmdhyyyyhhdhyhhhhhhhhhhhhhhhhhhhhddddhhhhhhhhhhhdddddddddddddddddddddddddddddddddddddddddddmmdyoo+//////+++oosssyyhhddmmmmmmmmmmmmmmmNNNNNNNNNNNNmmmmmmdddd
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddhhhhhyyyyyyyyyyyyyyyyssssssoooossssso.``.oyhmmmmmNNNNNNNNmmdddddmmmmmmmmmmmmmmmmmmmmmNdo:-...---://+ossso/:----------..------------:::::::::::://++oosyyyyhddhsooo+/////::/+oyyhdmNNNNNNMNNNNNNNMMMMMMMMMMMMMMMMMMMMNms+//+oydmmmdhso++++ossyhmNNNNNNNNNNNNNNNmmddmmmmmmmmmmmmmmmmNNNNNmmmmmmmmmmNNNNNNNNdysssyhhhyyyyhhdhyyhhhhhhhhhhhhhhhhhhhddddhhhhhhhddhhhhddddddddddddddddddddddddddddddddddddddddddmds+///////+++oossyyyhhddmmmmmmmmmmmmNmmmNNNNNNNNNNNNmmmmmmdddd
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhhhhhhyyyyyyyyyyyyyyyssssssooooosssso:.`./yhmNmmNNNNNNNNNNmmddddmmmmmmmmmmmmmmmmmmmmmmy/-...---::/++ossyyo:-----------------------:/::::----:://++ooosssyyhhhyssso+//::::/++osyyhmNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmyo//+oshdddddyo+/++ossyhdNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmmmmNmmmNmmmmmmmmNNNNNNmy+::-::/oyyyyyyhdhyhhhhhhhhhhhhhyyhhhhhddddhhhhhhhdhhhhhhdddddddddddddddddddddddddddddddddddddddddho+///////+++oossyyyhhddmmmmmmmmmmNNNNmmNNNNNNNNNNNNNmmmmmmdddm
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmddhhhhhyyyyyyyyssyyyyyysssssoooooooooo+...-odmmmmNNNNNNNNNNmmddmdddmmmmmmmmmmmmmmmmmmmdo:-...--::/++oosyhyo:::::::----------------://::------:://+ooooossyyyyyyyyyso+//::-::/+osyhdNNNMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMNNmyo///+sydmmmdyo+//+oosyhdNNNNNNNNNNNNNNNNNNmhyyhdmmmmmmmmmNNNNNNNNNmmmmmmmNNNNNNds/:----:/+syyyyyhdhyhhhhhhhhhhhhhyyhhhhhhdddhhhhhhhdhhhhhhhddddddddddddddddddddddddddddddddddddddhs+/////////++oossyyhhhddmmmmNmmmNNNNNNmmNNMMMNNNNNNNNNmmmmmmdddm
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddhhhhhyyyyyyyysssyyyyyssssssoooooooooo-.../dmmmmmNNNNNNNNNmmmmmmdddmmmmmmmmmmmmmmNmmmh/-...---:/++oossyhyo/:::::::::------:::::::::---------::/++++//+oyyyyyyyyyyyso/:----::/osyhdmNNNMMMMMNNNNNNNNMMMMMMMMMMMMMMMMMNmyo///+oydmmmdyo+//+oosyhdmNNNNNmNNNNNNNNNNds+/+sdmmmmmmmmmmmmmmmmmmmmmmmmNNNNNmy+:-----://oyyyyyyhdhyhhyyyhhhhhhhhhhhhhhhhhhdhhhhhhhdhhhhhhhdddddddddddddddddddddddddddddddddddddyo/////////+++oossyyhhhddmmNNNNmmNNNNNNNmmNMMMMMMMMMMMNNmmmmmddddm
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmddhhhhhyyyyyyysssyyyyyysssssoooooooooo+-..:ymmmmNNNNNNNNNNNmmmmmdddmmmmmddmmmmmmmNNNms/-.----::/+oosssydho/:------------:////:::----------:::////:::/oyyyyssssyhhys+:-----::/oyhhdmNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMmyo///+oydmmmmhs+//+oosyhdNNNNmmmmNNNNNNNmho/:/ohmmmmmmmmmmNNNNNmmmmmmmmmNNNNNds/:-----://+oyyyyyyhhhhhhhyyyhhhhhhhhhhhhhhhhhhhhhhhhhdhhhhhhhhhdddddddddhhddddddddddddddddddddddhs+/////////++oossyyyhhhddmmNNNNNmNNMMMMMNmmNMMMMMMMMMNNNmmmmmmdddmm
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdddhhhhhyyyyyyssssyyyyysssssooooooooooo:-.-/mNNNNNNNNNNNNNNmmmmmdddmmmmmmddmmmmmmmNNho:------:/+ossssyhmms/--.-----..--////:-------------::://::--:/oyysssssooshhs+:------:/+oyhddmNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmdhhhhysoososydmmmmdyo+/++osshdNNNNmmmmNNNNNNmy+::/odmmmmmmmmmmmmmmmmmmmmmmmmmNNMNho:-----:://+osyyyyyyhhhhhhhyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddddddhhhhddddddddddddddddddddhyo//////////++oossyyhhhddmmNNNNNNmmmNNNNNNmmmNNNNNNNNNNNNmmmmmmmdddmm
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddddhhhhhyyyyyyyssyyyyyysssssoooooooooo+-..-yNNNNNNNNMMNNNNNmmmmmdmmmmmmmdddmmmmmmmms/-------:/+ssssyydmNdo:-.......-::::---.......------::::----:+oysssssso+osyho/---.---:/+oshdmmmNNNNNNNNNNNNNNNNNmdhhyso+:----:++osyyhhhhhdmmmmdyo+//++oshmNNNNmmmmNNNNNds/:-:odmmmmmmmmmmmmmmmmmmmmmmmmmNNNmy+:-----::/+osyyyyyyyyyhhhhhhyyyhhhhhhhhhhhhhhhhdhhhhhhhhdhhhhhhhhhddddddddhhhdddddddddhdddddddddyo+/////////++oossyyyhhddmmNNNmmmmmmmmNNNNNmmmmNNNNNNNNNNNNmmmmmmmmmmmN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdddhhhhhyyyyyyyysyyyyyysssssooooooooooo-.``/mNNNNNNNMMMNNNNmmmmmmmmmmmmmmdddmmmmmmms:-...---:/osssyyhdNMms/--....--::--..........-------------:/+ssssssooo+++oys+:-...---:/+oydmmmNNNNNNNNNNNNNNNNNmys++/::-..:/oshdmmmmdyhyhmmmmmmyo+///+oshmNNNNmmmmmNNNds/:-:+hNmmmmmmmmmmmmmmmmmmmmmmmmmNNho/------::/+osyhhhyyyyyyhhhhhhyhyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdddddddhhhhddddddddhhdddddddhs+/////////+++oossyyhhddmmNNNNmmmmmmmmNNNNNNmmmmNNNNNNNNNNNNmmmNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddhhhhhyyyyyyyyyyyyyyysssssssoooooooso/.``-yNNNNNNNMMMNNNNNNNNmmmmmmmmmmddddmmmmmh+:..--::/+osssyyyhmNNms/:--..-----............--::::-----::+ossssooooo++//+o+/--...---::/oydmNNNNNNNNNNNNNNNNNNNNNmhsssoo/-+ydmmmNNmdyhoohmmmmmmho/////osdmNNNNmmmmmNmho/---/smNmmmmmmmmmmmmmmmmmmmmmmmmmdy+:------://+syhmmdhyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdhhhhhhhhhhdddddddhhhhddddddddhhdddddhyo+/////////+++oossyyhhddmNNNmmmmmNNmmmmNNNNNNNmmNNNNNNNNNNNNNmmNNNNNMNMMM
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhhhhyyyyyyyyyyyyyyyysssssssooooossso-``.+mNNNNNMMMMNNNNNNNNmmmmmddmmmmdddmmmmmy/----:://++oosssydmNNdo/:--------............---::::::--::+oooooo++++o+/::/+/:--..---::/+shmNNNNNNNNNNNNNNNNNNNNNNNNmhsso+:./hmmmmdhydo/oymmmmmmyo/:://+ydNNNNNmmmmmdy+:---:odNNmmmmmmmmmmmmmmmmmmmmmmmdyo/------::/+oyhdmNNmhyyyyyyhhdhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdhhhhhhhhhhhdddddhhhhhhdddddddhhddddhs+//////////++oossyyhhddmNNNmmmmmmNNNmmmmNNNNNNNmmNNNNNMNNNNNNNmmNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhhhyyyyyyyyyyyyyyyyysssssssssssssss/...:ydmmNNNNNNNNNNNNNmmmmddddmmmmmddmmmmdy/-----://++ooosyhmNNNho:--------............--------::::::/+++/////+o+/::/+/:-...---::/+oshhhhhdmNNNNNNNNNNNNNNNNNNNNNdyo++/oyhdddhdmh//oydmmmmmyo/:::/+ymNNNmNNmmmho/:---:+ymNNmmmmmmmmmmmmmmmmmmmmmdho/:------:/+oshdmNMMMmhyyyyyyhhhddhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhddhhhhhhhdddddddhhddhyo//////////++ooossyhhddmNNNmmmmmmNNNNNmmmNMMMMMMNmmNNNNMMMMMMMMNmmNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhhyyyyyyyyyyyyyyyyyyyyyyyyyyyhhyys:...+yhhhhddddmmmmmNNmmmmdddmmmmmmmmmmmmds/----:://++ossyhdNMMNh+:------............-------------::::///:://+oo/::/++/-....---::/+osys+//+oydmNNNNNNNNNNNNNNNNNNmdhsoooshddmmNmy//oydmmmmmy+/:::/ohNNNmmmmmds+:---::+sdNNNmmmmmmmmmmmmmmmmmmmmdh+:------::/+sydmNNMMMMmhyyyyyhhhhddhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhhhddddddhhhyo+//////////++oossyyhhdmmNNmmddmmNNNNNNNmmmNMMMMMMNmmNNNMMMMMMMMMNmmNNNNMMMMMM
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhhhhhhhhhhhhhhhhhdddhhhhhhhhhhhy+-..-syyyyyyyyyyhdmNNmmmmddmmmmmmmmmmmmmdo:-----:://+ooshdNNMMNh+--...-....------------------------::::///+oso+///+++:-....---:/osyhhs/:--:/+sydmNNNNNNNNNNNNNmddhs+/oyhhhdmmmmy//oydmmmmmy+/:::+ymNNNmmmdy+/:-:://+sdNNNNNmmmmmmmmmmmmmmNmmdyo:-..-:///++sydmNNMMMMMMmhyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhhdddddddhys+////::////++oossyyhhdmmNNNmmmdmmmNNNNNMNmmNMMMMMMMNmmNNNMMMMMMMMMNmNNNNNNMMMMM
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmmddddddddddddddddddddddhhhhhhhys:.../yyyyyyyyyyyhmNNmmmmdmmmmmmmmmmmmmmds/------:://+oyhmNMMMNh+-.......--------------------::---::://+/+oso+//++++/-.....--:+oyyhmdy+:----::/+oshmNNNNNNNmdyo++s+:`-+ydyhhhddy++oyhddmmdy+:::/ohNNNmmdyo/:-::/+osyhmNMMNmmNNNNNNmmmmmNNmdy+-```-:/+osyhhdmNNMMMMMMMMmhyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhhddddddhs+////:::////++oosyyhhdmmNNNNmmmmmmmNNNNMMMNmmNMMMMMMMNmmNNNMMMMMMMMMNNNNNNNMNNMMM
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmmddddddddddddddddddhhhhhhhyy+.``.syyyyyyyyyyhmmNmmmmdmmmmmmmmmmmmmmmh+:-----:::/osydmNMMMNd+:........-----------------:::::://++o+//+os+//+o++/:......-:/oyhdmNNds+:----:////+shmmmmmdyo/:::oo/``.:oyhddddys++oooossso/:::+ymNNNmds/:--:/+syhdmmNNNNNmmmmmNNNNNmNNNmy+:-.``-++/+shddmNNMMMMMMMMMMmhyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhhddddhyo///::::////++oossyhhdmmNNNNNNNNNNNNNNNNMMMNNNmNMMMMMMMNNNNNMMMMNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmmddddddddddddddddddhhhhhhys-```/yyyyyyyyyyhdmmmmmmmmmmmmmmmmmmmmmmdo:-----::/+oyhmNMMMNMms/-.......---------------::://///++oo+///+oo++ooo+/:-.....--:+shdmNMMNms+:--:/+oso+++ossssso+++++++/.` `-shmmmmmds/////////:::/shmmmdyo/:-:/+shdmmNNNNNNNNmmmmmmmmmNNNmho/---.../ossyhdmNNMMMMMMMMMMMMmhyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhhddhyo+//:::::///+++ossyyhdmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmddddddddddddddddddhhhhhhy+.`.-shhhhhhyyyhdmmmmmmmmmmmmmNmmmmmmmdy+:-----:/+oshdNMMMMMMNd+:---------------------::://////+++++//+osssys+///:------::/+shdNMMMMNho///+osssso++++++osyyyys/:/-`  `.-oyddddmmy+//::::::::/+sssoo/::::/ohdmmmNNNNNNNNmmmmmNNNNmmmho/-------:+yhddmNNMMMMMMMMMMMMMMmhyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhhhyo+//:::::////++oosyyhdmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmddddddddddddddddddhhhhys-...+hhhhhhyssydmmmmmmmmmmmmmNmmmmmmds+:------::+osdmNMMMMNNNNyo/:::::::::::::------::::://+++oooo++osyyyyo+/:://///////+osyhmNMMMMNmyooshddhysooo++++oyhhhy+:..   `` `-osssydddhyysoo++/::::///++ooooosdmmmmmNNNNNNNNNmmmmmmNNmds/--------:/oydmNNMMMNNNNMMMMMMMMMmhyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhhhyo+//::::::///++oosyyhdmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmmddddddddddddddddhhhhy+-..:yhhhhysosyhmmmmmmmmmmmmmmmmmmmmyo//::----:/oshdNMNNNNNNNNmdhyssssssssso++/::://////+oyyhhdddddddmdysoo+////////+++ooyhdmNNNNNNNmdddmmmmmmhyo+++++oyhhso+:-...``.:+oyhhyyyyhhhhhyshyoo+////++ossyyyhdmmmmmNNNNNNNNmmmmmmdhys+:-------:/+shdmNMMMNhsooshdNNMMMMNmhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhyo+//::::::///++ossyhddmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmmddddddddddhhdddhhhys:-.-+hhhhysosyhdmmmmmmmmmmmmmmmmmmmho+//::--::+syhmNNNmmdddddmmmmdmmmmmmmddddhysyyyyhhdmmNNNNNNNNNNNNhysyhs+++++++oossssdmmmmmmmmmmmmmmmmmmmmmhs++//+osyyyhyo/:-/:..:ohddddhyhhhddddhhhhyysso+/////++oyhmmmmmNNNNmdhhyyyyso+//::------:/oshdmNMMNmho/---::/oydmNNNmhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhso+/:::::::///++oosyhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmddddddhhyyhddhhhyy/.``.yhhhysssyhdmmmmmmmmmmmmmmmmmmmdso+++//://+syhdmddhhhhhhhddddmmNNNNmmddmNNNmmmmmNNNNmmmmmmmmmmmmmdddmdyooooosyyhhhhdNNNNNNNmmmmmmmmmmmmmmmdyoooooyhhddhhyso++:--:oyhdddhhhhhhhddhhmhyhhss+/////+oyhdmmmmmmmdyo+/:::///:::::::::::/+shdmNMMNmy+/::::::--::/oshddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdhhhhhhhhhhhhhyyso+/:::::::///++ossyhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmddhyssssyhdhhyys+.```/hhhhyssyhhhhdmmmmmmmmmmmmdhyyso+oosoo+++oosyyhhhyyyyyyhddddmmNNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhhhhdddmmdmmmmmmmmmmmmmmmmmmmmmmmmdddyyo++++::.--.``.-://+yyoyhysyyyssdmdhhmhdhs++/////+oshdmmmdhs+/:--::://++//:://////+oydmNNMMNy/:-:/+o+/:---::///+oyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdhhyyyhhhhhhhyooo+++///::://++ossyhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNdyooossyhddhyso+-```-sssssooooooooyhdddhhddddyo++++++oyyyyyyyyyyyyyyyyysssyhdhhhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddmmmmmmmmmmmmmmmmmmmdddhd+soo:`- `.``-oyddhdmmsshyyhmdysymmdmmmdhs/++++++osyhmNNms/:----::/+syys+//+ooooosydmNNMMMNy+:--://+/::-:://///++shhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyhhhhhhhhs+///+oo+++///+ossyhddmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdyoosssyhhhyoo++::/+++++++++++//+oyhhhyyhhhhs+//+ossyhhhhhhhyyyyhhhddhysssyhyssyhdmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddhysssyhddddddddmmmmmddddmmmmmmmdmdho+oss-`-````./ydmhyhNmyshyydmdhhdmmmmNNmdy/+ooooossydmNms/---::/+shdmdy+/+oyddddddmmmNNNNNh/:------:////++ooo+++oshhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyhhhhhhhhhhhhhyyhhho+//::::::/oosooosyhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhysssyhhysooooooosoooooooooooooshhhyyyhhhsoooosydmdhhhhhhhhddmmmmmdhsosyyyooyhmmNNmmmmmmmmmddddddddddddddddhhhddddddddddddhysssyyhdddddddddddddddmmmmmmmmmdddoso+/--:-`-::oyhhhyymmhydddmmdyhmmNmNNNNmh/+osssssyhdmds/--:+yyhdmNNNdyoshmNNmmmdddddddmmmh+---::/+syyhhhyyysssssyhhhhhhhhhhhhhhhhhhhhhhhhhyo+:://+oosyyyhhyyyso+yhs:-:/:::-:::/hhhyyhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            NNNMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmhyssyhyssssossyssooooooosssssyhddhhhdddddddhhdmmmmmmmmmmmmmmmdddmdhyyhhyssyhdmmmmmddddhhhhddddddddddddhyssyyhddddmddddddddhhhdddddddddddddddddmmmmmmmmmmdddyyoo+///o.:/+shsoyhyhdhyyydmNdhhmmNNNmmmmyyyhhhhhhdddmy+::+ydmmmNNNNNNNmNNNNNmmddddddddddddhsosyyhhdhhhhyyssssssyyhhhhhhhhhhhhhhhhhhhhhhyo+:--------::/+++o++++++os/-:/:-.---::/dmdddmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMNNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNdhyyyssooooshysoososyyyhddddmmmmmmmNmmmmNNNNNmNmmmmmmmmmmmmmmmmmddddddddddddddddddhyysssssyhddddddddhyyyhddddddddddddddddddddhso++ooyhdddddddddmmmmmmmddddhsss++/y+/osyhsyhdssooosyhmmmmmmmNNmmNNmddddddddddmmdy+/ohmmmmNNNNNNNNNNNNNNNmmmmmddddddddddddddyo//////////++oosyddddhhhhhhhhhhhhhhyo/::-----------:::/++++++//+o/--::::///:/ymmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhssooooshhyyyyhddmmmNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddmddhyso++oshddmdddddmddddhhhyyyyhddddddddddddyo/://+oyhdddddddddddmmmdddddhddhso+yy/oosdmNmmhyddhdmmNNNNmNNNNmNNmddddddmdddddddhyyhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddhs/:::///:::/+osyddmmmddddddddddddhs/:--::::::-----:::::://+++++++oo+/:::///+oymNNNNmNNNNNNNNNNNNNNNmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdsooosshhddddmmmmNNNNNNNNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddhysoossyhddddddddddddhyssssyhddddddddddddddhyyyyyysssssyhdmdddddddmdddmhddhhsydyyyhdmNmmdhmNNNNNNmmmdmmmmmmmmNdddddddddddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmdhyyyyyyyyyyhhhhdddddddddddddddddyo///////::::/::://://:::/++++++++oyhhhhdddmmmNNNNNNNNNNNNNNmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMNNNNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNMMMMMMMMMMMMMMMMMMMMMMMMMMNmhssyhhddddmmmmNNNNNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddhhyyhhhddddddddddmmddhhhhhdddddddmmdddddddmdddhso///+oshddmddddhhhdddmmmmmdyyddhhdddmdhhyhdddddmddhyhdddddddmdyssssyyyyhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddddddhhhhhhhhhhhhhhhhhyyyyssssssssoooosyhhdNNmNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmmmNNMMMMMMMMMMMMMMMMMMMMMMNNmdhhhhhhdddhhhhhdmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddmddhyyyyyhhddddmmdddddmddddddhhddhhhddmmmmddddddmdhs+++ooshhddddddddddhhhdmNNmysoydoooooyo///:+sssydhyysyssyhhyhddhyyyyyyyyyhhhhhhhhhhhyyyyyyyssssssssssssssssssssssossossssyyyyyyyhhhhhhhhhhhhdddddddddddddddddddddddddddddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMNNNNNNNNNMMMMMMMMNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddmmNNMMMMMMMMMMMMMMMMMMNNNmmddhhyyyyyssssyhhhhyyyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddyssoo+oosssyddmmdddddddddhyssssyyhdddmmmmddddddddddddhhhdhhhhhhdddddhhhhmmmms:::y/:/++sso+++syhshyhhhyhhyyhyhhhssooooooooooooooooooooooooo++++++////////////+++ooooooooooooo+++///////::///++++oooooossssyyyyhhhhdddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMNNNNNNNNNNMMMMMNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdddmmmmmNNNMMMMMMMMMMMMMMNNNNNmdhhyyyyyyyyyyyyyyhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmdmmmmmdmmdddddmmmmmmmmddddddddhsooooosyhdmmmdddddmmdhyyyyhhdddddddddddddhhhhhhhhyyyyyyhhhhhdddhhhhhddmd+oo++osss+sys++osyhhhyhhhhhyyyyhssdddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhyssssssyyyyyhyhhhhhhhhhyyyyyyyyyhhyyyyhhhhdddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhhhhhdddmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMNNNNNNNNNMMMMMNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdddmmmmmmmmNMMMMMMMMMMMMMMMMNNmddhhhhhdddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdmmmdddddddddddddddddmmmmmmmddddmmmddyo+++++osdmmmmmddhddmmddmddhyyhhyyhhddddhyysssssyyhhhhhhhhddddddddddddyy+yoooooososhhysoyddddhhdddmddsyhodNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNmmmmmmmmNNNmmmmmmmmmmmmmddddddhhdhhhdddddddddmmmmmmmmmmmmmmmmmmmmmmmmmdhhhhhyyyyyyyhhhddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMNNNNNNNMMNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddddmmmmmmmNNmhmNNNMMMMMMMMMMMNNNNNNNNNNNNNNNNmddddhdmmmmmmmmmmmmmddddddddmmdddddddddddddddddmmmmmmmmdhdddmddhso++ooosyhdmmmmddhhdhhyysoo++ooooosyyyhyyyyhhhddddddmmmmmmmmmmmmmmNNNdysyssossosyhddhyshNNNNddmmmmddyhysNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmdddddddddddddmmmmmmmmmmmmmmddhhhhhyyyyyyyyyhhhhddddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMNMMMNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdddmmmmmmNNNNdydmNNNMMMMMMMMMMMMMMMMMMNNNNNNmddhddhhmmmmmmmddddddddmdddhddmmdddddddddddddddddmmmmmmmmdhhddddddyoooosyyhhhyyssoo+///////++oossyyhhhdddddmmmmmmmmmNNNNNNNNNNNNNNNNNNNNmysssossymmddmmdhmNNNNmmNNNNNdyhsmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmdddddddddmmmmmmddddhhhyyyyyyhhhhhddddddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            NNNNNNMNNNNNNNNNNMMMMNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdmmmmNNNNNNNNNNNNNMMMMMMMMMMMMMMMNNNNNNNNNmmddddddmmmmmmmdddddmddmmdddddmmddddddhdddddddddddmmmmmmmmddhdmdddhyssoo+++//////+++oossyyhhddddmmmmmmmNNNNNNNNNNNNNMMMMMMMMNNNNNNNNNNNNNNmyshyyyhmmdsdmmdmNNNNNNNNNNNmdydNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhydmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMNNNNNNNNNNmmmmmmmmmmmmmmmmmdddhhhhhhdddddmmmmmNNNNNNNNNNNNNNNNNmmmmNNNNNNNNNNNNNNNNNNNNNNNN
            MNNNNMMNMMNNNNNNMNNNNNNNMMMMMNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMNNNNNNNNNNNNNNmmmmmmmmmmmmddddddddddmdddddmmddddddhhhddmddddddmmmmmmmmddhysso++//::::://++osyyhdddmmmmmmNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMNNNmsyhmddmmmhohmdmNNNNNNNNNNNmhdNNNmmmmmmmmmmmmmmmmmmmmmmmddddddddddddhhhhhhhhhhddddddddddddddddddddddddddddddddddddddddddmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMNNNNNNNNNNNNNNmmmmmmmmmmmmmdddddmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMNNNNNNNNNNNNMMNNmmdhhhhhhhdmMMMMMMNNNmdmmNMMMMMMMMNNNNNNNNNNNNNNMNmmNMMMMMMMNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmdddddddddddhhhhdmmdddddhhhhdddddddddddhhyysoo+///::::///+osyhdddmmmmNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNhydmmmmmdy/sydmmNNNNNNNNmhdmmmmmmmdddddddddddddhhhhhhhhhhhyyyyyysssssssssssssssssssssssssssssssssyyyyyyssso++osyyhhhhddddddmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNMNNNNNMMMMMMMMMNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmNNNNNNN
            MMMMMMMMMMNMMNNNNNNMNNdhysssooooooooosyhhhyyso+//+oydNMMMMMMNNNNNNNNNNNNMMMNhydmNNMNNNNNNNNNNNNNNNNNNmmmmmmmmmdddmddddddddddddhhhhhmmddddddhhhhddddddhyso+///////:://+syhhddmmmmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNmhdmmmds:-/oyddmmNNNNNmhdmmmmmmmmmmdddddddddddddddddddddddddhhhhhhhhhhhhhhhhhyhhhhhhhhhhhhhhyyyyyhhhhyyyyyssssyyyyyyyyyhhhhddddddmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmddddNN
            MMMMMMMMMMMMMNNNNNNmho+//+++++++/////////://+oo+++osyhdNNNNNNNNNNNNNNNNNMMMN+:odmNNNNNNNNNNNNNNNNNNNmmmmmmmmmddmdddddddddddmdhhhhhdmdddddddddddddddddddhyo++ooyyhhhdmmmNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNNNNmddmmyo:-:+ydmmmNNNNNhddmmmmmmmmddddddddhhdddddhddyyyhhhyyyyssyyyyyyyyyyyyyyssyyyyyyyyhhhhhhhhhhhhhhhdddhhhhdddddddddddddddddhhdddddddddddddmmmmmmmmmmmNmmNNNNNNNNNNNNNMMMMMMMMNNNNMMMNNNNNNNNNNNNNNNNNNNNNmmdmmNNNNNmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmdmm
            MMMMMMMMMMMMMMMMNNdo///////////:::::::::::/osyysoosssssyhhhhdmNNNNNMMMMMMMMNhsymNNNNNNNNNNNNNNNNNmmmmmmmmdddddmmddddddddddmddhhhhddmddddddddddddddddddddddddmmmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmdhddy+-:+yddmmNNNmdhdhhddddddddddhhdddhhhdddhhdhyyyssyyyysssyyyyysyysssssssssssssyyyyyyyyyyyyyyyyyhhhhhhhhyyhhhhhdddddddddddddmmmdddddyo///oyhdddmmmmmmmmNNNNNNNNNNNNNNNNNNMMMMMNMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMms/:://::::::::::::::/+++oosyyyyyysooooso++oydmNNMMMMMMMMNNNNNNNNNNNNNNNNNNNNNmmmmmmmmdddddmddddddddddddddhhhdddddddmmdddddddddmmmmmmmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmddddhhhhhhhhyyhhhsooydmmmNmmdyddddddhhhhddddhhddhhhhhhhhddhyysssyysssyyyyyssssssssssssssssssyyyyyyssso++ossyhhhhhhhhyyyyyhhhhhhyyyhhyyhhhhddddddo-````.-+hddmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmmmmmNNNmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMNho/:::::::::----::/++ooossssyyyyso++osys++++oydNMMMMMNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmdddddmddddddddddddddddddddddddddddmmmmmmmmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNNmmmmddddddhhdhhhhyyyyhhyyyyyyhs+++syyhddddddddddddhhhhhddhhhhhhhhhhhhhdddyysssyyysssyyysssssssssssssssssyyyyyyyyo/:-.````.-/oyhhyyysyhhyyhhhyyyyhyyyyyyhhhhhyys.````..-/ydddmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmmNNNNNNmmddmmNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMNNMMMMMMMMMMMmy+::---------::///++oosyyssssyyyooosyhhyyyyhmNMMMNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmdddddddddhhhhdddddmmmmddddddddddmmmmmNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNmmddmmmmddddhyyhhhhyhhyyyyyysyhsdysssydy/.:oyhdddddmddddddhhhhhhdddhhhhhhhhhhhhddysyyyyyyyssyyyyssssssssssssssyyyyyyyyyyyso+/-``.``..-+shhyyyhhhyyhhyyyyyyyyyyhhhyyyyyyy-...--:/ohhhhhhddmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNmmmmNNNNNNNNNNNNNNNNNN
            NNMMMMNNNNMMMMMMMMMMMMMmy+:------::://+++++oossssssyyhhyossydNNNNNMMMMNNNNNNNNNNNNNNNNNNmmmmmmmdddhhhdddddhyyyyyhhhdddddddddddddmmmNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmmmddddddddyhdddddddhyyyyhhhyhhyyyyyysss-sdyssyyo:`.:shhyyyydhdhddhhhhhhhhhhhhyyyyyyyyyyyyoosssooooooossoooooosooossssssyyyyyyyyyyyyysso+oooossyhhyyyhysyhhhhyssssyyyyyhhyyyyyyyys/::/+oydddhhhdmddhhhhhhddddddmmmNNNNNNNmmmmmmmmNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMNNNNNNmmmmmNNNNNmmNNNNNNNNNNNNNNN
            NNNNMMMMMMMMMMMMMMMMMMMMMms::-::::::/+osso+++oosyyyyhhhddhdmNMMMMMMMNNNNNNNNNNNNNNNNmmmmdhyso+/::---:shyo/:/syyyyhhyyyhdddmmmNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmmmmddddddddhhdddddhhhhhdddhhyyyhhyyyhhhyyssssss-:dysyyoo:..`.:+yhdmmmmmddhso+/::::::-------------...................---------:::::////++++ooososssssyyyyssosysosyyhysssssyyyyyyyyyyyyyyyyyyyyhdddhhddddhhhyyhhhhhhhhhdddddmmNNNNNNNNNNNmmmmmmNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMNNNNNNNmmmNNNNNmmNNNNNNNNNNNN
            NNNNNMMMMMMMMMMMMMMMMMMMMMNho++///:::://+osooossyyhhdddmNNNNMMMMMMNNNNNNNNNNNNNNmmmdddy+:--.....-:+osyyo:--:osyyhhyyhdmmNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmmmmmmmmmmddddddddhhddhhhhddddhhyyhhhhysyhhssyhhhyssoooso/-ooso+/:.`` `.-+yhdddmmmddhhhyo:..............``````````````````````````````.................----::::////++ooooosssossssysssyyyyyyyyyyyyyyyyyyyyhhddhhhhhyyyyyhhhhhddhhhhhhdmdmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmmNNNNNNNNN
            NNNNNMMNMMMMMMMMMMMMMMMMMNNNmddddhs+/:://+osyyyyyyhmNNNNMMMMMMMMNNNNNNNNNNNmdhyo+//:----::::::--syyyyyyo:-:/oydmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNmmmmmmmmdddddddmmddddddddhyhdddhyhdddhhhhyyhhyssyysoooo+/:::----:++o+/-.`    ```-+syyyyhdddhyhddh:-:::::::::::////:-----------........-........````````````````............-----::///++oooossssyyyyysyyyyyyysssyyhyyyyyyyyyyyyyyhhhhhhhhyhddddddddhhhhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmmNNNNNN
            NNNNNMMMMMMMMMMMMMNNNNNNNmmmNNNNMMNNdyo++++ohddddmNNMMMMMMMMMNNNNNNNNNNNmy+/--......-:/oyyyyo//+yyyyysoooyhmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNmmmmmmmmmddddddddddddddddmdddddddhhhdddhyyhhhhyyso+++/:::--------------+soss+/:-......-/oyhhdhhhhddddddddhddyydddso+//hddhss+//::+sso+//+oosshddhs+ohhyyso+osoo+::-........```..........-------:-::://+++osssyssyyyysssssssyhhhhhhyyyyhhhyyyyyhhhddddhhhhhhddddhhddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMNNNNNNNNNNNNNmmNNN
            NNNNMMMMMMMMMMNNNNNNNNNNNNNNNNMMMMMMMMNmhyydmmmmNNMMMMMMMMMMMMMMNNNNNNNNd-....---/+oyhdhhhhysoosyyyyhhmmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNmmmmmmmmdddddddddddddddhhhddddddddmdddddhhhhyyso++//::-----------:::::///+++ooyyso+/:-......-/+osyyhhhhhhhddyhdhhddddddhyhy::hddyssoo+::o+:-:/+sssyhdddy--ydddh+-/ddddyso+/::osoo+//////::::----....-----------::://++oosshhhysyyyyyyhhhyyyyhhyyyhhhhdddhhhhhhhddddhhhddddddddddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMNNNNNNNNNNNNmmN
            MMMMMMNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMNNNmmmNNNMMMMMMMMMMMMMMMMNNNNNNN+...--/shhhhhhhhhyysyhhdmmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNmmmmmmdddmmmmmmddddddddddhhhdddhhhdddddddhhyso+//::--------:::://////+++++/oosydhyhhhsoo+:-``..-://+syysyyyyhhhdddddmmdhyhhhydds/.:hdhssso+:.:/.-++:./sshdddh:-yddmdo-+dmdhysooo+--++::++::ssyydmmddhysso++/::--------:::///+++++++oossyyyyyyyhhhhhyyyyydhhhhyyyyyhhdddddddddddddddddddddmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMNNNNNNNNNNNm
            NNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNmmmh/---:+yhhhyyyyyssydmmNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNmmmddddddhhhhddddddddhyhddddddhhhhhhhhyyso+//::-----::::////++oo++o+///+ossso:-/sssyooo+o////:.`````.-:/+ossyhhhdddhhhddddhhhdhyyhddh:/hdysooso/-/-.oso--+shdddy:-ydmdd+-odmdhysso/--+/--+ss/./syhmmmmmyooys/ymmmddhyo+//::::::::///+/////++++oosyhhyyyyyyhddhyyyyyhhhddddddddddddddddhddddddmmmdddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMNNNNNNNNN
            NNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmmNNmdhyo///oyysoosyhddmNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNmmmmdmmdddddhhhdddhhhhhhhhdddyyhddddhhhyo++/:::---::::///+++osssssoosddhys++++-:sso//:-+ssyyys+/-.-.```      ```.-:/+oossssssyhhhhhhhyhs:/+ooyyyo+-:///+o/-////osyddhs/-sdddy/-sdddysssss+-::-/sso:-+yhdmmmmms./hy++hmmmmmmhyssoossso++//:::::///+++++++++osssyyhdhyyyhhhhhhhhhhhhhhdddddddddhyyydddmmdddddddmddmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMNNNNNNN
            NNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNmmdhyyyso+/oyhmNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNmmmdddddddddhhhhhhhhhhhyhhhhhyyhdhhyyso+//::::::::////++ossyhhsydmd/+ooo-ymdhssss+--://:/:..:+sysyyyso+:-..```````.-:/+osyhhhyyhhdddhyhyhhhy:---...----...........---::://///+oo+++shhso::++++o+.+so/:+shdmmmmhso+..ohdmmmmmmhyoooo:.:yyysoossso+///:////++oooooooossyyyhhhhyyyhhhhhhhhhhddddho//+osydddddddddddmmdddddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmdys++ohmNNmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNmmmmdddddhhyhddddyddhhhhhhhhhyyyhhyoo+/:::::::://+++++++++osyhdmdy+-+dmdmmmd:+mmdhysssso/-/++o+-:osyys+///:----..-----:/+osyhhhhhyhhdhddhyhhyhhy+/:::-:o+::----.......-/o//::-----------------:://++//++osydmmmmd//ydd:-hmmmmmdhyyyyys+:/ssooo:.+yyyyhmdhyo++//+++oooooooo+ooosyhhhhhhhhhhhhhhho:``-+yhdddddddddddddmddddddmmdmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNmmmmNNNNNNNNNNNNNmmmmddddmNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNmmmmmddddhyyyhhdhhddhyyyyyyyhhhyso+//::::::://++++oooossso:::+ssyydmmmy::ymmmmd+:dmmdhyo////+oo++////oyyso/:--.....-/+ossysssyhdhydhhyhddddhyhhyhyyyyss++yys+++////:::::+yhhsoo+o++/////:+++/://///::::::::::+osyhdd+ossoymmmmmdhyysoo++osyyso++++syyhmNNmhyymNmdhso+++++/++++ooo+oossyhhhhdhhhh+.`.:/oyhhhhddddddddddddddmmddddmdddhhdmNNNNNNNNNNNNNNNNmNNNNNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmmNNNNNNNNNNNNNNNNmmmmmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNmmmmmddddddhsoyyyhhhhhyyyyyyysso++//::::::/+++ossyssys/::::/oo----::+syhdmmd+-oddmmy:yddhyo+////+++ooooo++yyyo+:--......:osysysysyhdhydhhyhhdhdhyhhyhyhydhs/yhysssoooooo+//sdddhyyyyyyyyys+oyyyyoo+++ooo+//:///+//////://+osyhdmmdy+:-:+ossyyyyyo.-oyyhdmNNNh+/sdNNmdhhdmdyso++///+++ooooooosyyhdhs. `-+ssyhhddhhddddddddddddddddddddddhhhddmddmNNNNNNNNNNNNNNmmmNNNNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmmmNNNNNNNNNNNNNNNNNNNmmmmNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNmmmmmmmmdddddhhyhyyyyyyyyyysso+//::::::/++oossyhdmmmmmdhs/syss:-sssssso/:oyydmmd+/osysooo+oo+/:/osssssoooosssyyys+/:-......:+sssyyssyhhhydhhyhhddmdyyhyhyhyhy/oyyyyssoooooo//ydddhhhhhhhhhs+oyhhyyyssssssss++osyyysoo+o+++++++///:://+ooo+///-oyso+/+yhdmNNNho/odmhs+oshds:mNNmdysoo+++///++oooooossyssyyhhddddddddhhhhhddddddddddddhdddddhhhhhhhhhhdmNNNNNNNNNNNNNNmmmNNNNNNNNNNN
            MMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNmmmdhydmNNNNNNNNNNNNNNNNNNmmmmNNmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNmmmmmmmmmmddddhhhhhhhyyyysso////::::/++oosyhdmh/////sdmmmmdhyyyyo:sss+o+++:ossooooooosyyhhyyssso+//+oyyyyyyyyyyyyyso/:--.....-+oosssossyyhydhdyhhdhddyyhyhhhyyds+syys+/////::---oyhhyooooss++yyyyyyyyyyyyso+oyhdddddhhddddhhhyo+++//-:://///+oooosssyyhmNNNho/odmh+/ohmmdo/ommdhyyyyyyysoo++///+oosssssssyhdddddddddddhhhhhhhhhhdddddddddhhhhhhhhdddddhdddmNNNNNNNNNNNNNNmmNNNNNNNNN
            MMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmdddyyhdmNNNNNNNNNNNNNNNNNNmmmmNNNNmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNmmmmmmmmmddddddddddhhhhhyyssooo++///+oooooshmmmmmmhommmh+/mmmmmmdhyy+:::::+///+++++/::+shhddddmmmmmmddyo//syyyyyyyyhhhys+/:-.....-/+osoossyyhhhhhdyhhdhddhyddddhhhddooooo+/////::---:/+oo+/////////+osssssyso+shdmmdhhyyhhhhhhysoosssso+//////////////+oymNNhs:+hNms/ohmmho/+yddhyyyyyyso++oyyysooo++/+oossssssssyhddddddddhhhhhhhhyhhhhhhhhhhhhhdddhhddddddddddmNNNNNNNNNNNNNNmmmNNNNMN
            MMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNmdsshdmNNNNNNNNNNNNNNNNNNNmmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNmmmmmmmmmmmdddddddddddhhysssooo++++oossssssyyyyhdmmmmmmmmmmd/dmdyhmmmdho/++++oossysso+//:://ohmmmmmmmmmmmmdy+/syyyyyyhyhhyyso+//:::/+osyyyyhyhhddhhddhyhdddmdmNmNNdhyyhyddhyyyso+os++ss+oyhdddhyosyyso+osyysoo+osyhhdhysyhhhhyooosyyyyyyyyyyysssso+/:////-:/+oshdddNm/odhso+syhhyyyyyys/-:sso//osyyyyssooo+/+oooossssosyhddddddhhhhhhhhhhhhhhhhhhhhhhhhhhhddhdddddddddmNNNNNNNMMNNNNNmmNNNM
            MMMNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmhmNNNNNNNNNNNNNNNNNNNmmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmmmmmmmmmmmmmddddddddddhhysooooo+++oossssyyyyy/::+syyyyhdmmmmmmmm/+//+sdhys+/:/osyyyyyyyyyyyyyso+/::ohmmmmddhsossssyyysssoyyhhysssoo+///+/osyyyydhhhddhhdddddmNNNNNNmmmmhhhhhhyyyssssssssoo++++++osssooyhddhsydmdhyyhyssyssyyyyyo/+syyyhyyyyyyyyyyyssooossss++/::/+++++oyddhhhdddhyyyyyyyyyy:.:yyyyyyyyyyyhhddysoo+//+osssssssyhddddddhhhhhhhhhhhhhhhhhhddhddhhhddddddhddddddmNNNNNNNNMMMNNNNNNN
            NNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmNNNNNNNNNNNNNNNNNNNNmmmmNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmmmmmmmmmmmmddddddhhhhyssooooo++ossssyyy+////+syys+::+syyyyhdmmmmmyyysssssyso/-:://+oyyhhhhhhyyyyyyso+ohhhhyyssoosssssssssyo/o/ooo+/::-::::/ossyyhhhhhhhhhhhhdmmmddddddddddddhNNNmmmmmddddddddddddhhyyyssssoooooossoooo+++//oyyssyhhhyyyyyyyyyysoooosyyyyhhhdddhyysoooooo+++oyhhyyys+syyyyso//oyyyyyyyyhhdmmmdmNNdysooo++ossssssyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhdddddhhdddddddddmmmNNNNMNNMMMMNNNNN
            NNNNNNNNNNNNNNNNNNNNmmmmmmmNNNNNNNNNNNNNNNNNNNNmmmmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmmmmmmmmmmmmddddddddhyssoooooooossyhdmmdhyy/oyyso//yyyys+::+ssyyyhhysssyhhhhhhhhhhysoo+/:/+syyhyyyysyyhhhhhhhyyhdddhhyyyoosyyyso+/:---..```````.-::://+oo+sssssyyyyyyhhddmmmddddmNNNNNNNNNNNNmNNNNmmmmmmmmddddddhhhhhys+/::::-:://++syhdmmmdyyso++oyhddddmmmmmmmmmmmmddhyo+/++/-:/+osyo/+ooo+osyyyyyyyhhdmNmdhhh/-/NNNmhsoooo+osssssyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhddddddddddddmdddddmNNNMMMNMNNNNN
            NNNNNNNNNNNNNNNNNNNNmmmNmNNNNNNNNNNNNNNNNNNNmmmmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmmmmmmmmmdddddddhhysoooo+++ooosyydmNNNNNNNNmhyyyyyy++yys+syo/+ooo++//+osyddmmmmmmmmmmdddhhs+//yyyyyysyyysyddddhshddhhhhhhhhddddhysso+/-..``````` ``````..-:/+syyhhhdddddmmmmmddddmdmNNNNNNNNNNmmmmNNmmmmmmmmmmmmmmmmdddhs+:--.-/++oooyhyysyhhhhysosyhdmmmmmmmmmmmddhyssoooooo++/::///++osyyyyyyyyyyhddmNNNNNNmdy+/smNNNNNNdysoooossssssyyyyyhhhhhhhhhhhhhhhhhhhhhhhhddddddddddddddddddddmNNNMMMNNMMNN
            NNNNNNNNNNNNNNNNNNNmNNNNNNNNNNNNNNNNNNNNNNNmdddmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmmmmmddddddddhyso+++++oooosyhmNNNs+ydmNNNNNNNmdhyyy/+::/osoooossos+::////+oshdmmmmmmmmdddhhyyyysyyydddysddhhhhhhhdddmmmmmmmddddhyyyyso+::::----::://+oosyhddddmmdddddddmmmmddmmmNmmNNNNNNNNNNNNNmmmmdhddmmmmmmmmmmmmmmmmddhs++osyhdddddddhhhyyyyyyyysyhdmmdhyssooossoososssssssoo++++o++osyyyyhhdddddddddhyyyhdmmmddhyyymNNmhsoooosssssssssyyhhhhhhhhhhhhhhhhhhhhhhhhddddddddddddddmmmmmmNNNMMMMNNMM
            NNNNNNmmmddddddmmNNNNNNNNNNNNNNNNNNNNNNNNNmmmmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmmmmmmmmmmddddddhyso+++++oooosyhmNNNNNNNy+sooydmdmNNNNNmdsooooosyyhhyyyysssoo++///::/+shddhyyyyysysyysyhdddhhhhddddmmmmmmmmmddhhhhhddhhhyysoo+/+oo+osyyyhhdddddmmddddmmmddmddmmmmmmNNNNNNNNNNNNNNNNNNmNNNNmmddddddmmmmdddddmmmmmmmmmddddddddddhyshdddddddddhyss+/+ossyyyyyyyyhhhhhhyyyyysso++ooo+ohmNd+::ymmmmhshhhhhysoooshmmNNmmdhssssoooosssssyyyyhhyyyyyhhhhhhhhhhhhhdddddddddddmmmddddddddddmNNNMMMNN
            mdhyso++/////+ymNNNNNNNNNNNNNNNNNNNNNNNNNmmmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNmmmmmdddddddddhysoooo+ooossssyhdmmNNNNNNNNdsdds://+dmNNNNdyo/+oyyhhhhyyyyyyyyyyyyyssoo+shddhyyssyhyyyyhhhdddmmmmmmmmmmmmddhyyyyyhhhddddhhhyyyysoo++-:+osyyyhhhddddddddmmddddmdmmNNmNNNNmNmmmmmNmNNNNNNNNNNmmmmmdddddddmddddddddddmmmmmmmmddddhyssyyhdddddddddddhyooyhhhhhhhhhhhhhhyyysssssooo++//:/+shmNh++ydmNs::yyssyhdmNNmmdhhyyyyyyssssooossssyyyyyhhhhyhhhhhhhhhhhddddddddddddhhddddddddddddddmNNMMMMM
            +/////:///+oymNNNNNNNNNNNNNNNNNNNNNNNNNmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmmmmmmddddddddhhysooo++oossssyyssssyhhdmmNNNNNmyoshmmdyhmdysoos+//////+++ossyyhhyyyyyyyyhdmmmdhhhyyhhhddddmmmmmmmmmmmddhyso+++oyhdddddddddddhhyyysoo++--/+osyyhhdhhdddddmmmddmmmmNNNNNNNNNmmmmmmmmmmmmmmmmNNNNNmmmmddddddddddddddddddddddddmmmmmdhhhddddddddddmmmmmmdyoosyhhhyyysssooooossyysyysso/:-:/+oshmNNNmdyso+/+mNNmddhhyyyso//osyyyyssss+oosssyyyyyhhhhyhhhhhhdddddmmmddddddddhhhhddddddddddddmmNNNMMM
            ////+++oshdmNNNNNNNNNNNNNNNNNNNNNNNNNmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNmmmmmdddddddddhyyssooooossssyyys/oso++//+oyhddmNNNNNNNNmhyyhhhyyhssooo++++++//://+syyhdhhdmmmmdhhhhdddmmmmmmmmmmmmmdhyoo++osyhhdddddddddddddddddhysoo+++:-:/+osshhdhddmmmmNNNmmmmNNNNNNNmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmhsoso+oosysyyyyhhhhhhhdddddhhyo/+sssshNNmhdmmmddhhhyyyso++++ossyyyyyyyyyys++ossssyyyyyhhhhdddddddddddddhhhddddhhhhyyhhddddddddddmmmNNMM
            oosysyhdmNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNmmmmmmddddddddhyyyyssooossssyyyyyyyo//+osso/://oyyhhdmmmhyyhddmdmmmmmmmmmdddddddhhsooydmmmdhhddddddmmmmmmmmmmmmmmdhyso++osyhddddddmmdmmmdmmmdddddhhhhhhysss+++ossyyhdddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNmmmmmmmmmmmmmmmmmmmmmmmmmmddddddmmmmmmmmmmmmmmmmmmmmmmNNNNNNNmmmmNmmmmyooshddmmmmmmmmmmmmmmmmmmmmmdhyoossosdmmdhhhyysoo+++oossssssooosssyyyyyyyo+osssssssyhdddddddhhhhhhhhhhhhhhhhhhhhhhhhhhdddddddddddmNNM
            syssydmNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNmmmmmmmdddddddhysssssoossyyyyhyyo/++oosssoo+oosyo:+yyyysoo+osyyyhhddmmmmmmmmmmmmmdhyydmmmdddddddmmmmmmmmmmmmmmmmmdhyyyhhhddddmmmmmmmmmmmmmmdddddddddhyyyyssoo+/::/osyhhhdddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddhhhhddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNmysoydmmmmmmmmmmmmmmmdddddhhhyyso+o+/oyyyy+//++ossso++//::+oosssssoyhhyyyyo++ossssyyyyhhhhhhhhhhhhdddhhhdddhhhhhyyyyyyyyhhhddddddddmN
            +oydmNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNmmmmmmmmmdddddhysssyysoosyyhdmmddhhyyyyso++++ossyyyyo+yssoosyo:::::::::://++osyhhdhyyhdddddddddmmmmmmmmmmmmmmmmmddmmddmmmmmmmmmmmmmmmmmmmmmmmddddddmmmddhysysso+/:-.-+oyyhhhddmmmmmmmmmmmmmmmdddmmmmmmmmmmmmmmmmmmmmmmdddddhhhhhhddddhhhhdddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNmNNmdsssdmmddhhyyssooo+oooooooooooo+//:++syyyoyys++++ossso/-oyyyyyhhhddmmmhyys++ossyyyyyyddhhhhhhhhhhhhhdddddhhhyyyyyyyyyyyyhhhddddddmN
            ydmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNmmmmmmmmmmdmddddhyysssysssyyyhmNmssmNNmmmddhhyyysoo+/+oyysosyyhhyso++++++++++++///:::oyhdddddmmmmmmmmmmmmmmmmmmddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddmmmmmddhhhhhyyo+/-...:+syhhyhddmmmmmmmmmmmmmmdddddddmmmmmmmmmmmmmmmmmmmmmdddddhhddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhyyo++++++ooooooooosssssssssso+/:/+osyyys:+ossso++/+oyhhhddmdmddmNNNmhyys+osyyyyyyyhhhhhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhhdddmmmm
            dmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNmNmmmmmmmmmmmmddddddhyyyyysosyyydmNNmo:sddhyyyyhddmmdhhhyssyssyhhhhhhyyyyyyyyyyyyyyyyysooydddddmmmmmmmmmmmmmmmmmdhhhhddddmmmmmmmmmmmmmmmmmmmmmmmdddddddmmmmmddhhhhhhhhhyo/:-..-:osyhyhhdmmmmmmmmmmmmmddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddmmmmmmmmmmmmmmmmmmmddddmmmmmmmmmmmmmmmmmmmyhyyyyyyhhhhhhhhhhhhhhhhhhhhhyys+/oooyyyoooooosyhddmmNNNNNNmmh+:oNNNmhyyoosyyyyyyyyhhhhhhhhhhhhhddddddhhhhhhhhhhhhhhhhhhhhhdddmm
            mNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmNNNmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmmmmmmmmmdddddddddddhhyyyyyyssyyydNNmNNNNdhs+oyhhdhhyyydNNmmho+oyyyyysssssyyyyyyyyyyyyyssshdddmmmmmmmmmmmmmmmmddhyo+/ohdmmmmmmmmmmmmmmmmmmmmmmmmmddddddmmmmmmddhhhhhhhhhhhhso///::-+syhhyhdmmmmmmmmmmmdddddddddddddmmmmmmmmmmmmmmmmmmmmmddddddddmmmmmmmmdddddmmmmmmmmmmmmmmmddhhhhhdddddddddmmdddddmdhhyhhhhhhhhhhhhhhhhhhhhhhhhhhhys+/oooyhhhhhdmmNNNNNmsshddhysooydNNNNdyyyssyyyyyyyyhhdddhhhdddhhddddhhhhhhhhhhhhhhhhhhhhhhhhhhdd
            NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmNmmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNmmmmmmmmmmmmddddddddddddhhhyyyyhysyyyydNNNNoosyhhdmmNNNNNNNmdy/mNdyosy+//:::--------::::///+ooohdddmmmmmmmmmmmmmmdhhhyyssyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmdmmmmmmmmmddhhhhhhhhhhhhhhy+:::-/.:oyhhyhddmmmmmmmmddddddddddddddmmmmmmmmmmmmmmmmmmmmmdhyyyhhhhhdddddddddddhdmmmmNNNNmmmmmdhhhhhhhyyyyyyyhhhhhhhhhhdyhyyhhhyyyyyyyysssssssssssssssso+://+smmmo/yNNNNmdy+/+hmmmmddhhsymNNNhyhyssyyyyyyyyhdddddddddddddddddhhhhhhhhhhyyyyhhhhhhhhhddm
            NNNNNNNmmNNNNNNNNNNNNNNNNNNNNmmmmmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNmmdso+///+oyhdddddddddhhhhhhhyhyhyyyyhhyhdmNNNNmNNmdhyysssyhdmmhsydmysyyhhyo+/++++++++++oo+oooo/+sdmmmmmmmmmmmmmmmdyo++oshdddmmmmmmmmmmmmmmmmmmmmmmmmmmddddddmmmmmmmddhhhhhhhhhhhhhhhhhys+:---:oyhhyhddmmmmmmmddddddddddddddddmmmmmmmmmmmmmmmmmmmmmdhhhhddhhhdddddddddddddmmmmNNNmmmmmddhhyhhhhhhyyyyyyyyyyhhhhmooso+++++++++++++++o+oooooooooo++/:-+odNNyshyyyyyyhdmmmNNNNmmds:/hNNNdyyhssyyyyyyyyhhhhhdddddddddddddhdhhhhhhhhhhhhhhhhhhhhddmm
            mmmNNNNNNNNNNNNNNNNNNNNNNNNNmmmddmMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNmmmmd+-..```.-/+osyhhhhhhhhhhyyyhhyyyyhyhhhhyyyhhddmmmNNNNNmdhys+smmhshdddmmmdhhhhhhhhhhhhdddddhooymmmmmmmmmmmmmmdhysssoooosyddmmmmmmmmmmmmmmmmmmmmmmmmdddddmmmmmmmmdddhhhhhhhhhhhhhhhhhhhhyyysssysyhhhddmmmmmmmmdddddddddddddddddddddmmmmmmmmmmmmmmmmmmdddddhhddddddddddddmmmmmNNNNmmmmmmmddhhhhhhhhhhhhhhhhhhhhd++oshhhhhhhhhhhhhhhhhhyyyysssssoo/--/oyNNNhsyNNNNNNmh//oyyssssydmNNNNdyyhyyyyyyyyyyhddddddddddddddddddddhhhhhhhhhhhhhhdddddmmNN
            mmmNNNNNNNNNNNNNNNNNNNNNNNNmmmddmNMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmmdddysooo+++osyhhhhhhhhhyyhhyyyyyyhhyhhhs//++++oosyyhhhdddmmNNmNdsydmdmmmmmmmmmdddmmmmmmmmmmyoohmmmmmmmmmmmmmddhhhhyyssyyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhhhhhhhhhhhhhhdddddyhdmmmmmmmmmmmmddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNmmmmmmmddddhhhhhhhhhhmd++osmmmmmmmmmmmmmmmmmmmmmmmmmmmmddyo/osmNm++hmddhyso+shmNNNNNmmmdddhhhyshyssyyyyyyyhdmmmmmmmmmmmmdddddddddhhhhhhhhhhhhdddmmNNNN
            dmmmNNNNNNNNNNNNNNNNNNNNNNNmmmddNMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNmddhyyyyyyyyyhhddddhhhhyyyhhhyhhdhhhhhhs/+yyyyysooosyyyy++shhhyosssoooo+++++++++++++++++ooooodmmmmmmmmmmmdddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmddmmmmmmmmmmmddhhhhhhhhhhhhhhhhhhhhhhhhhhddddhhdmmmmmmmmmmmmmmddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNmNNNNmmmmmmmmmdddddddmysssymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdy/+smNNNddhhhdddmmmdddhhhhhhhhhhhhhsshyssyyyyyyhhmmmmmmmmmmmmmdddddddddhhhhhhhddddddmmNNNNNN
            ddmmNNNNNNNNNNNNNNNNNNNNNNNmmddmNMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmmmmmmmmddhhhhhhhhhhhhhyyyhhhhhyhhyhhhyoooooosyyyyyyyssos+-:syysshys+////////////++//++++oo/++hmmmmmmmmmdddhhddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmddmmmmmmmmmdddhhhhhhhhhhhhhhhhhhhhhhhhhhhdddhydmmmmmmmmmmmmmmmmdddddddddddddddddddddddddmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNmmmmmmmmdsyyoshhhhhhhhhhhhhhhhddddddddmmmmmmdh/+odmmmmdddhhhhhhyyyyyyyyyyyyyyhhhyyhyyyyyyyhhhhdmmmmmmmmmmmmdddddddddhhhhhhhdddmmmNNNNNNNN
            hdmmNNNNNNNNNNNNNNNNNNNNNNNmmmmNMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmmmmmmmmmmddddddhhhhhhyyyyyyyhhdhyhhhh+:ossssoo//+++oooss+/yhyyyhddyo+oooooooooossssssyyyyo++ommmmmmmddhsooshdddddddddmmmmmmmmmddhdmmmmmmmmmmmmmmmmmmmmmmmmddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdddo+dmmmmmmmmmmmmmmmmddddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNmyyyyo/:::::::::::::::::::::://////++++/+shhhhyyyyyyyyyyyyyyyyyss+/osyhhyyyyysyyyyhhhhhdmmmmmmmmmmmmmdddddddddhhhhhddmmmNNNNNNNNNN
            hddmmmNNNNNNNNNNmmmNNNNNNNNmmmmNMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNmmmmmmmmmmmmmddddddhyhhhyyyhhdhhdhhhhhyyyhhhhyoyyyyyyys+syhyyhddddhyysyyyyyyyyyyyyyyyyyys/++hmdmmdddhhyhhddddddddddddmmmmmmdhyo/+hmmmmmmmmmmmmmmmmmmmmmmddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdddd/oddmmmmmmmmmmmmmmmdddddddddddddddddddddddddddmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNmhhhhyhyyyyyyyysssoo+oo++++++++++++++////oyhhyyyyyyysssoo+++//++++oosyyhhyyyysssyyhhhhhdmmmmmmmmmmmmmmmmmmddddddddddmmmNNNNNNNNNNNN
            hhddmmmmmmmmmmmmmmmNNNNNNNmmmmNNMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmmmmmmmmmmmmdddddddddddddhhhhyyhhhdhhdddddddddddhhhhhhhhhhhs+/shyyhddddhhyyyyyyyyssssssooooooo+/++dhyhddddddddddddddddddddmmmmdhyo:/ohmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdddohhdmmmmmmmmmmmmmmmmdddddddddddddddddddddddddddmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNmhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyssssoo+/:/yyhyo:////+++oossyyyyyyyyyyyyhhhyyyysyyyyyyyyhdmmmmmmmmmmmmmmmNNNNmmdddddmmmNNNNNNNNNNNNNN
            hhddmmmmmmmmmmmmmNmmNNNNNNmmmmmNMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmmmmmmmmmmmmmmmmddddddhhhhhhyyyhddhdddddddddddddddddddddddhhhhhssyyso+++//////////////++oooo+:/++ddddddddddddddddddddddmmmmmmddhhhmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyhdhyhhhdmmdmmmmmmmmmmmmddddddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNmdhhhyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyysosyhhyosyyyyyyyyyyyyyyyyyyyyyhhhhyyyysyyyyyyyyyddmmmmmmmmmmmddmmNNNNNmmddmmNNNNNNNNNNNNNNNNN
            hhhdddmmmmmmmmmmmmmmmmmNNNNmmmmNMMMMNMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNmmmmmmmdddddddddddhhhhhyyyyddhdddhsssoooo++++ooosyhhddddddyyyssossssssoosssyyyyyyyhhhhhhy///+ddddddddddddddddddddddmmdddmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhhhhhhhhhhhhhyhhhhhhhhhhhhyyhhsshsyhddhdmmmmmmmmmmmdddddmmmmddddddmmmmmmmmmmdddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyhhyso++osssyyyyyhhhhhhhhhhhhhhhhhhhhhhhyssyhhhyyyyyyyyyyyyyyyyyhhhhhhhhhhhyyyyyyyyyyyyyhdmmmmmmmmmmddddmmNNNNNmmmmmNNNNNNNNNNNNNNNNNN
            hhhhhhhddddmmmmmmmmmmmmmNNNmmmmNMMMNMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmddhhhhhhhyyhmhhmddyoossyhhdddhhhyyssoooyddhyhddyssyyyyyyhhhhhhhhhhhhhhhhhy/:-:hhdddddddddddddddddddhyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmddddhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyhhhhyhyyys+oyooyddyymmmmmmmmmmmmmmddmmmmmmddddmmmmmmmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyossosyo/::--........--:://++ossyhhhhhhhhhysyyhhhhhhhhhhhhhhhdddddddddmmmmNmhyyyyyyyyyyyyhdmmmmmmmmmmddddddmNNNNNNmmmNNNNNNNNNNNNNNNNNNN
            hhhyhhhhhddddmmmmmmmmmmmmNNmmmmmNMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNmmmmmmmmmddddddddddhhhhhhhhhddhdddddddhysoo+++++++oooooosddyyddmdhhhhhhhhhhhhhhhhhhhhhhhhyo----ohhddhhhddddddddddhsosddmmmmmmmmmmmmmmmmmmmmmmmmmmdddddhhhhhhhhhhhhhhhhhyhyyyyyyyyyyyhyyyhhhhyhyo//o//shdssdmmmmmmmmmmmmmddddmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyooooosdmmmmddhysso++///::---........-::/+oosshddhhdmmmmmmmmmNNNNNmdhy+/+hNNmdyyyyyyyyyyyyhddmmmmmmmmmmddddddmNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            hhhhhhhhhhhdddmmmmmmmmmmmNNmmmmmNNNMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmdhhhhhhhhhhdhhmdddddddddddddddddddddddddddyhdmmdhhhhhhhhhyyssoo++++++++++/:--.-shhddhyhdddddddhysydmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyhhhhhhhys/:/::ohds+dmmmmmmmmmmmmmddddddmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhoooosydmmmmmmmmmmmdddhhyyssoo++///:::-:::---/sdNNy:-+ssyyhdddmmmmddhys+::+hNmdyysyyyyyyyyyhddmmmmmmmmmmmdhddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dhhhhhhyyyhhhdddmmmmmmmmmNNmmmmmmmNNMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmdhhhhhhhhyddhmNNNNNNNNmmmmmmmmmmmdddddddddyhmmdhyso++++++++osssyyyhhhddddds:--..shhddhhddddddhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyhhhhhyy+::::+hdy+ddmmmmmmmmmmmdddddddddddmdddmmmmmmmmmmmmmmmmmmmmmmmmmdddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdysooooyhdmmmmmmmmmmmmmmmmmmddddhhhyyssooo++/::+ydNNs:-+dmmmdhysoo+++++oosyhmmNmdyyyyyyyyyyyyhddmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            ddhhhhyyyyyyhhdmmmmmmmmmmmmmmmmmmmNNMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmddddhhhhhhhyydhhNMNdydNNNNNNmhyysssyyhhmNNNNmys++++osyhhyyyyhhhhddddmmmmmmmmmdo--...ohydddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyhhyyyysooosyhyshddmmmmddmddddddddddddddddddmmmmmmmddddmmmmmmmmmmmmmmmddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmhsooooo++osyhddmmmmmmmmmNNmmmmmmmmmmmmddddhhhhyssymNNms+/+osoo++++++++++++oshmNNmdyyyyyyyyyyyyhdddddmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            ddhhhhyyyyyyyyhhddddmmmmmmmmmmmmmmmNNMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmdddhhhhhhyyyydhhNNNNdyssyhdh//ydmmmmmddhyodNmyyddhyyyhhhddddmmmmmmmmmmmmmmmmmmd+--...+yyhhhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhyyyyyssyyhhdmmmmdddddddddddddddddddmdddmmmmmdddddmmmmmmmmmmmmmmmmdddddmmmmmmmmmmmmmmmmmmmmmmdhyoo++ossso/::-----://+syhddmmmmmmmmmmmmmmmmmmmmdhydmmhyssssyyhhhhddddddddhhyo+smNmhyyyyyyyyyyyyhdddddmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            ddhhhhyyyyyyyyyyyyyhhddddmmmmmmmmmmmmNNMMMMMMMMNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmmdhhhhyyyyyydhhNNNNNNNmhyso+++oosssssossymNmyydhddmmmmmmmmmmmmmmmmmmmmddhyysoo/-.....:oyydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhyhhhhyhhhddhhhhddmmmmddddddddddddddddddmmmmmdddmmmmmddddmmmmmmmmmmmmmmmmmdddmmmmmmmmmmmmmmmmmmmdhso++++osyyyyhhyyso+///:::---.--:/osyhdmmmmmmmmmmmdhhdNNy/+osssssssssoooooooossyhdmmdhyyyyyyyyyyyyhddddmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dddhhhhyyyyyysssssyyyyyhhhhdddddddddmmNNMMMMNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmdhyyyhyyyyyhhhmNNNho++oosssssyhhdmmmdy++yNNhyhmmmmmmmmmmmmmmddhyssooooooossssso+-....-/oyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhdddmmmmmmdddddddddddddddddddmmmmmmmdmmmmmmmmdmddmmmmmmmmmmmmmmmmddddddmmmmmmmmmmmmhyo++++++osyyhhhhhhhhhyyyyssoo++/::----...--:+oyhdmmdhhdmNNNmdhyyyssssssyyyyhhdddmmmmmmhyyyyyyyyyyyyhddmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            ddddhhhhyyyyyyyyssssssssyyyyhhhhhhdddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmhyyyhhyyyyyhhmNNms+/ydmmNNNNmmmddhhdh/-/mNmyymNmmmmmdhysoo+++ossyyyyyyyyyyyyyyys/-.....-+syhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhdddmmddddddddddmmmmmdddddddmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddmmmmmmmdys++////+osssyyhhhhhhhhhhhhhhhyyyysso++//::::::------:oyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyhhddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dddddhhhyyyyyyysssssosssssssyyyhhhhhdddmmmmNNNMMNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmdyyyhhyyyyyhhdNNNNmdddddmNNNNNNNNNmmdhsshmmhshdhso++++osyyyyyyyyyyyyyyyyyyyyyyyyyo/-..```.:+sydmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhdmmddddddddddddmmmmmmdddddmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddmmmmdhyso+////+++////+syyhhhhhhhhhhhhhhhhhhhyyyyssooo++//:::-:/oyhysossssssssssssssssssssosyhhhhyyyyyyhhhhhhhdddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            ddddddhhhyyyysssssooooooosssssyyhhhhhhdddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmdhyyyyyyyyshhyhddhhhhhhhhhhhhhhhhhhhhhyyyyyyso+osyyyyyysyyyyyyyyyyyyyyyyyyyyyyyyso+/--...```-/osyhdmmmmmmmmmmmmmmmmmmmmmmmddhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhyhhhhhhhhhhdddddddddmmdddddmmmmmmmdddmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhso+//////+ssyyyys+/::::/+osyyhhhhhhhhhhhhhhhhhyyyyyysssoo++oyhys+///////////////////////+yhhyyyyyhhhhhdddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dddddddhhyyyssssssoooooooosssyyyhhhhhhhhddddmmmmNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmdhyyyyyyyssyhyyhhhhhhhhhhhhhhhhhhhyyyyssssyysoohdhyyyyyyyyyyyyyyyyyyyyyyyssoo++oosyyyy+:-.``..-:/+syddmmmmmmmmmmmmmmmmmmmdddhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhddddddddmmmdddddmmmmmmmddddmmmmmmmmddddmmmmmmmddddmmmmmmmmmmmddhso+//::://+osyhdmmmmmmmdhso/:::--:/+syyhhhhhhhhhhhhhhhhhhyyyssyyhhyyyyysooossyyyyyyyyyyyyyyyyyhhyyyhhhdddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            ddddddddhhyyysssssoooooooosssyyyhhhhhhhhhhddddmmmmmNNNNNNNNNNNNNNNNNmmmmmmmmmmmmmddddhyyyyyyyysyyyyhhhhhyyysssyyyyso+++++++oossyysoyhhhhhyyyyyyyyyyyyyssoo++osyhhdddmmmmddhyo/-.`...--:/+syhhdmmmmmmmmmmmddddhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhddmdddmmmmmmdddddmmmmmmmdddmmmmmmmmmddddmmmmmmmdddmmmmmddhyso+//::::://+osyhddmmmNNNNmmmmmdhyso+//::--:/+osyhhhhhhhhhhhhhyyyyyyyyyyyyo+::+oo++oosyyyyyyyyhhhhhhhhhddmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dddddddddhhyyyysssssoooooosssyyyhhhhdhhhhhhhddddddddmmmNNNNNNNNNNNmmmmmmmmmmmmmmmmddddyyyyyyyysosyyyhhhs/:/ooosso+/:+sssssssso/+sysoshhhhyyyyyyyysoo++osyhddddmmmmmmmmmmmmmdddyo/-.....---::+oyyhddmmmmddddhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhddmmddmmmmmmdddddmmmmmmdddddmmmmmmmmdddmmmmmmmmdddhyysoo+/:::::::::://+ohdmmmmmmmmmmmmmmmmmmmmdhyso+///::--:/+syhhhhhhyyyyyhhs++++//::-:/+ooo++///+osyhhhhhdddddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            mmddddddddhhhhyyyssssoooosssssyyhhhhdhhhhhhhhhdddddddddmmmmNNNNNNNmmmmmmmmmmmmmmmdddddhyyyyyyyso++ssyhhyo+ossyyhyyyyyyyyyyyyyo++syysosyhhyyyso+++osyhdddddmmmmmmmmmmmmmmmmmmmdhyo/:-.......`.-:::/+osyhhddhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhddddddddddmmdddddmmmmmdddddddmmmmmmddddddddhyyso+//:::::::///++++/:::::+yhmmmNNNNNNmmmmmmmmmmmmmmmdhyso+////:---:+osyyyyhhhhyysss+//+oooooooo+++////+syddddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhhh
            mdddddddddddhhhyyyysssssssssssyyhhhhdddddhhhhhhhddddhddddddmmmmNNmmmmmmmmmmddddddddddddhyyssssss+:/osyhhhhhyyyhhhhhhhhhyyyyyyyyyyhhhysssso//+oyhddmdddmmmmmmmmmmmmmmmmmmmdhysooooossoo+/::-....``...-:///+osyyyyyhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhddmddddddddddddddmmmmmddddddmmdddddhysso+////:::::::://+++ooosyyyyyys+/:::/oydmmNNNNNNNNNNNmmmmmmmmmmddhys+////:::/oyhdddddddddddhhhhhhhhhhhhhyyyyyyhhdmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdyysy
            mddddddddddddhhhhyyyyssssssssyyyhhhhdddddddhhhhhhhddddhhhddddmmmmmmmmmmmmmmmmmmmmmmmmdddhysssssoo/-:oosyhhhhhhyyyyyyyyhhhhhhhhhhdddddddyooyddddddmmmmmmmmmmmmmmmmmmmmdhyooosyyyyyyyyyyyysso+/:-.````````....--:://+ooossyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhddmmdddddddddddddddddddddhhyyyso++//:::::---::::::://+ossssyyhhhhhhhhhyso+/::::+shmmmNNNNNNNNNNNNNNNNmmmmmddys+//+yyysoosdNNNNNNNNNNmmmmmmmmddddhddddmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhyyyh
            mmmdmdddddddddhhhhyyyyyyyyyyyyyyhhhddddddddddhhhhhhhhdddhhhhddddmmmmmmmmmmmmmmmmmmmmmmmddhysssooo+:.-+++oyhhysooooossyyyssooooosssyyyhhhhhyhhdmmmmmmmmmmmmmmmmmmmdhyooosyhhhhhyyyyyyyyyyyyyyyso+:--...`````````````....-::::///+++ooosssssssyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhyyyssssoo+////::----------::::::::----:/+oyyyhhhhhhhhhhhhhhhhyyso+//:-:/shdmmmNNNNNNNNNNNNNNmmmhyoossyhs++syhdmNNNNmmmNNNNNNmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhhdmm
            mmmmmmdddddddddddhhhhyyyyyyyyyhhhhhdddddddddddddhhhhhhhhhdhhhhhdddddmmmmmmmmmmmdddddddddddhyyssoo+/-`-/+::+o+/:--:/+oo+:--:osyyhhhhhhy+/odmdhhddmmmmmmmmmmmmmdhyooosyhhhhhhhyyyyyyyyyyyyyyyyso+//+sssoo+/:-..```````````````````````.....---::::///////////////+////++//::::::::--:----.-......-------::///+oooooo+oso+:--/oyyyhhhhhhhhhhhhhhhhhhhhyyo+//::-:/oydmNNNNNNNNNNNmmdyo/oyhdddhy++osyyhhhyysshmmmmNNmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmNNN
            mmmmmmmmdddddddddddhhhhhhhhhhhhhhhdddddddddddddddddhhhhhhhhddddhhhddddddddddddddddddddddddddhyssso+/-`-//--:/::---://+/:::+yhhyysssossoosddmmddhhddmmmmmmdhyo++oyhhhhhhhhhyyyyyyyyyyyyyyyso+++sydddmmmdddhhyyso+/:--..``````      ````` `````````````````````````````````````````........-------://+osyyyhhdddmmmmmmmmmho/::/oyhhhhhhhhhhhhhhhhhhhhhhyso+///::--/ohdmNNNmmmmdhys+//++shdhdmdhhyyyyyyyhhddmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmNNNNNNNN
            mmmmmmmmdddddddddddddddddhhhhhhhddddddddddddddddddddddhhhhhhhddddhhhhhdddddddddddddddddddddddhyyssso/-.-//:--:///++oooo++oosss+:::/+oyhddmdhoohmdhhhhdhyo++oshhhhhhhhhhyyyyyyyyyyyyyyyys+++shdmmmmmmmmmmmmmmmddddhyo::////::--.......`````````````````````````````````````.....--:://///////+/:-:oyddmmmmmmmmmmmmmmmmmmmdyo/::/oyhhhhhhhhhhhhhhhhhhhhhyosso+/::::--/ohdddhhhhhys++o+++ooshdmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmNNNNNNN
            mmmmmmmmmmdddddddddddddddddddddddddddddddddddddddddddddddhhhhhhdddhhhhhhdddddddddddddddddddddddhyysso+:::/+/:-:/ossso/::/ooosoo+/+syhdmNNNNdsshmmmdhys+/oyhhhhhhhhhyyyyyyyyyyyyyyyyys++oshdmmmmmmmmmmmmmmmmmmmmddy+/+syysssssoooo++++++////-.-:::///////////////++//-.-::://+++oosssyyyysyyyyy+:-/ymmmmmmmmmmmmmmmmmmmmmmmhs+/::/syhhhhhhhhhhhhhhhhhhhhyyyyyso/::::::+yyhdddddhhhdmmdddhhhddmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmddmNNNNNNN
            mmmmmmmmmmmddddddddddddddddddddddddddddddddddddddddddddddddhhhhhhhddddddddddddddddddddddddddddddhhyysoo+//+++/::/+syyo++ossssyyyyyyhhddmmmdddhhhyssosyyyyyyyhhhhhyyyyyyyyyyyyyyyyso++shmmmmmmmmmmmmmmmmmmmmmmmdy+/oyhhhyyyyyyyyyyyyyyyssss+::shhhddddddddddddddddddho-:osssyyyyyyyyyyyyyyyyyyys+:-/hmmmmmmmmmmmmmmmmmmmmmmmdyo+/::/syhhhhhhhhhhhhhhhhhhhhhhhyysooosyyhhhhdddddmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmdhhdmNNNNN
            mmmmmmmmmmmmmmddddddddddddddddddddddddddddddddddddddddddddddddhhhdddddddddhhhhhddddddhhhyyyyhhdddddhhysssooooo+///+oshhhyysssssssssyyyyyyyyyyyyyss+/::+osyyyyyyyyyyyyyyyyyyyyyso++ohdmmmmmmmmmmmmmmmmmmmmmmmdy+/oyddhhyyyyyyyyyyyyyyyyyyy+::sdmmmmmmmmmmmmmmmmmmmmmdo-:syyyyyyyyyyyyyyyyyyyyyyys/--+dmmmmmmmmmmmmmmmmmmmmmmmmdy+//::+syhhhhhhhhhhhhhhhhhhhhhyhhhhhhdddddddmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhyyyhmNNNN
            mmmmmmmmmmmmmmmmdddddddddddddddddddddddddddddddddddddddddddddddddddddddddhhhhhhhhhhhhhhhyyyyyhddddddddhhhyyyyssso++++ossssssoooo++///+++oooosssssssoo+//+oyyyyyyyyyyyyyyyyyyo+/+ydmmmmmmmmmmmmmmmmmmmmmmmmdho/+yddhhyyyyyyyyyyyyyyyyyyyy+::odmmmmmmmmmmmmmmmmmmmmmmdo:/yhyyyyyyyyyyyyyyyyyyyyyyyo/-:odmmmmmmmmmmmmmmmmmmmmmmmmdho+/:::oyhhhhhhhhhhhhhhhhhhhddddddddmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNmNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhysssydmNNN
            mmmmmmmmmmmmmmmmmddddddddddddddddddddddddddddddddddddddddddddddddddddddddhhhhyyyyyyhhhhhhhhhhdddddmmmmdddddhhhhhhysssssoooossso+:--:+ssyyyyyyyyyyyyyyyyysso+//+syyyyssssss+//ohmmmmmmmmmmmmmmmmmmmmmmmmmmho/+ydddhhyyyyyyyyyyyyyyyyyyyyo//ydmmmmmmmmmmmmmmmmmmmmmmmd+:+hhhyyyyyyyyyyyyyyyyyyyyyys+:-:sdmmmmmmmmmmNmmmmmmmmmmmmmdhyoo+//oyhhdddddddddddddmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmNmNNmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhyyyyhdmNNN
            mmmmmmmmmmmmmmmmmmmmmmddddddddddddddddddddddddddddddddddddddddddddddddddddhhhhyyyyyyhhddddddddddddmmmmmmmmmmddddddddhyyysoosyyyo+//++osssyyhhhhyyysoo++///++ossyyyhhhhhhhsooydddmmmmmmmmmmmmmmmmmmmmmmmhs/+shddhhhyyyyyyyyyyyyyyyyyyyyo/+ymmmmmmmmmmmmmmmmmmmmmmmmmd+:+hhhyyyyyyyyyyyyyyyyyyyyyyys/::/ymmmmmmmmmmmmmmmmmmmmmmmmmmddyyyssydddddmmmmmmmmmmmmmmmmmmmNNNmNNNNNNNNNNNNNNNNmmmmmmmmmmmmmmmmmNmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhhhdddmNNNNN
            mmmmmmmmmmmmmmmmmmmmmmmddddddddddddmdmdddddddddddddddddddddddddddddddddddddhhhyysssyhhdddddddddddmmmmmmmmmmmmmmmmmmmmmddyyyyyyhhhhhyyhhhhhhhhyso++++oosyyyhhhhhhhddmmdddddhhhhhhhhhhddddmmmmmmmmmmmmmds//shdddhhhyyyyyyyyyyyyyyyyyyyyo/+ymmmmmmmmmmmmmmmmmmmmmmmmmmh+:+hhhyyyyyyyyyyyyyyyyyyyyhyyyo+//ohmmmmmmmmmmmmmmmmmmmmmmmmmmmmddmddmmmmmmmmmmmmmmmmmmmmmmmmmNNNNmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmdhhhdmNNNNNNNN
            mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdmmmmmmmdmmddddddddddddddddhhhhdddddddddddddddhhyssssyhddddddddddddmmmmmmmmmmmmmmmmmmmmmmdhdddddddmmmmdddddddhyyyyyhhhdddhhhhddddmmmdysoosyhhhysoydmddhhyyyyyhhddmmmmdy//ohdddhhhhyyyyyyyyyyyyyyyyyyyy+//ymmmmmmmmmmmmmmmmmmmmmmmmmmdy/:ohhhyyyyyyyhhhhhhhhhhhhhhhhhysooohmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmNNNNNNNNNN
            mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddhhhhhhddddddddddddhhysoooshhdddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddmmmmmmmmdyooydmmmmdyo+yddhyyhhddhhhyyyyhhhs++yddddhhhhhhhhhhhhhhyyyyhyyhhyo//ymmmmmmmmmmmmmmmmmmmmmmmmmmddy+/shhhhhhhhhhhhhhhddddddddddddddhhhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddhhdhhhhhdddddddddddhyyooosyyhdddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhdmmddhhhhddddhyysssyhhdddddddhyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyo+ydmmmmmmmmmmmmmmmmmmmmmmmmmmmdhsshdddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            dddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddhdhhhhhhhddddddddddhhysooossyhhdddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddmmmmmddddddddddddddddddddddddddddddddhyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
            yhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddhhhhhhhhhhhddddddddhhhyssoossyyhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNNNNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMM
            */

    /*
    1-albastru
    2-green
    3-aqua
    4-red
    5-purple
    6-yellow
    7-white
    8-grey
    9-lt blue
    0-black
    A-lt green
    B-lt aqua
    C-lt red
    D-lt purple
    E-lt yellow
    F-br white
    */
    return 0;
}
