
#include <mruby.h>
#include <mruby/compile.h>

#include <crtdbg.h>

int main()
{
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto const mrb = mrb_open();
	mrb_load_string(mrb, "puts 'HelloWorld!'");
	mrb_close(mrb);
	return 0;
}
