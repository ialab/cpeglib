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


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  Line_Terms
//
//-------------------------------------------------------------------------
//
//  Line showing a pair of conflicting terminals.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Line_Terms extends Line
{
  TermPair terms;

  //-------------------------------------------------------------------
  //  Constructor.
  //-------------------------------------------------------------------
  Line_Terms(final TermPair terms)
    { this.terms = terms; }

  //-------------------------------------------------------------------
  //  Append to StringBuffer 'sb' the expression as String with name.
  //-------------------------------------------------------------------
  void writeTo(StringBuffer sb)
    {
      start = sb.length();
      sb.append("  " + terms.asString());
      end = sb.length();
      sb.append("\n");
    }

  //-------------------------------------------------------------------
  //  Return information about this Line if selected
  //  by clicking mouse at offset 'offs' in display area.
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

