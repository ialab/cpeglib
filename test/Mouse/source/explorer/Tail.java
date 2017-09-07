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
//    170301 Created
//
//=========================================================================

package mouse.explorer;

import java.util.Vector;
import java.util.Hashtable;


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  Class Tail
//
//-------------------------------------------------------------------------
//
//  Describes what follows after an expression 'e' returns to 'caller'.
//  It is a (possibly empty) sequence 'seq' of expressions optionally
//  followed by Tail(caller).
//  In the process of 'refinement', the Tail objects are successively
//  derived from other Tail objects. To be able to present this process
//  in the window 'explain', each object has information about its 'parent'.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

public class Tail
{
  Expr e;                                 // Whose tail?
  Expr caller;                            // Where does 'e' return?
  Vector<Expr> seq = new Vector<Expr>();  // Expressions that follow
  boolean hasTail = true;                 // Tail(caller) present?
  Tail parent = null;                     // Derived from

  //=====================================================================
  //  Constructors
  //=====================================================================
  //-------------------------------------------------------------------
  //  Construct for 'e' and 'caller' with empty 'seq' and Tail(caller).
  //-------------------------------------------------------------------
  Tail(final Expr e, final Expr caller)
    {
      this.e = e;
      this.caller = caller;
    }

  //-------------------------------------------------------------------
  //  Construct for 'e' and 'caller' with 'seq' and Tail(caller).
  //-------------------------------------------------------------------
  Tail(final Expr e, final Expr caller, final Expr ... seq)
    {
      this.e = e;
      this.caller = caller;
      for (Expr p: seq)
        this.seq.add(p);
    }

  //-------------------------------------------------------------------
  //  Construct for 'e' and 'caller' with 'seq' and Tail(caller).
  //-------------------------------------------------------------------
  Tail(final Expr e, final Expr caller, final Vector<Expr> seq)
    {
      this.e = e;
      this.caller = caller;
      for (Expr p: seq)
        this.seq.add(p);
    }

  //-------------------------------------------------------------------
  //  Copy.
  //-------------------------------------------------------------------
  static Tail copy(final Tail t)
    {
      Tail copy = new Tail(t.e,t.caller,t.seq);
      copy.hasTail = t.hasTail;
      copy.parent = t.parent;
      return copy;
    }


  //=====================================================================
  //  Elementary methods
  //=====================================================================
  //-------------------------------------------------------------------
  //  As String.
  //-------------------------------------------------------------------
  String asString()
    {
      StringBuffer sb = new StringBuffer();
      for (Expr e: seq)
      {
        if (e.bind()==0)
          sb.append("(" + e.simple() +  ") ");
        else
          sb.append(e.simple()+ " ");
      }
      if (hasTail)
        sb.append("Tail("+caller.name+")");
      return sb.toString();
    }

  //-------------------------------------------------------------------
  //  Is it Tail(e)?
  //-------------------------------------------------------------------
  boolean isOwnTail()
    { return seq.size()==0 && hasTail && caller==e; }

  //-------------------------------------------------------------------
  //  Is refinable?
  //-------------------------------------------------------------------
  boolean isRefinable()
    { return hasTail && !caller.isRule;}

  //=====================================================================
  //  Refining the Tail
  //=====================================================================
  //-------------------------------------------------------------------
  //  Refine Tail 'theTail' and add result to 'list'.
  //  Refinement means logically replacing Tail(caller) in 'theTail'
  //  by expression representing it. Tail(caller) is represented by
  //  one or more Tail objects listed in 'caller.tails'.
  //  The method creates a new refined Tail object using each of them.
  //-------------------------------------------------------------------
  static void refine (final Tail theTail, Vector<Tail> list)
    {
      if (!theTail.isRefinable())
      {
        list.add(theTail);
        return;
      }

      if (theTail.caller.tails.isEmpty())
      {
        Tail better = copy(theTail);
        better.hasTail = false;
        list.add(better);
        return;
      }

      for (Tail tail: theTail.caller.tails)
      {
        Tail better = copy(theTail);
        better.caller = tail.caller;
        for (Expr e: tail.seq)
          better.seq.add(e);
        better.hasTail = tail.hasTail;
        better.parent = theTail;
        if (!better.isOwnTail())
          list.add(better);
      }
   }

  //------------------------------------------------------------------
  //  Expand Tail(e) to refined components.
  //------------------------------------------------------------------
  static Vector<Tail> expand(final Expr e)
    {
      Vector<Tail> toRefine = e.tails;
      loop:
      while (true)
      {
        Vector<Tail> refined = new Vector<Tail>();
        for (Tail t: toRefine)
          refine(t,refined);
        for (Tail t: refined)
          if (t.isRefinable())
          {
            toRefine = refined;
            continue loop;
          }
        return refined;
      }
    }

  //------------------------------------------------------------------
  //  Expand Tail(e) to unique refined components.
  //------------------------------------------------------------------
  static Vector<Tail> expandUnique(final Expr e)
    {
      Hashtable<String,Tail> temp = new Hashtable<String,Tail>();
      Vector<Tail> expanded = expand(e);
      for (Tail t: expanded)
        temp.put(t.asString(),t);

      Vector<Tail> result = new Vector<Tail>();
      for (String key: temp.keySet())
        result.add(temp.get(key));
      return result;
    }
}

