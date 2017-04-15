//
//  GfxCanvas.cpp
//  cpp11sdl
//
//  Created by Familia Oros on 14/04/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxCanvas.hpp"
#include <iostream>
#include <cmath>

GfxCanvas::GfxCanvas(GfxSurface& surf) : surf_(surf)
{
	bgi_.setCanvas(static_cast<uint32_t*>(surf_.surf_->pixels),surf_.surf_->w,surf_.surf_->h);
}

uint8_t compute1(int x, int y)
{
	double dx = (double)x * M_PI / 180.0;
	double dy = (double)y * M_PI / 180.0;
	double r;
	int ic;

    dx += 50.0;
    dy += 50.0;
    r = dx * std::sin(dy) + dy * std::cos(dx) + dx * std::sin(dx) + dy * std::cos(dy);
    r = r * 2.55 + std::tan(r);
    ic = (int)r;
	return ic % 4;
}

uint8_t compute2(int x, int y)
{
    double dx = (double)x * M_PI / 180.0;
    double dy = (double)y * M_PI / 180.0;
    double r;
    int ic;
    
    dx += -50.0;
    dy += -50.0;
    r = std::log(dx * dy) + 2.0 * std::cos(dy * dx) + 2.0 * std::sin(dx * dy);
    ic = (int)r;
    return (ic % 16);
}


void GfxCanvas::paint(void)
{
    for(int i = 0; i < 960; i++)
        for(int j = 0; j < 480; j++)
        {
        	uint8_t c = compute2(i,j);
            surf_.putPixelPrv(i,j,GfxConstants::vga16GetColorByIndex(c));
        }
}

void GfxCanvas::circle(const uint16_t x, const uint16_t y, const uint16_t r)
{
    bgi_.setcolor(SDL_bgi::bgiColors::WHITE);
	bgi_.circle(x,y,r);
}

void GfxCanvas::arc(const uint16_t x,const uint16_t y, const int stangle,const int endangle,const uint16_t radius)
{
	bgi_.setcolor(SDL_bgi::bgiColors::YELLOW);
	bgi_.arc(x,y,stangle,endangle,radius);
}

void GfxCanvas::outtextxy(const uint16_t x, const uint16_t y,std::string text)
{
	bgi_.setcolor(SDL_bgi::bgiColors::LIGHTRED);
	bgi_.outtextxy(x,y,(char *)text.c_str());
}

/********************************************************** SDL_bgi **********************************************************/
GfxCanvas::SDL_bgi::SDL_bgi() : GfxRootClass("GfxCanvas::SDL_bgi")
{
	graphdefaults();
	bgi_activepage = nullptr;
	bgi_maxx = -1;
	bgi_maxy = -1;
}

void GfxCanvas::SDL_bgi::setCanvas(uint32_t* ptr, int maxx, int maxy)
{
	graphdefaults();
	bgi_activepage = ptr;    // active (= being drawn on) page; may be hidden
	bgi_maxx = maxx - 1;
	bgi_maxy = maxy - 1;
}

int GfxCanvas::SDL_bgi::is_in_range (int x, int x1, int x2)
{
    return ((x >= x1) && (x <= x2));
}

// -----

#define PI_CONV (3.1415926 / 180.0)

void GfxCanvas::SDL_bgi::arc (int x, int y, int stangle, int endangle, int radius)
{
    // Draws a circular arc centered at (x, y), with a radius
    // given by radius, traveling from stangle to endangle.
    
    // Quick and dirty for now, Bresenham-based later (maybe)
    
    int angle;
    
    if (0 == radius)
    {
        return;
    }
    
    if (endangle < stangle)
    {
        endangle += 360;
    }
    
    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    bgi_last_arc.xstart = x + (radius * cos (stangle * PI_CONV));
    bgi_last_arc.ystart = y - (radius * sin (stangle * PI_CONV));
    bgi_last_arc.xend = x + (radius * cos (endangle * PI_CONV));
    bgi_last_arc.yend = y - (radius * sin (endangle * PI_CONV));
    
    for (angle = stangle; angle < endangle; angle++)
        line (x + floor (0.5 + (radius * cos (angle * PI_CONV))),
              y - floor (0.5 + (radius * sin (angle * PI_CONV))),
              x + floor (0.5 + (radius * cos ((angle + 1) * PI_CONV))),
              y - floor (0.5 + (radius * sin ((angle + 1) * PI_CONV))));
    
} // arc ()

// -----

void GfxCanvas::SDL_bgi::bar3d (int left, int top, int right, int bottom, int depth, int topflag)
{
    // Draws a three-dimensional, filled-in rectangle (bar), using
    // the current fill colour and fill pattern.
    
    bgiColors tmp;
    bgiColors tmpcolor;
    
    tmp = bgi_fg_color;
    
    if (bgiFillStyles::EMPTY_FILL == bgi_fill_style.pattern)
    {
        tmpcolor = bgi_bg_color;
    }
    else // all other styles
    {
        tmpcolor = bgi_fill_style.color;
    }
    
    setcolor (tmpcolor); // fill
    bar (left, top, right, bottom);
    setcolor (tmp); // outline
    if (depth > 0)
    {
        line (left, top, left + depth, top - depth);
        line (left + depth, top - depth, right + depth, top - depth);
        line (right, top, right + depth, top - depth);
        line (right, bottom, right + depth, bottom - depth);
        line (right + depth, bottom - depth, right + depth, top - depth);
    }
    rectangle (left, top, right, bottom);
    
    // topflag - what should I do with it?
    
} // bar3d ()

// -----

void GfxCanvas::SDL_bgi::bar (int left, int top, int right, int bottom)
{
    // Draws a filled-in rectangle (bar), using the current fill colour
    // and fill pattern.
    
    int y;
    bgiLineThickness tmpthickness;
    bgiColors tmp;
    bgiColors tmpcolor;
    
    tmp = bgi_fg_color;
    
    if (bgiFillStyles::EMPTY_FILL == bgi_fill_style.pattern)
    {
        tmpcolor = bgi_bg_color;
    }
    else // all other styles
    {
        tmpcolor = bgi_fill_style.color;
    }
    
    setcolor (tmpcolor);
    tmpthickness = bgi_line_style.thickness;
    bgi_line_style.thickness = bgiLineThickness::NORM_WIDTH;
    
    if (bgiFillStyles::SOLID_FILL == bgi_fill_style.pattern)
    {
        for (y = top; y <= bottom; y++)
        {
            line (left, y, right, y);
        }
    }
    else
    {
        for (y = top; y <= bottom; y++)
        {
            line_fill (left, y, right, y);
        }
    }
    
    setcolor (tmp);
    bgi_line_style.thickness = tmpthickness;
    
} // bar ()

// -----

void GfxCanvas::SDL_bgi::circle_bresenham (int x, int y, int radius)
{
    // Draws a circle of the given radius at (x, y).
    // Adapted from:
    // http://members.chello.at/easyfilter/bresenham.html
    
    int xx = -radius;
    int yy = 0;
    int err = 2 - 2 * radius;
    
    do
    {
        _putpixel (x - xx, y + yy); //  I  quadrant
        _putpixel (x - yy, y - xx); //  II quadrant
        _putpixel (x + xx, y - yy); //  III quadrant
        _putpixel (x + yy, y + xx); //  IV quadrant
        radius = err;
        
        if (radius <= yy)
        {
            yy += 1;
            err += yy * 2 + 1;
        }
        
        if ((radius > xx) || (err > yy))
        {
            xx += 1;
            err += xx * 2 + 1;
        }
    }
    while (xx < 0);
    
} // circle_bresenham ();

