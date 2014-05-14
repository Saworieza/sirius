#!/bin/perl
# head-tight:
# rule format is "S->NP-VP"
# rather than    "S -> NP VP "
# (for subcat experiments, so so can be conveniently output as a feature )

%head1 = ( 
	  'ADJP JJ', 1,
	  'ADJP JJR', 1,
	  'ADJP JJS', 1,
	  'ADVP RB', 1,
	  'ADVP RBB', 1,
	  'LST LS', 1,
	  'NAC NNS', 1,
	  'NAC NN', 1,
	  'NAC PRP', 1,
	  'NAC NNPS', 1,
	  'NAC NNP', 1,
	  'NX NNS', 1,
	  'NX NN', 1,
	  'NX PRP', 1,
	  'NX NNPS', 1,
	  'NX NNP', 1,
	  'NP NNS', 1,
	  'NP NN', 1,
	  'NP PRP', 1,
	  'NP NNPS', 1,
	  'NP NNP', 1,
	  'NP \$', 1,
	  'PP IN', 1,
	  'PP TO', 1,
	  'PP RP', 1,
	  'PRT RP', 1,
	  'S VP', 1,
	  'S1 S', 1,
	  'SBAR IN', 1,
	  'SBAR WHNP', 1,
	  'SBARQ SQ', 1,
	  'SBARQ VP', 1,
	  'SINV VP', 1,
	  'SQ MD', 1,
	  'SQ AUX', 1,
	  'VP VB', 1,
	  'VP VBZ', 1,
	  'VP VBP', 1,
	  'VP VBG', 1,
	  'VP VBN', 1,
	  'VP VBD', 1,
	  'VP AUX', 1,
	  'VP AUXG', 1,
	  'VP TO', 1,
	  'VP MD', 1,
	  'WHADJP WRB', 1,
	  'WHADVP WRB', 1,
	  'WHNP WP', 1,
	  'WHNP WDT', 1,
	  'WHNP WP\$', 1,
	  'WHPP IN', 1,
	  'WHPP TO', 1 );

%head2 = (
	  'ADJP VBN', 1,
	  'ADJP RB', 1,
	  'NAC NP', 1,
	  'NAC CD', 1,
	  'NAC FW', 1,
	  'NAC ADJP', 1,
	  'NAC JJ', 1,
	  'NX NP', 1,
	  'NX CD', 1,
	  'NX FW', 1,
	  'NX ADJP', 1,
	  'NX JJ', 1,
	  'NP CD', 1,
	  'NP ADJP', 1,
	  'NP JJ', 1,
	  'S SINV', 1,
	  'S SBARQ', 1,
	  'S X', 1,
	  'PRT RB', 1,
	  'PRT IN', 1,
	  'SBAR WHADJP', 1,
	  'SBAR WHADVP', 1,
	  'SBAR WHPP', 1,
	  'SBARQ S', 1,
	  'SBARQ SINV', 1,
	  'SBARQ X', 1,
	  'SINV SBAR', 1,
	  'SQ VP', 1 );


%term = (
	 'AUX', 1,
	 'AUXG', 1, 
	 'CC', 1, 
	 'CD', 1, 
	 'DT', 1, 
	 'EX', 1, 
	 'FW', 1, 
	 'IN', 1, 
	 'JJ', 1, 
	 'JJR', 1, 
	 'JJS', 1, 
	 'LS', 1, 
	 'MD', 1, 
	 'NN', 1, 
	 'NNS', 1, 
	 'NNP', 1, 
	 'NNPS', 1, 
	 'PDT', 1, 
	 'POS', 1, 
	 'PRP', 1, 
	 'PRP\$', 1, 
	 'RB', 1, 
	 'RBR', 1, 
	 'RBS', 1, 
	 'RP', 1, 
	 'SYM', 1, 
	 'TO', 1, 
	 'UH', 1, 
	 'VB', 1, 
	 'VBD', 1, 
	 'VBG', 1, 
	 'VBN', 1, 
	 'VBP', 1, 
	 'VBZ', 1, 
	 'WDT', 1, 
	 'WP', 1, 
	 'WP\$', 1, 
	 'WRB', 1, 
	 '#', 1, 
	 '\$', 1, 
	 '.', 1, 
	 ',', 1, 
	 ':', 1, 
	 '-RRB-', 1, 
	 '-LRB-', 1, 
	 '``', 1, 
	 '\'\'', 1, 
	 'EOS', 1 );

%isPunc = (
	   '#', 1, 
	   '\$', 1, 
	   '.', 1, 
	   ',', 1, 
	   ':', 1, 
	   '-RRB-', 1, 
	   '-LRB-', 1, 
	   '``', 1, 
	   '\'\'', 1, 
	   );


open(GRAMMAR, "$ENV{\"ASSERT\"}/data/grammar.txt") || die;
while (<GRAMMAR>) 
{
    next if (/\*/);
    @a = split;
    shift(@a);
    pop(@a);
    $lhs = shift(@a);
    shift(@a);
    $pos = -1;
    $ans = -1;
    $ansPriority = 10;
    for $rhs (@a) 
	{
		$pos++;
		
		$both = "$lhs $rhs";
		if($head1{$both})
		{
			$ans = $pos;
			$ansPriority = 1;
		}
		elsif ($ansPriority == 1) {next;}
		elsif ($ansPriority == 2) {next;} # goes before check because we want
		elsif ($rhs == $lhs) 		# lhs constit. e.g. np -> NP , np
		{
			$ans = $pos;
			$ansPriority = 2;
		}
		elsif ($head2s{$both})
		{
			$ans = $pos;
			$ansPriority = 3;
		}
		elsif ($ansPriority == 3) {next;}
		elsif ($term{$rhs} && $isPunc{$rhsTerm})
		{
			$ans = $pos;
			$ansPriority = 4;
		}
		elsif ($ansPriority == 4) {next;}
		elsif (!$term{$rhs} && $rhs ne "PP")
		{
			$ansPriority = 5;
			$ans = $pos;
		}
		elsif ($ansPriority == 5) {next;}
		elsif (!$term{$rhs})
		{
			$ansPriority = 6;
			$ans = $pos;
		}
		elsif ($ansPriority == 6) {next;}
		else
		{
			$ansPriority = 7;
			$ans = $pos;
		}
    }
#  return $ans;
#    print " $lhs -> ", join(' ', @a), ' ', $ans, "\n";
    $headpos{"$lhs->" . join('-', @a)} = $ans;
}

1;