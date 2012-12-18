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

#include "Window.h"
#include <stdexcept>

namespace AbsGUI
{

glfwWindow::glfwWindow(const int width, const int height, const int left, const int top, const std::string& title)
: Window(width, height, left, top, title)
{
  if (glfwOpenWindow(width, height, 8, 8, 8, 8, /*RGBA bits*/
                 8, /*8 bit depth buffer*/
                 0, /*stencil buffer bits*/
                 GLFW_WINDOW)==GL_TRUE)
  {
    glfwSetWindowPos(left, top);
    m_WindowPosX = left;
    m_WindowPosY = top;
    glfwSetWindowTitle(title.c_str());
    //m_NeedsRedisplay = true;
    return;
  }
  //window could not be created
  throw std::runtime_error("glfWindow could not be created!");
}

glfwWindow::~glfwWindow()
{
  glfwCloseWindow();
}

int glfwWindow::getWidth()
{
  int width = 0;
  glfwGetWindowSize(&width, NULL);
  return width;
}

int glfwWindow::getHeight()
{
  int h = 0;
  glfwGetWindowSize(NULL, &h);
  return h;
}

void glfwWindow::setDimensions(const int width, const int height)
{
  glfwSetWindowSize(width, height);
  //m_NeedsRedisplay = true;
}

int glfwWindow::getPosX()
{
  return m_WindowPosX;
}

int glfwWindow::getPosY()
{
  return m_WindowPosY;
}

void glfwWindow::setWindowPosition(const int x, const int y)
{
  glfwSetWindowPos(x, y);
  m_WindowPosX = x;
  m_WindowPosY = y;
}

void glfwWindow::makeFullScreen()
{
  #warning Not implemented yet!
}

void glfwWindow::setWindowTitle(const std::string& title)
{
  glfwSetWindowTitle(title.c_str());
}

void glfwWindow::swapBuffers()
{
  glfwSwapBuffers();
}

} //namespace
