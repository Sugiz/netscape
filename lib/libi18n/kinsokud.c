/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/*	kinsokud.c	*/

/*
  Japanese Kinsoku table:
  Characters are not allowed in the beginning of line 
*/

#include "intlpriv.h"

MODULE_PRIVATE const char *ProhibitBegin_SJIS[] = 
{
"\x21",  "\x25",  "\x29",  "\x2C",  "\x2E",  "\x3A",  "\x3B",  "\x3F",  "\x5D", "\x7D", 
"\xA1",   "\xA3",   "\xA4",   "\xA5",   "\xDE",   "\xDF",   "\x81\x41", "\x81\x42", "\x81\x43", "\x81\x44", 	
"\x81\x45", "\x81\x46", "\x81\x47", "\x81\x48", "\x81\x49", "\x81\x4A", "\x81\x4B", "\x81\x52",	"\x81\x53", "\x81\x54", 
"\x81\x55", "\x81\x58", "\x81\x66", "\x81\x68", "\x81\x6A", "\x81\x6C", "\x81\x6E", "\x81\x70", "\x81\x72", "\x81\x74", 	
"\x81\x76", "\x81\x78", "\x81\x7A", "\x81\x8B", "\x81\x8C", "\x81\x8D", "\x81\x8E", "\x81\x91", "\x81\x93", "\x81\xF1", 
"\0"
};
MODULE_PRIVATE const char *ProhibitBegin_EUCJP[] = 
{
"\x21",	 "\x25",	  "\x29",   "\x2C",   "\x2E",   "\x3A",   "\x3B",   "\x3F",   "\x5D",   "\x7D",            
"\x8E\xA1", "\x8E\xA3", "\x8E\xA4", "\x8E\xA5", "\x8E\xDE", "\x8E\xDF", "\xA1\xA2", "\xA1\xA3", "\xA1\xA4", "\xA1\xA5", 
"\xA1\xA6", "\xA1\xA7", "\xA1\xA8", "\xA1\xA9", "\xA1\xAA", "\xA1\xAB", "\xA1\xAC", "\xA1\xB3", "\xA1\xB4", "\xA1\xB5",
"\xA1\xB6", "\xA1\xB9", "\xA1\xC7", "\xA1\xC9",	"\xA1\xCB", "\xA1\xCD", "\xA1\xCF", "\xA1\xD1", "\xA1\xD3", "\xA1\xD5",
"\xA1\xD7", "\xA1\xD9", "\xA1\xDB", "\xA1\xEB", "\xA1\xEC", "\xA1\xED", "\xA1\xEE", "\xA1\xF1", "\xA1\xF3", "\xA2\xF3",
"\0"
};

/*
 * BIG5 table
 */
MODULE_PRIVATE const char *ProhibitBegin_BIG5[] = 
{
"\x21",     "\x29",     "\x2C", 	"\x2E",     "\x3A",     "\x3B",     "\x3F",     "\x5D",     "\x7D",     "\xA1\x41", 
"\xA1\x43", "\xA1\x44", "\xA1\x45", "\xA1\x46", "\xA1\x47", "\xA1\x48", "\xA1\x49", "\xA1\x4A", "\xA1\x4B", "\xA1\x4C", 
"\xA1\x4D", "\xA1\x4E", "\xA1\x50", "\xA1\x51", "\xA1\x52", "\xA1\x53", "\xA1\x54", "\xA1\x55", "\xA1\x56", "\xA1\x57", 
"\xA1\x58", "\xA1\x59", "\xA1\x5A", "\xA1\x5B", "\xA1\x5C", "\xA1\x5E", "\xA1\x60", "\xA1\x62", "\xA1\x64", "\xA1\x66", 
"\xA1\x68", "\xA1\x6A", "\xA1\x6C", "\xA1\x6E", "\xA1\x70", "\xA1\x72", "\xA1\x74", "\xA1\x76", "\xA1\x78", "\xA1\x7A", 
"\xA1\x7C", "\xA1\x7E", "\xA1\xA2", "\xA1\xA4", "\xA1\xA6", "\xA1\xA8", "\xA1\xAA", "\xA1\xAC", "\0"
};
/*
	Convert the table from BIG5 into CNS_8BIT
*/
MODULE_PRIVATE const char *ProhibitBegin_CNS[] = 
{
"\x21",     "\x29",     "\x2C", 	"\x2E",     "\x3A",     "\x3B",     "\x3F",     "\x5D",     "\x7D",     "\xA1\xA2", 
"\xA1\xA4", "\xA1\xA5", "\xA1\xA6", "\xA1\xA7", "\xA1\xA8", "\xA1\xA9", "\xA1\xAA", "\xA1\x4B", "\xA1\x4B", "\xA1\xAC", 
"\xA1\xAC", "\xA1\xAD", "\xA1\xB1", "\xA1\xB2", "\xA1\xB3", "\xA1\xB4", "\xA1\xB5", "\xA1\xB6", "\xA1\xB7", "\xA1\xB8", 
"\xA1\xB9", "\xA1\xBA", "\xA1\xBB", "\xA1\xBC", "\xA1\xBD", "\xA1\xBF", "\xA1\xC1", "\xA1\xC2", "\xA1\x64", "\xA1\x66", 
"\xA1\xC9", "\xA1\xCB", "\xA1\xCD", "\xA1\xCF", "\xA1\xD1", "\xA1\xD3", "\xA1\xD5", "\xA1\xD7", "\xA1\xDA", "\xA1\xDB", 
"\xA1\xDD", "\xA1\xDF", "\xA1\xE1", "\xA1\xE3", "\xA1\xE5", "\xA1\xE7", "\xA1\xE9", "\xA1\xEB", "\0"
};

