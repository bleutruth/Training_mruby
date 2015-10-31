## mruby.h

##### struct mrb_state;
mrubyの取り扱い単位となる構造体。  
通常、最初にmrb_openで生成して、最後にmrb_closeで破棄する。  
独立して取り扱いたいために、複数生成するということもありそう。

##### MRB_API mrb_state* mrb_open(void);
mrb_stateを生成して返す。

##### MRB_API void mrb_close(mrb_state* mrb);
mrb_stateを破棄する。

##### typedef void* (*mrb_allocf) (mrb_state *mrb, void* ptr, size_t s, void *ud);
ユーザー定義アロケータの型定義。  
アロケータの動作としては、reallocと同じように、  
sが0の時はメモリを解放し、ptrがNULLの時は新たにメモリを確保する。

##### MRB_API void* mrb_default_allocf(mrb_state* mrb, void* ptr, size_t s, void* ud);
デフォルトのアロケータ。  
mrb_open_allocfでユーザー定義のものを指定すれば置き換えられる。

##### MRB_API mrb_state* mrb_open_allocf(mrb_allocf f, void *ud);
mrb_stateを生成して返す。  
ユーザー定義アロケータとユーザーデータの指定版。

##### MRB_API struct RClass *mrb_define_class(mrb_state *mrb, const char *name, struct RClass *super);
クラスを定義する。

##### MRB_API struct RClass *mrb_define_module(mrb_state* mrb, const char* name);
モジュールを定義する。

##### MRB_API mrb_value mrb_singleton_class(mrb_state* mrb, mrb_value v);
特異クラスを返す。

##### MRB_API void mrb_include_module(mrb_state* mrb, struct RClass* c, struct RClass* m);
cクラスにmモジュールをincludeする。

##### MRB_API void mrb_prepend_module(mrb_state* mrb, struct RClass* c, struct RClass* m);
cクラスにmモジュールをprependする。

##### MRB_API void mrb_define_method(mrb_state *mrb, struct RClass *cla, const char *name, mrb_func_t func, mrb_aspec aspec);
メソッドを定義する。

##### MRB_API void mrb_define_class_method(mrb_state *mrb, struct RClass *cla, const char *name, mrb_func_t func, mrb_aspec aspec);
クラスメソッドを定義する。

##### MRB_API void mrb_define_singleton_method(mrb_state* mrb, struct RObject* o, const char* name, mrb_func_t func, mrb_aspec aspec);
特異メソッドを定義する。

##### MRB_API void mrb_define_module_function(mrb_state* mrb, struct RClass* cla, const char* name, mrb_func_t func, mrb_aspec aspec);
モジュールメソッドを定義する。

##### MRB_API void mrb_define_const(mrb_state* mrb, struct RClass* cla, const char *name, mrb_value v);
定数を定義する。

##### MRB_API void mrb_define_global_const(mrb_state *mrb, const char *name, mrb_value val);
グローバル定数を定義する。

##### MRB_API void mrb_undef_method(mrb_state* mrb, struct RClass* cla, const char* name);
メソッドの定義を消す。

##### MRB_API void mrb_undef_class_method(mrb_state* mrb, struct RClass* cla, const char* name);
クラスメソッドの定義を消す。

##### MRB_API mrb_value mrb_obj_new(mrb_state *mrb, struct RClass *c, mrb_int argc, const mrb_value *argv);
オブジェクトを生成する。  
argc, argvをinitializeの引数にする。

##### MRB_API mrb_value mrb_instance_new(mrb_state *mrb, mrb_value cv);
オブジェクトを生成する。  
initializeの引数はmrb_get_argsで取り出す。

##### MRB_API struct RClass * mrb_class_get(mrb_state *mrb, const char *name);
名前からクラスを取得。

##### MRB_API struct RClass * mrb_class_get_under(mrb_state *mrb, struct RClass *outer, const char *name);
派生クラスからクラスを取得。

