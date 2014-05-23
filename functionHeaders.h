#include "cd.c"
#include "cp.c"
#include "ln.c"
#include "mv.c"
#include "head.c"
#include "touch.c"
#include "mkdir.c"
#include "rmdir.c"
#include "uname.c"
#include "file.c"
#include "tail.c"
#include "ls.c"
#include "cat.c"
#include "pwd.c"
#include "rm.c"
#include "bc.c"
#include "grep.c"
#include "date.c"
#include "time.c"
#include "wc.c"

int mycd(int argc, char *argv[]);
int mycp(int argc, char *argv[]);
int myln(int argc, char *argv[]);
int mymv(int argc, char *argv[]);
int myhead(int argc, char *argv[]);
int mytouch(int argc, char *argv[]);
int mymkdir(int argc, char *argv[]);
int myrmdir(int argc, char *argv[]);
int myuname();
int myfile(int argc, char *argv[]);
int mytail(int argc, char *argv[]);
int myls(int argc, char *argv[]);
int mycat(int argc, char *argv[]);
int mypwd();
int myrm(int argc, char *argv[]);
int mybc();
int mygrep(int argc, char *argv[]);
int mydate();
int mytime(int argc, char *argv[]);
int mywc(int argc, char *argv[]);