// -----

void GfxCanvas::SDL_bgi::circle (int x, int y, int radius)
{
    // Draws a circle of the given radius at (x, y).
    
    // the Bresenham algorithm draws a better-looking circle
    
    if (bgiLineThickness::NORM_WIDTH == bgi_line_style.thickness)
    {
        circle_bresenham (x, y, radius);
    }
    else
    {
        arc (x, y, 0, 360, radius);
    }
    
} // circle ();

// -----

void GfxCanvas::SDL_bgi::cleardevice (void)
{
    // Clears the graphics screen, filling it with the current
    // background color.
    
    int x;
    int y;
    
    bgi_cp_x = 0;
    bgi_cp_y = 0;
    
    for (x = 0; x < bgi_maxx + 1; x++)
    {
        for (y = 0; y < bgi_maxy + 1; y++)
        {
            bgi_activepage [y * (bgi_maxx + 1) + x] = palette[static_cast<int>(bgi_bg_color)];
        }
    }
    
} // cleardevice ()

// -----

void GfxCanvas::SDL_bgi::clearviewport (void)
{
    // Clears the viewport, filling it with the current
    // background color.
    
    int x;
    int y;
    
    bgi_cp_x = bgi_cp_y = 0;
    
    for (x = vp.left; x < vp.right + 1; x++)
    {
        for (y = vp.top; y < vp.bottom + 1; y++)
        {
            bgi_activepage [y * (bgi_maxx + 1) + x] = palette[static_cast<int>(bgi_bg_color)];
        }
    }
    
} // clearviewport ()

// -----

void GfxCanvas::SDL_bgi::drawpoly (int numpoints, int *polypoints)
{
    // Draws a polygon of numpoints vertices.
    
    int n;
    
    for (n = 0; n < numpoints - 1; n++)
    {
        line (polypoints[2*n], polypoints[2*n + 1],
              polypoints[2*n + 2], polypoints[2*n + 3]);
    }
    // close the polygon
    line (polypoints[2*n], polypoints[2*n + 1],
          polypoints[0], polypoints[1]);
    
} // drawpoly ()

// -----

void GfxCanvas::SDL_bgi::swap_if_greater (int *x1, int *x2)
{
    int tmp;
    
    if (*x1 > *x2)
    {
        tmp = *x1;
        *x1 = *x2;
        *x2 = tmp;
    }
    
} // swap_if_greater ()

// -----

void GfxCanvas::SDL_bgi::ellipse (int x, int y, int stangle, int endangle,
                                  int xradius, int yradius)
{
    // Draws an elliptical arc centered at (x, y), with axes given by
    // xradius and yradius, traveling from stangle to endangle.
    
    // Bresenham-based if complete
    int angle;
    
    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }
    
    if (endangle < stangle)
    {
        endangle += 360;
    }
    
    // draw complete ellipse
    if (0 == stangle && 360 == endangle)
    {
        _ellipse (x, y, xradius, yradius);
        return;
    }
    
    // needed?
    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    
    for (angle = stangle; angle < endangle; angle++)
    {
        line (x + (xradius * cos (angle * PI_CONV)),
              y - (yradius * sin (angle * PI_CONV)),
              x + (xradius * cos ((angle+1) * PI_CONV)),
              y - (yradius * sin ((angle+1) * PI_CONV)));
    }
    
} // ellipse ()

// -----

// Yeah, replicated code. The thing is, I can't catch the bug.

void GfxCanvas::SDL_bgi::_ellipse (int cx, int cy, int xradius, int yradius)
{
    // from "A Fast Bresenham Type Algorithm For Drawing Ellipses"
    // by John Kennedy
    
    int x;
    int y;
    int xchange;
    int ychange;
    int ellipseerror;
    int TwoASquare;
    int TwoBSquare;
    int StoppingX;
    int StoppingY;

    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }
    
    TwoASquare = 2 * xradius * xradius;
    TwoBSquare = 2 * yradius * yradius;
    x = xradius;
    y = 0;
    xchange = yradius * yradius * (1 - 2 * xradius);
    ychange = xradius * xradius;
    ellipseerror = 0;
    StoppingX = TwoBSquare * xradius;
    StoppingY = 0;
    
    while (StoppingX >= StoppingY)
    {
        
        // 1st set of points, y' > -1
        
        // normally, I'd put the line_fill () code here; but
        // the outline gets overdrawn, can't find out why.
        _putpixel (cx + x, cy - y);
        _putpixel (cx - x, cy - y);
        _putpixel (cx - x, cy + y);
        _putpixel (cx + x, cy + y);
        y++;
        StoppingY += TwoASquare;
        ellipseerror += ychange;
        ychange +=TwoASquare;
        
        if ((2 * ellipseerror + xchange) > 0 )
        {
            x--;
            StoppingX -= TwoBSquare;
            ellipseerror +=xchange;
            xchange += TwoBSquare;
        }
    } // while
    
    // 1st point set is done; start the 2nd set of points
    
    x = 0;
    y = yradius;
    xchange = yradius*yradius;
    ychange = xradius*xradius*(1 - 2*yradius);
    ellipseerror = 0;
    StoppingX = 0;
    StoppingY = TwoASquare*yradius;
    
    while (StoppingX <= StoppingY )
    {
        
        // 2nd set of points, y' < -1
        
        _putpixel (cx + x, cy - y);
        _putpixel (cx - x, cy - y);
        _putpixel (cx - x, cy + y);
        _putpixel (cx + x, cy + y);
        x++;
        StoppingX += TwoBSquare;
        ellipseerror += xchange;
        xchange +=TwoBSquare;
        if ((2 * ellipseerror + ychange) > 0) {
            y--;
            StoppingY -= TwoASquare;
            ellipseerror += ychange;
            ychange +=TwoASquare;
        }
    }
    
} // _ellipse ()

// -----

void GfxCanvas::SDL_bgi::fillellipse (int cx, int cy, int xradius, int yradius)
{
    // Draws an ellipse centered at (x, y), with axes given by
    // xradius and yradius, and fills it using the current fill color
    // and fill pattern.
    
    // from "A Fast Bresenham Type Algorithm For Drawing Ellipses"
    // by John Kennedy
    
    int x;
    int y;
    int xchange;
    int ychange;
    int ellipseerror;
    int TwoASquare;
    int TwoBSquare;
    int StoppingX;
    int StoppingY;

    if ((0 == xradius) && (0 == yradius))
        return;
    
    TwoASquare = 2 * xradius * xradius;
    TwoBSquare = 2 * yradius * yradius;
    x = xradius;
    y = 0;
    xchange = yradius * yradius * (1 - 2 * xradius);
    ychange = xradius * xradius;
    ellipseerror = 0;
    StoppingX = TwoBSquare * xradius;
    StoppingY = 0;
    
    while (StoppingX >= StoppingY)
    {
        
        // 1st set of points, y' > -1
        
        line_fill (cx + x, cy - y, cx - x, cy - y);
        line_fill (cx - x, cy + y, cx + x, cy + y);
        y++;
        StoppingY += TwoASquare;
        ellipseerror += ychange;
        ychange +=TwoASquare;
        
        if ((2 * ellipseerror + xchange) > 0 )
        {
            x--;
            StoppingX -= TwoBSquare;
            ellipseerror +=xchange;
            xchange += TwoBSquare;
        }
    } // while
    
    // 1st point set is done; start the 2nd set of points
    
    x = 0;
    y = yradius;
    xchange = yradius * yradius;
    ychange = xradius * xradius * (1 - 2 * yradius);
    ellipseerror = 0;
    StoppingX = 0;
    StoppingY = TwoASquare * yradius;
    
    while (StoppingX <= StoppingY ) {
        
        // 2nd set of points, y' < -1
        
        line_fill (cx + x, cy - y, cx - x, cy - y);
        line_fill (cx - x, cy + y, cx + x, cy + y);
        x++;
        StoppingX += TwoBSquare;
        ellipseerror += xchange;
        xchange +=TwoBSquare;
        if ((2 * ellipseerror + ychange) > 0)
        {
            y--;
            StoppingY -= TwoASquare;
            ellipseerror += ychange;
            ychange +=TwoASquare;
        }
    }
    
    // outline
    
    _ellipse (cx, cy, xradius, yradius);
    
} // _ellipse ()

