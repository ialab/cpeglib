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
//  Paragraph_Text
//
//-------------------------------------------------------------------------
//
//  Non-selectable Paragraph containing text.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Paragraph_Text extends Paragraph
{
  String text;

  //-------------------------------------------------------------------
  //  Constructor.
  //-------------------------------------------------------------------
  Paragraph_Text(String text)
    { this.text = text; }

  //-------------------------------------------------------------------
  //  Append text represented by this Paragraph to StringBuffer 'sb'.
  //-------------------------------------------------------------------
  void writeTo(StringBuffer sb)
    { sb.append(text); }

  //-------------------------------------------------------------------
  //  The paragraph is not selectable.
  //-------------------------------------------------------------------
  Element find(int offset)
    { return null; }
}