MODULE_PRIVATE const char *ProhibitBegin_GB[] = 
{
"\x21",     "\x29",     "\x2C",     "\x2E",     "\x3A",     "\x3B",     "\x3F",     "\x5D",     "\x7D",     "\xA1\xA2", 
"\xA1\xA3", "\xA1\xA4", "\xA1\xA5", "\xA1\xA6", "\xA1\xA7", "\xA1\xA8", "\xA1\xA9", "\xA1\xAA", "\xA1\xAB", "\xA1\xAC", 
"\xA1\xAD", "\xA1\xAF", "\xA1\xB1", "\xA1\xB3", "\xA1\xB5", "\xA1\xB7", "\xA1\xB9", "\xA1\xBB", "\xA1\xBD", "\xA1\xBF", 
"\xA1\xC3", "\xA3\xA1", "\xA3\xA2", "\xA3\xA7", "\xA3\xA9", "\xA3\xAC", "\xA3\xAE", "\xA3\xBA", "\xA3\xBB", "\xA3\xBF", 
"\xA3\xDD", "\xA3\xE0", "\xA3\xFC", "\xA3\xFD", "\0"
};

MODULE_PRIVATE const char *ProhibitBegin_KSC[] = 
{
"\x21",     "\x25",     "\x29",     "\x2C",     "\x2E",     "\x3A",     "\x3B",     "\x3F",     "\x5D",     "\x7D", 
"\xA1\xA2", "\xA1\xAF", "\xA1\xB1", "\xA1\xB3", "\xA1\xB5", "\xA1\xB7", "\xA1\xB9", "\xA1\xBB", "\xA1\xBD", "\xA1\xC6", 
"\xA1\xC7", "\xA1\xC8", "\xA1\xC9", "\xA1\xCB", "\xA3\xA1", "\xA3\xA5", "\xA3\xA9", "\xA3\xAC", "\xA3\xAE", "\xA3\xBA", 
"\xA3\xBB", "\xA3\xBF", "\xA3\xDC", "\xA3\xDD", "\xA3\xFD", "\0"
};


/*	ProhibitBegin_UTF8: Made by ftang.  */
MODULE_PRIVATE const char *ProhibitBegin_UTF8[] = 
{
/* U+  21 */  "\x21",
/* U+  25 */  "\x25",
/* U+  29 */  "\x29",
/* U+  2C */  "\x2C",
/* U+  2E */  "\x2E",
/* U+  3A */  "\x3A",
/* U+  3B */  "\x3B",
/* U+  5D */  "\x5D",
/* U+  7D */  "\x7D",
/* U+  3F */  "\x3F",
/* U+  A2 */  "\xC2\xA2",
/* U+  BB */  "\xC2\xBB",
/* U+2019 */  "\xE2\x80\x99",
/* U+201D */  "\xE2\x80\x9D",
/* U+2024 */  "\xE2\x80\xA4",
/* U+2025 */  "\xE2\x80\xA5",
/* U+2026 */  "\xE2\x80\xA6",
/* U+2030 */  "\xE2\x80\xB0",
/* U+3001 */  "\xE3\x80\x81",
/* U+3002 */  "\xE3\x80\x82",
/* U+3005 */  "\xE3\x80\x85",
/* U+3009 */  "\xE3\x80\x89",
/* U+300B */  "\xE3\x80\x8B",
/* U+300D */  "\xE3\x80\x8D",
/* U+300F */  "\xE3\x80\x8F",
/* U+3011 */  "\xE3\x80\x91",
/* U+3015 */  "\xE3\x80\x95",
/* U+3017 */  "\xE3\x80\x97",
/* U+3019 */  "\xE3\x80\x99",
/* U+301B */  "\xE3\x80\x9B",
/* U+3099 */  "\xE3\x82\x99",
/* U+309A */  "\xE3\x82\x9A",
/* U+309B */  "\xE3\x82\x9B",
/* U+309C */  "\xE3\x82\x9C",
/* U+309D */  "\xE3\x82\x9D",
/* U+309E */  "\xE3\x82\x9E",
/* U+30FB */  "\xE3\x83\xBB",
/* U+30FC */  "\xE3\x83\xBC",
/* U+30FD */  "\xE3\x83\xBD",
/* U+30FE */  "\xE3\x83\xBE",
/* U+FF61 */  "\xEF\xBD\xA1",
/* U+FF63 */  "\xEF\xBD\xA3",
/* U+FF64 */  "\xEF\xBD\xA4",
/* U+FF65 */  "\xEF\xBD\xA5",
/* U+FF9E */  "\xEF\xBE\x9E",
/* U+FF9F */  "\xEF\xBE\x9F",
"\0"
};


