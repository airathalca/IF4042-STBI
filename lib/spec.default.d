text_stop_file          /mnt/c/kuliah/semester7/IF4042-STBI/lib/common_words
database                "."
temp_dir                ""

trace                   0
global_trace_start      -1
global_trace_end        2147483647
global_trace_file       ""
global_start            -1
global_end              2147483647
global_accounting       0

# Indexing Locations    
doc_loc                 -
query_loc               -
qrels_text_file         ""
query_skel              ""

# DEFAULTS FOR INDEXING PROCEDURES AND FLAGS
index_pp                index.index_pp.index_pp
index_vec               index.vec_index.doc
query.index_vec         index.vec_index.query
preparse                index.preparse.generic
next_vecid              index.next_vecid.next_vecid
query.next_vecid        index.next_vecid.next_vecid_1
addtextloc              index.addtextloc.add_textloc
query.addtextloc        index.addtextloc.empty
token_sect              index.token_sect.token_sect
interior_char           "'.@!_"
interior_hyphenation    false
endline_hyphenation     true
parse.single_case       false
makevec                 index.makevec.makevec
expand                  index.expand.none
weight                  convert.weight.weight
store                   index.store.store_vec
doc.store               index.store.store_aux

# DEFAULTS FOR DATABASE FILES AND MODES
dict_file               dict
doc_file                ""
textloc_file            textloc
query.textloc_file      ""
inv_file                inv
query_file              ""
qrels_file              ""
collstat_file           ""
rwmode                  SRDWR
rmode                   SRDONLY
rwcmode                 SRDWR|SCREATE

## DEFAULTS FOR DOCUMENT DESCRIPTIONS
#### GENERIC PREPARSING
num_pp_sections                 0
pp_section.string               ""
pp_section.section_name         -
pp_section.action               copy
pp_section.oneline_flag         false
pp_section.newdoc_flag          false
pp.default_section_name         -
pp.default_section_action       discard
pp_filter                       ""

#### PARSING INPUT
index.section.name      none
index.section.ctype     -1
method                  index.parse_sect.none
token_to_con            index.token_to_con.dict
stem_wanted             1
stemmer                 index.stem.triestem
stopword_wanted         1
stopword                index.stop.stop_dict
stop_file               common_words
thesaurus_wanted        0
text_thesaurus_file     ""

#### PARSING OUTPUT
index.ctype.name        none
con_to_token            index.con_to_token.contok_dict
store_aux               convert.tup.vec_inv
weight_ctype            convert.wt_ctype.weight_tri
doc_weight              nnn
query_weight            nnn
sect_weight             nnn

num_sections            0
num_ctypes              0

## DEFAULTS FOR COLLECTION CREATION
stop_file_size          1501
dict_file_size          30001

## DEFAULTS FOR CONVERSION
vec_inv.mem_usage       4194000
vec_inv.virt_mem_usage  50000000
in                      ""
out                     ""
deleted_doc_file        ""

#########################################
## DEFAULTS FOR RETRIEVAL
## Procedures
get_query               retrieve.get_query.get_q_user
user_qdisp              retrieve.user_query.edit_skel
qdisp_query             retrieve.query_index.std_vec
get_seen_docs           retrieve.get_seen_docs.empty
coll_sim                retrieve.coll_sim.inverted
inv_sim                 retrieve.ctype_coll.ctype_inv
seq_sim                 retrieve.ctype_vec.inner
vecs_vecs               retrieve.vecs_vecs.vecs_vecs
vec_vec                 retrieve.vec_vec.vec_vec
retrieve.output         retrieve.output.ret_tr
rank_tr                 retrieve.rank_tr.rank_did
sim_ctype_weight        1.0
eval.num_queries        0

num_wanted              10

## Files
tr_file                 ""
rr_file                 ""
seen_docs_file          ""
run_name                ""

#########################################
## DEFAULTS FOR FEEDBACK
## Procedures
feedback                feedback.feedback.feedback
feedback.expand         feedback.expand.exp_const
feedback.occ_info       feedback.occ_info.ide
feedback.weight         feedback.weight.ide
feedback.form           feedback.form.form_query

feedback.num_expand     15

feedback.num_iterations 0
feedback.alpha          1.0
feedback.beta           1.0
feedback.gamma          0.5

#########################################
## DEFAULTS FOR TOP-LEVEL INTERACTIVE DISPLAY AND PRINTING DOCS
indivtext               print.indivtext.text_filter
filter                  ""
print.format            ""
print.rawdocflag        0
print.doctext           print.print.doctext
spec_list               ""
verbose                 1
max_title_len           68
get_query.editor_only   0

## SUBSET OF TOP-LEVEL ROUTINES (these are ones that are often called
## elsewhere, and substitution of routines may be desired.)
index.doc               index.top.doc_coll
index.query             index.top.query_coll
top.exp_coll            index.top.exp_coll
top.inter               inter.inter
exp_coll                index.top.exp_coll
inter                   inter.inter
convert                 convert.convert.convert
print                   print.top.print
retrieve                retrieve.top.retrieve


## OBSOLETE  (only included for backward compatibility)
text_loc_prefix         ""
spec_file               ./spec
token                   index.token.std_token
parse                   index.parse.std_parse
