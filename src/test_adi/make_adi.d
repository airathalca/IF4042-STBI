#! /bin/tcsh
# Make the adi test collection.  Change first 4 pathnames as appropriate.
# Adi collection obtainable in ~ftp/pub/smart/adi on  ftp.cs.cornell.edu

# set echo verbose

# 
set bin = /mnt/c/kuliah/semester7/IF4042-STBI/src/bin
set srcdir = /mnt/c/kuliah/semester7/IF4042-STBI/src
set tlibdir = /mnt/c/kuliah/semester7/IF4042-STBI/lib

set current  = $srcdir/test_adi
set database = $current/indexed
set coll     = $current/coll
set doc_loc  = $coll/adi.all
set query_loc = $coll/query.text

# create the empty collection
/bin/rm -rf $database
mkdir $database


cat > $database/spec << EOF1
## INFORMATION LOCATIONS
database                $database
include_file            $tlibdir/spec.expcoll
doc_loc                 $database/doc_loc
query_loc               $database/query_loc
qrels_text_file         $coll/qrels.text

## ADI DOCDESC
#### GENERIC PREPARSER
num_pp_sections                 6
pp_section.0.string             ".I"
pp_section.0.action             discard
pp_section.0.oneline_flag       true
pp_section.0.newdoc_flag        true
pp_section.1.string             ".A"
pp_section.1.section_name       a
pp_section.2.string             ".B"
pp_section.2.section_name       b
pp_section.3.string             ".W"
pp_section.3.section_name       w
pp_section.4.string             ".T"
pp_section.4.section_name       t
pp_section.5.string             ".O"
pp_section.5.action             discard

#### DESCRIPTION OF PARSE INPUT
index.num_sections              4
index.section.0.name            a
index.section.1.name            b
index.section.2.name            w
  index.section.2.method        index.parse_sect.full
  index.section.2.word.ctype    0
  index.section.2.proper.ctype  0
index.section.3.name            t
  index.section.3.method        index.parse_sect.full
  index.section.3.word.ctype    0
  index.section.3.proper.ctype  0
title_section 3

#### DESCRIPTION OF FINAL VECTORS
num_ctypes                      1
ctype.0.name                    words

## ALTERATIONS OF STANDARD PARAMETERS
dict_file_size                  3563

## ALTERATIONS OF STANDARD PROCEDURES
EOF1

#echo Creating new database at `date`
# Copy auxiliary files to collection
echo "$doc_loc" > $database/doc_loc
echo "$query_loc" > $database/query_loc

#index the collection
#echo Indexing docs,queries,rels at `date`
$bin/smart exp_coll $database/spec

#time

# Create atc (a tf*idf variant) versions of docs and queries
$bin/smart convert $database/spec   proc convert.obj.weight_query \
                   in query.nnn  out query.atc   query_weight atc
$bin/smart convert $database/spec   proc convert.obj.weight_doc \
                   in doc.nnn  out doc.atc   doc_weight atc
$bin/smart convert $database/spec   proc convert.obj.vec_aux  \
                   in doc.atc  out inv.atc

#time
#echo All done at `date`
