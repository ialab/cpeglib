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
//  class Item_Expr
//
//-------------------------------------------------------------------------
//
//  Item shown on an Explorer line, representing expression 'e'
//  (defined in base class).
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Item_Expr extends Item
{
  static ExpandVisitor expandVisitor = new ExpandVisitor();

  Item_Expr(Expr e)
    { this.e = e; }

  Item_Expr copy()
    { return new Item_Expr(e); }

  String asString()
    {
      if (e.bind()==0)
        return("("+e.asString+")");
      else
        return(e.asString());
    }

  BitSet terms()
    { return e.first; }

  boolean NUL()
    { return e.NUL; }

  Item[][] expand()
    {
      if (e.isTerm) return null;
      e.accept(expandVisitor);
      return expandVisitor.expanded;
    }

  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  Expand Visitor
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  static class ExpandVisitor extends Visitor
  {
    Item[][] expanded;

    //-----------------------------------------------------------------
    //  Choice.
    //-----------------------------------------------------------------
    public void visit(Expr.Choice e)
      {
        expanded = new Item[e.args.length][1];
        for (int i=0;i<e.args.length;i++)
        {
          Item row[] = {new Item_Expr(e.args[i])};
          expanded[i] = row;
        }
      }

    //-----------------------------------------------------------------
    //  Sequence.
    //-----------------------------------------------------------------
    public void visit(Expr.Sequence e)
      {
        expanded = new Item[1][e.args.length];
        Item[] row = new Item[e.args.length];
        for (int i=0;i<e.args.length;i++)
          row[i] = new Item_Expr(e.args[i]);
        expanded[0] = row;
      }

    //-----------------------------------------------------------------
    //  Plus.
    //  e = arg+ is replaced by arg e / arg.
    //-----------------------------------------------------------------
    public void visit(Expr.Plus e)
      {
        Item[][] exp = {{new Item_Expr(e.arg),new Item_Expr(e)},
                        {new Item_Expr(e.arg)}};
        expanded = exp;
      }

    //-----------------------------------------------------------------
    //  Star.
    //  e = arg* is replaced by arg e / empty.
    //-----------------------------------------------------------------
    public void visit(Expr.Star e)
      {
        Item[][] exp = {{new Item_Expr(e.arg),new Item_Expr(e)},{}};
        expanded = exp;
      }

    //-----------------------------------------------------------------
    //  Query.
    //  e = arg? is replaced by arg / empty.
    //-----------------------------------------------------------------
    public void visit(Expr.Query e)
      {
        Item[][] exp = {{new Item_Expr(e.arg)},{}};
        expanded = exp;
      }

    //-----------------------------------------------------------------
    //  Ref.
    //-----------------------------------------------------------------
    public void visit(Expr.Ref e)
      {
        Item[][] exp = {{new Item_Expr(e.rule)}};
        expanded = exp;
      }
  }
}