##### MRB_API struct RClass * mrb_module_get(mrb_state *mrb, const char *name);
名前からモジュールを取得。

##### MRB_API struct RClass * mrb_module_get_under(mrb_state *mrb, struct RClass *outer, const char *name);
派生クラスからモジュールを取得。

##### MRB_API mrb_value mrb_notimplement_m(mrb_state* mrb, mrb_value self);
派生クラスで実装を強制するメソッド。  
オーバーライドされずに呼ばれた場合、NotImplementedErrorを投げる。

##### MRB_API mrb_value mrb_obj_clone(mrb_state *mrb, mrb_value self);
オブジェクトのコピーを生成する。  
Object#clone

##### MRB_API mrb_value mrb_obj_dup(mrb_state *mrb, mrb_value obj);
オブジェクトのコピーを生成する。  
Object#dup

##### MRB_API mrb_bool mrb_respond_to(mrb_state *mrb, mrb_value obj, mrb_sym mid);
##### MRB_API mrb_bool mrb_obj_respond_to(mrb_state *mrb, struct RClass* c, mrb_sym mid);
クラスがシンボルを持つか調べる。  
見つからない場合は親クラスを辿る。

##### mrb_aspec MRB_ARGS_REQ(n);
必要な引数の数を示す。

##### mrb_aspec MRB_ARGS_OPT(n);
オプションな引数の数を示す。

##### mrb_aspec MRB_ARGS_ARG(n1, n2);
必要な引数とオプションそれぞれの数を示す。

##### mrb_aspec MRB_ARGS_REST();
レスト引数をとることを示す。

##### mrb_aspec MRB_ARGS_POST(n);
post引数の数を示す。

##### mrb_aspec MRB_ARGS_KEY(n1,n2);
キーワード引数。

##### mrb_aspec MRB_ARGS_BLOCK();
ブロック引数をとることを示す。

##### mrb_aspec MRB_ARGS_ANY();
任意の引数をとることを示す。

##### mrb_aspec MRB_ARGS_NONE();
引数なし。

##### typedef const char *mrb_args_format;
mrb_get_argsで受け取る引数を示すための型定義。

##### MRB_API mrb_int mrb_get_args(mrb_state *mrb, mrb_args_format format, ...);
引数を受け取る。

##### mrb_sym mrb_get_mid(mrb_state *mrb);
実行中のメソッドのシンボルを取得。

##### int mrb_get_argc(mrb_state *mrb);
実行中のメソッドの引数の数を取得。

##### size_t mrb_strlen_lit(lit);
文字列リテラルの長さを返す。

##### MRB_API mrb_value mrb_funcall(mrb_state* mrb, mrb_value self, const char* name, mrb_int argc,...);
メソッドを呼び出す。  
引数は可変個の引数で渡す。

##### MRB_API mrb_value mrb_funcall_argv(mrb_state* mrb, mrb_value self, mrb_sym mid, mrb_int argc, const mrb_value* argv);
メソッドを呼び出す。  
引数は配列で渡す。

##### MRB_API mrb_value mrb_funcall_with_block(mrb_state* mrb, mrb_value self, mrb_sym mid, mrb_int argc, const mrb_value* argv, mrb_value blk);
メソッドを呼び出す。ブロック付き。

##### MRB_API mrb_sym mrb_intern_cstr(mrb_state* mrb, const char* name);
##### MRB_API mrb_sym mrb_intern(mrb_state* mrb, const char* name, size_t len);
##### MRB_API mrb_sym mrb_intern_str(mrb_state* mrb, mrb_value str);
文字列からシンボルを登録して返す。  
キーとして文字列のコピーをとる。

##### MRB_API mrb_sym mrb_intern_lit(mrb_state* mrb, const char* lit);
##### MRB_API mrb_sym mrb_intern_static(mrb_state* mrb,const char* name, size_t len);
文字列からシンボルを登録して返す。  
キーとして文字列のコピーをとらない。

