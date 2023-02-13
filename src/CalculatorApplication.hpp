#pragma once

#include "Application.hpp"
#include "IO.hpp"

class CalculatorApplication : public Application
{
public:
	CalculatorApplication(IO io);
	void OnBoot() override;
	void Update() override;
	void OnInput(InputToken) override;

private:
	IO io;
};