// -----

// helper function for fillpoly ()

static int intcmp (const void *n1, const void *n2)
{
    return (*(const int *) n1) - (*(const int *) n2);
}

// -----

// the following function was adapted from the public domain
// code by Darel Rex Finley,
// http://alienryderflex.com/polygon_fill/

void GfxCanvas::SDL_bgi::fillpoly (int numpoints, int *polypoints)
{
    // Draws a polygon of numpoints vertices and fills it using the
    // current fill color.
    
    int nodes;      // number of nodes
    int* nodeX;     // array of nodes
    int ymin;
    int ymax;
    int pixelY;
    int i;
    int j;
    bgiColors tmp;
    bgiColors tmpcolor;

    nodeX = (int *)calloc (sizeof (int), numpoints);
    if (NULL == nodeX) {
        /* fprintf (stderr, "Can't allocate memory for fillpoly()\n"); */
        return;
    }
    
    tmp = bgi_fg_color;
    if (bgiFillStyles::EMPTY_FILL == bgi_fill_style.pattern)
    {
        tmpcolor = bgi_bg_color;
    }
    else // all other styles
    {
        tmpcolor = bgi_fill_style.color;
    }
    
    setcolor (tmpcolor);
    
    // find Y maxima
    
    ymin = ymax = polypoints[1];
    
    for (i = 0; i < 2 * numpoints; i += 2)
    {
        if (polypoints[i + 1] < ymin)
        {
            ymin = polypoints[i + 1];
        }
        if (polypoints[i + 1] > ymax)
        {
            ymax = polypoints[i + 1];
        }
    }
    
    //  Loop through the rows of the image.
    for (pixelY = ymin; pixelY < ymax; pixelY++)
    {
        
        //  Build a list of nodes.
        nodes = 0;
        j = 2 * numpoints - 2;
        
        for (i = 0; i < 2 * numpoints; i += 2)
        {
            if (
                ((float) polypoints[i + 1] < (float)  pixelY && (float) polypoints[j + 1] >= (float) pixelY) ||
                ((float) polypoints[j + 1] < (float)  pixelY && (float) polypoints[i + 1] >= (float) pixelY))
            {
                nodeX[nodes++] =
                (int) (polypoints[i] + (pixelY - (float) polypoints[i + 1]) /
                       ((float) polypoints[j + 1] - (float) polypoints[i + 1]) *
                       (polypoints[j] - polypoints[i]));
            }
            j = i;
        }
        
        // sort the nodes
        qsort (nodeX, nodes, sizeof (int), intcmp);
        
        // fill the pixels between node pairs.
        for (i = 0; i < nodes; i += 2)
        {
            if (bgiFillStyles::SOLID_FILL == bgi_fill_style.pattern)
            {
                line (nodeX[i], pixelY, nodeX[i + 1], pixelY);
            }
            else
            {
                line_fill (nodeX[i], pixelY, nodeX[i + 1], pixelY);
            }
        }
        
    } //   for pixelY
    
    setcolor (tmp);
    drawpoly (numpoints, polypoints);
    
    free(nodeX);
    
} // fillpoly ()

// -----

void GfxCanvas::SDL_bgi::ff_putpixel (int x, int y)
{
    // similar to putpixel (), but uses fill patterns
    
    x += vp.left;
    y += vp.top;
    
    // if the corresponding bit in the pattern is 1
    if ( (fill_patterns[static_cast<int>(bgi_fill_style.pattern)][y % 8] >> x % 8) & 1)
    {
        putpixel_copy (x, y, palette[static_cast<int>(bgi_fill_style.color)]);
    }
    else
    {
        putpixel_copy (x, y, palette[static_cast<int>(bgi_bg_color)]);
    }
    
} // ff_putpixel ()

// -----

// the following code is adapted from "A Seed Fill Algorithm"
// by Paul Heckbert, "Graphics Gems", Academic Press, 1990

// Filled horizontal segment of scanline y for xl<=x<=xr.
// Parent segment was on line y-dy. dy=1 or -1

typedef struct {
    int y;
    int xl;
    int xr;
    int dy;
} Segment;

// max depth of stack - was 10000

#define STACKSIZE 2000

Segment stack[STACKSIZE];
Segment* sp = stack; // stack of filled segments

// the following functions were implemented as unreadable macros

static inline void ff_push (int y, int xl, int xr, int dy, int bottom, int top)
{
    // push new segment on stack
    if ((sp < stack + STACKSIZE) && (y + dy >= 0) &&
        ((y + dy) <= (bottom - top)) )
    {
        sp->y = y;
        sp->xl = xl;
        sp->xr = xr;
        sp->dy = dy;
        sp++;
    }
}

// -----

static inline void ff_pop (int *y, int *xl, int *xr, int *dy)
{
    // pop segment off stack
    sp--;
    *dy = sp->dy;
    *y = sp->y + *dy;
    *xl = sp->xl;
    *xr = sp->xr;
}

// -----

// fill: set the pixel at (x,y) and all of its 4-connected neighbors
// with the same pixel value to the new pixel value nv.
// A 4-connected neighbor is a pixel above, below, left, or right of a pixel.

void GfxCanvas::SDL_bgi::_floodfill (int x, int y, bgiColors border)
{
    // Fills an enclosed area, containing the x and y points bounded by
    // the border color. The area is filled using the current fill color.
    
    int start;
    int x1;
    int x2;
    int dy = 0;
    unsigned int oldcol;
  
    oldcol = getpixel (x, y);
    ff_push (y, x, x, 1,vp.bottom ,vp.top);           // needed in some cases
    ff_push (y + 1, x, x, -1,vp.bottom , vp.top);      // seed segment (popped 1st)
    
    while (sp > stack)
    {
        
        // pop segment off stack and fill a neighboring scan line
        
        ff_pop (&y, &x1, &x2, &dy);
        
        // segment of scan line y-dy for x1<=x<=x2 was previously filled,
        // now explore adjacent pixels in scan line y
        
        for (x = x1; x >= 0 && getpixel (x, y) == oldcol; x--)
        {
            ff_putpixel (x, y);
        }
        
        if (x >= x1)
        {
            for (x++; x <= x2 && getpixel (x, y) == static_cast<int>(border); x++)
            {
                ;
            }
            start = x;
            if (x > x2)
            {
                continue;
            }
        }
        else
        {
            start = x + 1;
            if (start < x1)
            {
                ff_push (y, start, x1 - 1, -dy,vp.bottom , vp.top);    // leak on left?
            }
            x = x1 + 1;
        }
        
        do
        {
            for (x1 = x; x <= vp.right && getpixel (x, y) != static_cast<int>(border); x++)
            {
                ff_putpixel (x, y);
            }
            ff_push (y, start, x - 1, dy,vp.bottom , vp.top);
            if (x > x2 + 1)
            {
                ff_push (y, x2 + 1, x - 1, -dy,vp.bottom, vp.top);    // leak on right?
            }
            for (x++; x <= x2 && getpixel (x, y) == static_cast<int>(border); x++)
            {
                ;
            }
            start = x;
        }
        while (x <= x2);
        
    } // while
    
} // floodfill ()

