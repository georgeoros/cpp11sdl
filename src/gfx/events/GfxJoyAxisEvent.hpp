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

#ifndef GfxJoyAxisEvent_hpp
#define GfxJoyAxisEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "IGetCommonEvent.hpp"
#include "IGetJoystickID.hpp"
#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"

namespace gfx
{

namespace events
{

class GfxJoyAxisEvent : public GfxObject, public prv::IGetCommonEvent, public prv::IGetJoystickID
{
public:
    typedef sdl2::SDL_JoyAxisEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxJoyAxisEvent() noexcept;
    explicit GfxJoyAxisEvent(const SdlType event) noexcept;

    GfxJoyAxisEvent(GfxJoyAxisEvent const& other) noexcept;
    GfxJoyAxisEvent(GfxJoyAxisEvent&& other) noexcept;

    GfxJoyAxisEvent& operator=(GfxJoyAxisEvent const& other) noexcept;
    GfxJoyAxisEvent& operator=(GfxJoyAxisEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual GfxCommonEvent getCommonEvent(void) const noexcept;

    virtual joystick::GfxJoystickID getJoystickID(void) const noexcept;

    uint8_t getAxis(void) const noexcept;
    int16_t getValue(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType jaxEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxJoyAxisEvent_hpp */
