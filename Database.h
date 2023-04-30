#pragma once
#include <iostream>
#include <string>
using namespace std;

class Database
{
private:
	static Database* instance;
protected:
	Database() {}
public:
	static Database* Instance();
	bool processData();
};