// -----

#define random(range) (rand() % (range))

void GfxCanvas::SDL_bgi::floodfill (int x, int y, bgiColors border)
{
    bgiColors oldcol;
    int found;
    bgiFillStyles tmp_pattern;
    bgiColors tmp_color;

    oldcol = static_cast<bgiColors>(getpixel (x, y));
    
    // the way the above implementation of floodfill works,
    // the fill colour must be different than the border colour
    // and the current shape's background color.
    
    if ((oldcol == border) || (oldcol == bgi_fill_style.color) ||
        (x < 0) || (x > vp.right - vp.left) || // out of viewport/window?
        (y < 0) || (y > vp.bottom - vp.top))
    {
        return;
    }
    
    // special case for fill patterns. The background colour can't be
    // the same in the area to be filled and in the fill pattern.
    
    if (bgiFillStyles::SOLID_FILL == bgi_fill_style.pattern)
    {
        _floodfill (x, y, border);
        return;
    }
    else
    { // fill patterns
        if (bgi_bg_color == oldcol)
        {
            // solid fill first...
            tmp_pattern = bgi_fill_style.pattern;
            bgi_fill_style.pattern = bgiFillStyles::SOLID_FILL;
            tmp_color = bgi_fill_style.color;
            // find a suitable temporary fill colour; it must be different
            // than the border and the background
            found = false;
            while (!found)
            {
                bgi_fill_style.color = static_cast<bgiColors>(static_cast<int>(bgiColors::BLUE) + random (static_cast<int>(bgiColors::WHITE)));
                if ((oldcol != bgi_fill_style.color) &&
                    (border != bgi_fill_style.color))
                {
                    found = true;
                }
            }
            _floodfill (x, y, border);
            // ...then pattern fill
            bgi_fill_style.pattern = tmp_pattern;
            bgi_fill_style.color = tmp_color;
            _floodfill (x, y, border);
        }
        else
        {
            _floodfill (x, y, border);
        }
    }

} // floodfill ()

// -----

void GfxCanvas::SDL_bgi::getarccoords (struct arccoordstype *arccoords)
{
    // Gets the coordinates of the last call to arc(), filling the
    // arccoords structure.
    
    arccoords->x = bgi_last_arc.x;
    arccoords->y = bgi_last_arc.y;
    arccoords->xstart = bgi_last_arc.xstart;
    arccoords->ystart = bgi_last_arc.ystart;
    arccoords->xend = bgi_last_arc.xend;
    arccoords->yend = bgi_last_arc.yend;
} // getarccoords ()

// -----

GfxCanvas::SDL_bgi::bgiColors GfxCanvas::SDL_bgi::getbkcolor (void)
{
    // Returns the current background color.
    
    return bgi_bg_color;
} // getbkcolor ()

// -----

GfxCanvas::SDL_bgi::bgiColors GfxCanvas::SDL_bgi::getcolor (void)
{
    // Returns the current drawing (foreground) color.
    
    return bgi_fg_color;
} // getcolor ()

// -----

struct GfxCanvas::SDL_bgi::palettetype *GfxCanvas::SDL_bgi::getdefaultpalette (void)
{
    return &pal;
} // getdefaultpalette ()

// -----

void GfxCanvas::SDL_bgi::getfillpattern (char *pattern)
{
    // Copies the user-defined fill pattern, as set by setfillpattern,
    // into the 8-byte area pointed to by pattern.
    
    int i;
    
    for (i = 0; i < 8; i++)
    {
        pattern[i] = (char) fill_patterns[static_cast<int>(bgiFillStyles::USER_FILL)][i];
    }
    
} // getfillpattern ()

// -----

void GfxCanvas::SDL_bgi::getfillsettings (struct fillsettingstype *fillinfo)
{
    // Fills the fillsettingstype structure pointed to by fillinfo
    // with information about the current fill pattern and fill color.
    
    fillinfo->pattern = bgi_fill_style.pattern;
    fillinfo->color = bgi_fill_color;
} // getfillsettings ()

// -----

void GfxCanvas::SDL_bgi::getimage (int left, int top, int right, int bottom, void *bitmap)
{
    // Copies a bit image of the specified region into the memory
    // pointed by bitmap.
    
    uint32_t bitmap_w;
    uint32_t bitmap_h;
    uint32_t* tmp;
    int i = 2;
    int x;
    int y;
    
    // bitmap has already been malloc()'ed by the user.
    tmp = (uint32_t *)bitmap;
    bitmap_w = right - left + 1;
    bitmap_h = bottom - top + 1;
    
    // copy width and height to the beginning of bitmap
    memcpy (tmp, &bitmap_w, sizeof (uint32_t));
    memcpy (tmp + 1, &bitmap_h, sizeof (uint32_t));
    
    // copy image to bitmap
    for (y = top + vp.top; y <= bottom + vp.top; y++)
    {
        for (x = left + vp.left; x <= right + vp.left; x++)
        {
            tmp [i++] = getpixel_raw (x, y);
        }
    }
} // getimage ()

// -----

void GfxCanvas::SDL_bgi::getlinesettings (struct linesettingstype *lineinfo)
{
    // Fills the linesettingstype structure pointed by lineinfo with
    // information about the current line style, pattern, and thickness.
    
    lineinfo->linestyle = bgi_line_style.linestyle;
    lineinfo->upattern = bgi_line_style.upattern;
    lineinfo->thickness = bgi_line_style.thickness;
} // getlinesettings ();

// -----

int GfxCanvas::SDL_bgi::getmaxcolor (void)
{
    // Returns the maximum color value available (MAXCOLORS).
    
    return PALETTE_SIZE;
} // getmaxcolor ()

// -----

int GfxCanvas::SDL_bgi::getmaxx ()
{
    // Returns the maximum x screen coordinate.
    
    return bgi_maxx;
} // getmaxx ()

// -----

int GfxCanvas::SDL_bgi::getmaxy ()
{
    // Returns the maximum y screen coordinate.
    
    return bgi_maxy;
} // getmaxy ()

// -----

void GfxCanvas::SDL_bgi::getpalette (struct palettetype *palette)
{
    // Fills the palettetype structure pointed by palette with
    // information about the current palette’s size and colors.
    
    int i;
    
    for (i = 0; i <= MAXCOLORS; i++)
    {
        palette->colors[i] = pal.colors[i];
    }

} // getpalette ()

// -----

int GfxCanvas::SDL_bgi::getpalettesize (struct palettetype *palette)
{
    // Returns the size of the palette.
    
    // !!! BUG - don't ignore the parameter
    return 1 + MAXCOLORS + 3 + PALETTE_SIZE;
} // getpalettesize ()

// -----

uint32_t GfxCanvas::SDL_bgi::getpixel_raw (int x, int y)
{
    return bgi_activepage [y * (bgi_maxx + 1) + x];
} // getpixel_raw ()

// -----

