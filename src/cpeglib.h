#ifndef CPEGLIB_H
#define CPEGLIB_H

/* ユーザ定義可能なパラメータ */

// メモ化表のサイズ
#ifndef CPEG_MEMO_SIZE
#define CPEG_MEMO_SIZE  (1<<8)  /* 256 */
#endif

// 実験のため，メモ化をオフにできるようにする．
#ifndef CPEG_DO_MEMOIZE
#define CPEG_DO_MEMOIZE (1) /* デフォルト,1でメモ化 */
#endif

#ifndef CPEG_DO_COUNT
#define CPEG_DO_COUNT (0)
#endif

#ifndef CPEG_VALUE_TYPE
#define CPEG_VALUE_TYPE void *  /* デフォルトはvoid * */
#endif

/* ユーザ定義可能なパラメータはここまで */

typedef int cpeg_pos_t;
typedef CPEG_VALUE_TYPE cpeg_value_t;
typedef enum {false = 0, true} bool; /* これは定義しないほうがいいかも */

// global registers
// これはcpeg_というprefixをつけてリネームすべき．
extern cpeg_pos_t pos;
extern bool failed;
cpeg_value_t val;

#define AS_CHAR(v) ((char)(long)(v))
#define AS_VAL(v) ((cpeg_value_t)(long)(v))

extern char *input;

// 文字集合のサイズ
#include <limits.h>
#define CPEG_CHARSET_SIZE (1<<CHAR_BIT)

#define SIZE (1 << 8)

#define FAIL (-1)  /* toposがFAILなら，すでに失敗したことをメモ化済み */
#define NO_POS (-2) /* どのposとも等しくならない...必ずミスする */

typedef struct memo_entry {
  cpeg_pos_t frompos;
  cpeg_pos_t topos;
  cpeg_value_t v;
} cpeg_result_t;

typedef int cpeg_charset_t[CPEG_CHARSET_SIZE];

extern void cs_range(cpeg_charset_t set, char ch1, char ch2);
extern void cs_add_char(cpeg_charset_t set, char ch);
extern void cs_simple(cpeg_charset_t set, char ch); // cs_add_charの古い名前
extern void cs_del_char(cpeg_charset_t set, char ch);
extern void cs_add_str(cpeg_charset_t set, const char *str);

extern void cs_complement(cpeg_charset_t set);
extern void cs_add_set(cpeg_charset_t set1, cpeg_charset_t set2);
extern void cs_union(cpeg_charset_t set1, cpeg_charset_t set2); // cs_add_setの古い名前

#define STMT(block) do block while (0)


#define MEMO_TABLE()  static cpeg_result_t memo[CPEG_MEMO_SIZE] = {{NO_POS}};
#define MEMO_CHECK(arg)	STMT({                        \
      if(memo[arg%CPEG_MEMO_SIZE].frompos == arg) {		\
	val = memo[arg%CPEG_MEMO_SIZE].v;				\
	failed = (memo[arg%CPEG_MEMO_SIZE].topos == FAIL);		\
	if (!failed) pos = memo[arg%CPEG_MEMO_SIZE].topos;	\
	return;						\
      }							\
      })


#if CPEG_DO_COUNT
#define CPEG_COUNT_CALLED(name) (cpeg_ ## name ## _called++);
#define CPEG_COUNT_MISSED(name) (cpeg_ ## name ## _missed++);
#else
#define CPEG_COUNT_CALLED(name)
#define CPEG_COUNT_MISSED(name)
#endif

#if CPEG_DO_MEMOIZE
#define PROLOGUE(name)				\
  MEMO_TABLE();					\
  CPEG_COUNT_CALLED(name);			\
  MEMO_CHECK(pos);				\
  CPEG_COUNT_MISSED(name);			\
  cpeg_pos_t first_pos = pos;

