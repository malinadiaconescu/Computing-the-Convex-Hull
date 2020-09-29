#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;
ifstream f("file.in");
ofstream g("file.out");
struct Punct
{
    double x,y;
    int contor;
};
Punct *p;
Punct pimp;
int n;
vector<Punct> s;
void afiseaza()
{
    g<<s.size()<<"\n";
    for(int i=s.size()-1; i>=0; i--)
        {g<<fixed<<setprecision(12)<<s[i].x<<" ";
        g<<fixed<<setprecision(12)<<s[i].y<<"\n";
                cout<<"P"<<s[i].contor<<endl;
        }
}
double CrossProduct(Punct P0,  Punct P1,  Punct P2){
    return (P1.x-P0.x)*(P2.y-P0.y)-(P1.y-P0.y)*(P2.x-P0.x);
}
void stangajos()
{
    for(int i=2; i<=n; i++)
    {
        if(p[i].x<p[1].x) swap(p[1],p[i]);
        else if(p[i].x==p[1].x&&p[i].y<p[1].y) swap(p[1],p[i]);
    }
    //cout<<pimp.x<<" "<<pimp.y;
}
bool functie(Punct A,Punct B)
{
    return CrossProduct(p[1],A,B)<0;
}
void graham()
{
    stangajos();
    sort(p+2,p+n+1,functie);
    s.push_back(p[1]);
    s.push_back(p[2]);
    for(int i=3;i<=n;i++)
    {
        while(s.size()>=2&&CrossProduct(s[s.size()-2],s[s.size()-1],p[i])>0)
            s.pop_back();
        s.push_back(p[i]);
    }
    afiseaza();
}
int main()
{
    f>>n;
     p=new Punct[n+1];

    for(int i=1; i<=n; i++)
        {f>>p[i].x>>p[i].y;p[i].contor=i-1;}
        //pimp=p[1];
    graham();
    return 0;
}
