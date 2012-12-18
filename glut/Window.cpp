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
#include "IncludeGLUT.h"

namespace AbsGUI
{

glutWindow::glutWindow(const int width, const int height, const int left, const int top, const std::string& title)
: Window(width, height, left, top, title)
{
  glutInitWindowPosition(left, top);
  glutInitWindowSize(width, height);
  m_glutWindowID = glutCreateWindow(title.c_str());
}

glutWindow::~glutWindow()
{
  glutDestroyWindow(m_glutWindowID);
}

int glutWindow::getWidth()
{
  glutSetWindow(m_glutWindowID);
  return glutGet(GLUT_WINDOW_WIDTH);
}

int glutWindow::getHeight()
{
  glutSetWindow(m_glutWindowID);
  return glutGet(GLUT_WINDOW_HEIGHT);
}

void glutWindow::setDimensions(const int width, const int height)
{
  glutSetWindow(m_glutWindowID);
  glutReshapeWindow(width, height);
}

int glutWindow::getPosX()
{
  glutSetWindow(m_glutWindowID);
  return glutGet(GLUT_WINDOW_X);
}

int glutWindow::getPosY()
{
  glutSetWindow(m_glutWindowID);
  return glutGet(GLUT_WINDOW_Y);
}

void glutWindow::setWindowPosition(const int x, const int y)
{
  glutSetWindow(m_glutWindowID);
  glutPositionWindow(x, y);
}

void glutWindow::makeFullScreen()
{
  glutSetWindow(m_glutWindowID);
  glutFullScreen();
}

void glutWindow::setWindowTitle(const std::string& title)
{
  glutSetWindow(m_glutWindowID);
  glutSetWindowTitle(title.c_str());
}

void glutWindow::swapBuffers()
{
  glutSetWindow(m_glutWindowID);
  glutSwapBuffers();
}

} //namespace
