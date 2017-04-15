//
//  GfxWindow.cpp
//  FirstProject
//
//  Created by George Oros on 3/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxWindow.hpp"

GfxWindow::GfxWindow(const std::string& title,const uint16_t width,const uint16_t height) : GfxRootClass("GfxWindow"), title_(title)
{
    window_ = SDL_CreateWindow(title.c_str(), 100, 100, width, height, 0);
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::GfxWindow(GfxWindow&& win) : GfxRootClass("GfxWindow")
{
    window_ = win.window_;
    title_ = win.title_;
    
    win.window_ = nullptr;
    win.title_ = "";
}

GfxWindow::~GfxWindow()
{
    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
    }
}

GfxWindow& GfxWindow::operator=(GfxWindow&& win)
{
    if (this != &win)
    {
        window_ = win.window_;
        title_ = win.title_;
        
        win.window_ = nullptr;
        win.title_ = "";
    }
    return *this;
}

void GfxWindow::destroyWindow()
{
    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

std::unique_ptr<GfxSurface> GfxWindow::getWindowSurface(void)
{
    if (window_ != nullptr)
    {
        SDL_Surface* surf = SDL_GetWindowSurface(window_);
        if (surf != nullptr)
        {
            std::unique_ptr<GfxSurface> ptr {new GfxSurface(surf)};
            return ptr;
        }
    }
    return nullptr;
}

std::string GfxWindow::getTitle() const
{
    return title_;
}

uint16_t GfxWindow::getWidth() const
{
    int w;
    int h;

    SDL_GetWindowSize(window_,&w,&h);
    return w;
}

uint16_t GfxWindow::getHeight() const
{
    int w;
    int h;

    SDL_GetWindowSize(window_,&w,&h);
    return h;
}

void GfxWindow::setTitle(const std::string& title)
{
    title_ = title;
    SDL_SetWindowTitle(window_,title_.c_str());
}
                       
GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const
{
    return window_;
}
