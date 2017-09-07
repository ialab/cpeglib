//=========================================================================
//
//  Part of PEG parser generator Mouse.
//
//  Copyright (C) 2017 by Roman R. Redziejowski (www.romanredz.se).
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//-------------------------------------------------------------------------
//
//  Change log
//    170301 Created.
//
//=========================================================================

package mouse.explorer;

import java.util.BitSet;
import java.util.Vector;

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  class Item
//
//-------------------------------------------------------------------------
//
//  Base class for items shown on an Explorer line.
//  Such item may represent either an expression (Item_Expr)
//  or Tail (Item_Tail).
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

abstract class Item
{
  //=====================================================================
  //  Data
  //=====================================================================
  //-------------------------------------------------------------------
  //  The expression (common for both subclasses).
  //-------------------------------------------------------------------
  Expr e;

  //-------------------------------------------------------------------
  //  Start and end offset in the GUI area (when shown).
  //-------------------------------------------------------------------
  int start = -1;
  int end = -1;

  //=====================================================================
  //  Abstract methods
  //=====================================================================
  abstract Item[][] expand();
  abstract String asString();
  abstract BitSet terms();
  abstract boolean NUL();
  abstract Item copy();

  //=====================================================================
  //  Methods required by Line_Explorer
  //=====================================================================
  //-------------------------------------------------------------------
  //  Append string representation to StringBuffer 'sb'.
  //-------------------------------------------------------------------
  void writeTo(StringBuffer sb)
    {
      start = sb.length();
      sb.append(asString());
      end = sb.length();
      sb.append(" ");
    }

  //-------------------------------------------------------------------
  //  If offset 'offset' in the GUI area is inside the string displayed
  //  for this Item return Element object with start and end filled.
  //  Otherwise return null.
  //-------------------------------------------------------------------
  Element find(int offset)
    {
      if (offset<start || offset>=end) return null;
      Element elem = new Element();
      elem.start = start;
      elem.end = end;
      return elem;
    }
}