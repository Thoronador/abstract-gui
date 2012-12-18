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

#ifndef ABSGUI_GLFWGUI_H
#define ABSGUI_GLFWGUI_H

#include "../GUI.h"

namespace AbsGUI
{

class glfwGUI: public GUI
{
  public:
    /* constructor */
    glfwGUI();

    /* destructor */
    virtual ~glfwGUI() {}

    /* returns a string identifying the GUI's type */
    virtual std::string getType() const;

    /* initializes the GUI class for later use and returns true in case of success */
    virtual bool init();

    /* starts the GUI loop */
    virtual void start();

    /* terminates the GUI, i.e. cleans up all created resources */
    virtual void terminate();

    /* tries to create a new window for the GUI and returns a pointer to that
       window, if successful.

       parameters:
           width  - width of the window in pixels
           height - height of the window in pixels
           left   - distance from left screen border in pixels
           top    - distance from top screen border in pixels
           title  - title of the window
    */
    virtual Window* newWindow(const int width, const int height, const int left, const int top, const std::string& title);

    virtual void draw() {}
    virtual void idle() {}
  private:
     bool m_Started;
     bool m_ExitLoop;
     bool m_NeedsRedisplay;
};//class GUI

} //namespace

#endif // ABSGUI_GLFWGUI_H
