
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

#include <crtdbg.h>

FILE* ExecFile(mrb_state& mrb, char filename[])
{
	auto const fp = fopen(filename, "r");
	if(!fp){
		return 0;
	}
	mrb_load_file(&mrb, fp);
	if(mrb.exc){
		mrb_p(&mrb, mrb_obj_value(mrb.exc));
	}
	return fp;
}

void Exec(mrb_state& mrb, char filename[])
{
	auto const fp = ExecFile(mrb, filename);
	if(fp){
		fclose(fp);
	}
}

int main()
{
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto const mrb = mrb_open();
	if(!mrb){
		return -1;
	}
	Exec(*mrb, "test.rb");
	mrb_close(mrb);
	return 0;
}
