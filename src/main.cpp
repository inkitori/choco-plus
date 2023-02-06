#include "App.hpp"
#include "Input.hpp"
#include "Output.hpp"

int main()
{
	Input input;
	Output output;

	App app(input, output);
	app.Run();
}