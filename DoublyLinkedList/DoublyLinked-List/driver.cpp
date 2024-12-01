#pragma once
#include "implementation.h"

int main() 
{
	
	default_random_engine rd(time(NULL));
	uniform_real_distribution<double> dist(0.0, 0.99);

	
	default_random_engine dre(time(NULL));
	uniform_int_distribution<int> dis1(1000000000, 1000010000);
	

	
	mystructure my;
	set<int> isunique = my.uniquenumbers();

	
	for (const auto& num : isunique) 
	{
		int randomx = dis1(dre);
		double chtotaultra = dist(rd);
		chtotaultra = round(chtotaultra * 100) / 100.0;
		my.push(chtotaultra, randomx, "name" + to_string(num + 1 ));


	}
	

	
	my.push(0.76, 1090000065, "Tsu");
    my.push(0.76, 1000000023, "Iliauni");
	my.push(0.30, 1000000042, "caucasus uni" );
	my.push(0.30, 1000000053, "btu");
	my.push(0.20, 1000000041, "gau");
	my.push(0.56, 1000000031, "kiu");
	my.push(0.57, 1000000021, "sulxan kvernadze");
	my.push(0.58, 1000000011, "my");
	my.push(0.59, 1000000081, "ultra" );
	my.push(0.60, 1000000091, " evolution");
	
	
	cout << "I"<<"\n";	my.display(cout); cout << "\n";
	my.delete_Node(0);
	cout << "-----------------II delete ing node-------------" << "\n" << "\n"; my.display(cout); cout << endl;
	my.delete_Node(2);
	cout << "-----------------IIIdelete ing node-------------" << "\n" << "\n"; my.display(cout);  cout << endl;
	mystructure my1(my);
	cout << "-----------------IV copy ing node --------------" << "\n" << "\n"; my1.display(cout); cout << endl;
	my.delete_Nodes_from_front();
	cout << "-----------------V Delete From front --------------" << "\n" << "\n"; my.display(cout); cout << endl;



}