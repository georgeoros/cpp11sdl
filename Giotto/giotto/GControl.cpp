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

#include "GControl.hpp"

namespace giotto
{

namespace objects
{

GControl::GControl(std::string const& name, GComponent* owner) : GComponent(name, owner)
{
    bounds_.clear();
    clientBounds_.clear();
    enabled_ = false;
    borderType_ = kDefaultBorderType;
    hint_.clear();
    showHint_ = false;
    visible_ = false;
}

GControl::~GControl()
{
    // nothing to do yet
}

void GControl::setBounds(gfx::GfxRect const& bounds) noexcept
{
    bounds_ = bounds;
    adjustClientBounds();
}

gfx::GfxRect const& GControl::getBounds(void) const noexcept
{
    return bounds_;
}

gfx::GfxRect const& GControl::getClientBounds(void) const noexcept
{
    return clientBounds_;
}


void GControl::setEnabled(void) noexcept
{
    enabled_ = true;
}

bool GControl::getEnabled(void) const noexcept
{
    return enabled_;
}

void GControl::setBorder(GBorderType bordertype) noexcept
{
    borderType_ = bordertype;
    adjustClientBounds();
}

bool GControl::hasBorder(void) const noexcept
{
    return (borderType_ != GBorderType::noBorder);
}

void GControl::setHint(std::string const& hint) noexcept
{
    hint_ = hint;
}

std::string const& GControl::getHint(void) const noexcept
{
    return hint_;
}

bool GControl::hasHint(void) const noexcept
{
    return (hint_.length() > 0);
}

void GControl::showHint(void) noexcept
{
    showHint_ = true;
}
void GControl::hideHint(void) noexcept
{
    showHint_ = false;
}

bool GControl::getShowHint(void) const noexcept
{
    return showHint_;
}

void GControl::hide(void) noexcept
{
    visible_ = false;
}

void GControl::show(void) noexcept
{
    visible_ = true;
}

bool GControl::isVisible(void) const noexcept
{
    return visible_;
}

int32_t GControl::getWidth(void) const noexcept
{
    return bounds_.getWidth();
}

int32_t GControl::getHeight(void) const noexcept
{
    return bounds_.getHeight();
}

// Private methods
void GControl::adjustClientBounds(void) noexcept
{
    uint8_t borderThikness;

    if (borderType_ == GBorderType::noBorder)
    {
        clientBounds_ = bounds_;
    }
    else
    {
        borderThikness = static_cast<uint8_t>(borderType_);
        clientBounds_.setX(bounds_.getX() + borderThikness);
        clientBounds_.setY(bounds_.getY() + borderThikness);
        clientBounds_.setWidth(bounds_.getWidth() - 2 * borderThikness);
        clientBounds_.setHeight(bounds_.getHeight() - 2 * borderThikness);
    }
}

}  // namespace objects

}  // namespace giotto

/* EOF */
