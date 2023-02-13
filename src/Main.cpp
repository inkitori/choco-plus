#include "App.hpp"
#include "IO.hpp"
#include "ncursesIO.hpp"
#include "Calculator.hpp"
#include "InputToken.hpp"

#include <memory>
#include <array>

int main()
{
	std::unique_ptr<IO> io = std::make_unique<ncursesIO>();

	App app(std::move(io));
	// app.Run();

	std::array<MathToken, 128> tokens = {MathToken::GetNumber(10), MathToken::GetAdd(), MathToken::GetNumber(20), MathToken::GetMul(), MathToken::GetNumber(30)};
	Calculator::ComputeInput(tokens);
}