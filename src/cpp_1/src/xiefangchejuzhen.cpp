#include<iostream>
#include "Eigen/Dense"
#include <Eigen/SVD>

using namespace std;
using namespace Eigen;
using namespace Eigen::internal;  
using namespace Eigen::Architecture;  
struct Point
{
    double x;
    double y;
    double z;
};

MatrixXf shujuchuli(Point p[10])
{
    MatrixXf m(3,1);
    m(0,0)=(p[0].x+p[1].x+p[2].x+p[3].x+p[4].x+p[5].x+p[6].x+p[7].x+p[8].x+p[9].x)/10;
   
    m(1,0)=(p[0].y+p[1].y+p[2].y+p[3].y+p[4].y+p[5].y+p[6].y+p[7].y+p[8].y+p[9].y)/10;
    m(2,0)=(p[0].z+p[1].z+p[2].z+p[3].z+p[4].z+p[5].z+p[6].z+p[7].z+p[8].z+p[9].z)/10;
    //cout<<m<<endl;
    return m;
}
MatrixXf jian(int i,Point p[10],MatrixXf m)
{
    MatrixXf q(3,1),z(3,1);
    q(0,0)=p[i].x-m(0,0);
    q(1,0)=p[i].y-m(1,0);
    q(2,0)=p[i].z-m(2,0);
    return q;
    

}

int main()
{
    MatrixXf n(3,1),l(3,1),p(3,1),q(3,1);
    MatrixXf a,b(3,3);
    Point p1[10]=
    {
        {53.3617,100.843,242.354},
        {132.529,145.62,275.242},
        {39.1834,145.603,206.53},
        {28.4663,92.4999,206.419},
        {45.4732,89.9758,149.867},
        {122.55,-38.0708,389.425},
        {164.699,-38.1067,308.317},
        {146.824,133.73,355.618},
        {149.4,-104.417,369.344},
        {141.244,276.988,352.2}
    };
    Point p2[10]=
    {
        {685.505,190.434,470.767},
        {693.821,114.93,362.551},
        {590.363,211.248,350.075},
        {567.267,212.817,426.019},
        {489.725,158.972,302.617},
        {675.111,83.2033,525.216},
        {656.617,252.007,565.976},
        {602.549,32.9839,534.874},
        {649.104,333.586,482.071},
        {716.07,27.9724,647.56}
    };
    n=shujuchuli(p1);
    q=shujuchuli(p2);
    for(int j=0;j<10;j++)
    {
        cout<<"----"<<j<<"-----"<<endl;
        l=jian(j,p1,n);
        p=jian(j,p2,q);
        a=l*p.transpose();
        cout<<"a:=\n"<<a<<endl;
        //cout<<"-----------"<<endl;
        b+=a;
        cout<<"b:=\n"<<b<<endl;
        
    }
    JacobiSVD<Eigen::MatrixXf> svd(b, ComputeThinU | ComputeThinV );
    Matrix3f V = svd.matrixV(), U = svd.matrixU();
	Matrix3f  S = U.inverse() * b * V.transpose().inverse();
	//std::cout<<"b :\n"<<b<<std::endl;
	//std::cout<<"U :\n"<<U<<std::endl;
	//std::cout<<"S :\n"<<S<<std::endl;
	//std::cout<<"V :\n"<<V<<std::endl;
	//std::cout<<"U * S * VT :\n"<<U * S * V.transpose()<<std::endl;
    MatrixXf R(3,3),T(3,3);
    R=V*U.transpose();
    cout<<"R---:\n"<<R<<endl;
    T=-R*n+q;
    cout<<"T:= \n"<<T<<endl;
    //cout<<"T:= \n"<<T<<endl;
    //l=jian(0,p1,n);
    //l=shujuchuli(p2);
    //cout<<n<<endl;
    //cout<<l<<endl;
    return 0;
}
