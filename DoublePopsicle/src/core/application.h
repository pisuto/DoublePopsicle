#pragma once

#include "core.h"

namespace dp {

	class DP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be defined in CLIENT
	Application* createApplication();
}

