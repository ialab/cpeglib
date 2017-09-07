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
//  Line_Items
//
//-------------------------------------------------------------------------
//
//  Line containing an expression being explored.
//  It is a sequence of Items.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Line_Items extends Line
{
  Vector<Item> items = new Vector<Item>();

  //-------------------------------------------------------------------
  //  Default constructor.
  //-------------------------------------------------------------------
  Line_Items() {}

  //-------------------------------------------------------------------
  //  Construct Line containing expression 'e' with tail 'tail'.
  //  One of these items may be missing, indicated by null.
  //-------------------------------------------------------------------
  Line_Items(Expr e, Expr tail)
    {
      if (e!=null) addItem(new Item_Expr(e));
      if (tail!=null) addItem(new Item_Tail(tail));
      cleanEnd();
      expandSeq();
    }

  //-------------------------------------------------------------------
  //  Deep copy.
  //-------------------------------------------------------------------
  Line_Items copy(Line_Items line)
    {
      Line_Items result = new Line_Items();
      for (Item item: line.items)
        result.addItem(item.copy());
      return result;
    }

  //-------------------------------------------------------------------
  //  Append Strings of all Items to StringBuffer 'sb'.
  //-------------------------------------------------------------------
  void writeTo(StringBuffer sb)
    {
      start = sb.length();
      for (Item item: items)
        item.writeTo(sb);
      end = sb.length();
      sb.append("\n");
    }

  //-------------------------------------------------------------------
  //  Return information about an item in this Line if selected
  //  by clicking mouse at offset 'offs' in display area.
  //-------------------------------------------------------------------
  Element find(int offset)
    {
      if (offset<start || offset>=end) return null;
      for (int i=0;i<nItems();i++)
      {
        Element elem = item(i).find(offset);
        if (elem!=null)
        {
          elem.item = i;
          return elem;
        }
      }
      return null;
    }

  //-------------------------------------------------------------------
  //  Get number of Items.
  //-------------------------------------------------------------------
  int nItems()
    { return items.size(); }

  //-------------------------------------------------------------------
  //  Get item at position 'i'.
  //-------------------------------------------------------------------
  Item item(int i)
    { return items.elementAt(i); }

  //-------------------------------------------------------------------
  //  Add 'item' at the end.
  //-------------------------------------------------------------------
  void addItem(final Item item)
    { items.add(item); }

  //-------------------------------------------------------------------
  //  Insert 'item' at position 'i'.
  //-------------------------------------------------------------------
  void insertItem(int i, final Item item)
    { items.add(i,item); }

  //-------------------------------------------------------------------
  //  Remove item at position 'i'.
  //-------------------------------------------------------------------
  void removeItem(int i)
    { items.remove(i); }

  //-------------------------------------------------------------------
  //  Replace item at position 'i' by 'item'.
  //-------------------------------------------------------------------
  void replaceItemBy(int i, final Item item)
    {
      items.remove(i);
      items.add(i,item);
    }
  //-------------------------------------------------------------------
  //  Replace item at position 'i' by Items for 'exprList'.
  //-------------------------------------------------------------------
  void replaceItemBy(int i, final Expr[] exprList)
    {
      items.remove(i);
      int j = i;
      for (Expr e: exprList)
      {
        items.add(j,new Item_Expr(e));
        j++;
      }
    }

  //-------------------------------------------------------------------
  //  Return set of (indexes of) first terminals for expression
  //  represented by this Line.
  //-------------------------------------------------------------------
  BitSet terms()
    {
      BitSet result = new BitSet();
      for (Item item: items)
      {
        result.or(item.terms());
        if (!item.NUL()) break;
      }
      return result;
    }

  //-------------------------------------------------------------------
  //  Replace items representing Expr.Sequence by sequence of Items.
  //-------------------------------------------------------------------
  private void expandSeq()
    {
      for (int i=nItems()-1;i>=0;i--)
      {
        if (item(i) instanceof Item_Expr
            && item(i).e instanceof Expr.Sequence)
        {
          Expr.Sequence seq = (Expr.Sequence)item(i).e;
          replaceItemBy(i,seq.args);
        }
      }
    }

  //-------------------------------------------------------------------
  //  Remove all Items after Item with attribute 'end'.
  //-------------------------------------------------------------------
  private void cleanEnd()
    {
      int endFound = -1;
      for (int i=0;i<nItems();i++)
      {
        if (item(i) instanceof Item_Expr && item(i).e.end)
        {
          endFound = i;
          break;
        }
      }
      if (endFound>=0)
        for (int i=nItems()-1;i>endFound;i--)
          removeItem(i);
    }


  //-------------------------------------------------------------------
  //  Expand the i-th item.
  //-------------------------------------------------------------------
  Line_Items[] expand(int i)
    {
      Vector<Line_Items> newLines = new Vector<Line_Items>();
      Item[][] expItem = item(i).expand();
      if (expItem==null) return null;

      for (int k=0;k<expItem.length;k++)
      {
        Item[] row = expItem[k];
        Line_Items newLine = copy(this);
        newLine.removeItem(i);
        int j = i;
        for (Item item: row)
        {
          newLine.insertItem(j,item);
          j++;
        }
        newLine.cleanEnd();
        newLine.expandSeq();
        newLines.add(newLine);
      }
      return newLines.toArray(new Line_Items[0]);
    }


  //-------------------------------------------------------------------
  //  As String.
  //-------------------------------------------------------------------
  String show()
    {
      StringBuffer sb = new StringBuffer();
      for (Item it: items)
         sb.append(it.asString()+" ");
      return sb.toString();
    }

}

