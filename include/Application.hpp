#pragma once

#include "InputToken.hpp"

class Application
{
public:
	Application() {}
	virtual void OnBoot() {}
	virtual void Update() {}
	virtual void OnInput(InputToken) {}
};