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
//  Item_Tail
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Item_Tail extends Item
{
  Item_Tail(Expr e)
    { this.e = e; }

  Item_Tail copy()
    { return new Item_Tail(e); }

  String asString()
    { return("Tail("+e.name+")"); }

  BitSet terms()
    {
      BitSet follow = Relations.follow.row(e.index);
      BitSet result = new BitSet();
      for (BitIter iter=new BitIter(follow);iter.hasNext();)
        result.or(PEG.index[iter.next()].first);
      return result;
    }

  boolean NUL()
    { return false; }

  Item[][] expand()
   {
      Vector<Tail> tails = Tail.expandUnique(e);

      Item[][] result = new Item[tails.size()][];

      int i = 0;
      for (Tail tail: tails)
      {
        Vector<Item> row = new Vector<Item>();
        for (Expr p: tail.seq)
          row.add(new Item_Expr(p));
        if (tail.hasTail)
          row.add(new Item_Tail(tail.caller));
        result[i] = row.toArray(new Item[0]);
        i++;
      }

      return result;
   }
}