unsigned int GfxCanvas::SDL_bgi::getpixel (int x, int y)
{
    // Returns the color of the pixel located at (x, y).
    
    int col;
    uint32_t tmp;
    
    x += vp.left;
    y += vp.top;
    
    // out of screen?
    if (! is_in_range (x, 0, bgi_maxx) &&
        ! is_in_range (y, 0, bgi_maxy))
    {
        return static_cast<int>(bgi_bg_color);
    }
    
    tmp = getpixel_raw (x, y);
    
    // now find the colour
    
    for (col = static_cast<int>(bgiColors::BLACK); col < static_cast<int>(bgiColors::WHITE) + 1; col++)
    {
        if (tmp == palette[col])
        {
            return static_cast<int>(col);
        }
    }
    
    // if it's not a BGI color, just return the 0xAARRGGBB value
    return tmp;

} // getpixel ()

// -----

void GfxCanvas::SDL_bgi::gettextsettings (struct textsettingstype *texttypeinfo)
{
    // Fills the textsettingstype structure pointed to by texttypeinfo
    // with information about the current text font, direction, size,
    // and justification.
    
    texttypeinfo->font = bgi_txt_style.font;
    texttypeinfo->direction = bgi_txt_style.direction;
    texttypeinfo->charsize = bgi_txt_style.charsize;
    texttypeinfo->horiz = bgi_txt_style.horiz;
    texttypeinfo->vert = bgi_txt_style.vert;
} // gettextsettings ()

// -----

void GfxCanvas::SDL_bgi::getviewsettings (struct viewporttype *viewport)
{
    // Fills the viewporttype structure pointed to by viewport with
    // information about the current viewport.
    
    viewport->left = vp.left;
    viewport->top = vp.top;
    viewport->right = vp.right;
    viewport->bottom = vp.bottom;
    viewport->clip = vp.clip;
} // getviewsettings ()

// -----

int GfxCanvas::SDL_bgi::getx (void)
{
    // Returns the current viewport’s x coordinate.
    
    return bgi_cp_x;
} // getx ()

// -----

int GfxCanvas::SDL_bgi::gety (void)
{
    // Returns the current viewport’s y coordinate.
    
    return bgi_cp_y;
} // gety ()

// -----

void GfxCanvas::SDL_bgi::graphdefaults (void)
{
    // Resets all graphics settings to their defaults.
    
    int i;
    
    initpalette ();
    
    // initialise the graphics writing mode
    bgi_writemode = bgiDrawingMode::COPY_PUT;
    
    // initialise the viewport
    vp.left = 0;
    vp.top = 0;
    
    vp.right = bgi_maxx;
    vp.bottom = bgi_maxy;
    vp.clip = false;
    
    // initialise the CP
    bgi_cp_x = 0;
    bgi_cp_y = 0;
    
    // initialise the text settings
    bgi_txt_style.font = bgiFonts::DEFAULT_FONT;
    bgi_txt_style.direction = bgiDirection::HORIZ_DIR;
    bgi_txt_style.charsize = 1;
    bgi_txt_style.horiz = bgiTextJustification::LEFT_TEXT;
    bgi_txt_style.vert = bgiTextJustification::TOP_TEXT;
    
    // initialise the fill settings
    bgi_fill_style.pattern =  bgiFillStyles::SOLID_FILL;
    bgi_fill_style.color = bgiColors::WHITE;
    
    // initialise the line settings
    bgi_line_style.linestyle = bgiLineStyle::SOLID_LINE;
    bgi_line_style.upattern = bgiFillStyles::SOLID_FILL;
    bgi_line_style.thickness = bgiLineThickness::NORM_WIDTH;
    
    // initialise the palette
    pal.size = 1 + MAXCOLORS;
    for (i = 0; i < MAXCOLORS + 1; i++)
    {
        pal.colors[i] = i;
    }
    
} // graphdefaults ()

// -----

unsigned GfxCanvas::SDL_bgi::imagesize (int left, int top, int right, int bottom)
{
    // Returns the size in bytes of the memory area required to store
    // a bit image.
    
    return 2 * sizeof(uint32_t) + // witdth, height
    (right - left + 1) * (bottom - top + 1) * sizeof (uint32_t);
} // imagesize ()

// -----

void GfxCanvas::SDL_bgi::initpalette (void)
{
    int i;
    
    for (i = static_cast<int>(bgiColors::BLACK); i < static_cast<int>(bgiColors::WHITE) + 1; i++)
    {
        palette[i] = bgi_palette[i];
    }
} // initpalette ()

// -----

// Bresenham's line algorithm routines that implement logical 
// operations: copy, xor, and, or, not.

