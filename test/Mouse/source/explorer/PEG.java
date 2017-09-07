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

import java.util.Arrays;
import java.util.Hashtable;
import java.util.HashSet;
import java.util.Vector;
import mouse.utility.BitMatrix;
import mouse.utility.Convert;
import mouse.runtime.Source;


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//
//  Class PEG
//
//-------------------------------------------------------------------------
//
//  Holds parsed grammar.
//  The parsed grammar is a structure of Expr objects in the form of
//  trees rooted in Expr objects representing Rules.
//  These objects are listed in the array 'rules'.
//  The objects representing terminals and nonterminals are listed
//  separately in 'terms' and 'nonterms'. Note that both terminals
//  and nonterminals may appear among rules.
//  All Expr objects are listed in array 'index', all terminals
//  appearing first. Each object holds its index position in field 'index'.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

public class PEG
{
  //=====================================================================
  //
  //  Data
  //
  //=====================================================================
  //-------------------------------------------------------------------
  //  Lists of Expressions.
  //-------------------------------------------------------------------
  public static Expr rules[] = new Expr[0];
  public static Expr.Ref refs[] = new Expr.Ref[0];
  public static Expr nonterms[];
  public static Expr terms[];
  public static Expr index[];

  public static int N;  // Number of all Expressions.
  public static int T;  // Number of Terminals.

  //-------------------------------------------------------------------
  //  Start expression.
  //-------------------------------------------------------------------
  public static Expr startExpr;

  //-------------------------------------------------------------------
  //  Counters.
  //-------------------------------------------------------------------
  public static int errors = 0; // Errors
  public static int iterAt;     // Iterations for attributes

  //=====================================================================
  //
  //  Constructor
  //
  //=====================================================================

  public static void parse(Source src)
    {
      //---------------------------------------------------------------
      //  Parse the grammar and quit if error found
      //---------------------------------------------------------------
      Parser parser = new Parser();
      parser.parse(src);

      Semantics sem = parser.semantics();
      if (sem.errcount>0) return;

      //---------------------------------------------------------------
      //  Add start expression.
      //---------------------------------------------------------------
      Expr.Ref startRef = new Expr.Ref(sem.rules.elementAt(0).name);
      startExpr = new Expr.Sequence(startRef,new Expr.SigmaStar());
      startExpr.name = "#Start";
      sem.refs.add(startRef);
      sem.rules.add(startExpr);

      //---------------------------------------------------------------
      //  Get list of rules and refs.
      //---------------------------------------------------------------
      rules = sem.rules.toArray(rules);
      refs = sem.refs.toArray(refs);

      //---------------------------------------------------------------
      //  Resolve references and quit if error found.
      //---------------------------------------------------------------
      resolve();
      if (errors>0) return;

      //---------------------------------------------------------------
      //  Compute source for all expressions.
      //---------------------------------------------------------------
      SourceVisitor sourceVisitor = new SourceVisitor();
      for (Expr e: rules)
        e.accept(sourceVisitor);
      sourceVisitor = null;

      //---------------------------------------------------------------
      //  Give names to subexpressions, build lists and index.
      //---------------------------------------------------------------
      ListVisitor listVisitor = new ListVisitor();
      listVisitor.apply();
      listVisitor = null;

      //---------------------------------------------------------------
      //  Compute attributes.
      //---------------------------------------------------------------
      computeAttributes();

      //---------------------------------------------------------------
      //  Construct matrices.
      //---------------------------------------------------------------
      Relations.compute();

      //---------------------------------------------------------------
      //  Insert into expressions info about first terminals.
      //---------------------------------------------------------------
      for (Expr e: index)
        e.first = Relations.First.row(e.index).get(0,T);

      //---------------------------------------------------------------
      //  Compute tails.
      //---------------------------------------------------------------
      TailVisitor tailVisitor = new TailVisitor();
      for (Expr e: index)
        e.accept(tailVisitor);
      tailVisitor = null;

      for (Expr.Ref ref: refs)
        {
          for (Tail tail: ref.tails)
            ref.rule.tails.add(tail);
        }

      //---------------------------------------------------------------
      //  Diagnose.
      //---------------------------------------------------------------
      Diagnose.apply();

      //---------------------------------------------------------------
      //  Find LL1 violations.
      //---------------------------------------------------------------
      Conflicts.find();
    }


