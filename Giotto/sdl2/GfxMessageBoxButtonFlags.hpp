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
 */

#ifndef GfxMessageBoxButtonFlags_hpp
#define GfxMessageBoxButtonFlags_hpp

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

class GfxMessageBoxButtonFlags final : public GfxRootClass
{
public:
    typedef SDL_MessageBoxButtonFlags SdlType;
    typedef SDL_MessageBoxButtonFlags* SdlTypePtr;

    enum class GfxMessageBoxButtonFlagsValues : int
    {
        noneDefault = 0,
        returnKeyDefault = SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,
        escKeyDefault = SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT
    };

    GfxMessageBoxButtonFlags();
    GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlagsValues flags);
    GfxMessageBoxButtonFlags(SdlType flags);
    GfxMessageBoxButtonFlags(SdlTypePtr flags);
    GfxMessageBoxButtonFlags(const GfxMessageBoxButtonFlags& other);
    GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags&& other);

    GfxMessageBoxButtonFlags& operator=(const GfxMessageBoxButtonFlags& other);
    GfxMessageBoxButtonFlags& operator=(GfxMessageBoxButtonFlags&& other);

    bool operator==(const GfxMessageBoxButtonFlags& other);

    bool isReturnDefault(void) const;
    bool isEscDefault(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType flags_;
};

#endif /* GfxMessageBoxButtonFlags_hpp */