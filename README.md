# IF4042-STBI

# STEP BY STEP
1. Create test_{name_coll} folder in folder src
2. Create make_{name_coll} and test_{name_coll} in folder test_{name_coll}
3. Move file from each collection to test_{name_coll}/coll
4. Run sudo tcsh make_{name_coll}
5. Run sudo tcsh test_{name_coll}
6. Check the result in test_{name_coll}/test/out.{query_weight}.{doc_weight}.3 OR cd test_{name_coll}/test and run sudo tcsh {path_to_folder}/src/bin.smprint rr_eval spec.{query_weight}.{doc_weight}