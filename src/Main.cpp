#include "App.hpp"
#include "IO.hpp"
#include "ncursesIO.hpp"

#include <memory>

int main()
{
	std::unique_ptr<IO> io = std::make_unique<ncursesIO>();

	App app(std::move(io));
	app.Run();
}