##### MRB_API mrb_value mrb_check_intern_cstr(mrb_state* mrb, const char* name);
##### MRB_API mrb_value mrb_check_intern(mrb_state* mrb, const char* name, size_t len);
##### MRB_API mrb_value mrb_check_intern_str(mrb_state* mrb, mrb_value str);
文字列からシンボルを検索して返す。  
存在しない場合はnilを返す。

##### MRB_API const char *mrb_sym2name(mrb_state* mrb, mrb_sym sym);
##### MRB_API const char *mrb_sym2name_len(mrb_state* mrb, mrb_sym sym, mrb_int* lenp);
##### MRB_API mrb_value mrb_sym2str(mrb_state* mrb, mrb_sym sym);
シンボルの値から文字列を返す。

##### MRB_API void *mrb_malloc(mrb_state* mrb, size_t len);
##### MRB_API void *mrb_calloc(mrb_state* mrb, size_t nelem, size_t len);
##### MRB_API void *mrb_realloc(mrb_state* mrb, void* p, size_t len);
##### MRB_API void mrb_free(mrb_state* mrb, void* p);
malloc, calloc, realloc, free。

##### MRB_API void *mrb_malloc_simple(mrb_state* mrb, size_t len);
##### MRB_API void *mrb_realloc_simple(mrb_state* mrb, void* p, size_t len);
malloc, realloc。  
メモリ確保に失敗しても例外を投げない。

##### MRB_API struct RBasic *mrb_obj_alloc(mrb_state* mrb, enum mrb_vtype ttype, struct RClass* cls);
オブジェクトを生成。

##### MRB_API mrb_value mrb_str_new_cstr(mrb_state* mrb, const char* p);
##### MRB_API mrb_value mrb_str_new(mrb_state *mrb, const char *p, size_t len);
文字列のmrb_valueを生成する。  
文字列のコピーをとる。

##### MRB_API mrb_value mrb_str_new_lit(mrb_state *mrb, const char *lit);
##### MRB_API mrb_value mrb_str_new_static(mrb_state *mrb, const char *p, size_t len);
文字列のmrb_valueを生成する。  
文字列のコピーをとらない。 

##### MRB_API mrb_value mrb_format(mrb_state *mrb, const char *format, ...);
format指定の結果を格納した文字列を返す。

##### MRB_API mrb_value mrb_run(mrb_state* mrb, struct RProc* proc, mrb_value self);
実行する。

##### MRB_API mrb_value mrb_inspect(mrb_state *mrb, mrb_value obj);
##### MRB_API mrb_value mrb_obj_inspect(mrb_state *mrb, mrb_value self);
オブジェクトの内容を文字列で返す。  
Object#inspect

##### MRB_API void mrb_p(mrb_state* mrb, mrb_value obj);
オブジェクトの内容を標準出力に出力する。  
Kernel.#p

##### MRB_API mrb_int mrb_obj_id(mrb_value obj);
オブジェクトIDを返す。

##### MRB_API mrb_sym mrb_obj_to_sym(mrb_state *mrb, mrb_value name);
シンボルを返す。

##### MRB_API mrb_bool mrb_obj_eq(mrb_state* mrb, mrb_value v1, mrb_value v2);
##### MRB_API mrb_bool mrb_obj_equal(mrb_state* mrb, mrb_value v1, mrb_value v2);
オブジェクトが等しいかチェックする。

##### MRB_API mrb_bool mrb_equal(mrb_state *mrb, mrb_value obj1, mrb_value obj2);
オブジェクトが等しいかチェックする。  
mrb_obj_eqでチェックしてfalseが返ってきたら、==メソッドを呼んで判定する。

##### MRB_API mrb_bool mrb_eql(mrb_state *mrb, mrb_value obj1, mrb_value obj2);
オブジェクトが等しいかチェックする。  
mrb_obj_eqでチェックしてfalseが返ってきたら、eql?メソッドを呼んで判定する。

