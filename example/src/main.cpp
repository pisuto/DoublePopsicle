#include <popsicle.h>

class example : public dp::Application
{
public:
	example() {}

	~example() {}
};

dp::Application* dp::createApplication() 
{
	return new example();
}