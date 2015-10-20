
mruby.h  

struct mrb_state;  
mrubyの取り扱い単位となる構造体。  
通常、最初にmrb_openで生成して、最後にmrb_closeで破棄する。  
独立して取り扱いたいために、複数生成するということもありそう。  

MRB_API mrb_state* mrb_open(void);  
mrb_stateを生成して返す。  

MRB_API void mrb_close(mrb_state*);  
mrb_stateを破棄する。  

その他  

void mrb_init_mrblib(mrb_state*);  
mrblib(rubyで記述したコアな部分をmrbcでC形式で出力したもの)をロードする関数。  
mrubyをビルドすると、mrblibフォルダ以下の.rbファイルをまとめて自動的に生成(mrblib.c)される。  

void mrb_init_mrbgems(mrb_state*);  
mrbgemsをロードする関数  
mrubyをビルドすると、mrbgems以下のパッケージをまとめて自動的に生成(gem_init.c)される。  
含めるパッケージはbuild_config.rbで指定する.gemboxファイルに記述する。  
