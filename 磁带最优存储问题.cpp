#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


struct Point
{
	int a;
	int b;
	long time()
	{
		return a*b;
	}
};
bool camp(Point p1,Point p2)
{
	return p1.time() < p2.time();
}
int main()
{
	int n;
	vector<Point> p;
	
	while (in>>n)
	{
		long sum = 0;
		double all = 0;
		Point temp;
		for (size_t i = 0; i < n; i++)
		{
			in >> temp.a>>temp.b;
			sum = sum + temp.b;
			p.push_back(temp);
		}
		sort(p.begin(), p.end(), camp);
		for (size_t i = 0; i < n; i++)
		{
			all = all + p[i].time()*(n - i)*1.0/sum;
		}

		out << all << endl;
	}

	return 0;
}