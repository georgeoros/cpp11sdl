/*
  Giotto
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php

  Font file ANTIQUE.FNT I found many years ago on the internet. Please message
  me asap if you think there is a copyright issue at play here.
*/

#ifndef __fntAntique_hpp__
#define __fntAntique_hpp__

namespace gfx
{
namespace bgi
{
namespace fnt
{


const uint8_t GfxBgiFontConstants::fntAntiqueData_[16 * 256] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x81, 0xA5, 0x81, 0x81, 0xBD, 0x99, 0x81, 0x81, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0xFF, 0xDB, 0xFF, 0xFF, 0xC3, 0xE7, 0xFF, 0xFF, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x6C, 0xFE, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x3C, 0x3C, 0xE7, 0xE7, 0xE7, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x7E, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x1E, 0x0E, 0x1A, 0x32, 0x78, 0xCC, 0xCC, 0xCC, 0xCC, 0x78, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3F, 0x33, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x70, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0x63, 0x7F, 0x63, 0x63, 0x63, 0x63, 0x67, 0xE7, 0xE6, 0xC0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x18, 0xDB, 0x3C, 0xE7, 0x3C, 0xDB, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFE, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x06, 0x0E, 0x1E, 0x3E, 0xFE, 0x3E, 0x1E, 0x0E, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0xDB, 0xDB, 0xDB, 0x7B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7C, 0xC6, 0x60, 0x38, 0x6C, 0xC6, 0xC6, 0x6C, 0x38, 0x0C, 0xC6, 0x7C, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x0C, 0xFE, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x60, 0xFE, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x6C, 0xFE, 0x6C, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x38, 0x7C, 0x7C, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x7C, 0x7C, 0x38, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x66, 0x42, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x6C, 0x6C, 0x6C, 0xFE, 0x6C, 0x6C, 0x6C, 0xFE, 0x6C, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x7C, 0xD2, 0xD0, 0xF0, 0x7C, 0x3E, 0x1E, 0x16, 0x96, 0x7C, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x62, 0x66, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xCC, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x68, 0x58, 0x38, 0x70, 0xF2, 0xD4, 0xC8, 0xD4, 0x76, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x10, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x08, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xD6, 0xFE, 0x7C, 0xEE, 0x7C, 0xFE, 0xD6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x10, 0x20, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x06, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x26, 0x66, 0x66, 0x6E, 0x76, 0x66, 0x66, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x38, 0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x46, 0x66, 0x06, 0x0C, 0x18, 0x30, 0x62, 0x7E, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x66, 0x66, 0x06, 0x3C, 0x06, 0x06, 0x66, 0x66, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x06, 0x0E, 0x16, 0x26, 0x46, 0xFF, 0x06, 0x06, 0x0F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x7E, 0x40, 0x5C, 0x66, 0x46, 0x06, 0x66, 0x46, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x26, 0x66, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x7E, 0x42, 0x06, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x66, 0x62, 0x74, 0x3C, 0x2E, 0x46, 0x46, 0x66, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x06, 0x66, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x38, 0x18, 0x10, 0x20, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7C, 0xC6, 0x86, 0x06, 0x0C, 0x18, 0x30, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x46, 0x9A, 0xB6, 0xBA, 0xB6, 0x9C, 0x80, 0xC2, 0x7C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x06, 0x0E, 0x0E, 0x16, 0x16, 0x26, 0x3E, 0x46, 0x46, 0xEF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFC, 0x66, 0x62, 0x66, 0x7C, 0x66, 0x62, 0x62, 0x66, 0xFC, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3E, 0x46, 0xC2, 0xC0, 0xC0, 0xC0, 0xC0, 0xC2, 0xE6, 0x7C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFC, 0x6E, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x64, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFE, 0x62, 0x60, 0x64, 0x7C, 0x64, 0x60, 0x60, 0x62, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFE, 0x62, 0x60, 0x64, 0x7C, 0x64, 0x60, 0x60, 0x60, 0xF0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x66, 0xC2, 0xC0, 0xCE, 0xC6, 0xC6, 0xC6, 0xE4, 0x78, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE7, 0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x66, 0xE7, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xD8, 0x70, 0x00, 0x00,
    0x00, 0x00, 0xE7, 0x62, 0x62, 0x64, 0x68, 0x7C, 0x6E, 0x66, 0x66, 0xE7, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xF0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x62, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE7, 0x66, 0x76, 0x7E, 0x7E, 0x56, 0x46, 0x46, 0x46, 0xEF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE7, 0x62, 0x72, 0x72, 0x5A, 0x5A, 0x4E, 0x4E, 0x46, 0xE6, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x4E, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xE4, 0x78, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFC, 0x66, 0x66, 0x66, 0x64, 0x78, 0x60, 0x60, 0x60, 0xF0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x4E, 0xC6, 0xC6, 0xC6, 0xC6, 0xD6, 0xD6, 0xF4, 0x78, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFC, 0x66, 0x66, 0x66, 0x6C, 0x78, 0x64, 0x66, 0x66, 0xE7, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7A, 0xC6, 0xC2, 0xE0, 0x70, 0x1C, 0x0E, 0x86, 0xCE, 0xBC, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xDB, 0x99, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE3, 0x62, 0x62, 0x62, 0x62, 0x62, 0x62, 0x62, 0x72, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE3, 0x62, 0x64, 0x64, 0x68, 0x68, 0x70, 0x70, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE3, 0x62, 0x62, 0x6A, 0x6A, 0x7E, 0x7E, 0x7E, 0x6C, 0x68, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xF7, 0x62, 0x62, 0x74, 0x38, 0x1C, 0x2E, 0x46, 0x46, 0xEF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE3, 0x62, 0x74, 0x34, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFE, 0x86, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0xC2, 0xFE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x10, 0x20, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x8C, 0x1C, 0x6C, 0xCE, 0xDC, 0x68, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x60, 0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0x66, 0x64, 0x58, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x26, 0x60, 0x60, 0x62, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x0C, 0x1C, 0x0C, 0x3C, 0x4C, 0xCC, 0xCC, 0xCC, 0xDC, 0x6E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x22, 0x64, 0x78, 0x72, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x0F, 0x16, 0x30, 0x7C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x3A, 0x4C, 0x64, 0x38, 0x7C, 0x8E, 0x66, 0x62, 0x3C, 0x00, 0x00,
    0x00, 0x20, 0x60, 0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0x66, 0x66, 0xE7, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0C, 0x00, 0x00, 0x04, 0x0C, 0x1C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0C, 0x00, 0x00, 0x04, 0x0C, 0x1C, 0x0C, 0x0C, 0x0C, 0x0C, 0x68, 0x70, 0x00, 0x00,
    0x00, 0x20, 0x60, 0xE0, 0x60, 0x6E, 0x64, 0x68, 0x70, 0x78, 0x6C, 0xEE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x7F, 0xEB, 0x6B, 0x6B, 0x6B, 0xEB, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x76, 0xE6, 0x66, 0x66, 0x66, 0xE7, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x26, 0x66, 0x66, 0x66, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x76, 0xE6, 0x66, 0x64, 0x78, 0x60, 0x60, 0xF0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x4C, 0xCC, 0xCC, 0xCC, 0x7C, 0x0C, 0x0C, 0x1E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x4F, 0xF6, 0x60, 0x60, 0x60, 0x60, 0xF0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x32, 0x38, 0x1C, 0x0E, 0x26, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x10, 0x30, 0x7E, 0x30, 0x30, 0x30, 0x32, 0x34, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x66, 0x66, 0x66, 0x67, 0x6E, 0x34, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xE6, 0x64, 0x68, 0x68, 0x70, 0x70, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xE3, 0x62, 0x6A, 0x6E, 0x7E, 0x6C, 0x48, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x64, 0x38, 0x38, 0x38, 0x4C, 0xEE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF3, 0x62, 0x36, 0x3C, 0x1C, 0x08, 0x10, 0x70, 0x60, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x46, 0x0C, 0x18, 0x30, 0x62, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0E, 0x18, 0x18, 0x18, 0x18, 0x70, 0x18, 0x18, 0x18, 0x18, 0x0E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x00, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0x18, 0x18, 0x18, 0x18, 0x0E, 0x18, 0x18, 0x18, 0x18, 0x70, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x32, 0x7E, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x6C, 0xC6, 0x82, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x33, 0x61, 0x60, 0x60, 0x61, 0x33, 0x1E, 0x06, 0x03, 0x3E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x66, 0x66, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x0C, 0x18, 0x00, 0x3E, 0x63, 0x7F, 0x60, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x1C, 0x36, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x66, 0x66, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x18, 0x0C, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1C, 0x36, 0x1C, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x0C, 0x06, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x1C, 0x36, 0x00, 0x3E, 0x63, 0x7F, 0x60, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x66, 0x66, 0x00, 0x3E, 0x63, 0x7F, 0x60, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x18, 0x0C, 0x00, 0x3E, 0x63, 0x7F, 0x60, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x66, 0x66, 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x18, 0x3C, 0x66, 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x60, 0x30, 0x18, 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x63, 0x63, 0x08, 0x1C, 0x36, 0x63, 0x63, 0x7F, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1C, 0x36, 0x1C, 0x00, 0x1C, 0x36, 0x63, 0x63, 0x7F, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0C, 0x18, 0x30, 0x00, 0x7F, 0x33, 0x30, 0x3E, 0x30, 0x33, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x6E, 0x3B, 0x1B, 0x7E, 0xD8, 0xDC, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1F, 0x36, 0x66, 0x66, 0x7F, 0x66, 0x66, 0x66, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x1C, 0x36, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x63, 0x63, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x18, 0x0C, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x18, 0x3C, 0x66, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x18, 0x0C, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x63, 0x63, 0x00, 0x63, 0x63, 0x63, 0x63, 0x3F, 0x03, 0x06, 0x3C, 0x00, 0x00, 0x00,
    0x00, 0x63, 0x63, 0x1C, 0x36, 0x63, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x63, 0x63, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x18, 0x18, 0x7E, 0xC3, 0xC0, 0xC0, 0xC3, 0x7E, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1C, 0x36, 0x32, 0x30, 0x78, 0x30, 0x30, 0x30, 0x73, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xC3, 0x66, 0x3C, 0x18, 0xFF, 0x18, 0xFF, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFC, 0x66, 0x66, 0x7C, 0x62, 0x66, 0x6F, 0x66, 0x66, 0xF3, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0E, 0x1B, 0x18, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x18, 0x18, 0xD8, 0x70, 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x18, 0x30, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x18, 0x30, 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x18, 0x30, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x18, 0x30, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3B, 0x6E, 0x00, 0x6E, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3B, 0x6E, 0x00, 0x63, 0x73, 0x7B, 0x7F, 0x6F, 0x67, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3C, 0x6C, 0x6C, 0x3E, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x6C, 0x6C, 0x38, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x30, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x60, 0xE0, 0x63, 0x66, 0x6C, 0x18, 0x30, 0x6E, 0xC3, 0x06, 0x0C, 0x1F, 0x00, 0x00, 0x00,
    0x00, 0x60, 0xE0, 0x63, 0x66, 0x6C, 0x18, 0x33, 0x67, 0xCF, 0x1F, 0x03, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x3C, 0x3C, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1B, 0x36, 0x6C, 0x36, 0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x6C, 0x36, 0x1B, 0x36, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44,
    0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA,
    0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xF6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x36, 0x36, 0x36, 0x36, 0x36, 0xF6, 0x06, 0xF6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x06, 0xF6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0xF6, 0x06, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0x18, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x30, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0xF7, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xF7, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x36, 0x36, 0x36, 0x36, 0x36, 0xF7, 0x00, 0xF7, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x18, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xFF, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x6E, 0x6C, 0x6C, 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x7E, 0x63, 0x63, 0x7E, 0x60, 0x60, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0x63, 0x63, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0x63, 0x30, 0x18, 0x0C, 0x18, 0x30, 0x63, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x6C, 0x6C, 0x6C, 0x6C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3B, 0x6E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x18, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x36, 0x63, 0x63, 0x7F, 0x63, 0x63, 0x36, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x36, 0x36, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x30, 0x18, 0x0C, 0x3E, 0x66, 0x66, 0x66, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xDB, 0xDB, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x06, 0x7E, 0xDB, 0xDB, 0xF3, 0x7E, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x30, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x30, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x1B, 0x1B, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xD8, 0xD8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3B, 0x6E, 0x00, 0x3B, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x6C, 0x6C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xEC, 0x6C, 0x3C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xD8, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0xD8, 0x30, 0x60, 0xC8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

}  // namespace fnt
}  // namespace bgi
}  // namespace gfx

#endif  // __fntAntique_hpp__