/*
  Japanese Kinsoku table:
  Characters are not allowed in the end of line 
*/

MODULE_PRIVATE const char *ProhibitEnd_SJIS[] =
{
"\x24",     "\x28",     "\x5B",     "\x5C",     "\x7B",     "\xA2",     "\x81\x65", "\x81\x67", "\x81\x69", "\x81\x6B",
"\x81\x6D", "\x81\x6F", "\x81\x71", "\x81\x73", "\x81\x75", "\x81\x77", "\x81\x79", "\x81\x8F", "\x81\x90", "\x81\x92",
"\0"
};
MODULE_PRIVATE const char *ProhibitEnd_EUCJP[] =
{
"\x24",     "\x28",     "\x5B",     "\x5C",     "\x7B",     "\x8E\xA2", "\xA1\xC6", "\xA1\xC8", "\xA1\xCA", "\xA1\xCC",
"\xA1\xCE", "\xA1\xD0", "\xA1\xD2", "\xA1\xD4", "\xA1\xD6", "\xA1\xD8", "\xA1\xDA", "\xA1\xEF", "\xA1\xF0", "\xA1\xF2",
"\0"
};

/*
 * BIG5 table
 */
MODULE_PRIVATE const char *ProhibitEnd_BIG5[] = 
{
"\x28",    "\x5B",    "\x7B",    "\xA1\x5D", "\xA1\x5F", "\xA1\x61", "\xA1\x63", "\xA1\x65", "\xA1\x67", "\xA1\x69", 
"\xA1\x6D","\xA1\x6F","\xA1\x71","\xA1\x73", "\xA1\x75", "\xA1\x77", "\xA1\x79", "\xA1\x7B", "\xA1\x7D", 
"\xA1\xA1","\xA1\xA3","\xA1\xA5","\xA1\xA7", "\xA1\xA9", "\xA1\xAB", "\0"
};
/*
	Convert the table from BIG5 into CNS
*/
MODULE_PRIVATE const char *ProhibitEnd_CNS[] = 
{
"\x28",    "\x5B",    "\x7B",    "\xA1\xBE", "\xA1\xC0", "\xA1\xC2", "\xA1\xC4", "\xA1\xC6", "\xA1\xC8", "\xA1\xCA", 
"\xA1\xCE","\xA1\xD0","\xA1\xD2","\xA1\xD4", "\xA1\xD6", "\xA1\xD8", "\xA1\xDA", "\xA1\xDC", "\xA1\xDE", 
"\xA1\xE0","\xA1\xE2","\xA1\xE4","\xA1\xE6", "\xA1\xE8", "\xA1\xEA", "\0"
};

MODULE_PRIVATE const char *ProhibitEnd_GB[] = 
{
"\x28",    "\x5B",    "\x7B",    "\xA1\xAE", "\xA1\xB0", "\xA1\xB2", "\xA1\xB4", "\xA1\xB6", "\xA1\xB8", "\xA1\xBA", 
"\xA1\xBC","\xA1\xBE","\xA3\xA8","\xA3\xAE", "\xA3\xDB", "\xA3\xFB", "\0"
};

MODULE_PRIVATE const char *ProhibitEnd_KSC[] = 
{
"\x28",    "\x5B",    "\x5C",    "\x7B",    "\xA1\xAE", "\xA1\xB0", "\xA1\xB2", "\xA1\xB4", "\xA1\xB6", "\xA1\xB8", 
"\xA1\xBA","\xA1\xBC","\xA3\xA4","\xA3\xA8","\xA3\xDB", "\xA3\xDC", "\xA3\xFB", "\0"
};

/*	ProhibitEnd_UTF8: Made by ftang.  */
MODULE_PRIVATE const char *ProhibitEnd_UTF8[] = 
{
/* U+  24 */  "\x24",
/* U+  28 */  "\x28",
/* U+  5B */  "\x5B",
/* U+  7B */  "\x7B",
/* U+  A2 */  "\xC2\xA2",
/* U+  A3 */  "\xC2\xA3",
/* U+  A5 */  "\xC2\xA5",
/* U+  AB */  "\xC2\xAB",
/* U+2018 */  "\xE2\x80\x98",
/* U+201C */  "\xE2\x80\x9C",
/* U+3008 */  "\xE3\x80\x88",
/* U+300A */  "\xE3\x80\x8A",
/* U+300C */  "\xE3\x80\x8C",
/* U+300E */  "\xE3\x80\x8E",
/* U+3010 */  "\xE3\x80\x90",
/* U+3014 */  "\xE3\x80\x94",
/* U+3016 */  "\xE3\x80\x96",
/* U+3018 */  "\xE3\x80\x98",
/* U+301A */  "\xE3\x80\x9A",
/* U+FF62 */  "\xEF\xBD\xA2",
"\0"	
};

