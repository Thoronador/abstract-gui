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

#ifndef ABSGUI_ID_GEN_H
#define ABSGUI_ID_GEN_H

namespace AbsGUI
{

/* generates a "unique" integer-typed ID */
unsigned int generateUniqueID()
{
  static unsigned int currID = 0;
  return ++currID;
}//function

} //namespace

#endif // ABSGUI_ID_GEN_H