#define EPILOGUE() STMT({                       \
      memo[first_pos%CPEG_MEMO_SIZE].frompos = first_pos;	\
      if (failed) {				\
        memo[first_pos%CPEG_MEMO_SIZE].topos = FAIL;		\
      } else {                                  \
	memo[first_pos%CPEG_MEMO_SIZE].topos = pos;	\
        memo[first_pos%CPEG_MEMO_SIZE].v = val;           \
      }                                         \
    } )
#else
#define PROLOGUE(name) \
  CPEG_COUNT_CALLED(name);			\
  CPEG_COUNT_MISSED(name);
#define EPILOGUE()
#endif

#define SEQ_I(e1, e2)                           \
  STMT(                                         \
       {					\
	 cpeg_pos_t first_pos = pos;		\
	 e1;					\
         if (!failed) {                         \
           e2;                                  \
	   if (failed) pos = first_pos;		\
         }                                      \
       } )

#define SEQ1(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) e1
#define SEQ2(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) SEQ_I(e1, e2)
#define SEQ3(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) SEQ_I(SEQ_I(e1, e2), e3)
#define SEQ4(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) SEQ_I(SEQ_I(e1, e2), SEQ_I(e3, e4))
#define SEQ5(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)	\
  SEQ_I(SEQ_I(SEQ_I(e1, e2), e3), SEQ_I(e4, e5))
#define SEQ6(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)		\
  SEQ_I(SEQ_I(SEQ_I(e1, e2), SEQ_I(e3, e4)), SEQ_I(e5, e6))
#define SEQ7(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  SEQ_I(SEQ_I(SEQ_I(e1, e2), SEQ_I(e3, e4)), SEQ_I(SEQ_I(e5, e6), e7))
#define SEQ8(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  SEQ_I(SEQ_I(SEQ_I(e1, e2), SEQ_I(e3, e4)), SEQ_I(SEQ_I(e5, e6), SEQ_I(e7, e8)))
#define SEQ9(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  SEQ_I(SEQ_I(SEQ_I(e1, e2), SEQ_I(e3, e4)), SEQ_I(SEQ_I(e5, e6), SEQ_I(SEQ_I(e7, e8), e9)))

#define SEQ10(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  SEQ_I(SEQ_I(SEQ_I(e1, e2), SEQ_I(e3, e4)), SEQ_I(SEQ_I(e5, e6), SEQ_I(SEQ_I(e7, e8), SEQ_I(e9, e10))))
// 0個や11個以上だとエラーになるようにしたほうがいいかも．


#define SEQ_V(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, name, ...)	\
  name(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)

#define SEQ(...)                                                      \
  SEQ_V(__VA_ARGS__, SEQ10, SEQ9, SEQ8, SEQ7, SEQ6, SEQ5, SEQ4, SEQ3, SEQ2, SEQ1)

#define ALT_I(e1, e2)                           \
  STMT(                                         \
       {					\
         e1;                                    \
         if (failed) {                          \
           failed = false;                      \
           e2;                                  \
         }                                      \
       } )

#define ALT1(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) e1
#define ALT2(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) ALT_I(e1, e2)
#define ALT3(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) ALT_I(ALT_I(e1, e2), e3)
#define ALT4(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) ALT_I(ALT_I(e1, e2), ALT_I(e3, e4))
#define ALT5(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)	\
  ALT_I(ALT_I(ALT_I(e1, e2), e3), ALT_I(e4, e5))
#define ALT6(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)		\
  ALT_I(ALT_I(ALT_I(e1, e2), e3), ALT_I(ALT_I(e4, e5), e6))
#define ALT7(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  ALT_I(ALT_I(ALT_I(e1, e2), ALT_I(e3, e4)), ALT_I(ALT_I(e5, e6), e7))
#define ALT8(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
	ALT_I(ALT_I(ALT_I(e1, e2), ALT_I(e3, e4)), ALT_I(ALT_I(e5, e6), ALT_I(e7, e8)))
