register $udf; 

define hfilter udf.Hfilter('$path', '$hashmap');

smallset = load '$smallset' USING PigStorage('\t') as (name, id);
--describe smallset;
--dump smallset;

bigset = load '$bigset' USING PigStorage('\t') as (name, id);
--describe bigset;

bigset_with_flag = foreach bigset generate name as name, id as id, hfilter(id) as flag; 
--dump bigset_with_flag;

SPLIT bigset_with_flag into ClickFalse if flag == 'F', ClickTrue if flag == 'T';

adaptive_join = JOIN ClickTrue by id LEFT OUTER, smallset by id;
dump adaptive_join;
dump ClickFalse;
--dump ClickTrue;
