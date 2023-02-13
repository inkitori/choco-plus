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

	std::array<MathToken, 128> tokens = {MathToken::GetNumber(3), MathToken::GetAdd(), MathToken::GetNumber(4), MathToken::GetMul(), MathToken::GetNumber(2), MathToken::GetDiv(), MathToken::GetLeftParen(), MathToken::GetNumber(1), MathToken::GetSub(), MathToken::GetNumber(5), MathToken::GetRightParen(), MathToken::GetPow(), MathToken::GetNumber(2), MathToken::GetPow(), MathToken::GetNumber(3)};
	Calculator::ComputeInput(tokens);
}