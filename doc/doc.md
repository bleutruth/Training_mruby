
mruby.h

struct mrb_state;  
mrubyの取り扱い単位となる構造体。  
通常、最初にmrb_openで生成して、最後にmrb_closeで破棄する。  
独立して取り扱いたいために、複数生成するということもありそう。  

MRB_API mrb_state* mrb_open(void);  
mrb_stateを生成して返す。  

MRB_API void mrb_close(mrb_state*);  
mrb_stateを破棄する。  
