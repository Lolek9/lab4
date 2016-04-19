#include<iostream>
#include<cstdlib>

using namespace std;

string int2string(int n);
int counter(int n);
bool finderK(int n);
void convertNumber2Text( int n);

int main(int argc, char *argv[])
{
    int n=atoi(argv[1]);
    
    finderK(n);
    
    return 0;
}

int counter(int n)
{
    string slowo=int2string(n);
    int length=slowo.size();
    int helper=0;
    for( int i = 1; i <= length; i++)
    {
        if(slowo[length-i]=='0' || slowo[length-i]=='1')
            helper++;
    }
    
    return helper;
}

string int2string(int n)
{
    char stringi[255];
    itoa(n, stringi, 10);
    return (string)stringi;
}

bool finderK(int n)
{
    int k=1;
    do{
        k++;
        
        if(counter(n*k)==int2string(n*k).size())
        {
            cout<<"Wartosc K: "<<k<<endl;
            convertNumber2Text(n*k);
            return true;
        }
    }while(n*k<=99999);
    cout<<"Nie znaleziono K :( "<<endl;
    return false;
}

void convertNumber2Text(int n)
{

    string     units[]={"jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};
    string     teens[]={"jedenascie","dwanascie","trzynascie","czternascie","pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};
    string     tens[]={"dziesiec","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiecdziesiat"};
    string    hundreds[]={"sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset"};
    string    thousands[]={"tysiac","tysiace","tysiecy"};

    int tab[6];    

    for(int i = 0; i < 6; i++)
    {                    
        tab[i]=n%10;
        n/=10;
    }
    
    for(int i = 1 ; i < 10; i++)    
        if(tab[5]==i) 
            cout<<hundreds[i-1]<<" "; 
            
    if(tab[4]==1)
    {
        for(int i = 1; i < 10; i++) 
            if(tab[3]==i)
                cout<<teens[i-1] <<" ";
        
        if(tab[3]==0) 
            cout<<tens[0]<<" ";
        
        cout<< thousands[2]<<" ";
    }else 
    {
        for(int i = 2; i < 10; i++) 
            if(tab[4]==i) 
                cout<<tens[i-1]<<" ";
                
        for(int i = 1; i < 10; i++) 
            if(tab[3]==i) 
                cout<<units[i-1]<<" ";

            if(tab[5]==0 && tab[4]==0 && tab[3]==1 ) 
            {
                cout<<thousands[0]<<" ";
            }else 
            {
                if(tab[5]!=0 || tab[4]!=0 || tab[3]!=0)
                {
                    if(tab[3]>1 && tab[3]<5) 
                    {
                        cout<<thousands[1]<<" ";
                    }else
                    {
                        cout<<thousands[2]<<" ";
                    }
                }
            }
    }
    for(int i = 1; i < 10; i++)    
        if(tab[2]==i) 
            cout<<hundreds[i-1]<<" ";

    if(tab[1]==1)
    {    
        for(int i = 1; i < 10; i++) 
            if(tab[0]==i)
                cout<<teens[i-1] <<" ";
                
        if(tab[0]==0) 
            cout<<tens[0]<<" ";    
    }else 
    {
        for(int i = 2;i < 10; i++) 
            if(tab[1]==i) 
                cout<<tens[i-1]<<" ";
                
        for(int i = 1; i < 10; i++) 
            if(tab[0]==i) 
                cout<<units[i-1]<<" ";      
    }
}