    //===================================================================
    //  Resolve references.
    //===================================================================
    private static void resolve()
      {
        Hashtable<String,Expr> names = new Hashtable<String,Expr>();
        HashSet<String> referenced = new HashSet<String>();

        //-------------------------------------------------------------
        //  Dummy rule - replaces undefined to stop multiple messages.
        //-------------------------------------------------------------

        Expr dummy = new Expr.Any();

        //-------------------------------------------------------------
        //  Build table for finding Rules by name.
        //-------------------------------------------------------------
        for (Expr r: rules)
        {
          Expr prev = names.put(r.name,r);
          if (prev!=null)
          {
            System.out.println("Error: duplicate name '" + r.name + "'.");
            errors++;
          }
        }

        //-------------------------------------------------------------
        //  Start expression is assumed referenced.
        //-------------------------------------------------------------
        referenced.add(startExpr.name);

        //-------------------------------------------------------------
        //  Insert rule in Ref objects.
        //-------------------------------------------------------------
        for (Expr.Ref ref: refs)
        {
          Expr rule = names.get(ref.target);
          if (rule==null)
          {
            System.out.println("Error: undefined name '" + ref.target + "'.");
            errors++;
            names.put(ref.target,dummy);
            rule = dummy;
          }
          else
            referenced.add(ref.target);
          ref.rule = rule;
        }

        //-------------------------------------------------------------
        //  Detect unused rules.
        //-------------------------------------------------------------
        for (Expr r: rules)
        {
          if (!referenced.contains(r.name))
            System.out.println("Warning: rule '" + r.name + "' is not used.");
        }
      }


    //===================================================================
    //  Compute attributes by iteration to fixpoint.
    //===================================================================
    private static void computeAttributes()
      {
        int trueAttrs; // Number of true attributes after last step
        int a = 0;     // Number of true attributes before last step
        iterAt = 0;    // Number of steps
        AttrVisitor attrVisitor = new AttrVisitor();

        while(true)
        {
          //-----------------------------------------------------------
          //  Iteration step
          //-----------------------------------------------------------
          for (Expr e: index)
            e.accept(attrVisitor);

          //-----------------------------------------------------------
          //  Count true attributes
          //-----------------------------------------------------------
          trueAttrs = 0;
          for (Expr e: index)
            trueAttrs += (e.nul? 1:0) + (e.adv? 1:0) + (e.fal? 1:0) + (e.NUL? 1:0) + (e.end? 1:0);

          //-----------------------------------------------------------
          //  Break if fixpoint reached
          //-----------------------------------------------------------
          if (trueAttrs==a) break;

          //-----------------------------------------------------------
          //  To next step
          //-----------------------------------------------------------
          a = trueAttrs;
          iterAt++;
        }
        attrVisitor = null;
        // System.out.println("iterAt "+iterAt);
      }



  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  ListVisitor
  //
  //-----------------------------------------------------------------------
  //
  //  Constructs names for subexpressions and builds lists of expressions.
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

  static class ListVisitor extends Visitor
  {
    //===================================================================
    //  Local data.
    //===================================================================
    private Vector<Expr> myNonterms  = new Vector<Expr>();
    private Vector<Expr> myTerms = new Vector<Expr>();

    //===================================================================
    //  Do the job.
    //===================================================================
    public void apply()
      {
        for (Expr r: rules)
        {
          r.inRule = r;
          r. accept(this);
        }

        nonterms = myNonterms.toArray(new Expr[0]);
        terms = myTerms.toArray(new Expr[0]);

        //---------------------------------------------------------------
        //  Build index of expressions.
        //---------------------------------------------------------------
        T = terms.length;
        N = T + nonterms.length;
        index = new Expr[N];

        int i = 0;

        for (Expr e: terms)
        {
          e.index = i;
          index[i] = e;
          i++;
        }

        for (Expr e: nonterms)
        {
          e.index = i;
          index[i] = e;
          i++;
        }
      }

    //===================================================================
    //  Private methods.
    //===================================================================
    //-----------------------------------------------------------------
    //  Common for Choice and Sequence.
    //-----------------------------------------------------------------
    private void doCompound(Expr e, Expr args[])
      {
        myNonterms.add(e);
        for (int i=0;i<args.length;i++)
        {
          Expr arg = args[i];
          if (arg.isRule) continue;
          arg.name = e.name + "." + (i+1);
          arg.inRule = e.inRule;
          arg.accept(this);
        }
      }