##### mrb_int mrb_int(mrb, val)
整数値に変換。

##### MRB_API mrb_value mrb_to_int(mrb_state *mrb, mrb_value val);
##### MRB_API mrb_value mrb_Integer(mrb_state *mrb, mrb_value val);
##### MRB_API mrb_value mrb_convert_to_integer(mrb_state *mrb, mrb_value val, int base);
整数オブジェクトに変換。

##### MRB_API mrb_value mrb_Float(mrb_state *mrb, mrb_value val);
浮動小数点数に変換。

##### MRB_API void mrb_garbage_collect(mrb_state* mrb);
##### MRB_API void mrb_full_gc(mrb_state* mrb);
GCを動かす。

##### MRB_API void mrb_incremental_gc(mrb_state *mrb);
インクリメンタルGCを動かす。

##### MRB_API mrb_value mrb_convert_type(mrb_state *mrb, mrb_value val, enum mrb_vtype type, const char *tname, const char *method);
##### MRB_API mrb_value mrb_check_convert_type(mrb_state *mrb, mrb_value val, enum mrb_vtype type, const char *tname, const char *method);
valをtypeに変換する。

##### MRB_API mrb_value mrb_any_to_s(mrb_state *mrb, mrb_value obj);
"#<クラス名:アドレス>"の形式で文字列を返す。

##### MRB_API const char* mrb_class_name(mrb_state *mrb, struct RClass* klass);
##### MRB_API const char* mrb_obj_classname(mrb_state *mrb, mrb_value obj);
クラス名を返す。

##### MRB_API struct RClass* mrb_obj_class(mrb_state *mrb, mrb_value obj);
クラスを返す。

##### MRB_API mrb_bool mrb_obj_is_instance_of(mrb_state *mrb, mrb_value obj, struct RClass* c);
クラスを判定する。

##### MRB_API mrb_bool mrb_obj_is_kind_of(mrb_state *mrb, mrb_value obj, struct RClass *c);
cクラスと継承関係にあるか判定する。  
親クラスなどもチェックする。  
Object#is_a?  
Object#kind_of?

##### bool ISASCII(int c);
ASCIIコードかどうか判定する。

##### bool ISPRINT(int c);
印刷可能な文字(PrintableCharacters)かどうか判定する。

##### bool ISSPACE(int c);
スペースかどうか判定する。  
半角スペース, \t, \n, \v, \f, \r

##### bool ISUPPER(int c);
大文字かどうか判定する。

##### bool ISLOWER(int c);
小文字かどうか判定する。

##### bool ISALPHA(int c);
アルファベットかどうか判定する。

##### bool ISDIGIT(int c);
数字かどうか判定する。

##### bool ISXDIGIT(int c);
数字またはA-Fのアルファベット(16進数で使う文字)かどうか判定する。

##### bool ISALNUM(int c);
数字またはアルファベットかどうか判定する。

##### bool ISBLANK(int c);
空白(半角スペースまたはタブ)かどうか判定する。

##### bool ISCNTRL(int c);
制御文字かどうか判定する。

##### int TOUPPER(int c);
大文字に変換。

##### int TOLOWER(int c);
小文字に変換。

##### MRB_API mrb_value mrb_exc_new(mrb_state *mrb, struct RClass *c, const char *ptr, size_t len);
例外クラスを生成。

##### MRB_API mrb_noreturn void mrb_exc_raise(mrb_state *mrb, mrb_value exc);
##### MRB_API mrb_noreturn void mrb_raise(mrb_state *mrb, struct RClass *c, const char *msg);
##### MRB_API mrb_noreturn void mrb_raisef(mrb_state *mrb, struct RClass *c, const char *fmt, ...);
例外を投げる。

##### MRB_API mrb_noreturn void mrb_name_error(mrb_state *mrb, mrb_sym id, const char *fmt, ...);
NameErrorの例外を投げる。

