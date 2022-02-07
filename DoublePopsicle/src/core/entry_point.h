#pragma once

#ifdef DP_PLATFORM_WIN

extern dp::Application* dp::createApplication();

int main(int argc, char** argv)
{
	dp::log::init();
	DP_CORE_WARN("initialized log!");

	auto app = dp::createApplication();
	app->run();
	delete app;
	app = nullptr;

	return 0;
}

#endif // DP_PLATFORM_WIN

