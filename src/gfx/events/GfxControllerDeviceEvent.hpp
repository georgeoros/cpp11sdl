/*
 Giotto
 Copyright (C) 2020 George Oros

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

#ifndef GfxControllerDeviceEvent_hpp
#define GfxControllerDeviceEvent_hpp

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

class GfxControllerDeviceEvent final : public GfxObject, public prv::IGetCommonEvent, public prv::IGetJoystickID
{
public:
    typedef SDL_ControllerDeviceEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxControllerDeviceEvent() noexcept;
    explicit GfxControllerDeviceEvent(const SdlType event) noexcept;

    GfxControllerDeviceEvent(const GfxControllerDeviceEvent& other) noexcept;
    GfxControllerDeviceEvent(GfxControllerDeviceEvent&& other) noexcept;

    GfxControllerDeviceEvent& operator=(const GfxControllerDeviceEvent& other) noexcept;
    GfxControllerDeviceEvent& operator=(GfxControllerDeviceEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual const GfxCommonEvent getCommonEvent(void) const noexcept;

    virtual const joystick::GfxJoystickID getJoystickID(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType cdEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxControllerDeviceEvent_hpp */
