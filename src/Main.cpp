#include "App.hpp"
#include "IO.hpp"
#include "ncursesIO.hpp"
#include "Calculator.hpp"
#include "InputToken.hpp"

#include <memory>
#include <vector>

int main()
{
	std::unique_ptr<IO> io = std::make_unique<ncursesIO>();

	App app(std::move(io));
	// app.Run();

	std::vector<MathToken> tokens = {MathToken::GetNumber(3), MathToken::GetAdd(), MathToken::GetNumber(4), MathToken::GetDiv(), MathToken::GetNumber(2)};
	// Calculator::ComputeInput(tokens);
	std::cout << "Output value is: " << std::to_string(Calculator::ComputeInput(tokens)) << std::endl;
}