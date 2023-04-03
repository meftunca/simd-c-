#pragma once

/*
    Very Strict UTF-8 Decoder

    UTF-8 is a multibyte character encoding of Unicode. A character can be
    represented by 1-4 bytes. The bit pattern of the first byte indicates the
    number of continuation bytes.

    Most UTF-8 decoders tend to be lenient, attempting to recover as much
    information as possible, even from badly encoded input. This UTF-8
    decoder is not lenient. It will reject input which does not include
    proper continuation bytes. It will reject aliases (or suboptimal
    codings). It will reject surrogates. (Surrogate encoding should only be
    used with UTF-16.)

    Code     Contination Minimum Maximum
    0xxxxxxx           0       0     127
    10xxxxxx       error
    110xxxxx           1     128    2047
    1110xxxx           2    2048   65535 excluding 55296 - 57343
    11110xxx           3   65536 1114111
    11111xxx       error
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#define UTF8_END -1
#define UTF8_ERROR -2

extern int utf8_decode_at_byte();
extern int utf8_decode_at_character();
extern void utf8_decode_init(char p[], int length);
extern int utf8_decode_next();

static int the_index = 0;
static int the_length = 0;
static int the_char = 0;
static int the_byte = 0;
static char* the_input;

using JSON_checker = struct JSON_checker_struct {
  int valid;
  int state;
  int depth;
  int top;
  int* stack;
};

inline int utf8_to_utf16(unsigned short w[], char p[], int length);
inline JSON_checker new_JSON_checker(int depth);
inline int JSON_checker_char(JSON_checker jc, int next_char);
inline int JSON_checker_done(JSON_checker jc);
#define TRUE 1
#define FALSE 0
#define GOOD 0xBABAB00E  // 0xBABAB00E is a good number
#define __ -1            /* the universal error code */

/*
    Characters are mapped into these 31 character classes. This allows for
    a significant reduction in the size of the state transition table.
*/

enum classes {
  C_SPACE, /* space */
  C_WHITE, /* other whitespace */
  C_LCURB, /* {  */
  C_RCURB, /* } */
  C_LSQRB, /* [ */
  C_RSQRB, /* ] */
  C_COLON, /* : */
  C_COMMA, /* , */
  C_QUOTE, /* " */
  C_BACKS, /* \ */
  C_SLASH, /* / */
  C_PLUS,  /* + */
  C_MINUS, /* - */
  C_POINT, /* . */
  C_ZERO,  /* 0 */
  C_DIGIT, /* 123456789 */
  C_LOW_A, /* a */
  C_LOW_B, /* b */
  C_LOW_C, /* c */
  C_LOW_D, /* d */
  C_LOW_E, /* e */
  C_LOW_F, /* f */
  C_LOW_L, /* l */
  C_LOW_N, /* n */
  C_LOW_R, /* r */
  C_LOW_S, /* s */
  C_LOW_T, /* t */
  C_LOW_U, /* u */
  C_ABCDF, /* ABCDF */
  C_E,     /* E */
  C_ETC,   /* everything else */
  NR_CLASSES
};

static int ascii_class[128] = {
    /*
        This array maps the 128 ASCII characters into character classes.
        The remaining Unicode characters should be mapped to C_ETC.
        Non-whitespace control characters are errors.
    */
    __,      __,      __,      __,      __,      __,      __,      __,
    __,      C_WHITE, C_WHITE, __,      __,      C_WHITE, __,      __,
    __,      __,      __,      __,      __,      __,      __,      __,
    __,      __,      __,      __,      __,      __,      __,      __,

    C_SPACE, C_ETC,   C_QUOTE, C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_PLUS,  C_COMMA, C_MINUS, C_POINT, C_SLASH,
    C_ZERO,  C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT,
    C_DIGIT, C_DIGIT, C_COLON, C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,

    C_ETC,   C_ABCDF, C_ABCDF, C_ABCDF, C_ABCDF, C_E,     C_ABCDF, C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_LSQRB, C_BACKS, C_RSQRB, C_ETC,   C_ETC,

    C_ETC,   C_LOW_A, C_LOW_B, C_LOW_C, C_LOW_D, C_LOW_E, C_LOW_F, C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_LOW_L, C_ETC,   C_LOW_N, C_ETC,
    C_ETC,   C_ETC,   C_LOW_R, C_LOW_S, C_LOW_T, C_LOW_U, C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_LCURB, C_ETC,   C_RCURB, C_ETC,   C_ETC};

