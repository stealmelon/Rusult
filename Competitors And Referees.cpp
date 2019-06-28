#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#define Num 7
using namespace std;

struct Competitors{
    char Number[10];
    char Name[10];
    char Sex[10];
    int Class;
    char QQnumber[11];
    float Avgscore;
};
struct Referees{
    char Name[10];
    float Score[Num];
};
bool cmp1(int a, int b)
{
    return a>b;
}
int cmp2(const void *a,const void *b)
{
    struct Competitors *x = (struct Competitors*)a;
    struct Competitors *y = (struct Competitors*)b;
    return (x->Avgscore < y->Avgscore);
}
int main()
{
    int score[7];
    float sum = 0;
    struct Competitors Competitors[Num];
    struct Referees Referees[7];
    
    ifstream Competitor("/Users/s20181106115/Desktop/Competitor.txt");
    ifstream Referee("/Users/s20181106115/Desktop/Referee.txt");
    ofstream Result("/Users/s20181106115/Desktop/Result.txt");
    
    if(Referee.is_open())
    {
        //cout << "Succeeded!" << endl;
        for(int i = 0; i < 7; i++)
        {
            Referee >> Referees[i].Name;
            for(int j = 0; j < Num; j++)
            {
                Referee >> Referees[i].Score[j];
            }
        }
        for(int i = 0; i < Num; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                score[j] = Referees[j].Score[i];
            }
            sort(score, score + 7, cmp1);
            for(int k = 1; k < 6; k++)
            {
                sum += score[k];
            }
            Competitors[i].Avgscore = sum / Num;
            sum = 0;
        }
        Referee.close();
    }
    if(Competitor.is_open())
    {
        //cout << "Also Succeeded!" << endl;
        for(int i = 0; i < Num; i++)"
        {
            Competitor >> Competitors[i].Number
            >> Competitors[i].Name
            >> Competitors[i].Sex
            >> Competitors[i].Class
            >> Competitors[i].QQnumber;
        }
        Competitor.close();
    }
    if(Result.is_open())
    {
        qsort(Competitors, Num, sizeof(Competitors[0]), cmp2);
        for(int i = 0; i < Num; i++)
        {
            Result  << left << setw(5) << Competitors[i].Number << " "
            << left << setw(8) << Competitors[i].Name <<" "
            << left << setw(8) << Competitors[i].Sex <<" "
            << left << setw(3) << Competitors[i].Class <<" "
            << left << setw(13) << Competitors[i].QQnumber <<" "
            << left << setw(8) << setprecision(2)<< fixed << Competitors[i].Avgscore <<" "
            << endl;
        }
        Result.close();
    }
    return 0;
}