    //-----------------------------------------------------------------
    //  Common for one-argument operations.
    //-----------------------------------------------------------------
    private void doUnary(Expr e, Expr arg)
      {
        myNonterms.add(e);
        if (arg.isRule) return;
        arg.name = e.name + ".1";
        arg.inRule = e.inRule;
        arg.accept(this);
      }

    //-----------------------------------------------------------------
    //  Common for terminals.
    //-----------------------------------------------------------------
    private void doTerm(Expr e, Expr arg)
      {
        myTerms.add(e);
        arg.inRule = e.inRule;
      }

    //===================================================================
    //  Visitor methods.
    //===================================================================

    public void visit(Expr.Choice e)
      { doCompound(e,e.args); }

    public void visit(Expr.Sequence e)
      { doCompound(e,e.args); }

    public void visit(Expr.And e)
      { doUnary(e,e.arg); }

    public void visit(Expr.Not e)
      { doUnary(e,e.arg); }

    public void visit(Expr.Plus e)
      { doUnary(e,e.arg); }

    public void visit(Expr.Star e)
      { doUnary(e,e.arg); }

    public void visit(Expr.Query e)
      { doUnary(e,e.arg); }

    public void visit(Expr.Ref e)
      { myNonterms.add(e); }

    public void visit(Expr.StringLit e)
      { myTerms.add(e); }

    public void visit(Expr.Range e)
      { myTerms.add(e); }

    public void visit(Expr.CharClass e)
      { myTerms.add(e); }

    public void visit(Expr.Any e)
      { myTerms.add(e); }

    public void visit(Expr.End e)
      { myTerms.add(e); }

    public void visit(Expr.SigmaStar e)
      { myTerms.add(e); }
  }


  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  SourceVisitor - Constructs source strings of expressions
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

  public static class SourceVisitor extends Visitor
  {
    public void visit(Expr.Choice e)
      {
        StringBuilder sb = new StringBuilder();
        String sep = "";
        for (Expr arg: e.args)
        {
          sb.append(sep + asString(arg,0));
          sep = " / ";
        }
        e.asString = sb.toString();
      }

    public void visit(Expr.Sequence e)
      {
        StringBuilder sb = new StringBuilder();
        String sep = "";
        for (Expr arg: e.args)
        {
          sb.append(sep + asString(arg,1));
          sep = " ";
        }
        e.asString = sb.toString();
      }

    public void visit(Expr.And e)
      { e.asString = "&" + asString(e.arg,3); }

    public void visit(Expr.Not e)
      { e.asString = "!" + asString(e.arg,3); }

    public void visit(Expr.Plus e)
      { e.asString = asString(e.arg,4) + "+"; }

    public void visit(Expr.Star e)
      { e.asString = asString(e.arg,4) + "*"; }

    public void visit(Expr.Query e)
      { e.asString = asString(e.arg,4) + "?"; }


    //-----------------------------------------------------------------
    //  Get string of 'e', parenthesized if needed
    //-----------------------------------------------------------------
    private String asString(final Expr e, int myBind)
      {
        if (e.isRule) return e.name;
        if (e.asString==null)
          e.accept(this);
        boolean nest = e.bind()<=myBind;
        return (nest?"(":"") + e.asString + (nest?")":"");
     }
  }


  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  AttrVisitor
  //
  //---------------------------------------------------------------------
  //
  //  Computes nul, suc, and fal attributes of an expression
  //  from these attributes of its subexpressions.
  //  The process uses iteration to a fixpoint, which requires that
  //  the process is monotone, i.e. no value is changed from true to false.
  //  Moreover, the nul attribute is subsequently used to discover
  //  left-recursion, and must be correct even if there is left recursion.
  //  Therefore we compute it as "the language of e treated as EBNF
  //  contains empty word".
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

  static class AttrVisitor extends Visitor
  {
    public void visit(Expr.Choice e)
      {
        boolean exNul = false;
        boolean exAdv = false;
        boolean allFal = true;
        boolean exNUL = false;
        boolean allEnd = true;

        for (Expr arg: e.args)
        {
          exNul |= arg.nul;
          exAdv |= arg.adv;
          allFal &= arg.fal;
          exNUL |= arg.NUL;
          allEnd &= arg.end;
        }

        e.nul = exNul;
        e.adv = exAdv;
        e.fal = allFal;
        e.NUL = exNUL;
        e.end = allEnd;
      }

