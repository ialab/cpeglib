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

import java.util.Vector;


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  Paragraph_Lines
//
//-------------------------------------------------------------------------
//
//  Paragraph consisting of lines of type L.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Paragraph_Lines<L extends Line> extends Paragraph
{
  Vector<L> lines = new Vector<L>();
  int start = -1;
  int end = -1;

  //-------------------------------------------------------------------
  //  Append text represented by this Paragraph to StringBuffer 'sb'.
  //-------------------------------------------------------------------
  void writeTo(StringBuffer sb)
    {
      start = sb.length();
      for (L line: lines)
        line.writeTo(sb);
      end = sb.length();
    }

  //-------------------------------------------------------------------
  //  Return information about the Line or its contained object
  //  selected by clicking mouse at offset 'offs' in display area.
  //-------------------------------------------------------------------
  Element find(int offset)
    {
      if (offset<start || offset>=end) return null;
      for (int i=0;i<nLines();i++)
      {
        Element elem = line(i).find(offset);
        if (elem!=null)
        {
          elem.line = i;
          return elem;
        }
      }
      return null;
    }

  //-------------------------------------------------------------------
  //  Get number of lines.
  //-------------------------------------------------------------------
  int nLines()
    { return lines.size(); }

  //-------------------------------------------------------------------
  //  Get line at position 'i'.
  //-------------------------------------------------------------------
  L line(int i)
    { return lines.elementAt(i); }

  //-------------------------------------------------------------------
  //  Add 'line' at the end.
  //-------------------------------------------------------------------
  void addLine(final L line)
    { lines.add(line); }

  //-------------------------------------------------------------------
  //  Insert 'line' at position 'i'.
  //-------------------------------------------------------------------
  void insertLine(int i, final L line)
    { lines.add(i,line); }

  //-------------------------------------------------------------------
  //  Remove line at position 'i'.
  //-------------------------------------------------------------------
  void removeLine(int i)
    { lines.remove(i); }

  //-------------------------------------------------------------------
  //  Remove all lines.
  //-------------------------------------------------------------------
  void clear()
    { lines = new Vector<L>(); }

  //-------------------------------------------------------------------
  //  Replace line at position 'i' by 'line'.
  //-------------------------------------------------------------------
  void replaceLineBy(int i, final L line)
    {
      lines.remove(i);
      lines.add(i,line);
    }

  //-------------------------------------------------------------------
  //  Replace line at position 'i' by 'lineList'.
  //-------------------------------------------------------------------
  void replaceLineBy(int i, final L[] lineList)
    {
      lines.remove(i);
      int j = i;
      for (L line: lineList)
      {
        lines.add(j,line);
        j++;
      }
    }

}

