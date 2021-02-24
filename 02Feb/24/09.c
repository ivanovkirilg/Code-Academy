/* Задача 9. Ако имеме дефинирано макро */
#define M

/* кои от по-долните дефиниции ще пропаднат: */

#if M /* M is only a statement, not an expression. Preprocessor error. */
#endif

#ifdef M /* Valid, true (will execute) */
#endif

#ifndef M /* Valid, but false (will NOT execute) */
#endif

#if defined(M) /* Valid, true */
#endif

#if !defined(M) /* Valid, false */
#endif
