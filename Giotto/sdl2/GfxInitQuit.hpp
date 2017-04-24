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

#ifndef SdlInitQuit_hpp
#define SdlInitQuit_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxInitQuit final : public GfxRootClass
{
public:
    // Init Video, Audio or Everything ...
    enum class GfxInitComponent
    {
        initVideo,
        initAudio,
        initEverything
    };
    
    // No default constructor
    GfxInitQuit() = delete;
    
    GfxInitQuit(GfxInitComponent gfxInitComp);

    // Copy/Move constructors don't make sense
    GfxInitQuit(const GfxInitQuit&) = delete;
    GfxInitQuit(GfxInitQuit&&) = delete;
    
    // Forbid copy/move assignements
    GfxInitQuit& operator=(const GfxInitQuit&) = delete;
    GfxInitQuit& operator=(GfxInitQuit&&) = delete;
    
    // Explicit destructor to de-init SDL lib
    ~GfxInitQuit();
    
    int getErrorCode() const;
    GfxInitComponent getInitedComponent() const;
private:
    GfxInitComponent gfxInitComp_;
    int errorcode_;
};

#endif /* GfxInitQuit_hpp */