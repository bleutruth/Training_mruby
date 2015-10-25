
mruby.h  

struct mrb_state;  
mrubyの取り扱い単位となる構造体。  
通常、最初にmrb_openで生成して、最後にmrb_closeで破棄する。  
独立して取り扱いたいために、複数生成するということもありそう。  

MRB_API mrb_state* mrb_open(void);  
mrb_stateを生成して返す。  

MRB_API void mrb_close(mrb_state*);  
mrb_stateを破棄する。  

mruby/value.h  

struct mrb_value;  
Cとの値の受け渡しに使う構造体。  

enum mrb_vtype;  
mrb_valueのタイプ。  
MRB_TT_FIXNUM, MRB_TT_STRING, MRB_TT_TRUE, …  

enum mrb_vtype mrb_type(mrb_value o);  
mrb_valueのタイプを取得。  
nilの場合、MRB_TT_FALSEが返ってくるので、
きちんとnilかどうか判定したい時は、mrb_nil_pで判定する。  

bool mrb_nil_p(mrb_value o);  
bool mrb_fixnum_p(mrb_value o);  
bool mrb_array_p(mrb_value o);  
bool mrb_string_p(mrb_value o);など  
mrb_valueのタイプを判定する。  

mruby/compile.h  

MRB_API mrb_value mrb_load_file(mrb_state*,FILE*);  
MRB_API mrb_value mrb_load_string(mrb_state *mrb, const char *s);  
MRB_API mrb_value mrb_load_nstring(mrb_state *mrb, const char *s, int len);  
MRB_API mrb_value mrb_load_file_cxt(mrb_state*,FILE*, mrbc_context *cxt);  
MRB_API mrb_value mrb_load_string_cxt(mrb_state *mrb, const char *s, mrbc_context *cxt);  
MRB_API mrb_value mrb_load_nstring_cxt(mrb_state *mrb, const char *s, int len, mrbc_context *cxt);  
引数で与えられたプログラムを実行する。  
戻り値には実行したプログラムの戻り値が返る。  

その他  

void mrb_init_mrblib(mrb_state*);  
mrblib(rubyで記述したコアな部分をmrbcでC形式で出力したもの)をロードする関数。  
mrubyをビルドすると、mrblibフォルダ以下の.rbファイルをまとめて自動的に生成(mrblib.c)される。  

void mrb_init_mrbgems(mrb_state*);  
mrbgemsをロードする関数  
mrubyをビルドすると、mrbgems以下のパッケージをまとめて自動的に生成(gem_init.c)される。  
含めるパッケージはbuild_config.rbで指定する.gemboxファイルに記述する。  