#define ALT9(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  ALT_I(ALT_I(ALT_I(e1, e2), ALT_I(e3, e4)), ALT_I(ALT_I(e5, e6), ALT_I(ALT_I(e7, e8), e9)))
#define ALT10(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)			\
  ALT_I(ALT_I(ALT_I(e1, e2), ALT_I(e3, e4)), ALT_I(ALT_I(e5, e6), ALT_I(ALT_I(e7, e8), ALT_I(e9, e10))))

#define ALT_V(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, name, ...)	\
  name(e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)

#define ALT(...)                                                      \
  ALT_V(__VA_ARGS__, ALT10, ALT9, ALT8, ALT7, ALT6, ALT5, ALT4, ALT3, ALT2, ALT1)


#define CHAR(c) STMT(                               \
                     {                              \
                       if (check_char(pos, (c))) {  \
                         val = AS_VAL(input[pos++]);	\
                       } else {                     \
                         failed = true;             \
                       }                            \
                     } )                            \


#define STR(s) STMT({                           \
      check_str(pos, (s));                      \
    })

//関数呼び出しにする
//失敗した場合posが戻ってない
#define EMPTY() STMT({                          \
      failed = false;                           \
    })

//ワイルド"."
#define ANY() STMT({                            \
      if (input[pos]) val = AS_VAL(input[pos++]); else failed = true;	\
    })

// つねに失敗
#define FAILED() (failed = true)

#define REPEAT0(e) STMT({                       \
      while(!failed){                           \
        e;                                      \
      }                                         \
      failed = false;                           \
    })

#define REPEAT1(e) SEQ(e, REPEAT0(e))

#define OPTION(e) STMT({                        \
      e;                                        \
      if(failed){                               \
        failed = false;                         \
      }                                         \
    })

//肯定先読み"&e"
#define ANDPRE(a) STMT({                        \
      cpeg_pos_t andpre_pos = pos;		\
      e;                                        \
      pos = andpre_pos;				\
    })

//否定先読み"!e"
#define NOTPRE(e) STMT({                        \
      cpeg_pos_t notpre_pos = pos;		\
      e;                                        \
      failed = !failed;				\
      pos = notpre_pos;				\
    })

#define CHARSET(set) STMT({                     \
      char ch = input[pos];                     \
      if (check_cs(set, ch)) {                  \
        val = AS_VAL(input[pos++]);		\
      } else {                                  \
        failed = true;                          \
      }                                         \
    })

static bool check_char(cpeg_pos_t p, char c) {
  return input[p] == c;
}

//return 失敗 0, 成功 新しいpos
static void check_str(cpeg_pos_t p, char str[]){
  int str_pos = 0;
  int temp_pos = p;
  while (str[str_pos] != '\0') {
    if(!check_char(temp_pos, (str[str_pos]))){        //失敗した
      failed = true;
      return;
    }
    temp_pos++;
    str_pos++;
  }
  // 成功: posを進める
  pos = temp_pos;
  return;
}

static bool check_cs(cpeg_charset_t set, char ch) {
  int n = ch;
  return set[n];
}

//開始記号
extern void START(void);

typedef void rule_func_t(void);

#define DECLARE_RULES(...) rule_func_t __VA_ARGS__;

#if CPEG_DO_COUNT
#define BEGIN_RULE(name)			\
  long cpeg_ ## name ## _called, cpeg_ ## name ## _missed; \
  void name(void) {				\
    PROLOGUE(name);
#else
#define BEGIN_RULE(name)			\
  void name(void) {				\
    PROLOGUE(name);
#endif

#define END_RULE				\
    EPILOGUE();					\
}

extern void cpeg_error(char *funcname, char *path);

#include <unistd.h>  /* for off_t */
extern off_t cpeg_get_file_size(char *filepath);

extern char *cpeg_get_file_mmap(char *filepath);

extern char *cpeg_get_file_read(char *filepath);

extern int cpeg_main(int argc, char *argv[]);

typedef void (*result_processor)(cpeg_value_t result, char *input, cpeg_pos_t pos, size_t size);

extern int cpeg_main2(int argc, char *argv[], result_processor process);

#endif  /* CPEGLIB_H */
