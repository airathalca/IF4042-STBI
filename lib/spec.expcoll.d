# USE STANDARD DEFAULTS, EXCEPT FOR THOSE SPECIFIED IN THIS FILE
include_file            /mnt/c/kuliah/semester7/IF4042-STBI/lib/spec.default

# FOR SMART EXPERIMENTAL FILES, ASSUME DEFAULT SECTION IS W
pp.default_section_name  w
pp.default_section_action copy

# INITIAL INDEXED WEIGHT WILL BE JUST TF  (NNN)
doc_file                doc.nnn
inv_file                inv.nnn
query_file              query.nnn

# QUERY WILL HAVE OWN TEXTLOC FILE
query.textloc_file      q_textloc
index.query.addtextloc  index.addtextloc.add_textloc

qrels_file              qrels

# STORE BOTH VECTOR AND INVERTED FILE FOR DOCS
doc.store               index.store.store_vec_aux

# PRINT NICELY FORMATTED DOC INSTEAD OF RAW DOC 
indivtext               print.indivtext.text_form

# GET QUERY FROM SET OF PREINDEXED QUERIES
get_query               retrieve.get_query.get_q_vec

# STORE RR,TR OUTPUT BY DEFAULT
retrieve.output         retrieve.output.ret_tr_rr
tr_file                 ./tr
rr_file                 ./rr
eval_file               ./eval

# INCREASE NUM_WANTED (SHOULD BE 15 IN STANDARD DEFAULT FILE TOO?)
num_wanted 15
