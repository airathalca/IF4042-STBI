#!/bin/bash

# Define arrays for the term weighting components
TF=("n" "l" "a" "b")
IDF=("n" "t")
Normalization=("n" "c")

# Path to the folder containing the smprint executable
path_to_folder="/home/adeliaaaa/Downloads/IF4042-STBI/src/"

# Output file
output_file="results.csv"

# If the output file exists, remove it. if not, create it
if [ -f $output_file ]; then
  > $output_file
fi

# Clear the output file and add headers
echo "Combination,Retrieved,Relevant,Rel_ret,Trunc_ret,11-pt Avg,3-pt Avg,Recall_Exact,Precision_Exact,Truncated_Precision_Exact" > $output_file

# Iterate over all combinations of document and query term weightings
for doc_tf in "${TF[@]}"; do
  for doc_idf in "${IDF[@]}"; do
    for doc_norm in "${Normalization[@]}"; do
      for query_tf in "${TF[@]}"; do
        for query_idf in "${IDF[@]}"; do
          for query_norm in "${Normalization[@]}"; do
            # Construct the combination string
            doc_combination="${doc_tf}${doc_idf}${doc_norm}"
            query_combination="${query_tf}${query_idf}${query_norm}"
            combination="${doc_combination}.${query_combination}"
            
            # Run the command
            result=$(sudo tcsh ${path_to_folder}/bin/smprint rr_eval spec.${doc_combination}.${query_combination})

            retrieved=$(echo "$result" | grep "Retrieved" | awk '{print $2}')
            relevant=$(echo "$result" | grep "Relevant" | awk '{print $2}' | tail -n 1)
            rel_ret=$(echo "$result" | grep "Rel_ret" | awk '{print $2}')
            trunc_ret=$(echo "$result" | grep "Trunc_ret" | awk '{print $2}')
            avg_11_pt=$(echo "$result" | grep "11-pt Avg" | awk '{print $3}')
            avg_3_pt=$(echo "$result" | grep "3-pt Avg" | awk '{print $3}')
            recall_exact=$(echo "$result" | grep -A 1 "Recall:" | grep "Exact:" | awk '{print $2}')
            precision_exact=$(echo "$result" | grep -A 1 "Precision:" | grep "Exact:" | awk '{print $2}' | head -n 1)
            trunc_precision_exact=$(echo "$result" | grep -A 1 "Truncated Precision:" | grep "Exact:" | awk '{print $2}')
            # Save the result to the output file
            echo "${combination},${retrieved},${relevant},${rel_ret},${trunc_ret},${avg_11_pt},${avg_3_pt},${recall_exact},${precision_exact},${trunc_precision_exact}" >> $output_file
          done
        done
      done
    done
  done
done

echo "All combinations have been tested and results are saved in $output_file"