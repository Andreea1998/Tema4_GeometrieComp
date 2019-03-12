#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>
using namespace std;
#define PI 3.14159265
struct punct{
    float x,y;
};

float calcul_unghi(punct A, punct B, punct C, punct D){
    float x1=B.x-A.x;
    float x2=D.x-A.x;
    float y1=B.y-A.y;
    float y2=D.y-C.y;
    float produs_scalar=x1*x2+y1*y2;
    float a=sqrt(x1*x1+y1*y1);
    float b=sqrt(x2*x2+y2*y2);
    float unghi=acos(produs_scalar/(a*b));
    return ((unghi*180.0)/PI); //transform radian in grade
}

float norma(punct A, punct B){
    float x1=B.x-A.x;
    float y1=B.y-A.y;
    return sqrt(x1*x1+y1*y1);
}
int main(){
    punct A,B,C,D;
    cout<<"A: ";
    cin>>A.x>>A.y;
    cout<<"B: ";
    cin>>B.x>>B.y;
    cout<<"C: ";
    cin>>C.x>>C.y;
    cout<<"D: ";
    cin>>D.x>>D.y;
    float unghi_B=calcul_unghi(B,A,B,C);
    float unghi_D=calcul_unghi(D,A,D,C);
    float angle=(unghi_B+unghi_D);
    cout<<angle;
    if(angle>179 && angle<181)
                cout<<"Punctul D se afla pe cerc."<<endl;
    else
    if(angle>180)
            cout<<"Punctul D se afla in interiorul cercului"<<endl;
    else{
                cout<<"Punctul D se afla inafara cercului"<<endl;
        }
    if((norma(A,B)+ norma(C,D))==(norma(A,D)+norma(B,C)))
        cout<< "Patrulaterul ABCD este circumscriptibil";
    else
        cout<<"Patrulaterul ABCD NU este circumscriptibil";
    return 0;
}
