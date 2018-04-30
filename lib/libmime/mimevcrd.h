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

/* mimevcrd.h --- definition of the MimeInlineTextVCard class (see mimei.h)
 */

#ifndef _MIMEVCRD_H_
#define _MIMEVCRD_H_

#include "mimetext.h"

/* The MimeInlineTextHTML class implements the text/x-vcard and (maybe?
   someday?) the application/directory MIME content types.
 */

typedef struct MimeInlineTextVCardClass MimeInlineTextVCardClass;
typedef struct MimeInlineTextVCard      MimeInlineTextVCard;

struct MimeInlineTextVCardClass {
  MimeInlineTextClass text;
  char* vCardString;
};

extern MimeInlineTextVCardClass mimeInlineTextVCardClass;

struct MimeInlineTextVCard {
  MimeInlineText text;
};

#endif /* _MIMEVCRD_H_ */