void GfxCanvas::SDL_bgi::line_copy (int x1, int y1, int x2, int y2)
{
    int counter = 0; // # of pixel plotted
    int dx = abs (x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs (y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    for (;;)
    {
        
        // plot the pixel only if the corresponding bit
        // in the current pattern is set to 1
        
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_copy (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_copy (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }
        
        counter++;
        
        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    } // for

} // line_copy ()

// -----

void GfxCanvas::SDL_bgi::line_xor (int x1, int y1, int x2, int y2)
{
    int counter = 0; // # of pixel plotted
    int dx = abs (x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs (y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    for (;;)
    {
        
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_xor (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_xor (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }
        
        counter++;
        
        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    } // for
    
} // line_xor ()

// -----

void GfxCanvas::SDL_bgi::line_and (int x1, int y1, int x2, int y2)
{
    int counter = 0; // # of pixel plotted
    int dx = abs (x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs (y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    for (;;)
    {
        
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_and (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_and (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }
        
        counter++;
        
        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    } // for
    
} // line_and ()

// -----

void GfxCanvas::SDL_bgi::line_or (int x1, int y1, int x2, int y2)
{
    int counter = 0; // # of pixel plotted
    int dx = abs (x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs (y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    for (;;)
    {
        
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_or (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_or (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }
        
        counter++;
        
        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    } // for
    
} // line_or ()

// -----

void GfxCanvas::SDL_bgi::line_not (int x1, int y1, int x2, int y2)
{
    int counter = 0; // # of pixel plotted
    int dx = abs (x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs (y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    for (;;)
    {
        
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_not (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_not (x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }
        
        counter++;
        
        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    } // for
    
} // line_not ()

// -----

void GfxCanvas::SDL_bgi::line_fill (int x1, int y1, int x2, int y2)
{
    // line routin used for filling
    
    int dx = abs (x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs (y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    for (;;)
    {
        
        ff_putpixel (x1, y1);
        
        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    } // for
    
} // line_fill ()

// -----

int GfxCanvas::SDL_bgi::octant (int x, int y)
{
    // returns the octant where x, y lies.
    
    if (x >= 0)
    { // octants 1, 2, 7, 8
        
        if (y >= 0)
        {
            return (x > y) ? 1 : 2;
        }
        else
        {
            return (x > -y) ? 8 : 7;
        }
        
    } // if (x > 0)
    else
    { // x < 0; 3, 4, 5, 6
        
        if (y >= 0)
        {
            return (-x > y) ? 4 : 3;
        }
        else
        {
            return (-x > -y) ? 5 : 6;
        }
        
    } // else
    
} // octant()

// -----

void GfxCanvas::SDL_bgi::line (int x1, int y1, int x2, int y2)
{
    // Draws a line between two specified points.
    
    int oct;
    
    // viewport
    x1 += vp.left;
    y1 += vp.top;
    x2 += vp.left;
    y2 += vp.top;
    
    switch (bgi_writemode)
    {
            
        case bgiDrawingMode::COPY_PUT:
            line_copy (x1, y1, x2, y2);
            break;
            
        case bgiDrawingMode::AND_PUT:
            line_and (x1, y1, x2, y2);
            break;
            
        case bgiDrawingMode::XOR_PUT:
            line_xor (x1, y1, x2, y2);
            break;
            
        case bgiDrawingMode::OR_PUT:
            line_or (x1, y1, x2, y2);
            break;
            
        case bgiDrawingMode::NOT_PUT:
            line_not (x1, y1, x2, y2);
            break;
            
    } // switch
    
    if (bgiLineThickness::THICK_WIDTH == bgi_line_style.thickness)
    {
        
        oct = octant (x2 - x1, y1 - y2);
        
        switch (oct) { // draw thick line
                
            case 1:
            case 4:
            case 5:
            case 8:
                switch (bgi_writemode) {
                    case bgiDrawingMode::COPY_PUT:
                        line_copy (x1, y1 - 1, x2, y2 - 1);
                        line_copy (x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::AND_PUT:
                        line_and (x1, y1 - 1, x2, y2 - 1);
                        line_and (x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::XOR_PUT:
                        line_xor (x1, y1 - 1, x2, y2 - 1);
                        line_xor (x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::OR_PUT:
                        line_or (x1, y1 - 1, x2, y2 - 1);
                        line_or (x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::NOT_PUT:
                        line_not (x1, y1 - 1, x2, y2 - 1);
                        line_not (x1, y1 + 1, x2, y2 + 1);
                        break;
                } // switch
                break;
                
            case 2:
            case 3:
            case 6:
            case 7:
                switch (bgi_writemode) {
                    case bgiDrawingMode::COPY_PUT:
                        line_copy (x1 - 1, y1, x2 - 1, y2);
                        line_copy (x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::AND_PUT:
                        line_and (x1 - 1, y1, x2 - 1, y2);
                        line_and (x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::XOR_PUT:
                        line_xor (x1 - 1, y1, x2 - 1, y2);
                        line_xor (x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::OR_PUT:
                        line_or (x1 - 1, y1, x2 - 1, y2);
                        line_or (x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::NOT_PUT:
                        line_not (x1 - 1, y1, x2 - 1, y2);
                        line_not (x1 + 1, y1, x2 + 1, y2);
                        break;
                } // switch
                break;
                
        } // switch
        
    } // if (THICK_WIDTH...)
    
} // line ()

// -----

void GfxCanvas::SDL_bgi::linerel (int dx, int dy)
{
    // Draws a line from the CP to a point that is (dx,dy)
    // pixels from the CP.
    
    line (bgi_cp_x, bgi_cp_y, bgi_cp_x + dx, bgi_cp_y + dy);
    bgi_cp_x += dx;
    bgi_cp_y += dy;
} // linerel ()

// -----

void GfxCanvas::SDL_bgi::lineto (int x, int y)
{
    // Draws a line from the CP to (x, y), then moves the CP to (dx, dy).
    
    line (bgi_cp_x, bgi_cp_y, x, y);
    bgi_cp_x = x;
    bgi_cp_y = y;
} // lineto ()

void GfxCanvas::SDL_bgi::moverel (int dx, int dy)
{
    // Moves the CP by (dx, dy) pixels.
    
    bgi_cp_x += dx;
    bgi_cp_y += dy;
} // moverel ()

// -----

void GfxCanvas::SDL_bgi::moveto (int x, int y)
{
    // Moves the CP to the position (x, y), relative to the viewport.
    
    bgi_cp_x = x;
    bgi_cp_y = y;
} // moveto ()

// -----

void GfxCanvas::SDL_bgi::_bar (int left, int top, int right, int bottom)
{
    // service routine
    int y;
    bgiColors tmp;
    
    // like bar (), but uses bgi_fg_color
    
    tmp = bgi_fg_color;
    // setcolor (bgi_fg_color);
    for (y = top; y <= bottom; y++)
    {
        line (left, y, right, y);
    }
    
    setcolor (tmp);
} // _bar ()

// -----

void GfxCanvas::SDL_bgi::drawchar (unsigned char ch)
{
    // used by outtextxy ()
    
    unsigned char i;
    unsigned char j;
    unsigned char k;
    int x;
    int y;
    bgiColors tmp;
    
    tmp = bgi_bg_color;
    bgi_bg_color = bgi_fg_color; // for bar ()
    setcolor (bgi_bg_color);
    
    // for each of the 8 bytes that make up the font
    
    for (i = 0; i < 8; i++)
    {
        
        k = fontptr[8*ch + i];
        
        // scan horizontal line
        
        for (j = 0; j < 8; j++)
        {
            
            if ( (k << j) & 0x80)
            { // bit set to 1
                if (bgiDirection::HORIZ_DIR == bgi_txt_style.direction)
                {
                    x = bgi_cp_x + j * bgi_font_mag_x;
                    y = bgi_cp_y + i * bgi_font_mag_y;
                    // putpixel (x, y, bgi_fg_color);
                    _bar (x, y, x + bgi_font_mag_x - 1, y + bgi_font_mag_y - 1);
                }
                else
                {
                    x = bgi_cp_x + i * bgi_font_mag_y;
                    y = bgi_cp_y - j * bgi_font_mag_x;
                    // putpixel (bgi_cp_x + i, bgi_cp_y - j, bgi_fg_color);
                    _bar (x, y, x + bgi_font_mag_x - 1, y + bgi_font_mag_y - 1);
                }
            }
        }
    }
    
    if (bgiDirection::HORIZ_DIR == bgi_txt_style.direction)
    {
        bgi_cp_x += 8 * bgi_font_mag_x;
    }
    else
    {
        bgi_cp_y -= 8 * bgi_font_mag_y;
    }
    
    bgi_bg_color = tmp;
    
} // drawchar ()

// -----

void GfxCanvas::SDL_bgi::outtext (char *textstring)
{
    // Outputs textstring at the CP.
    
    outtextxy (bgi_cp_x, bgi_cp_y, textstring);
    if ( (bgiDirection::HORIZ_DIR == bgi_txt_style.direction) &&
        (bgiTextJustification::LEFT_TEXT == bgi_txt_style.horiz))
    {
        bgi_cp_x += textwidth (textstring);
    }
} // outtext ()

// -----

void GfxCanvas::SDL_bgi::outtextxy (int x, int y, char *textstring)
{
    // Outputs textstring at (x, y).
    
    int i;
    int x1 = 0;
    int y1 = 0;
    int tw;
    int th;
    
    bgiLineThickness tmp;
    
    tw = textwidth (textstring);
    if (0 == tw)
        return;
    
    th = textheight (textstring);
    
    if (bgiDirection::HORIZ_DIR == bgi_txt_style.direction)
    {
        
        if (bgiTextJustification::LEFT_TEXT == bgi_txt_style.horiz)
        {
            x1 = x;
        }
        
        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.horiz)
        {
            x1 = x - tw / 2;
        }
        
        if (bgiTextJustification::RIGHT_TEXT == bgi_txt_style.horiz)
        {
            x1 = x - tw;
        }
        
        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.vert)
        {
            y1 = y - th / 2;
        }
        
        if (bgiTextJustification::TOP_TEXT == bgi_txt_style.vert)
        {
            y1 = y;
        }
        
        if (bgiTextJustification::BOTTOM_TEXT == bgi_txt_style.vert)
        {
            y1 = y - th;
        }
        
    }
    else
    { // VERT_DIR
        
        if (bgiTextJustification::LEFT_TEXT == bgi_txt_style.horiz)
        {
            y1 = y;
        }
        
        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.horiz)
        {
            y1 = y + tw / 2;
        }
        
        if (bgiTextJustification::RIGHT_TEXT == bgi_txt_style.horiz)
        {
            y1 = y + tw;
        }
        
        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.vert)
        {
            x1 = x - th / 2;
        }
        
        if (bgiTextJustification::TOP_TEXT == bgi_txt_style.vert)
        {
            x1 = x;
        }
        
        if (bgiTextJustification::BOTTOM_TEXT == bgi_txt_style.vert)
        {
            x1 = x - th;
        }
        
    } // VERT_DIR
    
    moveto (x1, y1);
    
    // if THICK_WIDTH, fallback to NORM_WIDTH
    tmp = bgi_line_style.thickness;
    bgi_line_style.thickness = bgiLineThickness::NORM_WIDTH;
    
    for (i = 0; i < strlen (textstring); i++)
    {
        drawchar (textstring[i]);
    }
    
    bgi_line_style.thickness = tmp;
    
} // outtextxy ()

// -----

void GfxCanvas::SDL_bgi::pieslice (int x, int y, int stangle, int endangle, int radius)
{
    // Draws and fills a pie slice centered at (x, y), with a radius
    // given by radius, traveling from stangle to endangle.
    
    // quick and dirty for now, Bresenham-based later.
    int angle;
    
    if ((0 == radius) || (stangle == endangle))
    {
        return;
    }
    
    if (endangle < stangle)
    {
        endangle += 360;
    }
    
    if (0 == radius)
    {
        return;
    }
    
    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    bgi_last_arc.xstart = x + (radius * cos (stangle * PI_CONV));
    bgi_last_arc.ystart = y - (radius * sin (stangle * PI_CONV));
    bgi_last_arc.xend = x + (radius * cos (endangle * PI_CONV));
    bgi_last_arc.yend = y - (radius * sin (endangle * PI_CONV));
    
    for (angle = stangle; angle < endangle; angle++)
    {
        line (x + (radius * cos (angle * PI_CONV)),
              y - (radius * sin (angle * PI_CONV)),
              x + (radius * cos ((angle + 1) * PI_CONV)),
              y - (radius * sin ((angle + 1) * PI_CONV)));
    }
    line (x, y, bgi_last_arc.xstart, bgi_last_arc.ystart);
    line (x, y, bgi_last_arc.xend, bgi_last_arc.yend);
    
    angle = (stangle + endangle) / 2;
    floodfill (x + (radius * cos (angle * PI_CONV)) / 2,
               y - (radius * sin (angle * PI_CONV)) / 2,
               bgi_fg_color);
    
} // arc ()

// -----

void GfxCanvas::SDL_bgi::putimage (int left, int top, void *bitmap, bgiDrawingMode op)
{
    // Puts the bit image pointed to by bitmap onto the screen.
    
    uint32_t bitmap_w;
    uint32_t bitmap_h;
    uint32_t* tmp;
    int i = 2;
    int x;
    int y;
    
    tmp = (uint32_t *)bitmap;
    
    // get width and height info from bitmap
    memcpy (&bitmap_w, tmp, sizeof (uint32_t));
    memcpy (&bitmap_h, tmp + 1, sizeof (uint32_t));
    
    // put bitmap to the screen
    for (y = top + vp.top; y < (top + vp.top + bitmap_h); y++)
    {
        for (x = left + vp.left; x < (left + vp.left + bitmap_w); x++)
        {
            
            switch (op)
            {
                    
                case bgiDrawingMode::COPY_PUT:
                    putpixel_copy (x, y, tmp[i++]);
                    break;
                    
                case bgiDrawingMode::AND_PUT:
                    putpixel_and (x, y, tmp[i++]);
                    break;
                    
                case bgiDrawingMode::XOR_PUT:
                    putpixel_xor (x, y, tmp[i++]);
                    break;
                    
                case bgiDrawingMode::OR_PUT:
                    putpixel_or (x, y, tmp[i++]);
                    break;
                    
                case bgiDrawingMode::NOT_PUT:
                    putpixel_not (x, y, tmp[i++]);
                    break;
            } // switch
        }
    }
    
} // putimage ()

// -----

void GfxCanvas::SDL_bgi::_putpixel (int x, int y)
{
    // line putpixel (), but not updated
    
    // viewport range is taken care of by this function only,
    // since all others use it to draw.
    
    x += vp.left;
    y += vp.top;
    
    switch (bgi_writemode)
    {
            
        case bgiDrawingMode::XOR_PUT:
            putpixel_xor  (x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
            
        case bgiDrawingMode::AND_PUT:
            putpixel_and  (x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
            
        case bgiDrawingMode::OR_PUT:
            putpixel_or   (x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
            
        case bgiDrawingMode::NOT_PUT:
            putpixel_not  (x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
            
        default:
        case bgiDrawingMode::COPY_PUT:
            putpixel_copy (x, y, palette[static_cast<int>(bgi_fg_color)]);
            
    } // switch
    
} // _putpixel ()

// -----

void GfxCanvas::SDL_bgi::putpixel_copy (int x, int y, uint32_t pixel)
{
    // plain putpixel - no logical operations
    
    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }
    
    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }
    
    bgi_activepage [y * (bgi_maxx + 1) + x] = pixel;
    
    // we could use the native function:
    // SDL_RenderDrawPoint (bgi_renderer, x, y);
    // but strangely it's slower
    
} // putpixel_copy ()

// -----

void GfxCanvas::SDL_bgi::putpixel_xor (int x, int y, uint32_t pixel)
{
    // XOR'ed putpixel
    
    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }
    
    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }
    
    bgi_activepage [y * (bgi_maxx + 1) + x] ^= (pixel & 0x00ffffff);
    
} // putpixel_xor ()

// -----

void GfxCanvas::SDL_bgi::putpixel_and (int x, int y, uint32_t pixel)
{
    // AND-ed putpixel
    
    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }
    
    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }
    
    bgi_activepage [y * (bgi_maxx + 1) + x] &= (pixel & 0x00ffffff);
    
} // putpixel_and ()

// -----

void GfxCanvas::SDL_bgi::putpixel_or (int x, int y, uint32_t pixel)
{
    // OR-ed putpixel
    
    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }
    
    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }
    
    bgi_activepage [y * (bgi_maxx + 1) + x] |= (pixel & 0x00ffffff);
    
} // putpixel_or ()

// -----

void GfxCanvas::SDL_bgi::putpixel_not (int x, int y, uint32_t pixel)
{
    // NOT-ed putpixel
    
    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }
    
    if (true == vp.clip)
    {
        if (x < vp.left || x > vp.right || y < vp.top || y > vp.bottom)
        {
            return;
        }
    }
    
    // !!!BUG???
    bgi_activepage [y * (bgi_maxx + 1) + x] = ~ bgi_activepage [y * (bgi_maxx + 1) + x];
    
} // putpixel_not ()

// -----

void GfxCanvas::SDL_bgi::putpixel (int x, int y, int color)
{
    // Plots a point at (x,y) in the color defined by color.
    
    int tmpcolor;
    
    x += vp.left;
    y += vp.top;
    
    // clip
    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }
    
    tmpcolor = color;
    
    switch (bgi_writemode)
    {
            
        case bgiDrawingMode::XOR_PUT:
            putpixel_xor  (x, y, palette[tmpcolor]);
            break;
            
        case bgiDrawingMode::AND_PUT:
            putpixel_and  (x, y, palette[tmpcolor]);
            break;
            
        case bgiDrawingMode::OR_PUT:
            putpixel_or   (x, y, palette[tmpcolor]);
            break;
            
        case bgiDrawingMode::NOT_PUT:
            putpixel_not  (x, y, palette[tmpcolor]);
            break;
            
        default:
        case bgiDrawingMode::COPY_PUT:
            putpixel_copy (x, y, palette[tmpcolor]);
            
    } // switch
    
} // putpixel ()

// -----

void GfxCanvas::SDL_bgi::rectangle (int x1, int y1, int x2, int y2)
{
    // Draws a rectangle delimited by (left,top) and (right,bottom).
    
    line (x1, y1, x2, y1);
    line (x2, y1, x2, y2);
    line (x2, y2, x1, y2);
    line (x1, y2, x1, y1);
    
} // rectangle ()

// -----

void GfxCanvas::SDL_bgi::sector (int x, int y, int stangle, int endangle,
             int xradius, int yradius)
{
    // Draws and fills an elliptical pie slice centered at (x, y),
    // horizontal and vertical radii given by xradius and yradius,
    // traveling from stangle to endangle.
    
    // quick and dirty for now, Bresenham-based later.
    int angle;
    bgiColors tmpcolor;
    
    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }
    
    if (endangle < stangle)
    {
        endangle += 360;
    }
    
    // really needed?
    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    bgi_last_arc.xstart = x + (xradius * cos (stangle * PI_CONV));
    bgi_last_arc.ystart = y - (yradius * sin (stangle * PI_CONV));
    bgi_last_arc.xend = x + (xradius * cos (endangle * PI_CONV));
    bgi_last_arc.yend = y - (yradius * sin (endangle * PI_CONV));
    
    for (angle = stangle; angle < endangle; angle++)
    {
        line (x + (xradius * cos (angle * PI_CONV)),
              y - (yradius * sin (angle * PI_CONV)),
              x + (xradius * cos ((angle + 1) * PI_CONV)),
              y - (yradius * sin ((angle + 1) * PI_CONV)));
    }
    line (x, y, bgi_last_arc.xstart, bgi_last_arc.ystart);
    line (x, y, bgi_last_arc.xend, bgi_last_arc.yend);
    
    tmpcolor = bgi_fg_color;
    setcolor (bgi_fill_style.color);
    angle = (stangle + endangle) / 2;
    // find a point within the sector
    floodfill (x + (xradius * cos (angle * PI_CONV)) / 2,
               y - (yradius * sin (angle * PI_CONV)) / 2,
               tmpcolor);
    
} // sector ()

// -----

void GfxCanvas::SDL_bgi::setallpalette (struct palettetype *palette)
{
    // Sets the current palette to the values given in palette.
    
    int i;
    
    for (i = 0; i <= MAXCOLORS; i++)
    {
        if (palette->colors[i] != -1)
        {
            setpalette (i, palette->colors[i]);
        }
    }
} // setallpalette ()

// -----

void GfxCanvas::SDL_bgi::setbkcolor (bgiColors col)
{
    bgi_bg_color = col;
} // setbkcolor ()

// -----

void GfxCanvas::SDL_bgi::setcolor (bgiColors col)
{
    bgi_fg_color = col;
} // setcolor ()

// -----

void GfxCanvas::SDL_bgi::setalpha (int col, uint8_t alpha)
{
    // Sets alpha transparency for 'col' to 'alpha' (0-255).
    
    uint32_t tmp;
    
    bgi_fg_color = static_cast<bgiColors>(col);
    
    tmp = palette[static_cast<int>(bgi_fg_color)] << 8; // get rid of alpha
    tmp = tmp >> 8;
    palette[static_cast<int>(bgi_fg_color)] = ((uint32_t)alpha << 24) | tmp;
    
} // setcoloralpha ()

// -----

void GfxCanvas::SDL_bgi::setfillpattern (char *upattern, int color)
{
    // Sets a user-defined fill pattern.
    
    int i;
    
    for (i = 0; i < 8; i++)
    {
        fill_patterns[static_cast<int>(bgiFillStyles::USER_FILL)][i] = (uint8_t) *upattern++;
    }
    
    bgi_fill_style.color = static_cast<bgiColors>(color);
    bgi_fill_style.pattern = bgiFillStyles::USER_FILL;
    
} // setfillpattern ()

// -----

void GfxCanvas::SDL_bgi::setfillstyle (bgiFillStyles pattern, int color)
{
    // Sets the fill pattern and fill color.
    
    bgi_fill_style.pattern = pattern;
    
    bgi_fill_style.color = static_cast<bgiColors>(color);
    
} // setfillstyle ()

// -----

void GfxCanvas::SDL_bgi::setlinestyle (bgiLineStyle linestyle, bgiFillStyles upattern, bgiLineThickness thickness)
{
    // Sets the line width and style for all lines drawn by line(),
    // lineto(), rectangle(), drawpoly(), etc.
    
    bgi_line_style.linestyle = linestyle;
    line_patterns[static_cast<int>(bgiLineStyle::USERBIT_LINE)] = static_cast<uint16_t>(upattern);
    bgi_line_style.upattern = upattern;
    bgi_line_style.thickness = thickness;
    
} // setlinestyle ()

// -----

void GfxCanvas::SDL_bgi::setpalette (int colornum, int color)
{
    // Changes the standard palette colornum to color.
    
    palette[colornum] = bgi_palette[color];
} // setpalette ()

// -----

void GfxCanvas::SDL_bgi::settextjustify (bgiTextJustification horiz, bgiTextJustification vert)
{
    // Sets text justification.
    
    bgi_txt_style.horiz = horiz;
    bgi_txt_style.vert = vert;
} // settextjustify ()

// -----

void GfxCanvas::SDL_bgi::settextstyle (int font, bgiDirection direction, int charsize)
{
    // Sets the text font (only DEFAULT FONT is actually available),
    // the direction in which text is displayed (HORIZ DIR, VERT DIR),
    // and the size of the characters.
    
    if (bgiDirection::VERT_DIR == direction)
    {
        bgi_txt_style.direction = bgiDirection::VERT_DIR;
    }
    else
    {
        bgi_txt_style.direction = bgiDirection::HORIZ_DIR;
    }
    bgi_txt_style.charsize = bgi_font_mag_x = bgi_font_mag_y = charsize;
    
} // settextstyle ()

// -----

void GfxCanvas::SDL_bgi::setusercharsize (int multx, int divx, int multy, int divy)
{
    // Lets the user change the character width and height.
    
    bgi_font_mag_x = (float)multx / (float)divx;
    bgi_font_mag_y = (float)multy / (float)divy;
    
} // setusercharsize ()

// -----

void GfxCanvas::SDL_bgi::setviewport (int left, int top, int right, int bottom, int clip)
{
    // Sets the current viewport for graphics output.
    
    if ((left < 0) || (right > bgi_maxx) || (top < 0) || (bottom > bgi_maxy))
    {
        return;
    }
    
    vp.left = left;
    vp.top = top;
    vp.right = right;
    vp.bottom = bottom;
    vp.clip = clip;
    bgi_cp_x = 0;
    bgi_cp_y = 0;
    
} // setviewport ()

// -----

void GfxCanvas::SDL_bgi::setwritemode (bgiDrawingMode mode)
{
    // Sets the writing mode for line drawing. mode can be COPY PUT,
    // XOR PUT, OR PUT, AND PUT, and NOT PUT.
    
    bgi_writemode = mode;
    
} // setwritemode ()

// -----

int GfxCanvas::SDL_bgi::textheight (char *textstring)
{
    // Returns the height in pixels of a string.
    
    return bgi_font_mag_y * bgi_font_height;
} // textheight ()

// -----

int GfxCanvas::SDL_bgi::textwidth (char *textstring)
{
    // Returns the height in pixels of a string.
    
    return (strlen (textstring) * bgi_font_width * bgi_font_mag_x);
} // textwidth ()

// --- end of file SDL_bgi.c
