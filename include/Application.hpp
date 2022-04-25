#pragma once
#include <list>
#include <string>

class Application
{
public:
	int execute();

	Application(int argc, char* argv[]);

	Application(const Application&) = delete;

private:
	std::list<std::string> arguments_;
};