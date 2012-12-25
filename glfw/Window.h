/*
    This file is part of Abstract GUI, a GUI abstraction layer.
    Copyright (C) 2012  Thoronador

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ABSGUI_GLFWWINDOW_H
#define ABSGUI_GLFWWINDOW_H

#include "../Window.h"
#include <GL/glfw.h>

namespace AbsGUI
{

class glfwWindow: public Window
{
  public:
    /* constructor

       parameters:
           width  - width of the window in pixels
           height - height of the window in pixels
           left   - distance from left screen border in pixels
           top    - distance from top screen border in pixels
           title  - title of the window
    */
    glfwWindow(const int width, const int height, const int left, const int top, const std::string& title);

    /* destructor */
    virtual ~glfwWindow();

    /* gets the width of the window in pixels */
    virtual int getWidth();

    /* gets the width of the window in pixels*/
    virtual int getHeight();

    /* sets the dimensions of the window

       parameters:
           width  - requested window width
           height - requested window height
    */
    virtual void setDimensions(const int width, const int height);

    /* gets the window's distance from the left screen border in pixles */
    virtual int getPosX();

    /* gets the window's distance from the top screen border in pixles */
    virtual int getPosY();

    /* sets the position of the window

       parameters:
           x - requested distance from the left screen border in pixles
           y - requested distance from the top screen border in pixles
    */
    virtual void setWindowPosition(const int x, const int y);

    /* requests that the current window shall be made full screen */
    virtual void makeFullScreen();

    /* sets the title of the current window */
    virtual void setWindowTitle(const std::string& title);

    /* writes a text to the given position

       parameters:
           text    - the text
           x, y, z - coordinates of the text location
    */
    virtual void writeText(const std::string& text, const float x, const float y, const float z);

    /* swap front and back buffers */
    virtual void swapBuffers();
  private:
    int m_WindowPosX, m_WindowPosY;
};//class

}//namespace

#endif // ABSGUI_GLFWWINDOW_H
