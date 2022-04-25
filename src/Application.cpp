#include "Application.hpp"

#if defined(_WIN32)
#include "Windows.hpp"
#endif // !OS Windows(x86/x64)

int Application::execute()
{
	return ImplExecute();
}

Application::Application(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++) {
		arguments_.push_back(argv[i]);
	}

	if (!ImplRegisterClass())
	{
		// Register class Failed.
	}
}