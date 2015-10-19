
#include <mruby.h>

#include <crtdbg.h>

int main()
{
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto const mrb = mrb_open();
	mrb_close(mrb);
	return 0;
}

extern "C"{

//	mrb_open_allocf(state.c)から呼ばれる
void mrb_init_mrbgems(mrb_state *mrb)
{
}

}	//	extern "C"
