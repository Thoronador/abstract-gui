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

#include "GUI.h"
#include "Window.h"
#include "IncludeGLUT.h"

namespace AbsGUI
{

std::string glutGUI::getType() const
{
  return "glut";
}

bool glutGUI::init()
{
  int argcount = 0;
  glutInit(&argcount, NULL);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  #ifdef APP_USING_FREEGLUT
  //If we use freeglut API instead of the usual one, we like to return from the
  //main loop instead of exiting without prior notice.
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  #endif
  return true;
}

void glutGUI::start()
{
  glutMainLoop();
}

void glutGUI::terminate()
{
  /* glutLeaveMainLoop() would be a nicer, cleaner way, but this function is
     only part of freeglut(?) and not part of the original GLUT implementation.
     So we do an ordinary exit(0) instead. */
  #ifdef APP_USING_FREEGLUT
  glutLeaveMainLoop();
  #else
  exit(0);
  #endif
}

Window* glutGUI::newWindow(const int width, const int height, const int left, const int top, const std::string& title)
{
  Window* wnd = new glutWindow(width, height, left, top, title);
  m_Windows.push_back(wnd);
  return wnd;
}

} //namespace
