
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

#include <crtdbg.h>

int main()
{
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto const mrb = mrb_open();
	auto const v = mrb_load_string(mrb, "'abcde'");
	auto const type = mrb_type(v);
	auto const s = RSTRING_PTR(v);
	auto const len = RSTRING_LEN(v);
	mrb_close(mrb);
	return 0;
}