##### MRB_API void mrb_warn(mrb_state *mrb, const char *fmt, ...);
警告を標準エラー出力に出す。

##### MRB_API mrb_noreturn void mrb_bug(mrb_state *mrb, const char *fmt, ...);
バグ内容を標準エラー出力に出して、プログラムを終了する。

##### MRB_API void mrb_print_backtrace(mrb_state *mrb);
バックトレースを標準エラー出力に出す。

##### MRB_API void mrb_print_error(mrb_state *mrb);
バックトレースと例外の内容を標準エラー出力に出す。

##### E_RUNTIME_ERROR, E_TYPE_ERRORなど
例外クラスを示すマクロ。

##### MRB_API void mrb_check_type(mrb_state *mrb, mrb_value x, enum mrb_vtype t);
オブジェクトのタイプをチェックし、不一致な時は例外を投げる。

##### MRB_API void mrb_define_alias(mrb_state *mrb, struct RClass *klass, const char *name1, const char *name2);
メソッドに別名を付ける。  
Module#alias_method

##### void mrb_assert(bool p);
assert

##### void mrb_static_assert(exp, str);
static assert

##### MRB_API void mrb_show_version(mrb_state *mrb);
バージョン情報を標準出力に出す。

##### MRB_API void mrb_show_copyright(mrb_state *mrb);
コピーライトを標準出力に出す。

## mruby/value.h

##### struct mrb_value;
Cとの値の受け渡しに使う構造体。

##### enum mrb_vtype;
mrb_valueのタイプ。  
MRB_TT_FIXNUM, MRB_TT_STRING, MRB_TT_TRUE, …

##### enum mrb_vtype mrb_type(mrb_value o);
mrb_valueのタイプを取得。  
nilの場合、MRB_TT_FALSEが返ってくるので、  
きちんとnilかどうか判定したい時は、mrb_nil_pで判定する。

##### bool mrb_nil_p(mrb_value o);
##### bool mrb_bool(mrb_value o);
##### bool mrb_fixnum_p(mrb_value o);
##### bool mrb_array_p(mrb_value o);
##### bool mrb_string_p(mrb_value o);など
mrb_valueのタイプや真偽を判定する。

##### mrb_int mrb_fixnum(mrb_value o);
##### mrb_float mrb_float(mrb_value o);など
mrb_valueの値を取得する。

## mruby/string.h

##### const char* RSTRING_PTR(mrb_value s);
mrb_valueから文字列を取得。

##### mrb_int RSTRING_LEN(mrb_value s);
mrb_valueから文字列の長さを取得。

## mruby/compile.h

##### MRB_API mrb_value mrb_load_file(mrb_state*,FILE*);
##### MRB_API mrb_value mrb_load_string(mrb_state *mrb, const char *s);
##### MRB_API mrb_value mrb_load_nstring(mrb_state *mrb, const char *s, int len);
##### MRB_API mrb_value mrb_load_file_cxt(mrb_state*,FILE*, mrbc_context *cxt);
##### MRB_API mrb_value mrb_load_string_cxt(mrb_state *mrb, const char *s, mrbc_context *cxt);
##### MRB_API mrb_value mrb_load_nstring_cxt(mrb_state *mrb, const char *s, int len, mrbc_context *cxt);
引数で与えられたプログラムを実行する。  
戻り値には実行したプログラムの戻り値が返る。

## その他

##### void mrb_init_mrblib(mrb_state*);
mrblib(rubyで記述したコアな部分をmrbcでC形式で出力したもの)をロードする関数。  
mrubyをビルドすると、mrblibフォルダ以下の.rbファイルをまとめて自動的に生成(mrblib.c)される。

##### void mrb_init_mrbgems(mrb_state*);
mrbgemsをロードする関数  
mrubyをビルドすると、mrbgems以下のパッケージをまとめて自動的に生成(gem_init.c)される。  
含めるパッケージはbuild_config.rbで指定する.gemboxファイルに記述する。
