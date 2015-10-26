
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

#include <crtdbg.h>

int main()
{
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto const mrb = mrb_open();

//	auto const v = mrb_load_string(mrb, "'abcde'");
//	auto const type = mrb_type(v);
//	auto const s = RSTRING_PTR(v);
//	auto const len = RSTRING_LEN(v);

	auto const s0 = mrb_str_new_cstr(mrb, "abcde");
	auto const s1 = mrb_str_new_lit(mrb, "abcde");

	mrb_close(mrb);
	return 0;
}
