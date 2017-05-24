make re
gcc main/main_memmove.c
export LD_PRELOAD=`pwd`/libasm.so
