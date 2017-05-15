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

#include <string>

#include "GfxControlledSurface.hpp"

#include "GfxSurfaceFlags.hpp"

namespace gfx
{

namespace supp
{

GfxControlledSurface::GfxControlledSurface()
{
    surf_ = nullptr;
    surfaceConstructed_ = false;
}

GfxControlledSurface::~GfxControlledSurface()
{
    if (surfaceConstructed_ == true)
    {
        delete surf_;
    }
}

void GfxControlledSurface::createSurface(const uint16_t w, const uint16_t h) throw(std::invalid_argument)
{
    if (surfaceConstructed_ == false)
    {
        if ((w > 1) && (h > 1))
        {
            surf_ = new gfx::GfxSurface(GfxSurfaceFlags(), w, h);
            surfaceConstructed_ = true;
            return;
        }
    }
    throw std::invalid_argument("Object already constructed");
}

gfx::GfxSurface& GfxControlledSurface::operator()(void) const throw(std::invalid_argument)
{
    if (surfaceConstructed_ == false)
    {
        throw std::invalid_argument("Object not constructed");
    }
    return *surf_;
}

}  // namespace supp

}  // namespace gfx

/* EOF */