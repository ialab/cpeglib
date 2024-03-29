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
//  Paragraph
//
//-------------------------------------------------------------------------
//
//  Abstract base class for different kinds of paragraphs.
//  Paragraph is made non-selectable by letting 'find' return null.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

abstract class Paragraph
{
  //-------------------------------------------------------------------
  //  Append text represented by this Paragraph to StringBuffer 'sb'.
  //-------------------------------------------------------------------
  abstract void writeTo(StringBuffer sb);

  //-------------------------------------------------------------------
  //  Return information about this Paragraph or a contained object
  //  selected by clicking mouse at offset 'offs' in display area.
  //-------------------------------------------------------------------
  abstract Element find(int offset);
}