/*
    The state codes.
*/
enum states {
  GO, /* start    */
  OK, /* ok       */
  OB, /* object   */
  KE, /* key      */
  CO, /* colon    */
  VA, /* value    */
  AR, /* array    */
  ST, /* string   */
  ES, /* escape   */
  U1, /* u1       */
  U2, /* u2       */
  U3, /* u3       */
  U4, /* u4       */
  MI, /* minus    */
  ZE, /* zero     */
  IN, /* integer  */
  FR, /* fraction */
  FS, /* fraction */
  E1, /* e        */
  E2, /* ex       */
  E3, /* exp      */
  T1, /* tr       */
  T2, /* tru      */
  T3, /* true     */
  F1, /* fa       */
  F2, /* fal      */
  F3, /* fals     */
  F4, /* false    */
  N1, /* nu       */
  N2, /* nul      */
  N3, /* null     */
  NR_STATES
};

static int state_transition_table[NR_STATES][NR_CLASSES] = {
    /*
        The state transition table takes the current state and the current
       symbol, and returns either a new state or an action. An action is
       represented as a negative number. A JSON text is accepted if at the end
       of the text the state is OK and if the mode is MODE_DONE.

                     white                                      1-9 ABCDF  etc
                 space |  {  }  [  ]  :  ,  "  \  /  +  -  .  0  |  a  b  c  d
       e  f  l  n  r  s  t  u  |  E  |*/
    /*start  GO*/ {GO, GO, -6, __, -5, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*ok     OK*/ {OK, OK, __, -8, __, -7, __, -3, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*object OB*/ {OB, OB, __, -9, __, __, __, __, ST, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*key    KE*/ {KE, KE, __, __, __, __, __, __, ST, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*colon  CO*/ {CO, CO, __, __, __, __, -2, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*value  VA*/ {VA, VA, -6, __, -5, __, __, __, ST, __, __,
                   __, MI, __, ZE, IN, __, __, __, __, __, F1,
                   __, N1, __, __, T1, __, __, __, __},
    /*array  AR*/ {AR, AR, -6, __, -5, -7, __, __, ST, __, __,
                   __, MI, __, ZE, IN, __, __, __, __, __, F1,
                   __, N1, __, __, T1, __, __, __, __},
    /*string ST*/ {ST, __, ST, ST, ST, ST, ST, ST, -4, ES, ST,
                   ST, ST, ST, ST, ST, ST, ST, ST, ST, ST, ST,
                   ST, ST, ST, ST, ST, ST, ST, ST, ST},
    /*escape ES*/ {__, __, __, __, __, __, __, __, ST, ST, ST,
                   __, __, __, __, __, __, ST, __, __, __, ST,
                   __, ST, ST, __, ST, U1, __, __, __},
    /*u1     U1*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, U2, U2, U2, U2, U2, U2, U2, U2,
                   __, __, __, __, __, __, U2, U2, __},
    /*u2     U2*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, U3, U3, U3, U3, U3, U3, U3, U3,
                   __, __, __, __, __, __, U3, U3, __},
    /*u3     U3*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, U4, U4, U4, U4, U4, U4, U4, U4,
                   __, __, __, __, __, __, U4, U4, __},
    /*u4     U4*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, ST, ST, ST, ST, ST, ST, ST, ST,
                   __, __, __, __, __, __, ST, ST, __},
    /*minus  MI*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, ZE, IN, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*zero   ZE*/ {OK, OK, __, -8, __, -7, __, -3, __, __, __,
                   __, __, FR, __, __, __, __, __, __, E1, __,
                   __, __, __, __, __, __, __, E1, __},
    /*int    IN*/ {OK, OK, __, -8, __, -7, __, -3, __, __, __,
                   __, __, FR, IN, IN, __, __, __, __, E1, __,
                   __, __, __, __, __, __, __, E1, __},
    /*frac   FR*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, FS, FS, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*fracs  FS*/ {OK, OK, __, -8, __, -7, __, -3, __, __, __,
                   __, __, __, FS, FS, __, __, __, __, E1, __,
                   __, __, __, __, __, __, __, E1, __},
    /*e      E1*/ {__, __, __, __, __, __, __, __, __, __, __,
                   E2, E2, __, E3, E3, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*ex     E2*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, E3, E3, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*exp    E3*/ {OK, OK, __, -8, __, -7, __, -3, __, __, __,
                   __, __, __, E3, E3, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*tr     T1*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, T2, __, __, __, __, __, __},
    /*tru    T2*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, T3, __, __, __},
    /*true   T3*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, OK, __,
                   __, __, __, __, __, __, __, __, __},
    /*fa     F1*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, F2, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __},
    /*fal    F2*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   F3, __, __, __, __, __, __, __, __},
    /*fals   F3*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, F4, __, __, __, __, __},
    /*false  F4*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, OK, __,
                   __, __, __, __, __, __, __, __, __},
    /*nu     N1*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, N2, __, __, __},
    /*nul    N2*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   N3, __, __, __, __, __, __, __, __},
    /*null   N3*/ {__, __, __, __, __, __, __, __, __, __, __,
                   __, __, __, __, __, __, __, __, __, __, __,
                   OK, __, __, __, __, __, __, __, __}};

/*
    These modes can be pushed on the stack.
*/
enum modes { MODE_ARRAY, MODE_DONE, MODE_KEY, MODE_OBJECT };

/*
    Get the next byte. It returns UTF8_END if there are no more bytes.
*/
static int get() {
  int c;
  if (the_index >= the_length) {
    return UTF8_END;
  }
  c = the_input[the_index] & 0xFF;
  the_index += 1;
  return c;
}

/*
    Get the 6-bit payload of the next continuation byte.
    Return UTF8_ERROR if it is not a contination byte.
*/
static int cont() {
  int c = get();
  return ((c & 0xC0) == 0x80) ? (c & 0x3F) : UTF8_ERROR;
}

/*
    Initialize the UTF-8 decoder. The decoder is not reentrant,
*/
inline void utf8_decode_init(char p[], int length) {
  the_index = 0;
  the_input = p;
  the_length = length;
  the_char = 0;
  the_byte = 0;
}

static void destroy(JSON_checker& jc) {
  /*
    Delete the JSON_checker object.
*/
  jc.valid = 0;
  free((void*)jc.stack);

  // delete[] jc.stack;
  free((void*)jc);
  // delete jc;
}

static int reject(JSON_checker jc) {
  /*
    Delete the JSON_checker object.
*/
  destroy(jc);
  return FALSE;
}

static int push(JSON_checker& jc, const int& mode) {
  /*
    Push a mode onto the stack. Return false if there is overflow.
*/
  jc.top += 1;
  if (jc.top >= jc.depth) {
    return FALSE;
  }
  jc.stack[jc.top] = mode;
  return TRUE;
}

static int pop(JSON_checker& jc, const int& mode) {
  /*
    Pop the stack, assuring that the current mode matches the expectation.
    Return false if there is underflow or if the modes mismatch.
*/
  if (jc.top < 0 || jc.stack[jc.top] != mode) {
    return FALSE;
  }
  jc.top -= 1;
  return TRUE;
}

JSON_checker new_JSON_checker(const int depth) {
  /*
    new_JSON_checker starts the checking process by constructing a
   JSON_checker object. It takes a depth parameter that restricts the level of
   maximum nesting.

    To continue the process, call JSON_checker_char for each character in the
    JSON text, and then call JSON_checker_done to obtain the final result.
    These functions are fully reentrant.

    The JSON_checker object will be deleted by JSON_checker_done.
    JSON_checker_char will delete the JSON_checker object if it sees an error.
*/
  JSON_checker jc = reinterpret_cast<JSON_checker>(
      malloc(sizeof(struct JSON_checker_struct)));
  jc.valid = GOOD;
  jc.state = GO;
  jc.depth = depth;
  jc.top = -1;
  jc.stack = reinterpret_cast<int*>(calloc(depth, sizeof(int)));
  push(jc, MODE_DONE);
  return jc;
}

int JSON_checker_char(JSON_checker jc, int next_char) {
  /*
    After calling new_JSON_checker, call this function for each character (or
    partial character) in your JSON text. It can accept UTF-8, UTF-16, or
    UTF-32. It returns TRUE if things are looking ok so far. If it rejects the
    text, it deletes the JSON_checker object and returns false.
*/
  int next_class = 0;
  int next_state = 0;
  /*
    Determine the character's class.
*/
  if (jc.valid != GOOD) {
    return FALSE;
  }
  if (next_char < 0) {
    return reject(jc);
  }
  if (next_char >= 128) {
    next_class = C_ETC;
  } else {
    next_class = ascii_class[next_char];
    if (next_class <= __) {
      return reject(jc);
    }
  }
  /*
    Get the next state from the state transition table.
*/
  next_state = state_transition_table[jc.state][next_class];
  if (next_state >= 0) {
    /*
    Change the state.
*/
    jc.state = next_state;
    /*
    Or perform one of the actions.
*/
  } else {
    switch (next_state) {
        /* empty } */
      case -9:
        if (!pop(jc, MODE_KEY)) {
          return reject(jc);
        }
        jc.state = OK;
        break;

      /* } */ case -8:
        if (!pop(jc, MODE_OBJECT)) {
          return reject(jc);
        }
        jc.state = OK;
        break;

      /* ] */ case -7:
        if (pop(jc, MODE_ARRAY) == 0) {
          return reject(jc);
        }
        jc.state = OK;
        break;

      /* { */ case -6:
        if (push(jc, MODE_KEY) == 0) {
          return reject(jc);
        }
        jc.state = OB;
        break;

      /* [ */ case -5:
        if (push(jc, MODE_ARRAY) == 0) {
          return reject(jc);
        }
        jc.state = AR;
        break;

      /* " */ case -4:
        switch (jc.stack[jc.top]) {
          case MODE_KEY:
            jc.state = CO;
            break;
          case MODE_ARRAY:
          case MODE_OBJECT:
            jc.state = OK;
            break;
          default:
            return reject(jc);
        }
        break;

      /* , */ case -3:
        switch (jc.stack[jc.top]) {
          case MODE_OBJECT:
            /*
A comma causes a flip from object mode to key mode.
*/
            if ((pop(jc, MODE_OBJECT) == 0) || (push(jc, MODE_KEY) == 0)) {
              return reject(jc);
            }
            jc.state = KE;
            break;
          case MODE_ARRAY:
            jc.state = VA;
            break;
          default:
            return reject(jc);
        }
        break;

      /* : */ case -2:
        /*
  A colon causes a flip from key mode to object mode.
*/
        if ((pop(jc, MODE_KEY) == 0) || (push(jc, MODE_OBJECT) == 0)) {
          return reject(jc);
        }
        jc.state = VA;
        break;
        /*
  Bad action.
*/
      default:
        return reject(jc);
    }
  }
  return TRUE;
}

int JSON_checker_done(JSON_checker jc) {
  /*
    The JSON_checker_done function should be called after all of the
   characters have been processed, but only if every call to JSON_checker_char
   returned TRUE. This function deletes the JSON_checker and returns TRUE if
   the JSON text was accepted.
*/
  if (jc.valid != GOOD) {
    return FALSE;
  }
  int result = jc.state == OK && pop(jc, MODE_DONE);
  destroy(jc);
  return result;
}

int utf8_to_utf16(unsigned short w[], char p[], int length) {
  int c;
  utf8_decode_init(p, length);
  the_index = 0;
  for (;;) {
    c = utf8_decode_next();
    if (c < 0) {
      return (c == UTF8_END) ? the_index : UTF8_ERROR;
    }
    if (c < 0x10000) {
      w[the_index] = (unsigned short)c;
      the_index += 1;
      continue;
    }

    c -= 0x10000;
    w[the_index] = (unsigned short)(0xD800 | (c >> 10));
    the_index += 1;
    w[the_index] = (unsigned short)(0xDC00 | (c & 0x3FF));
    the_index += 1;
  }
}

/*
    Get the current byte offset. This is generally used in error reporting.
*/
inline int utf8_decode_at_byte() { return the_byte; }

/*
    Get the current character offset. This is generally used in error reporting.
    The character offset matches the byte offset if the text is strictly ASCII.
*/
inline int utf8_decode_at_character() {
  return (the_char > 0) ? the_char - 1 : 0;
}

/*
    Extract the next character.
    Returns: the character (between 0 and 1114111)
         or  UTF8_END   (the end)
         or  UTF8_ERROR (error)
*/
inline int utf8_decode_next() {
  int c;  /* the first byte of the character */
  int c1; /* the first continuation character */
  int c2; /* the second continuation character */
  int c3; /* the third continuation character */
  int r;  /* the result */

  if (the_index >= the_length) {
    return the_index == the_length ? UTF8_END : UTF8_ERROR;
  }
  the_byte = the_index;
  the_char += 1;
  c = get();
  /*
    Zero continuation (0 to 127)
*/
  if ((c & 0x80) == 0) {
    return c;
  }
  /*
    One continuation (128 to 2047)
*/
  if ((c & 0xE0) == 0xC0) {
    c1 = cont();
    if (c1 >= 0) {
      r = ((c & 0x1F) << 6) | c1;
      if (r >= 128) {
        return r;
      }
    }

    /*
    Two continuations (2048 to 55295 and 57344 to 65535)
*/
  } else if ((c & 0xF0) == 0xE0) {
    c1 = cont();
    c2 = cont();
    if ((c1 | c2) >= 0) {
      r = ((c & 0x0F) << 12) | (c1 << 6) | c2;
      if (r >= 2048 && (r < 55296 || r > 57343)) {
        return r;
      }
    }

    /*
    Three continuations (65536 to 1114111)
*/
  } else if ((c & 0xF8) == 0xF0) {
    c1 = cont();
    c2 = cont();
    c3 = cont();
    if ((c1 | c2 | c3) >= 0) {
      r = ((c & 0x07) << 18) | (c1 << 12) | (c2 << 6) | c3;
      if (r >= 65536 && r <= 1114111) {
        return r;
      }
    }
  }
  return UTF8_ERROR;
}