    public void visit(Expr.Sequence e)
      {
        boolean allNul = true;
        boolean exAdv = false;
        boolean exFal  = false;
        boolean allNUL = true;
        boolean exEnd  = false;

        for (Expr arg: e.args)
        {
          allNul &= arg.nul;
          exAdv |= arg.adv;
          exFal |= arg.fal;
          allNUL &= arg.NUL;
          exEnd |= arg.end;
        }

        e.nul = allNul;
        e.adv = exAdv;
        e.fal = exFal;
        e.NUL = allNUL;
        e.end = exEnd;
      }

    public void visit(Expr.And e)
      {
        e.nul = true;  // In EBNF attributes consume null word.
        e.NUL = true;
      }

    public void visit(Expr.Not e)
      {
        e.nul = true;  // In EBNF attributes consume null word.
        e.NUL = true;
      }

    public void visit(Expr.Plus e)
      {
        Expr arg = e.arg;
        e.nul = arg.nul;
        e.adv = arg.adv;
        e.fal = arg.fal;
        e.NUL = arg.NUL;
        e.end = arg.end;
      }

    public void visit(Expr.Star e)
      {
        Expr arg = e.arg;
        e.nul = true;
        e.NUL = true;
        e.adv = arg.adv;
     }

    public void visit(Expr.Query e)
      {
        Expr arg = e.arg;
        e.nul = true;
        e.NUL = true;
        e.adv = arg.adv;
      }

    public void visit(Expr.Ref e)
      {
        Expr rule = e.rule;
        e.nul = rule.nul;
        e.adv = rule.adv;
        e.fal = rule.fal;
        e.NUL = rule.NUL;
        e.end = rule.end;
      }
  }



  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
  //
  //  TailVisitor
  //
  //-----------------------------------------------------------------------
  //
  //  Constructs Tail objects for expressions invoked by the visited one.
  //
  //HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

  static class TailVisitor extends Visitor
  {
    //-----------------------------------------------------------------
    //  Choice.
    //-----------------------------------------------------------------
    public void visit(Expr.Choice e)
      {
        for (Expr arg: e.args)
          //-----------------------------------------------------------
          //  Each 'arg' is called as last from 'e', so its 'seq' is empty.
          //  If 'arg' has 'end' attribute, nothing is called after.
          //-----------------------------------------------------------
          if (!arg.end)
            arg.tails.add(new Tail(arg,e));
      }

    //-----------------------------------------------------------------
    //  Sequence.
    //-----------------------------------------------------------------
    public void visit(Expr.Sequence e)
      {
        for (int i=0;i<e.args.length;i++)
        {
          Expr arg = e.args[i];
          //-----------------------------------------------------------
          //  The call to each 'arg' is followed by 'args[i+1]' etc.
          //-----------------------------------------------------------
          Expr[] post = Arrays.copyOfRange(e.args,i+1,e.args.length);
          Tail newTail = new Tail(arg,e,post);
          if (!e.end)
            arg.tails.add(new Tail(arg,e,post));
          else
          {
            //---------------------------------------------------------
            //  If 'e' has 'end' attribute, only the last 'arg' may
            //  have it; otherwise 'e' always fails.
            //---------------------------------------------------------
            newTail.hasTail = false;
            if (newTail.seq.size()>0)
              arg.tails.add(new Tail(arg,e,post));
          }
        }
      }

    //-----------------------------------------------------------------
    //  Plus.
    //  e = arg+ is replaced by arg e / arg.
    //-----------------------------------------------------------------
    public void visit(Expr.Plus e)
      {
        e.arg.tails.add(new Tail(e.arg,e,e));
        e.arg.tails.add(new Tail(e.arg,e));
      }

    //-----------------------------------------------------------------
    //  Star.
    //  e = arg* is replaced by arg e / empty.
    //-----------------------------------------------------------------
    public void visit(Expr.Star e)
      { e.arg.tails.add(new Tail(e.arg,e,e)); }

    //-----------------------------------------------------------------
    //  Query.
    //  e = arg? is replaced by arg / empty.
    //-----------------------------------------------------------------
    public void visit(Expr.Query e)
      { e.arg.tails.add(new Tail(e.arg,e)); }

  }
}

