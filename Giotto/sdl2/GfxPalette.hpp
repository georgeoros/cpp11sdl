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

#ifndef GfxPalette_hpp
#define GfxPalette_hpp

#include <vector>
#include <memory>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxColor.hpp"

class GfxPalette final : public GfxRootClass
{
public:
	typedef SDL_Palette SdlType;
	typedef SDL_Palette* SdlTypePtr;

	using GfxColorVector = std::vector<GfxColor>;

    GfxPalette();
	GfxPalette(const uint16_t ncolors,const GfxColorVector& colors);

	GfxPalette(const GfxPalette& other);
	GfxPalette(GfxPalette&& other);

    ~GfxPalette();

	GfxPalette& operator=(const GfxPalette& other);
	GfxPalette& operator=(GfxPalette&& other);

	/* Methods */
	void allocPalette(const uint16_t ncolors);
	void freePalette();
	int setPaletteColors(const GfxColorVector& vec,const uint16_t firstcolor);

	/* Getters */
	uint16_t getNumColors(void) const;
    std::unique_ptr<GfxColorVector> getColors(void) const;
	uint32_t getVersion(void) const;
	int getRefCount(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
	SdlTypePtr pal_;
};

#endif