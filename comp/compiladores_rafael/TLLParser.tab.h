#define tINTEGER 257
#define tREAL 258
#define tIDENTIFIER 259
#define tSTRING 260
#define tWHILE 261
#define tFOR 262
#define tDO 263
#define tIF 264
#define tREAD 265
#define tEND 266
#define tUSE 267
#define tPUBLIC 268
#define tRETURN 269
#define tNEXT 270
#define tSTOP 271
#define tTYPEINT 272
#define tTYPEREAL 273
#define tTYPESTRING 274
#define tVOID 275
#define tUNTIL 276
#define tMINUS 277
#define tPLUS 278
#define tPOS 279
#define tMUL 280
#define tDIV 281
#define tTHEN 282
#define tELSIF 283
#define tSTART_BLOCK 284
#define tEND_BLOCK 285
#define tLITREAL 286
#define tLITINT 287
#define tLITSTR 288
#define tENDLINE 289
#define tELSE 290
#define tWHX 291
#define tDOX 292
#define tIFX 293
#define tIFEX 294
#define tPN 295
#define tEQ 296
#define tNE 297
#define tGE 298
#define tLE 299
#define tPO 300
#define tUMINUS 301
typedef union {
  int                                i;	/* integer value */
  float								 r; /* real value */
  std::string                       *s;	/* symbol name or string literal */
  cdk::node::Node                   *node;	/* node pointer */
  cdk::node::Sequence               *sequence;
  cdk::node::expression::Expression *expression; /* expression nodes */
  ExpressionType					*expressiontype; /*types*/	
  tll::node::BlockNode				*block;		
} YYSTYPE;
extern YYSTYPE yylval;
