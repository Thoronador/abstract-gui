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
#include <GL/glfw.h>

namespace AbsGUI
{

glfwGUI::glfwGUI()
{
  m_Started = false;
  m_ExitLoop = false;
  m_NeedsRedisplay = true;
}

std::string glfwGUI::getType() const
{
  return "glfw";
}

bool glfwGUI::init()
{
  return (GL_TRUE==glfwInit());
}

void glfwGUI::start()
{
  if (m_Started) return;
  m_Started = true;
  while (!m_ExitLoop)
  {
    glfwPollEvents();
    if (m_NeedsRedisplay)
    {
      m_NeedsRedisplay = false;
      draw();
    }
    else idle();
  }//while
  glfwCloseWindow();
  glfwTerminate();
}

void glfwGUI::terminate()
{
  m_ExitLoop = true;
}

Window* glfwGUI::newWindow(const int width, const int height, const int left, const int top, const std::string& title)
{
  Window* wnd = new glfwWindow(width, height, left, top, title);
  m_Windows.push_back(wnd);
  m_NeedsRedisplay = true;
  return wnd;
}

} //namespace
