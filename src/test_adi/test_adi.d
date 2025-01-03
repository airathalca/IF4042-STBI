#! /bin/tcsh

set bin = /mnt/c/kuliah/semester7/IF4042-STBI/src/bin

set current = $cwd
set database = $current/indexed

# Very small test suite for smart on the included adi collection
# Run using "csh".  You can figure out more of what is going on by
# running this, and afterwords running
#        cd test
#        smart top.inter spec.atc spec_list "spec.nnn spec.atc"
# and playing around with the commands (try "help", "adv", "exp" first
# to get full list of available commands)

#########################################################################
# Make the adi test collection
#########################################################################
./make_adi

echo "collection made"

/bin/rm -rf test
mkdir test
cd test


#########################################################################
# Perform two retrieval runs with the vectors already prepared by make_adi
#########################################################################
cat > spec.nnn << EOF
include_file $database/spec
tr_file ./tr.nnn
rr_file ./rr.nnn
run_name "Doc weight == Query weight == nnn  (term-freq)"
EOF

$bin/smart retrieve spec.nnn

echo "retrieval run 1 done"

cat > spec.atc << EOF
include_file $database/spec
query_file query.atc
doc_file doc.atc
inv_file inv.atc
tr_file ./tr.atc
rr_file ./rr.atc
run_name "Doc weight == Query weight == atc  (augmented tfidf)"
EOF

$bin/smart retrieve spec.atc

echo "retrieval run 2 done"

#########################################################################
# Three different tests of the collection
#########################################################################

#################################################################
# Test 1 - Perform interactive query, look at result, and save it
#################################################################


cat > test.commands.1 << EOF
run
information retrieval and clustering
.
3
save ./save.1
EOF

#################################################################
# Test 2 - Interactive query, performing feedback, examining vectors
#          and reasons why docs were retrieved
#################################################################
cat > test.commands.2 << EOF
run
information retrieval and clustering
.
Qvec
more
55
Qv
feedback 55
Qv
Top
save ./save.2
Dtext 73
save
Dvec 73
Qsim 73
Qmatch 73
Drun 73
Dsim 73 55
Qsim 55
Dmatch 73 55
EOF

#################################################################
# Test 3 - Look at the two retrieval runs from above. Look at overall
#          evaluation, query-by-query evaluation, look at individual
#          query from each run to determine why query did better on
#          one run than other
#################################################################
cat > test.commands.3 << EOF
Elist
Eeval_rr
Eeval_tr
Ercl_prn
Eind_rr
Eind_tr
El
Euse 0
Eqid 2
Etr
Qv
Qm 12
s save.3
Euse 1
Eqid 2
Qm 12
s
EOF

/bin/rm -f out.final

foreach i (1 2 3)
    $bin/smart top.inter spec.atc spec_list "spec.nnn spec.atc" \
         < test.commands.$i > out.$i
    diff ../test.good/out.$i out.$i >> out.final
    diff ../test.good/save.$i save.$i >> out.final
    echo interactive comparison $i done
end

if (-z out.final) then
        echo "No differences at all detected"
else
        echo "The following differences detected"
        more out.final
endif

