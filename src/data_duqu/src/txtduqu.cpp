#include <stdio.h>
#include <stdlib.h>
#include<string> 
#include<iostream>
#include <vector>
#include <sstream>
#include <unistd.h>
using std::string;  //使用string对象
using std::vector;  //使用vector
using namespace std;

//字符串分割到数组
struct XUJIN 
{
	double* v;
	double* p;
};
void Split(const string& src, const string& separator, vector<string>& dest)
{
	string str = src;
	string substring;
	string::size_type start = 0, index;
	dest.clear();
	index = str.find_first_of(separator,start);
	do
	{
		if (index != string::npos)
		{    
			substring = str.substr(start,index-start );
			dest.push_back(substring);
			start =index+separator.size();
			index = str.find(separator,start);
			if (start == string::npos) break;
		}
	}while(index != string::npos);
 
	//the last part
	substring = str.substr(start);
	dest.push_back(substring);
}
//string to double
void string2num(string str, double &num)
{
	std::stringstream ss;
	ss << str;
	ss >> num;
}
XUJIN stringtodouble(std::string nametopic)
{	
	XUJIN book;
	FILE * fp;
	char * line = NULL;
	const char * abc=nametopic.data();
	
	std::string s1,s2;
	size_t len = 0;
	ssize_t read;
	fp = fopen(abc, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	for(int i=0;i<2;i++)
	{	read = getline(&line, &len, fp);
		
		if(i==0)
			s1=line;
		else
			s2=line;
	}
	if (line)
		free(line);
	vector<string> Data1,Data2;
	
	string sh1[7],sh2[7];
	Split(s1,",",Data1);
	Split(s2,",",Data2);
	
	
	for(int i=0;i<7;i++)
	{
		sh1[i]=Data1[i].c_str();
		sh2[i]=Data2[i].c_str();
		
	}
	
    double* vel = new double[7];
	double* pos = new double[7];
	for(int j=0;j<7;j++)
	{
		string2num(sh1[j],pos[j]);
		string2num(sh2[j],vel[j]);
	}
	book.p=pos;
	book.v=vel;
	return book;
}  


int main()
{
	XUJIN p;
	//double* v;
	//double*p;
	//int t=1;
	for(int t=1;t<100;t++)
	{
	std::string f_str=std::to_string(t);
    string inputstring="/home/xu/Desktop/pcl_ws/play_1/"+f_str+".txt";
	p=stringtodouble(inputstring);
	cout<<t<<endl;
	for(int i=0;i<7;i++)
	{
		std::cout<<p.p[i]<<std::endl;
		
		std::cout<<p.v[i]<<std::endl;
	}
	
	//
	sleep(1);
	}

	return 0;
}