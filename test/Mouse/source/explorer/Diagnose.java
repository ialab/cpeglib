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

import java.util.HashSet;
import mouse.utility.BitMatrix;


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  Class Diagnose
//
//-------------------------------------------------------------------------
//
//  Contains methods to detect and write messages about:
//  - not well-formed expressions;
//  - no-fail alternatives in Choice;
//  - no-success alternatives in Sequence;
//  - superfluous '?' operators.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

class Diagnose
{
  //-------------------------------------------------------------------
  //  Matrices for diagnosing left recursion.
  //-------------------------------------------------------------------
  static BitMatrix calls;
  static BitMatrix Calls;

  //=====================================================================
  //
  //  Lists of expression names to appear in diagnostics.
  //  The grammar often contains duplicate sub-expressions.
  //  To avoid duplication of messages, information is collected
  //  in hash sets.
  //
  //=====================================================================
  //-------------------------------------------------------------------
  //  Left-recursive expressions.
  //-------------------------------------------------------------------
  static HashSet<String> recur = new HashSet<String>();

  //-------------------------------------------------------------------
  //  Expressions under superfluous query.
  //-------------------------------------------------------------------
  static HashSet<String> query = new HashSet<String>();

  //-------------------------------------------------------------------
  //  Choice alternatives that cannot fail.
  //-------------------------------------------------------------------
  static HashSet<String> choice = new HashSet<String>();

  //-------------------------------------------------------------------
  //  Expressions that always fail.
  //-------------------------------------------------------------------
  static HashSet<String> fail = new HashSet<String>();

  //-------------------------------------------------------------------
  //  Nullable iterations.
  //-------------------------------------------------------------------
  static HashSet<String> iter = new HashSet<String>();


  //=====================================================================
  //  Do the job.
  //=====================================================================
  static void apply()
    {
      //---------------------------------------------------------------
      //  Scan expressions using DiagVisitor.
      //---------------------------------------------------------------
      DiagVisitor diagVisitor = new DiagVisitor();
      for (Expr e: PEG.index)
        e.accept(diagVisitor);

      //---------------------------------------------------------------
      //  Find expressions that always fail.
      //---------------------------------------------------------------
      for (Expr e: PEG.index)
        if (!(e.nul|e.adv))
           fail.add(e.asString);

      //---------------------------------------------------------------
      //  Find left recursion.
      //---------------------------------------------------------------
      calls = Relations.calls;
      Calls = calls.closure();
      for (Expr r: PEG.rules)
      {
        int i = r.index;
        if (Calls.at(i,i))
          leftRecursion(i);
      }

      //---------------------------------------------------------------
      //  Write out findings.
      //---------------------------------------------------------------
        for (String s: iter)
          System.out.println("Error: '" + s + "' may consume empty string.");

        for (String s: recur)
          System.out.println(s + ".");

      //---------------------------------------------------------------
      //  We arrive here only if the grammar is well-formed.
      //  Otherwise the fail / succeed attributes are incomplete.
      //---------------------------------------------------------------
      for (String s: fail)
        System.out.println("Warning: '" + s + "' always fails.");

      for (String s: choice)
        System.out.println("Warning: '" + s + "' never fails and hides other alternative(s).");

      for (String s: query)
        System.out.println("Info: as '" + s + "' never fails, the '?' in '" + s + "?' can be dropped.");
    }


  //=====================================================================
  //  Provide left-recursion details of exprs[i].
  //=====================================================================
  private static void leftRecursion(int i)
    {
      StringBuilder sb = new StringBuilder();
      sb.append("Error: '" + PEG.index[i].simple() + "' is left-recursive");
      String sep = " via ";
      for (int j=0;j<PEG.N;j++)
      {
        if (calls.at(i,j) && Calls.at(j,i))
        {
          sb.append(sep + "'" + PEG.index[j].simple() + "'");
          sep = " and ";
        }
      }
      recur.add(sb.toString());
    }



  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  DiagVisitor - collects diagnostic information.
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

  static class DiagVisitor extends mouse.explorer.Visitor
  {
    //-----------------------------------------------------------------
    //  Choice.
    //-----------------------------------------------------------------
    private void doChoice(Expr.Choice e)
      {
        Expr args[] = e.args;
        for (int i=0; i<args.length-1; i++)
          if (!args[i].fal)
            choice.add(args[i].asString + "' in '" + e.name);
      }

    //-----------------------------------------------------------------
    //  Plus.
    //-----------------------------------------------------------------
    public void visit(Expr.Plus e)
      { if (e.arg.nul) iter.add(e.arg.asString + "' in '" + e.asString); }

    //-----------------------------------------------------------------
    //  Star.
    //-----------------------------------------------------------------
    public void visit(Expr.Star e)
      { if (e.arg.nul) iter.add(e.arg.asString + "' in '" + e.asString); }

    //-----------------------------------------------------------------
    //  Query.
    //-----------------------------------------------------------------
    public void visit(Expr.Query e)
      { if (e.arg.nul) query.add(e.arg.name); }
  }
}
