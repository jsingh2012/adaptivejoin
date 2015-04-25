smallset = load '$smallset' USING PigStorage('\t') as (name, id);
--describe smallset;
--dump smallset;

bigset = load '$bigset' USING PigStorage('\t') as (name, id);
--describe bigset;
--dump bigset;

brute_join = JOIN bigset by id LEFT OUTER, smallset by id;

SPLIT brute_join into ClickFalse if $3 is NULL, ClickTrue if $3 is not NULL;

dump ClickTrue;
dump ClickFalse;
