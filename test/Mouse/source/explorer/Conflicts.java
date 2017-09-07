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

import mouse.utility.BitMatrix;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Vector;


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  Class Conflicts
//
//-------------------------------------------------------------------------
//
//  A static class to find and keep LL1 violations in the grammar
//  represented by PEG object.
//  An LL1 violation can be one of these:
//
//  (1) A pair of alternatives 'arg1', 'arg2' of a Choice
//      expression 'expr' where 'arg1' and 'arg2 Tail(expr)'
//      have non-disjoint first terminals.
//  (2) The argument 'arg1' of Plus, Star, or Query expression 'expr'
//      that has non-disjoint first terminals with 'Tail(expr)'.
//
//  The violations are kept in array 'conflicts', sorted by name of 'expr'.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

public class Conflicts
{
  public static Conflict[] conflicts;

  static Conflict.Compare compare = new Conflict.Compare();

  //------------------------------------------------------------------
  //  Make list of LL1 violations.
  //------------------------------------------------------------------
  public static void find()
    {
      LL1Visitor ll1Visitor = new LL1Visitor();
      for (Expr e: PEG.nonterms)
        e.accept(ll1Visitor);

      conflicts = ll1Visitor.conflicts.toArray(new Conflict[0]);

      Conflict.Compare compare = new Conflict.Compare();
      Arrays.sort(conflicts,compare);

      ll1Visitor = null;
      compare = null;
    }

  //------------------------------------------------------------------
  //  Check LL1 conditions for a pair 'e1','e2' of expressions.
  //  If 'e2' is nullable, check 'e1' against 'e2 Tail(e)'.
  //  Argument 'e2' may be null, meaning check against 'Tail(e)'.
  //  Represent detected violation by a 'Conflict' object.
  //  Return null if the pair satisfies LL1.
  //------------------------------------------------------------------
  private static Conflict checkLL1(final Expr e1,final Expr e2,final Expr e)
    {
      //--------------------------------------------------------------
      //  Make set of first terminals of e1.
      //--------------------------------------------------------------
      BitSet firstTerms1 = new BitSet();
      firstTerms1.or(e1.first);

      //--------------------------------------------------------------
      //  Make copy of first terminals of e2
      //  or of e2 and Tail(e) (if e2 nullable), or only Tail(e).
      //  First terminals of Tail(e) are in Relations.Follow.
      //--------------------------------------------------------------
      BitSet firstTerms2 = new BitSet();
      if (e2!=null) firstTerms2.or(e2.first);
      if (e2==null || e2.NUL )
        firstTerms2.or(Relations.Follow.row(e.index).get(0,PEG.T));

      //--------------------------------------------------------------
      //  Check for collisions and return if none.
      //--------------------------------------------------------------
      BitMatrix coincidence = BitMatrix.product(firstTerms1,firstTerms2,PEG.T);
      BitMatrix collisions = coincidence.and(Relations.nonDisjoint);
      if (collisions.weight()==0) return null;

      //--------------------------------------------------------------
      //  Make list of conflicting terminals as a Vector of TermPairs.
      //--------------------------------------------------------------
      Vector<TermPair> tpairs = new Vector<TermPair>();
      for (Expr t1: PEG.terms)
      {
        BitSet bs = collisions.row(t1.index);
        if (bs.isEmpty()) continue;
        for (Expr t2: PEG.terms)
          if (bs.get(t2.index))
            tpairs.add(new TermPair(t1,t2));
      }

      //--------------------------------------------------------------
      //  Construct and return a Conflict object.
      //--------------------------------------------------------------
      return new Conflict(e1,e2,e,tpairs);
    }


  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  LL1Visitor - finds LL1 conflicts.
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

  static class LL1Visitor extends mouse.explorer.Visitor
  {
    Vector<Conflict> conflicts = new Vector<Conflict>();

    //----------------------------------------------------------------
    //  Choice. Check each alternative against all that follow.
    //----------------------------------------------------------------
    public void visit(Expr.Choice e)
      {
        for (int i=0;i<e.args.length-1;i++)
        {
          for (int j=i+1;j<e.args.length;j++)
          {
            Conflict c = checkLL1(e.args[i],e.args[j],e);
            if (c!=null) conflicts.add(c);
          }
        }
      }

    //----------------------------------------------------------------
    //  Plus
    //----------------------------------------------------------------
    public void visit(Expr.Plus e)
      {
        Conflict c = checkLL1(e.arg,null,e);
        if (c!=null) conflicts.add(c);
      }

    //----------------------------------------------------------------
    //  Star
    //----------------------------------------------------------------
    public void visit(Expr.Star e)
      {
        Conflict c = checkLL1(e.arg,null,e);
        if (c!=null) conflicts.add(c);
      }

    //----------------------------------------------------------------
    //  Query
    //----------------------------------------------------------------
    public void visit(Expr.Query e)
      {
        Conflict c = checkLL1(e.arg,null,e);
        if (c!=null) conflicts.add(c);
      }
  }
}


