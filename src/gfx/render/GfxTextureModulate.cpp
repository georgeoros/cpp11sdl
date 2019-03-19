/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include <cassert>
#include <string>
#include <utility>

#include "GfxTextureModulate.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtexturemodulate::render::gfx");

namespace gfx
{

namespace render
{

const char GfxTextureModulate::ClassName[] = "GfxTextureModulate";

GfxTextureModulate::GfxTextureModulate() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTextureModulate::GfxTextureModulate(const ValueType modulate) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    modulate_ = static_cast<SdlType>(modulate);
}

GfxTextureModulate::GfxTextureModulate(const SdlType modulate) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(modulate >= 0);

    modulate_ = modulate;
}

GfxTextureModulate::GfxTextureModulate(const int32_t modulate) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(modulate >= 0);

    modulate_ = static_cast<SdlType>(modulate);
}

GfxTextureModulate::GfxTextureModulate(const GfxTextureModulate& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    modulate_ = other.modulate_;
}

GfxTextureModulate::GfxTextureModulate(GfxTextureModulate&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    modulate_ = other.modulate_;
    // Delete other's data
    other.clear();
}

GfxTextureModulate& GfxTextureModulate::operator=(const GfxTextureModulate& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        modulate_ = other.modulate_;
    }
    return *this;
}

GfxTextureModulate& GfxTextureModulate::operator=(GfxTextureModulate&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        modulate_ = other.modulate_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTextureModulate::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTextureModulate::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxTextureModulate::isNone(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (modulate_ == static_cast<SdlType>(ValueType::modulateNone));
}

bool GfxTextureModulate::isColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = modulate_ & SDL_TEXTUREMODULATE_COLOR;

    return (r != 0);
}

bool GfxTextureModulate::isAlpha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = modulate_ & SDL_TEXTUREMODULATE_ALPHA;

    return (r != 0);
}

void GfxTextureModulate::setColor(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    modulate_ = static_cast<SdlType>(modulate_ | SDL_TEXTUREMODULATE_COLOR);
}

void GfxTextureModulate::resetColor(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    modulate_ = static_cast<SdlType>(modulate_ & ~SDL_TEXTUREMODULATE_COLOR);
}

void GfxTextureModulate::setAlpha(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    modulate_ = static_cast<SdlType>(modulate_ | SDL_TEXTUREMODULATE_ALPHA);
}

void GfxTextureModulate::resetAlpha(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    modulate_ = static_cast<SdlType>(modulate_ & ~SDL_TEXTUREMODULATE_ALPHA);
}

void GfxTextureModulate::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    modulate_ = static_cast<SdlType>(ValueType::modulateNone);
}

GfxTextureModulate::SdlType GfxTextureModulate::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return modulate_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
